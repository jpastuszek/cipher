/**********************************************************************

  iseq.c -

  $Author: ko1 $
  $Date: 2007-02-26 01:29:26 +0900 (月, 26 2 2007) $
  created at: 2006-07-11(Tue) 09:00:03 +0900

  Copyright (C) 2006 Koichi Sasada

**********************************************************************/

#include <ruby.h>
#include <node.h>

#include "yarvcore.h"
#include "insns.inc"
#include "insns_info.inc"

/* #define MARK_FREE_DEBUG 1 */
#include "gc.h"

VALUE rb_cISeq;

static void
compile_data_free(struct iseq_compile_data *compile_data)
{
    if (compile_data) {
	struct iseq_compile_data_storage *cur, *next;
	cur = compile_data->storage_head;
	while (cur) {
	    next = cur->next;
	    ruby_xfree(cur);
	    cur = next;
	}
	ruby_xfree(compile_data);
    }
}

static void
iseq_free(void *ptr)
{
    rb_iseq_t *iseq;
    FREE_REPORT_ENTER("iseq");

    if (ptr) {
	iseq = ptr;
	/* It's possible that strings are freed
         * GC_INFO("%s @ %s\n", RSTRING_PTR(iseq->name),
         *                      RSTRING_PTR(iseq->filename));
	 */
	if (iseq->iseq != iseq->iseq_encoded) {
	    FREE_UNLESS_NULL(iseq->iseq_encoded);
	}
	
	FREE_UNLESS_NULL(iseq->iseq);
	FREE_UNLESS_NULL(iseq->insn_info_tbl);
	FREE_UNLESS_NULL(iseq->local_table);
	FREE_UNLESS_NULL(iseq->catch_table);
	FREE_UNLESS_NULL(iseq->arg_opt_tbl);
	compile_data_free(iseq->compile_data);
	ruby_xfree(ptr);
    }
    FREE_REPORT_LEAVE("iseq");
}

static void
iseq_mark(void *ptr)
{
    rb_iseq_t *iseq;
    MARK_REPORT_ENTER("iseq");

    if (ptr) {
	iseq = ptr;
	GC_INFO("%s @ %s\n", RSTRING_PTR(iseq->name), RSTRING_PTR(iseq->filename));
	MARK_UNLESS_NULL(iseq->iseq_mark_ary);
	MARK_UNLESS_NULL(iseq->name);
	MARK_UNLESS_NULL(iseq->filename);
	MARK_UNLESS_NULL((VALUE)iseq->cref_stack);
	MARK_UNLESS_NULL(iseq->klass);
	MARK_UNLESS_NULL((VALUE)iseq->node);
	MARK_UNLESS_NULL(iseq->cached_special_block);

	if (iseq->compile_data != 0) {
	    MARK_UNLESS_NULL(iseq->compile_data->mark_ary);
	    MARK_UNLESS_NULL(iseq->compile_data->err_info);
	    MARK_UNLESS_NULL(iseq->compile_data->catch_table_ary);
	}
    }
    MARK_REPORT_LEAVE("iseq");
}

static VALUE
iseq_alloc(VALUE klass)
{
    VALUE volatile obj;
    rb_iseq_t *iseq;

    obj = Data_Make_Struct(klass, rb_iseq_t, iseq_mark, iseq_free, iseq);
    MEMZERO(iseq, rb_iseq_t, 1);
    return obj;
}

static VALUE
prepare_iseq_build(rb_iseq_t *iseq,
		   VALUE name, VALUE filename,
		   VALUE parent, VALUE type, VALUE block_opt,
		   const rb_compile_option_t *option)
{
    rb_thread_t *th = GET_THREAD();

    iseq->name = name;
    iseq->defined_method_id = 0;
    iseq->filename = filename;
    iseq->iseq_mark_ary = rb_ary_new();
    RBASIC(iseq->iseq_mark_ary)->klass = 0;

    iseq->type = type;
    iseq->arg_rest = 0;
    iseq->arg_block = 0;
    iseq->klass = 0;
    iseq->special_block_builder = GC_GUARDED_PTR_REF(block_opt);
    iseq->cached_special_block_builder = 0;
    iseq->cached_special_block = 0;

    /* set class nest stack */
    if (type == ISEQ_TYPE_TOP) {
	/* toplevel is private */
	iseq->cref_stack = NEW_BLOCK(th->top_wrapper ? th->top_wrapper : rb_cObject);
	iseq->cref_stack->nd_file = 0;
	iseq->cref_stack->nd_visi = NOEX_PRIVATE;
    }
    else if (type == ISEQ_TYPE_METHOD || type == ISEQ_TYPE_CLASS) {
	iseq->cref_stack = NEW_BLOCK(0); /* place holder */
	iseq->cref_stack->nd_file = 0;
    }
    else if (parent) {
	rb_iseq_t *piseq;
	GetISeqPtr(parent, piseq);
	iseq->cref_stack = piseq->cref_stack;
    }

    iseq->compile_data = ALLOC(struct iseq_compile_data);
    MEMZERO(iseq->compile_data, struct iseq_compile_data, 1);
    iseq->compile_data->mark_ary = rb_ary_new();
    RBASIC(iseq->compile_data->mark_ary)->klass = 0;

    iseq->compile_data->storage_head = iseq->compile_data->storage_current =
      (struct iseq_compile_data_storage *)
	ALLOC_N(char, INITIAL_ISEQ_COMPILE_DATA_STORAGE_BUFF_SIZE +
		sizeof(struct iseq_compile_data_storage));

    iseq->compile_data->catch_table_ary = rb_ary_new();
    iseq->compile_data->storage_head->pos = 0;
    iseq->compile_data->storage_head->next = 0;
    iseq->compile_data->storage_head->size =
      INITIAL_ISEQ_COMPILE_DATA_STORAGE_BUFF_SIZE;
    iseq->compile_data->storage_head->buff =
      (char *)(&iseq->compile_data->storage_head->buff + 1);
    iseq->compile_data->option = option;

    if (type == ISEQ_TYPE_TOP ||
	type == ISEQ_TYPE_METHOD || type == ISEQ_TYPE_CLASS) {
	iseq->local_iseq = iseq;
    }
    else {
	rb_iseq_t *piseq;
	GetISeqPtr(parent, piseq);
	iseq->local_iseq = piseq->local_iseq;
    }

    if (RTEST(parent)) {
	rb_iseq_t *piseq;
	GetISeqPtr(parent, piseq);
	iseq->parent_iseq = piseq;
    }

    return Qtrue;
}

static VALUE
cleanup_iseq_build(rb_iseq_t *iseq)
{
    struct iseq_compile_data *data = iseq->compile_data;
    iseq->compile_data = 0;
    compile_data_free(data);
    
    if (ruby_nerrs > 0) {
	VALUE str = rb_str_buf_new2("compile error");
	ruby_nerrs = 0;
	rb_exc_raise(rb_exc_new3(rb_eSyntaxError, str));
    }
    return Qtrue;
}

static rb_compile_option_t COMPILE_OPTION_DEFAULT = {
    OPT_INLINE_CONST_CACHE, /* int inline_const_cache; */
    OPT_PEEPHOLE_OPTIMIZATION, /* int peephole_optimization; */
    OPT_SPECIALISED_INSTRUCTION, /* int specialized_instruction; */
    OPT_OPERANDS_UNIFICATION, /* int operands_unification; */
    OPT_INSTRUCTIONS_UNIFICATION, /* int instructions_unification; */
    OPT_STACK_CACHING, /* int stack_caching; */
};
static const rb_compile_option_t COMPILE_OPTION_FALSE;

static void
make_compile_option(rb_compile_option_t *option, VALUE opt)
{
    if (opt == Qnil) {
	*option = COMPILE_OPTION_DEFAULT;
    }
    else if (opt == Qfalse) {
	*option = COMPILE_OPTION_FALSE;
    }
    else if (opt == Qtrue) {
	memset(option, 1, sizeof(rb_compile_option_t));
    }
    else if (CLASS_OF(opt) == rb_cHash) {
#define SET_COMPILE_OPTION(o, h, mem) \
  { VALUE flag = rb_hash_aref(h, ID2SYM(rb_intern(#mem))); dp(flag);\
      if (flag == Qtrue)  { o->mem = 1; } \
      if (flag == Qfalse) { o->mem = 0; } \
  }
	SET_COMPILE_OPTION(option, opt, inline_const_cache);
	SET_COMPILE_OPTION(option, opt, peephole_optimization);
	SET_COMPILE_OPTION(option, opt, specialized_instruction);
	SET_COMPILE_OPTION(option, opt, operands_unification);
	SET_COMPILE_OPTION(option, opt, instructions_unification);
	SET_COMPILE_OPTION(option, opt, stack_caching);
#undef SET_COMPILE_OPTION
    }
    else {
	rb_raise(rb_eTypeError, "Compile option must be Hash/true/false/nil");
    }
}

static VALUE
make_compile_option_value(rb_compile_option_t *option)
{
    VALUE opt = rb_hash_new();
#define SET_COMPILE_OPTION(o, h, mem) \
  rb_hash_aset(h, ID2SYM(rb_intern(#mem)), o->mem ? Qtrue : Qfalse)
    {
	SET_COMPILE_OPTION(option, opt, inline_const_cache);
	SET_COMPILE_OPTION(option, opt, peephole_optimization);
	SET_COMPILE_OPTION(option, opt, specialized_instruction);
	SET_COMPILE_OPTION(option, opt, operands_unification);
	SET_COMPILE_OPTION(option, opt, instructions_unification);
	SET_COMPILE_OPTION(option, opt, stack_caching);
    }
#undef SET_COMPILE_OPTION
    return opt;
}

VALUE
rb_iseq_new(NODE *node, VALUE name, VALUE filename,
	      VALUE parent, VALUE type)
{
    return rb_iseq_new_with_opt(node, name, filename, parent, type,
				&COMPILE_OPTION_DEFAULT);
}

static VALUE
rb_iseq_new_with_bopt_and_opt(NODE *node, VALUE name, VALUE filename,
				VALUE parent, VALUE type, VALUE bopt,
				const rb_compile_option_t *option)
{
    rb_iseq_t *iseq;
    VALUE self = iseq_alloc(rb_cISeq);
    
    GetISeqPtr(self, iseq);
    iseq->self = self;

    prepare_iseq_build(iseq, name, filename, parent, type, bopt, option);
    iseq_compile(self, node);
    cleanup_iseq_build(iseq);
    return self;
}

VALUE
rb_iseq_new_with_opt(NODE *node, VALUE name, VALUE filename,
		     VALUE parent, VALUE type,
		     const rb_compile_option_t *option)
{
    return rb_iseq_new_with_bopt_and_opt(node, name, filename, parent, type,
					   Qfalse, option);
}

VALUE
rb_iseq_new_with_bopt(NODE *node, VALUE name, VALUE filename,
		       VALUE parent, VALUE type, VALUE bopt)
{
    return rb_iseq_new_with_bopt_and_opt(node, name, filename, parent, type,
					   bopt, &COMPILE_OPTION_DEFAULT);
}

VALUE iseq_build_from_ary(rb_iseq_t *iseq, VALUE line,
			  VALUE locals, VALUE args, VALUE exception, VALUE body);

#define CHECK_ARRAY(v)   rb_convert_type(v, T_ARRAY, "Array", "to_ary")
#define CHECK_STRING(v)  rb_convert_type(v, T_STRING, "String", "to_str")
#define CHECK_SYMBOL(v)  rb_convert_type(v, T_SYMBOL, "Symbol", "to_sym")
#define CHECK_INTEGER(v) (NUM2LONG(v), v)
VALUE
iseq_load(VALUE self, VALUE data, VALUE parent, VALUE opt)
{
    VALUE iseqval = iseq_alloc(rb_cISeq);

    VALUE magic, version1, version2, format_type, misc;
    VALUE name, filename, line;
    VALUE type, body, locals, args, exception;

    VALUE iseq_type;
    struct st_table *type_map = 0;
    rb_iseq_t *iseq;
    rb_compile_option_t option;

    /* [magic, major_version, minor_version, format_type, misc,
     *  name, filename, line,
     *  type, locals, args, exception_table, body]
     */

    data        = CHECK_ARRAY(data);
    
    magic       = CHECK_STRING(rb_ary_entry(data, 0));
    version1    = CHECK_INTEGER(rb_ary_entry(data, 1));
    version2    = CHECK_INTEGER(rb_ary_entry(data, 2));
    format_type = CHECK_INTEGER(rb_ary_entry(data, 3));
    misc        = rb_ary_entry(data, 4); /* TODO */

    name        = CHECK_STRING(rb_ary_entry(data, 5));
    filename    = CHECK_STRING(rb_ary_entry(data, 6));
    line        = CHECK_ARRAY(rb_ary_entry(data, 7));

    type        = CHECK_SYMBOL(rb_ary_entry(data, 8));
    locals      = CHECK_ARRAY(rb_ary_entry(data, 9));
    args = rb_ary_entry(data, 10);
    if (FIXNUM_P(args) || (args = CHECK_ARRAY(args))) {
	/* */
    }
    exception   = CHECK_ARRAY(rb_ary_entry(data, 11));
    body        = CHECK_ARRAY(rb_ary_entry(data, 12));

    GetISeqPtr(iseqval, iseq);
    iseq->self = iseqval;

    if (type_map == 0) {
	type_map = st_init_numtable();
	st_insert(type_map, ID2SYM(rb_intern("toplevel")), ISEQ_TYPE_TOP);
	st_insert(type_map, ID2SYM(rb_intern("method")),   ISEQ_TYPE_METHOD);
	st_insert(type_map, ID2SYM(rb_intern("block")),    ISEQ_TYPE_BLOCK);
	st_insert(type_map, ID2SYM(rb_intern("class")),    ISEQ_TYPE_CLASS);
	st_insert(type_map, ID2SYM(rb_intern("rescue")),   ISEQ_TYPE_RESCUE);
	st_insert(type_map, ID2SYM(rb_intern("ensure")),   ISEQ_TYPE_ENSURE);
	st_insert(type_map, ID2SYM(rb_intern("eval")),     ISEQ_TYPE_EVAL);
    }

    if (st_lookup(type_map, type, &iseq_type) == 0) {
	rb_raise(rb_eTypeError, "unsupport type: %p", type);
    }

    if (parent == Qnil) {
	parent = 0;
    }

    make_compile_option(&option, opt);
    prepare_iseq_build(iseq, name, filename,
		       parent, iseq_type, 0, &option);

    iseq_build_from_ary(iseq, line, locals, args, exception, body);

    cleanup_iseq_build(iseq);
    return iseqval;
}

static VALUE
iseq_s_load(int argc, VALUE *argv, VALUE self)
{
    VALUE data, opt=Qnil;
    rb_scan_args(argc, argv, "11", &data, &opt);
    
    return iseq_load(self, data, 0, opt);
}

static NODE *
compile_string(VALUE str, VALUE file, VALUE line)
{
    NODE *node;
    node = rb_compile_string(StringValueCStr(file), str, NUM2INT(line));

    if (ruby_nerrs > 0) {
	ruby_nerrs = 0;
	rb_exc_raise(GET_THREAD()->errinfo);	/* TODO: check err */
    }
    return node;
}

static VALUE
iseq_s_compile(int argc, VALUE *argv, VALUE self)
{
    VALUE str, file = Qnil, line = INT2FIX(1), opt = Qnil;
    NODE *node;
    rb_compile_option_t option;
    
    rb_scan_args(argc, argv, "13", &str, &file, &line, &opt);

    file = file == Qnil ? rb_str_new2("<compiled>") : file;
    line = line == Qnil ? INT2FIX(1) : line;

    node = compile_string(str, file, line);
    make_compile_option(&option, opt);
    return rb_iseq_new_with_opt(node, rb_str_new2("<main>"), file, Qfalse,
				ISEQ_TYPE_TOP, &option);
}

static VALUE
iseq_s_compile_file(int argc, VALUE *argv, VALUE self)
{
    VALUE file, line = INT2FIX(1), opt = Qnil;
    VALUE parser;
    VALUE f;
    NODE *node;
    const char *fname;
    rb_compile_option_t option;

    rb_scan_args(argc, argv, "11", &file, &opt);
    fname = StringValueCStr(file);

    f = rb_file_open(fname, "r");

    parser = rb_parser_new();
    node = rb_parser_compile_file(parser, fname, f, NUM2INT(line));
    make_compile_option(&option, opt);
    return rb_iseq_new_with_opt(node, rb_str_new2("<main>"), file, Qfalse,
				ISEQ_TYPE_TOP, &option);
}

static VALUE
iseq_s_compile_option_set(VALUE self, VALUE opt)
{
    rb_compile_option_t option;
    make_compile_option(&option, opt);
    COMPILE_OPTION_DEFAULT = option;
    return make_compile_option_value(&option);
}

static rb_iseq_t *
iseq_check(VALUE val)
{
    rb_iseq_t *iseq;
    GetISeqPtr(val, iseq);
    if (!iseq->name) {
	rb_raise(rb_eTypeError, "uninitialized InstructionSequence");
    }
    return iseq;
}

static VALUE
iseq_eval(VALUE self)
{
    return rb_thread_eval(GET_THREAD(), self);
}

static VALUE
iseq_inspect(VALUE self)
{
    char buff[0x100];
    rb_iseq_t *iseq = iseq_check(self);

    snprintf(buff, sizeof(buff), "<ISeq:%s@%s>",
	     RSTRING_PTR(iseq->name), RSTRING_PTR(iseq->filename));

    return rb_str_new2(buff);
}

VALUE iseq_data_to_ary(rb_iseq_t *iseq);

static VALUE
iseq_to_a(VALUE self)
{
    rb_iseq_t *iseq = iseq_check(self);
    return iseq_data_to_ary(iseq);
}

/*
  now, search algorithm is brute force. but this should be binary search.
 */
static unsigned short
find_line_no(rb_iseq_t *iseqdat, unsigned long pos)
{
    unsigned long i, size = iseqdat->insn_info_size;
    struct insn_info_struct *iiary = iseqdat->insn_info_tbl;

    for (i = 0; i < size; i++) {
	if (iiary[i].position == pos) {
	    return iiary[i].line_no;
	}
    }
    /* rb_bug("find_line_no: can't find %lu", pos); */
    return 0;
}

static unsigned short
find_prev_line_no(rb_iseq_t *iseqdat, unsigned long pos)
{
    unsigned long i, size = iseqdat->insn_info_size;
    struct insn_info_struct *iiary = iseqdat->insn_info_tbl;

    for (i = 0; i < size; i++) {
	if (iiary[i].position == pos) {
	    if (i > 0) {
		return iiary[i - 1].line_no;
	    }
	    else {
		return 0;
	    }
	}
    }
    rb_bug("find_prev_line_no: can't find - %lu", pos);
    return 0;
}

static VALUE
insn_operand_intern(rb_iseq_t *iseq,
		    int insn, int op_no, VALUE op,
		    int len, int pos, VALUE *pnop, VALUE child)
{
    char *types = insn_op_types(insn);
    char type = types[op_no];
    VALUE ret;
    char buff[0x100];

    switch (type) {
    case TS_OFFSET:		/* LONG */
	snprintf(buff, sizeof(buff), "%ld", pos + len + op);
	ret = rb_str_new2(buff);
	break;

    case TS_NUM:		/* ULONG */
	snprintf(buff, sizeof(buff), "%lu", op);
	ret = rb_str_new2(buff);
	break;

    case TS_LINDEX:
	{
	    rb_iseq_t *ip = iseq->local_iseq;
	    int lidx = ip->local_size - op;
	    ID id = ip->local_table[lidx];

	    if (id) {
		ret = rb_str_new2(rb_id2name(id));
	    }
	    else {
		ret = rb_str_new2("*");
	    }
	    break;
	}
    case TS_DINDEX:{
	    if (insn == BIN(getdynamic) || insn == BIN(setdynamic)) {
		rb_iseq_t *ip = iseq;
		int level = *pnop;
		int i;
		for (i = 0; i < level; i++) {
		    ip = ip->parent_iseq;
		}
		ret = rb_str_new2(rb_id2name(ip->local_table[ip->local_size - op]));
	    }
	    else {
		ret = rb_inspect(INT2FIX(op));
	    }
	    break;
	}
    case TS_ID:		/* ID (symbol) */
	op = ID2SYM(op);
    case TS_VALUE:		/* VALUE */
	ret = rb_inspect(op);
	if (CLASS_OF(op) == rb_cISeq) {
	    rb_ary_push(child, op);
	}
	break;

    case TS_ISEQ:		/* iseq */
	{
	    rb_iseq_t *iseq = (rb_iseq_t *)op;
	    if (iseq) {
		ret = iseq->name;
		if (child) {
		    rb_ary_push(child, iseq->self);
		}
	    }
	    else {
		ret = rb_str_new2("nil");
	    }
	    break;
	}
    case TS_GENTRY:
	{
	    struct global_entry *entry = (struct global_entry *)op;
	    ret = rb_str_new2(rb_id2name(entry->id));
	}
	break;

    case TS_IC:
	ret = rb_str_new2("<ic>");
	break;

    case TS_CDHASH:
	ret = rb_str_new2("<cdhash>");
	break;

    default:
	rb_bug("ruby_iseq_disasm: unknown operand type: %c", type);
    }
    return ret;
}

/**
 * Disassemble a instruction
 * Iseq -> Iseq inspect object
 */
VALUE
ruby_iseq_disasm_insn(VALUE ret, VALUE *iseq, int pos,
		 rb_iseq_t *iseqdat, VALUE child)
{
    int insn = iseq[pos];
    int len = insn_len(insn);
    int i, j;
    char *types = insn_op_types(insn);
    VALUE str = rb_str_new(0, 0);
    char buff[0x100];
    char insn_name_buff[0x100];

    strcpy(insn_name_buff, insn_name(insn));
    if (0) {
	for (i = 0; insn_name_buff[i]; i++) {
	    if (insn_name_buff[i] == '_') {
		insn_name_buff[i] = 0;
	    }
	}
    }

    snprintf(buff, sizeof(buff), "%04d %-16s ", pos, insn_name_buff);
    rb_str_cat2(str, buff);

    for (j = 0; types[j]; j++) {
	char *types = insn_op_types(insn);
	VALUE opstr = insn_operand_intern(iseqdat, insn, j, iseq[pos + j + 1],
					  len, pos, &iseq[pos + j + 2],
					  child);
	rb_str_concat(str, opstr);

	GC_CHECK();
	if (types[j + 1]) {
	    rb_str_cat2(str, ", ");
	}
    }

    {
	int line_no = find_line_no(iseqdat, pos);
	int prev = find_prev_line_no(iseqdat, pos);
	if (line_no && line_no != prev) {
	    snprintf(buff, sizeof(buff), "%-70s(%4d)", RSTRING_PTR(str),
		     line_no);
	    str = rb_str_new2(buff);
	}
    }
    if (ret) {
	rb_str_cat2(str, "\n");
	rb_str_concat(ret, str);
    }
    else {
	printf("%s\n", RSTRING_PTR(str));
    }
    return len;
}

static char *
catch_type(int type)
{
    switch (type) {
    case CATCH_TYPE_RESCUE:
	return "rescue";
    case CATCH_TYPE_ENSURE:
	return "ensure";
    case CATCH_TYPE_RETRY:
	return "retry";
    case CATCH_TYPE_BREAK:
	return "break";
    case CATCH_TYPE_REDO:
	return "redo";
    case CATCH_TYPE_NEXT:
	return "next";
    default:
	rb_bug("unknown catch type (%d)", type);
	return 0;
    }
}

VALUE
ruby_iseq_disasm(VALUE self)
{
    rb_iseq_t *iseqdat = iseq_check(self);
    VALUE *iseq;
    VALUE str = rb_str_new(0, 0);
    VALUE child = rb_ary_new();
    unsigned long size;
    int i;
    ID *tbl;
    char buff[0x200];

    iseq = iseqdat->iseq;
    size = iseqdat->size;

    rb_str_cat2(str, "== disasm: ");

    rb_str_concat(str, iseq_inspect(iseqdat->self));
    for (i = RSTRING_LEN(str); i < 72; i++) {
	rb_str_cat2(str, "=");
    }
    rb_str_cat2(str, "\n");

    /* show catch table information */
    if (iseqdat->catch_table_size != 0) {
	rb_str_cat2(str, "== catch table\n");
    }
    for (i = 0; i < iseqdat->catch_table_size; i++) {
	struct catch_table_entry *entry = &iseqdat->catch_table[i];
	sprintf(buff,
		"| catch type: %-6s st: %04d ed: %04d sp: %04d cont: %04d\n",
		catch_type((int)entry->type), (int)entry->start,
		(int)entry->end, (int)entry->sp, (int)entry->cont);
	rb_str_cat2(str, buff);
	if (entry->iseq) {
	    rb_str_concat(str, ruby_iseq_disasm(entry->iseq));
	}
    }
    if (iseqdat->catch_table_size != 0) {
	rb_str_cat2(str, "|-------------------------------------"
		    "-----------------------------------\n");
    }

    /* show local table information */
    tbl = iseqdat->local_table;

    if (tbl) {
	snprintf(buff, sizeof(buff),
		 "local scope table (size: %d, argc: %d)\n",
		 iseqdat->local_size, iseqdat->argc);
	rb_str_cat2(str, buff);

	for (i = 0; i < iseqdat->local_table_size; i++) {
	    const char *name = rb_id2name(tbl[i]);
	    char info[0x100];
	    char argi[0x100] = "";
	    char opti[0x100] = "";

	    if (iseqdat->arg_opts) {
		int argc = iseqdat->argc;
		int opts = iseqdat->arg_opts;
		if (i >= argc && i < argc + opts - 1) {
		    snprintf(opti, sizeof(opti), "Opt=%ld",
			     iseqdat->arg_opt_tbl[i - argc]);
		}
	    }

	    snprintf(argi, sizeof(argi), "%s%s%s%s",	/* arg, opts, rest, block */
		     iseqdat->argc > i ? "Arg" : "",
		     opti,
		     iseqdat->arg_rest - 1 == i ? "Rest" : "",
		     iseqdat->arg_block - 1 == i ? "Block" : "");

	    snprintf(info, sizeof(info), "%s%s%s%s", name ? name : "?",
		     *argi ? "<" : "", argi, *argi ? ">" : "");

	    snprintf(buff, sizeof(buff), "[%2d] %-11s",
		     iseqdat->local_size - i, info);

	    rb_str_cat2(str, buff);
	}
	rb_str_cat2(str, "\n");
    }

    GC_CHECK();

    /* show each line */
    for (i = 0; i < size;) {
	i += ruby_iseq_disasm_insn(str, iseq, i, iseqdat, child);
    }

    for (i = 0; i < RARRAY_LEN(child); i++) {
	VALUE isv = rb_ary_entry(child, i);
	rb_str_concat(str, ruby_iseq_disasm(isv));
    }

    return str;
}

char *
ruby_node_name(int node)
{
    switch (node) {
    case NODE_METHOD:
	return "NODE_METHOD";
    case NODE_FBODY:
	return "NODE_FBODY";
    case NODE_CFUNC:
	return "NODE_CFUNC";
    case NODE_SCOPE:
	return "NODE_SCOPE";
    case NODE_BLOCK:
	return "NODE_BLOCK";
    case NODE_IF:
	return "NODE_IF";
    case NODE_CASE:
	return "NODE_CASE";
    case NODE_WHEN:
	return "NODE_WHEN";
    case NODE_OPT_N:
	return "NODE_OPT_N";
    case NODE_WHILE:
	return "NODE_WHILE";
    case NODE_UNTIL:
	return "NODE_UNTIL";
    case NODE_ITER:
	return "NODE_ITER";
    case NODE_FOR:
	return "NODE_FOR";
    case NODE_BREAK:
	return "NODE_BREAK";
    case NODE_NEXT:
	return "NODE_NEXT";
    case NODE_REDO:
	return "NODE_REDO";
    case NODE_RETRY:
	return "NODE_RETRY";
    case NODE_BEGIN:
	return "NODE_BEGIN";
    case NODE_RESCUE:
	return "NODE_RESCUE";
    case NODE_RESBODY:
	return "NODE_RESBODY";
    case NODE_ENSURE:
	return "NODE_ENSURE";
    case NODE_AND:
	return "NODE_AND";
    case NODE_OR:
	return "NODE_OR";
    case NODE_NOT:
	return "NODE_NOT";
    case NODE_MASGN:
	return "NODE_MASGN";
    case NODE_LASGN:
	return "NODE_LASGN";
    case NODE_DASGN:
	return "NODE_DASGN";
    case NODE_DASGN_CURR:
	return "NODE_DASGN_CURR";
    case NODE_GASGN:
	return "NODE_GASGN";
    case NODE_IASGN:
	return "NODE_IASGN";
    case NODE_IASGN2:
	return "NODE_IASGN2";
    case NODE_CDECL:
	return "NODE_CDECL";
    case NODE_CVASGN:
	return "NODE_CVASGN";
    case NODE_OP_ASGN1:
	return "NODE_OP_ASGN1";
    case NODE_OP_ASGN2:
	return "NODE_OP_ASGN2";
    case NODE_OP_ASGN_AND:
	return "NODE_OP_ASGN_AND";
    case NODE_OP_ASGN_OR:
	return "NODE_OP_ASGN_OR";
    case NODE_CALL:
	return "NODE_CALL";
    case NODE_FCALL:
	return "NODE_FCALL";
    case NODE_VCALL:
	return "NODE_VCALL";
    case NODE_SUPER:
	return "NODE_SUPER";
    case NODE_ZSUPER:
	return "NODE_ZSUPER";
    case NODE_ARRAY:
	return "NODE_ARRAY";
    case NODE_ZARRAY:
	return "NODE_ZARRAY";
    case NODE_VALUES:
	return "NODE_VALUES";
    case NODE_HASH:
	return "NODE_HASH";
    case NODE_RETURN:
	return "NODE_RETURN";
    case NODE_YIELD:
	return "NODE_YIELD";
    case NODE_LVAR:
	return "NODE_LVAR";
    case NODE_DVAR:
	return "NODE_DVAR";
    case NODE_GVAR:
	return "NODE_GVAR";
    case NODE_IVAR:
	return "NODE_IVAR";
    case NODE_CONST:
	return "NODE_CONST";
    case NODE_CVAR:
	return "NODE_CVAR";
    case NODE_NTH_REF:
	return "NODE_NTH_REF";
    case NODE_BACK_REF:
	return "NODE_BACK_REF";
    case NODE_MATCH:
	return "NODE_MATCH";
    case NODE_MATCH2:
	return "NODE_MATCH2";
    case NODE_MATCH3:
	return "NODE_MATCH3";
    case NODE_LIT:
	return "NODE_LIT";
    case NODE_STR:
	return "NODE_STR";
    case NODE_DSTR:
	return "NODE_DSTR";
    case NODE_XSTR:
	return "NODE_XSTR";
    case NODE_DXSTR:
	return "NODE_DXSTR";
    case NODE_EVSTR:
	return "NODE_EVSTR";
    case NODE_DREGX:
	return "NODE_DREGX";
    case NODE_DREGX_ONCE:
	return "NODE_DREGX_ONCE";
    case NODE_ARGS:
	return "NODE_ARGS";
    case NODE_POSTARG:
	return "NODE_POSTARG";
    case NODE_ARGSCAT:
	return "NODE_ARGSCAT";
    case NODE_ARGSPUSH:
	return "NODE_ARGSPUSH";
    case NODE_SPLAT:
	return "NODE_SPLAT";
    case NODE_TO_ARY:
	return "NODE_TO_ARY";
    case NODE_BLOCK_ARG:
	return "NODE_BLOCK_ARG";
    case NODE_BLOCK_PASS:
	return "NODE_BLOCK_PASS";
    case NODE_DEFN:
	return "NODE_DEFN";
    case NODE_DEFS:
	return "NODE_DEFS";
    case NODE_ALIAS:
	return "NODE_ALIAS";
    case NODE_VALIAS:
	return "NODE_VALIAS";
    case NODE_UNDEF:
	return "NODE_UNDEF";
    case NODE_CLASS:
	return "NODE_CLASS";
    case NODE_MODULE:
	return "NODE_MODULE";
    case NODE_SCLASS:
	return "NODE_SCLASS";
    case NODE_COLON2:
	return "NODE_COLON2";
    case NODE_COLON3:
	return "NODE_COLON3";
    case NODE_CREF:
	return "NODE_CREF";
    case NODE_DOT2:
	return "NODE_DOT2";
    case NODE_DOT3:
	return "NODE_DOT3";
    case NODE_FLIP2:
	return "NODE_FLIP2";
    case NODE_FLIP3:
	return "NODE_FLIP3";
    case NODE_ATTRSET:
	return "NODE_ATTRSET";
    case NODE_SELF:
	return "NODE_SELF";
    case NODE_NIL:
	return "NODE_NIL";
    case NODE_TRUE:
	return "NODE_TRUE";
    case NODE_FALSE:
	return "NODE_FALSE";
    case NODE_ERRINFO:
	return "NODE_ERRINFO";
    case NODE_DEFINED:
	return "NODE_DEFINED";
    case NODE_POSTEXE:
	return "NODE_POSTEXE";
    case NODE_ALLOCA:
	return "NODE_ALLOCA";
    case NODE_BMETHOD:
	return "NODE_BMETHOD";
    case NODE_MEMO:
	return "NODE_MEMO";
    case NODE_IFUNC:
	return "NODE_IFUNC";
    case NODE_DSYM:
	return "NODE_DSYM";
    case NODE_ATTRASGN:
	return "NODE_ATTRASGN";
    case NODE_PRELUDE:
	return "NODE_PRELUDE";
    case NODE_LAMBDA:
	return "NODE_LAMBDA";
    case NODE_OPTBLOCK:
	return "NODE_OPTBLOCK";
    case NODE_LAST:
	return "NODE_LAST";
    default:
	rb_bug("unknown node (%d)", node);
	return 0;
    }
}

int
debug_node(NODE *node)
{
    printf("node type: %d\n", nd_type(node));
    printf("node name: %s\n", ruby_node_name(nd_type(node)));
    printf("node filename: %s\n", node->nd_file);
    return 0;
}

#define DECL_SYMBOL(name) \
  static VALUE sym_##name

#define INIT_SYMBOL(name) \
  sym_##name = ID2SYM(rb_intern(#name))

static VALUE
register_label(struct st_table *table, int idx)
{
    VALUE sym;
    char buff[0x20];

    snprintf(buff, 0x20, "label_%u", idx);
    sym = ID2SYM(rb_intern(buff));
    st_insert(table, idx, sym);
    return sym;
}

static VALUE
exception_type2symbol(VALUE type)
{
    ID id;
    switch(type) {
      case CATCH_TYPE_RESCUE: id = rb_intern("rescue"); break;
      case CATCH_TYPE_ENSURE: id = rb_intern("ensure"); break;
      case CATCH_TYPE_RETRY:  id = rb_intern("retry");  break;
      case CATCH_TYPE_BREAK:  id = rb_intern("break");  break;
      case CATCH_TYPE_REDO:   id = rb_intern("redo");   break;
      case CATCH_TYPE_NEXT:   id = rb_intern("next");   break;
      default:
	rb_bug("...");
    }
    return ID2SYM(id);
}

static int
cdhash_each(VALUE key, VALUE value, VALUE ary)
{
    rb_ary_push(ary, key);
    rb_ary_push(ary, value);
    return ST_CONTINUE;
}

VALUE
iseq_data_to_ary(rb_iseq_t *iseq)
{
    int i, pos, opt = 0;
    VALUE *seq;

    VALUE val = rb_ary_new();
    VALUE type; /* Symbol */
    VALUE locals = rb_ary_new();
    VALUE args = rb_ary_new();
    VALUE body = rb_ary_new(); /* [[:insn1, ...], ...] */
    VALUE nbody;
    VALUE line = rb_ary_new();
    VALUE exception = rb_ary_new(); /* [[....]] */
    
    static VALUE insn_syms[YARV_MAX_INSTRUCTION_SIZE];
    struct st_table *labels_table = st_init_numtable();
    
    DECL_SYMBOL(toplevel);
    DECL_SYMBOL(method);
    DECL_SYMBOL(block);
    DECL_SYMBOL(class);
    DECL_SYMBOL(rescue);
    DECL_SYMBOL(ensure);
    DECL_SYMBOL(eval);

    if (sym_toplevel == 0) {
	int i;
	for (i=0; i<YARV_MAX_INSTRUCTION_SIZE; i++) {
	    insn_syms[i] = ID2SYM(rb_intern(insn_name(i)));
	}
	INIT_SYMBOL(toplevel);
	INIT_SYMBOL(method);
	INIT_SYMBOL(block);
	INIT_SYMBOL(class);
	INIT_SYMBOL(rescue);
	INIT_SYMBOL(ensure);
	INIT_SYMBOL(eval);
    }
    
    /* type */
    switch(iseq->type) {
      case ISEQ_TYPE_TOP:    type = sym_toplevel; break;
      case ISEQ_TYPE_METHOD: type = sym_method;   break;
      case ISEQ_TYPE_BLOCK:  type = sym_block;    break;
      case ISEQ_TYPE_CLASS:  type = sym_class;    break;
      case ISEQ_TYPE_RESCUE: type = sym_rescue;   break;
      case ISEQ_TYPE_ENSURE: type = sym_ensure;   break;
      case ISEQ_TYPE_EVAL:   type = sym_eval;     break;
      default: rb_bug("unsupported iseq type");
    };

    /* locals */
    for (i=0; i<iseq->local_table_size; i++) {
	ID lid = iseq->local_table[i];
	if (lid) {
	    rb_ary_push(locals, ID2SYM(lid));
	}
	else {
	    rb_ary_push(locals, ID2SYM(rb_intern("#arg_rest")));
	}
    }

    /* args */
    {
	/*
	 * [argc,                 # argc
	 *  [label1, label2, ...] # opts
	 *  rest_iex,
	 *  block_idx,
         * ]
	 * or
	 *  argc (Fixnum) # arg_simple
	 */
	VALUE arg_opt_labels = rb_ary_new();
	int j;

	for (j=0; j<iseq->arg_opts; j++) {
	    rb_ary_push(arg_opt_labels,
			register_label(labels_table, iseq->arg_opt_tbl[j]));
	}

	/* commit */
	if (iseq->arg_simple) {
	    args = INT2FIX(iseq->argc);
	}
	else {
	    rb_ary_push(args, INT2FIX(iseq->argc));
	    rb_ary_push(args, INT2FIX(iseq->arg_opts));
	    rb_ary_push(args, arg_opt_labels);
	    rb_ary_push(args, INT2FIX(iseq->arg_rest));
	    rb_ary_push(args, INT2FIX(iseq->arg_block));
	}
    }

    /* body */
    for (seq = iseq->iseq; seq < iseq->iseq + iseq->size; ) {
	VALUE ary = rb_ary_new();
	VALUE insn = *seq++;
	int j, len = insn_len(insn);
	VALUE *nseq = seq + len - 1;
	
	rb_ary_push(ary, insn_syms[insn]);
	for (j=0; j<len-1; j++, seq++) {
	    switch (insn_op_type(insn, j)) {
	      case TS_OFFSET: {
		  unsigned int idx = nseq - iseq->iseq + *seq;
		  rb_ary_push(ary, register_label(labels_table, idx));
		  break;
	      }
	      case TS_LINDEX:
	      case TS_DINDEX:
	      case TS_NUM:
		rb_ary_push(ary, INT2FIX(*seq));
		break;
	      case TS_VALUE:
		rb_ary_push(ary, *seq);
		break;
	      case TS_ISEQ:
		{
		    rb_iseq_t *iseq = (rb_iseq_t *)*seq;
		    if (iseq) {
			VALUE val = iseq_data_to_ary(iseq);
			rb_ary_push(ary, val);
		    }
		    else {
			rb_ary_push(ary, Qnil);
		    }
		}
		break;
	      case TS_GENTRY:
		{
		    struct global_entry *entry = (struct global_entry *)*seq;
		    rb_ary_push(ary, ID2SYM(entry->id));
		}
		break;
	      case TS_IC:
		rb_ary_push(ary, Qnil);
		break;
	      case TS_ID:
		rb_ary_push(ary, ID2SYM(*seq));
		break;
	      case TS_CDHASH:
		{
		    VALUE hash = *seq;
		    VALUE val = rb_ary_new();
		    int i;
		    
		    rb_hash_foreach(hash, cdhash_each, val);

		    for (i=0; i<RARRAY_LEN(val); i+=2) {
			VALUE pos = FIX2INT(rb_ary_entry(val, i+1));
			unsigned int idx = nseq - iseq->iseq + pos;

			rb_ary_store(val, i+1,
				     register_label(labels_table, idx));
		    }
		    rb_ary_push(ary, val);
		}
		break;
	      default:
		rb_bug("unknown operand: %c", insn_op_type(insn, j));
	    }
	}
	rb_ary_push(body, ary);
    }

    nbody = body;

    /* exception */
    for (i=0; i<iseq->catch_table_size; i++) {
	VALUE ary = rb_ary_new();
	struct catch_table_entry *entry = &iseq->catch_table[i];
	rb_ary_push(ary, exception_type2symbol(entry->type));
	if (entry->iseq) {
	    rb_iseq_t *eiseq;
	    GetISeqPtr(entry->iseq, eiseq);
	    rb_ary_push(ary, iseq_data_to_ary(eiseq));
	}
	else {
	    rb_ary_push(ary, Qnil);
	}
	rb_ary_push(ary, register_label(labels_table, entry->start));
	rb_ary_push(ary, register_label(labels_table, entry->end));
	rb_ary_push(ary, register_label(labels_table, entry->cont));
	rb_ary_push(ary, INT2FIX(entry->sp));
	rb_ary_push(exception, ary);
    }

    /* make body with labels */
    body = rb_ary_new();

    for (i=0, pos=0; i<RARRAY_LEN(nbody); i++) {
	VALUE ary = RARRAY_PTR(nbody)[i];
	VALUE label;

	if (st_lookup(labels_table, pos, &label)) {
	    rb_ary_push(body, label);
	}

	rb_ary_push(body, ary);
	pos += RARRAY_LEN(ary);
    }

    st_free_table(labels_table);

    /* build array */
    
    /* [magic, major_version, minor_version, format_type, misc,
     *  name, filename, line,
     *  type, args, vars, exception_table, body]
     */
    rb_ary_push(val, rb_str_new2("YARVInstructionSimpledataFormat"));
    rb_ary_push(val, INT2FIX(1));
    rb_ary_push(val, INT2FIX(1));
    rb_ary_push(val, INT2FIX(1));
    rb_ary_push(val, Qnil);
    rb_ary_push(val, iseq->name);
    rb_ary_push(val, iseq->filename);
    rb_ary_push(val, line);
    rb_ary_push(val, type);
    rb_ary_push(val, locals);
    rb_ary_push(val, args);
    rb_ary_push(val, exception);
    rb_ary_push(val, body);
    return val;
}

struct st_table *
insn_make_insn_table(void)
{
    struct st_table *table;
    int i;
    table = st_init_numtable();

    for (i=0; i<YARV_MAX_INSTRUCTION_SIZE; i++) {
	st_insert(table, ID2SYM(rb_intern(insn_name(i))), i);
    }

    return table;
}


void
Init_ISeq(void)
{
    /* declare YARVCore::InstructionSequence */
    rb_cISeq = rb_define_class_under(rb_cVM, "InstructionSequence", rb_cObject);
    rb_define_alloc_func(rb_cISeq, iseq_alloc);
    rb_define_method(rb_cISeq, "inspect", iseq_inspect, 0);
    rb_define_method(rb_cISeq, "disasm", ruby_iseq_disasm, 0);
    rb_define_method(rb_cISeq, "to_a", iseq_to_a, 0);
    rb_define_method(rb_cISeq, "eval", iseq_eval, 0);

    rb_define_singleton_method(rb_cISeq, "load", iseq_s_load, -1);
    rb_define_singleton_method(rb_cISeq, "compile", iseq_s_compile, -1);
    rb_define_singleton_method(rb_cISeq, "new", iseq_s_compile, -1);
    rb_define_singleton_method(rb_cISeq, "compile_file", iseq_s_compile_file, -1);
    rb_define_singleton_method(rb_cISeq, "compile_option=",
			       iseq_s_compile_option_set, 1);
}

