/**********************************************************************

  yarvcore.h - 

  $Author: ko1 $
  $Date: 2007-02-26 01:29:26 +0900 (月, 26 2 2007) $
  created at: 04/01/01 01:17:22 JST

  Copyright (C) 2004-2006 Koichi Sasada

**********************************************************************/

#include "ruby.h"
#include "node.h"

#include "yarvcore.h"
#include "gc.h"

VALUE rb_cVM;
VALUE rb_cThread;

VALUE symIFUNC;
VALUE symCFUNC;

ID idPLUS;
ID idMINUS;
ID idMULT;
ID idDIV;
ID idMOD;
ID idLT;
ID idLTLT;
ID idLE;
ID idEq;
ID idEqq;
ID idBackquote;
ID idEqTilde;
ID idThrowState;
ID idAREF;
ID idASET;
ID idIntern;
ID idMethodMissing;
ID idLength;
ID idLambda;
ID idGets;
ID idSucc;
ID idEach;
ID idRangeEachLT;
ID idRangeEachLE;
ID idArrayEach;
ID idTimes;
ID idEnd;
ID idBitblt;
ID idAnswer;
ID idSvarPlaceholder;
ID idSend;
ID id__send__;
ID id__send;
ID idFuncall;
ID id__send_bang;

/* from Ruby 1.9 eval.c */
#ifdef HAVE_STDARG_PROTOTYPES
#include <stdarg.h>
#define va_init_list(a,b) va_start(a,b)
#else
#include <varargs.h>
#define va_init_list(a,b) va_start(a)
#endif

/************/
/* YARVCore */
/************/

rb_thread_t *yarvCurrentThread = 0;
rb_vm_t *theYarvVM = 0;
static VALUE yarvVMArray = Qnil;

RUBY_EXTERN int ruby_nerrs;

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
yarvcore_eval_iseq(VALUE iseq)
{
    return rb_thread_eval(GET_THREAD(), iseq);
}

static VALUE
th_compile_from_node(rb_thread_t *th, NODE * node, VALUE file)
{
    VALUE iseq;
    if (th->base_block) {
	iseq = rb_iseq_new(node,
			     th->base_block->iseq->name,
			     file,
			     th->base_block->iseq->self,
			     ISEQ_TYPE_EVAL);
    }
    else {
	iseq = rb_iseq_new(node, rb_str_new2("<main>"), file,
			     Qfalse, ISEQ_TYPE_TOP);
    }
    return iseq;
}

VALUE
th_compile(rb_thread_t *th, VALUE str, VALUE file, VALUE line)
{
    NODE *node = (NODE *) compile_string(str, file, line);
    return th_compile_from_node(th, (NODE *) node, file);
}

VALUE
yarvcore_eval_parsed(NODE *node, VALUE file)
{
    VALUE iseq = th_compile_from_node(GET_THREAD(), node, file);
    return yarvcore_eval_iseq(iseq);
}

VALUE
yarvcore_eval(VALUE self, VALUE str, VALUE file, VALUE line)
{
    NODE *node;
    node = compile_string(str, file, line);
    return yarvcore_eval_parsed(node, file);
}

/******/
/* VM */
/******/

void native_thread_cleanup(void *);

static void
vm_free(void *ptr)
{
    FREE_REPORT_ENTER("vm");
    if (ptr) {
	rb_vm_t *vmobj = ptr;

	st_free_table(vmobj->living_threads);
	/* TODO: MultiVM Instance */
	/* VM object should not be cleaned by GC */
	/* ruby_xfree(ptr); */
	/* theYarvVM = 0; */
    }
    FREE_REPORT_LEAVE("vm");
}

static int
vm_mark_each_thread_func(st_data_t key, st_data_t value, st_data_t dummy)
{
    VALUE thval = (VALUE)key;
    rb_gc_mark(thval);
    return ST_CONTINUE;
}

static void
vm_mark(void *ptr)
{
    MARK_REPORT_ENTER("vm");
    GC_INFO("-------------------------------------------------\n");
    if (ptr) {
	rb_vm_t *vm = ptr;
	if (vm->living_threads) {
	    st_foreach(vm->living_threads, vm_mark_each_thread_func, 0);
	}
	MARK_UNLESS_NULL(vm->thgroup_default);
	MARK_UNLESS_NULL(vm->mark_object_ary);
	MARK_UNLESS_NULL(vm->last_status);
	MARK_UNLESS_NULL(vm->loaded_features);
    }

    MARK_REPORT_LEAVE("vm");
}

static VALUE
vm_alloc(VALUE klass)
{
    VALUE volatile obj;
    rb_vm_t *vm;
    obj = Data_Make_Struct(klass, rb_vm_t, vm_mark, vm_free, vm);

    vm->self = obj;
    vm->mark_object_ary = rb_ary_new();
    return obj;
}

static void
vm_init2(rb_vm_t *vm)
{
    MEMZERO(vm, rb_vm_t, 1);
}

/**********/
/* Thread */
/**********/

static void
thread_free(void *ptr)
{
    rb_thread_t *th;
    FREE_REPORT_ENTER("thread");

    if (ptr) {
	th = ptr;
	FREE_UNLESS_NULL(th->stack);
	FREE_UNLESS_NULL(th->top_local_tbl);

	if (th->local_storage) {
	    st_free_table(th->local_storage);
	}

#if USE_VALUE_CACHE
	{
	    VALUE *ptr = th->value_cache_ptr;
	    while (*ptr) {
		VALUE v = *ptr;
		RBASIC(v)->flags = 0;
		RBASIC(v)->klass = 0;
		ptr++;
	    }
	}
#endif

	if (th->vm->main_thread == th) {
	    GC_INFO("main thread\n");
	}
	else {
	    ruby_xfree(ptr);
	}
    }
    FREE_REPORT_LEAVE("thread");
}

void yarv_machine_stack_mark(rb_thread_t *th);

static void
thread_mark(void *ptr)
{
    rb_thread_t *th = NULL;
    MARK_REPORT_ENTER("thread");
    if (ptr) {
	th = ptr;
	if (th->stack) {
	    VALUE *p = th->stack;
	    VALUE *sp = th->cfp->sp;
	    rb_control_frame_t *cfp = th->cfp;
	    rb_control_frame_t *limit_cfp =
		(void *)(th->stack + th->stack_size);

	    while (p < sp) {
		rb_gc_mark(*p++);
	    }
	    while (cfp != limit_cfp) {
		rb_gc_mark(cfp->proc);
		cfp = RUBY_VM_PREVIOUS_CONTROL_FRAME(cfp);
	    }
	}

	/* mark ruby objects */
	MARK_UNLESS_NULL(th->first_proc);
	MARK_UNLESS_NULL(th->first_args);
	
	MARK_UNLESS_NULL(th->thgroup);
	MARK_UNLESS_NULL(th->value);
	MARK_UNLESS_NULL(th->errinfo);
	MARK_UNLESS_NULL(th->local_svar);
	MARK_UNLESS_NULL(th->top_self);
	MARK_UNLESS_NULL(th->top_wrapper);

	rb_mark_tbl(th->local_storage);

	if (GET_THREAD() != th &&
	    th->machine_stack_start && th->machine_stack_end) {
	    yarv_machine_stack_mark(th);
	    rb_gc_mark_locations((VALUE *)&th->machine_regs,
				 (VALUE *)(&th->machine_regs) +
				 sizeof(th->machine_regs) / sizeof(VALUE));
	}
    }

    MARK_UNLESS_NULL(th->stat_insn_usage);
    MARK_REPORT_LEAVE("thread");
}

static VALUE
thread_alloc(VALUE klass)
{
    VALUE volatile obj;
    rb_thread_t *th;
    obj = Data_Make_Struct(klass, rb_thread_t,
			   thread_mark, thread_free, th);
    return obj;
}

static void
th_init2(rb_thread_t *th)
{
    MEMZERO(th, rb_thread_t, 1);

    /* allocate thread stack */
    th->stack = ALLOC_N(VALUE, RUBY_VM_THREAD_STACK_SIZE);

    th->stack_size = RUBY_VM_THREAD_STACK_SIZE;
    th->cfp = (void *)(th->stack + th->stack_size);
    th->cfp--;

    th->cfp->pc = 0;
    th->cfp->sp = th->stack;
    th->cfp->bp = 0;
    th->cfp->lfp = th->stack;
    th->cfp->dfp = th->stack;
    th->cfp->self = Qnil;
    th->cfp->magic = 0;
    th->cfp->iseq = 0;
    th->cfp->proc = 0;
    th->cfp->block_iseq = 0;

    th->status = THREAD_RUNNABLE;
    th->errinfo = Qnil;

#if USE_VALUE_CACHE
    th->value_cache_ptr = &th->value_cache[0];
#endif
}

static void
th_init(rb_thread_t *th)
{
    th_init2(th);
}

extern VALUE ruby_top_self;

static VALUE
thread_init(VALUE self)
{
    rb_thread_t *th;
    rb_vm_t *vm = GET_THREAD()->vm;
    GetThreadPtr(self, th);

    th_init(th);
    th->self = self;
    th->vm = vm;

    th->top_wrapper = 0;
    th->top_self = ruby_top_self;
    return self;
}

VALUE
rb_thread_alloc(VALUE klass)
{
    VALUE self = thread_alloc(klass);
    thread_init(self);
    return self;
}

/********************************************************************/

VALUE insns_name_array(void);
extern VALUE *rb_gc_stack_start;

static VALUE
sdr(void)
{
    yarv_bug();
    return Qnil;
}

static VALUE
nsdr(void)
{
    VALUE ary = rb_ary_new();
#if HAVE_BACKTRACE
#include <execinfo.h>
#define MAX_NATIVE_TRACE 1024
    static void *trace[MAX_NATIVE_TRACE];
    int n = backtrace(trace, MAX_NATIVE_TRACE);
    char **syms = backtrace_symbols(trace, n);
    int i;

    if (syms == 0) {
	rb_memerror();
    }

    for (i=0; i<n; i++) {
	rb_ary_push(ary, rb_str_new2(syms[i]));
    }
    free(syms);
#endif
    return ary;
}

static char *yarv_options = ""
#if   OPT_DIRECT_THREADED_CODE
    "[direct threaded code] "
#elif OPT_TOKEN_THREADED_CODE
    "[token threaded code] "
#elif OPT_CALL_THREADED_CODE
    "[call threaded code] "
#endif

#if OPT_BASIC_OPERATIONS
    "[optimize basic operation] "
#endif
#if OPT_STACK_CACHING
    "[stack caching] "
#endif
#if OPT_OPERANDS_UNIFICATION
    "[operands unification] "
#endif
#if OPT_INSTRUCTIONS_UNIFICATION
    "[instructions unification] "
#endif
#if OPT_INLINE_METHOD_CACHE
    "[inline method cache] "
#endif
#if OPT_BLOCKINLINING
    "[block inlining] "
#endif
    ;

void yarv_init_redefined_flag(void);

void
Init_VM(void)
{
    /* ::VM */
    rb_cVM = rb_define_class("VM", rb_cObject);
    rb_undef_alloc_func(rb_cVM);

    /* Env */
    rb_cEnv = rb_define_class_under(rb_cVM, "Env", rb_cObject);
    rb_undef_alloc_func(rb_cEnv);

    /* ::Thread */
    rb_cThread = rb_define_class("Thread", rb_cObject);
    rb_undef_alloc_func(rb_cThread);
    rb_define_method(rb_cThread, "initialize", thread_init, 0);

    /* ::VM::USAGE_ANALISYS_* */
    rb_define_const(rb_cVM, "USAGE_ANALISYS_INSN", rb_hash_new());
    rb_define_const(rb_cVM, "USAGE_ANALISYS_REGS", rb_hash_new());
    rb_define_const(rb_cVM, "USAGE_ANALISYS_INSN_BIGRAM", rb_hash_new());
    rb_define_const(rb_cVM, "OPTS", rb_str_new2(yarv_options));

    /* ::VM::InsnNameArray */
    rb_define_const(rb_cVM, "InsnNameArray", insns_name_array());

    /* ::VM::eval() */
    rb_define_singleton_method(rb_cVM, "eval", yarvcore_eval, 3);

    /* debug functions ::VM::SDR(), ::VM::NSDR() */
    rb_define_singleton_method(rb_cVM, "SDR", sdr, 0);
    rb_define_singleton_method(rb_cVM, "NSDR", nsdr, 0);

    /* Symbols */
    symIFUNC = ID2SYM(rb_intern("<IFUNC>"));
    symCFUNC = ID2SYM(rb_intern("<CFUNC>"));

    /* IDs */
    idPLUS = rb_intern("+");
    idMINUS = rb_intern("-");
    idMULT = rb_intern("*");
    idDIV = rb_intern("/");
    idMOD = rb_intern("%");
    idLT = rb_intern("<");
    idLTLT = rb_intern("<<");
    idLE = rb_intern("<=");
    idEq = rb_intern("==");
    idEqq = rb_intern("===");
    idBackquote = rb_intern("`");
    idEqTilde = rb_intern("=~");

    idAREF = rb_intern("[]");
    idASET = rb_intern("[]=");

    idEach = rb_intern("each");
    idTimes = rb_intern("times");
    idLength = rb_intern("length");
    idLambda = rb_intern("lambda");
    idIntern = rb_intern("intern");
    idGets = rb_intern("gets");
    idSucc = rb_intern("succ");
    idEnd = rb_intern("end");
    idRangeEachLT = rb_intern("Range#each#LT");
    idRangeEachLE = rb_intern("Range#each#LE");
    idArrayEach = rb_intern("Array#each");
    idMethodMissing = rb_intern("method_missing");

    idThrowState = rb_intern("#__ThrowState__");

    idBitblt = rb_intern("bitblt");
    idAnswer = rb_intern("the_answer_to_life_the_universe_and_everything");
    idSvarPlaceholder = rb_intern("#svar");

    idSend = rb_intern("send");
    id__send__ = rb_intern("__send__");
    id__send = rb_intern("__send");
    idFuncall = rb_intern("funcall");
    id__send_bang = rb_intern("__send!");

    /* VM bootstrap: phase 2 */
    {
	/* create vm object */
	VALUE vmval = vm_alloc(rb_cVM);
	VALUE thval;
	rb_vm_t *vm;
	rb_thread_t *th;

	vm = theYarvVM;

	xfree(RDATA(vmval)->data);
	RDATA(vmval)->data = vm;
	vm->self = vmval;

	yarvVMArray = rb_ary_new();
	rb_register_mark_object(yarvVMArray);
	rb_ary_push(yarvVMArray, vm->self);

	/* create main thread */
	thval = rb_thread_alloc(rb_cThread);
	GetThreadPtr(thval, th);

	vm->main_thread = th;
	vm->running_thread = th;
	GET_THREAD()->vm = vm;
	thread_free(GET_THREAD());
	th->vm = vm;
	rb_thread_set_current(th);

	th->machine_stack_start = rb_gc_stack_start;
	vm->living_threads = st_init_numtable();
	st_insert(vm->living_threads, th->self, (st_data_t) th->thread_id);
    }
    yarv_init_redefined_flag();
}

void
Init_yarv(void)
{
    /* VM bootstrap: phase 1 */
    rb_vm_t *vm = ALLOC(rb_vm_t);
    rb_thread_t *th = ALLOC(rb_thread_t);

    vm_init2(vm);
    theYarvVM = vm;

    th_init2(th);
    th->vm = vm;
    th->machine_stack_start = rb_gc_stack_start;
    rb_thread_set_current_raw(th);
}

