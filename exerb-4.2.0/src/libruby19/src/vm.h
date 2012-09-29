/**********************************************************************

  vm.h -

  $Author: ko1 $
  $Date: 2007-02-15 03:08:10 +0900 (木, 15 2 2007) $
  created at: 04/01/01 16:56:59 JST

  Copyright (C) 2004-2006 Koichi Sasada

**********************************************************************/

#ifndef _VM_H_INCLUDED_
#define _VM_H_INCLUDED_

#include "version.h"

#if YARVDEBUG > VMDEBUG
#undef  VMDEBUG
#define VMDEBUG YARVDEBUG
#endif

typedef long OFFSET;

/**
 * VM Debug Level
 *
 * debug level:
 *  0: no debug output
 *  1: show instruction name
 *  2:
 *  3: show stack status
 *  4: show register
 *  5:
 * 10: gc check
 */

#if 0
#undef  VMDEBUG
#define VMDEBUG 3
#endif

#ifdef  COLLECT_USAGE_ANALYSIS
#define USAGE_ANALYSIS_INSN(insn)           vm_analysis_insn(insn)
#define USAGE_ANALYSIS_OPERAND(insn, n, op) vm_analysis_operand(insn, n, (VALUE)op)
#define USAGE_ANALYSIS_REGISTER(reg, s)     vm_analysis_register(reg, s)
#else
#define USAGE_ANALYSIS_INSN(insn)	/* none */
#define USAGE_ANALYSIS_OPERAND(insn, n, op)	/* none */
#define USAGE_ANALYSIS_REGISTER(reg, s)	/* none */
#endif

#ifdef __GCC__
/* TODO: machine dependent prefetch instruction */
#define PREFETCH(pc)
#else
#define PREFETCH(pc)
#endif

#if VMDEBUG > 0
#define debugs printf
#define DEBUG_ENTER_INSN(insn) \
  debug_print_pre(th, GET_CFP());

#if OPT_STACK_CACHING
#define SC_REGS() , reg_a, reg_b
#else
#define SC_REGS()
#endif

#define DEBUG_END_INSN() \
  debug_print_post(th, GET_CFP() SC_REGS());

#else

#define debugs
#define DEBUG_ENTER_INSN(insn)
#define DEBUG_END_INSN()
#endif

#define throwdebug if(0)printf
/* #define throwdebug printf */

#define SDR2(cfp) vm_stack_dump_raw(GET_THREAD(), (cfp))


/************************************************/
#if   DISPATCH_XXX
error !
/************************************************/
#elif OPT_CALL_THREADED_CODE

#if __GCC__
#define FASTCALL __attribute__ ((fastcall))
#else
#define FASTCALL
#endif


#define LABEL(x)  insn_func_##x
#define ELABEL(x)
#define LABEL_PTR(x) &LABEL(x)

typedef rb_control_frame_t *
    (*insn_func_type) (rb_thread_t *, rb_control_frame_t *)FASTCALL;

#define INSN_ENTRY(insn) \
  rb_control_frame_t * \
    LABEL(insn)(rb_thread_t *th, rb_control_frame_t *reg_cfp) FASTCALL {

#define END_INSN(insn) return reg_cfp;}

#define NEXT_INSN() return reg_cfp;

/************************************************/
#elif OPT_TOKEN_THREADED_CODE || OPT_DIRECT_THREADED_CODE
/* threaded code with gcc */

#define LABEL(x)  INSN_LABEL_##x
#define ELABEL(x) INSN_ELABEL_##x
#define LABEL_PTR(x) &&LABEL(x)

#define INSN_ENTRY_SIG(insn) \
  asm volatile (  "; #**************************************************\n" \
                "\t; #[start] " # insn "\n") \


#define INSN_DISPATCH_SIG(insn) \
  asm volatile (  "; #[end  ] " # insn "\n"\
                "\t; #==================================================\n") \

#define INSN_ENTRY(insn) \
  LABEL(insn): \
  INSN_ENTRY_SIG(insn); \

/* dispather */
#if __GNUC__ && (__i386__ || __x86_64__) && __GNUC__ == 3
#define DISPATCH_ARCH_DEPEND_WAY(addr) \
  asm volatile("jmp *%0;\t# -- inseted by vm.h\t[length = 2]" : : "r" (addr))

#else
#define DISPATCH_ARCH_DEPEND_WAY(addr) \
				/* do nothing */

#endif


/**********************************/
#if OPT_DIRECT_THREADED_CODE

/* for GCC 3.4.x */
#define TC_DISPATCH(insn) \
  DISPATCH_ARCH_DEPEND_WAY(GET_CURRENT_INSN()); \
  INSN_DISPATCH_SIG(insn); \
  goto *GET_CURRENT_INSN(); \
  ;

#else
/* token threade code */

#define TC_DISPATCH(insn)  \
  DISPATCH_ARCH_DEPEND_WAY(insns_address_table[GET_CURRENT_INSN()]); \
  INSN_DISPATCH_SIG(insn); \
  goto *insns_address_table[GET_CURRENT_INSN()]; \
  rb_bug("tc error");


#endif /* DISPATCH_DIRECT_THREADED_CODE */

#define END_INSN(insn)      \
  GC_CHECK();               \
  DEBUG_END_INSN();         \
  TC_DISPATCH(insn);        \

#define INSN_DISPATCH()     \
  TC_DISPATCH(__START__)    \
  {

#define END_INSNS_DISPATCH()    \
      rb_bug("unknown insn: %ld", GET_CURRENT_INSN());   \
  }   /* end of while loop */   \

#define NEXT_INSN() TC_DISPATCH(__NEXT_INSN__)

/************************************************/
#else /* no threaded code */
/* most common method */

#define INSN_ENTRY(insn) \
case BIN(insn):

#define END_INSN(insn)                        \
  GC_CHECK();                                 \
  DEBUG_END_INSN();                           \
  break;


#define INSN_DISPATCH()         \
  while(1){                     \
    switch(GET_CURRENT_INSN()){

#define END_INSNS_DISPATCH()    \
default:                        \
  SDR(); \
      rb_bug("unknown insn: %ld", GET_CURRENT_INSN());   \
    } /* end of switch */       \
  }   /* end of while loop */   \

#define NEXT_INSN() goto first

#endif


/************************************************/
/************************************************/

/*
  env{
    env[0] // special (block or prev env)
    env[1] // orphan
    env[2] // in heap
    env[3] // env object
    env[4] // prev env val
  };
 */

#define ORPHAN_ENV_P(env)   ((env)[1] == Qundef)
#define ENV_IN_HEAP_P(env)  ((env)[2] == Qundef)
#define ENV_VAL(env)        ((env)[3])

#define FRAME_MAGIC_METHOD 0xfaffff11
#define FRAME_MAGIC_BLOCK  0xfaffff21
#define FRAME_MAGIC_CLASS  0xfaffff31
#define FRAME_MAGIC_TOP    0xfaffff41
#define FRAME_MAGIC_FINISH 0xfaffff51
#define FRAME_MAGIC_CFUNC  0xfaffff61
#define FRAME_MAGIC_PROC   0xfaffff71
#define FRAME_MAGIC_IFUNC  0xfaffff81
#define FRAME_MAGIC_EVAL   0xfaffff91
#define FRAME_MAGIC_LAMBDA 0xfaffffa1

#define CHECK_FRAME_MAGIC(magic)                   \
{                                                  \
  if((magic & 0xffffff00) != 0xfaffff00){          \
    rb_bug("YARV Stack frame error: %08x", magic); \
  }                                                \
}

/*
 * Excception
 */

#define NEW_THROW_OBJECT(val, pt, st) NEW_NODE(NODE_LIT, (val), (pt), (st))
#define GET_THROWOBJ_VAL(obj)         ((VALUE)RNODE((obj))->u1.value)
#define GET_THROWOBJ_CATCH_POINT(obj) ((VALUE*)RNODE((obj))->u2.value)
#define GET_THROWOBJ_STATE(obj)       ((int)RNODE((obj))->u3.value)

#define SET_THROWOBJ_CATCH_POINT(obj, val) \
  (RNODE((obj))->u2.value = (val))
#define SET_THROWOBJ_STATE(obj, val) \
  (RNODE((obj))->u3.value = (val))

#define SCREG(r) (reg_##r)

/* VM state version */

#define GET_VM_STATE_VERSION() (vm_global_state_version)
#define INC_VM_STATE_VERSION() \
  (vm_global_state_version = (vm_global_state_version+1) & 0x8fffffff)

#define BOP_PLUS     0x01
#define BOP_MINUS    0x02
#define BOP_MULT     0x04
#define BOP_DIV      0x08
#define BOP_MOD      0x10
#define BOP_EQ       0x20
#define BOP_LT       0x40
#define BOP_LE       0x80
#define BOP_LTLT    0x100
#define BOP_AREF    0x200
#define BOP_ASET    0x400
#define BOP_LENGTH  0x800
#define BOP_SUCC   0x1000

#endif /* _VM_H_INCLUDED_ */
