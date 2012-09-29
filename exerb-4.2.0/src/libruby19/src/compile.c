/**********************************************************************

  compile.c - ruby node tree -> yarv instruction sequence

  $Author: ko1 $
  $Date: 2007-02-25 10:34:33 +0900 (日, 25 2 2007) $
  created at: 04/01/01 03:42:15 JST

  Copyright (C) 2004-2006 Koichi Sasada

**********************************************************************/

#include "ruby.h"
#include "node.h"

#include "yarvcore.h"
#include "compile.h"
#include "insns.inc"
#include "insns_info.inc"


#ifdef HAVE_STDARG_PROTOTYPES
#include <stdarg.h>
#define va_init_list(a,b) va_start(a,b)
#else
#include <varargs.h>
#define va_init_list(a,b) va_start(a)
#endif

VALUE iseq_load(VALUE self, VALUE data, VALUE parent, VALUE opt);

/* types */

#define ISEQ_ELEMENT_NONE  INT2FIX(0x00)
#define ISEQ_ELEMENT_LABEL INT2FIX(0x01)
#define ISEQ_ELEMENT_INSN  INT2FIX(0x02)
#define ISEQ_ELEMENT_SEQ   INT2FIX(0x03)

typedef struct iseq_link_element {
    int type;
    struct iseq_link_element *next;
    struct iseq_link_element *prev;
} LINK_ELEMENT;

typedef struct iseq_link_anchor {
    LINK_ELEMENT anchor;
    LINK_ELEMENT *last;
} LINK_ANCHOR;

typedef struct iseq_label_data {
    LINK_ELEMENT link;
    int label_no;
    int position;
    int sc_state;
    int set;
    int sp;
} LABEL;

typedef struct iseq_insn_data {
    LINK_ELEMENT link;
    int insn_id;
    int line_no;
    int operand_size;
    int sc_state;
    VALUE *operands;
} INSN;

struct ensure_range {
    LABEL *begin;
    LABEL *end;
    struct ensure_range *next;
};

struct iseq_compile_data_ensure_node_stack {
    NODE *ensure_node;
    struct iseq_compile_data_ensure_node_stack *prev;
    struct ensure_range *erange;
};


/* for debug */
#if CPDEBUG > 0
static long gl_node_level = 0;
static long gl_tmp = 0;
static void debug_list(LINK_ANCHOR *anchor);
#endif

static void dump_disasm_list(LINK_ELEMENT *elem);

static int insn_data_length(INSN *iobj);
static int insn_data_line_no(INSN *iobj);
static int calc_sp_depth(int depth, INSN *iobj);
static int insn_ret_num(int insn);

static void ADD_ELEM(LINK_ANCHOR *anchor, LINK_ELEMENT *elem);

static INSN *new_insn_body(rb_iseq_t *iseq, int line_no,
			   int insn_id, int argc, ...);
static LABEL *new_label_body(rb_iseq_t *iseq, int line);

static int iseq_compile_each(rb_iseq_t *iseq, LINK_ANCHOR *anchor,
			     NODE * n, int);
static int iseq_setup(rb_iseq_t *iseq, LINK_ANCHOR *anchor);

static int iseq_optimize(rb_iseq_t *iseq, LINK_ANCHOR *anchor);
static int iseq_insns_unification(rb_iseq_t *iseq, LINK_ANCHOR *anchor);
static int set_sequence_stackcaching(rb_iseq_t *iseq, LINK_ANCHOR *anchor);
static int set_sequence(rb_iseq_t *iseq, LINK_ANCHOR *anchor);

static int set_exception_table(rb_iseq_t *iseq);
static int set_localtbl(rb_iseq_t *iseq, ID *tbl);
static int set_localtbl_eval(rb_iseq_t *iseq, ID *tbl);
static int set_arguments(rb_iseq_t *iseq, LINK_ANCHOR *anchor, NODE * node);
static NODE *set_block_local_tbl(rb_iseq_t *iseq, NODE * node,
				 LINK_ANCHOR *anchor);
static int set_exception_tbl(rb_iseq_t *iseq);
static int set_optargs_table(rb_iseq_t *iseq);

static int
iseq_add_mark_object(rb_iseq_t *iseq, VALUE v)
{
    rb_ary_push(iseq->iseq_mark_ary, v);
    return COMPILE_OK;
}

static int
iseq_add_mark_object_compile_time(rb_iseq_t *iseq, VALUE v)
{
    rb_ary_push(iseq->compile_data->mark_ary, v);
    return COMPILE_OK;
}


#include "optinsn.inc"

#if OPT_INSTRUCTIONS_UNIFICATION
#include "optunifs.inc"
#endif

VALUE
iseq_compile(VALUE self, NODE *narg)
{
    DECL_ANCHOR(list_anchor);
    rb_iseq_t *iseq;
    NODE *node = (NODE *) narg;
    GetISeqPtr(self, iseq);

    debugs("[compile step 1 (traverse each node)]\n");

    iseq->node = node;

    if (iseq->type == ISEQ_TYPE_BLOCK) {
	node = set_block_local_tbl(iseq, node, list_anchor);
    }

    if (node && nd_type(node) == NODE_SCOPE) {
	/* with node scope */
	NODE *sn_body = node->nd_next;	/* sn: scope node */
	NODE *ndargs = 0;

	if (iseq->type != ISEQ_TYPE_BLOCK) {
	    set_localtbl(iseq, ((NODE *) node)->nd_tbl);
	}

	if (sn_body) {
	    switch (nd_type(sn_body)) {
	    case NODE_BLOCK:
		if (nd_type(sn_body->nd_head) == NODE_ARGS) {
		    /* some method attribute process */
		    ndargs = sn_body->nd_head;
		    set_arguments(iseq, list_anchor, ndargs);

		    /* with sn_body->nd_head */
		    if (iseq->type == ISEQ_TYPE_METHOD) {
			COMPILE(list_anchor, "normal method",
				sn_body->nd_next);
		    }
		    else if (iseq->type == ISEQ_TYPE_CLASS) {
			COMPILE(list_anchor, "class/module",
				sn_body->nd_next);
		    }
		    else {
			rb_bug("must be class or method");
		    }
		}
		else {
		    /* normal block */
		    if (iseq->type == ISEQ_TYPE_CLASS) {
			COMPILE(list_anchor, "class/module", sn_body);
		    }
		    else if (iseq->type == ISEQ_TYPE_BLOCK) {
			COMPILE(list_anchor, "normal block", sn_body);
		    }
		    else {
			rb_bug("must be class or block");
		    }
		}
		break;
	    case NODE_ARGS:
		/* empty method */
		/* some method attribute process */
		debugs("empty method\n");

		set_arguments(iseq, list_anchor, sn_body);
		ADD_INSN(list_anchor, nd_line(sn_body), putnil);
		break;

	    default:
		COMPILE(list_anchor, "other scope", sn_body);
		break;
	    }
	}
	else {
	    /* sn_body == 0 */
	    ADD_INSN(list_anchor, 0, putnil);
	}
    }
    else {
	if (iseq->type == ISEQ_TYPE_BLOCK) {
	    VALUE tmp;
	    LABEL *start = iseq->compile_data->start_label = NEW_LABEL(0);
	    LABEL *end = iseq->compile_data->end_label = NEW_LABEL(0);

	    ADD_LABEL(list_anchor, iseq->compile_data->start_label);
	    COMPILE(list_anchor, "block body", node);
	    ADD_LABEL(list_anchor, iseq->compile_data->end_label);

	    /* wide range catch handler must put at last */
	    ADD_CATCH_ENTRY(CATCH_TYPE_REDO, start, end, 0, start);
	    ADD_CATCH_ENTRY(CATCH_TYPE_NEXT, start, end, 0, end);
	}
	else if (iseq->type == ISEQ_TYPE_TOP) {
	    set_localtbl(iseq, GET_THREAD()->top_local_tbl);
	    COMPILE(list_anchor, "top level node", node);
	}
	else if (iseq->type == ISEQ_TYPE_EVAL) {
	    set_localtbl_eval(iseq, GET_THREAD()->top_local_tbl);
	    COMPILE(list_anchor, "eval node", node);
	}
	else if (iseq->type == ISEQ_TYPE_RESCUE) {
	    set_exception_tbl(iseq);
	    COMPILE(list_anchor, "rescue", node);
	}
	else if (iseq->type == ISEQ_TYPE_ENSURE) {
	    set_exception_tbl(iseq);
	    COMPILE_POPED(list_anchor, "ensure", node);
	}
	else if (iseq->type == ISEQ_TYPE_DEFINED_GUARD) {
	    COMPILE(list_anchor, "defined guard", node);
	}
	else if (node == 0) {
	    COMPILE(list_anchor, "nil", node);
	}
	else {
	    rb_bug("unknown scope");
	}
    }

    GC_CHECK();

    if (iseq->type == ISEQ_TYPE_RESCUE || iseq->type == ISEQ_TYPE_ENSURE) {
	ADD_INSN2(list_anchor, 0, getdynamic, INT2FIX(1), INT2FIX(0));
	ADD_INSN1(list_anchor, 0, throw, INT2FIX(0) /* continue throw */ );
    }
    else {
	ADD_INSN(list_anchor, iseq->compile_data->last_line, leave);
    }

    return iseq_setup(iseq, list_anchor);
}

VALUE th_eval(void *);

static int
iseq_translate_direct_threaded_code(rb_iseq_t *iseq)
{
#if OPT_DIRECT_THREADED_CODE || OPT_CALL_THREADED_CODE

#if OPT_DIRECT_THREADED_CODE
    void **table = (void **)th_eval(0);
#else
    extern void **insns_address_table();
    void **table = get_insns_address_table();
#endif
    int i;

    iseq->iseq_encoded = ALLOC_N(VALUE, iseq->size);
    MEMCPY(iseq->iseq_encoded, iseq->iseq, VALUE, iseq->size);

    for (i = 0; i < iseq->size; /* */ ) {
	int insn = iseq->iseq_encoded[i];
	int len = insn_len(insn);
	iseq->iseq_encoded[i] = (VALUE)table[insn];
	i += len;
    }
#else
    iseq->iseq_encoded = iseq->iseq;
#endif
    return COMPILE_OK;
}

/*********************************************/
/* definition of data structure for compiler */
/*********************************************/


static void *
compile_data_alloc(rb_iseq_t *iseq, size_t size)
{
    void *ptr = 0;
    struct iseq_compile_data_storage *storage =
	iseq->compile_data->storage_current;

    if (storage->pos + size > storage->size) {
	unsigned long alloc_size = storage->size * 2;

      retry:
	if (alloc_size < size) {
	    alloc_size *= 2;
	    goto retry;
	}
	storage->next = (void *)ALLOC_N(char, alloc_size +
					sizeof(struct
					       iseq_compile_data_storage));
	storage = iseq->compile_data->storage_current = storage->next;

	storage->next = 0;
	storage->pos = 0;
	storage->size = alloc_size;
	storage->buff = (char *)(&storage->buff + 1);
    }

    ptr = (void *)&storage->buff[storage->pos];
    storage->pos += size;
    return ptr;
}

static INSN *
compile_data_alloc_insn(rb_iseq_t *iseq)
{
    return (INSN *)compile_data_alloc(iseq, sizeof(INSN));
}

static LABEL *
compile_data_alloc_label(rb_iseq_t *iseq)
{
    return (LABEL *)compile_data_alloc(iseq, sizeof(LABEL));
}

/*
 * To make Array to LinkedList, use link_anchor
 */

static void
verify_list(char *info, LINK_ANCHOR *anchor)
{
#if CPDEBUG > 0
    int flag = 0;
    LINK_ELEMENT *list = anchor->anchor.next, *plist = &anchor->anchor;

    while (list) {
	if (plist != list->prev) {
	    flag += 1;
	}
	plist = list;
	list = list->next;
    }

    if (anchor->last != plist && anchor->last != 0) {
	flag |= 0x70000;
    }

    if (flag != 0) {
	rb_bug("list verify error: %08x (%s)", flag, info);
    }
#endif
}

/*
 * elem1, elem2 => elem1, elem2, elem
 */
static void
ADD_ELEM(LINK_ANCHOR *anchor, LINK_ELEMENT *elem)
{
    elem->prev = anchor->last;
    anchor->last->next = elem;
    anchor->last = elem;
    verify_list("add", anchor);
}

/*******************************************/
#if 0
/*
 * elem1, elemX => elem1, elem2, elemX
 */
static void
INSERT_ELEM_NEXT(LINK_ELEMENT *elem1, LINK_ELEMENT *elem2)
{
    elem2->next = elem1->next;
    elem2->prev = elem1;
    elem1->next = elem2;
    if (elem2->next) {
	elem2->next->prev = elem2;
    }
}
#endif

/*
 * elemX, elem1 => elemX, elem2, elem1
 */
static void
INSERT_ELEM_PREV(LINK_ELEMENT *elem1, LINK_ELEMENT *elem2)
{
    elem2->prev = elem1->prev;
    elem2->next = elem1;
    elem1->prev = elem2;
    if (elem2->prev) {
	elem2->prev->next = elem2;
    }
}
/*******************************************/

/*
 * elemX, elem1, elemY => elemX, elem2, elemY
 */
static void
REPLACE_ELEM(LINK_ELEMENT *elem1, LINK_ELEMENT *elem2)
{
    elem2->prev = elem1->prev;
    elem2->next = elem1->next;
    if (elem1->prev) {
	elem1->prev->next = elem2;
    }
    if (elem1->next) {
	elem1->next->prev = elem2;
    }
}

static void
REMOVE_ELEM(LINK_ELEMENT *elem)
{
    elem->prev->next = elem->next;
    if (elem->next) {
	elem->next->prev = elem->prev;
    }
}

static LINK_ELEMENT *
FIRST_ELEMENT(LINK_ANCHOR *anchor)
{
    return anchor->anchor.next;
}

/* 
static LINK_ELEMENT *
LAST_ELEMENT(LINK_ANCHOR *anchor)
{
  return anchor->last;
}
 */

static LINK_ELEMENT *
POP_ELEMENT(LINK_ANCHOR *anchor)
{
    LINK_ELEMENT *elem = anchor->last;
    anchor->last = anchor->last->prev;
    anchor->last->next = 0;
    verify_list("pop", anchor);
    return elem;
}

static LINK_ELEMENT *
SHIFT_ELEMENT(LINK_ANCHOR *anchor)
{
    LINK_ELEMENT *elem = anchor->anchor.next;
    if (elem) {
	anchor->anchor.next = elem->next;
    }
    return elem;
}

static int
LIST_SIZE(LINK_ANCHOR *anchor)
{
    LINK_ELEMENT *elem = anchor->anchor.next;
    int size = 0;
    while (elem) {
	size += 1;
	elem = elem->next;
    }
    return size;
}

static int
LIST_SIZE_ZERO(LINK_ANCHOR *anchor)
{
    if (anchor->anchor.next == 0) {
	return 1;
    }
    else {
	return 0;
    }
}

/*
 * anc1: e1, e2, e3
 * anc2: e4, e5
 *#=>
 * anc1: e1, e2, e3, e4, e5
 * anc2: e4, e5 (broken)
 */
static void
APPEND_LIST(LINK_ANCHOR *anc1, LINK_ANCHOR *anc2)
{
    if (anc2->anchor.next) {
	anc1->last->next = anc2->anchor.next;
	anc2->anchor.next->prev = anc1->last;
	anc1->last = anc2->last;
    }
    verify_list("append", anc1);
}

/*
 * anc1: e1, e2, e3
 * anc2: e4, e5
 *#=>
 * anc1: e4, e5, e1, e2, e3
 * anc2: e4, e5 (broken)
 */
static void
INSERT_LIST(LINK_ANCHOR *anc1, LINK_ANCHOR *anc2)
{
    if (anc2->anchor.next) {
	LINK_ELEMENT *first = anc1->anchor.next;
	anc1->anchor.next = anc2->anchor.next;
	anc1->anchor.next->prev = &anc1->anchor;
	anc2->last->next = first;
	if (first) {
	    first->prev = anc2->last;
	}
	else {
	    anc1->last = anc2->last;
	}
    }

    verify_list("append", anc1);
}

#if 0
/*
 * anc1: e1, e2, e3
 * anc2: e4, e5
 *#=>
 * anc1: e4, e5
 * anc2: e1, e2, e3
 */
static void
SWAP_LIST(LINK_ANCHOR *anc1, LINK_ANCHOR *anc2)
{
    LINK_ANCHOR tmp = *anc2;

    /* it has bug */
    *anc2 = *anc1;
    *anc1 = tmp;
    
    verify_list("swap1", anc1);
    verify_list("swap2", anc2);
}

static LINK_ANCHOR *
REVERSE_LIST(LINK_ANCHOR *anc)
{
    LINK_ELEMENT *first, *last, *elem, *e;
    first = &anc->anchor;
    elem = first->next;
    last = anc->last;

    if (elem != 0) {
	anc->anchor.next = last;
	anc->last = elem;
    }
    else {
	/* null list */
	return anc;
    }
    while (elem) {
	e = elem->next;
	elem->next = elem->prev;
	elem->prev = e;
	elem = e;
    }

    first->next = last;
    last->prev = first;
    anc->last->next = 0;

    verify_list("reverse", anc);
    return anc;
}
#endif

#if CPDEBUG > 0
static void
debug_list(LINK_ANCHOR *anchor)
{
    LINK_ELEMENT *list = FIRST_ELEMENT(anchor);
    printf("----\n");
    printf("anch: %p, frst: %p, last: %p\n", &anchor->anchor,
	   anchor->anchor.next, anchor->last);
    while (list) {
	printf("curr: %p, next: %p, prev: %p, type: %d\n", list, list->next,
	       list->prev, FIX2INT(list->type));
	list = list->next;
    }
    printf("----\n");

    dump_disasm_list(anchor->anchor.next);
    verify_list("debug list", anchor);
}
#endif

static LABEL *
new_label_body(rb_iseq_t *iseq, int line)
{
    LABEL *labelobj = compile_data_alloc_label(iseq);
    static int label_no = 0;

    labelobj->link.type = ISEQ_ELEMENT_LABEL;
    labelobj->link.next = 0;

    labelobj->label_no = label_no++;
    labelobj->sc_state = 0;
    labelobj->sp = -1;
    return labelobj;
}

static INSN *
new_insn_core(rb_iseq_t *iseq, int line_no,
	      int insn_id, int argc, VALUE *argv)
{
    INSN *iobj = compile_data_alloc_insn(iseq);

    iobj->link.type = ISEQ_ELEMENT_INSN;
    iobj->link.next = 0;
    iobj->insn_id = insn_id;
    iobj->line_no = line_no;
    iobj->operands = argv;
    iobj->operand_size = argc;
    iobj->sc_state = 0;
    return iobj;
}

static INSN *
new_insn_body(rb_iseq_t *iseq, int line_no, int insn_id, int argc, ...)
{
    VALUE *operands = 0;
    va_list argv;
    if (argc > 0) {
	int i;
	va_init_list(argv, argc);
	operands = (VALUE *)compile_data_alloc(iseq, sizeof(VALUE) * argc);
	for (i = 0; i < argc; i++) {
	    VALUE v = va_arg(argv, VALUE);
	    operands[i] = v;
	}
	va_end(argv);
    }
    return new_insn_core(iseq, line_no, insn_id, argc, operands);
}

static INSN *
new_insn_send(rb_iseq_t *iseq, int line_no,
	      VALUE id, VALUE argc, VALUE block, VALUE flag)
{
    INSN *iobj = 0;
    VALUE *operands =
      (VALUE *)compile_data_alloc(iseq, sizeof(VALUE) * 5);
    operands[0] = id;
    operands[1] = argc;
    operands[2] = block;
    operands[3] = flag;
    operands[4] = 0;
    iobj = new_insn_core(iseq, line_no, BIN(send), 5, operands);
    return iobj;
}

static VALUE
new_child_iseq(rb_iseq_t *iseq, NODE *node,
	       VALUE name, VALUE parent, VALUE type)
{
    VALUE ret;

    debugs("[new_child_iseq]> ---------------------------------------\n");
    ret = rb_iseq_new_with_opt(node, name, iseq_filename(iseq->self),
			       parent, type, iseq->compile_data->option);
    debugs("[new_child_iseq]< ---------------------------------------\n");
    iseq_add_mark_object(iseq, ret);
    return ret;
}

static int
iseq_setup(rb_iseq_t *iseq, LINK_ANCHOR *anchor)
{
    /* debugs("[compile step 2] (iseq_array_to_linkedlist)\n"); */

    GC_CHECK();
    if (CPDEBUG > 5)
	dump_disasm_list(FIRST_ELEMENT(anchor));
    GC_CHECK();

    debugs("[compile step 3.1 (iseq_optimize)]\n");
    iseq_optimize(iseq, anchor);

    if (CPDEBUG > 5)
	dump_disasm_list(FIRST_ELEMENT(anchor));
    GC_CHECK();

    if (iseq->compile_data->option->instructions_unification) {
	debugs("[compile step 3.2 (iseq_insns_unification)]\n");
	iseq_insns_unification(iseq, anchor);
	if (CPDEBUG > 5)
	  dump_disasm_list(FIRST_ELEMENT(anchor));
	GC_CHECK();
    }

    if (iseq->compile_data->option->stack_caching) {
	debugs("[compile step 3.3 (set_sequence_stackcaching)]\n");
	set_sequence_stackcaching(iseq, anchor);
	if (CPDEBUG > 5)
	  dump_disasm_list(FIRST_ELEMENT(anchor));
	GC_CHECK();
    }

    debugs("[compile step 4.1 (set_sequence)]\n");
    set_sequence(iseq, anchor);
    if (CPDEBUG > 5)
	dump_disasm_list(FIRST_ELEMENT(anchor));
    GC_CHECK();

    GC_CHECK();
    debugs("[compile step 4.2 (set_exception_table)]\n");
    set_exception_table(iseq);

    debugs("[compile step 4.3 (set_optargs_table)] \n");
    set_optargs_table(iseq);

    debugs("[compile step 5 (iseq_translate_direct_threaded_code)] \n");
    iseq_translate_direct_threaded_code(iseq);
    GC_CHECK();

    if (CPDEBUG > 1) {
	VALUE str = ruby_iseq_disasm(iseq->self);
	printf("%s\n", StringValueCStr(str));
	fflush(stdout);
    }
    debugs("[compile step: finish]\n");

    return 0;
}

VALUE
iseq_assemble_setup(VALUE self, VALUE args, VALUE locals, VALUE insn_ary)
{
    /* unsupported */
    return Qnil;
}

int
set_exception_tbl(rb_iseq_t *iseq)
{
    static ID id_dollar_bang;

    if (!id_dollar_bang) {
	id_dollar_bang = rb_intern("#$!");
    }
    iseq->local_table = (ID *)ALLOC_N(ID *, 1);
    iseq->local_table_size = iseq->local_size = 1;
    iseq->local_table[0] = id_dollar_bang;
    return COMPILE_OK;
}

static int
search_block_local_variables(NODE * node, VALUE local_vars)
{
    switch (nd_type(node)) {
    case NODE_DASGN_CURR:{
	    rb_ary_push(local_vars, ID2SYM(node->nd_vid));
	    break;
	}
    case NODE_MASGN:{
	    NODE *narg = node->nd_head;
	    while (narg) {
		search_block_local_variables(narg->nd_head, local_vars);
		narg = narg->nd_next;
	    }
	    if (node->nd_args != 0 && (long)node->nd_args != -1) {
		search_block_local_variables(node->nd_args, local_vars);
		break;
	    }
	}
    default:
	break;
    }
    return COMPILE_OK;
}

static NODE *
search_block_local_parameters(rb_iseq_t *iseq, NODE * lnode)
{
    NODE *node = lnode;
    NODE *nelem;
    VALUE local_vars = rb_ary_new();
    VALUE param_vars = rb_ary_new();

    /* search args */
    if (node->nd_var && (VALUE)node->nd_var != 1) {
	switch (nd_type(node->nd_var)) {
	case NODE_DASGN_CURR:
	    iseq->argc = 1;
	    rb_ary_push(param_vars, ID2SYM(node->nd_var->nd_vid));
	    debugi("block 1arg", node->nd_var->nd_vid);
	    break;
	case NODE_MASGN:{
		int i;
		nelem = node->nd_var->nd_head;
		if (nelem != 0) {
		    iseq->argc = node->nd_var->nd_head->nd_alen;
		    for (i = 0; i < iseq->argc; i++, nelem = nelem->nd_next) {
			if (nd_type(nelem->nd_head) == NODE_DASGN_CURR) {
			    rb_ary_push(param_vars,
					ID2SYM(nelem->nd_head->nd_vid));
			    debugi("block arg", nelem->nd_head->nd_vid);
			}
			else {
			    char buff[0x20];
			    ID id;
			    int idx = iseq->argc - RARRAY_LEN(param_vars);
			    snprintf(buff, 0x20, "#blp%d", idx);
			    id = rb_intern(buff);
			    rb_ary_push(param_vars, ID2SYM(id));
			    debugi("block arg (auto)", id);
			    search_block_local_variables(nelem->nd_head,
							 local_vars);
			}
		    }
		}
		if (node->nd_var->nd_args) {
		    NODE *sn = node->nd_var->nd_args;
		    if ((long)sn != -1) {
			if (nd_type(sn) == NODE_DASGN_CURR) {
			    rb_ary_push(param_vars, ID2SYM(sn->nd_vid));
			}
			else {
			    rb_ary_push(param_vars,
					ID2SYM(rb_intern("#blp_splat")));
			    debugi("block/splat (auto)",
				   rb_intern("#blp_splat"));
			}
		    }
		}
		break;
	    }
	default:
	    rb_ary_push(param_vars, ID2SYM(rb_intern("#blp")));
	    debugi("block 1arg (auto)", rb_intern("#blp"));
	    iseq->argc = 1;
	    break;
	}
    }
    else {
	iseq->argc = 0;
    }

    node = node->nd_body;

    /* other block local variables 2 */
    if (node && nd_type(node) == NODE_BLOCK) {
	nelem = node->nd_head;
	if (nelem && nd_type(nelem) == NODE_DASGN_CURR) {
	    while (nelem && nd_type(nelem) == NODE_DASGN_CURR) {
		if (!rb_ary_includes(local_vars, ID2SYM(nelem->nd_vid))) {
		    debugi("block initialized variable", nelem->nd_vid);
		    rb_ary_push(local_vars, ID2SYM(nelem->nd_vid));
		}
		nelem = nelem->nd_value;
	    }
	    if (nelem == 0) {
		node = node->nd_next;
	    }
	}
    }

    /* translate to block inlining code */
    if (iseq->special_block_builder != 0) {
	node = ((NODE * (*)(rb_iseq_t *, NODE *, NODE *, VALUE, VALUE))
		iseq->special_block_builder) (iseq, node, lnode->nd_var,
					      param_vars, local_vars);
    }

    rb_ary_concat(param_vars, local_vars);
    local_vars = param_vars;

    {
	int i, size = RARRAY_LEN(local_vars);

	if (size > 0) {
	    iseq->local_table = ALLOC_N(ID, size);
	    for (i = 0; i < size; i++) {
		iseq->local_table[i] = SYM2ID(RARRAY_PTR(local_vars)[i]);
		debugi("block local variable", iseq->local_table[i]);
	    }
	}
	iseq->local_table_size = iseq->local_size = size;
    }
    return node;
}

static int
set_block_initializer(rb_iseq_t *iseq, NODE * node, LINK_ANCHOR *anchor, int didx)
{
    DECL_ANCHOR(anc);
    LINK_ELEMENT *elem;

    COMPILE_POPED(anc, "set_block_local_tbl#masgn/other", node);

    if (nd_type(node) == NODE_ATTRASGN) {
	INSN *iobj = (INSN *)anc->last->prev;
	iobj->operands[1] = INT2FIX(FIX2INT(iobj->operands[1]) + 1);
	INSERT_ELEM_PREV((void *)iobj,
			 (void *)new_insn_body(iseq, nd_line(node),
					       BIN(getdynamic), 2,
					       INT2FIX(didx), INT2FIX(0)));
    }
    else {
	ADD_INSN2(anchor, nd_line(node), getdynamic,
		  INT2FIX(didx), INT2FIX(0));
	elem = FIRST_ELEMENT(anc);
	if (elem->type == ISEQ_ELEMENT_INSN &&
	    ((INSN *)elem)->insn_id == BIN(putnil)) {
	    SHIFT_ELEMENT(anc);
	}
    }
    APPEND_LIST(anchor, anc);

    return COMPILE_OK;
}

static NODE *
set_block_local_tbl(rb_iseq_t *iseq, NODE * node, LINK_ANCHOR *anchor)
{
    NODE *rnode;

    /* argument check */
    if (iseq->type != ISEQ_TYPE_BLOCK) {
	rb_bug("set_block_local_tbl: unexpected iseq type");
    }

    rnode = search_block_local_parameters(iseq, node);

    if ((VALUE)node->nd_var == 1) {
	/* TODO */
    }
    else if (node->nd_var) {
	NODE *nargs = node->nd_var;
	switch (nd_type(nargs)) {
	  case NODE_MASGN:{
	      NODE *massign = nargs;
	      int i = 0;
	      if (nargs->nd_head != 0) {
		  NODE *lhsn = massign->nd_head;

		  while (lhsn) {
		      if (nd_type(lhsn->nd_head) != NODE_DASGN_CURR) {
			  /* idx-th param, current level */
			  set_block_initializer(iseq, lhsn->nd_head,
						anchor, iseq->local_size - i);
		      }
		      i++;
		      lhsn = lhsn->nd_next;
		  }
	      }

	      /* check rest */
	      if (massign->nd_args != 0 && (long)massign->nd_args != -1) {
		  iseq->argc++;
		  iseq->arg_rest = i + 1;

		  if (nd_type(massign->nd_args) != NODE_DASGN_CURR) {
		      set_block_initializer(iseq, massign->nd_args,
					    anchor, iseq->local_size - i);
		  }
	      }
	      else if (i == 1) {
		  iseq->arg_rest = -1;
	      }
	      break;
	  }

	  case NODE_DASGN_CURR:
	    break;

	  case NODE_ARGS:{
	      /* make parameters */
	      VALUE a = nargs->nd_frml;
	      int i;
	      int argc = a ? RARRAY_LEN(a) : 0;
	      int local_size = argc + iseq->local_size - 1;
	      ID *local_tbl = local_size > 0 ? ALLOC_N(ID, local_size) : 0;

	      for (i=0; i<argc; i++) {
		  ID id = SYM2ID(RARRAY_PTR(a)[i]);
		  debugi("NODE_ARGS param", id);
		  local_tbl[i] = id;
	      }

	      if (iseq->local_table) {
		  /* copy from old local tbl and delete it */
		  for (i=1; i<iseq->local_size; i++) {
		      local_tbl[argc + i - 1] = iseq->local_table[i];
		  }
		  ruby_xfree(iseq->local_table);
	      }
	      iseq->local_table = local_tbl;
	      iseq->local_size = local_size;
	      iseq->argc = argc;
	      break;
	  }
	  default:{
	      /* for 1.x compatibility */
	      /* first param, current level */
	      set_block_initializer(iseq, nargs, anchor, iseq->local_size);
	      break;
	  }
	}
    }

    if (iseq->arg_opts || iseq->arg_rest || iseq->arg_block) {
	iseq->arg_simple = 0;
    }
    else {
	iseq->arg_simple = 1;
    }

    if (nd_type(node) == NODE_FOR) {
	iseq->compile_data->for_iseq = 1;
    }
    return rnode;
}

static int
get_dyna_var_idx_at_raw(rb_iseq_t *iseq, ID id)
{
    int i;

    for (i = 0; i < iseq->local_table_size; i++) {
	if (iseq->local_table[i] == id) {
	    return i;
	}
    }
    return -1;
}

static int
get_local_var_idx(rb_iseq_t *iseq, ID id)
{
    int idx = get_dyna_var_idx_at_raw(iseq->local_iseq, id);

    if (idx == -1) {
	rb_bug("get_local_var_idx: -1");
    }

    return idx;
}

static int
get_dyna_var_idx(rb_iseq_t *iseq, ID id, int *level, int *ls)
{
    int lv = 0, idx;

    while (iseq) {
	if ((idx = get_dyna_var_idx_at_raw(iseq, id)) >= 0) {
	    *level = lv;
	    *ls = iseq->local_size;
	    return idx;
	}
	iseq = iseq->parent_iseq;
	lv++;
    }

    rb_bug("get_dyna_var_idx: -1");
    return -1;
}

#if 1

static int
set_arguments(rb_iseq_t *iseq, LINK_ANCHOR *optargs, NODE *node_arg)
{
    NODE *node_aux = node_arg->nd_next;
    int mandatory_len = 0;
    NODE *node_opt = 0;
    ID rest_id = 0;
    ID block_id = 0;
    ID post_start_id = 0;
    int post_len = 0;
    NODE *node_init = 0;
    int d = iseq->local_size - iseq->local_table_size;

    iseq->argc = node_arg->nd_frml;
    node_opt = node_arg->nd_opt;

    if (node_aux) {
	rest_id = node_aux->nd_rest;
	block_id = (ID)node_aux->nd_body;
	node_aux = node_aux->nd_next;

	if (node_aux) {
	    post_start_id = node_aux->nd_pid;
	    post_len = node_aux->nd_plen;
	    node_init = node_aux->nd_next;
	}
    }

    if (node_init) {
	COMPILE(optargs, "arguments", node_init);
    }

    if (node_opt) {
	NODE *node = node_opt;
	LABEL *label;
	VALUE labels = rb_ary_new();
	int i = 0, j;

	while (node) {
	    label = NEW_LABEL(nd_line(node));
	    rb_ary_push(labels, (VALUE)label | 1);
	    ADD_LABEL(optargs, label);
	    COMPILE_POPED(optargs, "optarg", node->nd_body);

	    node = node->nd_next;
	    i += 1;
	}
	/* last label */
	label = NEW_LABEL(nd_line(node_arg));
	rb_ary_push(labels, (VALUE)label | 1);
	ADD_LABEL(optargs, label);
	i += 1;

	iseq->arg_opts = i;
	iseq->arg_opt_tbl = ALLOC_N(VALUE, i);
	MEMCPY(iseq->arg_opt_tbl, RARRAY_PTR(labels), VALUE, i);
	for (j = 0; j < i; j++) {
	    iseq->arg_opt_tbl[j] &= ~1;
	}
    }
    else {
	iseq->arg_opts = 0;
    }

    if ((long)rest_id == -1) {
	iseq->arg_rest = get_dyna_var_idx_at_raw(iseq, 0 /* dummy var */) + d;
    }
    else if (rest_id) {
	iseq->arg_rest = get_dyna_var_idx_at_raw(iseq, rest_id) + d;
    }
    if (iseq->arg_rest == -1) {
	rb_bug("arg_rest: -1");
    }

    if (block_id) {
	iseq->arg_block = get_dyna_var_idx_at_raw(iseq, block_id) + d;
    }

    if (iseq->arg_rest != 0 || iseq->arg_opts != 0 || iseq->arg_block != 0) {
	iseq->arg_simple = 0;
    }
    else {
	iseq->arg_simple = 1;
    }

    return COMPILE_OK;
}

#else

static int
set_arguments(rb_iseq_t *iseq, LINK_ANCHOR *optargs, NODE * node)
{
    int i, j;

    if (node) {
	/* normal method */
	if (node->nd_frml) {
	    iseq->argc = RARRAY_LEN(node->nd_frml);
	}
	else {
	    iseq->argc = 0;
	}

	if (node->nd_rest) {
	    iseq->arg_rest = node->nd_rest->nd_cnt - 2 + 1;
	}

	/* optional initializer */
	if (node->nd_opt) {
	    NODE *optarg = node->nd_opt;
	    LABEL *label;
	    VALUE labels = rb_ary_new();
	    i = 0;
	    while (optarg) {
		label = NEW_LABEL(nd_line(node));
		rb_ary_push(labels, (VALUE)label | 1);
		ADD_LABEL(optargs, label);
		COMPILE_POPED(optargs, "optarg", optarg->nd_head);

		optarg = optarg->nd_next;
		i += 1;
	    }
	    /* last label */
	    label = NEW_LABEL(nd_line(node));
	    rb_ary_push(labels, (VALUE)label | 1);
	    ADD_LABEL(optargs, label);
	    i += 1;

	    iseq->arg_opts = i;
	    iseq->arg_opt_tbl = ALLOC_N(VALUE, i);

	    MEMCPY(iseq->arg_opt_tbl, RARRAY_PTR(labels), VALUE, i);

	    for (j = 0; j < i; j++) {
		iseq->arg_opt_tbl[j] &= ~1;
	    }
	}
	else {
	    iseq->arg_opts = 0;
	}
    }
    else {
	iseq->argc = 0;
	iseq->arg_rest = 0;
	iseq->arg_opts = 0;
    }

    if (iseq->arg_rest != 0 || iseq->arg_opts != 0) {
	iseq->arg_simple = 0;
    }
    else {
	iseq->arg_simple = 1;
    }
    return COMPILE_OK;
}
#endif

static int
set_localtbl(rb_iseq_t *iseq, ID *tbl)
{
    int size;

    if (tbl) {
	size = *tbl - 2 /* $~, $_ */;
    }
    else {
	size = 0;
    }

    if (size > 0) {
	iseq->local_table = (ID *)ALLOC_N(ID *, size);
	MEMCPY(iseq->local_table, tbl + 3 /* size, $~, $_ */, ID *, size);
    }

    iseq->local_table_size = size;
    iseq->local_size = size + 1 /* svar */;

    return COMPILE_OK;
}

static int
set_localtbl_eval(rb_iseq_t *iseq, ID *tbl)
{
    int size;
    if (tbl) {
	size = *tbl;
    }
    else {
	size = 0;
    }
    if (tbl) {
	iseq->local_table = (ID *)ALLOC_N(ID *, size);
	MEMCPY(iseq->local_table, tbl + 1, ID *, size);
    }
    iseq->local_table_size = iseq->local_size = size;
    return COMPILE_OK;
}

/**
  ruby insn object array -> raw instruction sequence
 */
static int
set_sequence(rb_iseq_t *iseq, LINK_ANCHOR *anchor)
{
    LABEL *lobj;
    INSN *iobj;
    struct insn_info_struct *insn_info_tbl;
    LINK_ELEMENT *list;
    VALUE *generated_iseq;

    int k, pos, sp, stack_max = 0;

    GC_CHECK();

    /* set label position */
    list = FIRST_ELEMENT(anchor);
    k = pos = 0;
    while (list) {
	switch (list->type) {
	case ISEQ_ELEMENT_INSN:{
		iobj = (INSN *)list;
		pos += insn_data_length(iobj);

		k += 1;
		break;
	    }
	case ISEQ_ELEMENT_LABEL:{
		lobj = (LABEL *)list;
		lobj->position = pos;
		lobj->set = Qtrue;
		break;
	    }
	case ISEQ_ELEMENT_NONE:{
		/* ignore */
		break;
	    }
	default:
	    dump_disasm_list(FIRST_ELEMENT(anchor));
	    dump_disasm_list(list);
	    rb_bug("error: set_sequence");
	    break;
	}
	list = list->next;
    }

    /* make instruction sequence */
    generated_iseq = ALLOC_N(VALUE, pos);
    insn_info_tbl = ALLOC_N(struct insn_info_struct, k);

    GC_CHECK();

    list = FIRST_ELEMENT(anchor);
    k = pos = sp = 0;

    while (list) {
	switch (list->type) {
	case ISEQ_ELEMENT_INSN:{
		int j, len, insn;
		char *types;
		VALUE *operands;

		iobj = (INSN *)list;

		if (iobj->insn_id == BIN(emptstack) && sp == 0) {
		    iobj->insn_id = BIN(nop);
		}
		else {
		    sp = calc_sp_depth(sp, iobj);
		    if (sp > stack_max) {
			stack_max = sp;
		    }
		}

		/* fprintf(stderr, "insn: %-16s, sp: %d\n", insn_name(iobj->insn_id), sp); */

		operands = iobj->operands;
		insn = iobj->insn_id;
		generated_iseq[pos] = insn;
		types = insn_op_types(insn);
		len = insn_len(insn);

		/* operand check */
		if (iobj->operand_size != len - 1) {
		    dump_disasm_list(list);
		    rb_bug("operand size miss! (%d for %d)",
			   iobj->operand_size, len - 1);
		    return 0;
		}

		for (j = 0; types[j]; j++) {
		    char type = types[j];
		    /* printf("--> [%c - (%d-%d)]\n", type, k, j); */
		    switch (type) {
		    case TS_OFFSET:{
			    /* label(destination position) */
			    lobj = (LABEL *)operands[j];
			    if (lobj->set != Qtrue) {
				rb_bug("unknown label");
			    }
			    if (lobj->sp == -1) {
				lobj->sp = sp;
			    }
			    generated_iseq[pos + 1 + j] =
				lobj->position - (pos + len);
			    break;
			}
		    case TS_CDHASH:{
			    /*
			     * [obj, label, ...]
			     */
			    int i;
			    VALUE lits = operands[j];
			    VALUE map = rb_hash_new();

			    for (i=0; i < RARRAY_LEN(lits); i+=2) {
				VALUE obj = rb_ary_entry(lits, i);
				VALUE lv  = rb_ary_entry(lits, i+1);
				lobj = (LABEL *)(lv & ~1);
				
				if (lobj->set != Qtrue) {
				    rb_bug("unknown label");
				}
				rb_hash_aset(map, obj,
					     INT2FIX(lobj->position - (pos+len)));
			    }
			    generated_iseq[pos + 1 + j] = map;
			    iseq_add_mark_object(iseq, map);
			    break;
			}
		    case TS_LINDEX:
		    case TS_DINDEX:
		    case TS_NUM:	/* ulong */
			generated_iseq[pos + 1 + j] = FIX2INT(operands[j]);
			break;
		    case TS_ISEQ:	/* iseq */
			{
			    VALUE v = operands[j];
			    rb_iseq_t *block = 0;
			    if (v) {
				GetISeqPtr(v, block);
			    }
			    generated_iseq[pos + 1 + j] = (VALUE)block;
			    break;
			}
		    case TS_VALUE:	/* VALUE */
			{
			    VALUE v = operands[j];
			    generated_iseq[pos + 1 + j] = v;
			    /* to mark ruby object */
			    if (!SPECIAL_CONST_P(v)) {
				iseq_add_mark_object(iseq, v);
			    }
			    break;
			}
		    case TS_IC:	/* inline cache */
			{
			    VALUE v = (VALUE)NEW_INLINE_CACHE_ENTRY();
			    generated_iseq[pos + 1 + j] = v;
			    iseq_add_mark_object(iseq, v);
			    break;
			}
		    case TS_ID:	/* ID */
			generated_iseq[pos + 1 + j] = SYM2ID(operands[j]);
			break;
		    case TS_GENTRY:
			{
			    struct global_entry *entry =
				(struct global_entry *)(operands[j] & (~1));
			    generated_iseq[pos + 1 + j] = (VALUE)entry;
			}
			break;
		    default:
			rb_bug("unknown operand type: %c", type);
			return 0;
		    }
		}
		insn_info_tbl[k].line_no = iobj->line_no;
		insn_info_tbl[k].position = pos;
		pos += len;
		k++;
		break;
	    }
	case ISEQ_ELEMENT_LABEL:{
		lobj = (LABEL *)list;
		if (lobj->sp == -1) {
		    lobj->sp = sp;
		}
		else {
		    sp = lobj->sp;
		}
		break;
	    }
	default:
	    /* ignore */
	    break;
	}
	list = list->next;
    }

    {
	iseq->iseq = (void *)generated_iseq;
	iseq->size = pos;
	iseq->insn_info_tbl = insn_info_tbl;
	iseq->insn_info_size = k;
	iseq->stack_max = stack_max;
    }
    return COMPILE_OK;
}

static int
label_get_position(LABEL *lobj)
{
    return lobj->position;
}

static int
label_get_sp(LABEL *lobj)
{
    return lobj->sp;
}

static int
set_exception_table(rb_iseq_t *iseq)
{
    VALUE *tptr, *ptr;
    int tlen, i;
    struct catch_table_entry *entry;

    tlen = RARRAY_LEN(iseq->compile_data->catch_table_ary);
    tptr = RARRAY_PTR(iseq->compile_data->catch_table_ary);

    iseq->catch_table = ALLOC_N(struct catch_table_entry, tlen);
    iseq->catch_table_size = tlen;

    for (i = 0; i < tlen; i++) {
	ptr = RARRAY_PTR(tptr[i]);
	entry = &iseq->catch_table[i];
	entry->type = ptr[0] & 0xffff;
	entry->start = label_get_position((LABEL *)(ptr[1] & ~1));
	entry->end = label_get_position((LABEL *)(ptr[2] & ~1));
	entry->iseq = ptr[3];

	/* register iseq as mark object */
	if (entry->iseq != 0) {
	    iseq_add_mark_object(iseq, entry->iseq);
	}

	/* stack depth */
	if (ptr[4]) {
	    LABEL *lobj = (LABEL *)(ptr[4] & ~1);
	    entry->cont = label_get_position(lobj);
	    entry->sp = label_get_sp(lobj);

	    /* TODO: Dirty Hack!  Fix me */
	    if (entry->type == CATCH_TYPE_RESCUE ||
		entry->type == CATCH_TYPE_BREAK ||
		(((ptr[0] & 0x10000) == 0)
		 && entry->type == CATCH_TYPE_NEXT)) {
		entry->sp--;
	    }
	}
	else {
	    entry->cont = 0;
	}
    }

    iseq->compile_data->catch_table_ary = 0;	/* free */
    return COMPILE_OK;
}

/*
 * set optional argument table
 *   def foo(a, b=expr1, c=expr2)
 *   =>
 *    b:
 *      expr1
 *    c:
 *      expr2
 */
static int
set_optargs_table(rb_iseq_t *iseq)
{
    int i;

    if (iseq->arg_opts != 0) {
	for (i = 0; i < iseq->arg_opts; i++) {
	    iseq->arg_opt_tbl[i] =
		label_get_position((LABEL *)iseq->arg_opt_tbl[i]);
	}
    }
    return COMPILE_OK;
}

static LINK_ELEMENT *
get_destination_insn(INSN *iobj)
{
    LABEL *lobj = (LABEL *)OPERAND_AT(iobj, 0);
    LINK_ELEMENT *list;

    list = lobj->link.next;
    while (list) {
	if (list->type == ISEQ_ELEMENT_INSN) {
	    break;
	}
	list = list->next;
    }
    return list;
}

static LINK_ELEMENT *
get_next_insn(INSN *iobj)
{
    LINK_ELEMENT *list = iobj->link.next;

    while (list) {
	if (list->type == ISEQ_ELEMENT_INSN) {
	    return list;
	}
	list = list->next;
    }
    return 0;
}

static LINK_ELEMENT *
get_prev_insn(INSN *iobj)
{
    LINK_ELEMENT *list = iobj->link.prev;

    while (list) {
	if (list->type == ISEQ_ELEMENT_INSN) {
	    return list;
	}
	list = list->prev;
    }
    return 0;
}

static int
iseq_peephole_optimize(rb_iseq_t *iseq, LINK_ELEMENT *list)
{
    INSN *iobj = (INSN *)list;
  again:
    if (iobj->insn_id == BIN(jump)) {
	INSN *niobj, *diobj, *piobj;
	/*
	 *  useless jump elimination:
	 *     jump LABEL1
	 *     ...
	 *   LABEL1:
	 *     jump LABEL2
	 *
	 *   => in this case, first jump instruction should jump tp
	 *      LABEL2 directly
	 */
	diobj = (INSN *)get_destination_insn(iobj);
	niobj = (INSN *)get_next_insn(iobj);

	if (diobj == niobj) {
	    REMOVE_ELEM(&iobj->link);
	}
	else if (iobj != diobj && diobj->insn_id == BIN(jump)) {
	    OPERAND_AT(iobj, 0) = OPERAND_AT(diobj, 0);
	    goto again;
	}
	else if (diobj->insn_id == BIN(leave)) {
	    INSN *eiobj = new_insn_core(iseq, iobj->line_no, BIN(leave),
					diobj->operand_size,
					diobj->operands);
	    /* replace */
	    REPLACE_ELEM((LINK_ELEMENT *)iobj, (LINK_ELEMENT *)eiobj);
	}
	/*
	 * useless jump elimination (if/unless destination):
	 *   if   L1
	 *   jump L2
	 * L1:
	 *   ...
	 * L2:
	 *
	 * ==>
	 *   unless L2
	 * L1:
	 *   ...
	 * L2:
	 */
	else if ((piobj = (INSN *)get_prev_insn(iobj)) != 0 &&
		 (piobj->insn_id == BIN(branchif) ||
		  piobj->insn_id == BIN(branchunless))) {
	    if (niobj == (INSN *)get_destination_insn(piobj)) {
		piobj->insn_id = (piobj->insn_id == BIN(branchif))
		  ? BIN(branchunless) : BIN(branchif) ;
		OPERAND_AT(piobj, 0) = OPERAND_AT(iobj, 0);
		REMOVE_ELEM(&iobj->link);
	    }
	}
    }
    if (iobj->insn_id == BIN(branchif) ||
	iobj->insn_id == BIN(branchunless)) {
	/*
	 *   if L1
	 *   ...
	 * L1:
	 *   jump L2
	 * =>
	 *   if L2
	 */
	INSN *nobj = (INSN *)get_destination_insn(iobj);
	if (nobj->insn_id == BIN(jump)) {
	    OPERAND_AT(iobj, 0) = OPERAND_AT(nobj, 0);
	}
    }

    if (iobj->insn_id == BIN(leave)) {
	INSN *piobj = (INSN *)get_prev_insn((INSN *)list);
	if (piobj->insn_id == BIN(send)) {
	    /* TODO: tail call optimization */
	    if (piobj->operands[2] == 0) {
		/* piobj->operands[3] = INT2FIX(FIX2INT(piobj->operands[3]) | VM_CALL_TAILCALL_BIT); */
		/* piobj->operands[3] = INT2FIX(FIX2INT(piobj->operands[3]) | VM_CALL_TAILRECURSION_BIT); */
	    }
	}
    }
    return COMPILE_OK;
}

static int
insn_set_specialized_instruction(INSN *iobj, int insn_id)
{
    iobj->insn_id = insn_id;
    iobj->operand_size = 0;
    return COMPILE_OK;
}


static int
iseq_specialized_instruction(rb_iseq_t *iseq, INSN *iobj)
{
    if (iobj->insn_id == BIN(send)) {
	ID mid = SYM2ID(OPERAND_AT(iobj, 0));
	int argc = FIX2INT(OPERAND_AT(iobj, 1));
	VALUE block = OPERAND_AT(iobj, 2);
	VALUE flag = OPERAND_AT(iobj, 3);

	/* TODO: should be more sophisticated search */
	if (block == 0 && flag == INT2FIX(0)) {
	    if (argc == 0) {
		if (mid == idLength) {
		    insn_set_specialized_instruction(iobj, BIN(opt_length));
		}
		else if (mid == idSucc) {
		    insn_set_specialized_instruction(iobj, BIN(opt_succ));
		}
	    }
	    else if (argc == 1) {
		if (0) {
		}
		else if (mid == idPLUS) {
		    insn_set_specialized_instruction(iobj, BIN(opt_plus));
		}
		else if (mid == idMINUS) {
		    insn_set_specialized_instruction(iobj, BIN(opt_minus));
		}
		else if (mid == idMULT) {
		    insn_set_specialized_instruction(iobj, BIN(opt_mult));
		}
		else if (mid == idDIV) {
		    insn_set_specialized_instruction(iobj, BIN(opt_div));
		}
		else if (mid == idMOD) {
		    insn_set_specialized_instruction(iobj, BIN(opt_mod));
		}
		else if (mid == idEq) {
		    insn_set_specialized_instruction(iobj, BIN(opt_eq));
		}
		else if (mid == idLT) {
		    insn_set_specialized_instruction(iobj, BIN(opt_lt));
		}
		else if (mid == idLE) {
		    insn_set_specialized_instruction(iobj, BIN(opt_le));
		}
		else if (mid == idLTLT) {
		    insn_set_specialized_instruction(iobj, BIN(opt_ltlt));
		}
		else if (mid == idAREF) {
		    insn_set_specialized_instruction(iobj, BIN(opt_aref));
		}
	    }
	}

	if (mid == idSend || mid == id__send__ || mid == id__send ||
		 mid == idFuncall || mid == id__send_bang) {
	    OPERAND_AT(iobj, 3) |= INT2FIX(VM_CALL_SEND_BIT);
	}
    }
    return COMPILE_OK;
}

static int
iseq_optimize(rb_iseq_t *iseq, LINK_ANCHOR *anchor)
{
    LINK_ELEMENT *list;
    const int do_peephole = iseq->compile_data->option->peephole_optimization;
    const int do_si = iseq->compile_data->option->specialized_instruction;
    const int do_ou = iseq->compile_data->option->operands_unification;
    list = FIRST_ELEMENT(anchor);
    
    while (list) {
	if (list->type == ISEQ_ELEMENT_INSN) {
	    if (do_peephole) {
		iseq_peephole_optimize(iseq, list);
	    }
	    if (do_si) {
		iseq_specialized_instruction(iseq, (INSN *)list);
	    }
	    if (do_ou) {
		insn_operands_unification((INSN *)list);
	    }
	}
	list = list->next;
    }
    return COMPILE_OK;
}

#if OPT_INSTRUCTIONS_UNIFICATION
static INSN *
new_unified_insn(rb_iseq_t *iseq,
		 int insn_id, int size, LINK_ELEMENT *seq_list)
{
    INSN *iobj = 0;
    LINK_ELEMENT *list = seq_list;
    int i, argc = 0;
    VALUE *operands = 0, *ptr = 0;


    /* count argc */
    for (i = 0; i < size; i++) {
	iobj = (INSN *)list;
	argc += iobj->operand_size;
	list = list->next;
    }

    if (argc > 0) {
	ptr = operands =
	    (VALUE *)compile_data_alloc(iseq, sizeof(VALUE) * argc);
    }

    /* copy operands */
    list = seq_list;
    for (i = 0; i < size; i++) {
	iobj = (INSN *)list;
	MEMCPY(ptr, iobj->operands, VALUE, iobj->operand_size);
	ptr += iobj->operand_size;
	list = list->next;
    }

    return new_insn_core(iseq, iobj->line_no, insn_id, argc, operands);
}
#endif

/*
 * This scheme can get more performance if do this optimize with
 * label address resolving.
 * It's future work (if compile time was bottle neck).
 */
static int
iseq_insns_unification(rb_iseq_t *iseq, LINK_ANCHOR *anchor)
{
#if OPT_INSTRUCTIONS_UNIFICATION
    LINK_ELEMENT *list;
    INSN *iobj, *niobj;
    int id, j, k;

    list = FIRST_ELEMENT(anchor);
    while (list) {
	if (list->type == ISEQ_ELEMENT_INSN) {
	    iobj = (INSN *)list;
	    id = iobj->insn_id;
	    if (unified_insns_data[id] != 0) {
		int **entry = unified_insns_data[id];
		for (j = 1; j < (int)entry[0]; j++) {
		    int *unified = entry[j];
		    LINK_ELEMENT *li = list->next;
		    for (k = 2; k < unified[1]; k++) {
			if (li->type != ISEQ_ELEMENT_INSN ||
			    ((INSN *)li)->insn_id != unified[k]) {
			    goto miss;
			}
			li = li->next;
		    }
		    /* matched */
		    niobj =
			new_unified_insn(iseq, unified[0], unified[1] - 1,
					 list);

		    /* insert to list */
		    niobj->link.prev = (LINK_ELEMENT *)iobj->link.prev;
		    niobj->link.next = li;
		    if (li) {
			li->prev = (LINK_ELEMENT *)niobj;
		    }

		    list->prev->next = (LINK_ELEMENT *)niobj;
		    list = (LINK_ELEMENT *)niobj;
		    break;
		  miss:;
		}
	    }
	}
	list = list->next;
    }
#endif
    return COMPILE_OK;
}

#if OPT_STACK_CACHING

#define SC_INSN(insn, stat) sc_insn_info[(insn)][(stat)]
#define SC_NEXT(insn)       sc_insn_next[insn]

#include "opt_sc.inc"

static int
insn_set_sc_state(INSN *iobj, int state)
{
    int nstate;
    int insn_id;

    insn_id = iobj->insn_id;
    iobj->insn_id = SC_INSN(insn_id, state);
    nstate = SC_NEXT(iobj->insn_id);

    if (insn_id == BIN(jump) ||
	insn_id == BIN(branchif) || insn_id == BIN(branchunless)) {
	LABEL *lobj = (LABEL *)OPERAND_AT(iobj, 0);

	if (lobj->sc_state != 0) {
	    if (lobj->sc_state != nstate) {
		dump_disasm_list((LINK_ELEMENT *)iobj);
		dump_disasm_list((LINK_ELEMENT *)lobj);
		printf("\n-- %d, %d\n", lobj->sc_state, nstate);
		rb_bug("insn_set_sc_state error\n");
		return 0;
	    }
	}
	else {
	    lobj->sc_state = nstate;
	}
	if (insn_id == BIN(jump)) {
	    nstate = SCS_XX;
	}
    }
    else if (insn_id == BIN(leave)) {
	nstate = SCS_XX;
    }

    return nstate;
}

static int
label_set_sc_state(LABEL *lobj, int state)
{
    if (lobj->sc_state != 0) {
	if (lobj->sc_state != state) {
	    state = lobj->sc_state;
	}
    }
    else {
	lobj->sc_state = state;
    }

    return state;
}


#endif

static int
set_sequence_stackcaching(rb_iseq_t *iseq, LINK_ANCHOR *anchor)
{
#if OPT_STACK_CACHING
    LINK_ELEMENT *list;
    int state, insn_id;

    /* initialize */
    state = SCS_XX;
    list = FIRST_ELEMENT(anchor);
    /* dump_disasm_list(list); */

    /* for each list element */
    while (list) {
      redo_point:
	switch (list->type) {
	case ISEQ_ELEMENT_INSN:{
		INSN *iobj = (INSN *)list;
		insn_id = iobj->insn_id;

		/* dump_disasm_list(list); */

		switch (insn_id) {
		case BIN(nop):{
			/* exception merge point */
			if (state != SCS_AX) {
			    INSN *rpobj =
				new_insn_body(iseq, 0, BIN(reput), 0);

			    /* replace this insn */
			    REPLACE_ELEM(list, (LINK_ELEMENT *)rpobj);
			    list = (LINK_ELEMENT *)rpobj;
			    goto redo_point;
			}
			break;
		    }
		case BIN(swap):{
			if (state == SCS_AB || state == SCS_BA) {
			    state = (state == SCS_AB ? SCS_BA : SCS_AB);

			    REMOVE_ELEM(list);
			    list = list->next;
			    goto redo_point;
			}
			break;
		    }
		case BIN(pop):{
			switch (state) {
			case SCS_AX:
			case SCS_BX:
			    state = SCS_XX;
			    break;
			case SCS_AB:
			    state = SCS_AX;
			    break;
			case SCS_BA:
			    state = SCS_BX;
			    break;
			case SCS_XX:
			    goto normal_insn;
			default:
			    rb_bug("unreachable");
			}
			/* remove useless pop */
			REMOVE_ELEM(list);
			list = list->next;
			goto redo_point;
		    }
		default:;
		    /* none */
		}		/* end of switch */
	      normal_insn:
		state = insn_set_sc_state(iobj, state);
		break;
	    }
	case ISEQ_ELEMENT_LABEL:{
		LABEL *lobj;
		lobj = (LABEL *)list;

		state = label_set_sc_state(lobj, state);
	    }
	default:
	    break;
	}
	list = list->next;
    }
#endif
    return COMPILE_OK;
}



static int
compile_dstr(rb_iseq_t *iseq, LINK_ANCHOR *ret, NODE * node)
{
    NODE *list = node->nd_next;
    VALUE lit = node->nd_lit;
    int cnt = 1;
    
    debugp_param("nd_lit", lit);
    ADD_INSN1(ret, nd_line(node), putobject, node->nd_lit);

    while (list) {
	COMPILE(ret, "each string", list->nd_head);
	cnt++;
	list = list->nd_next;
    }

    ADD_INSN1(ret, nd_line(node), concatstrings, INT2FIX(cnt));
    return COMPILE_OK;
}

static int
compile_branch_condition(rb_iseq_t *iseq, LINK_ANCHOR *ret, NODE * cond,
			 LABEL *then_label, LABEL *else_label)
{
    switch (nd_type(cond)) {
    case NODE_NOT:
	compile_branch_condition(iseq, ret, cond->nd_body, else_label,
				 then_label);
	break;

    case NODE_AND:{
	    LABEL *label = NEW_LABEL(nd_line(cond));
	    compile_branch_condition(iseq, ret, cond->nd_1st, label,
				     else_label);
	    ADD_LABEL(ret, label);
	    compile_branch_condition(iseq, ret, cond->nd_2nd, then_label,
				     else_label);
	    break;
	}
    case NODE_OR:{
	    LABEL *label = NEW_LABEL(nd_line(cond));
	    compile_branch_condition(iseq, ret, cond->nd_1st, then_label,
				     label);
	    ADD_LABEL(ret, label);
	    compile_branch_condition(iseq, ret, cond->nd_2nd, then_label,
				     else_label);
	    break;
	}
    case NODE_LIT:		/* NODE_LIT is always not true */
    case NODE_TRUE:
    case NODE_STR:
	/* printf("useless conditon eliminate (%s)\n",  ruby_node_name(nd_type(cond))); */
	ADD_INSNL(ret, nd_line(cond), jump, then_label);
	break;
    case NODE_FALSE:
    case NODE_NIL:
	/* printf("useless conditon eliminate (%s)\n", ruby_node_name(nd_type(cond))); */
	ADD_INSNL(ret, nd_line(cond), jump, else_label);
	break;
    default:
	COMPILE(ret, "branch condition", cond);
	ADD_INSNL(ret, nd_line(cond), branchunless, else_label);
	ADD_INSNL(ret, nd_line(cond), jump, then_label);
	break;
    }
    return COMPILE_OK;
}

static int
compile_array(rb_iseq_t *iseq,
	      LINK_ANCHOR *ret, NODE * node_root, VALUE opt_p)
{
    NODE *node = node_root;
    int len = node->nd_alen, line = nd_line(node), i=0;
    DECL_ANCHOR(anchor);

    while (node) {
	i++;
	if (opt_p && nd_type(node->nd_head) != NODE_LIT) {
	    opt_p = Qfalse;
	}
	COMPILE(anchor, "array element", node->nd_head);
	node = node->nd_next;
    }

    if (len != i) {
	if (0) rb_bug("node error: compile_array (%d: %d-%d)",
		      nd_line(node_root), len, i);
	len = i;
    }

    if (opt_p == Qtrue) {
	VALUE ary = rb_ary_new();
	node = node_root;
	while (node) {
	    rb_ary_push(ary, node->nd_head->nd_lit);
	    node = node->nd_next;
	}

	iseq_add_mark_object_compile_time(iseq, ary);
	ADD_INSN1(ret, nd_line(node_root), duparray, ary);
    }
    else {
	ADD_INSN1(anchor, line, newarray, INT2FIX(len));
	APPEND_LIST(ret, anchor);
    }
    return len;
}

static VALUE
case_when_optimizable_literal(NODE * node)
{
    if (nd_type(node) == NODE_LIT) {
	VALUE v = node->nd_lit;
	if (SYMBOL_P(v) || rb_obj_is_kind_of(v, rb_cNumeric)) {
	    return v;
	}
    }
    else if (nd_type(node) == NODE_STR) {
	return node->nd_lit;
    }
    return Qfalse;
}

static VALUE
when_vals(rb_iseq_t *iseq, LINK_ANCHOR *cond_seq, NODE *vals, LABEL *l1, VALUE special_literals)
{
    while (vals) {
	VALUE lit;
	NODE* val;

	val = vals->nd_head;

	if (special_literals &&
	    (lit = case_when_optimizable_literal(val)) != Qfalse) {
	    rb_ary_push(special_literals, lit);
	    rb_ary_push(special_literals, (VALUE)(l1) | 1);
	}
	else {
	    special_literals = Qfalse;
	}

	COMPILE(cond_seq, "when cond", val);
	ADD_INSN1(cond_seq, nd_line(val), topn, INT2FIX(1));
	ADD_SEND(cond_seq, nd_line(val), ID2SYM(idEqq), INT2FIX(1));
	ADD_INSNL(cond_seq, nd_line(val), branchif, l1);
	vals = vals->nd_next;
    }
    return special_literals;
}

static int
make_masgn_lhs(rb_iseq_t *iseq, LINK_ANCHOR *ret, NODE * node)
{

    switch (nd_type(node)) {
    case NODE_ATTRASGN:{
	INSN *iobj;
	VALUE dupidx;

	COMPILE_POPED(ret, "masgn lhs (NODE_ATTRASGN)", node);
	POP_ELEMENT(ret);        /* pop pop insn */
	iobj = (INSN *)POP_ELEMENT(ret); /* pop send insn */

	dupidx = iobj->operands[1];
	dupidx = INT2FIX(FIX2INT(dupidx) + 1);
	iobj->operands[1] = dupidx;

	ADD_INSN1(ret, nd_line(node), topn, dupidx);
	ADD_ELEM(ret, (LINK_ELEMENT *)iobj);
	ADD_INSN(ret, nd_line(node), pop);	/* result */
	ADD_INSN(ret, nd_line(node), pop);	/* rhs    */
	break;
    }

    case NODE_MASGN:
	COMPILE_POPED(ret, "nest masgn lhs", node);
	break;

    default:{
	    DECL_ANCHOR(anchor);
	    COMPILE_POPED(anchor, "masgn lhs", node);
	    /* dump_disasm_list(FIRST_ELEMENT(anchor)); */
	    REMOVE_ELEM(FIRST_ELEMENT(anchor));
	    /* dump_disasm_list(FIRST_ELEMENT(anchor)); */
	    ADD_SEQ(ret, anchor);
	    /* ADD_ELEM(ret, LAST_ELEMENT(anchor)); */
	}
    }

    return COMPILE_OK;
}

static int
compile_massign(rb_iseq_t *iseq, LINK_ANCHOR *ret,
		NODE * rhsn, NODE * splatn, NODE * lhsn, int llen)
{
    if (lhsn != 0) {
	compile_massign(iseq, ret, rhsn, splatn, lhsn->nd_next, llen + 1);
	make_masgn_lhs(iseq, ret, lhsn->nd_head);
    }
    else {
	int lhs_splat = 0;

	if (splatn && (VALUE)splatn != -1) {
	    lhs_splat = 1;
	}

	if (rhsn) {
	    switch (nd_type(rhsn)) {
	    case NODE_ARRAY:{
		    int rlen = rhsn->nd_alen;
		    int max = rlen > llen ? rlen : llen;
		    int i, si = 0;

		    for (i = 0; i < max; i++) {
			if (i < rlen && i < llen) {
			    /* a, b = c, d */
			    COMPILE(ret, "masgn val1", rhsn->nd_head);
			    rhsn = rhsn->nd_next;
			}
			else if (i < rlen) {
			    if (lhs_splat) {
				while (rhsn) {
				    /* a, *b = x, y, z */
				    si++;
				    COMPILE(ret, "masgn rhs for lhs splat",
					    rhsn->nd_head);
				    rhsn = rhsn->nd_next;
				}
				break;
			    }
			    else {
				/* a, b = c, d, e */
				COMPILE_POPED(ret, "masgn rhs (popped)",
					      rhsn->nd_head);
				rhsn = rhsn->nd_next;
			    }
			}
			else if (i < llen) {
			    /* a, b, c = c, d */
			    ADD_INSN(ret, 0, putnil);
			}
		    }

		    if (lhs_splat) {
			ADD_INSN1(ret, 0, newarray, INT2FIX(si));
		    }
		    break;
		}
	    case NODE_TO_ARY:
		COMPILE(ret, "rhs to ary", rhsn->nd_head);
		ADD_INSN2(ret, nd_line(rhsn), expandarray, INT2FIX(llen),
			  INT2FIX(lhs_splat));
		break;

	    case NODE_SPLAT:
		COMPILE(ret, "rhs to ary (splat)", rhsn->nd_head);
		ADD_INSN2(ret, nd_line(rhsn), expandarray, INT2FIX(llen),
			  INT2FIX(lhs_splat));
		break;

	    case NODE_ARGSCAT:{
		    NODE *ary = rhsn->nd_head;
		    int idx = 0;

		    while (ary) {
			if (idx < llen || lhs_splat) {
			    COMPILE(ret, "rhs aggscat each head",
				    ary->nd_head);
			}
			else {
			    COMPILE_POPED(ret,
					  "rhs aggscat each head (popped)",
					  ary->nd_head);
			}
			ary = ary->nd_next;
			idx++;
		    }

		    if (llen > idx) {
			COMPILE(ret, "rhs to ary (argscat/splat)",
				rhsn->nd_body);
			ADD_INSN2(ret, nd_line(rhsn), expandarray,
				  INT2FIX(llen - idx), INT2FIX(lhs_splat));
		    }
		    else if (lhs_splat) {
			COMPILE(ret, "rhs to ary (argscat/splat)",
				rhsn->nd_body);
			ADD_INSN2(ret, nd_line(rhsn), expandarray,
				  INT2FIX(llen - idx), INT2FIX(lhs_splat));
		    }
		    break;
		}
	    default:
		COMPILE(ret, "rhs to ary (splat/default)", rhsn);
		ADD_INSN2(ret, nd_line(rhsn), expandarray, INT2FIX(llen),
			  INT2FIX(lhs_splat));
		/* rb_bug("unknown rhs: %s", ruby_node_name(nd_type(rhsn))); */
	    }
	}
	else {
	    /* nested massign */
	    ADD_INSN2(ret, 0, expandarray, INT2FIX(llen), INT2FIX(lhs_splat));
	}

	if (lhs_splat) {
	    make_masgn_lhs(iseq, ret, splatn);
	}
    }
    return COMPILE_OK;
}

static int
compile_colon2(rb_iseq_t *iseq, NODE * node,
	       LINK_ANCHOR *pref, LINK_ANCHOR *body)
{
    switch (nd_type(node)) {
      case NODE_CONST:
	debugi("compile_colon2 - colon", node->nd_vid);
	ADD_INSN1(body, nd_line(node), getconstant, ID2SYM(node->nd_vid));
	break;
      case NODE_COLON3:
	debugi("compile_colon2 - colon3", node->nd_mid);
	ADD_INSN(body, nd_line(node), pop);
	ADD_INSN1(body, nd_line(node), putobject, rb_cObject);
	ADD_INSN1(body, nd_line(node), getconstant, ID2SYM(node->nd_mid));
	break;
      case NODE_COLON2:
	compile_colon2(iseq, node->nd_head, pref, body);
	debugi("compile_colon2 - colon2", node->nd_mid);
	ADD_INSN1(body, nd_line(node), getconstant, ID2SYM(node->nd_mid));
	break;
      default:
	COMPILE(pref, "const colon2 prefix", node);
	break;
    }
    return COMPILE_OK;
}

static int
compile_cpath(LINK_ANCHOR *ret, rb_iseq_t *iseq, NODE *cpath)
{
    if(cpath->nd_head) {
	COMPILE(ret, "nd_else->nd_head", cpath->nd_head);
    }
    else if (nd_type(cpath) == NODE_COLON2) {
	COMPILE(ret, "cpath (NODE_COLON2)", cpath->nd_head);
    }
    else {
	ADD_INSN1(ret, nd_line(cpath), putobject, rb_cObject);
    }
    return COMPILE_OK;
}

static int
defined_expr(rb_iseq_t *iseq, LINK_ANCHOR *ret,
	     NODE * node, LABEL *lfinish, VALUE needstr)
{
    char *estr = 0;

    switch (nd_type(node)) {

	/* easy literals */
      case NODE_NIL:
	estr = "nil";
	break;
      case NODE_SELF:
	estr = "self";
	break;
      case NODE_TRUE:
	estr = "true";
	break;
      case NODE_FALSE:
	estr = "false";
	break;
      case NODE_STR:
      case NODE_LIT:
	estr = "expression";
	break;

	/* variables */
      case NODE_LVAR:
      case NODE_DVAR:
	estr = "local-variable";
	break;

      case NODE_IVAR:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_IVAR),
		  ID2SYM(node->nd_vid), needstr);
	return 1;

      case NODE_GVAR:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_GVAR),
		  ((VALUE)node->nd_entry) | 1, needstr);
	return 1;

      case NODE_CVAR:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_CVAR),
		  ID2SYM(node->nd_vid), needstr);
	return 1;

      case NODE_CONST:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_CONST),
		  ID2SYM(node->nd_vid), needstr);
	return 1;
      case NODE_COLON2:
	if (rb_is_const_id(node->nd_mid)) {
	    LABEL *lcont = NEW_LABEL(nd_line(node));
	    defined_expr(iseq, ret, node->nd_head, lfinish, Qfalse);

	    ADD_INSNL(ret, nd_line(node), branchif, lcont) ;
	    ADD_INSN(ret, nd_line(node), putnil);
	    ADD_INSNL(ret, nd_line(node), jump, lfinish);

	    ADD_LABEL(ret, lcont);
	    COMPILE(ret, "defined/colon2#nd_head", node->nd_head);
	    ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_CONST),
		      ID2SYM(node->nd_mid), needstr);
	}
	else {
	    LABEL *lcont = NEW_LABEL(nd_line(node));
	    defined_expr(iseq, ret, node->nd_head, lfinish, Qfalse);

	    ADD_INSNL(ret, nd_line(node), branchif, lcont) ;
	    ADD_INSN(ret, nd_line(node), putnil);
	    ADD_INSNL(ret, nd_line(node), jump, lfinish);

	    ADD_LABEL(ret, lcont);
	    COMPILE(ret, "defined/colon2#nd_head", node->nd_head);
	    ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_METHOD),
		      ID2SYM(node->nd_mid), needstr);
	}
	return 1;
      case NODE_COLON3:
	ADD_INSN1(ret, nd_line(node), putobject, rb_cObject);
	ADD_INSN3(ret, nd_line(node), defined,
		  INT2FIX(DEFINED_CONST), ID2SYM(node->nd_mid), needstr);
	return 1;

	/* method dispatch */
      case NODE_CALL:
      case NODE_VCALL:
      case NODE_FCALL:
	if (nd_type(node) == NODE_CALL) {
	    LABEL *lcont = NEW_LABEL(nd_line(node));

	    defined_expr(iseq, ret, node->nd_recv, lfinish, Qfalse);
	    ADD_INSNL(ret, nd_line(node), branchif, lcont) ;
	    ADD_INSN(ret, nd_line(node), putnil);
	    ADD_INSNL(ret, nd_line(node), jump, lfinish);

	    ADD_LABEL(ret, lcont);
	    COMPILE(ret, "defined/recv", node->nd_recv);
	    ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_METHOD),
		      ID2SYM(node->nd_mid), needstr);
	}
	else {
	    ADD_INSN(ret, nd_line(node), putself);
	    ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_FUNC),
		      ID2SYM(node->nd_mid), needstr);
	}
	return 1;

      case NODE_YIELD:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_YIELD), 0,
		  needstr);
	return 1;

      case NODE_NTH_REF:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_REF),
		  INT2FIX(node->nd_nth), needstr);
	return 1;

      case NODE_ZSUPER:
	ADD_INSN(ret, nd_line(node), putnil);
	ADD_INSN3(ret, nd_line(node), defined, INT2FIX(DEFINED_ZSUPER), 0,
		  needstr);
	return 1;

      default:{
	  LABEL *lstart = NEW_LABEL(nd_line(node));
	  LABEL *lend = NEW_LABEL(nd_line(node));
	  LABEL *ldefed = NEW_LABEL(nd_line(node));
	  VALUE str = rb_str_new2("expression");
	  VALUE tmp;
	  VALUE ensure = NEW_CHILD_ISEQVAL(NEW_NIL(),
					   rb_str_concat(rb_str_new2
							 ("defined guard in "),
							 iseq->name),
					   ISEQ_TYPE_DEFINED_GUARD);

	  iseq_add_mark_object_compile_time(iseq, str);

	  ADD_LABEL(ret, lstart);
	  COMPILE(ret, "defined expr (others)", node);
	  ADD_INSNL(ret, nd_line(node), branchif, ldefed) ;
	  ADD_INSN(ret, nd_line(node), putnil);
	  ADD_INSNL(ret, nd_line(node), jump, lend);
	  ADD_LABEL(ret, ldefed);
	  ADD_INSN1(ret, nd_line(node), putobject, str);
	  ADD_LABEL(ret, lend);

	  ADD_CATCH_ENTRY(CATCH_TYPE_ENSURE, lstart, lend, ensure, lfinish);
	  return 1;
	  /* rb_bug("unimplemented defined: %s", ruby_node_name(nd_type(node))); */
      }			/* end of default */
    }

    if (estr != 0) {
	if (needstr != Qfalse) {
	    VALUE str = rb_str_new2(estr);
	    ADD_INSN1(ret, nd_line(node), putstring, str);
	    iseq_add_mark_object_compile_time(iseq, str);
	}
	else {
	    ADD_INSN1(ret, nd_line(node), putobject, Qtrue);
	}
	return 1;
    }
    return 0;
}

#define BUFSIZE 0x100

static VALUE
make_name_for_block(rb_iseq_t *iseq)
{
    char buf[BUFSIZE];
    if (iseq->parent_iseq == 0) {
	snprintf(buf, BUFSIZE, "block in %s", RSTRING_PTR(iseq->name));
    }
    else {
	int level = 1;
	rb_iseq_t *ip = iseq;
	while (1) {
	    if (ip->local_iseq != ip) {
		ip = ip->parent_iseq;
	    }
	    else {
		break;
	    }
	    level++;
	}
	snprintf(buf, BUFSIZE, "block (%d levels) in %s", level,
		 RSTRING_PTR(ip->name));
    }
    return rb_str_new2(buf);
}

static VALUE
make_name_with_str(const char *fmt, const char *str)
{
    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, fmt, str);
    return rb_str_new2(buf);
}

static void
add_ensure_range(rb_iseq_t *iseq, struct ensure_range *erange,
		 LABEL *lstart, LABEL *lend)
{
    struct ensure_range *ne =
	compile_data_alloc(iseq, sizeof(struct ensure_range));

    while (erange->next != 0) {
	erange = erange->next;
    }
    ne->next = 0;
    ne->begin = lend;
    ne->end = erange->end;
    erange->end = lstart;

    erange->next = ne;
}

static void
add_ensure_iseq(LINK_ANCHOR *ret, rb_iseq_t *iseq)
{
    struct iseq_compile_data_ensure_node_stack *enlp =
	iseq->compile_data->ensure_node_stack;
    struct iseq_compile_data_ensure_node_stack *prev_enlp = enlp;
    DECL_ANCHOR(ensure);

    while (enlp) {
	DECL_ANCHOR(ensure_part);
	LABEL *lstart = NEW_LABEL(0);
	LABEL *lend = NEW_LABEL(0);
	add_ensure_range(iseq, enlp->erange, lstart, lend);

	iseq->compile_data->ensure_node_stack = enlp->prev;
	ADD_LABEL(ensure_part, lstart);
	COMPILE_POPED(ensure_part, "ensure part", enlp->ensure_node);
	ADD_LABEL(ensure_part, lend);

	ADD_SEQ(ensure, ensure_part);
	enlp = enlp->prev;
    }
    iseq->compile_data->ensure_node_stack = prev_enlp;
    ADD_SEQ(ret, ensure);
}

static VALUE
setup_arg(rb_iseq_t *iseq, LINK_ANCHOR *args, NODE *node, VALUE *flag)
{
    VALUE argc = INT2FIX(0);
    NODE *argn = node->nd_args;
    DECL_ANCHOR(arg_block);
    DECL_ANCHOR(args_push);
    
    if (argn && nd_type(argn) == NODE_BLOCK_PASS) {
	COMPILE(arg_block, "block", argn->nd_body);
	*flag |= VM_CALL_ARGS_BLOCKARG_BIT;
	argn = argn->nd_head;
    }

  setup_argn:
    if (argn) {
	switch (nd_type(argn)) {
	  case NODE_SPLAT: {
	      COMPILE(args, "args (splat)", argn->nd_head);
	      argc = INT2FIX(1);
	      *flag |= VM_CALL_ARGS_SPLAT_BIT;
	      break;
	  }
	  case NODE_ARGSCAT: {
	      argc = INT2FIX(compile_array(iseq, args, argn->nd_head, Qfalse) + 1);
	      POP_ELEMENT(args);
	      COMPILE(args, "args (cat: splat)", argn->nd_body);
	      *flag |= VM_CALL_ARGS_SPLAT_BIT;
	      break;
	  }
	  case NODE_ARGSPUSH: {
	      DECL_ANCHOR(args_push_e);
	      COMPILE(args_push_e, "argspush (cdr)", argn->nd_body);
	      ADD_INSN(args_push_e, nd_line(node), concatarray);
	      INSERT_LIST(args_push, args_push_e);
	      argn = argn->nd_head;
	      goto setup_argn;
	  }
	  default: {
	      argc = INT2FIX(compile_array(iseq, args, argn, Qfalse));
	      POP_ELEMENT(args);
	      break;
	  }
	}
    }

    if (!LIST_SIZE_ZERO(args_push)) {
	ADD_SEQ(args, args_push);
    }

    if (*flag & VM_CALL_ARGS_BLOCKARG_BIT) {
	ADD_SEQ(args, arg_block);
    }
    return argc;
}
     

/**
  compile each node

  self:  InstructionSequence
  node:  Ruby compiled node
  poped: This node will be poped
 */
static int
iseq_compile_each(rb_iseq_t *iseq, LINK_ANCHOR *ret, NODE * node, int poped)
{
    VALUE tmp;			/* reserved for macro */
    int type;

    GC_CHECK();

    if (node == 0) {
	if (!poped) {
	    debug_nodeprint("NODE_NIL(implicit)");
	    debug_nodeprint_close();
	    ADD_INSN(ret, 0, putnil);
	    return COMPILE_OK;
	}
	return COMPILE_OK;
    }

    iseq->compile_data->last_line = nd_line(node);
    debug_nodeprint(node);

    type = nd_type(node);

    switch (type) {

      case NODE_METHOD:{
	  /* OK */
	  bp();
	  COMPILE_ERROR(("BUG: unknown node: NODE_METHOD"));
	  break;
      }
      case NODE_FBODY:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_FBODY"));
	  break;
      }
      case NODE_CFUNC:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_CFUNC"));
	  break;
      }
      case NODE_SCOPE:{
	  /* OK */
	  COMPILE_ERROR(("BUG: shouldn't reach: NODE_SCOPE"));
	  break;
      }
      case NODE_BLOCK:{
	  while (node && nd_type(node) == NODE_BLOCK) {
	      COMPILE_(ret, "BLOCK body", node->nd_head,
		       (node->nd_next == 0 && poped == 0) ? 0 : 1);
	      node = node->nd_next;
	  }
	  if (node) {
	      COMPILE_(ret, "BLOCK next", node->nd_next, poped);
	  }
	  break;
      }
      case NODE_IF:{
	  DECL_ANCHOR(cond_seq);
	  DECL_ANCHOR(then_seq);
	  DECL_ANCHOR(else_seq);
	  LABEL *then_label, *else_label, *end_label;

	  then_label = NEW_LABEL(nd_line(node));
	  else_label = NEW_LABEL(nd_line(node));
	  end_label = NEW_LABEL(nd_line(node));

	  compile_branch_condition(iseq, cond_seq, node->nd_cond,
				   then_label, else_label);
	  COMPILE_(then_seq, "then", node->nd_body, poped);
	  COMPILE_(else_seq, "else", node->nd_else, poped);

	  ADD_SEQ(ret, cond_seq);

	  ADD_LABEL(ret, then_label);
	  ADD_SEQ(ret, then_seq);
	  ADD_INSNL(ret, nd_line(node), jump, end_label);

	  ADD_LABEL(ret, else_label);
	  ADD_SEQ(ret, else_seq);

	  ADD_LABEL(ret, end_label);

	  break;
      }
      case NODE_CASE:{
	  NODE *vals;
	  NODE *tempnode = node;
	  LABEL *endlabel, *elselabel;
	  DECL_ANCHOR(head);
	  DECL_ANCHOR(body_seq);
	  DECL_ANCHOR(cond_seq);
	  VALUE special_literals = rb_ary_new();

	  if (node->nd_head == 0) {
	      COMPILE_(ret, "when", node->nd_body, poped);
	      break;
	  }
	  COMPILE(head, "case base", node->nd_head);

	  node = node->nd_body;
	  type = nd_type(node);

	  if (type != NODE_WHEN) {
	      COMPILE_ERROR(("NODE_CASE: unexpected node. must be NODE_WHEN, but %s", ruby_node_name(type)));
	  }

	  endlabel = NEW_LABEL(nd_line(node));
	  elselabel = NEW_LABEL(nd_line(node));

	  ADD_SEQ(ret, head);	/* case VAL */

	  while (type == NODE_WHEN) {
	      LABEL *l1;

	      l1 = NEW_LABEL(nd_line(node));
	      ADD_LABEL(body_seq, l1);
	      ADD_INSN(body_seq, nd_line(node), pop);
	      COMPILE_(body_seq, "when body", node->nd_body, poped);
	      ADD_INSNL(body_seq, nd_line(node), jump, endlabel);

	      vals = node->nd_head;
	      if (vals) {
		  if (nd_type(vals) == NODE_ARRAY) {
		      special_literals = when_vals(iseq, cond_seq, vals, l1, special_literals);
		  }
		  else if (nd_type(vals) == NODE_SPLAT || nd_type(vals) == NODE_ARGSCAT) {
		      NODE *val = vals->nd_head;
		      special_literals = 0;

		      if (nd_type(vals) == NODE_ARGSCAT) {
			  when_vals(iseq, cond_seq, vals->nd_head, l1, 0);
			  val = vals->nd_body;
		      }

		      COMPILE(cond_seq, "when/cond splat", val);
		      ADD_INSN1(cond_seq, nd_line(val), checkincludearray, Qtrue);
		      ADD_INSNL(cond_seq, nd_line(val), branchif, l1);
		  }
		  else {
		      rb_bug("NODE_CASAE: unknown node (%s)", ruby_node_name(nd_type(vals)));
		  }
	      }
	      else {
		  rb_bug("NODE_CASAE: must be NODE_ARRAY, but 0\n");
	      }

	      node = node->nd_next;
	      if (!node) {
		  break;
	      }
	      type = nd_type(node);
	  }
	  /* else */
	  if (node) {
	      ADD_LABEL(cond_seq, elselabel);
	      ADD_INSN(cond_seq, nd_line(node), pop);
	      COMPILE_(cond_seq, "else", node, poped);
	      ADD_INSNL(cond_seq, nd_line(node), jump, endlabel);
	  }
	  else {
	      debugs("== else (implicit)\n");
	      ADD_LABEL(cond_seq, elselabel);
	      ADD_INSN(cond_seq, nd_line(tempnode), pop);
	      if (!poped) {
		  ADD_INSN(cond_seq, nd_line(tempnode), putnil);
	      }
	      ADD_INSNL(cond_seq, nd_line(tempnode), jump, endlabel);
	  }

	  if (special_literals) {
	      ADD_INSN(ret, nd_line(tempnode), dup);
	      ADD_INSN2(ret, nd_line(tempnode), opt_case_dispatch,
			special_literals, elselabel);
	      iseq_add_mark_object_compile_time(iseq, special_literals);
	  }

	  ADD_SEQ(ret, cond_seq);
	  ADD_SEQ(ret, body_seq);
	  ADD_LABEL(ret, endlabel);
	  break;
      }
      case NODE_WHEN:{
	  NODE *vals;
	  NODE *val;
	  NODE *orig_node = node;
	  LABEL *endlabel;
	  DECL_ANCHOR(body_seq);

	  endlabel = NEW_LABEL(nd_line(node));

	  while (node && nd_type(node) == NODE_WHEN) {
	      LABEL *l1 = NEW_LABEL(nd_line(node));
	      ADD_LABEL(body_seq, l1);
	      COMPILE_(body_seq, "when", node->nd_body, poped);
	      ADD_INSNL(body_seq, nd_line(node), jump, endlabel);

	      vals = node->nd_head;
	      if (vals && nd_type(vals) == NODE_ARRAY) {
		  while (vals) {
		      val = vals->nd_head;
		      COMPILE(ret, "when2", val);
		      ADD_INSNL(ret, nd_line(val), branchif, l1) ;
		      vals = vals->nd_next;
		  }
	      }
	      else if (nd_type(vals) == NODE_SPLAT || nd_type(vals) == NODE_ARGSCAT) {
		  NODE *val = vals->nd_head;
		  
		  if (nd_type(vals) == NODE_ARGSCAT) {
		      NODE *vs = vals->nd_head;
		      val = vals->nd_body;

		      while (vs) {
			  NODE* val = vs->nd_head;
			  COMPILE(ret, "when/argscat", val);
			  ADD_INSNL(ret, nd_line(val), branchif, l1);
			  vs = vs->nd_next;
		      }
		  }

		  ADD_INSN(ret, nd_line(val), putnil);
		  COMPILE(ret, "when2/splat", val);
		  ADD_INSN1(ret, nd_line(val), checkincludearray, Qfalse);
		  ADD_INSN(ret, nd_line(val), pop);
		  ADD_INSNL(ret, nd_line(val), branchif, l1);
	      }
	      else {
		  rb_bug("err");
	      }
	      node = node->nd_next;
	  }
	  /* else */
	  COMPILE_(ret, "else", node, poped);
	  ADD_INSNL(ret, nd_line(orig_node), jump, endlabel);

	  ADD_SEQ(ret, body_seq);
	  ADD_LABEL(ret, endlabel);

	  break;
      }
      case NODE_OPT_N:
      case NODE_WHILE:
      case NODE_UNTIL:{
	  LABEL *prev_start_label = iseq->compile_data->start_label;
	  LABEL *prev_end_label = iseq->compile_data->end_label;
	  LABEL *prev_redo_label = iseq->compile_data->redo_label;
	  VALUE prev_loopval_popped = iseq->compile_data->loopval_popped;

	  struct iseq_compile_data_ensure_node_stack *enlp =
	    iseq->compile_data->ensure_node_stack;

	  LABEL *next_label = iseq->compile_data->start_label = NEW_LABEL(nd_line(node));	/* next  */
	  LABEL *redo_label = iseq->compile_data->redo_label = NEW_LABEL(nd_line(node));	/* redo  */
	  LABEL *break_label = iseq->compile_data->end_label = NEW_LABEL(nd_line(node));	/* break */
	  LABEL *end_label = NEW_LABEL(nd_line(node));

	  iseq->compile_data->loopval_popped = 0;
	  iseq->compile_data->ensure_node_stack = 0;

	  if (type == NODE_OPT_N || node->nd_state) {
	      ADD_INSNL(ret, nd_line(node), jump, next_label);
	  }

	  ADD_LABEL(ret, redo_label);
	  COMPILE_POPED(ret, "while body", node->nd_body);
	  ADD_LABEL(ret, next_label);	/* next */

	  if (type == NODE_WHILE) {
	      compile_branch_condition(iseq, ret, node->nd_cond,
				       redo_label, end_label);
	  }
	  else if (type == NODE_UNTIL) {
	      /* untile */
	      compile_branch_condition(iseq, ret, node->nd_cond,
				       end_label, redo_label);
	  }
	  else {
	      ADD_CALL_RECEIVER(ret, nd_line(node));
	      ADD_CALL(ret, nd_line(node), ID2SYM(idGets), INT2FIX(0));
	      ADD_INSNL(ret, nd_line(node), branchif, redo_label) ;
	      /* opt_n */
	  }

	  ADD_LABEL(ret, end_label);

	  if (node->nd_state == Qundef) {
	      ADD_INSN(ret, nd_line(node), putundef);
	  }
	  else {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }

	  ADD_LABEL(ret, break_label);	/* braek */

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }

	  ADD_CATCH_ENTRY(CATCH_TYPE_BREAK, redo_label, break_label,
			  0, break_label);
	  ADD_CATCH_ENTRY(CATCH_TYPE_NEXT | 0x10000, redo_label,
			  break_label, 0, iseq->compile_data->start_label);
	  ADD_CATCH_ENTRY(CATCH_TYPE_REDO, redo_label, break_label, 0,
			  iseq->compile_data->redo_label);

	  iseq->compile_data->start_label = prev_start_label;
	  iseq->compile_data->end_label = prev_end_label;
	  iseq->compile_data->redo_label = prev_redo_label;
	  iseq->compile_data->loopval_popped = prev_loopval_popped;
	  iseq->compile_data->ensure_node_stack = enlp;
	  break;
      }
      case NODE_ITER:
      case NODE_FOR:{
	  VALUE prevblock = iseq->compile_data->current_block;
	  LABEL *retry_label = NEW_LABEL(nd_line(node));
	  LABEL *retry_end_l = NEW_LABEL(nd_line(node));
	  ID mid = 0;

	  ADD_LABEL(ret, retry_label);
	  if (nd_type(node) == NODE_FOR) {
	      COMPILE(ret, "iter caller (for)", node->nd_iter);

	      iseq->compile_data->current_block =
		NEW_CHILD_ISEQVAL(node, make_name_for_block(iseq),
				  ISEQ_TYPE_BLOCK);

	      mid = idEach;
	      ADD_SEND_R(ret, nd_line(node), ID2SYM(idEach), INT2FIX(0),
			 iseq->compile_data->current_block, INT2FIX(0));
	      if (poped) {
		  ADD_INSN(ret, nd_line(node), pop);
	      }
	  }
	  else {
	      iseq->compile_data->current_block =
		NEW_CHILD_ISEQVAL(node, make_name_for_block(iseq),
				  ISEQ_TYPE_BLOCK);
	      COMPILE_(ret, "iter caller", node->nd_iter, poped);
	  }
	  ADD_LABEL(ret, retry_end_l);
	  iseq->compile_data->current_block = prevblock;

	  ADD_CATCH_ENTRY(CATCH_TYPE_RETRY, retry_label, retry_end_l, 0,
			  retry_label);
	  break;
      }
      case NODE_BREAK:{
	  unsigned long level = 0;

	  if (iseq->compile_data->redo_label != 0) {
	      /* while/until */
	      add_ensure_iseq(ret, iseq);
	      COMPILE_(ret, "break val (while/until)", node->nd_stts,
		       iseq->compile_data->loopval_popped);
	      ADD_INSNL(ret, nd_line(node), jump,
			iseq->compile_data->end_label);
	  }
	  else if (iseq->type == ISEQ_TYPE_BLOCK) {
	    break_by_insn:
	      /* escape from block */
	      COMPILE(ret, "break val (block)", node->nd_stts);
	      ADD_INSN1(ret, nd_line(node), throw,
			INT2FIX(level | 0x02) /* TAG_BREAK */ );
	  }
	  else if (iseq->type == ISEQ_TYPE_EVAL) {
	      COMPILE_ERROR(("Can't escape from eval with break"));
	  }
	  else {
	      rb_iseq_t *ip = iseq->parent_iseq;
	      while (ip) {
		  level++;
		  if (ip->compile_data->redo_label != 0) {
		      level = 0x8000;
		      if (ip->compile_data->loopval_popped == 0) {
			  /* need value */
			  level |= 0x4000;
		      }
		      goto break_by_insn;
		  }
		  else if (ip->type == ISEQ_TYPE_BLOCK) {
		      level <<= 16;
		      goto break_by_insn;
		  }
		  ip = ip->parent_iseq;
	      }
	      COMPILE_ERROR(("Illegal break"));
	  }
	  break;
      }
      case NODE_NEXT:{
	  unsigned long level = 0;

	  if (iseq->compile_data->redo_label != 0) {
	      add_ensure_iseq(ret, iseq);
	      ADD_INSNL(ret, nd_line(node), jump,
			iseq->compile_data->start_label);
	  }
	  else if (iseq->compile_data->end_label) {
	      COMPILE(ret, "next val", node->nd_stts);
	      add_ensure_iseq(ret, iseq);
	      ADD_INSNL(ret, nd_line(node), jump,
			iseq->compile_data->end_label);
	  }
	  else if (iseq->type == ISEQ_TYPE_EVAL) {
	      COMPILE_ERROR(("Can't escape from eval with next"));
	  }
	  else {
	      rb_iseq_t *ip = iseq->parent_iseq;
	      while (ip) {
		  level = 0x8000;
		  if (ip->type == ISEQ_TYPE_BLOCK) {
		      level |= 0x4000;
		      break;
		  }
		  else if (ip->compile_data->redo_label != 0) {
		      break;
		  }
		  ip = ip->parent_iseq;
	      }
	      if (ip != 0) {
		  COMPILE(ret, "next val", node->nd_stts);
		  add_ensure_iseq(ret, iseq);
		  ADD_INSN1(ret, nd_line(node), throw,
			    INT2FIX(level | 0x03) /* TAG_NEXT */ );
	      }
	      else {
		  COMPILE_ERROR(("Illegal next"));
	      }
	  }
	  break;
      }
      case NODE_REDO:{
	  if (iseq->compile_data->redo_label) {
	      add_ensure_iseq(ret, iseq);
	      ADD_INSNL(ret, nd_line(node), jump,
			iseq->compile_data->redo_label);
	      if (!poped) { /* for stack consistency */
		  ADD_INSN(ret, nd_line(node), putnil);
	      }
	  }
	  else if (iseq->type == ISEQ_TYPE_EVAL) {
	      COMPILE_ERROR(("Can't escape from eval with redo"));
	  }
	  else if (iseq->compile_data->start_label) {
	      ADD_INSNL(ret, nd_line(node), jump,
			iseq->compile_data->start_label);
	      if (!poped) { /* for stack consistency */
		  ADD_INSN(ret, nd_line(node), putnil);
	      }
	  }
	  else {
	      rb_iseq_t *ip = iseq->parent_iseq;
	      unsigned long level = 0x8000 | 0x4000;
	      while (ip) {
		  if (ip->type == ISEQ_TYPE_BLOCK) {
		      break;
		  }
		  else if (ip->type == ISEQ_TYPE_EVAL) {
		      COMPILE_ERROR(("Can't escape from eval with redo"));
		  }
		  else if (ip->compile_data->redo_label != 0) {
		      break;
		  }
		  ip = ip->parent_iseq;
	      }
	      if (ip != 0) {
		  add_ensure_iseq(ret, iseq);
		  ADD_INSN1(ret, nd_line(node), throw,
			    INT2FIX(level | 0x05) /* TAG_REDO */ );
	      }
	      else {
		  COMPILE_ERROR(("Illegal redo"));
	      }
	  }
	  break;
      }
      case NODE_RETRY:{
	  if (iseq->type == ISEQ_TYPE_BLOCK ||
	      iseq->type == ISEQ_TYPE_RESCUE) {
	      ADD_INSN(ret, nd_line(node), putnil);
	      ADD_INSN1(ret, nd_line(node), throw,
			INT2FIX(0x04) /* TAG_RETRY */ );
	  }
	  else {
	      COMPILE_ERROR(("Illegal retry"));
	  }
	  break;
      }
      case NODE_BEGIN:{
	  COMPILE_(ret, "NODE_BEGIN", node->nd_body, poped);
	  break;
      }
      case NODE_RESCUE:{
	  LABEL *lstart = NEW_LABEL(nd_line(node));
	  LABEL *lend = NEW_LABEL(nd_line(node));
	  LABEL *lcont = NEW_LABEL(nd_line(node));
	  VALUE rescue = NEW_CHILD_ISEQVAL(node->nd_resq,
					   rb_str_concat(rb_str_new2
							 ("rescue in "),
							 iseq->name),
					   ISEQ_TYPE_RESCUE);

	  ADD_LABEL(ret, lstart);
	  COMPILE(ret, "rescue head", node->nd_head);
	  ADD_LABEL(ret, lend);
	  if (node->nd_else) {
	      ADD_INSN(ret, nd_line(node), pop);
	      COMPILE(ret, "rescue else", node->nd_else);
	  }
	  ADD_INSN(ret, nd_line(node), nop);
	  ADD_LABEL(ret, lcont);

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }

	  /* resgister catch entry */
	  ADD_CATCH_ENTRY(CATCH_TYPE_RESCUE, lstart, lend, rescue, lcont);
	  ADD_CATCH_ENTRY(CATCH_TYPE_RETRY, lend, lcont, 0, lstart);
	  break;
      }
      case NODE_RESBODY:{
	  NODE *resq = node;
	  NODE *narg;
	  LABEL *label_miss, *label_hit;

	  while (resq) {
	      label_miss = NEW_LABEL(nd_line(node));
	      label_hit = NEW_LABEL(nd_line(node));

	      narg = resq->nd_args;
	      while (narg) {
		  COMPILE(ret, "rescue arg", narg->nd_head);
		  ADD_INSN2(ret, nd_line(node), getdynamic, INT2FIX(1),
			    INT2FIX(0));
		  ADD_SEND(ret, nd_line(node), ID2SYM(idEqq), INT2FIX(1));
		  ADD_INSNL(ret, nd_line(node), branchif, label_hit) ;
		  narg = narg->nd_next;
	      }
	      if (resq->nd_args == 0) {
		  ADD_INSN1(ret, nd_line(node), putobject,
			    rb_eStandardError);
		  ADD_INSN2(ret, nd_line(node), getdynamic, INT2FIX(1),
			    INT2FIX(0));
		  ADD_SEND(ret, nd_line(node), ID2SYM(idEqq), INT2FIX(1));
		  ADD_INSNL(ret, nd_line(node), branchif, label_hit) ;
	      }
	      ADD_INSNL(ret, nd_line(node), jump, label_miss);
	      ADD_LABEL(ret, label_hit);
	      COMPILE(ret, "resbody body", resq->nd_body);
	      ADD_INSN(ret, nd_line(node), leave);
	      ADD_LABEL(ret, label_miss);
	      resq = resq->nd_head;
	  }
	  break;
      }
      case NODE_ENSURE:{
	  DECL_ANCHOR(ensr);
	  VALUE ensure = NEW_CHILD_ISEQVAL(node->nd_ensr,
					   rb_str_concat(rb_str_new2
							 ("ensure in "),
							 iseq->name),
					   ISEQ_TYPE_ENSURE);
	  LABEL *lstart = NEW_LABEL(nd_line(node));
	  LABEL *lend = NEW_LABEL(nd_line(node));
	  LABEL *lcont = NEW_LABEL(nd_line(node));
	  struct ensure_range er = { lstart, lend, 0 };
	  struct iseq_compile_data_ensure_node_stack enl = {
	      node->nd_ensr,
	      iseq->compile_data->ensure_node_stack,	/* prev */
	      &er,
	  };
	  struct ensure_range *erange;

	  COMPILE_POPED(ensr, "ensure ensr", node->nd_ensr);

	  iseq->compile_data->ensure_node_stack = &enl;

	  ADD_LABEL(ret, lstart);
	  COMPILE_(ret, "ensure head", node->nd_head, poped);
	  ADD_LABEL(ret, lend);
	  if (ensr->anchor.next == 0) {
	      ADD_INSN(ret, nd_line(node), nop);
	  }
	  else {
	      ADD_SEQ(ret, ensr);
	  }
	  ADD_LABEL(ret, lcont);

	  erange = iseq->compile_data->ensure_node_stack->erange;
	  while (erange) {
	      ADD_CATCH_ENTRY(CATCH_TYPE_ENSURE, erange->begin, erange->end,
			      ensure, lcont);
	      erange = erange->next;
	  }
	  iseq->compile_data->ensure_node_stack = enl.prev;
	  break;
      }

      case NODE_AND:
      case NODE_OR:{
	  LABEL *end_label = NEW_LABEL(nd_line(node));
	  COMPILE(ret, "nd_1st", node->nd_1st);
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }
	  if (type == NODE_AND) {
	      ADD_INSNL(ret, nd_line(node), branchunless, end_label);
	  }
	  else {
	      ADD_INSNL(ret, nd_line(node), branchif, end_label) ;
	  }
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  COMPILE_(ret, "nd_2nd", node->nd_2nd, poped);
	  ADD_LABEL(ret, end_label);
	  break;
      }
      case NODE_NOT:{
	  COMPILE(ret, "value", node->nd_body);
	  ADD_INSN(ret, nd_line(node), putnot);
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }

      case NODE_MASGN:{
	  compile_massign(iseq, ret, node->nd_value,	/* rhsn  */
			  node->nd_args,	/* splat */
			  node->nd_head,	/* lhsn  */
			  0);
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), putobject, Qtrue);
	  }
	  break;
      }

      case NODE_LASGN:{
	  ID id = node->nd_vid;
	  int idx = iseq->local_iseq->local_size - get_local_var_idx(iseq, id);

	  debugs("lvar: %s idx: %d\n", rb_id2name(id), idx);
	  COMPILE(ret, "lvalue", node->nd_value);

	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }
	  ADD_INSN1(ret, nd_line(node), setlocal, INT2FIX(idx));

	  break;
      }
      case NODE_DASGN:
      case NODE_DASGN_CURR:{
	  int idx, lv, ls;
	  COMPILE(ret, "dvalue", node->nd_value);
	  debugp_param("dassn id", rb_str_new2(rb_id2name(node->nd_vid)));

	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }
	  idx = get_dyna_var_idx(iseq, node->nd_vid, &lv, &ls);
	  if (nd_type(node) == NODE_DASGN_CURR &&
	      lv > 0 &&
	      iseq->type == ISEQ_TYPE_BLOCK &&
	      iseq->compile_data->for_iseq != 1) {

	      dpi(node->nd_vid);
	      rb_bug("NODE_DASGN_CURR, but lv == %d (line: %d)", lv,
		     nd_line(node));
	  }

	  if (idx < 0) {
	      debugi("unknown id", node->nd_vid);
	      COMPILE_ERROR(("NODE_DASGN error"));
	  }
	  ADD_INSN2(ret, nd_line(node), setdynamic,
		    INT2FIX(ls - idx), INT2FIX(lv));
	  break;
      }
      case NODE_GASGN:{
	  COMPILE(ret, "lvalue", node->nd_value);

	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }
	  ADD_INSN1(ret, nd_line(node), setglobal,
		    (((long)node->nd_entry) | 1));
	  break;
      }
      case NODE_IASGN:
      case NODE_IASGN2:{
	  COMPILE(ret, "lvalue", node->nd_value);
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }
	  ADD_INSN1(ret, nd_line(node), setinstancevariable,
		    ID2SYM(node->nd_vid));
	  break;
      }
      case NODE_CDECL:{
	  COMPILE(ret, "lvalue", node->nd_value);

	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }

	  if (node->nd_vid) {
	      ADD_INSN(ret, nd_line(node), putnil);
	      ADD_INSN1(ret, nd_line(node), setconstant,
			ID2SYM(node->nd_vid));
	  }
	  else {
	      compile_cpath(ret, iseq, node->nd_else);
	      ADD_INSN1(ret, nd_line(node), setconstant,
			ID2SYM(node->nd_else->nd_mid));
	  }
	  break;
      }
      case NODE_CVASGN:{
	  COMPILE(ret, "cvasgn val", node->nd_value);
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), dup);
	  }
	  ADD_INSN1(ret, nd_line(node), setclassvariable,
		    ID2SYM(node->nd_vid));
	  break;
      }
      case NODE_OP_ASGN1:{
	  DECL_ANCHOR(args);
	  int argc;
	  ID id = node->nd_mid;

	  /*
	   * a[x] (op)= y
	   *
	   * eval a    # a
	   * eval x    # a x
	   * dupn 2    # a x a x
	   * send :[]  # a x a[x]
	   * eval y    # a x a[x] y
	   * send op   # a x a[x]+y
	   * send []=  # ret
	   */

	  /*
	   * nd_recv[nd_args->nd_body] (nd_mid)= nd_args->nd_head;
	   * NODE_OP_ASGN nd_recv
	   *              nd_args->nd_head
	   *              nd_args->nd_body
	   *              nd_mid
	   */

	  COMPILE(ret, "NODE_OP_ASGN1 recv", node->nd_recv);
	  argc = compile_array(iseq, args, node->nd_args->nd_body, Qfalse);
	  POP_ELEMENT(args);
	  ADD_SEQ(ret, args);
	  ADD_INSN1(ret, nd_line(node), dupn, INT2FIX(argc+1));
	  ADD_SEND(ret, nd_line(node), ID2SYM(idAREF), INT2FIX(argc));

	  if (id == 0 || id == 1) {
	      /* 0: or, 1: and
		   a[x] ||= y

		   unless/if a[x]
		   a[x]= y
		   else
		   nil
		   end
	       */
	      LABEL *label = NEW_LABEL(nd_line(node));
	      LABEL *lfin = NEW_LABEL(nd_line(node));

	      if (id == 0) {
		  /* or */
		  ADD_INSN(ret, nd_line(node), dup);
		  ADD_INSNL(ret, nd_line(node), branchif, label) ;
		  ADD_INSN(ret, nd_line(node), pop);
	      }
	      else {
		  /* and */
		  ADD_INSNL(ret, nd_line(node), branchunless, label);
	      }

	      COMPILE(ret, "NODE_OP_ASGN1 args->head: ",
		      node->nd_args->nd_head);
	      ADD_SEND(ret, nd_line(node), ID2SYM(idASET),
		       INT2FIX(argc + 1));
	      ADD_INSNL(ret, nd_line(node), jump, lfin);
	      ADD_LABEL(ret, label);
	      if (id == 0) {	/* or */
		  ADD_INSN(ret, nd_line(node), swap);
		  ADD_INSN(ret, nd_line(node), pop);
		  ADD_INSN(ret, nd_line(node), swap);
		  ADD_INSN(ret, nd_line(node), pop);
	      }
	      else if (id == 1) {	/* and */
		  ADD_INSN(ret, nd_line(node), pop);
		  ADD_INSN(ret, nd_line(node), pop);
		  ADD_INSN(ret, nd_line(node), putnil);
	      }
	      ADD_LABEL(ret, lfin);
	  }
	  else {
	      COMPILE(ret, "NODE_OP_ASGN1 args->head: ",
		      node->nd_args->nd_head);
	      ADD_SEND(ret, nd_line(node), ID2SYM(id), INT2FIX(1));
	      ADD_SEND(ret, nd_line(node), ID2SYM(idASET),
		       INT2FIX(argc + 1));
	  }

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }

	  break;
      }
      case NODE_OP_ASGN2:{
	  ID atype = node->nd_next->nd_mid;
	  LABEL *lfin = NEW_LABEL(nd_line(node));
	  LABEL *lcfin = NEW_LABEL(nd_line(node));
	  /*
	       class C; attr_accessor :c; end
	       r = C.new
	       r.a &&= v # asgn2

	       eval r    # r
	       dup       # r r
	       eval r.a  # r o

	       # or
	       dup       # r o o
	       if lcfin  # r o
	       pop       # r
	       eval v    # r v
	       send a=   # v
	       jump lfin # v

	       lcfin:      # r o
	       swap      # o r
	       pop       # o

	       lfin:       # v

	       # and
	       dup       # r o o
	       unless lcfin
	       pop       # r
	       eval v    # r v
	       send a=   # v
	       jump lfin # v

	       # others
	       eval v    # r o v
	       send ??   # r w
	       send a=   # w

	   */

	  COMPILE(ret, "NODE_OP_ASGN2#recv", node->nd_recv);
	  ADD_INSN(ret, nd_line(node), dup);
	  ADD_SEND(ret, nd_line(node), ID2SYM(node->nd_next->nd_vid),
		   INT2FIX(0));

	  if (atype == 0 || atype == 1) {	/* 0: OR or 1: AND */
	      ADD_INSN(ret, nd_line(node), dup);
	      if (atype == 0) {
		  ADD_INSNL(ret, nd_line(node), branchif, lcfin) ;
	      }
	      else {
		  ADD_INSNL(ret, nd_line(node), branchunless, lcfin);
	      }
	      ADD_INSN(ret, nd_line(node), pop);
	      COMPILE(ret, "NODE_OP_ASGN2 val", node->nd_value);
	      ADD_SEND(ret, nd_line(node), ID2SYM(node->nd_next->nd_aid),
		       INT2FIX(1));
	      ADD_INSNL(ret, nd_line(node), jump, lfin);

	      ADD_LABEL(ret, lcfin);
	      ADD_INSN(ret, nd_line(node), swap);
	      ADD_INSN(ret, nd_line(node), pop);

	      ADD_LABEL(ret, lfin);
	  }
	  else {
	      COMPILE(ret, "NODE_OP_ASGN2 val", node->nd_value);
	      ADD_SEND(ret, nd_line(node), ID2SYM(node->nd_next->nd_mid),
		       INT2FIX(1));
	      ADD_SEND(ret, nd_line(node), ID2SYM(node->nd_next->nd_aid),
		       INT2FIX(1));
	  }

	  if (poped) {
	      /* we can apply more optimize */
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_OP_ASGN_AND:
      case NODE_OP_ASGN_OR:{
	  LABEL *lfin = NEW_LABEL(nd_line(node));
	  LABEL *lassign = NEW_LABEL(nd_line(node));
	  
	  if (nd_type(node) == NODE_OP_ASGN_OR) {
	      defined_expr(iseq, ret, node->nd_head, lassign, Qfalse);
	      ADD_INSNL(ret, nd_line(node), branchunless, lassign);
	  }
	  
	  COMPILE(ret, "NODE_OP_ASGN_AND/OR#nd_head", node->nd_head);
	  ADD_INSN(ret, nd_line(node), dup);
	  
	  if (nd_type(node) == NODE_OP_ASGN_AND) {
	      ADD_INSNL(ret, nd_line(node), branchunless, lfin);
	  }
	  else {
	      ADD_INSNL(ret, nd_line(node), branchif, lfin) ;
	  }

	  ADD_INSN(ret, nd_line(node), pop);
	  ADD_LABEL(ret, lassign);
	  COMPILE(ret, "NODE_OP_ASGN_AND/OR#nd_value", node->nd_value);
	  ADD_LABEL(ret, lfin);

	  if (poped) {
	      /* we can apply more optimize */
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_CALL:
      case NODE_FCALL:
      case NODE_VCALL:{		/* VCALL: variable or call */
	  /*
	       call:  obj.method(...)
	       fcall: func(...)
	       vcall: func
	   */
	  DECL_ANCHOR(recv);
	  DECL_ANCHOR(args);
	  ID mid = node->nd_mid;
	  VALUE argc;
	  VALUE flag = 0;
	  VALUE parent_block = iseq->compile_data->current_block;
	  iseq->compile_data->current_block = Qfalse;

#if SUPPORT_JOKE
	  if (nd_type(node) == NODE_VCALL) {
	      if (mid == idBitblt) {
		  ADD_INSN(ret, nd_line(node), bitblt);
		  break;
	      }
	      else if (mid == idAnswer) {
		  ADD_INSN(ret, nd_line(node), answer);
		  break;
	      }
	  }
	  /* only joke */
	  {
	      static ID goto_id;
	      static ID label_id;
	      VALUE label;
	      VALUE label_sym;

	      if (goto_id == 0) {
		  goto_id = rb_intern("__goto__");
		  label_id = rb_intern("__label__");
	      }

	      if (nd_type(node) == NODE_FCALL &&
		  (mid == goto_id || mid == label_id)) {
		  if (nd_type(node->nd_args->nd_head) == NODE_LIT &&
		      SYMBOL_P(node->nd_args->nd_head->nd_lit)) {

		      label_sym = label = node->nd_args->nd_head->nd_lit;
		      if ((label =
			   rb_hash_aref(iseq->compile_data,
					label_sym)) == Qnil) {
			  rb_hash_aset(iseq->compile_data, label_sym,
				       label = NEW_LABEL(nd_line(node)));
		      }
		  }
		  else {
		      rb_bug("illegal goto/label format");
		  }


		  if (mid == goto_id) {
		      ADD_INSNL(ret, nd_line(node), jump, label);
		  }
		  else {
		      ADD_LABEL(ret, label);
		  }
		  break;
	      }
	  }
#endif
	  /* reciever */
	  if (type == NODE_CALL) {
	      COMPILE(recv, "recv", node->nd_recv);
	  }
	  else if (type == NODE_FCALL || type == NODE_VCALL) {
	      ADD_CALL_RECEIVER(recv, nd_line(node));
	  }

	  /* args */
	  if (nd_type(node) != NODE_VCALL) {
	      argc = setup_arg(iseq, args, node, &flag);
	  }
	  else {
	      argc = INT2FIX(0);
	  }

	  ADD_SEQ(ret, recv);
	  ADD_SEQ(ret, args);

	  debugp_param("call args argc", argc);
	  debugp_param("call method", ID2SYM(mid));

	  switch (nd_type(node)) {
	    case NODE_VCALL:
	      flag |= VM_CALL_VCALL_BIT;
	      /* VCALL is funcall, so fall through */
	    case NODE_FCALL:
	      flag |= VM_CALL_FCALL_BIT;
	  }

	  ADD_SEND_R(ret, nd_line(node), ID2SYM(mid),
		     argc, parent_block, INT2FIX(flag));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_SUPER:
      case NODE_ZSUPER:{
	  DECL_ANCHOR(args);
	  VALUE argc;
	  VALUE flag = 0;
	  VALUE parent_block = iseq->compile_data->current_block;
	  iseq->compile_data->current_block = Qfalse;

	  if (nd_type(node) == NODE_SUPER) {
	      argc = setup_arg(iseq, args, node, &flag);
	  }
	  else {
	      /* NODE_ZSUPER */
	      int i;
	      rb_iseq_t *liseq = iseq->local_iseq;

	      argc = INT2FIX(liseq->argc);

	      /* normal arguments */
	      for (i = 0; i < liseq->argc; i++) {
		  int idx = liseq->local_size - i;
		  ADD_INSN1(args, nd_line(node), getlocal, INT2FIX(idx));
	      }

	      if (!liseq->arg_simple) {
		  if (liseq->arg_opts) {
		      /* optional arguments */
		      int j;
		      for (j = 0; j < liseq->arg_opts - 1; j++) {
			  int idx = liseq->local_size - (i + j);
			  ADD_INSN1(args, nd_line(node), getlocal,
				    INT2FIX(idx));
		      }
		      i += j;
		      argc = INT2FIX(i);
		  }

		  if (liseq->arg_rest) {
		      /* rest arguments */

		      if (liseq->arg_rest == -1) {
			  /* TODO */
		      }
		      else {
			  int idx = liseq->local_size - liseq->arg_rest + 1;
			  ADD_INSN1(args, nd_line(node), getlocal,
				    INT2FIX(idx));
			  argc = INT2FIX(liseq->arg_rest);
			  flag |= VM_CALL_ARGS_SPLAT_BIT;
		      }
		  }
	      }
	  }

	  /* dummy reciever */
	  ADD_INSN1(ret, nd_line(node), putobject,
		    nd_type(node) == NODE_ZSUPER ? Qfalse : Qtrue);
	  ADD_SEQ(ret, args);
	  ADD_INSN3(ret, nd_line(node), invokesuper,
		    argc, parent_block, INT2FIX(flag));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_ARRAY:{
	  compile_array(iseq, ret, node, Qtrue);
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_ZARRAY:{
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), newarray, INT2FIX(0));
	  }
	  break;
      }
      case NODE_VALUES:{
	  NODE *n = node;
	  while (n) {
	      COMPILE(ret, "values item", n->nd_head);
	      n = n->nd_next;
	  }
	  ADD_INSN1(ret, nd_line(node), newarray, INT2FIX(node->nd_alen));
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_HASH:{
	  DECL_ANCHOR(list);
	  VALUE size = 0;
	  int type = node->nd_head ? nd_type(node->nd_head) : NODE_ZARRAY;

	  switch (type) {
	    case NODE_ARRAY:{
		compile_array(iseq, list, node->nd_head, Qfalse);
		size = OPERAND_AT(POP_ELEMENT(list), 0);
		ADD_SEQ(ret, list);
		break;
	    }
	    case NODE_ZARRAY:
	      size = INT2FIX(0);
	      break;

	    default:
	      rb_bug("can't make hash with this node: %s", ruby_node_name(type));
	  }

	  ADD_INSN1(ret, nd_line(node), newhash, size);

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_RETURN:{
	  rb_iseq_t *is = iseq;

	  while (is) {
	      if (is->type == ISEQ_TYPE_TOP || is->type == ISEQ_TYPE_CLASS) {
		  COMPILE_ERROR(("Illegal return"));
		  break;
	      }
	      else {
		  if (is->type == ISEQ_TYPE_METHOD) {
		      ADD_INSN(ret, nd_line(node), emptstack);
		  }

		  COMPILE(ret, "return nd_stts (return val)",
			  node->nd_stts);

		  if (is->type == ISEQ_TYPE_METHOD) {
		      add_ensure_iseq(ret, iseq);
		      ADD_INSN(ret, nd_line(node), leave);
		  }
		  else {
		      ADD_INSN1(ret, nd_line(node), throw,
				INT2FIX(0x01) /* TAG_RETURN */ );
		  }
		  break;
	      }
	  }

	  break;
      }
      case NODE_YIELD:{
	  DECL_ANCHOR(args);
	  int argc;
	  unsigned long flag = 0;

	  if (iseq->type == ISEQ_TYPE_TOP || iseq->type == ISEQ_TYPE_CLASS) {
	      COMPILE_ERROR(("Illegal yield"));
	  }

	  if (node->nd_head) {
	      if (nd_type(node->nd_head) == NODE_ARRAY) {
		  NODE *p;
		  for (argc = 0, p = node->nd_head; p;
		       p = p->nd_next, argc++) {
		      /* count argc */
		  }
		  if (argc == 1) {
		      COMPILE(args, "yield with an arg", node->nd_head);
		  }
		  else {
		      compile_array(iseq, args, node->nd_head, Qfalse);
		      POP_ELEMENT(args);
		  }
		  debugs("argc: %d\n", argc);
	      }
	      else {
		  if (nd_type(node->nd_head) == NODE_ARGSCAT) {
		      if (node->nd_state == 2) {
			  flag |= VM_CALL_ARGS_SPLAT_BIT;
		      }

		      compile_array(iseq, args, node->nd_head->nd_head,
				    Qfalse);
		      POP_ELEMENT(args);
		      argc = LIST_SIZE(args) + 1;

		      COMPILE(args, "args(cat: splat)",
			      node->nd_head->nd_body);
		  }
		  else if (nd_type(node->nd_head) == NODE_SPLAT) {
		      if (node->nd_state == 2) {
			  flag |= VM_CALL_ARGS_SPLAT_BIT;
		      }

		      argc = 1;
		      COMPILE(args, "splat", node->nd_head->nd_head);
		  }
		  else {
		      COMPILE(args, "nd_head(1)", node->nd_head);
		      argc = 1;
		  }
	      }
	  }
	  else {
	      argc = 0;
	  }
	  ADD_SEQ(ret, args);
	  ADD_INSN2(ret, nd_line(node), invokeblock, INT2FIX(argc),
		    INT2FIX(flag));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_LVAR:{
	  if (!poped) {
	      ID id = node->nd_vid;
	      int idx = iseq->local_iseq->local_size - get_local_var_idx(iseq, id);

	      debugs("id: %s idx: %d\n", rb_id2name(id), idx);
	      ADD_INSN1(ret, nd_line(node), getlocal, INT2FIX(idx));
	  }
	  break;
      }
      case NODE_DVAR:{
	  int lv, idx, ls;
	  debugi("nd_vid", node->nd_vid);
	  if (!poped) {
	      idx = get_dyna_var_idx(iseq, node->nd_vid, &lv, &ls);
	      if (idx < 0) {
		  rb_bug("unknown dvar (%s)", rb_id2name(node->nd_vid));
	      }
	      ADD_INSN2(ret, nd_line(node), getdynamic, INT2FIX(ls - idx),
			INT2FIX(lv));
	  }
	  break;
      }
      case NODE_GVAR:{
	  ADD_INSN1(ret, nd_line(node), getglobal,
		    (((long)node->nd_entry) | 1));
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_IVAR:{
	  debugi("nd_vid", node->nd_vid);
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), getinstancevariable,
			ID2SYM(node->nd_vid));
	  }
	  break;
      }
      case NODE_CONST:{
	  debugi("nd_vid", node->nd_vid);

	  if (iseq->compile_data->option->inline_const_cache) {
	      LABEL *lstart = NEW_LABEL(nd_line(node));
	      LABEL *lend = NEW_LABEL(nd_line(node));

	      ADD_LABEL(ret, lstart);
	      ADD_INSN2(ret, nd_line(node), getinlinecache,
			NEW_INLINE_CACHE_ENTRY(), lend);
	      ADD_INSN1(ret, nd_line(node), getconstant, ID2SYM(node->nd_vid));
	      ADD_INSN1(ret, nd_line(node), setinlinecache, lstart);
	      ADD_LABEL(ret, lend);
	  }
	  else {
	      ADD_INSN(ret, nd_line(node), putnil);
	      ADD_INSN1(ret, nd_line(node), getconstant, ID2SYM(node->nd_vid));
	  }

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_CVAR:{
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), getclassvariable,
			ID2SYM(node->nd_vid));
	  }
	  break;
      }
      case NODE_NTH_REF:{
	  ADD_INSN2(ret, nd_line(node), getspecial, INT2FIX(1) /* '~'  */,
		    INT2FIX(node->nd_nth << 1));
	  break;
      }
      case NODE_BACK_REF:{
	  ADD_INSN2(ret, nd_line(node), getspecial, INT2FIX(1) /* '~' */,
		    INT2FIX(0x01 | (node->nd_nth << 1)));
	  break;
      }
      case NODE_MATCH:
      case NODE_MATCH2:
      case NODE_MATCH3:{
	  DECL_ANCHOR(recv);
	  DECL_ANCHOR(val);

	  switch(nd_type(node)) {
	    case NODE_MATCH:
	      ADD_INSN1(recv, nd_line(node), putobject, node->nd_lit);
	      ADD_INSN2(val, nd_line(node), getspecial, INT2FIX(0),
			INT2FIX(0));
	      break;
	    case NODE_MATCH2:
	      COMPILE(recv, "reciever", node->nd_recv);
	      COMPILE(val, "value", node->nd_value);
	      break;
	    case NODE_MATCH3:
	      COMPILE(recv, "reciever", node->nd_value);
	      COMPILE(val, "value", node->nd_recv);
	      break;
	  }

	  if (iseq->compile_data->option->specialized_instruction) {
	      /* TODO: detect by node */
	      if (recv->last == recv->anchor.next &&
		  INSN_OF(recv->last) == BIN(putobject) &&
		  nd_type(node) == NODE_MATCH2) {
		  ADD_SEQ(ret, val);
		  ADD_INSN1(ret, nd_line(node), opt_regexpmatch1,
			    OPERAND_AT(recv->last, 0));
	      }
	      else {
		  ADD_SEQ(ret, recv);
		  ADD_SEQ(ret, val);
		  ADD_INSN(ret, nd_line(node), opt_regexpmatch2);
	      }
	  }
	  else {
	      ADD_SEQ(ret, recv);
	      ADD_SEQ(ret, val);
	      ADD_SEND(ret, nd_line(node), ID2SYM(idEqTilde), INT2FIX(1));
	  }

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_LIT:{
	  debugp_param("lit", node->nd_lit);
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), putobject, node->nd_lit);
	  }
	  break;
      }
      case NODE_STR:{
	  debugp_param("nd_lit", node->nd_lit);
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), putstring, node->nd_lit);
	  }
	  break;
      }
      case NODE_DSTR:{
	  compile_dstr(iseq, ret, node);

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_XSTR:{
	  ADD_CALL_RECEIVER(ret, nd_line(node));
	  ADD_INSN1(ret, nd_line(node), putobject, node->nd_lit);
	  ADD_CALL(ret, nd_line(node), ID2SYM(idBackquote), INT2FIX(1));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_DXSTR:{
	  ADD_CALL_RECEIVER(ret, nd_line(node));
	  compile_dstr(iseq, ret, node);
	  ADD_CALL(ret, nd_line(node), ID2SYM(idBackquote), INT2FIX(1));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_EVSTR:{
	  COMPILE(ret, "nd_body", node->nd_body);

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  else {
	      ADD_INSN(ret, nd_line(node), tostring);
	  }
	  break;
      }
      case NODE_DREGX:{
	  compile_dstr(iseq, ret, node);
	  ADD_INSN1(ret, nd_line(node), toregexp, INT2FIX(node->nd_cflag));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_DREGX_ONCE:{
	  /* fix me: once? */
	  LABEL *lstart = NEW_LABEL(nd_line(node));
	  LABEL *lend = NEW_LABEL(nd_line(node));

	  ADD_LABEL(ret, lstart);
	  ADD_INSN2(ret, nd_line(node), onceinlinecache,
		    NEW_INLINE_CACHE_ENTRY(), lend);
	  ADD_INSN(ret, nd_line(node), pop);

	  compile_dstr(iseq, ret, node);
	  ADD_INSN1(ret, nd_line(node), toregexp, INT2FIX(node->nd_cflag));

	  ADD_INSN1(ret, nd_line(node), setinlinecache, lstart);
	  ADD_LABEL(ret, lend);

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_ARGS:{
	  /* OK */
	  COMPILE_ERROR(("BUG: should not reach here: compile_each#NODE_ARGS"));
	  break;
      }
      case NODE_ARGSCAT:{
	  COMPILE(ret, "argscat head", node->nd_head);
	  COMPILE(ret, "argscat body", node->nd_body);
	  ADD_INSN(ret, nd_line(node), concatarray);
	  break;
      }
      case NODE_ARGSPUSH:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_ARGSPUSH"));
	  break;
      }
      case NODE_SPLAT:{
	  COMPILE(ret, "splat", node->nd_head);
	  ADD_INSN1(ret, nd_line(node), splatarray, Qfalse);
	  break;
      }
      case NODE_TO_ARY:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_TO_ARY"));
	  break;
      }
      case NODE_BLOCK_PASS:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_BLOCK_PASS"));
	  break;
      }
      case NODE_DEFN:{
	  VALUE iseqval = NEW_ISEQVAL(node->nd_defn,
				      rb_str_new2(rb_id2name(node->nd_mid)),
				      ISEQ_TYPE_METHOD);

	  debugp_param("defn/iseq", iseqval);

	  ADD_INSN (ret, nd_line(node), putnil);
	  ADD_INSN3(ret, nd_line(node), definemethod,
		    ID2SYM(node->nd_mid), iseqval, INT2FIX(0));
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  debugp_param("defn", iseqval);
	  break;
      }
      case NODE_DEFS:{
	  VALUE iseqval = NEW_ISEQVAL(node->nd_defn,
				      rb_str_new2(rb_id2name(node->nd_mid)),
				      ISEQ_TYPE_METHOD);

	  debugp_param("defs/iseq", iseqval);

	  COMPILE(ret, "defs: recv", node->nd_recv);
	  ADD_INSN3(ret, nd_line(node), definemethod,
		    ID2SYM(node->nd_mid), iseqval, INT2FIX(1));
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  break;
      }
      case NODE_ALIAS:{
	  VALUE s1, s2;

	  if (nd_type(node->u1.node) != NODE_LIT ||
	      nd_type(node->u2.node) != NODE_LIT) {
	      rb_bug("alias args must be NODE_LIT");
	  }
	  s1 = node->u1.node->nd_lit;
	  s2 = node->u2.node->nd_lit;

	  ADD_INSN3(ret, nd_line(node), alias, Qfalse, ID2SYM(rb_to_id(s1)),
		    ID2SYM(rb_to_id(s2)));
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  break;
      }
      case NODE_VALIAS:{
	  ADD_INSN3(ret, nd_line(node), alias, Qtrue, ID2SYM(node->u1.id),
		    ID2SYM(node->u2.id));
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  break;
      }
      case NODE_UNDEF:{
	  if (nd_type(node->u2.node) != NODE_LIT) {
	      rb_bug("undef args must be NODE_LIT");
	  }
	  ADD_INSN1(ret, nd_line(node), undef,
		    ID2SYM(rb_to_id(node->u2.node->nd_lit)));
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  break;
      }
      case NODE_CLASS:{
	  VALUE iseqval =
	    NEW_CHILD_ISEQVAL(
		node->nd_body,
		make_name_with_str("<class:%s>",
				   rb_id2name(node->nd_cpath->nd_mid)),
		ISEQ_TYPE_CLASS);
	  compile_cpath(ret, iseq, node->nd_cpath);
	  COMPILE(ret, "super", node->nd_super);
	  ADD_INSN3(ret, nd_line(node), defineclass,
		    ID2SYM(node->nd_cpath->nd_mid), iseqval, INT2FIX(0));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_MODULE:{
	  VALUE iseqval = NEW_CHILD_ISEQVAL(node->nd_body,
					    make_name_with_str
					    ("<module:%s>",
					     rb_id2name(node->nd_cpath->
							nd_mid)),
					    ISEQ_TYPE_CLASS);

	  COMPILE(ret, "mbase", node->nd_cpath->nd_head);
	  ADD_INSN (ret, nd_line(node), putnil); /* dummy */
	  ADD_INSN3(ret, nd_line(node), defineclass,
		    ID2SYM(node->nd_cpath->nd_mid), iseqval, INT2FIX(2));
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_SCLASS:{
	  VALUE iseqval =
	    NEW_ISEQVAL(node->nd_body, rb_str_new2("singletonclass"),
			ISEQ_TYPE_CLASS);

	  COMPILE(ret, "sclass#recv", node->nd_recv);
	  ADD_INSN (ret, nd_line(node), putnil);
	  ADD_INSN3(ret, nd_line(node), defineclass,
		    ID2SYM(rb_intern("singletonclass")), iseqval, INT2FIX(1));

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_COLON2:{
	  if (rb_is_const_id(node->nd_mid)) {
	      /* constant */
	      LABEL *lstart = NEW_LABEL(nd_line(node));
	      LABEL *lend = NEW_LABEL(nd_line(node));
	      DECL_ANCHOR(pref);
	      DECL_ANCHOR(body);

	      compile_colon2(iseq, node, pref, body);
	      if (LIST_SIZE_ZERO(pref)) {
		  if (iseq->compile_data->option->inline_const_cache) {
		      ADD_LABEL(ret, lstart);
		      ADD_INSN2(ret, nd_line(node), getinlinecache,
				NEW_INLINE_CACHE_ENTRY(), lend);
		  }
		  else {
		      ADD_INSN(ret, nd_line(node), putnil);
		  }

		  ADD_SEQ(ret, body);

		  if (iseq->compile_data->option->inline_const_cache) {
		      ADD_INSN1(ret, nd_line(node), setinlinecache, lstart);
		      ADD_LABEL(ret, lend);
		  }
	      }
	      else {
		  ADD_SEQ(ret, pref);
		  ADD_SEQ(ret, body);
	      }
	  }
	  else {
	      /* function call */
	      ADD_CALL_RECEIVER(ret, nd_line(node));
	      COMPILE(ret, "colon2#nd_head", node->nd_head);
	      ADD_CALL(ret, nd_line(node), ID2SYM(node->nd_mid),
		       INT2FIX(1));
	  }
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_COLON3:{
	  LABEL *lstart = NEW_LABEL(nd_line(node));
	  LABEL *lend = NEW_LABEL(nd_line(node));
	  debugi("colon3#nd_mid", node->nd_mid);

	  /* add cache insn */
	  if (iseq->compile_data->option->inline_const_cache) {
	      ADD_LABEL(ret, lstart);
	      ADD_INSN2(ret, nd_line(node), getinlinecache,
			NEW_INLINE_CACHE_ENTRY(), lend);
	      ADD_INSN(ret, nd_line(node), pop);
	  }

	  ADD_INSN1(ret, nd_line(node), putobject, rb_cObject);
	  ADD_INSN1(ret, nd_line(node), getconstant, ID2SYM(node->nd_mid));

	  if (iseq->compile_data->option->inline_const_cache) {
	      ADD_INSN1(ret, nd_line(node), setinlinecache, lstart);
	      ADD_LABEL(ret, lend);
	  }

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_CREF:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_CREF"));
	  break;
      }
      case NODE_DOT2:
      case NODE_DOT3:{
	  int flag = type == NODE_DOT2 ? INT2FIX(0) : INT2FIX(1);
	  COMPILE(ret, "min", (NODE *) node->nd_beg);
	  COMPILE(ret, "max", (NODE *) node->nd_end);
	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  else {
	      ADD_INSN1(ret, nd_line(node), newrange, flag);
	  }
	  break;
      }
      case NODE_FLIP2:
      case NODE_FLIP3:{
	  LABEL *lend = NEW_LABEL(nd_line(node));
	  LABEL *lfin = NEW_LABEL(nd_line(node));
	  LABEL *ltrue = NEW_LABEL(nd_line(node));

	  ADD_INSN2(ret, nd_line(node), getspecial, INT2FIX(node->nd_cnt),
		    INT2FIX(0));
	  ADD_INSNL(ret, nd_line(node), branchif, lend) ;

	  /* *flip == 0 */
	  COMPILE(ret, "flip2 beg", node->nd_beg);
	  ADD_INSN(ret, nd_line(node), dup);
	  ADD_INSNL(ret, nd_line(node), branchunless, lfin);
	  if (nd_type(node) == NODE_FLIP3) {
	      ADD_INSN(ret, nd_line(node), dup);
	      ADD_INSN1(ret, nd_line(node), setspecial, INT2FIX(node->nd_cnt));
	      ADD_INSNL(ret, nd_line(node), jump, lfin);
	  }
	  else {
	      ADD_INSN1(ret, nd_line(node), setspecial, INT2FIX(node->nd_cnt));
	  }

	  /* *flip == 1 */
	  ADD_LABEL(ret, lend);
	  COMPILE(ret, "flip2 end", node->nd_end);
	  ADD_INSNL(ret, nd_line(node), branchunless, ltrue);
	  ADD_INSN1(ret, nd_line(node), putobject, Qfalse);
	  ADD_INSN1(ret, nd_line(node), setspecial, INT2FIX(node->nd_cnt));

	  ADD_LABEL(ret, ltrue);
	  ADD_INSN1(ret, nd_line(node), putobject, Qtrue);

	  ADD_LABEL(ret, lfin);
	  break;
      }
      case NODE_ATTRSET:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_ATTRSET"));
	  break;
      }
      case NODE_SELF:{
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putself);
	  }

	  break;
      }
      case NODE_NIL:{
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  break;
      }
      case NODE_TRUE:{
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), putobject, Qtrue);
	  }
	  break;
      }
      case NODE_FALSE:{
	  if (!poped) {
	      ADD_INSN1(ret, nd_line(node), putobject, Qfalse);
	  }
	  break;
      }
      case NODE_ERRINFO:{
	  if (!poped) {
	      if (iseq->type == ISEQ_TYPE_RESCUE) {
		  ADD_INSN2(ret, nd_line(node), getdynamic, INT2FIX(1),
			    INT2FIX(0));
	      }
	      else {
		  rb_iseq_t *ip = iseq;
		  int level = 0;
		  while (ip) {
		      if (ip->type == ISEQ_TYPE_RESCUE) {
			  break;
		      }
		      ip = ip->parent_iseq;
		      level++;
		  }
		  if (ip) {
		      ADD_INSN2(ret, nd_line(node), getdynamic, INT2FIX(1),
				INT2FIX(level));
		  }
		  else {
		      ADD_INSN(ret, nd_line(node), putnil);
		  }
	      }
	  }
	  break;
      }
      case NODE_DEFINED:{
	  if (!poped) {
	      LABEL *lfinish = NEW_LABEL(nd_line(node));
	      defined_expr(iseq, ret, node->nd_head, lfinish, Qtrue);
	      ADD_LABEL(ret, lfinish);
	  }
	  break;
      }
      case NODE_POSTEXE:{
	  VALUE block = NEW_CHILD_ISEQVAL(node, make_name_for_block(iseq), ISEQ_TYPE_BLOCK);
	  ADD_INSN1(ret, nd_line(node), postexe, block);
	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	  }
	  break;
      }
#ifdef C_ALLOCA
      case NODE_ALLOCA:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_ALLOCA"));
	  break;
      }
#endif
      case NODE_BMETHOD:{
	  /* block method, OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_BMETHOD"));
	  break;
      }
      case NODE_MEMO:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_MEMO"));
	  break;
      }
      case NODE_IFUNC:{
	  /* OK */
	  COMPILE_ERROR(("BUG: unknown node: NODE_IFUNC"));
	  break;
      }
      case NODE_DSYM:{
	  compile_dstr(iseq, ret, node);
	  if (!poped) {
	      ADD_SEND(ret, nd_line(node), ID2SYM(idIntern), INT2FIX(0));
	  }
	  else {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      case NODE_ATTRASGN:{
	  DECL_ANCHOR(recv);
	  DECL_ANCHOR(args);
	  VALUE flag = 0;
	  VALUE argc;

	  argc = setup_arg(iseq, args, node, &flag);

	  if (node->nd_recv == (NODE *) 1) {
	      ADD_INSN(recv, nd_line(node), putself);
	  }
	  else {
	      COMPILE(recv, "recv", node->nd_recv);
	  }

	  debugp_param("argc", argc);
	  debugp_param("nd_mid", ID2SYM(node->nd_mid));

	  if (!poped) {
	      ADD_INSN(ret, nd_line(node), putnil);
	      ADD_SEQ(ret, recv);
	      ADD_SEQ(ret, args);
	      ADD_INSN1(ret, nd_line(node), setn, INT2FIX(FIX2INT(argc) + 1));
	  }
	  else {
	      ADD_SEQ(ret, recv);
	      ADD_SEQ(ret, args);
	  }
	  ADD_SEND_R(ret, nd_line(node), ID2SYM(node->nd_mid), argc, 0, INT2FIX(flag));
	  ADD_INSN(ret, nd_line(node), pop);

	  break;
      }
      case NODE_OPTBLOCK:{
	  /* for optimize */
	  LABEL *redo_label = NEW_LABEL(0);
	  LABEL *next_label = NEW_LABEL(0);

	  iseq->compile_data->start_label = next_label;
	  iseq->compile_data->redo_label = redo_label;

	  ADD_LABEL(ret, redo_label);
	  COMPILE_(ret, "optblock body", node->nd_head, 1 /* pop */ );
	  ADD_LABEL(ret, next_label);
	  ADD_INSN(ret, 0, opt_checkenv);
	  break;
      }
      case NODE_PRELUDE:{
	  COMPILE_POPED(ret, "prelude", node->nd_head);
	  COMPILE_(ret, "body", node->nd_body, poped);
	  break;
      }
      case NODE_LAMBDA:{
	  /* compile same as lambda{...} */
	  VALUE block = NEW_CHILD_ISEQVAL(node, make_name_for_block(iseq), ISEQ_TYPE_BLOCK);
	  VALUE argc = INT2FIX(0);
	  ADD_CALL_RECEIVER(ret, nd_line(node));
	  ADD_CALL_WITH_BLOCK(ret, nd_line(node), ID2SYM(idLambda), argc, block);

	  if (poped) {
	      ADD_INSN(ret, nd_line(node), pop);
	  }
	  break;
      }
      default:
	COMPILE_ERROR(("BUG: unknown node (default): %s", ruby_node_name(type)));
	return Qnil;
    }

    debug_nodeprint_close();
    return COMPILE_OK;
}

/***************************/
/* instruction information */
/***************************/

static int
insn_data_length(INSN *iobj)
{
    return insn_len(iobj->insn_id);
}

static int
calc_sp_depth(int depth, INSN *insn)
{
    return insn_stack_increase(depth, insn->insn_id, insn->operands);
}

static int
insn_data_line_no(INSN *iobj)
{
    return insn_len(iobj->line_no);
}

static VALUE
insn_data_to_s_detail(INSN *iobj)
{
    VALUE str = rb_str_new(0, 0);
    char buff[0x100];

    snprintf(buff, sizeof(buff), "%-16s", insn_name(iobj->insn_id));
    rb_str_cat2(str, buff);
    if (iobj->operands) {
	char *types = insn_op_types(iobj->insn_id);
	int j;

	for (j = 0; types[j]; j++) {
	    char type = types[j];

	    switch (type) {
	      case TS_OFFSET:	/* label(destination position) */
		{
		    char buff[0x100];
		    LABEL *lobj = (LABEL *)OPERAND_AT(iobj, j);
		    snprintf(buff, sizeof(buff), "<L%03d>", lobj->label_no);
		    rb_str_concat(str, rb_str_new2(buff));
		    break;
		}
		break;
	      case TS_ISEQ:	/* iseq */
		{
		    rb_iseq_t *iseq = (rb_iseq_t *)OPERAND_AT(iobj, j);
		    VALUE val = Qnil;
		    if (iseq) {
			val = iseq->self;
		    }
		    rb_str_concat(str, rb_inspect(val));
		}
		break;
	      case TS_LINDEX:
	      case TS_DINDEX:
	      case TS_NUM:	/* ulong */
	      case TS_VALUE:	/* VALUE */
		rb_str_concat(str, rb_inspect(OPERAND_AT(iobj, j)));
		break;
	      case TS_ID:	/* ID */
		rb_str_concat(str, rb_inspect(OPERAND_AT(iobj, j)));
		break;
	      case TS_GENTRY:
		{
		    struct global_entry *entry = (struct global_entry *)
		      (OPERAND_AT(iobj, j) & (~1));
		    rb_str_cat2(str, rb_id2name(entry->id));
		}
	      case TS_IC:	/* method cache */
		rb_str_cat2(str, "<ic>");
		break;
	      case TS_CDHASH:	/* case/when condition cache */
		rb_str_cat2(str, "<ch>");
		break;
	      default:{
		  rb_bug("unknown operand type: %c", type);
	      }
	    }
	    if (types[j + 1]) {
		rb_str_cat2(str, ", ");
	    }
	}
    }
    return str;
}

static void
dump_disasm_list(struct iseq_link_element *link)
{
    int pos = 0;
    INSN *iobj;
    LABEL *lobj;
    VALUE str;

    printf("-- raw disasm--------\n");

    while (link) {
	switch (link->type) {
	case ISEQ_ELEMENT_INSN:{
		iobj = (INSN *)link;
		str = insn_data_to_s_detail(iobj);
		printf("%04d %-65s(%4d)\n", pos, StringValueCStr(str),
		       insn_data_line_no(iobj));
		pos += insn_data_length(iobj);
		break;
	    }
	case ISEQ_ELEMENT_LABEL:{
		lobj = (LABEL *)link;
		printf("<L%03d>\n", lobj->label_no);
		break;
	    }
	case ISEQ_ELEMENT_NONE:{
		printf("[none]\n");
		break;
	    }
	default:
	    /* ignore */
	    printf("%ld\n", FIX2LONG(link->type));
	    rb_bug("dump_disasm_list error");
	}
	link = link->next;
    }
    printf("---------------------\n");
}

int
nd_line_debug(NODE * n)
{
    return nd_line(n);
}

VALUE
insns_name_array(void)
{
    VALUE ary = rb_ary_new();
    int i;
    for (i = 0; i < sizeof(insn_name_info) / sizeof(insn_name_info[0]); i++) {
	rb_ary_push(ary, rb_str_new2(insn_name_info[i]));
    }
    return ary;
}

static LABEL *
register_label(rb_iseq_t *iseq, struct st_table *labels_table, VALUE obj)
{
    LABEL *label = 0;
    obj = rb_convert_type(obj, T_SYMBOL, "Symbol", "to_sym");

    if (st_lookup(labels_table, obj, (st_data_t *)&label) == 0) {
	label = NEW_LABEL(0);
	st_insert(labels_table, obj, (st_data_t)label);
    }
    return label;
}

static VALUE
get_exception_sym2type(VALUE sym)
{
    static VALUE symRescue, symEnsure, symRetry;
    static VALUE symBreak, symRedo, symNext;

    if (symRescue == 0) {
	symRescue = ID2SYM(rb_intern("rescue"));
	symEnsure = ID2SYM(rb_intern("ensure"));
	symRetry  = ID2SYM(rb_intern("retry"));
	symBreak  = ID2SYM(rb_intern("break"));
	symRedo   = ID2SYM(rb_intern("redo"));
	symNext   = ID2SYM(rb_intern("next"));
    }

    if (sym == symRescue) return CATCH_TYPE_RESCUE;
    if (sym == symEnsure) return CATCH_TYPE_ENSURE;
    if (sym == symRetry)  return CATCH_TYPE_RETRY;
    if (sym == symBreak)  return CATCH_TYPE_BREAK;
    if (sym == symRedo)   return  CATCH_TYPE_REDO;
    if (sym == symNext)   return CATCH_TYPE_NEXT;
    rb_bug("get_exception_sym2type");
    return 0;
}

static int
iseq_build_exception(rb_iseq_t *iseq, struct st_table *labels_table,
		     VALUE exception)
{
    int i;
    VALUE tmp;
    
    for (i=0; i<RARRAY_LEN(exception); i++) {
	VALUE v = rb_ary_entry(exception, i);
	VALUE *ptr = RARRAY_PTR(v);
	VALUE type = get_exception_sym2type(ptr[0]);
	VALUE eiseqval;
	LABEL *lstart, *lend, *lcont;
	int sp;

	if (ptr[1] == Qnil) {
	    eiseqval = 0;
	}
	else {
	    eiseqval = iseq_load(0, ptr[1], iseq->self, Qnil);
	}

	lstart = register_label(iseq, labels_table, ptr[2]);
	lend   = register_label(iseq, labels_table, ptr[3]);
	lcont  = register_label(iseq, labels_table, ptr[4]);
	sp     = NUM2INT(ptr[5]);

	ADD_CATCH_ENTRY(type, lstart, lend, eiseqval, lcont);
    }
    return COMPILE_OK;
}


struct st_table *insn_make_insn_table(void);

static int
iseq_build_body(rb_iseq_t *iseq, LINK_ANCHOR *anchor,
		VALUE body, VALUE line, struct st_table *labels_table)
{
    /* TODO: body should be freezed */
    VALUE *ptr = RARRAY_PTR(body);
    int len = RARRAY_LEN(body);
    int i, j;
    int line_no = 0;
    /*
     * index -> LABEL *label
     */
    static struct st_table *insn_table;

    if (insn_table == 0) {
	insn_table = insn_make_insn_table();
    }

    for (i=0; i<len; i++) {
	VALUE obj = ptr[i];

	if (SYMBOL_P(obj)) {
	    LABEL *label = register_label(iseq, labels_table, obj);
	    ADD_LABEL(anchor, label);
	}
	else if (FIXNUM_P(obj)) {
	    line_no = NUM2INT(obj);
	}
	else if (TYPE(obj) == T_ARRAY) {
	    VALUE *argv = 0;
	    int argc = RARRAY_LEN(obj) - 1;
	    VALUE insn_id;

	    if (st_lookup(insn_table, rb_ary_entry(obj, 0), &insn_id) == 0) {
		/* TODO: exception */
		rb_bug("unknown instruction: ");
	    }

	    if (argc != insn_len(insn_id)-1) {
		rb_bug("operand size mismatch");
	    }

	    if (argc > 0) {
		argv = compile_data_alloc(iseq, sizeof(VALUE) * argc);
		for (j=0; j<argc; j++) {
		    VALUE op = rb_ary_entry(obj, j+1);
		    switch (insn_op_type(insn_id, j)) {
		      case TS_OFFSET: {
			  LABEL *label = register_label(iseq, labels_table, op);
			  argv[j] = (VALUE)label;
			  break;
		      }
		      case TS_LINDEX:
		      case TS_DINDEX:
		      case TS_NUM:
			argv[j] = (NUM2INT(op), op);
			break;
		      case TS_VALUE:
			argv[j] = op;
			if (!SPECIAL_CONST_P(op)) {
			    iseq_add_mark_object(iseq, op);
			}
			break;
		      case TS_ISEQ:
			{
			    if (op != Qnil) {
				if (TYPE(op) == T_ARRAY) {
				    argv[j] =
				      iseq_load(0, op, iseq->self, Qnil);
				}
				else if (CLASS_OF(op) == rb_cISeq) {
				    argv[j] = op;
				}
				else {
				    /* TODO: exception */
				    rb_bug("not an iseq");
				}
				iseq_add_mark_object(iseq, argv[j]);
			    }
			    else {
				argv[j] = 0;
			    }
			}
			break;
		      case TS_GENTRY:
			op = rb_convert_type(op, T_SYMBOL, "Symbol", "to_sym");
			argv[j] = (VALUE)rb_global_entry(SYM2ID(op));
			break;
		      case TS_IC:
			argv[j] = (VALUE)NEW_INLINE_CACHE_ENTRY();
			iseq_add_mark_object(iseq, argv[j]);
			break;
		      case TS_ID:
			argv[j] = rb_convert_type(op, T_SYMBOL,
						  "Symbol", "to_sym");
			break;
		      case TS_CDHASH:
			{
			    int i;
			    op = rb_convert_type(op, T_ARRAY, "Array", "to_ary");
			    for (i=0; i<RARRAY_LEN(op); i+=2) {
				VALUE sym = rb_ary_entry(op, i+1);
				LABEL *label =
				  register_label(iseq, labels_table, sym);
				rb_ary_store(op, i+1, (VALUE)label | 1);
			    }
			    argv[j] = op;
			}
			break;
		      default:
			rb_bug("unknown operand: %c", insn_op_type(insn_id, j));
		    }
		}
	    }
	    ADD_ELEM(anchor,
		     (LINK_ELEMENT*)new_insn_core(iseq, line_no,
						  insn_id, argc, argv));
	}
	else {
	    rb_raise(rb_eTypeError, "unexpected object for instruction");
	}
    }
    st_free_table(labels_table);
    iseq_setup(iseq, anchor);
    return COMPILE_OK;
}

VALUE
iseq_build_from_ary(rb_iseq_t *iseq, VALUE line,
		    VALUE locals, VALUE args, VALUE exception, VALUE body)
{
    int i;
    int opt = 0;
    ID *tbl;
    struct st_table *labels_table = st_init_numtable();

    DECL_ANCHOR(anchor);

    if (iseq->type == ISEQ_TYPE_METHOD ||
	iseq->type == ISEQ_TYPE_TOP ||
	iseq->type == ISEQ_TYPE_CLASS) {
	opt = 1;
    }

    iseq->local_size = opt + RARRAY_LEN(locals);
    iseq->local_table_size = iseq->local_size;
    iseq->local_table = (ID *)ALLOC_N(ID *, iseq->local_size);
    tbl = iseq->local_table + opt;
    
    for (i=0; i<RARRAY_LEN(locals); i++) {
	tbl[i] = SYM2ID(RARRAY_PTR(locals)[i]);
    }
    
    /* args */
    if (FIXNUM_P(args)) {
	iseq->argc = FIX2INT(args);
	iseq->arg_simple = 1;
    }
    else {
	/*
	 * [argc,                 # argc
	 *  opts,                 # opts
	 *  [label1, label2, ...] # opt labels
	 *  rest_iex,
	 *  block_idx,
	 * ]
	 * or
	 *  argc (Fixnum) # arg_simple
	 */
	int i = 0;
	VALUE argc  = rb_ary_entry(args, i++);
	VALUE arg_opts = rb_ary_entry(args, i++);
	VALUE arg_opt_labels = rb_ary_entry(args, i++);
	VALUE arg_rest = rb_ary_entry(args, i++);
	VALUE arg_block = rb_ary_entry(args, i++);

	iseq->argc = FIX2INT(argc);
	iseq->arg_opts = FIX2INT(arg_opts);
	iseq->arg_rest = FIX2INT(arg_rest);
	iseq->arg_block = FIX2INT(arg_block);

	iseq->arg_opt_tbl = (VALUE *)ALLOC_N(VALUE, iseq->arg_opts);
	
	for (i=0; i<RARRAY_LEN(arg_opt_labels); i++) {
	    iseq->arg_opt_tbl[i] = 
	      (VALUE)register_label(iseq, labels_table,
				    rb_ary_entry(arg_opt_labels, i));
	}
    }

    /* exception */
    iseq_build_exception(iseq, labels_table, exception);
    
    /* body */
    iseq_build_body(iseq, anchor, body, line, labels_table);
    return iseq->self;
}
