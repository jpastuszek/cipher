/* A Bison parser, made by GNU Bison 2.1.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     keyword_class = 258,
     keyword_module = 259,
     keyword_def = 260,
     keyword_undef = 261,
     keyword_begin = 262,
     keyword_rescue = 263,
     keyword_ensure = 264,
     keyword_end = 265,
     keyword_if = 266,
     keyword_unless = 267,
     keyword_then = 268,
     keyword_elsif = 269,
     keyword_else = 270,
     keyword_case = 271,
     keyword_when = 272,
     keyword_while = 273,
     keyword_until = 274,
     keyword_for = 275,
     keyword_break = 276,
     keyword_next = 277,
     keyword_redo = 278,
     keyword_retry = 279,
     keyword_in = 280,
     keyword_do = 281,
     keyword_do_cond = 282,
     keyword_do_block = 283,
     keyword_do_LAMBDA = 284,
     keyword_return = 285,
     keyword_yield = 286,
     keyword_super = 287,
     keyword_self = 288,
     keyword_nil = 289,
     keyword_true = 290,
     keyword_false = 291,
     keyword_and = 292,
     keyword_or = 293,
     keyword_not = 294,
     modifier_if = 295,
     modifier_unless = 296,
     modifier_while = 297,
     modifier_until = 298,
     modifier_rescue = 299,
     keyword_alias = 300,
     keyword_defined = 301,
     keyword_BEGIN = 302,
     keyword_END = 303,
     keyword__LINE__ = 304,
     keyword__FILE__ = 305,
     tIDENTIFIER = 306,
     tFID = 307,
     tGVAR = 308,
     tIVAR = 309,
     tCONSTANT = 310,
     tCVAR = 311,
     tLABEL = 312,
     tINTEGER = 313,
     tFLOAT = 314,
     tSTRING_CONTENT = 315,
     tCHAR = 316,
     tNTH_REF = 317,
     tBACK_REF = 318,
     tREGEXP_END = 319,
     tUPLUS = 320,
     tUMINUS = 321,
     tPOW = 322,
     tCMP = 323,
     tEQ = 324,
     tEQQ = 325,
     tNEQ = 326,
     tGEQ = 327,
     tLEQ = 328,
     tANDOP = 329,
     tOROP = 330,
     tMATCH = 331,
     tNMATCH = 332,
     tDOT2 = 333,
     tDOT3 = 334,
     tAREF = 335,
     tASET = 336,
     tLSHFT = 337,
     tRSHFT = 338,
     tCOLON2 = 339,
     tCOLON3 = 340,
     tOP_ASGN = 341,
     tASSOC = 342,
     tLPAREN = 343,
     tLPAREN_ARG = 344,
     tRPAREN = 345,
     tLBRACK = 346,
     tLBRACE = 347,
     tLBRACE_ARG = 348,
     tSTAR = 349,
     tAMPER = 350,
     tLAMBDA = 351,
     tSYMBEG = 352,
     tSTRING_BEG = 353,
     tXSTRING_BEG = 354,
     tREGEXP_BEG = 355,
     tWORDS_BEG = 356,
     tQWORDS_BEG = 357,
     tSTRING_DBEG = 358,
     tSTRING_DVAR = 359,
     tSTRING_END = 360,
     tLAMBEG = 361,
     tLOWEST = 362,
     tUMINUS_NUM = 363,
     tLAST_TOKEN = 364
   };
#endif
/* Tokens.  */
#define keyword_class 258
#define keyword_module 259
#define keyword_def 260
#define keyword_undef 261
#define keyword_begin 262
#define keyword_rescue 263
#define keyword_ensure 264
#define keyword_end 265
#define keyword_if 266
#define keyword_unless 267
#define keyword_then 268
#define keyword_elsif 269
#define keyword_else 270
#define keyword_case 271
#define keyword_when 272
#define keyword_while 273
#define keyword_until 274
#define keyword_for 275
#define keyword_break 276
#define keyword_next 277
#define keyword_redo 278
#define keyword_retry 279
#define keyword_in 280
#define keyword_do 281
#define keyword_do_cond 282
#define keyword_do_block 283
#define keyword_do_LAMBDA 284
#define keyword_return 285
#define keyword_yield 286
#define keyword_super 287
#define keyword_self 288
#define keyword_nil 289
#define keyword_true 290
#define keyword_false 291
#define keyword_and 292
#define keyword_or 293
#define keyword_not 294
#define modifier_if 295
#define modifier_unless 296
#define modifier_while 297
#define modifier_until 298
#define modifier_rescue 299
#define keyword_alias 300
#define keyword_defined 301
#define keyword_BEGIN 302
#define keyword_END 303
#define keyword__LINE__ 304
#define keyword__FILE__ 305
#define tIDENTIFIER 306
#define tFID 307
#define tGVAR 308
#define tIVAR 309
#define tCONSTANT 310
#define tCVAR 311
#define tLABEL 312
#define tINTEGER 313
#define tFLOAT 314
#define tSTRING_CONTENT 315
#define tCHAR 316
#define tNTH_REF 317
#define tBACK_REF 318
#define tREGEXP_END 319
#define tUPLUS 320
#define tUMINUS 321
#define tPOW 322
#define tCMP 323
#define tEQ 324
#define tEQQ 325
#define tNEQ 326
#define tGEQ 327
#define tLEQ 328
#define tANDOP 329
#define tOROP 330
#define tMATCH 331
#define tNMATCH 332
#define tDOT2 333
#define tDOT3 334
#define tAREF 335
#define tASET 336
#define tLSHFT 337
#define tRSHFT 338
#define tCOLON2 339
#define tCOLON3 340
#define tOP_ASGN 341
#define tASSOC 342
#define tLPAREN 343
#define tLPAREN_ARG 344
#define tRPAREN 345
#define tLBRACK 346
#define tLBRACE 347
#define tLBRACE_ARG 348
#define tSTAR 349
#define tAMPER 350
#define tLAMBDA 351
#define tSYMBEG 352
#define tSTRING_BEG 353
#define tXSTRING_BEG 354
#define tREGEXP_BEG 355
#define tWORDS_BEG 356
#define tQWORDS_BEG 357
#define tSTRING_DBEG 358
#define tSTRING_DVAR 359
#define tSTRING_END 360
#define tLAMBEG 361
#define tLOWEST 362
#define tUMINUS_NUM 363
#define tLAST_TOKEN 364




/* Copy the first part of user declarations.  */
#line 13 "parse.y"


#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYSTACK_USE_ALLOCA 0

#include "ruby.h"
#include "intern.h"
#include "node.h"
#include "st.h"
#include <stdio.h>
#include <errno.h>
#include <ctype.h>

#define YYMALLOC(size)		rb_parser_malloc(parser, size)
#define YYREALLOC(ptr, size)	rb_parser_realloc(parser, ptr, size)
#define YYCALLOC(nelem, size)	rb_parser_calloc(parser, nelem, size)
#define YYFREE(ptr)		rb_parser_free(parser, ptr)
#define malloc	YYMALLOC
#define realloc	YYREALLOC
#define calloc	YYCALLOC
#define free	YYFREE

#define ID_SCOPE_SHIFT 3
#define ID_SCOPE_MASK 0x07
#define ID_LOCAL      0x00
#define ID_INSTANCE   0x01
#define ID_GLOBAL     0x03
#define ID_ATTRSET    0x04
#define ID_CONST      0x05
#define ID_CLASS      0x06
#define ID_JUNK       0x07
#define ID_INTERNAL   ID_JUNK

#define is_notop_id(id) ((id)>tLAST_TOKEN)
#define is_local_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_LOCAL)
#define is_global_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_GLOBAL)
#define is_instance_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_INSTANCE)
#define is_attrset_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_ATTRSET)
#define is_const_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_CONST)
#define is_class_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_CLASS)
#define is_junk_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_JUNK)

#define is_asgn_or_id(id) ((is_notop_id(id)) && \
	(((id)&ID_SCOPE_MASK) == ID_GLOBAL || \
	 ((id)&ID_SCOPE_MASK) == ID_INSTANCE || \
	 ((id)&ID_SCOPE_MASK) == ID_CLASS))

#ifndef RIPPER
char *ruby_sourcefile;		/* current source file */
int   ruby_sourceline;		/* current line no. */
#endif

enum lex_state_e {
    EXPR_BEG,			/* ignore newline, +/- is a sign. */
    EXPR_END,			/* newline significant, +/- is a operator. */
    EXPR_ARG,			/* newline significant, +/- is a operator. */
    EXPR_CMDARG,		/* newline significant, +/- is a operator. */
    EXPR_ENDARG,		/* newline significant, +/- is a operator. */
    EXPR_MID,			/* newline significant, +/- is a operator. */
    EXPR_FNAME,			/* ignore newline, no reserved words. */
    EXPR_DOT,			/* right after `.' or `::', no reserved words. */
    EXPR_CLASS,			/* immediate after `class', no here document. */
    EXPR_VALUE,			/* alike EXPR_BEG but label is disallowed. */
};

# ifdef HAVE_LONG_LONG
typedef unsigned LONG_LONG stack_type;
# else
typedef unsigned long stack_type;
# endif

# define BITSTACK_PUSH(stack, n)	(stack = (stack<<1)|((n)&1))
# define BITSTACK_POP(stack)	(stack = stack >> 1)
# define BITSTACK_LEXPOP(stack)	(stack = (stack >> 1) | (stack & 1))
# define BITSTACK_SET_P(stack)	(stack&1)

#define COND_PUSH(n)	BITSTACK_PUSH(cond_stack, n)
#define COND_POP()	BITSTACK_POP(cond_stack)
#define COND_LEXPOP()	BITSTACK_LEXPOP(cond_stack)
#define COND_P()	BITSTACK_SET_P(cond_stack)

#define CMDARG_PUSH(n)	BITSTACK_PUSH(cmdarg_stack, n)
#define CMDARG_POP()	BITSTACK_POP(cmdarg_stack)
#define CMDARG_LEXPOP()	BITSTACK_LEXPOP(cmdarg_stack)
#define CMDARG_P()	BITSTACK_SET_P(cmdarg_stack)

/* must sync with real YYSTYPE */
union tmpyystype {
    VALUE val;
    NODE *node;
    unsigned long id;
    int num;
    struct RVarmap *vars;
};

struct vtable {
    ID *tbl;
    int pos;
    int capa;
    struct vtable *prev;
};

struct local_vars {
    struct vtable *tbl;
    struct vtable *dvars;
    struct local_vars *prev;
};

#define DVARS_INHERIT ((void*)1)
#define DVARS_TOPSCOPE NULL
#define DVARS_SPECIAL_P(tbl) (!POINTER_P(tbl))
#define POINTER_P(val) ((unsigned long)(val) & ~3UL)

static int
vtable_size(struct vtable *tbl)
{
    if (POINTER_P(tbl)) {
        return tbl->pos;
    }
    else {
        return 0;
    }
}

#define VTBL_DEBUG 0

static struct vtable *
vtable_alloc(struct vtable *prev)
{
    struct vtable *tbl = ALLOC(struct vtable);
    tbl->pos = 0;
    tbl->capa = 8;
    tbl->tbl = ALLOC_N(ID, tbl->capa);
    tbl->prev = prev;
    if (VTBL_DEBUG) printf("vtable_alloc: %p\n", tbl);
    return tbl;
}

static void
vtable_free(struct vtable *tbl)
{
    if (VTBL_DEBUG)printf("vtable_free: %p\n", tbl);
    if (POINTER_P(tbl)) {
        if (tbl->tbl) {
            xfree(tbl->tbl);
        }
        if (tbl) {
            xfree(tbl);
        }
    }
}

static void
vtable_add(struct vtable *tbl, ID id)
{
    if (!POINTER_P(tbl)) {
        rb_bug("vtable_add: vtable is not allocated (%p)", tbl);
    }
    if (VTBL_DEBUG) printf("vtable_add: %p, %s\n", tbl, rb_id2name(id));
    
    if (tbl->pos == tbl->capa) {
        tbl->capa = tbl->capa * 2;
        REALLOC_N(tbl->tbl, ID, tbl->capa);
    }
    tbl->tbl[tbl->pos++] = id;
}

static int
vtable_included(struct vtable * tbl, ID id)
{
    int i;

    if (POINTER_P(tbl)) {
        for (i = 0; i < tbl->pos; i++) {
            if (tbl->tbl[i] == id) {
                return 1;
            }
        }
    }
    return 0;
}

/*
    Structure of Lexer Buffer:

 lex_pbeg      tokp         lex_p        lex_pend
    |           |              |            |
    |-----------+--------------+------------|
                |<------------>|
                     token
*/
struct parser_params {
    NODE *heap;

    union tmpyystype *parser_yylval;   /* YYSTYPE not defined yet */
    VALUE eofp;

    NODE *parser_lex_strterm;
    enum lex_state_e parser_lex_state;
    stack_type parser_cond_stack;
    stack_type parser_cmdarg_stack;
    int parser_class_nest;
    int parser_paren_nest;
    int parser_lpar_beg;
    int parser_in_single;
    int parser_in_def;
    int parser_compile_for_eval;
    VALUE parser_cur_mid;
    int parser_in_defined;
    char *parser_tokenbuf;
    int parser_tokidx;
    int parser_toksiz;
    VALUE parser_lex_input;
    VALUE parser_lex_lastline;
    const char *parser_lex_pbeg;
    const char *parser_lex_p;
    const char *parser_lex_pend;
    int parser_heredoc_end;
    int parser_command_start;
    int parser_lex_gets_ptr;
    VALUE (*parser_lex_gets)(struct parser_params*,VALUE);
    struct local_vars *parser_lvtbl;
    int parser_ruby__end__seen;
    int line_count;
    int has_shebang;

#ifndef RIPPER
    /* Ruby core only */
    NODE *parser_eval_tree_begin;
    NODE *parser_eval_tree;
    VALUE debug_lines;
#else
    /* Ripper only */
    int parser_ruby_sourceline;
    VALUE parser_ruby_sourcefile;
    const char *tokp;
    VALUE delayed;
    int delayed_line;
    int delayed_col;

    VALUE value;
    VALUE result;
    VALUE parsing_thread;
    int toplevel_p;
#endif
};

#ifdef YYMALLOC
void *rb_parser_malloc(struct parser_params *, size_t);
void *rb_parser_realloc(struct parser_params *, void *, size_t);
void *rb_parser_calloc(struct parser_params *, size_t, size_t);
void rb_parser_free(struct parser_params *, void *);
#endif

static int parser_yyerror(struct parser_params*, const char*);
#define yyerror(msg) parser_yyerror(parser, msg)

#define YYPARSE_PARAM parser_v
#define YYLEX_PARAM parser_v
#define parser ((struct parser_params*)parser_v)

#define ruby_eval_tree		(parser->parser_eval_tree)
#define ruby_eval_tree_begin	(parser->parser_eval_tree_begin)
#define lex_strterm		(parser->parser_lex_strterm)
#define lex_state		(parser->parser_lex_state)
#define cond_stack		(parser->parser_cond_stack)
#define cmdarg_stack		(parser->parser_cmdarg_stack)
#define class_nest		(parser->parser_class_nest)
#define paren_nest		(parser->parser_paren_nest)
#define lpar_beg		(parser->parser_lpar_beg)
#define in_single		(parser->parser_in_single)
#define in_def			(parser->parser_in_def)
#define compile_for_eval	(parser->parser_compile_for_eval)
#define cur_mid			(parser->parser_cur_mid)
#define in_defined		(parser->parser_in_defined)
#define tokenbuf		(parser->parser_tokenbuf)
#define tokidx			(parser->parser_tokidx)
#define toksiz			(parser->parser_toksiz)
#define lex_input		(parser->parser_lex_input)
#define lex_lastline		(parser->parser_lex_lastline)
#define lex_pbeg		(parser->parser_lex_pbeg)
#define lex_p			(parser->parser_lex_p)
#define lex_pend		(parser->parser_lex_pend)
#define heredoc_end		(parser->parser_heredoc_end)
#define command_start		(parser->parser_command_start)
#define lex_gets_ptr		(parser->parser_lex_gets_ptr)
#define lex_gets		(parser->parser_lex_gets)
#define lvtbl			(parser->parser_lvtbl)
#define ruby__end__seen		(parser->parser_ruby__end__seen)
#ifdef RIPPER
#define ruby_sourceline		(parser->parser_ruby_sourceline)
#define ruby_sourcefile		(parser->parser_ruby_sourcefile)
#else
#define ruby_debug_lines	(parser->debug_lines)
#endif

static int yylex(void*, void*);

#ifndef RIPPER
#define yyparse ruby_yyparse
#define yydebug ruby_yydebug

static NODE *cond_gen(struct parser_params*,NODE*);
#define cond(node) cond_gen(parser, node)
static NODE *logop_gen(struct parser_params*,enum node_type,NODE*,NODE*);
#define logop(type,node1,node2) logop_gen(parser, type, node1, node2)

static int cond_negative(NODE**);

static NODE *newline_node(NODE*);
static void fixpos(NODE*,NODE*);

static int value_expr_gen(struct parser_params*,NODE*);
static void void_expr_gen(struct parser_params*,NODE*);
static NODE *remove_begin(NODE*);
#define value_expr(node) value_expr_gen(parser, (node) = remove_begin(node))
#define void_expr(node) void_expr_gen(parser, (node) = remove_begin(node))
static void void_stmts_gen(struct parser_params*,NODE*);
#define void_stmts(node) void_stmts_gen(parser, node)
static void reduce_nodes(NODE**);
static void block_dup_check(NODE*,NODE*);

static NODE *block_append(NODE*,NODE*);
static NODE *list_append(NODE*,NODE*);
static NODE *list_concat(NODE*,NODE*);
static NODE *arg_append(NODE*,NODE*);
static NODE *arg_concat(NODE*,NODE*);
static NODE *literal_concat(NODE*,NODE*);
static NODE *new_evstr(NODE*);
static NODE *evstr2dstr(NODE*);

static NODE *call_op_gen(struct parser_params*,NODE*,ID,int,NODE*);
#define call_op(recv,id,narg,arg1) call_op_gen(parser, recv,id,narg,arg1)

static NODE *new_args_gen(struct parser_params*,int,NODE*,ID,NODE*,ID);
#define new_args(f,o,r,p,b) new_args_gen(parser, f,o,r,p,b)
static void shadowing_lvar_gen(struct parser_params*,ID);
#define shadowing_lvar(name) shadowing_lvar_gen(parser, name)

static NODE *negate_lit(NODE*);
static NODE *ret_args(NODE*);
static NODE *arg_blk_pass(NODE*,NODE*);
static NODE *new_yield(NODE*);

static NODE *gettable_gen(struct parser_params*,ID);
#define gettable(id) gettable_gen(parser,id)
static NODE *assignable_gen(struct parser_params*,ID,NODE*);
#define assignable(id,node) assignable_gen(parser, id, node)
static NODE *new_bv_gen(struct parser_params*,ID,NODE*);
#define new_bv(id,node) new_bv_gen(parser, id, node)
static NODE *aryset_gen(struct parser_params*,NODE*,NODE*);
#define aryset(node1,node2) aryset_gen(parser, node1, node2)
static NODE *attrset_gen(struct parser_params*,NODE*,ID);
#define attrset(node,id) attrset_gen(parser, node, id)

static void rb_backref_error(NODE*);
static NODE *node_assign_gen(struct parser_params*,NODE*,NODE*);
#define node_assign(node1, node2) node_assign_gen(parser, node1, node2)

static NODE *match_op_gen(struct parser_params*,NODE*,NODE*);
#define match_op(node1,node2) match_op_gen(parser, node1, node2)

static void local_push_gen(struct parser_params*,int);
#define local_push(top) local_push_gen(parser,top)
static void local_pop_gen(struct parser_params*);
#define local_pop() local_pop_gen(parser)
static int  local_append_gen(struct parser_params*, ID);
#define local_append(id) local_append_gen(parser, id)
static int  local_cnt_gen(struct parser_params*, ID);
#define local_cnt(id) local_cnt_gen(parser, id)
static int  local_id_gen(struct parser_params*, ID);
#define local_id(id) local_id_gen(parser, id)
static ID  *local_tbl_gen(struct parser_params*);
#define local_tbl() local_tbl_gen(parser)
static ID  *dyna_tbl_gen(struct parser_params*);
#define dyna_tbl() dyna_tbl_gen(parser)
static ID   internal_id(void);

static void dyna_push_gen(struct parser_params*);
#define dyna_push() dyna_push_gen(parser)
static void dyna_pop_gen(struct parser_params*);
#define dyna_pop() dyna_pop_gen(parser)
static int dyna_in_block_gen(struct parser_params*);
#define dyna_in_block() dyna_in_block_gen(parser)
static NODE *dyna_init_gen(struct parser_params*, NODE*, int);
#define dyna_init(node, pre) dyna_init_gen(parser, node, pre)
static void dyna_var_gen(struct parser_params*,ID);
#define dyna_var(id) dyna_var_gen(parser, id)
static int dvar_defined_gen(struct parser_params*,ID);
#define dvar_defined(id) dvar_defined_gen(parser, id)
static int dvar_curr_gen(struct parser_params*,ID);
#define dvar_curr(id) dvar_curr_gen(parser, id)


static void top_local_init_gen(struct parser_params*);
#define top_local_init() top_local_init_gen(parser)
static void top_local_setup_gen(struct parser_params*);
#define top_local_setup() top_local_setup_gen(parser)
#else
#define remove_begin(node) (node)
#endif /* !RIPPER */
static int lvar_defined_gen(struct parser_params*, ID);
#define lvar_defined(id) lvar_defined_gen(parser, id)

#define RE_OPTION_ONCE (1<<16)

#define NODE_STRTERM NODE_ZARRAY	/* nothing to gc */
#define NODE_HEREDOC NODE_ARRAY 	/* 1, 3 to gc */
#define SIGN_EXTEND(x,n) (((1<<(n)-1)^((x)&~(~0<<(n))))-(1<<(n)-1))
#define nd_func u1.id
#if SIZEOF_SHORT == 2
#define nd_term(node) ((signed short)(node)->u2.id)
#else
#define nd_term(node) SIGN_EXTEND((node)->u2.id, CHAR_BIT*2)
#endif
#define nd_paren(node) (char)((node)->u2.id >> CHAR_BIT*2)
#define nd_nest u3.cnt

/****** Ripper *******/

#ifdef RIPPER
#define RIPPER_VERSION "0.1.0"

#include "eventids1.c"
#include "eventids2.c"
static ID ripper_id_gets;

static VALUE ripper_dispatch0(struct parser_params*,ID);
static VALUE ripper_dispatch1(struct parser_params*,ID,VALUE);
static VALUE ripper_dispatch2(struct parser_params*,ID,VALUE,VALUE);
static VALUE ripper_dispatch3(struct parser_params*,ID,VALUE,VALUE,VALUE);
static VALUE ripper_dispatch4(struct parser_params*,ID,VALUE,VALUE,VALUE,VALUE);
static VALUE ripper_dispatch5(struct parser_params*,ID,VALUE,VALUE,VALUE,VALUE,VALUE);

#define dispatch0(n)            ripper_dispatch0(parser, TOKEN_PASTE(ripper_id_, n))
#define dispatch1(n,a)          ripper_dispatch1(parser, TOKEN_PASTE(ripper_id_, n), a)
#define dispatch2(n,a,b)        ripper_dispatch2(parser, TOKEN_PASTE(ripper_id_, n), a, b)
#define dispatch3(n,a,b,c)      ripper_dispatch3(parser, TOKEN_PASTE(ripper_id_, n), a, b, c)
#define dispatch4(n,a,b,c,d)    ripper_dispatch4(parser, TOKEN_PASTE(ripper_id_, n), a, b, c, d)
#define dispatch5(n,a,b,c,d,e)  ripper_dispatch5(parser, TOKEN_PASTE(ripper_id_, n), a, b, c, d, e)

#define yyparse ripper_yyparse
#define yydebug ripper_yydebug

static VALUE ripper_intern(const char*);
static VALUE ripper_id2sym(ID);

#define arg_new() dispatch0(arglist_new)
#define arg_add(l,a) dispatch2(arglist_add, l, a)
#define arg_prepend(l,a) dispatch2(arglist_prepend, l, a)
#define arg_add_star(l,a) dispatch2(arglist_add_star, l, a)
#define arg_add_block(l,b) dispatch2(arglist_add_block, l, b)
#define arg_add_optblock(l,b) ((b)==Qundef? l : dispatch2(arglist_add_block, l, b))
#define bare_assoc(v) dispatch1(bare_assoc_hash, v)
#define arg_add_assocs(l,b) arg_add(l, bare_assoc(b))

#define args2mrhs(a) dispatch1(mrhs_new_from_arglist, a)
#define mrhs_new() dispatch0(mrhs_new)
#define mrhs_add(l,a) dispatch2(mrhs_add, l, a)
#define mrhs_add_star(l,a) dispatch2(mrhs_add_star, l, a)

#define mlhs_new() dispatch0(mlhs_new)
#define mlhs_add(l,a) dispatch2(mlhs_add, l, a)
#define mlhs_add_star(l,a) dispatch2(mlhs_add_star, l, a)

#define blockvar_new(p) dispatch1(blockvar_new, p)
#define blockvar_add_star(l,a) dispatch2(blockvar_add_star, l, a)
#define blockvar_add_block(l,a) dispatch2(blockvar_add_block, l, a)

#define method_optarg(m,a) ((a)==Qundef ? m : dispatch2(method_add_arg,m,a))
#define method_arg(m,a) dispatch2(method_add_arg,m,a)
#define escape_Qundef(x) ((x)==Qundef ? Qnil : (x))

#define FIXME 0

#endif /* RIPPER */

#ifndef RIPPER
# define ifndef_ripper(x) x
#else
# define ifndef_ripper(x)
#endif

#ifndef RIPPER
# define rb_warn0(fmt)    rb_warn(fmt)
# define rb_warnI(fmt,a)  rb_warn(fmt,a)
# define rb_warnS(fmt,a)  rb_warn(fmt,a)
# define rb_warning0(fmt) rb_warning(fmt)
# define rb_warningS(fmt,a) rb_warning(fmt,a)
#else
# define rb_warn0(fmt)    ripper_warn0(parser, fmt)
# define rb_warnI(fmt,a)  ripper_warnI(parser, fmt, a)
# define rb_warnS(fmt,a)  ripper_warnS(parser, fmt, a)
# define rb_warning0(fmt) ripper_warning0(parser, fmt)
# define rb_warningS(fmt,a) ripper_warningS(parser, fmt, a)
static void ripper_warn0(struct parser_params*, const char*);
static void ripper_warnI(struct parser_params*, const char*, int);
static void ripper_warnS(struct parser_params*, const char*, const char*);
static void ripper_warning0(struct parser_params*, const char*);
static void ripper_warningS(struct parser_params*, const char*, const char*);
#endif

#ifdef RIPPER
static void ripper_compile_error(struct parser_params*, const char *fmt, ...);
# define rb_compile_error ripper_compile_error
# define compile_error ripper_compile_error
# define PARSER_ARG parser,
#else
# define compile_error rb_compile_error
# define PARSER_ARG
#endif

#define NEW_BLOCK_PARAM(b, v) NEW_NODE(NODE_BLOCK_PASS, 0, b, v)

/* Older versions of Yacc set YYMAXDEPTH to a very low value by default (150,
   for instance).  This is too low for Ruby to parse some files, such as
   date/format.rb, therefore bump the value up to at least Bison's default. */
#ifdef OLD_YACC
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif
#endif



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 541 "parse.y"
typedef union YYSTYPE {
    VALUE val;
    NODE *node;
    ID id;
    int num;
    struct RVarmap *vars;
} YYSTYPE;
/* Line 196 of yacc.c.  */
#line 837 "parse.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 219 of yacc.c.  */
#line 849 "parse.c"

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T) && (defined (__STDC__) || defined (__cplusplus))
# include <stddef.h> /* INFRINGES ON USER NAME SPACE */
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#if ! defined (yyoverflow) || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if defined (__STDC__) || defined (__cplusplus)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     define YYINCLUDED_STDLIB_H
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM ((YYSIZE_T) -1)
#  endif
#  ifdef __cplusplus
extern "C" {
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if (! defined (malloc) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if (! defined (free) && ! defined (YYINCLUDED_STDLIB_H) \
	&& (defined (__STDC__) || defined (__cplusplus)))
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifdef __cplusplus
}
#  endif
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short int yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short int) + sizeof (YYSTYPE))			\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short int yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   9470

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  137
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  158
/* YYNRULES -- Number of rules. */
#define YYNRULES  539
/* YYNRULES -- Number of states. */
#define YYNSTATES  937

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   364

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     136,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   135,   122,     2,     2,     2,   120,   115,     2,
     131,   132,   118,   116,   129,   117,   128,   119,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   110,   134,
     112,   108,   111,   109,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   127,     2,   133,   114,     2,   130,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   125,   113,   126,   123,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   121,   124
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short int yyprhs[] =
{
       0,     0,     3,     4,     7,    12,    15,    17,    19,    23,
      26,    27,    32,    36,    40,    44,    47,    51,    55,    59,
      63,    67,    68,    74,    79,    83,    87,    91,    98,   104,
     110,   116,   120,   124,   128,   132,   134,   136,   140,   144,
     147,   150,   152,   154,   156,   158,   161,   164,   167,   169,
     174,   179,   180,   181,   188,   191,   195,   200,   206,   211,
     217,   220,   223,   225,   229,   231,   234,   238,   244,   247,
     252,   255,   260,   262,   266,   268,   272,   275,   279,   281,
     285,   287,   292,   296,   300,   304,   308,   311,   313,   315,
     320,   324,   328,   332,   336,   339,   341,   343,   345,   348,
     350,   354,   356,   358,   360,   362,   364,   366,   368,   370,
     372,   374,   375,   380,   382,   384,   386,   388,   390,   392,
     394,   396,   398,   400,   402,   404,   406,   408,   410,   412,
     414,   416,   418,   420,   422,   424,   426,   428,   430,   432,
     434,   436,   438,   440,   442,   444,   446,   448,   450,   452,
     454,   456,   458,   460,   462,   464,   466,   468,   470,   472,
     474,   476,   478,   480,   482,   484,   486,   488,   490,   492,
     494,   496,   498,   500,   502,   504,   506,   508,   510,   512,
     516,   522,   526,   533,   539,   545,   551,   557,   562,   566,
     570,   574,   578,   582,   586,   590,   594,   598,   603,   608,
     611,   614,   618,   622,   626,   630,   634,   638,   642,   646,
     650,   654,   658,   662,   666,   669,   672,   676,   680,   684,
     688,   689,   694,   701,   703,   705,   707,   710,   715,   718,
     722,   724,   726,   728,   730,   732,   735,   738,   743,   745,
     750,   754,   757,   762,   769,   771,   772,   775,   777,   778,
     782,   783,   788,   791,   794,   796,   798,   801,   805,   810,
     814,   819,   822,   824,   826,   828,   830,   832,   834,   836,
     838,   840,   841,   846,   847,   852,   856,   860,   863,   867,
     871,   873,   878,   882,   884,   885,   892,   895,   897,   900,
     903,   910,   917,   918,   919,   927,   928,   929,   937,   943,
     948,   949,   950,   960,   961,   968,   969,   970,   979,   980,
     986,   987,   994,   995,   996,  1006,  1008,  1010,  1012,  1014,
    1016,  1018,  1020,  1023,  1025,  1027,  1029,  1035,  1037,  1040,
    1042,  1044,  1046,  1050,  1052,  1056,  1058,  1061,  1066,  1076,
    1084,  1091,  1100,  1105,  1112,  1116,  1122,  1128,  1133,  1136,
    1141,  1149,  1151,  1155,  1162,  1165,  1167,  1169,  1173,  1175,
    1180,  1182,  1185,  1187,  1191,  1193,  1194,  1198,  1203,  1206,
    1210,  1214,  1215,  1216,  1223,  1226,  1231,  1236,  1239,  1244,
    1249,  1253,  1257,  1261,  1264,  1266,  1271,  1272,  1273,  1280,
    1281,  1282,  1289,  1295,  1297,  1299,  1306,  1308,  1310,  1312,
    1314,  1317,  1319,  1322,  1324,  1326,  1328,  1330,  1332,  1334,
    1336,  1339,  1343,  1347,  1351,  1355,  1359,  1360,  1364,  1366,
    1369,  1373,  1377,  1378,  1382,  1383,  1386,  1387,  1390,  1392,
    1393,  1397,  1398,  1403,  1405,  1407,  1409,  1411,  1414,  1416,
    1418,  1420,  1422,  1426,  1428,  1430,  1433,  1436,  1438,  1440,
    1442,  1444,  1446,  1448,  1450,  1452,  1454,  1456,  1458,  1460,
    1462,  1464,  1466,  1468,  1469,  1474,  1477,  1481,  1484,  1491,
    1500,  1505,  1512,  1517,  1524,  1527,  1532,  1539,  1542,  1547,
    1550,  1555,  1557,  1558,  1560,  1562,  1564,  1566,  1568,  1570,
    1574,  1576,  1580,  1584,  1586,  1590,  1592,  1594,  1597,  1599,
    1601,  1603,  1606,  1609,  1611,  1613,  1614,  1619,  1621,  1624,
    1627,  1629,  1633,  1637,  1640,  1642,  1644,  1646,  1648,  1650,
    1652,  1654,  1656,  1658,  1660,  1662,  1664,  1665,  1667,  1668,
    1670,  1673,  1676,  1677,  1679,  1681,  1683,  1685,  1687,  1690
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short int yyrhs[] =
{
     138,     0,    -1,    -1,   139,   141,    -1,   141,   235,   209,
     238,    -1,   142,   287,    -1,   294,    -1,   143,    -1,   142,
     293,   143,    -1,     1,   143,    -1,    -1,    45,   165,   144,
     165,    -1,    45,    53,    53,    -1,    45,    53,    63,    -1,
      45,    53,    62,    -1,     6,   166,    -1,   143,    40,   147,
      -1,   143,    41,   147,    -1,   143,    42,   147,    -1,   143,
      43,   147,    -1,   143,    44,   143,    -1,    -1,    47,   145,
     125,   141,   126,    -1,    48,   125,   141,   126,    -1,   160,
     108,   148,    -1,   154,   108,   148,    -1,   262,    86,   148,
      -1,   205,   127,   176,   290,    86,   148,    -1,   205,   128,
      51,    86,   148,    -1,   205,   128,    55,    86,   148,    -1,
     205,    84,    51,    86,   148,    -1,   263,    86,   148,    -1,
     160,   108,   187,    -1,   154,   108,   172,    -1,   154,   108,
     187,    -1,   146,    -1,   148,    -1,   146,    37,   146,    -1,
     146,    38,   146,    -1,    39,   146,    -1,   122,   148,    -1,
     170,    -1,   146,    -1,   153,    -1,   149,    -1,    30,   177,
      -1,    21,   177,    -1,    22,   177,    -1,   226,    -1,   226,
     128,   284,   179,    -1,   226,    84,   284,   179,    -1,    -1,
      -1,    93,   151,   214,   152,   141,   126,    -1,   283,   179,
      -1,   283,   179,   150,    -1,   205,   128,   284,   179,    -1,
     205,   128,   284,   179,   150,    -1,   205,    84,   284,   179,
      -1,   205,    84,   284,   179,   150,    -1,    32,   179,    -1,
      31,   179,    -1,   155,    -1,    88,   154,   289,    -1,   157,
      -1,   157,   156,    -1,   157,    94,   159,    -1,   157,    94,
     159,   129,   158,    -1,   157,    94,    -1,   157,    94,   129,
     158,    -1,    94,   159,    -1,    94,   159,   129,   158,    -1,
      94,    -1,    94,   129,   157,    -1,   159,    -1,    88,   154,
     289,    -1,   156,   129,    -1,   157,   156,   129,    -1,   156,
      -1,   158,   129,   156,    -1,   260,    -1,   205,   127,   176,
     290,    -1,   205,   128,    51,    -1,   205,    84,    51,    -1,
     205,   128,    55,    -1,   205,    84,    55,    -1,    85,    55,
      -1,   263,    -1,   260,    -1,   205,   127,   176,   290,    -1,
     205,   128,    51,    -1,   205,    84,    51,    -1,   205,   128,
      55,    -1,   205,    84,    55,    -1,    85,    55,    -1,   263,
      -1,    51,    -1,    55,    -1,    85,   161,    -1,   161,    -1,
     205,    84,   161,    -1,    51,    -1,    55,    -1,    52,    -1,
     168,    -1,   169,    -1,   163,    -1,   256,    -1,   164,    -1,
     258,    -1,   165,    -1,    -1,   166,   129,   167,   165,    -1,
     113,    -1,   114,    -1,   115,    -1,    68,    -1,    69,    -1,
      70,    -1,    76,    -1,   111,    -1,    72,    -1,   112,    -1,
      73,    -1,    82,    -1,    83,    -1,   116,    -1,   117,    -1,
     118,    -1,    94,    -1,   119,    -1,   120,    -1,    67,    -1,
     123,    -1,    65,    -1,    66,    -1,    80,    -1,    81,    -1,
     130,    -1,    49,    -1,    50,    -1,    47,    -1,    48,    -1,
      45,    -1,    37,    -1,     7,    -1,    21,    -1,    16,    -1,
       3,    -1,     5,    -1,    46,    -1,    26,    -1,    15,    -1,
      14,    -1,    10,    -1,     9,    -1,    36,    -1,    20,    -1,
      25,    -1,     4,    -1,    22,    -1,    34,    -1,    39,    -1,
      38,    -1,    23,    -1,     8,    -1,    24,    -1,    30,    -1,
      33,    -1,    32,    -1,    13,    -1,    35,    -1,     6,    -1,
      17,    -1,    31,    -1,    11,    -1,    12,    -1,    18,    -1,
      19,    -1,   160,   108,   170,    -1,   160,   108,   170,    44,
     170,    -1,   262,    86,   170,    -1,   205,   127,   176,   290,
      86,   170,    -1,   205,   128,    51,    86,   170,    -1,   205,
     128,    55,    86,   170,    -1,   205,    84,    51,    86,   170,
      -1,   205,    84,    55,    86,   170,    -1,    85,    55,    86,
     170,    -1,   263,    86,   170,    -1,   170,    78,   170,    -1,
     170,    79,   170,    -1,   170,   116,   170,    -1,   170,   117,
     170,    -1,   170,   118,   170,    -1,   170,   119,   170,    -1,
     170,   120,   170,    -1,   170,    67,   170,    -1,   121,    58,
      67,   170,    -1,   121,    59,    67,   170,    -1,    65,   170,
      -1,    66,   170,    -1,   170,   113,   170,    -1,   170,   114,
     170,    -1,   170,   115,   170,    -1,   170,    68,   170,    -1,
     170,   111,   170,    -1,   170,    72,   170,    -1,   170,   112,
     170,    -1,   170,    73,   170,    -1,   170,    69,   170,    -1,
     170,    70,   170,    -1,   170,    71,   170,    -1,   170,    76,
     170,    -1,   170,    77,   170,    -1,   122,   170,    -1,   123,
     170,    -1,   170,    82,   170,    -1,   170,    83,   170,    -1,
     170,    74,   170,    -1,   170,    75,   170,    -1,    -1,    46,
     288,   171,   170,    -1,   170,   109,   170,   288,   110,   170,
      -1,   188,    -1,   170,    -1,   294,    -1,   186,   291,    -1,
     186,   129,   281,   291,    -1,   281,   291,    -1,   131,   176,
     289,    -1,   294,    -1,   174,    -1,   294,    -1,   177,    -1,
     153,    -1,   186,   185,    -1,   281,   185,    -1,   186,   129,
     281,   185,    -1,   184,    -1,   172,   129,   186,   185,    -1,
     172,   129,   184,    -1,   281,   185,    -1,   172,   129,   281,
     185,    -1,   172,   129,   186,   129,   281,   185,    -1,   184,
      -1,    -1,   180,   181,    -1,   177,    -1,    -1,    89,   182,
     289,    -1,    -1,    89,   178,   183,   289,    -1,    95,   172,
      -1,   129,   184,    -1,   294,    -1,   172,    -1,    94,   172,
      -1,   186,   129,   172,    -1,   186,   129,    94,   172,    -1,
     186,   129,   172,    -1,   186,   129,    94,   172,    -1,    94,
     172,    -1,   239,    -1,   240,    -1,   243,    -1,   244,    -1,
     245,    -1,   248,    -1,   261,    -1,   263,    -1,    52,    -1,
      -1,     7,   189,   140,    10,    -1,    -1,    89,   146,   190,
     289,    -1,    88,   141,   132,    -1,   205,    84,    55,    -1,
      85,    55,    -1,    91,   173,   133,    -1,    92,   280,   126,
      -1,    30,    -1,    31,   131,   177,   289,    -1,    31,   131,
     289,    -1,    31,    -1,    -1,    46,   288,   131,   191,   146,
     289,    -1,   283,   228,    -1,   227,    -1,   227,   228,    -1,
      96,   219,    -1,    11,   147,   206,   141,   208,    10,    -1,
      12,   147,   206,   141,   209,    10,    -1,    -1,    -1,    18,
     192,   147,   207,   193,   141,    10,    -1,    -1,    -1,    19,
     194,   147,   207,   195,   141,    10,    -1,    16,   147,   287,
     233,    10,    -1,    16,   287,   233,    10,    -1,    -1,    -1,
      20,   210,    25,   196,   147,   207,   197,   141,    10,    -1,
      -1,     3,   162,   264,   198,   140,    10,    -1,    -1,    -1,
       3,    82,   146,   199,   292,   200,   140,    10,    -1,    -1,
       4,   162,   201,   140,    10,    -1,    -1,     5,   163,   202,
     266,   140,    10,    -1,    -1,    -1,     5,   278,   286,   203,
     163,   204,   266,   140,    10,    -1,    21,    -1,    22,    -1,
      23,    -1,    24,    -1,   188,    -1,   292,    -1,    13,    -1,
     292,    13,    -1,   292,    -1,    27,    -1,   209,    -1,    14,
     147,   206,   141,   208,    -1,   294,    -1,    15,   141,    -1,
     160,    -1,   154,    -1,   218,    -1,    88,   213,   289,    -1,
     211,    -1,   212,   129,   211,    -1,   212,    -1,   212,   129,
      -1,   212,   129,    95,   218,    -1,   212,   129,    94,   218,
     129,   212,   129,    95,   218,    -1,   212,   129,    94,   218,
     129,    95,   218,    -1,   212,   129,    94,   129,    95,   218,
      -1,   212,   129,    94,   129,   212,   129,    95,   218,    -1,
     212,   129,    94,   218,    -1,   212,   129,    94,   218,   129,
     212,    -1,   212,   129,    94,    -1,   212,   129,    94,   129,
     212,    -1,    94,   218,   129,    95,   218,    -1,    94,   129,
      95,   218,    -1,    94,   218,    -1,    94,   218,   129,   212,
      -1,    94,   218,   129,   212,   129,    95,   218,    -1,    94,
      -1,    94,   129,   212,    -1,    94,   129,   212,   129,    95,
     218,    -1,    95,   218,    -1,   294,    -1,   215,    -1,   113,
     216,   113,    -1,    75,    -1,   113,   213,   216,   113,    -1,
     294,    -1,   134,   217,    -1,   218,    -1,   217,   129,   218,
      -1,    51,    -1,    -1,   220,   221,   222,    -1,   131,   267,
     216,   289,    -1,   267,   216,    -1,   106,   141,   126,    -1,
      29,   141,    10,    -1,    -1,    -1,    28,   224,   214,   225,
     141,    10,    -1,   153,   223,    -1,   226,   128,   284,   175,
      -1,   226,    84,   284,   175,    -1,   283,   174,    -1,   205,
     128,   284,   175,    -1,   205,    84,   284,   174,    -1,   205,
      84,   285,    -1,   205,   128,   174,    -1,   205,    84,   174,
      -1,    32,   174,    -1,    32,    -1,   205,   127,   176,   290,
      -1,    -1,    -1,   125,   229,   214,   230,   141,   126,    -1,
      -1,    -1,    26,   231,   214,   232,   141,    10,    -1,    17,
     186,   206,   141,   234,    -1,   209,    -1,   233,    -1,     8,
     236,   237,   206,   141,   235,    -1,   294,    -1,   172,    -1,
     187,    -1,   294,    -1,    87,   160,    -1,   294,    -1,     9,
     141,    -1,   294,    -1,   259,    -1,   256,    -1,   258,    -1,
     241,    -1,    61,    -1,   242,    -1,   241,   242,    -1,    98,
     250,   105,    -1,    99,   251,   105,    -1,   100,   251,    64,
      -1,   101,   135,   105,    -1,   101,   246,   105,    -1,    -1,
     246,   247,   135,    -1,   252,    -1,   247,   252,    -1,   102,
     135,   105,    -1,   102,   249,   105,    -1,    -1,   249,    60,
     135,    -1,    -1,   250,   252,    -1,    -1,   251,   252,    -1,
      60,    -1,    -1,   104,   253,   255,    -1,    -1,   103,   254,
     141,   126,    -1,    53,    -1,    54,    -1,    56,    -1,   263,
      -1,    97,   257,    -1,   163,    -1,    54,    -1,    53,    -1,
      56,    -1,    97,   251,   105,    -1,    58,    -1,    59,    -1,
     121,    58,    -1,   121,    59,    -1,    51,    -1,    54,    -1,
      53,    -1,    55,    -1,    56,    -1,    34,    -1,    33,    -1,
      35,    -1,    36,    -1,    50,    -1,    49,    -1,   260,    -1,
     260,    -1,    62,    -1,    63,    -1,   292,    -1,    -1,   112,
     265,   147,   292,    -1,     1,   292,    -1,   131,   267,   289,
      -1,   267,   292,    -1,   269,   129,   272,   129,   274,   277,
      -1,   269,   129,   272,   129,   274,   129,   270,   277,    -1,
     269,   129,   272,   277,    -1,   269,   129,   272,   129,   270,
     277,    -1,   269,   129,   274,   277,    -1,   269,   129,   274,
     129,   270,   277,    -1,   269,   277,    -1,   272,   129,   274,
     277,    -1,   272,   129,   274,   129,   270,   277,    -1,   272,
     277,    -1,   272,   129,   270,   277,    -1,   274,   277,    -1,
     274,   129,   270,   277,    -1,   276,    -1,    -1,    55,    -1,
      54,    -1,    53,    -1,    56,    -1,    51,    -1,   268,    -1,
     269,   129,   268,    -1,   268,    -1,   270,   129,   268,    -1,
      51,   108,   172,    -1,   271,    -1,   272,   129,   271,    -1,
     118,    -1,    94,    -1,   273,    51,    -1,   273,    -1,   115,
      -1,    95,    -1,   275,    51,    -1,   129,   276,    -1,   294,
      -1,   261,    -1,    -1,   131,   279,   146,   289,    -1,   294,
      -1,   281,   291,    -1,   186,   291,    -1,   282,    -1,   281,
     129,   282,    -1,   172,    87,   172,    -1,    57,   172,    -1,
      51,    -1,    55,    -1,    52,    -1,    51,    -1,    55,    -1,
      52,    -1,   168,    -1,    51,    -1,    52,    -1,   168,    -1,
     128,    -1,    84,    -1,    -1,   293,    -1,    -1,   136,    -1,
     288,   132,    -1,   288,   133,    -1,    -1,   136,    -1,   129,
      -1,   134,    -1,   136,    -1,   292,    -1,   293,   134,    -1,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short int yyrline[] =
{
       0,   694,   694,   694,   725,   758,   769,   777,   785,   793,
     799,   799,   807,   815,   826,   836,   844,   857,   870,   886,
     902,   911,   910,   935,   946,   954,   964,   993,  1013,  1030,
    1047,  1064,  1074,  1082,  1091,  1100,  1103,  1104,  1112,  1120,
    1128,  1136,  1139,  1150,  1151,  1152,  1160,  1168,  1178,  1179,
    1188,  1200,  1207,  1199,  1223,  1232,  1243,  1252,  1263,  1272,
    1283,  1292,  1303,  1304,  1314,  1322,  1330,  1338,  1346,  1354,
    1362,  1370,  1378,  1386,  1396,  1397,  1407,  1415,  1425,  1433,
    1443,  1451,  1459,  1467,  1475,  1483,  1495,  1505,  1517,  1525,
    1533,  1541,  1549,  1557,  1570,  1583,  1594,  1602,  1605,  1613,
    1621,  1631,  1632,  1633,  1634,  1644,  1656,  1657,  1660,  1668,
    1671,  1679,  1679,  1689,  1690,  1691,  1692,  1693,  1694,  1695,
    1696,  1697,  1698,  1699,  1700,  1701,  1702,  1703,  1704,  1705,
    1706,  1707,  1708,  1709,  1710,  1711,  1712,  1713,  1714,  1717,
    1717,  1717,  1717,  1718,  1718,  1718,  1719,  1719,  1719,  1719,
    1720,  1720,  1720,  1720,  1721,  1721,  1721,  1722,  1722,  1722,
    1722,  1723,  1723,  1723,  1723,  1724,  1724,  1724,  1724,  1725,
    1725,  1725,  1725,  1726,  1726,  1726,  1726,  1727,  1727,  1730,
    1738,  1746,  1775,  1795,  1812,  1829,  1846,  1857,  1868,  1879,
    1896,  1913,  1921,  1929,  1937,  1945,  1953,  1961,  1970,  1979,
    1992,  2000,  2008,  2016,  2024,  2032,  2040,  2048,  2056,  2064,
    2072,  2080,  2088,  2096,  2104,  2112,  2120,  2128,  2136,  2144,
    2152,  2152,  2162,  2171,  2177,  2188,  2189,  2193,  2201,  2211,
    2221,  2222,  2225,  2226,  2229,  2238,  2246,  2256,  2265,  2274,
    2282,  2290,  2299,  2309,  2319,  2322,  2322,  2334,  2335,  2335,
    2344,  2344,  2355,  2365,  2369,  2372,  2380,  2388,  2396,  2406,
    2414,  2422,  2432,  2433,  2434,  2435,  2436,  2437,  2438,  2439,
    2440,  2449,  2448,  2473,  2473,  2482,  2491,  2499,  2507,  2520,
    2528,  2536,  2544,  2552,  2560,  2560,  2570,  2581,  2582,  2593,
    2597,  2614,  2631,  2631,  2631,  2645,  2645,  2645,  2659,  2670,
    2678,  2678,  2678,  2690,  2689,  2713,  2722,  2712,  2748,  2747,
    2771,  2770,  2801,  2802,  2801,  2828,  2836,  2844,  2852,  2862,
    2873,  2878,  2879,  2886,  2891,  2894,  2895,  2908,  2909,  2919,
    2920,  2923,  2924,  2939,  2947,  2957,  2971,  2979,  2987,  2996,
    3005,  3014,  3023,  3031,  3039,  3047,  3055,  3064,  3073,  3081,
    3089,  3098,  3106,  3114,  3123,  3133,  3140,  3143,  3151,  3159,
    3170,  3171,  3181,  3189,  3199,  3209,  3209,  3231,  3239,  3249,
    3253,  3260,  3267,  3259,  3287,  3298,  3307,  3318,  3327,  3337,
    3347,  3355,  3366,  3377,  3385,  3393,  3408,  3415,  3407,  3434,
    3441,  3433,  3461,  3473,  3474,  3477,  3496,  3499,  3507,  3508,
    3511,  3515,  3518,  3526,  3529,  3530,  3538,  3541,  3558,  3559,
    3560,  3570,  3580,  3607,  3644,  3652,  3659,  3666,  3676,  3684,
    3694,  3702,  3709,  3716,  3727,  3734,  3745,  3752,  3762,  3764,
    3763,  3780,  3779,  3801,  3809,  3817,  3825,  3828,  3840,  3841,
    3842,  3843,  3846,  3884,  3885,  3886,  3894,  3904,  3905,  3906,
    3907,  3908,  3909,  3910,  3911,  3912,  3913,  3914,  3917,  3927,
    3937,  3938,  3941,  3950,  3949,  3957,  3969,  3981,  3987,  3995,
    4003,  4011,  4019,  4027,  4035,  4043,  4051,  4059,  4067,  4075,
    4083,  4091,  4100,  4109,  4117,  4125,  4133,  4141,  4154,  4162,
    4172,  4180,  4191,  4204,  4212,  4228,  4229,  4232,  4243,  4259,
    4260,  4263,  4278,  4282,  4292,  4301,  4301,  4330,  4331,  4335,
    4348,  4355,  4365,  4373,  4383,  4384,  4385,  4388,  4389,  4390,
    4391,  4394,  4395,  4396,  4399,  4404,  4411,  4412,  4415,  4416,
    4419,  4422,  4425,  4426,  4427,  4430,  4431,  4434,  4435,  4439
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "keyword_class", "keyword_module",
  "keyword_def", "keyword_undef", "keyword_begin", "keyword_rescue",
  "keyword_ensure", "keyword_end", "keyword_if", "keyword_unless",
  "keyword_then", "keyword_elsif", "keyword_else", "keyword_case",
  "keyword_when", "keyword_while", "keyword_until", "keyword_for",
  "keyword_break", "keyword_next", "keyword_redo", "keyword_retry",
  "keyword_in", "keyword_do", "keyword_do_cond", "keyword_do_block",
  "keyword_do_LAMBDA", "keyword_return", "keyword_yield", "keyword_super",
  "keyword_self", "keyword_nil", "keyword_true", "keyword_false",
  "keyword_and", "keyword_or", "keyword_not", "modifier_if",
  "modifier_unless", "modifier_while", "modifier_until", "modifier_rescue",
  "keyword_alias", "keyword_defined", "keyword_BEGIN", "keyword_END",
  "keyword__LINE__", "keyword__FILE__", "tIDENTIFIER", "tFID", "tGVAR",
  "tIVAR", "tCONSTANT", "tCVAR", "tLABEL", "tINTEGER", "tFLOAT",
  "tSTRING_CONTENT", "tCHAR", "tNTH_REF", "tBACK_REF", "tREGEXP_END",
  "tUPLUS", "tUMINUS", "tPOW", "tCMP", "tEQ", "tEQQ", "tNEQ", "tGEQ",
  "tLEQ", "tANDOP", "tOROP", "tMATCH", "tNMATCH", "tDOT2", "tDOT3",
  "tAREF", "tASET", "tLSHFT", "tRSHFT", "tCOLON2", "tCOLON3", "tOP_ASGN",
  "tASSOC", "tLPAREN", "tLPAREN_ARG", "tRPAREN", "tLBRACK", "tLBRACE",
  "tLBRACE_ARG", "tSTAR", "tAMPER", "tLAMBDA", "tSYMBEG", "tSTRING_BEG",
  "tXSTRING_BEG", "tREGEXP_BEG", "tWORDS_BEG", "tQWORDS_BEG",
  "tSTRING_DBEG", "tSTRING_DVAR", "tSTRING_END", "tLAMBEG", "tLOWEST",
  "'='", "'?'", "':'", "'>'", "'<'", "'|'", "'^'", "'&'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "tUMINUS_NUM", "'!'", "'~'", "tLAST_TOKEN", "'{'",
  "'}'", "'['", "'.'", "','", "'`'", "'('", "')'", "']'", "';'", "' '",
  "'\\n'", "$accept", "program", "@1", "bodystmt", "compstmt", "stmts",
  "stmt", "@2", "@3", "expr", "expr_value", "command_call",
  "block_command", "cmd_brace_block", "@4", "@5", "command", "mlhs",
  "mlhs_basic", "mlhs_item", "mlhs_head", "mlhs_post", "mlhs_node", "lhs",
  "cname", "cpath", "fname", "fsym", "fitem", "undef_list", "@6", "op",
  "reswords", "arg", "@7", "arg_value", "aref_args", "paren_args",
  "opt_paren_args", "opt_call_args", "call_args", "call_args2",
  "command_args", "@8", "open_args", "@9", "@10", "block_arg",
  "opt_block_arg", "args", "mrhs", "primary", "@11", "@12", "@13", "@14",
  "@15", "@16", "@17", "@18", "@19", "@20", "@21", "@22", "@23", "@24",
  "@25", "@26", "primary_value", "then", "do", "if_tail", "opt_else",
  "for_var", "bparam_item", "bparam_list", "block_param",
  "opt_block_param", "block_param_def", "opt_bv_decl", "bv_decls", "bvar",
  "lambda", "@27", "f_larglist", "lambda_body", "do_block", "@28", "@29",
  "block_call", "method_call", "brace_block", "@30", "@31", "@32", "@33",
  "case_body", "cases", "opt_rescue", "exc_list", "exc_var", "opt_ensure",
  "literal", "strings", "string", "string1", "xstring", "regexp", "words",
  "word_list", "word", "qwords", "qword_list", "string_contents",
  "xstring_contents", "string_content", "@34", "@35", "string_dvar",
  "symbol", "sym", "dsym", "numeric", "variable", "var_ref", "var_lhs",
  "backref", "superclass", "@36", "f_arglist", "f_args", "f_norm_arg",
  "f_arg", "f_post_arg", "f_opt", "f_optarg", "restarg_mark", "f_rest_arg",
  "blkarg_mark", "f_block_arg", "opt_f_block_arg", "singleton", "@37",
  "assoc_list", "assocs", "assoc", "operation", "operation2", "operation3",
  "dot_or_colon", "opt_terms", "opt_nl", "rparen", "rbracket", "trailer",
  "term", "terms", "none", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short int yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,    61,    63,
      58,    62,    60,   124,    94,    38,    43,    45,    42,    47,
      37,   363,    33,   126,   364,   123,   125,    91,    46,    44,
      96,    40,    41,    93,    59,    32,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned short int yyr1[] =
{
       0,   137,   139,   138,   140,   141,   142,   142,   142,   142,
     144,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   145,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   143,   143,   143,   143,   146,   146,   146,   146,
     146,   146,   147,   148,   148,   148,   148,   148,   149,   149,
     149,   151,   152,   150,   153,   153,   153,   153,   153,   153,
     153,   153,   154,   154,   155,   155,   155,   155,   155,   155,
     155,   155,   155,   155,   156,   156,   157,   157,   158,   158,
     159,   159,   159,   159,   159,   159,   159,   159,   160,   160,
     160,   160,   160,   160,   160,   160,   161,   161,   162,   162,
     162,   163,   163,   163,   163,   163,   164,   164,   165,   165,
     166,   167,   166,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   168,
     168,   168,   168,   168,   168,   168,   168,   168,   168,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     171,   170,   170,   170,   172,   173,   173,   173,   173,   174,
     175,   175,   176,   176,   177,   177,   177,   177,   177,   178,
     178,   178,   178,   178,   178,   180,   179,   181,   182,   181,
     183,   181,   184,   185,   185,   186,   186,   186,   186,   187,
     187,   187,   188,   188,   188,   188,   188,   188,   188,   188,
     188,   189,   188,   190,   188,   188,   188,   188,   188,   188,
     188,   188,   188,   188,   191,   188,   188,   188,   188,   188,
     188,   188,   192,   193,   188,   194,   195,   188,   188,   188,
     196,   197,   188,   198,   188,   199,   200,   188,   201,   188,
     202,   188,   203,   204,   188,   188,   188,   188,   188,   205,
     206,   206,   206,   207,   207,   208,   208,   209,   209,   210,
     210,   211,   211,   212,   212,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   213,   213,   214,   214,   215,   215,   215,
     216,   216,   217,   217,   218,   220,   219,   221,   221,   222,
     222,   224,   225,   223,   226,   226,   226,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   229,   230,   228,   231,
     232,   228,   233,   234,   234,   235,   235,   236,   236,   236,
     237,   237,   238,   238,   239,   239,   239,   240,   241,   241,
     241,   242,   243,   244,   245,   245,   246,   246,   247,   247,
     248,   248,   249,   249,   250,   250,   251,   251,   252,   253,
     252,   254,   252,   255,   255,   255,   255,   256,   257,   257,
     257,   257,   258,   259,   259,   259,   259,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   261,   262,
     263,   263,   264,   265,   264,   264,   266,   266,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   268,   268,   268,   268,   268,   269,   269,
     270,   270,   271,   272,   272,   273,   273,   274,   274,   275,
     275,   276,   277,   277,   278,   279,   278,   280,   280,   280,
     281,   281,   282,   282,   283,   283,   283,   284,   284,   284,
     284,   285,   285,   285,   286,   286,   287,   287,   288,   288,
     289,   290,   291,   291,   291,   292,   292,   293,   293,   294
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     0,     2,     4,     2,     1,     1,     3,     2,
       0,     4,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     0,     5,     4,     3,     3,     3,     6,     5,     5,
       5,     3,     3,     3,     3,     1,     1,     3,     3,     2,
       2,     1,     1,     1,     1,     2,     2,     2,     1,     4,
       4,     0,     0,     6,     2,     3,     4,     5,     4,     5,
       2,     2,     1,     3,     1,     2,     3,     5,     2,     4,
       2,     4,     1,     3,     1,     3,     2,     3,     1,     3,
       1,     4,     3,     3,     3,     3,     2,     1,     1,     4,
       3,     3,     3,     3,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       5,     3,     6,     5,     5,     5,     5,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       0,     4,     6,     1,     1,     1,     2,     4,     2,     3,
       1,     1,     1,     1,     1,     2,     2,     4,     1,     4,
       3,     2,     4,     6,     1,     0,     2,     1,     0,     3,
       0,     4,     2,     2,     1,     1,     2,     3,     4,     3,
       4,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     3,     3,     2,     3,     3,
       1,     4,     3,     1,     0,     6,     2,     1,     2,     2,
       6,     6,     0,     0,     7,     0,     0,     7,     5,     4,
       0,     0,     9,     0,     6,     0,     0,     8,     0,     5,
       0,     6,     0,     0,     9,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     5,     1,     2,     1,
       1,     1,     3,     1,     3,     1,     2,     4,     9,     7,
       6,     8,     4,     6,     3,     5,     5,     4,     2,     4,
       7,     1,     3,     6,     2,     1,     1,     3,     1,     4,
       1,     2,     1,     3,     1,     0,     3,     4,     2,     3,
       3,     0,     0,     6,     2,     4,     4,     2,     4,     4,
       3,     3,     3,     2,     1,     4,     0,     0,     6,     0,
       0,     6,     5,     1,     1,     6,     1,     1,     1,     1,
       2,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     3,     3,     0,     3,     1,     2,
       3,     3,     0,     3,     0,     2,     0,     2,     1,     0,
       3,     0,     4,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     2,     3,     2,     6,     8,
       4,     6,     4,     6,     2,     4,     6,     2,     4,     2,
       4,     1,     0,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     3,     1,     3,     1,     1,     2,     1,     1,
       1,     2,     2,     1,     1,     0,     4,     1,     2,     2,
       1,     3,     3,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     1,     0,     1,
       2,     2,     0,     1,     1,     1,     1,     1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short int yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     0,   271,
       0,     0,   526,   292,   295,     0,   315,   316,   317,   318,
     280,   245,   384,   453,   452,   454,   455,     0,     0,   528,
      21,     0,   457,   456,   447,   516,   449,   448,   450,   451,
     443,   444,   408,   460,   461,     0,     0,     0,     0,     0,
     539,   539,    72,   365,   426,   424,   426,   426,   416,   422,
       0,     0,     0,     3,   526,     7,    35,    36,    44,    43,
       0,    62,     0,    64,    74,     0,    41,   223,     0,    48,
     287,   262,   263,   407,   409,   264,   265,   266,   267,   405,
     406,   404,   458,   268,     0,   269,   245,     6,     9,   315,
     316,   280,   283,   384,   528,    96,    97,     0,     0,     0,
       0,    99,     0,   319,     0,   458,   269,     0,   308,   148,
     159,   149,   172,   145,   165,   155,   154,   175,   176,   170,
     153,   152,   147,   173,   177,   178,   157,   146,   160,   164,
     166,   158,   151,   167,   174,   169,   168,   161,   171,   156,
     144,   163,   162,   143,   150,   141,   142,   139,   140,   101,
     103,   102,   134,   135,   132,   116,   117,   118,   121,   123,
     119,   136,   137,   124,   125,   129,   120,   122,   113,   114,
     115,   126,   127,   128,   130,   131,   133,   138,   505,   310,
     104,   105,   504,     0,   168,   161,   171,   156,   139,   140,
     101,   102,   106,   108,   110,    15,   107,   109,     0,     0,
      42,     0,     0,     0,   458,     0,   269,     0,   535,   536,
     526,     0,   537,   527,     0,     0,     0,   330,   329,     0,
       0,   458,   269,     0,     0,     0,     0,   234,   224,   255,
      46,   238,   539,   539,   510,    47,    45,   528,    61,     0,
     539,   383,    60,    39,     0,    10,   529,   220,     0,     0,
     199,     0,   200,   277,     0,   528,   273,     0,   532,   532,
     225,   532,     0,   532,   507,     0,     0,    70,     0,    80,
      87,   289,   482,   440,   439,   441,   438,     0,   437,     0,
       0,     0,     0,     0,     0,     0,   445,   446,    40,   214,
     215,     5,   527,     0,     0,     0,     0,     0,     0,     0,
     371,   374,     0,    76,     0,    68,    65,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   539,     0,     0,     0,   389,
     386,   288,   410,     0,     0,   377,    54,   286,     0,   305,
      96,    97,    98,   445,   446,     0,   463,   303,   462,     0,
     539,     0,     0,     0,   482,   525,   524,   312,   111,     0,
     539,   277,   321,     0,   320,     0,     0,   539,     0,     0,
       0,     0,     0,     0,     0,   538,     0,     0,   277,     0,
     539,     0,   300,   513,   256,   252,     0,     0,   235,   254,
       0,   236,   528,     0,   282,   248,   247,   246,   528,   233,
     232,    12,    14,    13,     0,   284,     0,     0,     0,     0,
       0,     0,   275,    63,   528,   278,   534,   533,   226,   534,
     228,   534,   509,   279,   508,    86,    73,     0,     0,   539,
       0,   487,   485,   484,   483,   486,   496,   500,   499,   495,
     482,     0,   539,   488,   539,   493,   539,   498,   539,     0,
     481,   428,   431,   429,   442,   427,   411,   425,   412,   413,
     414,   415,     0,   418,   420,     0,   421,     0,     0,     8,
      16,    17,    18,    19,    20,    37,    38,   539,     0,    25,
      33,     0,    34,   528,     0,    66,    77,    24,   179,   255,
      32,   196,   204,   209,   210,   211,   206,   208,   218,   219,
     212,   213,   189,   190,   216,   217,   528,   205,   207,   201,
     202,   203,   191,   192,   193,   194,   195,   517,   522,   518,
     523,   382,   245,   380,   528,   517,   519,   518,   520,   381,
     539,   517,   518,   245,   245,   539,   539,    26,   181,    31,
     188,    51,    55,     0,   465,     0,     0,    96,    97,   100,
       0,   528,   539,     0,   528,   482,     0,     0,     0,     0,
     272,   539,   539,   396,   539,   322,   179,   521,   276,   528,
     517,   518,   539,     0,     0,   299,   324,   293,   323,   296,
     521,   276,   528,   517,   518,     0,   512,     0,   257,   253,
     539,     0,   511,   281,   530,    41,     0,   250,   528,   244,
     539,   229,    11,     0,   221,     0,    23,   187,   274,   532,
     257,     0,    78,    71,    83,    85,   528,   517,   518,     0,
     539,     0,     0,   366,     0,   368,   360,     0,   474,   503,
       0,   477,   497,     0,   479,   501,     0,     0,   417,   419,
     423,   197,   198,   358,   539,   372,   356,   355,   261,     0,
      75,    69,     0,     0,     0,     0,     0,   379,    58,     0,
     385,     0,     0,   231,   378,    56,   230,   376,    50,   375,
      49,   390,   387,   539,   306,     0,     0,   385,   309,   506,
     528,     0,   467,   313,   112,   397,   398,   539,   399,     0,
     539,   327,     0,     0,   325,     0,   385,     0,     0,     0,
     298,     0,     0,     0,     0,   385,     0,   258,   237,     0,
     528,   249,   241,   528,    22,   227,     0,    81,   492,   528,
       0,     0,   364,   361,   362,   489,   539,   539,   502,   490,
     539,   494,   539,   487,   539,     0,   433,   434,   435,   430,
     436,     0,   351,     0,   333,   335,   539,     0,   331,     0,
       0,   259,    67,   180,     0,    30,   185,   186,    59,   531,
       0,    28,   183,    29,   184,    57,     0,     0,    52,     0,
     464,   304,   466,   311,   482,     0,     0,   401,   328,     0,
       4,   403,     0,   290,     0,   291,   539,     0,     0,   301,
     240,   539,   539,   251,   285,    79,   367,   370,   369,     0,
       0,   470,     0,   472,     0,   478,     0,   475,   480,   432,
     528,     0,   348,   354,   336,     0,   357,     0,   260,   222,
      27,   182,     0,     0,     0,     0,     0,     0,   400,     0,
      88,    95,     0,   402,     0,   393,   394,   392,   294,   297,
       0,     0,   239,   242,   363,   539,   539,   539,   491,   539,
     332,     0,   352,     0,   344,     0,   334,   359,   373,   391,
     388,     0,   307,     0,    94,     0,   539,     0,   539,   539,
       0,   539,   471,     0,   468,   473,   476,   347,     0,     0,
     349,     0,   342,   337,    53,   314,   521,    93,   528,   517,
     518,   395,   326,   302,   243,   539,     0,   346,     0,     0,
     345,     0,   385,   469,   353,     0,   340,     0,     0,   343,
     350,     0,   339,     0,   341,     0,   338
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short int yydefgoto[] =
{
      -1,     1,     2,   379,   380,    64,    65,   424,   258,    66,
     211,    67,    68,   562,   693,   844,    69,    70,    71,    72,
      73,   633,    74,   212,   111,   112,   202,   203,   204,   205,
     579,   548,   191,    76,   426,   239,   267,   541,   684,   418,
     419,   617,   248,   249,   417,   618,   730,   241,   408,   242,
     502,    77,   208,   434,   623,   224,   723,   225,   724,   605,
     860,   566,   563,   789,   372,   374,   578,   794,   261,   383,
     597,   713,   714,   230,   764,   765,   766,   665,   666,   645,
     743,   768,   281,   282,   461,   643,   311,   497,   769,    79,
      80,   357,   556,   787,   555,   786,   394,   857,   582,   707,
     796,   800,    81,    82,    83,    84,    85,    86,    87,   293,
     482,    88,   295,   289,   287,   475,   657,   656,   759,    89,
     288,    90,    91,   214,    93,   215,   216,   367,   565,   576,
     577,   749,   464,   750,   465,   466,   467,   468,   469,   748,
     648,   193,   373,   272,   243,   244,   117,   570,   543,   377,
     221,   413,   414,   680,   438,   384,   223,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -740
static const short int yypact[] =
{
    -740,   113,  2104,  -740,  5778,  7722,  8034,  4085,  5321,  -740,
    6750,  6750,  3845,  -740,  -740,  7826,  5886,  5886,  -740,  -740,
    5886,  2337,  4694,  -740,  -740,  -740,  -740,  6750,  5193,   -10,
    -740,    50,  -740,  -740,  4206,  2207,  -740,  -740,  4329,  -740,
    -740,  -740,  -740,  -740,  -740,  7506,  7506,   123,  3361,  6750,
    6426,  6426,  5570,  -740,  5065,  -740,  -740,  -740,    64,    69,
     380,  7614,  7506,  -740,    -7,   618,   459,  -740,  -740,   184,
     110,  -740,   108,  7930,  -740,   142,  2190,   404,   424,   199,
      70,  -740,  -740,   160,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   391,  -740,   192,   441,    43,  -740,   618,  -740,
    -740,  -740,   137,   156,   -10,   213,   492,  6750,   244,  3361,
     446,  -740,    77,  -740,   466,  -740,  -740,    43,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,   296,   299,   338,   417,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,   427,   430,   513,
    -740,   562,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,   628,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,   152,  -740,  -740,  2743,   261,
     459,    81,   216,   501,    37,   251,    39,    81,  -740,  -740,
      -7,   336,  -740,   224,  6750,  6750,   308,  -740,  -740,   522,
     396,    57,   114,  7506,  7506,  7506,  7506,  -740,  2190,   301,
    -740,  -740,   300,   306,  -740,  -740,  -740,  3737,  -740,  5994,
    5886,  -740,  -740,  -740,    68,  -740,  -740,   320,   349,  3495,
    -740,   525,   387,   728,   368,    12,   459,   389,   155,   182,
    -740,   240,   408,   182,  -740,   475,  8138,   410,   538,   610,
     622,  -740,   630,  -740,  -740,  -740,  -740,   388,  -740,   511,
     571,   478,   432,   584,   442,   100,   498,   500,  -740,  -740,
    -740,  -740,  3953,  6750,  6750,  6750,  6750,  5778,  6750,  6750,
    -740,  -740,  6858,  -740,  3361,  5674,   458,  6858,  7506,  7506,
    7506,  7506,  7506,  7506,  7506,  7506,  7506,  7506,  7506,  7506,
    7506,  7506,  7506,  7506,  7506,  7506,  7506,  7506,  7506,  7506,
    7506,  7506,  7506,  7506,  8299,  5886,  8369,  9139,  9139,  -740,
    -740,  -740,  -740,  7614,  7614,  -740,   482,  -740,   320,   459,
    -740,   642,  -740,  -740,  -740,    -7,  -740,  -740,  -740,  8439,
    5886,  8509,  2743,  6750,   969,  -740,  -740,  -740,  -740,   591,
     599,    51,  -740,  2877,   597,  7506,  8579,  5886,  8649,  7506,
    7506,  3145,   336,  6966,   614,  -740,    15,    15,   115,  8719,
    5886,  8789,  -740,  -740,  -740,  -740,  7506,  6102,  -740,  -740,
    6534,  -740,   -10,   495,  -740,  6210,  -740,  -740,   -10,  -740,
    -740,  -740,  -740,  -740,  5321,  -740,  7506,  3495,   509,  8579,
    8649,  7506,  -740,   540,   -10,  -740,  6642,  -740,  -740,  7074,
    -740,  7182,  -740,  -740,  -740,   642,  8138,  8138,  8859,  5886,
    8929,   564,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
     835,    55,   557,  -740,   566,  -740,   582,   663,   588,   672,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,   219,  -740,  -740,   592,  -740,  7506,  7506,   618,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,    31,  7506,  -740,
     601,   603,  -740,    12,  8138,   607,  -740,  -740,  1228,  -740,
    -740,   387,  9333,  9333,  9333,  9333,   706,   706,  9350,  9279,
    9333,  9333,  2320,  2320,   229,   229,  9203,   706,   706,   796,
     796,   926,   363,   363,   387,   387,   387,  2467,  4815,  2597,
    4936,  -740,   156,  -740,   -10,   732,  -740,   809,  -740,  -740,
    4694,  -740,  -740,  2609,  2609,    31,    31,  -740,  2190,  -740,
    2190,  -740,  -740,    -7,  -740,  6750,  2743,   520,   162,  -740,
     156,   -10,   156,   731,    61,   835,  2743,    -7,  5449,  5321,
    -740,  7290,   738,  -740,   514,  -740,  2445,  4452,  4573,   -10,
     101,   288,   738,   733,    95,  -740,  -740,  -740,  -740,  -740,
      65,   107,   -10,   125,   147,  6750,  -740,  7506,   301,  -740,
     306,   301,  -740,  -740,  -740,  9258,    48,  -740,   -10,  -740,
     306,  -740,  -740,  6750,  2190,   631,  -740,  2190,  -740,   182,
    -740,   458,  -740,   633,   520,   162,   -10,   141,   228,  7506,
     557,  3629,  3495,  -740,   709,  -740,  -740,   835,  -740,  -740,
     835,  -740,  -740,   649,  -740,  -740,  3495,   872,  -740,  -740,
    -740,   387,   387,  -740,   385,  -740,  -740,  -740,   636,  7398,
    -740,   633,  8138,  7506,   667,  7614,  7506,  -740,   482,   648,
     812,  7614,  7614,  -740,  -740,   482,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,    31,  -740,    -7,   770,  -740,  -740,  -740,
     -10,   772,  -740,  -740,  -740,   601,  -740,   696,  -740,  3253,
     781,  -740,  6750,   788,  -740,  7506,   329,  7506,  7506,   803,
    -740,  7182,  3011,  3629,  3629,   151,    15,  -740,  -740,  6318,
     -10,  -740,  -740,    61,  -740,  -740,  8138,   201,  -740,   -10,
     807,   701,  -740,   700,  -740,  -740,   702,   703,  -740,  -740,
     719,  -740,   722,  -740,   719,   704,  -740,  -740,  -740,  -740,
    -740,   316,    38,   709,  -740,   725,   557,   734,  -740,  3629,
    7506,   726,   633,  2190,  7506,  -740,  2190,  2190,  -740,  -740,
    7614,  -740,  2190,  -740,  2190,  -740,  3629,  3495,  -740,  2743,
    -740,  -740,  -740,  -740,   969,  8242,    81,  -740,  -740,  3629,
    -740,  -740,    81,  -740,  7506,  -740,   545,   854,   858,  -740,
    -740,   740,   306,  -740,  -740,  -740,  -740,  -740,  -740,   709,
     835,  -740,   649,  -740,   649,  -740,   649,  -740,  -740,  -740,
     -10,   133,   741,  -740,   421,   758,  -740,   877,   763,  2190,
    -740,  2190,   889,   775,  3495,   892,  2743,   848,  -740,   644,
     610,   622,  2743,  -740,  2877,  -740,  -740,  -740,  -740,  -740,
    3629,  6102,  -740,  -740,  -740,   719,   776,   719,  -740,   719,
    -740,   709,   778,   645,    52,   709,  -740,  -740,  -740,  -740,
    -740,   782,  -740,   894,   642,  8999,  5886,  9069,   599,   514,
     899,   306,  -740,   649,  -740,  -740,  -740,  -740,   664,   709,
     789,   712,   792,  -740,  -740,  -740,    54,   162,   -10,    98,
      99,  -740,  -740,  -740,  -740,   719,   709,  -740,   715,   709,
     794,   751,   106,  -740,  -740,   709,  -740,   761,   709,   795,
    -740,   709,  -740,   765,  -740,   709,  -740
};

/* YYPGOTO[NTERM-NUM].  */
static const short int yypgoto[] =
{
    -740,  -740,  -740,  -311,   150,  -740,    32,  -740,  -740,   181,
      27,   -45,  -740,  -210,  -740,  -740,    14,    80,  -740,   -54,
     634,  -453,     5,  1215,   -52,   921,    10,  -740,     7,  -740,
    -740,    47,  -740,   647,  -740,  1226,  -740,    19,   102,  -296,
     126,  -740,    58,  -740,  -740,  -740,  -740,  -367,  -178,     2,
    -289,     6,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,    -2,  -197,
    -371,    42,  -520,  -740,  -499,  -739,   183,  -468,  -740,  -540,
    -740,  -120,  -740,  -740,  -740,  -740,  -740,  -740,  -740,  -740,
    -740,   863,  -740,  -740,  -740,  -740,  -363,  -740,    59,  -740,
    -740,  -740,  -740,  -740,  -740,   862,  -740,  -740,  -740,  -740,
    -740,  -740,  -740,  -740,   718,  -216,  -740,  -740,  -740,    -1,
    -740,    16,  -740,  1104,   939,  1246,  1127,  -740,  -740,   154,
    -250,  -281,  -740,  -551,  -613,   304,  -740,  -564,  -740,  -277,
      91,  -740,  -740,  -740,   -28,  -301,   153,  -230,  -740,  -740,
      -4,   -23,   -62,  -526,  -203,    21,   890,   816
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -540
static const short int yytable[] =
{
      78,   463,    78,   114,   114,   470,   257,   206,   213,   213,
     213,   113,   113,   229,   213,   213,   298,   189,   213,   316,
     391,   113,   269,   273,   207,   213,   599,   206,   510,   593,
     237,   237,   462,   222,   237,   255,    98,   751,   217,   220,
     609,   251,   596,   609,   207,   697,    78,   213,   619,   544,
     278,   671,   268,   271,   190,   190,   362,   277,   113,   213,
     301,   573,   710,   716,   286,   411,   440,   -91,   442,   349,
     444,   278,   719,   477,   571,   190,   725,   483,   365,   113,
     252,   358,   -88,   747,   641,   222,   752,   691,   692,   742,
     -91,   589,   872,   463,   382,   227,   349,   470,   308,   309,
     739,   190,   754,   742,   602,   213,   663,    78,   382,   612,
     737,   -90,   -92,     3,   542,   355,   550,   553,   554,   -89,
     312,   421,   251,  -459,   767,   390,   256,   218,   265,   219,
     422,   423,   -93,   368,   900,   406,   355,   431,   612,   -95,
     -94,   572,   240,   245,   664,   -88,   246,   -95,   256,   218,
     -90,   219,    63,   636,   356,    96,   542,    96,   550,   -94,
     485,   642,   920,    96,    96,    96,   -82,   831,   350,    96,
      96,   572,   -92,    96,   250,   259,   -89,   729,   263,   463,
      96,   901,   929,   470,   742,  -517,   -80,   717,   -91,   366,
     -91,   210,   210,   210,   -83,   350,  -517,   256,   264,   292,
     572,    96,    96,   433,   294,   486,    78,   751,   253,   -90,
     640,   218,   310,   219,    96,   218,   392,   219,   312,   772,
     572,   761,   213,   213,   721,   788,   835,  -385,   871,   218,
     266,   219,   -90,   -92,   -90,   -92,   -85,   313,  -518,  -514,
     -89,   222,   -89,   -87,   -86,   213,  -276,   213,   213,   -82,
     317,   396,   397,   -84,   -82,   696,   866,    78,    55,   264,
      96,   237,    96,   237,   237,   701,   659,   499,   247,   865,
     -82,   867,   507,   -82,   278,   869,   -84,   -82,   353,   471,
     -81,   378,   113,   347,   436,  -385,   855,   250,   359,  -276,
    -276,   437,   706,  -518,   463,   360,   318,  -447,   470,   361,
      78,   213,   213,   213,   213,    78,   213,   213,   557,   559,
     213,   439,    78,   278,   501,   213,   381,   569,   437,   501,
     505,   113,   472,   473,   385,   700,  -385,   348,  -385,  -385,
     490,   491,   492,   493,   489,   876,   -84,   389,  -514,   494,
    -447,  -447,   915,   213,  -514,   339,   340,   341,   342,   343,
     613,   213,   213,   393,   658,   809,   621,   -84,   395,   237,
     -84,    96,   810,   398,   -84,   549,   745,   742,   213,   441,
      78,   213,   628,   412,   718,   416,   437,    96,    96,   610,
    -453,    78,   922,  -452,   237,   213,   564,   620,   406,    78,
     549,   540,   631,   632,   503,   594,   -92,   722,   213,   876,
      96,   237,    96,    96,   761,   210,   210,   549,   629,   428,
     762,   763,    96,   213,   237,   804,   540,   598,   598,   876,
     549,   402,  -454,   206,  -453,    78,   735,  -452,   876,   407,
     318,   622,   728,   540,   876,   410,   742,   -89,   296,   297,
     207,   670,   732,   856,   278,   278,   540,   213,   471,   549,
     632,   425,   113,   113,   318,    96,    96,    96,    96,    96,
      96,    96,    96,   237,   264,    96,  -454,    96,   778,   549,
      96,   190,   742,   761,   427,   785,   540,  -459,   845,   762,
     763,   341,   342,   343,   210,   210,   210,   210,  -319,   495,
     496,   472,   473,   474,   609,   540,   308,   309,    96,   -88,
     432,  -455,   278,   674,   363,   364,    96,    96,   344,   761,
     113,  -457,   699,   463,  -456,   874,   875,   470,  -515,   644,
     -80,   679,   435,    96,   744,    96,    96,   354,   712,   709,
     445,  -319,  -319,   584,   443,   883,    96,   480,   471,   447,
      96,   592,   479,   868,    96,  -455,  -521,   484,   679,   -95,
     369,   345,   346,    96,   574,  -457,   731,   651,  -456,   654,
     709,   677,   393,   213,    78,   487,   679,   488,    96,   683,
     -87,   471,   683,   683,    78,   561,  -450,   625,   206,   679,
      96,   472,   473,   501,   694,   386,   704,   506,   703,   677,
     908,   683,   695,   370,   371,   207,   266,  -447,   702,   852,
     678,   580,    96,   213,  -521,   854,   399,   581,   685,   429,
     585,   688,   690,   679,   472,   473,   476,  -515,   632,  -450,
    -450,   213,   448,  -515,   595,   190,   190,   614,   387,   388,
     775,   471,   726,   862,   863,   626,   781,   783,   792,    78,
      78,  -447,   832,   833,   471,  -521,  -450,  -521,  -521,   400,
     401,  -517,   387,   430,    78,   687,   689,   572,   303,   304,
     305,   306,   307,   238,   238,   449,   450,   238,   813,   -75,
     278,   814,   639,   213,   472,   473,   478,   816,   113,   213,
     213,   451,   815,   452,   453,   454,   455,   472,   473,   481,
    -450,   644,   260,   262,  -458,   647,   742,   238,   238,   864,
     753,   812,   452,   453,   454,   455,  -269,    78,   299,   300,
     213,   650,   375,   914,   652,   742,   790,   653,    96,    96,
      78,    78,    78,   655,   456,   457,  -277,   660,   885,    96,
    -255,   811,   669,   761,   278,   840,   672,  -458,  -458,   802,
     899,   698,   113,   720,   457,   458,   210,   598,   459,  -269,
    -269,   897,   761,   709,   902,   903,   376,   734,    96,   916,
     742,   460,   736,   742,   458,  -256,   742,    78,   870,  -277,
    -277,   886,   887,   318,   290,   291,    96,   774,   213,   917,
     791,   779,   793,   795,    78,    78,   210,    78,   331,   332,
     799,   740,   741,   849,    96,    96,   924,    78,   803,   926,
     761,   113,   742,   761,   733,   930,   755,   919,   932,    96,
     925,   934,   742,   805,   431,   936,   742,   817,   681,   336,
     337,   338,   339,   340,   341,   342,   343,   818,    96,   819,
     829,   820,   822,   891,    96,    96,   -94,   821,   823,   761,
     -90,   825,    78,   827,    78,   828,   928,   836,   824,   761,
      78,   826,    78,   761,   834,  -257,   931,   -86,    78,   798,
     935,   -82,    96,   318,   858,    96,   270,   274,   859,   861,
     873,   877,   806,   807,   808,    96,    96,    96,   331,   332,
     238,   238,   238,   299,   213,   679,   451,   878,   452,   453,
     454,   455,  -258,   210,   238,   682,   238,   238,   780,   879,
     237,   880,   882,   884,   905,   893,   549,   898,   904,   913,
     446,   338,   339,   340,   341,   342,   343,   -92,   918,   837,
     -89,   921,    96,   927,   933,   756,   757,   118,   758,   456,
     457,   912,   540,    96,    43,    44,   842,   843,   -84,    96,
      96,   -81,    96,   351,   830,   352,   192,   911,   846,   853,
     458,   746,    96,   459,   302,     0,   892,   894,   895,   238,
     896,     0,     0,     0,   508,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,     0,   238,   318,   881,     0,     0,    96,     0,    96,
     558,   560,   888,     0,   889,    96,   923,    96,   331,   332,
     890,     0,     0,    96,     0,     0,     0,   238,     0,     0,
     451,     0,   452,   453,   454,   455,     0,     0,     0,     0,
       0,     0,   586,     0,   238,     0,   558,   560,     0,    96,
     238,     0,   339,   340,   341,   342,   343,   238,     0,     0,
       0,     0,     0,   238,   238,     0,     0,   238,   409,   409,
       0,     0,   615,   456,   457,     0,   420,     0,     0,     0,
       0,     0,     0,   624,     0,     0,     0,     0,   627,     0,
       0,     0,     0,   238,   458,     0,   238,   459,   238,     0,
       0,     0,     0,     0,     0,     0,   238,     0,     0,     0,
     575,     0,     0,     0,     0,     0,    92,     0,    92,   115,
     115,   115,     0,     0,     0,     0,     0,     0,     0,   231,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    95,
       0,    95,   116,   116,   661,   662,     0,     0,     0,     0,
       0,     0,   232,     0,     0,   238,     0,     0,     0,     0,
       0,     0,    92,     0,     0,     0,   279,     0,     0,     0,
       0,   420,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    95,     0,   279,     0,   280,
       0,     0,     0,     0,     0,     0,   420,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   583,     0,     0,     0,
     280,     0,     0,   420,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    92,     0,     0,   420,    75,     0,    75,
       0,     0,     0,     0,     0,     0,     0,     0,   238,     0,
     228,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,     0,
      94,     0,     0,     0,   238,     0,     0,     0,     0,     0,
       0,     0,     0,    75,     0,   420,     0,     0,     0,     0,
       0,     0,   673,     0,     0,     0,     0,     0,   646,     0,
     649,     0,   649,     0,   649,     0,   238,     0,     0,     0,
       0,     0,     0,     0,    94,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,     0,
     331,   332,    92,   667,     0,     0,   238,     0,     0,     0,
     773,     0,   776,   777,    75,     0,     0,     0,   782,   784,
       0,     0,     0,     0,     0,    95,     0,   333,     0,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,     0,
       0,     0,     0,     0,     0,    94,     0,  -224,     0,     0,
       0,     0,   776,    92,   782,   784,   686,     0,   238,   686,
     686,   667,   667,     0,     0,     0,   238,     0,     0,     0,
     279,     0,     0,     0,     0,     0,    95,     0,   686,     0,
       0,     0,     0,     0,     0,     0,     0,   708,   711,     0,
     711,     0,     0,   280,     0,     0,    92,     0,   711,     0,
       0,    92,     0,     0,     0,     0,     0,   238,    92,   279,
       0,   839,     0,    75,     0,     0,   409,   841,     0,    95,
       0,     0,     0,     0,    95,     0,   409,     0,     0,     0,
       0,    95,   280,     0,     0,     0,     0,     0,     0,     0,
       0,   841,     0,     0,    94,     0,   646,     0,     0,   403,
     404,   405,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,    92,     0,     0,     0,
     646,     0,     0,     0,     0,     0,     0,    92,     0,     0,
       0,     0,     0,     0,     0,    92,     0,     0,     0,    95,
       0,     0,     0,     0,     0,    94,     0,     0,   238,   667,
      95,     0,     0,     0,     0,     0,     0,    75,    95,     0,
       0,     0,    75,   797,     0,     0,   801,     0,     0,    75,
       0,    92,     0,   238,     0,     0,     0,     0,   500,     0,
       0,     0,     0,   509,     0,     0,     0,     0,    94,     0,
     279,   279,     0,    94,    95,     0,     0,     0,     0,     0,
      94,     0,   649,   649,     0,     0,   649,     0,   649,     0,
     649,     0,     0,   280,   280,     0,     0,     0,     0,     0,
       0,     0,   646,     0,     0,     0,     0,    75,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,     0,
       0,     0,     0,     0,     0,     0,    75,     0,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    94,   509,
       0,     0,   711,     0,     0,     0,     0,   409,   409,    94,
       0,   280,   606,   608,     0,     0,   611,    94,     0,     0,
       0,   616,    75,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   608,     0,     0,   611,     0,   630,     0,     0,
      92,     0,     0,    94,     0,     0,     0,     0,     0,     0,
      92,   649,   649,   649,     0,   649,     0,     0,     0,     0,
       0,     0,     0,    95,     0,     0,     0,     0,     0,     0,
       0,     0,   420,    95,   583,   711,     0,   409,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   668,     0,     0,     0,     0,     0,
       0,   649,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      92,     0,     0,     0,     0,     0,     0,     0,    95,    95,
       0,     0,     0,     0,     0,     0,   279,     0,     0,     0,
       0,    75,     0,    95,   760,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,     0,     0,     0,   280,
       0,     0,     0,     0,     0,     0,     0,   705,     0,     0,
       0,     0,    94,    92,     0,     0,     0,     0,     0,     0,
       0,     0,    94,     0,     0,     0,    92,    92,    92,     0,
       0,     0,     0,   727,     0,     0,    95,     0,     0,     0,
     279,     0,     0,     0,     0,     0,     0,     0,     0,    95,
      95,    95,     0,     0,     0,     0,    75,    75,     0,     0,
       0,     0,     0,   280,     0,   738,     0,     0,     0,     0,
       0,    75,     0,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    94,    94,     0,
      92,    92,     0,    92,     0,   771,    95,     0,     0,   850,
       0,     0,    94,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,    95,     0,    95,     0,     0,     0,
       0,     0,   851,     0,    75,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    75,    75,    75,
       0,     0,     0,     0,     0,     0,     0,   630,    92,     0,
      92,     0,     0,     0,     0,    94,    92,     0,    92,     0,
       0,     0,     0,     0,    92,     0,     0,     0,    94,    94,
      94,    95,     0,    95,     0,     0,     0,     0,     0,    95,
       0,    95,     0,     0,    75,     0,     0,    95,     0,     0,
       0,     0,     0,     0,     0,     0,   838,     0,     0,     0,
       0,    75,    75,     0,    75,     0,     0,     0,     0,     0,
     848,     0,     0,     0,    75,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    94,    94,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    75,
       0,    75,     0,     0,     0,     0,     0,    75,     0,    75,
       0,     0,     0,     0,     0,    75,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   608,     0,     0,
      94,     0,    94,     0,     0,     0,     0,     0,    94,     0,
      94,     0,     0,     0,  -539,     4,    94,     5,     6,     7,
       8,     9,     0,     0,     0,    10,    11,     0,     0,     0,
      12,     0,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,    27,     0,     0,     0,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    47,
       0,     0,    48,    49,     0,    50,    51,     0,    52,     0,
      53,    54,    55,    56,    57,    58,    59,  -270,     0,     0,
       0,     0,     0,     0,     0,  -270,  -270,  -270,     0,     0,
    -270,  -270,  -270,     0,  -270,    60,    61,    62,     0,     0,
       0,     0,     0,     0,  -270,  -270,  -270,     0,  -539,     0,
    -539,     0,     0,     0,  -270,  -270,     0,  -270,  -270,  -270,
    -270,  -270,     0,     0,     0,     0,     0,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329,   330,
       0,     0,   331,   332,  -270,  -270,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,     0,     0,  -270,
    -270,  -270,     0,     0,  -270,     0,     0,     0,     0,   333,
    -270,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,     0,     0,  -270,     0,     0,  -270,  -270,  -270,  -270,
    -270,  -270,  -270,  -270,  -270,  -270,  -270,  -270,     0,     0,
       0,     0,     0,  -270,  -270,  -270,  -270,  -283,     0,  -270,
    -270,  -270,     0,  -270,     0,  -283,  -283,  -283,     0,     0,
    -283,  -283,  -283,     0,  -283,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -283,  -283,     0,     0,     0,     0,
       0,     0,     0,     0,  -283,  -283,     0,  -283,  -283,  -283,
    -283,  -283,     0,     0,     0,     0,     0,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,  -540,  -540,
       0,     0,   331,   332,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,     0,     0,  -283,
    -283,  -283,     0,     0,  -283,     0,     0,     0,     0,     0,
    -283,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,     0,     0,     0,     0,     0,  -283,     0,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,     0,     0,
       0,     0,     0,  -283,  -283,  -283,  -283,  -521,   247,  -283,
    -283,  -283,     0,  -283,     0,  -521,  -521,  -521,     0,     0,
       0,  -521,  -521,     0,  -521,     0,     0,     0,     0,   673,
       0,     0,     0,  -521,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -521,  -521,     0,  -521,  -521,  -521,
    -521,  -521,   318,   319,   320,   321,   322,   323,   324,   325,
     326,   327,   328,   329,   330,     0,     0,   331,   332,     0,
       0,     0,     0,     0,  -521,  -521,  -521,  -521,  -521,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,     0,     0,  -521,
    -521,  -521,     0,   675,   333,     0,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -91,  -521,     0,  -521,  -521,
    -521,  -521,  -521,  -521,  -521,  -521,  -521,  -521,     0,     0,
       0,     0,  -521,  -521,  -521,  -521,   -83,  -276,     0,  -521,
       0,  -521,     0,  -521,     0,  -276,  -276,  -276,     0,  -539,
       0,  -276,  -276,     0,  -276,     0,     0,  -539,  -539,  -539,
       0,     0,  -539,  -539,  -539,     0,  -539,     0,     0,     0,
       0,     0,     0,     0,  -276,  -276,  -539,  -276,  -276,  -276,
    -276,  -276,     0,     0,     0,     0,  -539,  -539,     0,  -539,
    -539,  -539,  -539,  -539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,     0,     0,  -276,
    -276,  -276,     0,   676,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -539,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   -93,  -276,     0,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,     0,     0,
       0,     0,     0,  -276,  -276,  -276,   -85,     0,     0,  -276,
       0,  -276,     0,  -276,     0,  -539,     0,  -539,     0,     0,
     250,  -539,     0,  -539,     4,  -539,     5,     6,     7,     8,
       9,  -539,  -539,  -539,    10,    11,     0,     0,  -539,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,     0,    42,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    48,    49,     0,    50,    51,     0,    52,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -539,     4,  -539,
       5,     6,     7,     8,     9,     0,     0,  -539,    10,    11,
       0,  -539,  -539,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,     0,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    40,    41,     0,    42,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    47,     0,     0,    48,    49,     0,    50,    51,
       0,    52,     0,    53,    54,    55,    56,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -539,     4,  -539,     5,     6,     7,     8,     9,     0,
       0,  -539,    10,    11,     0,     0,  -539,    12,  -539,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,     0,    42,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,    48,
      49,     0,    50,    51,     0,    52,     0,    53,    54,    55,
      56,    57,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -539,     4,  -539,     5,     6,
       7,     8,     9,     0,     0,  -539,    10,    11,     0,     0,
    -539,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,     0,    42,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,    48,    49,     0,    50,    51,     0,    52,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     4,     0,     5,     6,     7,     8,
       9,     0,  -539,  -539,    10,    11,    60,    61,    62,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,  -539,
       0,  -539,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,     0,    42,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    48,    49,     0,    50,    51,     0,    52,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
       0,     0,     4,     0,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,    60,    61,    62,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,  -539,     0,  -539,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,     0,    40,
      41,     0,    42,    43,    44,     0,    45,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,    48,
      49,     0,    50,    51,     0,    52,     0,    53,    54,    55,
      56,    57,    58,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,  -539,     0,  -539,     4,  -539,     5,     6,
       7,     8,     9,     0,     0,     0,    10,    11,     0,     0,
       0,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,     0,    42,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,    48,    49,     0,    50,    51,     0,    52,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    61,    62,     0,
       0,  -539,     0,     0,     0,     0,     0,     0,     0,  -539,
       4,  -539,     5,     6,     7,     8,     9,     0,     0,  -539,
      10,    11,     0,     0,     0,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,    26,     0,     0,    27,     0,
       0,     0,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,     0,    40,    41,     0,
      42,    43,    44,     0,    45,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    47,     0,     0,    48,    49,     0,
      50,    51,     0,    52,     0,    53,    54,    55,    56,    57,
      58,    59,     0,     0,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     0,     9,     0,     0,     0,    10,    11,
      60,    61,    62,    12,     0,    13,    14,    15,    99,   100,
      18,    19,     0,  -539,     0,  -539,     0,   101,    21,    22,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,     0,    32,    33,    34,    35,
      36,    37,    38,    39,   233,    40,    41,     0,    42,    43,
      44,     0,    45,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   209,     0,     0,   109,    49,     0,    50,    51,
       0,   234,   235,    53,    54,    55,    56,    57,    58,    59,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     0,     9,     0,     0,     0,    10,    11,    60,   236,
      62,    12,     0,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,   256,     0,    20,    21,    22,    23,    24,
      25,    26,     0,     0,    27,     0,     0,     0,     0,     0,
       0,    29,     0,     0,    32,    33,    34,    35,    36,    37,
      38,    39,     0,    40,    41,     0,    42,    43,    44,     0,
      45,    46,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     209,     0,     0,   109,    49,     0,    50,    51,     0,     0,
       0,    53,    54,    55,    56,    57,    58,    59,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,    60,    61,    62,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,   218,
       0,   219,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
       0,    40,    41,     0,    42,    43,    44,     0,    45,    46,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,    48,    49,     0,    50,    51,     0,    52,     0,    53,
      54,    55,    56,    57,    58,    59,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   395,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,     0,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   157,   158,   159,   160,    36,    37,
     161,    39,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,     0,   168,   169,     0,
       0,   170,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,     0,   186,  -514,
    -514,  -514,     0,  -514,     0,   187,   188,  -514,  -514,     0,
       0,     0,  -514,     0,  -514,  -514,  -514,  -514,  -514,  -514,
    -514,     0,  -514,     0,     0,     0,  -514,  -514,  -514,  -514,
    -514,  -514,  -514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -514,     0,     0,  -514,  -514,  -514,  -514,  -514,
    -514,  -514,  -514,  -514,  -514,  -514,     0,  -514,  -514,  -514,
       0,  -514,  -514,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -514,     0,     0,  -514,  -514,     0,  -514,  -514,     0,
    -514,  -514,  -514,  -514,  -514,  -514,  -514,  -514,  -514,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -514,  -514,  -514,
       0,  -514,  -515,  -515,  -515,     0,  -515,  -514,     0,     0,
    -515,  -515,     0,     0,     0,  -515,     0,  -515,  -515,  -515,
    -515,  -515,  -515,  -515,     0,  -515,     0,     0,     0,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -515,     0,     0,  -515,  -515,
    -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,  -515,     0,
    -515,  -515,  -515,     0,  -515,  -515,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -515,     0,     0,  -515,  -515,     0,
    -515,  -515,     0,  -515,  -515,  -515,  -515,  -515,  -515,  -515,
    -515,  -515,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -515,  -515,  -515,     0,  -515,  -517,  -517,  -517,     0,  -517,
    -515,     0,     0,  -517,  -517,     0,     0,     0,  -517,     0,
    -517,  -517,  -517,  -517,  -517,  -517,  -517,     0,     0,     0,
       0,     0,  -517,  -517,  -517,  -517,  -517,  -517,  -517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -517,     0,
       0,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,  -517,
    -517,  -517,     0,  -517,  -517,  -517,     0,  -517,  -517,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -517,   715,     0,
    -517,  -517,     0,  -517,  -517,     0,  -517,  -517,  -517,  -517,
    -517,  -517,  -517,  -517,  -517,     0,     0,     0,     0,     0,
     -91,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -517,  -517,  -517,  -518,  -518,  -518,     0,
    -518,     0,     0,  -517,  -518,  -518,     0,     0,     0,  -518,
       0,  -518,  -518,  -518,  -518,  -518,  -518,  -518,     0,     0,
       0,     0,     0,  -518,  -518,  -518,  -518,  -518,  -518,  -518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -518,
       0,     0,  -518,  -518,  -518,  -518,  -518,  -518,  -518,  -518,
    -518,  -518,  -518,     0,  -518,  -518,  -518,     0,  -518,  -518,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -518,   676,
       0,  -518,  -518,     0,  -518,  -518,     0,  -518,  -518,  -518,
    -518,  -518,  -518,  -518,  -518,  -518,     0,     0,     0,     0,
       0,   -93,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -518,  -518,  -518,  -245,  -245,  -245,
       0,  -245,     0,     0,  -518,  -245,  -245,     0,     0,     0,
    -245,     0,  -245,  -245,  -245,  -245,  -245,  -245,  -245,     0,
       0,     0,     0,     0,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -245,     0,     0,  -245,  -245,  -245,  -245,  -245,  -245,  -245,
    -245,  -245,  -245,  -245,     0,  -245,  -245,  -245,     0,  -245,
    -245,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -245,
       0,     0,  -245,  -245,     0,  -245,  -245,     0,  -245,  -245,
    -245,  -245,  -245,  -245,  -245,  -245,  -245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -245,  -245,  -245,  -519,  -519,
    -519,     0,  -519,     0,     0,   250,  -519,  -519,     0,     0,
       0,  -519,     0,  -519,  -519,  -519,  -519,  -519,  -519,  -519,
       0,     0,     0,     0,     0,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -519,     0,     0,  -519,  -519,  -519,  -519,  -519,  -519,
    -519,  -519,  -519,  -519,  -519,     0,  -519,  -519,  -519,     0,
    -519,  -519,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -519,     0,     0,  -519,  -519,     0,  -519,  -519,     0,  -519,
    -519,  -519,  -519,  -519,  -519,  -519,  -519,  -519,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -519,  -519,  -519,  -520,
    -520,  -520,     0,  -520,     0,     0,  -519,  -520,  -520,     0,
       0,     0,  -520,     0,  -520,  -520,  -520,  -520,  -520,  -520,
    -520,     0,     0,     0,     0,     0,  -520,  -520,  -520,  -520,
    -520,  -520,  -520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -520,     0,     0,  -520,  -520,  -520,  -520,  -520,
    -520,  -520,  -520,  -520,  -520,  -520,     0,  -520,  -520,  -520,
       0,  -520,  -520,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -520,     0,     0,  -520,  -520,     0,  -520,  -520,     0,
    -520,  -520,  -520,  -520,  -520,  -520,  -520,  -520,  -520,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -520,  -520,  -520,
       0,     0,     0,     0,     0,     0,     0,  -520,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,     0,     0,     0,   143,   144,   145,   194,   195,
     196,   197,   150,   151,   152,     0,     0,     0,     0,     0,
     153,   154,   155,   156,   198,   199,   200,   160,   283,   284,
     201,   285,     0,     0,     0,     0,     0,     0,     0,     0,
     162,   163,   164,   165,   166,   167,     0,   168,   169,     0,
       0,   170,     0,     0,     0,   171,   172,   173,   174,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,     0,     0,   186,     0,
       0,     0,     0,     0,     0,   187,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
       0,     0,     0,   143,   144,   145,   194,   195,   196,   197,
     150,   151,   152,     0,     0,     0,     0,     0,   153,   154,
     155,   156,   198,   199,   200,   160,   254,     0,   201,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   162,   163,
     164,   165,   166,   167,     0,   168,   169,     0,     0,   170,
       0,     0,     0,   171,   172,   173,   174,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   175,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,     0,     0,   186,     0,     0,     0,
       0,     0,     0,   187,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   143,   144,   145,   194,   195,   196,   197,   150,   151,
     152,     0,     0,     0,     0,     0,   153,   154,   155,   156,
     198,   199,   200,   160,     0,     0,   201,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   162,   163,   164,   165,
     166,   167,     0,   168,   169,     0,     0,   170,     0,     0,
       0,   171,   172,   173,   174,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   175,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,     0,     0,   186,     0,     0,     0,     0,     0,
       0,   187,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,     0,   143,
     144,   145,   194,   195,   196,   197,   150,   151,   152,     0,
       0,     0,     0,     0,   153,   154,   155,   156,   198,   199,
     200,   160,     0,     0,   201,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,     0,   186,     5,     6,     7,     0,     9,     0,   187,
       0,    10,    11,     0,     0,     0,    12,     0,    13,    14,
      15,    99,   100,    18,    19,     0,     0,     0,     0,     0,
     101,   102,   103,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,   109,    49,
       0,    50,    51,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,     0,     0,     0,
      12,   110,    13,    14,    15,    99,   100,    18,    19,   276,
       0,     0,     0,     0,   101,   102,   103,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   275,
       0,     0,   109,    49,     0,    50,    51,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,     0,     0,     0,    12,   110,    13,    14,    15,    16,
      17,    18,    19,   504,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    47,     0,     0,    48,    49,     0,    50,
      51,     0,    52,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,    60,
      61,    62,    12,     0,    13,    14,    15,    99,   100,    18,
      19,     0,     0,     0,     0,     0,   101,    21,    22,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,   233,    40,    41,     0,    42,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,   109,    49,     0,    50,    51,     0,
     234,   235,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,    60,   236,    62,
      12,     0,    13,    14,    15,    99,   100,    18,    19,     0,
       0,     0,     0,     0,   101,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,   233,    40,    41,     0,    42,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,   109,   415,     0,    50,    51,     0,   234,   235,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    60,   236,    62,    12,     0,
      13,    14,    15,    99,   100,    18,    19,     0,     0,     0,
       0,     0,   101,   102,   103,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,   233,
      40,    41,     0,    42,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,     0,     0,
     109,    49,     0,    50,    51,     0,   607,   235,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,    10,    11,    60,   236,    62,    12,     0,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    29,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,   233,    40,    41,
       0,    42,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,     0,   109,    49,
       0,    50,    51,     0,     0,   235,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,    60,    61,    62,    12,     0,    13,    14,    15,    99,
     100,    18,    19,     0,     0,     0,     0,     0,   101,   102,
     103,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,   233,    40,    41,     0,    42,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,   109,    49,     0,    50,
      51,     0,   234,   235,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,    60,
     236,    62,    12,     0,    13,    14,    15,    99,   100,    18,
      19,     0,     0,     0,     0,     0,   101,   102,   103,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,   233,    40,    41,     0,    42,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,   109,    49,     0,    50,    51,     0,
     234,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,    60,   236,    62,
      12,     0,    13,    14,    15,    99,   100,    18,    19,     0,
       0,     0,     0,     0,   101,   102,   103,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,   233,    40,    41,     0,    42,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,   109,    49,     0,    50,    51,     0,     0,   235,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    60,   236,    62,    12,     0,
      13,    14,    15,    99,   100,    18,    19,     0,     0,     0,
       0,     0,   101,   102,   103,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,   233,
      40,    41,     0,    42,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,     0,     0,
     109,    49,     0,    50,    51,     0,   607,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,    10,    11,    60,   236,    62,    12,     0,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,     0,
      20,    21,    22,    23,    24,    25,    26,     0,     0,    27,
       0,     0,     0,     0,     0,     0,    29,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,     0,   109,    49,
       0,    50,    51,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,    60,    61,    62,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,   109,    49,     0,    50,
      51,     0,   498,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,    60,
     236,    62,    12,     0,    13,    14,    15,    99,   100,    18,
      19,     0,     0,     0,     0,     0,   101,   102,   103,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,     0,    42,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,   109,    49,     0,    50,    51,     0,
     234,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,    60,   236,    62,
      12,     0,    13,    14,    15,    99,   100,    18,    19,     0,
       0,     0,     0,     0,   101,   102,   103,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,   233,    40,    41,     0,    42,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,   109,    49,     0,    50,    51,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    60,   236,    62,    12,     0,
      13,    14,    15,    99,   100,    18,    19,     0,     0,     0,
       0,     0,   101,   102,   103,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,     0,    42,    43,    44,     0,    45,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   209,     0,     0,
     109,    49,     0,    50,    51,     0,   607,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,    10,    11,    60,   236,    62,    12,     0,    13,    14,
      15,    99,   100,    18,    19,     0,     0,     0,     0,     0,
     101,   102,   103,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,    45,    46,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   209,     0,     0,   109,    49,
       0,    50,    51,     0,   498,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,    60,   236,    62,    12,     0,    13,    14,    15,    99,
     100,    18,    19,     0,     0,     0,     0,     0,   101,   102,
     103,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,    45,    46,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   209,     0,     0,   109,    49,     0,    50,
      51,     0,   770,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,    60,
     236,    62,    12,     0,    13,    14,    15,    99,   100,    18,
      19,     0,     0,     0,     0,     0,   101,   102,   103,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    29,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,     0,    42,    43,    44,
       0,    45,    46,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   209,     0,     0,   109,    49,     0,    50,    51,     0,
       0,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,    60,   236,    62,
      12,     0,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,     0,     0,    20,    21,    22,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      29,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,     0,    40,    41,     0,    42,    43,    44,     0,    45,
      46,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   209,
       0,     0,   109,    49,     0,    50,    51,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,    60,   236,    62,    12,     0,
      13,    14,    15,    99,   100,    18,    19,     0,     0,     0,
       0,     0,   101,   102,   103,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,    32,    33,   105,    35,    36,    37,   106,    39,     0,
      40,    41,     0,    42,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   107,     0,     0,   108,     0,     0,
     109,    49,     0,    50,    51,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,     0,
       0,     0,    12,   110,    13,    14,    15,    99,   100,    18,
      19,     0,     0,     0,     0,     0,   101,   102,   103,    23,
      24,    25,    26,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   104,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,     0,    40,    41,     0,    42,    43,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   226,     0,     0,    48,    49,     0,    50,    51,     0,
      52,     0,    53,    54,    55,    56,    57,    58,    59,     0,
       0,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,    10,    11,     0,     0,     0,    12,   110,    13,    14,
      15,    99,   100,    18,    19,     0,     0,     0,     0,     0,
     101,   102,   103,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   104,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,     0,    40,    41,
       0,    42,    43,    44,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   275,     0,     0,   314,    49,
       0,    50,    51,     0,   315,     0,    53,    54,    55,    56,
      57,    58,    59,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,     0,     0,     0,
      12,   110,    13,    14,    15,    99,   100,    18,    19,     0,
       0,     0,     0,     0,   101,   102,   103,    23,    24,    25,
      26,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,     0,     0,    32,    33,   105,    35,    36,    37,   106,
      39,     0,    40,    41,     0,    42,    43,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   108,
       0,     0,   109,    49,     0,    50,    51,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,     0,     0,     0,
       0,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,     0,    12,   110,    13,    14,    15,    99,
     100,    18,    19,     0,     0,     0,     0,     0,   101,   102,
     103,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   104,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,     0,    40,    41,     0,    42,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   275,     0,     0,   314,    49,     0,    50,
      51,     0,     0,     0,    53,    54,    55,    56,    57,    58,
      59,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,     0,     0,     0,    12,   110,
      13,    14,    15,    99,   100,    18,    19,     0,     0,     0,
       0,     0,   101,   102,   103,    23,    24,    25,    26,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   104,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,     0,
      40,    41,     0,    42,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   847,     0,     0,
     109,    49,     0,    50,    51,     0,     0,     0,    53,    54,
      55,    56,    57,    58,    59,     0,     0,     0,     0,     0,
     537,   538,     0,     0,   539,     0,     0,     0,     0,     0,
       0,     0,     0,   110,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     545,   546,   186,     0,   547,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     567,   538,   186,     0,   568,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     551,   546,   186,     0,   552,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     587,   538,   186,     0,   588,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     590,   546,   186,     0,   591,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     600,   538,   186,     0,   601,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     603,   546,   186,     0,   604,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     634,   538,   186,     0,   635,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     637,   546,   186,     0,   638,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     906,   538,   186,     0,   907,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     909,   546,   186,     0,   910,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     551,   546,   186,     0,   552,     0,     0,     0,     0,   187,
     250,     0,     0,     0,   162,   163,   164,   165,   166,   167,
       0,   168,   169,     0,     0,   170,     0,     0,     0,   171,
     172,   173,   174,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,     0,   186,     0,     0,     0,     0,     0,     0,   187,
     318,   319,   320,   321,   322,   323,   324,   325,   326,   327,
     328,   329,   330,     0,     0,   331,   332,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   333,     0,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,     0,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,     0,   256,
     331,   332,     0,     0,     0,  -224,   318,   319,   320,   321,
     322,   323,   324,   325,     0,   327,   328,     0,     0,     0,
       0,   331,   332,     0,     0,     0,     0,   333,     0,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,     0,
       0,     0,     0,     0,     0,     0,     0,  -224,     0,     0,
     334,   335,   336,   337,   338,   339,   340,   341,   342,   343,
     318,  -540,  -540,  -540,  -540,   323,   324,     0,     0,  -540,
    -540,     0,     0,     0,     0,   331,   332,   318,   319,   320,
     321,   322,   323,   324,     0,     0,   327,   328,     0,     0,
       0,     0,   331,   332,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,     0,     0,     0,     0,     0,     0,
       0,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343
};

static const short int yycheck[] =
{
       2,   282,     4,     5,     6,   282,    29,     8,    10,    11,
      12,     5,     6,    15,    16,    17,    61,     7,    20,    73,
     217,    15,    50,    51,     8,    27,   397,    28,   317,   392,
      16,    17,   282,    12,    20,    28,     4,   650,    11,    12,
     407,    22,    27,   410,    28,   571,    48,    49,   415,   345,
      52,   504,    50,    51,     7,     8,   108,    52,    52,    61,
      64,   372,   582,   589,    54,   243,   269,    13,   271,    26,
     273,    73,   592,   289,   370,    28,   602,   293,     1,    73,
      22,   104,    25,   647,    29,    64,   650,   555,   556,    51,
      25,   387,   831,   374,    13,    15,    26,   374,    37,    38,
     640,    54,   653,    51,   400,   107,    75,   109,    13,   410,
     636,    13,    13,     0,   344,    96,   346,   347,   348,    13,
     108,    53,   103,    86,   664,    86,   136,   134,    48,   136,
      62,    63,    25,   112,   873,    87,   117,    86,   439,    25,
      25,   371,    16,    17,   113,   108,    20,   108,   136,   134,
      25,   136,     2,   449,    96,     2,   386,     4,   388,   108,
      60,   106,   901,    10,    11,    12,    25,   129,   125,    16,
      17,   401,    25,    20,   131,   125,    25,   129,    55,   460,
      27,   129,   921,   460,    51,   131,   129,    86,   134,   112,
     136,    10,    11,    12,   129,   125,   131,   136,    48,   135,
     430,    48,    49,   265,   135,   105,   208,   820,    27,   108,
     460,   134,    28,   136,    61,   134,   220,   136,   108,   672,
     450,    88,   224,   225,   129,   693,   766,    26,    95,   134,
      49,   136,   134,   134,   136,   136,   129,   129,   131,    26,
     134,   220,   136,   129,   129,   247,    84,   249,   250,   108,
     108,   224,   225,    25,   129,   566,   820,   259,    98,   109,
     107,   247,   109,   249,   250,   576,   482,   312,   131,   820,
     129,   822,   317,   132,   276,   826,   129,   136,    86,    60,
     129,   129,   276,    84,   129,    84,   806,   131,   107,   127,
     128,   136,   581,   131,   575,    51,    67,    84,   575,    55,
     302,   303,   304,   305,   306,   307,   308,   309,   353,   354,
     312,   129,   314,   315,   312,   317,    55,   369,   136,   317,
     315,   315,   103,   104,   108,   575,   125,   128,   127,   128,
     303,   304,   305,   306,   302,   834,   108,    86,   125,   307,
     127,   128,   893,   345,   131,   116,   117,   118,   119,   120,
     412,   353,   354,    17,   135,   726,   418,   129,   134,   345,
     132,   208,   729,    55,   136,   346,   647,    51,   370,   129,
     372,   373,   434,   247,    86,   249,   136,   224,   225,   407,
      84,   383,   908,    84,   370,   387,   365,   415,    87,   391,
     371,   344,   446,   447,   314,   393,   108,   594,   400,   898,
     247,   387,   249,   250,    88,   224,   225,   388,   436,   259,
      94,    95,   259,   415,   400,    86,   369,   396,   397,   918,
     401,    25,    84,   424,   128,   427,   629,   128,   927,   129,
      67,   424,   610,   386,   933,   129,    51,   108,    58,    59,
     424,   503,   620,   806,   446,   447,   399,   449,    60,   430,
     504,   131,   446,   447,    67,   302,   303,   304,   305,   306,
     307,   308,   309,   449,   314,   312,   128,   314,   678,   450,
     317,   424,    51,    88,   125,   685,   429,    86,   789,    94,
      95,   118,   119,   120,   303,   304,   305,   306,    84,   308,
     309,   103,   104,   105,   861,   448,    37,    38,   345,   108,
     132,    84,   504,   526,    58,    59,   353,   354,    84,    88,
     504,    84,   574,   794,    84,    94,    95,   794,    26,   134,
     129,   544,   133,   370,   644,   372,   373,    86,    14,    15,
      55,   127,   128,   383,   126,   846,   383,   105,    60,   129,
     387,   391,    64,   824,   391,   128,    26,   105,   571,   108,
      84,   127,   128,   400,   373,   128,   618,   466,   128,   468,
      15,   542,    17,   565,   566,    67,   589,    67,   415,   550,
     129,    60,   553,   554,   576,    93,    84,   427,   579,   602,
     427,   103,   104,   581,   563,    84,   579,   129,   578,   570,
     886,   572,   565,   127,   128,   579,   415,    84,   577,   796,
     542,    10,   449,   605,    84,   802,    84,     8,   550,    84,
      13,   553,   554,   636,   103,   104,   105,   125,   672,   127,
     128,   623,    84,   131,    10,   578,   579,   132,   127,   128,
     675,    60,   605,   811,   812,   126,   681,   682,   700,   641,
     642,   128,   762,   763,    60,   125,    84,   127,   128,   127,
     128,   131,   127,   128,   656,   553,   554,   887,    40,    41,
      42,    43,    44,    16,    17,   127,   128,    20,   730,   129,
     672,   733,   108,   675,   103,   104,   105,   739,   672,   681,
     682,    51,   736,    53,    54,    55,    56,   103,   104,   105,
     128,   134,    45,    46,    84,   129,    51,    50,    51,   819,
      51,   729,    53,    54,    55,    56,    84,   709,    61,    62,
     712,   129,    84,   891,    51,    51,   695,   129,   565,   566,
     722,   723,   724,    51,    94,    95,    84,   135,    84,   576,
     129,   729,   129,    88,   736,   780,   129,   127,   128,   712,
      95,    10,   736,    10,    95,   115,   565,   726,   118,   127,
     128,   871,    88,    15,   874,   875,   128,   126,   605,    95,
      51,   131,   129,    51,   115,   129,    51,   769,   830,   127,
     128,   127,   128,    67,    56,    57,   623,   110,   780,   899,
      10,   133,    10,    87,   786,   787,   605,   789,    82,    83,
       9,   641,   642,   795,   641,   642,   916,   799,    10,   919,
      88,   795,    51,    88,   623,   925,   656,    95,   928,   656,
      95,   931,    51,    10,    86,   935,    51,    10,    86,   113,
     114,   115,   116,   117,   118,   119,   120,   126,   675,   129,
     126,   129,   129,   861,   681,   682,   108,   746,   747,    88,
     108,   750,   844,   752,   846,   754,    95,   113,   129,    88,
     852,   129,   854,    88,   129,   129,    95,   129,   860,   709,
      95,   129,   709,    67,    10,   712,    50,    51,    10,   129,
     129,   113,   722,   723,   724,   722,   723,   724,    82,    83,
     233,   234,   235,   236,   886,   908,    51,    10,    53,    54,
      55,    56,   129,   712,   247,    86,   249,   250,    86,    10,
     886,   126,    10,    55,    10,   129,   887,   129,   126,    10,
     276,   115,   116,   117,   118,   119,   120,   108,   129,   769,
     108,   129,   769,   129,   129,    53,    54,     6,    56,    94,
      95,   889,   885,   780,    62,    63,   786,   787,   129,   786,
     787,   129,   789,    80,   761,    83,     7,   888,   794,   799,
     115,   647,   799,   118,    64,    -1,   865,   866,   867,   312,
     869,    -1,    -1,    -1,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,    -1,   345,    67,   844,    -1,    -1,   844,    -1,   846,
     353,   354,   852,    -1,   854,   852,   915,   854,    82,    83,
     860,    -1,    -1,   860,    -1,    -1,    -1,   370,    -1,    -1,
      51,    -1,    53,    54,    55,    56,    -1,    -1,    -1,    -1,
      -1,    -1,   385,    -1,   387,    -1,   389,   390,    -1,   886,
     393,    -1,   116,   117,   118,   119,   120,   400,    -1,    -1,
      -1,    -1,    -1,   406,   407,    -1,    -1,   410,   242,   243,
      -1,    -1,   415,    94,    95,    -1,   250,    -1,    -1,    -1,
      -1,    -1,    -1,   426,    -1,    -1,    -1,    -1,   431,    -1,
      -1,    -1,    -1,   436,   115,    -1,   439,   118,   441,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,    -1,
     131,    -1,    -1,    -1,    -1,    -1,     2,    -1,     4,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     2,
      -1,     4,     5,     6,   487,   488,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    -1,    -1,   498,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,   345,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    -1,    73,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,   370,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   380,    -1,    -1,    -1,
      73,    -1,    -1,   387,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,   400,     2,    -1,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,
      15,    -1,    -1,    -1,    -1,    -1,   109,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     2,    -1,
       4,    -1,    -1,    -1,   607,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    48,    -1,   449,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,   462,    -1,
     464,    -1,   466,    -1,   468,    -1,   639,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,    -1,
      82,    83,   208,   497,    -1,    -1,   669,    -1,    -1,    -1,
     673,    -1,   675,   676,   109,    -1,    -1,    -1,   681,   682,
      -1,    -1,    -1,    -1,    -1,   208,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   109,    -1,   129,    -1,    -1,
      -1,    -1,   715,   259,   717,   718,   550,    -1,   721,   553,
     554,   555,   556,    -1,    -1,    -1,   729,    -1,    -1,    -1,
     276,    -1,    -1,    -1,    -1,    -1,   259,    -1,   572,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,   582,    -1,
     584,    -1,    -1,   276,    -1,    -1,   302,    -1,   592,    -1,
      -1,   307,    -1,    -1,    -1,    -1,    -1,   770,   314,   315,
      -1,   774,    -1,   208,    -1,    -1,   610,   780,    -1,   302,
      -1,    -1,    -1,    -1,   307,    -1,   620,    -1,    -1,    -1,
      -1,   314,   315,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   804,    -1,    -1,   208,    -1,   640,    -1,    -1,   233,
     234,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   259,    -1,   372,    -1,    -1,    -1,
     664,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   391,    -1,    -1,    -1,   372,
      -1,    -1,    -1,    -1,    -1,   259,    -1,    -1,   861,   693,
     383,    -1,    -1,    -1,    -1,    -1,    -1,   302,   391,    -1,
      -1,    -1,   307,   707,    -1,    -1,   710,    -1,    -1,   314,
      -1,   427,    -1,   886,    -1,    -1,    -1,    -1,   312,    -1,
      -1,    -1,    -1,   317,    -1,    -1,    -1,    -1,   302,    -1,
     446,   447,    -1,   307,   427,    -1,    -1,    -1,    -1,    -1,
     314,    -1,   746,   747,    -1,    -1,   750,    -1,   752,    -1,
     754,    -1,    -1,   446,   447,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   766,    -1,    -1,    -1,    -1,   372,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   391,    -1,   504,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   372,   393,
      -1,    -1,   806,    -1,    -1,    -1,    -1,   811,   812,   383,
      -1,   504,   406,   407,    -1,    -1,   410,   391,    -1,    -1,
      -1,   415,   427,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   436,    -1,    -1,   439,    -1,   441,    -1,    -1,
     566,    -1,    -1,   427,    -1,    -1,    -1,    -1,    -1,    -1,
     576,   865,   866,   867,    -1,   869,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   566,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   886,   576,   888,   889,    -1,   891,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   498,    -1,    -1,    -1,    -1,    -1,
      -1,   915,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   641,   642,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     656,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,   642,
      -1,    -1,    -1,    -1,    -1,    -1,   672,    -1,    -1,    -1,
      -1,   566,    -1,   656,   657,    -1,    -1,    -1,    -1,    -1,
      -1,   576,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   672,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   581,    -1,    -1,
      -1,    -1,   566,   709,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   576,    -1,    -1,    -1,   722,   723,   724,    -1,
      -1,    -1,    -1,   607,    -1,    -1,   709,    -1,    -1,    -1,
     736,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   722,
     723,   724,    -1,    -1,    -1,    -1,   641,   642,    -1,    -1,
      -1,    -1,    -1,   736,    -1,   639,    -1,    -1,    -1,    -1,
      -1,   656,    -1,   769,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   641,   642,    -1,
     786,   787,    -1,   789,    -1,   669,   769,    -1,    -1,   795,
      -1,    -1,   656,   799,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   786,   787,    -1,   789,    -1,    -1,    -1,
      -1,    -1,   795,    -1,   709,    -1,   799,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   722,   723,   724,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   721,   844,    -1,
     846,    -1,    -1,    -1,    -1,   709,   852,    -1,   854,    -1,
      -1,    -1,    -1,    -1,   860,    -1,    -1,    -1,   722,   723,
     724,   844,    -1,   846,    -1,    -1,    -1,    -1,    -1,   852,
      -1,   854,    -1,    -1,   769,    -1,    -1,   860,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   770,    -1,    -1,    -1,
      -1,   786,   787,    -1,   789,    -1,    -1,    -1,    -1,    -1,
     795,    -1,    -1,    -1,   799,   769,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   786,   787,    -1,   789,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   799,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   844,
      -1,   846,    -1,    -1,    -1,    -1,    -1,   852,    -1,   854,
      -1,    -1,    -1,    -1,    -1,   860,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   861,    -1,    -1,
     844,    -1,   846,    -1,    -1,    -1,    -1,    -1,   852,    -1,
     854,    -1,    -1,    -1,     0,     1,   860,     3,     4,     5,
       6,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    94,    -1,
      96,    97,    98,    99,   100,   101,   102,     0,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    17,   121,   122,   123,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,   134,    -1,
     136,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,   109,
      93,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,   106,    -1,    -1,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,     0,    -1,   132,
     133,   134,    -1,   136,    -1,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      -1,    -1,    82,    83,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    -1,    -1,    87,    -1,    -1,    -1,    -1,    -1,
      93,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,     0,   131,   132,
     133,   134,    -1,   136,    -1,     8,     9,    10,    -1,    -1,
      -1,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    -1,    86,   109,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,   125,   126,   127,   128,   129,     0,    -1,   132,
      -1,   134,    -1,   136,    -1,     8,     9,    10,    -1,     0,
      -1,    14,    15,    -1,    17,    -1,    -1,     8,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    27,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    -1,    -1,    82,
      83,    84,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,    -1,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,   127,   128,   129,    -1,    -1,   132,
      -1,   134,    -1,   136,    -1,   126,    -1,   128,    -1,    -1,
     131,   132,    -1,   134,     1,   136,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    -1,    91,    92,    -1,    94,    -1,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,     1,   136,
       3,     4,     5,     6,     7,    -1,    -1,    10,    11,    12,
      -1,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    -1,    58,    59,    -1,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,
      -1,    94,    -1,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   134,     1,   136,     3,     4,     5,     6,     7,    -1,
      -1,    10,    11,    12,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    -1,    91,    92,    -1,    94,    -1,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   134,     1,   136,     3,     4,
       5,     6,     7,    -1,    -1,    10,    11,    12,    -1,    -1,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,    94,
      -1,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,   121,   122,   123,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,   134,
      -1,   136,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    -1,    91,    92,    -1,    94,    -1,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,     1,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,   121,   122,   123,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,   134,    -1,   136,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    58,
      59,    -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,
      89,    -1,    91,    92,    -1,    94,    -1,    96,    97,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   132,    -1,   134,     1,   136,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,    94,
      -1,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,
       1,   136,     3,     4,     5,     6,     7,    -1,    -1,    10,
      11,    12,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    -1,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,
      91,    92,    -1,    94,    -1,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,
     121,   122,   123,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,   134,    -1,   136,    -1,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    62,
      63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,
      -1,    94,    95,    96,    97,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,   121,   122,
     123,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,   136,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,    -1,
      -1,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,   121,   122,   123,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,   134,
      -1,   136,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      -1,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    89,    -1,    91,    92,    -1,    94,    -1,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   134,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,     3,
       4,     5,    -1,     7,    -1,   130,   131,    11,    12,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
      -1,   125,     3,     4,     5,    -1,     7,   131,    -1,    -1,
      11,    12,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    -1,
      61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,
      91,    92,    -1,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     121,   122,   123,    -1,   125,     3,     4,     5,    -1,     7,
     131,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,
      88,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,   122,   123,     3,     4,     5,    -1,
       7,    -1,    -1,   131,    11,    12,    -1,    -1,    -1,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    -1,    61,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    89,    -1,    91,    92,    -1,    94,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   121,   122,   123,     3,     4,     5,
      -1,     7,    -1,    -1,   131,    11,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   121,   122,   123,     3,     4,
       5,    -1,     7,    -1,    -1,   131,    11,    12,    -1,    -1,
      -1,    16,    -1,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,    94,
      95,    96,    97,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,     3,
       4,     5,    -1,     7,    -1,    -1,   131,    11,    12,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   121,   122,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   131,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    67,    68,    69,    70,    -1,    72,    73,    -1,
      -1,    76,    -1,    -1,    -1,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,   130,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,
      67,    68,    69,    70,    -1,    72,    73,    -1,    -1,    76,
      -1,    -1,    -1,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,   123,    -1,    -1,    -1,
      -1,    -1,    -1,   130,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    -1,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    67,    68,
      69,    70,    -1,    72,    73,    -1,    -1,    76,    -1,    -1,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,    -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,
      -1,   130,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,     3,     4,     5,    -1,     7,    -1,   130,
      -1,    11,    12,    -1,    -1,    -1,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      -1,    91,    92,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,   121,    18,    19,    20,    21,    22,    23,    24,   129,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,   121,    18,    19,    20,    21,
      22,    23,    24,   129,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,
      92,    -1,    94,    -1,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,   121,
     122,   123,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      94,    95,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,   121,   122,   123,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   121,   122,   123,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      88,    89,    -1,    91,    92,    -1,    94,    95,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,   121,   122,   123,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      -1,    91,    92,    -1,    -1,    95,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,   121,   122,   123,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,
      92,    -1,    94,    95,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,   121,
     122,   123,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,   121,   122,   123,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   121,   122,   123,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      88,    89,    -1,    91,    92,    -1,    94,    -1,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,   121,   122,   123,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      -1,    91,    92,    -1,    -1,    -1,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,   121,   122,   123,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,
      92,    -1,    94,    -1,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,   121,
     122,   123,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,   121,   122,   123,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   121,   122,   123,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      88,    89,    -1,    91,    92,    -1,    94,    -1,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,   121,   122,   123,    16,    -1,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      -1,    91,    92,    -1,    94,    -1,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,   121,   122,   123,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,
      92,    -1,    94,    -1,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,   121,
     122,   123,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      -1,    -1,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,   121,   122,   123,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,   121,   122,   123,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    85,    -1,    -1,
      88,    89,    -1,    91,    92,    -1,    -1,    -1,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,   121,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    -1,    58,    59,    -1,    61,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    89,    -1,    91,    92,    -1,
      94,    -1,    96,    97,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,   121,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    -1,    58,    59,
      -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    89,
      -1,    91,    92,    -1,    94,    -1,    96,    97,    98,    99,
     100,   101,   102,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,   121,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    58,    59,    -1,    61,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    88,    89,    -1,    91,    92,    -1,    -1,    -1,
      96,    97,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,   121,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    58,    59,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    89,    -1,    91,
      92,    -1,    -1,    -1,    96,    97,    98,    99,   100,   101,
     102,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,   121,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      58,    59,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      88,    89,    -1,    91,    92,    -1,    -1,    -1,    96,    97,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      51,    52,   123,    -1,    55,    -1,    -1,    -1,    -1,   130,
     131,    -1,    -1,    -1,    65,    66,    67,    68,    69,    70,
      -1,    72,    73,    -1,    -1,    76,    -1,    -1,    -1,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,    -1,    -1,    -1,    -1,   130,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    -1,    -1,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    -1,   136,
      82,    83,    -1,    -1,    -1,    87,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,   109,    -1,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
      67,    68,    69,    70,    71,    72,    73,    -1,    -1,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    67,    68,    69,
      70,    71,    72,    73,    -1,    -1,    76,    77,    -1,    -1,
      -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned short int yystos[] =
{
       0,   138,   139,     0,     1,     3,     4,     5,     6,     7,
      11,    12,    16,    18,    19,    20,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      58,    59,    61,    62,    63,    65,    66,    85,    88,    89,
      91,    92,    94,    96,    97,    98,    99,   100,   101,   102,
     121,   122,   123,   141,   142,   143,   146,   148,   149,   153,
     154,   155,   156,   157,   159,   160,   170,   188,   205,   226,
     227,   239,   240,   241,   242,   243,   244,   245,   248,   256,
     258,   259,   260,   261,   262,   263,   283,   294,   143,    21,
      22,    30,    31,    32,    46,    51,    55,    82,    85,    88,
     121,   161,   162,   188,   205,   260,   263,   283,   162,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    45,    46,    47,    48,    49,    50,    51,
      52,    55,    65,    66,    67,    68,    69,    70,    72,    73,
      76,    80,    81,    82,    83,    94,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   123,   130,   131,   163,
     168,   169,   261,   278,    33,    34,    35,    36,    49,    50,
      51,    55,   163,   164,   165,   166,   256,   258,   189,    85,
     146,   147,   160,   205,   260,   262,   263,   147,   134,   136,
     147,   287,   292,   293,   192,   194,    85,   154,   160,   205,
     210,   260,   263,    57,    94,    95,   122,   153,   170,   172,
     177,   184,   186,   281,   282,   177,   177,   131,   179,   180,
     131,   174,   179,   146,    53,   165,   136,   288,   145,   125,
     170,   205,   170,    55,   141,   154,   146,   173,   186,   281,
     294,   186,   280,   281,   294,    85,   129,   159,   205,   260,
     263,   219,   220,    53,    54,    56,   163,   251,   257,   250,
     251,   251,   135,   246,   135,   249,    58,    59,   148,   170,
     170,   287,   293,    40,    41,    42,    43,    44,    37,    38,
      28,   223,   108,   129,    88,    94,   156,   108,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    82,    83,   109,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,    84,   127,   128,    84,   128,    26,
     125,   228,   242,    86,    86,   174,   179,   228,   288,   146,
      51,    55,   161,    58,    59,     1,   112,   264,   292,    84,
     127,   128,   201,   279,   202,    84,   128,   286,   129,   140,
     141,    55,    13,   206,   292,   108,    84,   127,   128,    86,
      86,   206,   287,    17,   233,   134,   147,   147,    55,    84,
     127,   128,    25,   172,   172,   172,    87,   129,   185,   294,
     129,   185,   177,   288,   289,    89,   177,   181,   176,   177,
     294,    53,    62,    63,   144,   131,   171,   125,   141,    84,
     128,    86,   132,   289,   190,   133,   129,   136,   291,   129,
     291,   129,   291,   126,   291,    55,   157,   129,    84,   127,
     128,    51,    53,    54,    55,    56,    94,    95,   115,   118,
     131,   221,   267,   268,   269,   271,   272,   273,   274,   275,
     276,    60,   103,   104,   105,   252,   105,   252,   105,    64,
     105,   105,   247,   252,   105,    60,   105,    67,    67,   143,
     147,   147,   147,   147,   143,   146,   146,   224,    94,   148,
     172,   186,   187,   154,   129,   159,   129,   148,   170,   172,
     187,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   170,   170,   170,    51,    52,    55,
     168,   174,   284,   285,   176,    51,    52,    55,   168,   174,
     284,    51,    55,   284,   284,   231,   229,   148,   170,   148,
     170,    93,   150,   199,   292,   265,   198,    51,    55,   161,
     284,   176,   284,   140,   146,   131,   266,   267,   203,   167,
      10,     8,   235,   294,   141,    13,   170,    51,    55,   176,
      51,    55,   141,   233,   186,    10,    27,   207,   292,   207,
      51,    55,   176,    51,    55,   196,   172,    94,   172,   184,
     281,   172,   282,   289,   132,   170,   172,   178,   182,   184,
     281,   289,   165,   191,   170,   141,   126,   170,   289,   281,
     172,   156,   156,   158,    51,    55,   176,    51,    55,   108,
     267,    29,   106,   222,   134,   216,   294,   129,   277,   294,
     129,   277,    51,   129,   277,    51,   254,   253,   135,   252,
     135,   170,   170,    75,   113,   214,   215,   294,   172,   129,
     289,   158,   129,    44,   288,    86,    86,   174,   179,   288,
     290,    86,    86,   174,   175,   179,   294,   175,   179,   175,
     179,   214,   214,   151,   292,   147,   140,   290,    10,   289,
     267,   140,   292,   163,   165,   172,   187,   236,   294,    15,
     209,   294,    14,   208,   209,    86,   290,    86,    86,   209,
      10,   129,   206,   193,   195,   290,   147,   172,   185,   129,
     183,   289,   185,   146,   126,   291,   129,   290,   172,   216,
     141,   141,    51,   217,   218,   268,   272,   274,   276,   268,
     270,   271,   274,    51,   270,   141,    53,    54,    56,   255,
     263,    88,    94,    95,   211,   212,   213,   216,   218,   225,
      94,   172,   158,   170,   110,   148,   170,   170,   150,   133,
      86,   148,   170,   148,   170,   150,   232,   230,   214,   200,
     292,    10,   289,    10,   204,    87,   237,   294,   141,     9,
     238,   294,   147,    10,    86,    10,   141,   141,   141,   207,
     184,   186,   281,   289,   289,   156,   289,    10,   126,   129,
     129,   277,   129,   277,   129,   277,   129,   277,   277,   126,
     213,   129,   218,   218,   129,   216,   113,   141,   172,   170,
     148,   170,   141,   141,   152,   140,   266,    85,   160,   205,
     260,   263,   206,   141,   206,   209,   233,   234,    10,    10,
     197,   129,   185,   185,   218,   270,   274,   270,   268,   270,
     289,    95,   212,   129,    94,    95,   211,   113,    10,    10,
     126,   141,    10,   140,    55,    84,   127,   128,   141,   141,
     141,   281,   277,   129,   277,   277,   277,   218,   129,    95,
     212,   129,   218,   218,   126,    10,    51,    55,   176,    51,
      55,   235,   208,    10,   185,   270,    95,   218,   129,    95,
     212,   129,   290,   277,   218,    95,   218,   129,    95,   212,
     218,    95,   218,   129,   218,    95,   218
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (0)


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (N)								\
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (0)
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
              (Loc).first_line, (Loc).first_column,	\
              (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (0)

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr,					\
                  Type, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short int *bottom, short int *top)
#else
static void
yy_stack_print (bottom, top)
    short int *bottom;
    short int *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      size_t yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

#endif /* YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);


# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()
    ;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short int yyssa[YYINITDEPTH];
  short int *yyss = yyssa;
  short int *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short int *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short int *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

/* Do appropriate processing given the current state.  */
/* Read a look-ahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to look-ahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 694 "parse.y"
    {
		    /*%%%*/
			lex_state = EXPR_BEG;
			top_local_init();
		    /*%
		        lex_state = EXPR_BEG;
		    %*/
		    ;}
    break;

  case 3:
#line 703 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[0].node) && !compile_for_eval) {
                            /* last expression should not be void */
			    if (nd_type((yyvsp[0].node)) != NODE_BLOCK) void_expr((yyvsp[0].node));
			    else {
				NODE *node = (yyvsp[0].node);
				while (node->nd_next) {
				    node = node->nd_next;
				}
				void_expr(node->nd_head);
			    }
			}
			ruby_eval_tree = block_append(ruby_eval_tree, (yyvsp[0].node));
                        top_local_setup();
                    /*%
                        $$ = $2;
                        parser->result = dispatch1(program, $$);
		    %*/
		    ;}
    break;

  case 4:
#line 729 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = (yyvsp[-3].node);
			if ((yyvsp[-2].node)) {
			    (yyval.node) = NEW_RESCUE((yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node));
			}
			else if ((yyvsp[-1].node)) {
			    rb_warn("else without rescue is useless");
			    (yyval.node) = block_append((yyval.node), (yyvsp[-1].node));
			}
			if ((yyvsp[0].node)) {
			    if ((yyval.node)) {
				(yyval.node) = NEW_ENSURE((yyval.node), (yyvsp[0].node));
			    }
			    else {
				(yyval.node) = block_append((yyvsp[0].node), NEW_NIL());
			    }
			}
			fixpos((yyval.node), (yyvsp[-3].node));
                    /*%
		        $$ = dispatch4(bodystmt,
                                       escape_Qundef($1),
                                       escape_Qundef($2),
                                       escape_Qundef($3),
                                       escape_Qundef($4));
		    %*/
		    ;}
    break;

  case 5:
#line 759 "parse.y"
    {
		    /*%%%*/
			void_stmts((yyvsp[-1].node));
		        (yyval.node) = (yyvsp[-1].node);
		    /*%
		    	$$ = $1;
		    %*/
		    ;}
    break;

  case 7:
#line 778 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = newline_node(remove_begin((yyvsp[0].node)));
		    /*%
			$$ = dispatch2(stmts_add, dispatch0(stmts_new), $1);
		    %*/
		    ;}
    break;

  case 8:
#line 786 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = block_append((yyvsp[-2].node), newline_node(remove_begin((yyvsp[0].node))));
		    /*%
			$$ = dispatch2(stmts_add, $1, $3);
		    %*/
		    ;}
    break;

  case 9:
#line 794 "parse.y"
    {
			(yyval.node) = remove_begin((yyvsp[0].node));
		    ;}
    break;

  case 10:
#line 799 "parse.y"
    {lex_state = EXPR_FNAME;;}
    break;

  case 11:
#line 800 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = NEW_ALIAS((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch2(alias, $2, $4);
		    %*/
		    ;}
    break;

  case 12:
#line 808 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = NEW_VALIAS((yyvsp[-1].id), (yyvsp[0].id));
		    /*%
			$$ = dispatch2(var_alias, $2, $3);
		    %*/
		    ;}
    break;

  case 13:
#line 816 "parse.y"
    {
		    /*%%%*/
			char buf[3];

			sprintf(buf, "$%c", (char)(yyvsp[0].node)->nd_nth);
		        (yyval.node) = NEW_VALIAS((yyvsp[-1].id), rb_intern(buf));
		    /*%
			$$ = dispatch2(var_alias, $2, $3);
		    %*/
		    ;}
    break;

  case 14:
#line 827 "parse.y"
    {
		    /*%%%*/
		        yyerror("can't make alias for the number variables");
		        (yyval.node) = 0;
		    /*%
			$$ = dispatch2(var_alias, $2, $3);
			$$ = dispatch1(alias_error, $$);
		    %*/
		    ;}
    break;

  case 15:
#line 837 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = dispatch1(undef, $2);
		    %*/
		    ;}
    break;

  case 16:
#line 845 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_IF(cond((yyvsp[0].node)), (yyvsp[-2].node), 0);
		        fixpos((yyval.node), (yyvsp[0].node));
			if (cond_negative(&(yyval.node)->nd_cond)) {
		            (yyval.node)->nd_else = (yyval.node)->nd_body;
		            (yyval.node)->nd_body = 0;
			}
		    /*%
			$$ = dispatch2(if_mod, $3, $1);
		    %*/
		    ;}
    break;

  case 17:
#line 858 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_UNLESS(cond((yyvsp[0].node)), (yyvsp[-2].node), 0);
		        fixpos((yyval.node), (yyvsp[0].node));
			if (cond_negative(&(yyval.node)->nd_cond)) {
		            (yyval.node)->nd_body = (yyval.node)->nd_else;
		            (yyval.node)->nd_else = 0;
			}
		    /*%
		    	$$ = dispatch2(unless_mod, $3, $1);
		    %*/
		    ;}
    break;

  case 18:
#line 871 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
			    (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
			}
			else {
			    (yyval.node) = NEW_WHILE(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
			}
			if (cond_negative(&(yyval.node)->nd_cond)) {
			    nd_set_type((yyval.node), NODE_UNTIL);
			}
		    /*%
			$$ = dispatch2(while_mod, $3, $1);
		    %*/
		    ;}
    break;

  case 19:
#line 887 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[-2].node) && nd_type((yyvsp[-2].node)) == NODE_BEGIN) {
			    (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node)->nd_body, 0);
			}
			else {
			    (yyval.node) = NEW_UNTIL(cond((yyvsp[0].node)), (yyvsp[-2].node), 1);
			}
			if (cond_negative(&(yyval.node)->nd_cond)) {
			    nd_set_type((yyval.node), NODE_WHILE);
			}
		    /*%
			$$ = dispatch2(until_mod, $3, $1);
		    %*/
		    ;}
    break;

  case 20:
#line 903 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0,(yyvsp[0].node),0), 0);
		    /*%
			$$ = dispatch2(rescue_mod, $3, $1);
		    %*/
		    ;}
    break;

  case 21:
#line 911 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single) {
			    yyerror("BEGIN in method");
			}
			/* local_push(0); */
		    /*%
			if (in_def || in_single) {
			    yyerror("BEGIN in method");
			}
		    %*/
		    ;}
    break;

  case 22:
#line 924 "parse.y"
    {
		    /*%%%*/
			ruby_eval_tree_begin = block_append(ruby_eval_tree_begin,
							    (yyvsp[-1].node));
			/* NEW_PREEXE($4)); */
		        /* local_pop(); */
		        (yyval.node) = 0;
		    /*%
			$$ = dispatch1(BEGIN, $4);
		    %*/
		    ;}
    break;

  case 23:
#line 936 "parse.y"
    {
			if (in_def || in_single) {
			    rb_warn0("END in method; use at_exit");
			}
		    /*%%%*/
			(yyval.node) = NEW_POSTEXE((yyvsp[-1].node));
		    /*%
		    	$$ = dispatch1(END, $3);
		    %*/
		    ;}
    break;

  case 24:
#line 947 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch2(assign, $1, $3);
		    %*/
		    ;}
    break;

  case 25:
#line 955 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			(yyvsp[-2].node)->nd_value = ((yyvsp[-2].node)->nd_head) ? NEW_TO_ARY((yyvsp[0].node)) : NEW_ARRAY((yyvsp[0].node));
			(yyval.node) = (yyvsp[-2].node);
		    /*%
		    	$$ = dispatch2(massign, $1, $3);
		    %*/
		    ;}
    break;

  case 26:
#line 965 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-2].node)) {
			    ID vid = (yyvsp[-2].node)->nd_vid;
			    if ((yyvsp[-1].id) == tOROP) {
				(yyvsp[-2].node)->nd_value = (yyvsp[0].node);
				(yyval.node) = NEW_OP_ASGN_OR(gettable(vid), (yyvsp[-2].node));
				if (is_asgn_or_id(vid)) {
				    (yyval.node)->nd_aid = vid;
				}
			    }
			    else if ((yyvsp[-1].id) == tANDOP) {
				(yyvsp[-2].node)->nd_value = (yyvsp[0].node);
				(yyval.node) = NEW_OP_ASGN_AND(gettable(vid), (yyvsp[-2].node));
			    }
			    else {
				(yyval.node) = (yyvsp[-2].node);
				(yyval.node)->nd_value = call_op(gettable(vid),(yyvsp[-1].id),1,(yyvsp[0].node));
			    }
			}
			else {
			    (yyval.node) = 0;
			}
		    /*%
		    	$$ = dispatch3(opassign, $1, $2, $3);
		    %*/
		    ;}
    break;

  case 27:
#line 994 "parse.y"
    {
		    /*%%%*/
			NODE *args = (yyvsp[-3].node);

			value_expr((yyvsp[0].node));
			args = arg_concat((yyvsp[0].node), (yyvsp[-3].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN1((yyvsp[-5].node), (yyvsp[-1].id), args);
		        fixpos((yyval.node), (yyvsp[-5].node));
		    /*%
			$$ = dispatch2(aref_field, $1, escape_Qundef($3));
		    	$$ = dispatch3(opassign, $$, $5, $6);
		    %*/
		    ;}
    break;

  case 28:
#line 1014 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN2((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
                        $$ = dispatch3(field, $1, ripper_id2sym('.'), $3);
			$$ = dispatch3(opassign, $$, $4, $5);
		    %*/
		    ;}
    break;

  case 29:
#line 1031 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN2((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
                        $$ = dispatch3(field, $1, ripper_id2sym('.'), $3);
			$$ = dispatch3(opassign, $$, $4, $5);
		    %*/
		    ;}
    break;

  case 30:
#line 1048 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN2((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
                        $$ = dispatch3(field, $1, ripper_intern("::"), $3);
		    	$$ = dispatch3(opassign, $$, $4, $5);
		    %*/
		    ;}
    break;

  case 31:
#line 1065 "parse.y"
    {
		    /*%%%*/
		        rb_backref_error((yyvsp[-2].node));
			(yyval.node) = 0;
		    /*%
                        $$ = dispatch2(assign, dispatch1(var_field, $1), $3);
		    	$$ = dispatch1(assign_error, $$);
		    %*/
		    ;}
    break;

  case 32:
#line 1075 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch2(assign, $1, $3);
		    %*/
		    ;}
    break;

  case 33:
#line 1083 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-2].node)->nd_value = (yyvsp[0].node);
			(yyval.node) = (yyvsp[-2].node);
		    /*%
		    	dispatch2(massign, $1, $3);
		    %*/
		    ;}
    break;

  case 34:
#line 1092 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-2].node)->nd_value = (yyvsp[0].node);
			(yyval.node) = (yyvsp[-2].node);
		    /*%
		    	$$ = dispatch2(massign, $1, $3);
		    %*/
		    ;}
    break;

  case 37:
#line 1105 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch3(binary, $1, ripper_intern("and"), $3);
		    %*/
		    ;}
    break;

  case 38:
#line 1113 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch3(binary, $1, ripper_intern("or"), $3);
		    %*/
		    ;}
    break;

  case 39:
#line 1121 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NOT(cond((yyvsp[0].node)));
		    /*%
		    	$$ = dispatch2(unary, ripper_intern("not"), $2);
		    %*/
		    ;}
    break;

  case 40:
#line 1129 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NOT(cond((yyvsp[0].node)));
		    /*%
		    	$$ = dispatch2(unary, ID2SYM('!'), $2);
		    %*/
		    ;}
    break;

  case 42:
#line 1140 "parse.y"
    {
		    /*%%%*/
			value_expr((yyval.node));
			(yyval.node) = (yyvsp[0].node);
		    /*%
		    	$$ = $1;
		    %*/
		    ;}
    break;

  case 45:
#line 1153 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_RETURN(ret_args((yyvsp[0].node)));
		    /*%
		    	$$ = dispatch1(return, $2);
		    %*/
		    ;}
    break;

  case 46:
#line 1161 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BREAK(ret_args((yyvsp[0].node)));
		    /*%
		    	$$ = dispatch1(break, $2);
		    %*/
		    ;}
    break;

  case 47:
#line 1169 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NEXT(ret_args((yyvsp[0].node)));
		    /*%
		    	$$ = dispatch1(next, $2);
		    %*/
		    ;}
    break;

  case 49:
#line 1180 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch3(call, $1, ripper_id2sym('.'), $3);
                        $$ = method_arg($$, $4);
		    %*/
		    ;}
    break;

  case 50:
#line 1189 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch3(call, $1, ripper_intern("::"), $3);
                        $$ = method_arg($$, $4);
		    %*/
		    ;}
    break;

  case 51:
#line 1200 "parse.y"
    {
		    /*%%%*/
			dyna_push();
			(yyval.num) = ruby_sourceline;
		    /*%
		    %*/
		    ;}
    break;

  case 52:
#line 1207 "parse.y"
    {(yyval.num) = vtable_size(lvtbl->dvars);;}
    break;

  case 53:
#line 1210 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-3].node)->nd_body = block_append((yyvsp[-3].node)->nd_body,
						   dyna_init((yyvsp[-1].node), (yyvsp[-2].num)));
			(yyval.node) = (yyvsp[-3].node);
			nd_set_line((yyval.node), (yyvsp[-4].num));
			dyna_pop();
		    /*%
			$$ = dispatch2(brace_block, escape_Qundef($3), $5);
		    %*/
		    ;}
    break;

  case 54:
#line 1224 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_FCALL((yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[0].node));
		    /*%
		        $$ = dispatch2(command, $1, $2);
		    %*/
		    ;}
    break;

  case 55:
#line 1233 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_FCALL((yyvsp[-2].id), (yyvsp[-1].node));
			block_dup_check((yyvsp[-1].node),(yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-1].node));
		    /*%
		        $$ = dispatch2(command, $1, $2);
                        $$ = dispatch2(iter_block, $$, $3);
		    %*/
		    ;}
    break;

  case 56:
#line 1244 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch4(command_call, $1, ripper_id2sym('.'), $3, $4);
		    %*/
		    ;}
    break;

  case 57:
#line 1253 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
			block_dup_check((yyvsp[-1].node),(yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
			$$ = dispatch4(command_call, $1, ripper_id2sym('.'), $3, $4);
			$$ = dispatch2(iter_block, $$, $5);
		    %*/
		   ;}
    break;

  case 58:
#line 1264 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch4(command_call, $1, ripper_intern("::"), $3, $4);
		    %*/
		    ;}
    break;

  case 59:
#line 1273 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].node));
			block_dup_check((yyvsp[-1].node),(yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
			$$ = dispatch4(command_call, $1, ripper_intern("::"), $3, $4);
                        $$ = dispatch2(iter_block, $$, $5);
		    %*/
		   ;}
    break;

  case 60:
#line 1284 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_SUPER((yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = dispatch1(super, $2);
		    %*/
		    ;}
    break;

  case 61:
#line 1293 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_yield((yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = dispatch1(yield, $2);
		    %*/
		    ;}
    break;

  case 63:
#line 1305 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(NEW_LIST((yyvsp[-1].node)), 0);
		    /*%
			$$ = dispatch1(mlhs_paren, $2);
		    %*/
		    ;}
    break;

  case 64:
#line 1315 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 65:
#line 1323 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(list_append((yyvsp[-1].node),(yyvsp[0].node)), 0);
		    /*%
			$$ = mlhs_add($1, $2);
		    %*/
		    ;}
    break;

  case 66:
#line 1331 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = mlhs_add_star($1, $3);
		    %*/
		    ;}
    break;

  case 67:
#line 1339 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_POSTARG((yyvsp[-2].node),(yyvsp[0].node)));
		    /*%
			$$ = mlhs_add_star($1, $3);
		    %*/
		    ;}
    break;

  case 68:
#line 1347 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-1].node), -1);
		    /*%
			$$ = mlhs_add_star($1, Qnil);
		    %*/
		    ;}
    break;

  case 69:
#line 1355 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-3].node), NEW_POSTARG(-1,(yyvsp[0].node)));
		    /*%
			$$ = mlhs_add_star($1, Qnil);
		    %*/
		    ;}
    break;

  case 70:
#line 1363 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, (yyvsp[0].node));
		    /*%
			$$ = mlhs_add_star(mlhs_new(), $2);
		    %*/
		    ;}
    break;

  case 71:
#line 1371 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyvsp[-2].node),(yyvsp[0].node)));
		    /*%
			$$ = mlhs_add_star(mlhs_new(), $2);
		    %*/
		    ;}
    break;

  case 72:
#line 1379 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, -1);
		    /*%
			$$ = mlhs_add_star(mlhs_new(), Qnil);
		    %*/
		    ;}
    break;

  case 73:
#line 1387 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1,(yyvsp[0].node)));
		    /*%
			$$ = mlhs_add_star(mlhs_new(), Qnil);
		    %*/
		    ;}
    break;

  case 75:
#line 1398 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[-1].node);
		    /*%
			$$ = dispatch1(mlhs_paren, $2);
		    %*/
		    ;}
    break;

  case 76:
#line 1408 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST((yyvsp[-1].node));
		    /*%
			$$ = mlhs_add(mlhs_new(), $1);
		    %*/
		    ;}
    break;

  case 77:
#line 1416 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
		    /*%
			$$ = mlhs_add($1, $2);
		    %*/
		    ;}
    break;

  case 78:
#line 1426 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST((yyvsp[0].node));
		    /*%
			$$ = mlhs_add(mlhs_new(), $1);
		    %*/
		    ;}
    break;

  case 79:
#line 1434 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = mlhs_add($1, $3);
		    %*/
		    ;}
    break;

  case 80:
#line 1444 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = assignable((yyvsp[0].id), 0);
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 81:
#line 1452 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
		    /*%
			$$ = dispatch2(aref_field, $1, escape_Qundef($3));
		    %*/
		    ;}
    break;

  case 82:
#line 1460 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch3(field, $1, ripper_id2sym('.'), $3);
		    %*/
		    ;}
    break;

  case 83:
#line 1468 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch2(constpath_field, $1, $3);
		    %*/
		    ;}
    break;

  case 84:
#line 1476 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch3(field, $1, ripper_id2sym('.'), $3);
		    %*/
		    ;}
    break;

  case 85:
#line 1484 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single)
			    yyerror("dynamic constant assignment");
			(yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
		    /*%
			if (in_def || in_single)
			    yyerror("dynamic constant assignment");
			$$ = dispatch2(constpath_field, $1, $3);
		    %*/
		    ;}
    break;

  case 86:
#line 1496 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single)
			    yyerror("dynamic constant assignment");
			(yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
		    /*%
			$$ = dispatch1(topconst_field, $2);
		    %*/
		    ;}
    break;

  case 87:
#line 1506 "parse.y"
    {
		    /*%%%*/
		        rb_backref_error((yyvsp[0].node));
			(yyval.node) = 0;
		    /*%
			$$ = dispatch1(var_field, $1);
                        $$ = dispatch1(assign_error, $$);
		    %*/
		    ;}
    break;

  case 88:
#line 1518 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = assignable((yyvsp[0].id), 0);
		    /*%
			$$ = dispatch1(var_field, $1);
		    %*/
		    ;}
    break;

  case 89:
#line 1526 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = aryset((yyvsp[-3].node), (yyvsp[-1].node));
		    /*%
			$$ = dispatch2(aref_field, $1, escape_Qundef($3));
		    %*/
		    ;}
    break;

  case 90:
#line 1534 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch3(field, $1, ripper_id2sym('.'), $3);
		    %*/
		    ;}
    break;

  case 91:
#line 1542 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch3(field, $1, ripper_intern("::"), $3);
		    %*/
		    ;}
    break;

  case 92:
#line 1550 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = attrset((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch3(field, $1, ripper_id2sym('.'), $3);
		    %*/
		    ;}
    break;

  case 93:
#line 1558 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single)
			    yyerror("dynamic constant assignment");
			(yyval.node) = NEW_CDECL(0, 0, NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id)));
		    /*%
                        $$ = dispatch2(constpath_field, $1, $3);
			if (in_def || in_single) {
			    $$ = dispatch1(assign_error, $$);
			}
		    %*/
		    ;}
    break;

  case 94:
#line 1571 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single)
			    yyerror("dynamic constant assignment");
			(yyval.node) = NEW_CDECL(0, 0, NEW_COLON3((yyvsp[0].id)));
		    /*%
                        $$ = dispatch1(topconst_field, $2);
			if (in_def || in_single) {
			    $$ = dispatch1(assign_error, $$);
			}
		    %*/
		    ;}
    break;

  case 95:
#line 1584 "parse.y"
    {
		    /*%%%*/
		        rb_backref_error((yyvsp[0].node));
			(yyval.node) = 0;
		    /*%
			$$ = dispatch1(assign_error, $1);
		    %*/
		    ;}
    break;

  case 96:
#line 1595 "parse.y"
    {
		    /*%%%*/
			yyerror("class/module name must be CONSTANT");
		    /*%
			$$ = dispatch1(class_name_error, $1);
		    %*/
		    ;}
    break;

  case 98:
#line 1606 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_COLON3((yyvsp[0].id));
		    /*%
			$$ = dispatch1(topconst_ref, $2);
		    %*/
		    ;}
    break;

  case 99:
#line 1614 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_COLON2(0, (yyval.node));
		    /*%
			$$ = dispatch1(const_ref, $1);
		    %*/
		    ;}
    break;

  case 100:
#line 1622 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch2(constpath_ref, $1, $3);
		    %*/
		    ;}
    break;

  case 104:
#line 1635 "parse.y"
    {
		    /*%%%*/
			lex_state = EXPR_END;
			(yyval.id) = (yyvsp[0].id);
		    /*%
			lex_state = EXPR_END;
			$$ = $1;
		    %*/
		    ;}
    break;

  case 105:
#line 1645 "parse.y"
    {
		    /*%%%*/
			lex_state = EXPR_END;
			(yyval.id) = (yyvsp[0].id);
		    /*%
			lex_state = EXPR_END;
			$$ = $1;
		    %*/
		    ;}
    break;

  case 108:
#line 1661 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
		    /*%
			$$ = dispatch1(symbol_literal, $1);
		    %*/
		    ;}
    break;

  case 110:
#line 1672 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_UNDEF((yyvsp[0].node));
		    /*%
			$$ = rb_ary_new3(1, $1);
		    %*/
		    ;}
    break;

  case 111:
#line 1679 "parse.y"
    {lex_state = EXPR_FNAME;;}
    break;

  case 112:
#line 1680 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = block_append((yyvsp[-3].node), NEW_UNDEF((yyvsp[0].node)));
		    /*%
			rb_ary_push($1, $4);
		    %*/
		    ;}
    break;

  case 113:
#line 1689 "parse.y"
    { ifndef_ripper((yyval.id) = '|'); ;}
    break;

  case 114:
#line 1690 "parse.y"
    { ifndef_ripper((yyval.id) = '^'); ;}
    break;

  case 115:
#line 1691 "parse.y"
    { ifndef_ripper((yyval.id) = '&'); ;}
    break;

  case 116:
#line 1692 "parse.y"
    { ifndef_ripper((yyval.id) = tCMP); ;}
    break;

  case 117:
#line 1693 "parse.y"
    { ifndef_ripper((yyval.id) = tEQ); ;}
    break;

  case 118:
#line 1694 "parse.y"
    { ifndef_ripper((yyval.id) = tEQQ); ;}
    break;

  case 119:
#line 1695 "parse.y"
    { ifndef_ripper((yyval.id) = tMATCH); ;}
    break;

  case 120:
#line 1696 "parse.y"
    { ifndef_ripper((yyval.id) = '>'); ;}
    break;

  case 121:
#line 1697 "parse.y"
    { ifndef_ripper((yyval.id) = tGEQ); ;}
    break;

  case 122:
#line 1698 "parse.y"
    { ifndef_ripper((yyval.id) = '<'); ;}
    break;

  case 123:
#line 1699 "parse.y"
    { ifndef_ripper((yyval.id) = tLEQ); ;}
    break;

  case 124:
#line 1700 "parse.y"
    { ifndef_ripper((yyval.id) = tLSHFT); ;}
    break;

  case 125:
#line 1701 "parse.y"
    { ifndef_ripper((yyval.id) = tRSHFT); ;}
    break;

  case 126:
#line 1702 "parse.y"
    { ifndef_ripper((yyval.id) = '+'); ;}
    break;

  case 127:
#line 1703 "parse.y"
    { ifndef_ripper((yyval.id) = '-'); ;}
    break;

  case 128:
#line 1704 "parse.y"
    { ifndef_ripper((yyval.id) = '*'); ;}
    break;

  case 129:
#line 1705 "parse.y"
    { ifndef_ripper((yyval.id) = '*'); ;}
    break;

  case 130:
#line 1706 "parse.y"
    { ifndef_ripper((yyval.id) = '/'); ;}
    break;

  case 131:
#line 1707 "parse.y"
    { ifndef_ripper((yyval.id) = '%'); ;}
    break;

  case 132:
#line 1708 "parse.y"
    { ifndef_ripper((yyval.id) = tPOW); ;}
    break;

  case 133:
#line 1709 "parse.y"
    { ifndef_ripper((yyval.id) = '~'); ;}
    break;

  case 134:
#line 1710 "parse.y"
    { ifndef_ripper((yyval.id) = tUPLUS); ;}
    break;

  case 135:
#line 1711 "parse.y"
    { ifndef_ripper((yyval.id) = tUMINUS); ;}
    break;

  case 136:
#line 1712 "parse.y"
    { ifndef_ripper((yyval.id) = tAREF); ;}
    break;

  case 137:
#line 1713 "parse.y"
    { ifndef_ripper((yyval.id) = tASET); ;}
    break;

  case 138:
#line 1714 "parse.y"
    { ifndef_ripper((yyval.id) = '`'); ;}
    break;

  case 179:
#line 1731 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = node_assign((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch2(assign, $1, $3);
		    %*/
		    ;}
    break;

  case 180:
#line 1739 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = node_assign((yyvsp[-4].node), NEW_RESCUE((yyvsp[-2].node), NEW_RESBODY(0,(yyvsp[0].node),0), 0));
		    /*%
		    	$$ = dispatch2(assign, $1, dispatch2(rescue_mod,$3,$5));
		    %*/
		    ;}
    break;

  case 181:
#line 1747 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-2].node)) {
			    ID vid = (yyvsp[-2].node)->nd_vid;
			    if ((yyvsp[-1].id) == tOROP) {
				(yyvsp[-2].node)->nd_value = (yyvsp[0].node);
				(yyval.node) = NEW_OP_ASGN_OR(gettable(vid), (yyvsp[-2].node));
				if (is_asgn_or_id(vid)) {
				    (yyval.node)->nd_aid = vid;
				}
			    }
			    else if ((yyvsp[-1].id) == tANDOP) {
				(yyvsp[-2].node)->nd_value = (yyvsp[0].node);
				(yyval.node) = NEW_OP_ASGN_AND(gettable(vid), (yyvsp[-2].node));
			    }
			    else {
				(yyval.node) = (yyvsp[-2].node);
				(yyval.node)->nd_value = call_op(gettable(vid),(yyvsp[-1].id),1,(yyvsp[0].node));
			    }
			}
			else {
			    (yyval.node) = 0;
			}
		    /*%
		    	$$ = dispatch3(opassign, $1, $2, $3);
		    %*/
		    ;}
    break;

  case 182:
#line 1776 "parse.y"
    {
		    /*%%%*/
                        NODE *args;

			value_expr((yyvsp[0].node));
			args = arg_concat((yyvsp[0].node), (yyvsp[-3].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN1((yyvsp[-5].node), (yyvsp[-1].id), args);
		        fixpos((yyval.node), (yyvsp[-5].node));
		    /*%
			$1 = dispatch2(aref_field, $1, escape_Qundef($3));
		    	$$ = dispatch3(opassign, $1, $5, $6);
		    %*/
		    ;}
    break;

  case 183:
#line 1796 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN2((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
			$1 = dispatch3(field, $1, ripper_id2sym('.'), $3);
		    	$$ = dispatch3(opassign, $1, $4, $5);
		    %*/
		    ;}
    break;

  case 184:
#line 1813 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN2((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
			$1 = dispatch3(field, $1, ripper_id2sym('.'), $3);
		    	$$ = dispatch3(opassign, $1, $4, $5);
		    %*/
		    ;}
    break;

  case 185:
#line 1830 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			if ((yyvsp[-1].id) == tOROP) {
			    (yyvsp[-1].id) = 0;
			}
			else if ((yyvsp[-1].id) == tANDOP) {
			    (yyvsp[-1].id) = 1;
			}
			(yyval.node) = NEW_OP_ASGN2((yyvsp[-4].node), (yyvsp[-2].id), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
		    /*%
			$1 = dispatch3(field, $1, ripper_intern("::"), $3);
		    	$$ = dispatch3(opassign, $1, $4, $5);
		    %*/
		    ;}
    break;

  case 186:
#line 1847 "parse.y"
    {
		    /*%%%*/
			yyerror("constant re-assignment");
			(yyval.node) = 0;
		    /*%
			$$ = dispatch2(constpath_field, $1, $3);
			$$ = dispatch3(opassign, $$, $4, $5);
                        $$ = dispatch1(assign_error, $$);
		    %*/
		    ;}
    break;

  case 187:
#line 1858 "parse.y"
    {
		    /*%%%*/
			yyerror("constant re-assignment");
			(yyval.node) = 0;
		    /*%
			$$ = dispatch1(topconst_field, $2);
			$$ = dispatch3(opassign, $$, $3, $4);
                        $$ = dispatch1(assign_error, $$);
		    %*/
		    ;}
    break;

  case 188:
#line 1869 "parse.y"
    {
		    /*%%%*/
		        rb_backref_error((yyvsp[-2].node));
			(yyval.node) = 0;
		    /*%
			$$ = dispatch1(var_field, $1);
			$$ = dispatch3(opassign, $$, $2, $3);
                        $$ = dispatch1(assign_error, $$);
		    %*/
		    ;}
    break;

  case 189:
#line 1880 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[-2].node));
			value_expr((yyvsp[0].node));
			if (nd_type((yyvsp[-2].node)) == NODE_LIT && FIXNUM_P((yyvsp[-2].node)->nd_lit) &&
			    nd_type((yyvsp[0].node)) == NODE_LIT && FIXNUM_P((yyvsp[0].node)->nd_lit)) {
			    (yyvsp[-2].node)->nd_lit = rb_range_new((yyvsp[-2].node)->nd_lit, (yyvsp[0].node)->nd_lit, Qfalse);
			    (yyval.node) = (yyvsp[-2].node);
			}
			else {
			    (yyval.node) = NEW_DOT2((yyvsp[-2].node), (yyvsp[0].node));
			}
		    /*%
			$$ = dispatch2(dot2, $1, $3);
		    %*/
		    ;}
    break;

  case 190:
#line 1897 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[-2].node));
			value_expr((yyvsp[0].node));
			if (nd_type((yyvsp[-2].node)) == NODE_LIT && FIXNUM_P((yyvsp[-2].node)->nd_lit) &&
			    nd_type((yyvsp[0].node)) == NODE_LIT && FIXNUM_P((yyvsp[0].node)->nd_lit)) {
			    (yyvsp[-2].node)->nd_lit = rb_range_new((yyvsp[-2].node)->nd_lit, (yyvsp[0].node)->nd_lit, Qtrue);
			    (yyval.node) = (yyvsp[-2].node);
			}
			else {
			    (yyval.node) = NEW_DOT3((yyvsp[-2].node), (yyvsp[0].node));
			}
		    /*%
			$$ = dispatch2(dot3, $1, $3);
		    %*/
		    ;}
    break;

  case 191:
#line 1914 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '+', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('+'), $3);
		    %*/
		    ;}
    break;

  case 192:
#line 1922 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = call_op((yyvsp[-2].node), '-', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('-'), $3);
		    %*/
		    ;}
    break;

  case 193:
#line 1930 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = call_op((yyvsp[-2].node), '*', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('*'), $3);
		    %*/
		    ;}
    break;

  case 194:
#line 1938 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '/', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('/'), $3);
		    %*/
		    ;}
    break;

  case 195:
#line 1946 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '%', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('%'), $3);
		    %*/
		    ;}
    break;

  case 196:
#line 1954 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tPOW, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("**"), $3);
		    %*/
		    ;}
    break;

  case 197:
#line 1962 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op(call_op((yyvsp[-2].node), tPOW, 1, (yyvsp[0].node)), tUMINUS, 0, 0);
		    /*%
			$$ = dispatch3(binary, $2, ripper_intern("**"), $4);
			$$ = dispatch2(unary, ripper_intern("-@"), $$);
		    %*/
		    ;}
    break;

  case 198:
#line 1971 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op(call_op((yyvsp[-2].node), tPOW, 1, (yyvsp[0].node)), tUMINUS, 0, 0);
		    /*%
			$$ = dispatch3(binary, $2, ripper_intern("**"), $4);
			$$ = dispatch2(unary, ripper_intern("-@"), $$);
		    %*/
		    ;}
    break;

  case 199:
#line 1980 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[0].node) && nd_type((yyvsp[0].node)) == NODE_LIT) {
			    (yyval.node) = (yyvsp[0].node);
			}
			else {
			    (yyval.node) = call_op((yyvsp[0].node), tUPLUS, 0, 0);
			}
		    /*%
			$$ = dispatch2(unary, ripper_intern("+@"), $2);
		    %*/
		    ;}
    break;

  case 200:
#line 1993 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[0].node), tUMINUS, 0, 0);
		    /*%
			$$ = dispatch2(unary, ripper_intern("-@"), $2);
		    %*/
		    ;}
    break;

  case 201:
#line 2001 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = call_op((yyvsp[-2].node), '|', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('!'), $3);
		    %*/
		    ;}
    break;

  case 202:
#line 2009 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '^', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('^'), $3);
		    %*/
		    ;}
    break;

  case 203:
#line 2017 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '&', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('&'), $3);
		    %*/
		    ;}
    break;

  case 204:
#line 2025 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tCMP, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("<=>"), $3);
		    %*/
		    ;}
    break;

  case 205:
#line 2033 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '>', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('>'), $3);
		    %*/
		    ;}
    break;

  case 206:
#line 2041 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tGEQ, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern(">="), $3);
		    %*/
		    ;}
    break;

  case 207:
#line 2049 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), '<', 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ID2SYM('<'), $3);
		    %*/
		    ;}
    break;

  case 208:
#line 2057 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tLEQ, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("<="), $3);
		    %*/
		    ;}
    break;

  case 209:
#line 2065 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tEQ, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("=="), $3);
		    %*/
		    ;}
    break;

  case 210:
#line 2073 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tEQQ, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("==="), $3);
		    %*/
		    ;}
    break;

  case 211:
#line 2081 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NOT(call_op((yyvsp[-2].node), tEQ, 1, (yyvsp[0].node)));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("!="), $3);
		    %*/
		    ;}
    break;

  case 212:
#line 2089 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = match_op((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("=~"), $3);
		    %*/
		    ;}
    break;

  case 213:
#line 2097 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NOT(match_op((yyvsp[-2].node), (yyvsp[0].node)));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("!~"), $3);
		    %*/
		    ;}
    break;

  case 214:
#line 2105 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NOT(cond((yyvsp[0].node)));
		    /*%
			$$ = dispatch2(unary, ID2SYM('!'), $2);
		    %*/
		    ;}
    break;

  case 215:
#line 2113 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[0].node), '~', 0, 0);
		    /*%
			$$ = dispatch2(unary, ID2SYM('~'), $2);
		    %*/
		    ;}
    break;

  case 216:
#line 2121 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tLSHFT, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("<<"), $3);
		    %*/
		    ;}
    break;

  case 217:
#line 2129 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = call_op((yyvsp[-2].node), tRSHFT, 1, (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern(">>"), $3);
		    %*/
		    ;}
    break;

  case 218:
#line 2137 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = logop(NODE_AND, (yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("&&"), $3);
		    %*/
		    ;}
    break;

  case 219:
#line 2145 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = logop(NODE_OR, (yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch3(binary, $1, ripper_intern("||"), $3);
		    %*/
		    ;}
    break;

  case 220:
#line 2152 "parse.y"
    {in_defined = 1;;}
    break;

  case 221:
#line 2153 "parse.y"
    {
		    /*%%%*/
		        in_defined = 0;
			(yyval.node) = NEW_DEFINED((yyvsp[0].node));
		    /*%
		        in_defined = 0;
			$$ = dispatch1(defined, $4);
		    %*/
		    ;}
    break;

  case 222:
#line 2163 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_IF(cond((yyvsp[-5].node)), (yyvsp[-3].node), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-5].node));
		    /*%
			$$ = dispatch3(ifop, $1, $3, $6);
		    %*/
		    ;}
    break;

  case 223:
#line 2172 "parse.y"
    {
			(yyval.node) = (yyvsp[0].node);
		    ;}
    break;

  case 224:
#line 2178 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 226:
#line 2190 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 227:
#line 2194 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
		    /*%
			$$ = arg_add_assocs($1, $3);
		    %*/
		    ;}
    break;

  case 228:
#line 2202 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
		    /*%
			$$ = arg_add_assocs(arg_new(), $1);
		    %*/
		    ;}
    break;

  case 229:
#line 2212 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[-1].node);
		    /*%
			$$ = dispatch1(arg_paren, escape_Qundef($2));
		    %*/
		    ;}
    break;

  case 234:
#line 2230 "parse.y"
    {
		        rb_warn("parenthesize argument(s) for future version");
		    /*%%%*/
			(yyval.node) = NEW_LIST((yyvsp[0].node));
		    /*%
			$$ = arg_add(arg_new(), $1);
		    %*/
		    ;}
    break;

  case 235:
#line 2239 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_blk_pass((yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_optblock($1, $2);
		    %*/
		    ;}
    break;

  case 236:
#line 2247 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
			(yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_assocs(arg_new(), $1);
			$$ = arg_add_optblock($$, $2);
		    %*/
		    ;}
    break;

  case 237:
#line 2257 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_append((yyvsp[-3].node), NEW_HASH((yyvsp[-1].node)));
			(yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_optblock(arg_add_assocs($1, $3), $4);
		    %*/
		    ;}
    break;

  case 239:
#line 2275 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_blk_pass(list_concat(NEW_LIST((yyvsp[-3].node)),(yyvsp[-1].node)), (yyvsp[0].node));
		    /*%
			$$ = arg_add_optblock(arg_prepend($3, $1), $4);
		    %*/
		    ;}
    break;

  case 240:
#line 2283 "parse.y"
    {
		    /*%%%*/
                        (yyval.node) = arg_blk_pass((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_block(arg_add(arg_new(), $1), $3);
		    %*/
                    ;}
    break;

  case 241:
#line 2291 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST(NEW_HASH((yyvsp[-1].node)));
			(yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_optblock(arg_add_assocs(arg_new(), $1), $2);
		    %*/
		    ;}
    break;

  case 242:
#line 2300 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_append(NEW_LIST((yyvsp[-3].node)), NEW_HASH((yyvsp[-1].node)));
			(yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_assocs(arg_add(arg_new(), $1), $3);
			$$ = arg_add_optblock($$, $4);
		    %*/
		    ;}
    break;

  case 243:
#line 2310 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_append(list_concat(NEW_LIST((yyvsp[-5].node)),(yyvsp[-3].node)), NEW_HASH((yyvsp[-1].node)));
			(yyval.node) = arg_blk_pass((yyval.node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_assocs(arg_prepend($3, $1), $5);
			$$ = arg_add_optblock($$, $6);
		    %*/
		    ;}
    break;

  case 245:
#line 2322 "parse.y"
    {
			(yyval.num) = cmdarg_stack;
			CMDARG_PUSH(1);
		    ;}
    break;

  case 246:
#line 2327 "parse.y"
    {
			/* CMDARG_POP() */
		        cmdarg_stack = (yyvsp[-1].num);
			(yyval.node) = (yyvsp[0].node);
		    ;}
    break;

  case 248:
#line 2335 "parse.y"
    {lex_state = EXPR_ENDARG;;}
    break;

  case 249:
#line 2336 "parse.y"
    {
		    /*%%%*/
		        rb_warning("don't put space before argument parentheses");
			(yyval.node) = 0;
		    /*%
			$$ = dispatch1(space, dispatch1(arg_paren, arg_new()));
		    %*/
		    ;}
    break;

  case 250:
#line 2344 "parse.y"
    {lex_state = EXPR_ENDARG;;}
    break;

  case 251:
#line 2345 "parse.y"
    {
		    /*%%%*/
		        rb_warning("don't put space before argument parentheses");
			(yyval.node) = (yyvsp[-2].node);
		    /*%
			$$ = dispatch1(space, dispatch1(arg_paren, $2));
		    %*/
		    ;}
    break;

  case 252:
#line 2356 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PASS((yyvsp[0].node));
		    /*%
			$$ = $2;
		    %*/
		    ;}
    break;

  case 253:
#line 2366 "parse.y"
    {
			(yyval.node) = (yyvsp[0].node);
		    ;}
    break;

  case 255:
#line 2373 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST((yyvsp[0].node));
		    /*%
			$$ = arg_add(arg_new(), $1);
		    %*/
		    ;}
    break;

  case 256:
#line 2381 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_SPLAT((yyvsp[0].node));
		    /*%
			$$ = arg_add_star(arg_new(), $2);
		    %*/
		    ;}
    break;

  case 257:
#line 2389 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = arg_add($1, $3);
		    %*/
		    ;}
    break;

  case 258:
#line 2397 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
		    /*%
			$$ = arg_add_star($1, $4);
		    %*/
		    ;}
    break;

  case 259:
#line 2407 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_append((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = mrhs_add(args2mrhs($1), $3);
		    %*/
		    ;}
    break;

  case 260:
#line 2415 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = arg_concat((yyvsp[-3].node), (yyvsp[0].node));
		    /*%
			$$ = mrhs_add_star(args2mrhs($1), $4);
		    %*/
		    ;}
    break;

  case 261:
#line 2423 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_SPLAT((yyvsp[0].node));
		    /*%
			$$ = mrhs_add_star(mrhs_new(), $2);
		    %*/
		    ;}
    break;

  case 270:
#line 2441 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_FCALL((yyvsp[0].id), 0);
		    /*%
			$$ = method_arg(dispatch1(fcall, $1), arg_new());
		    %*/
		    ;}
    break;

  case 271:
#line 2449 "parse.y"
    {
		    /*%%%*/
			(yyvsp[0].num) = ruby_sourceline;
		    /*%
		    %*/
		    ;}
    break;

  case 272:
#line 2457 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[-1].node) == NULL) {
			    (yyval.node) = NEW_NIL();
			}
			else {
			    if (nd_type((yyvsp[-1].node)) == NODE_RESCUE ||
				nd_type((yyvsp[-1].node)) == NODE_ENSURE)
				nd_set_line((yyvsp[-1].node), (yyvsp[-3].num));
			    (yyval.node) = NEW_BEGIN((yyvsp[-1].node));
			}
			nd_set_line((yyval.node), (yyvsp[-3].num));
		    /*%
			$$ = dispatch1(begin, $3);
		    %*/
		    ;}
    break;

  case 273:
#line 2473 "parse.y"
    {lex_state = EXPR_ENDARG;;}
    break;

  case 274:
#line 2474 "parse.y"
    {
		        rb_warning0("(...) interpreted as grouped expression");
		    /*%%%*/
			(yyval.node) = (yyvsp[-2].node);
		    /*%
			$$ = dispatch1(paren, $2);
		    %*/
		    ;}
    break;

  case 275:
#line 2483 "parse.y"
    {
		    /*%%%*/
			if (!(yyvsp[-1].node)) (yyval.node) = NEW_NIL();
			else (yyval.node) = (yyvsp[-1].node);
		    /*%
			$$ = dispatch1(paren, $2);
		    %*/
		    ;}
    break;

  case 276:
#line 2492 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_COLON2((yyvsp[-2].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch2(constpath_ref, $1, $3);
		    %*/
		    ;}
    break;

  case 277:
#line 2500 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_COLON3((yyvsp[0].id));
		    /*%
			$$ = dispatch1(topconst_ref, $2);
		    %*/
		    ;}
    break;

  case 278:
#line 2508 "parse.y"
    {
		    /*%%%*/
		        if ((yyvsp[-1].node) == 0) {
			    (yyval.node) = NEW_ZARRAY(); /* zero length array*/
			}
			else {
			    (yyval.node) = (yyvsp[-1].node);
			}
		    /*%
			$$ = dispatch1(array, escape_Qundef($2));
		    %*/
		    ;}
    break;

  case 279:
#line 2521 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_HASH((yyvsp[-1].node));
		    /*%
			$$ = dispatch1(hash, escape_Qundef($2));
		    %*/
		    ;}
    break;

  case 280:
#line 2529 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_RETURN(0);
		    /*%
			$$ = dispatch0(return0);
		    %*/
		    ;}
    break;

  case 281:
#line 2537 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_yield((yyvsp[-1].node));
		    /*%
			$$ = dispatch1(yield, dispatch1(paren, $3));
		    %*/
		    ;}
    break;

  case 282:
#line 2545 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_YIELD(0, Qfalse);
		    /*%
			$$ = dispatch1(yield, dispatch1(paren, arg_new()));
		    %*/
		    ;}
    break;

  case 283:
#line 2553 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_YIELD(0, Qfalse);
		    /*%
			$$ = dispatch0(yield0);
		    %*/
		    ;}
    break;

  case 284:
#line 2560 "parse.y"
    {in_defined = 1;;}
    break;

  case 285:
#line 2561 "parse.y"
    {
		    /*%%%*/
		        in_defined = 0;
			(yyval.node) = NEW_DEFINED((yyvsp[-1].node));
		    /*%
		        in_defined = 0;
			$$ = dispatch1(defined, $5);
		    %*/
		    ;}
    break;

  case 286:
#line 2571 "parse.y"
    {
		    /*%%%*/
			(yyvsp[0].node)->nd_iter = NEW_FCALL((yyvsp[-1].id), 0);
			(yyval.node) = (yyvsp[0].node);
			fixpos((yyvsp[0].node)->nd_iter, (yyvsp[0].node));
		    /*%
			$$ = method_arg(dispatch1(fcall, $1), arg_new());
			$$ = dispatch2(iter_block, $$, $2);
		    %*/
		    ;}
    break;

  case 288:
#line 2583 "parse.y"
    {
		    /*%%%*/
			block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
			(yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
			(yyval.node) = (yyvsp[0].node);
		        fixpos((yyval.node), (yyvsp[-1].node));
		    /*%
			$$ = dispatch2(iter_block, $1, $2);
		    %*/
		    ;}
    break;

  case 289:
#line 2594 "parse.y"
    {
			(yyval.node) = (yyvsp[0].node);
		    ;}
    break;

  case 290:
#line 2601 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_IF(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
			if (cond_negative(&(yyval.node)->nd_cond)) {
		            NODE *tmp = (yyval.node)->nd_body;
		            (yyval.node)->nd_body = (yyval.node)->nd_else;
		            (yyval.node)->nd_else = tmp;
			}
		    /*%
			$$ = dispatch3(if, $2, $4, escape_Qundef($5));
		    %*/
		    ;}
    break;

  case 291:
#line 2618 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_UNLESS(cond((yyvsp[-4].node)), (yyvsp[-2].node), (yyvsp[-1].node));
		        fixpos((yyval.node), (yyvsp[-4].node));
			if (cond_negative(&(yyval.node)->nd_cond)) {
		            NODE *tmp = (yyval.node)->nd_body;
		            (yyval.node)->nd_body = (yyval.node)->nd_else;
		            (yyval.node)->nd_else = tmp;
			}
		    /*%
			$$ = dispatch3(unless, $2, $4, escape_Qundef($5));
		    %*/
		    ;}
    break;

  case 292:
#line 2631 "parse.y"
    {COND_PUSH(1);;}
    break;

  case 293:
#line 2631 "parse.y"
    {COND_POP();;}
    break;

  case 294:
#line 2634 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_WHILE(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
		        fixpos((yyval.node), (yyvsp[-4].node));
			if (cond_negative(&(yyval.node)->nd_cond)) {
			    nd_set_type((yyval.node), NODE_UNTIL);
			}
		    /*%
			$$ = dispatch2(while, $3, $6);
		    %*/
		    ;}
    break;

  case 295:
#line 2645 "parse.y"
    {COND_PUSH(1);;}
    break;

  case 296:
#line 2645 "parse.y"
    {COND_POP();;}
    break;

  case 297:
#line 2648 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_UNTIL(cond((yyvsp[-4].node)), (yyvsp[-1].node), 1);
		        fixpos((yyval.node), (yyvsp[-4].node));
			if (cond_negative(&(yyval.node)->nd_cond)) {
			    nd_set_type((yyval.node), NODE_WHILE);
			}
		    /*%
			$$ = dispatch2(until, $3, $6);
		    %*/
		    ;}
    break;

  case 298:
#line 2662 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CASE((yyvsp[-3].node), (yyvsp[-1].node));
		        fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch2(case, $2, $4);
		    %*/
		    ;}
    break;

  case 299:
#line 2671 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CASE(0, (yyvsp[-1].node));
		    /*%
			$$ = dispatch2(case, Qnil, $3);
		    %*/
		    ;}
    break;

  case 300:
#line 2678 "parse.y"
    {COND_PUSH(1);;}
    break;

  case 301:
#line 2678 "parse.y"
    {COND_POP();;}
    break;

  case 302:
#line 2681 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_FOR((yyvsp[-7].node), (yyvsp[-4].node), (yyvsp[-1].node));
		        fixpos((yyval.node), (yyvsp[-7].node));
		    /*%
			$$ = dispatch3(for, $2, $5, $8);
		    %*/
		    ;}
    break;

  case 303:
#line 2690 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single)
			    yyerror("class definition in method body");
			local_push(0);
		        (yyval.num) = ruby_sourceline;
		    /*%
			if (in_def || in_single)
			    yyerror("class definition in method body");
		    %*/
		    ;}
    break;

  case 304:
#line 2703 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = NEW_CLASS((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-3].node));
		        nd_set_line((yyval.node), (yyvsp[-2].num));
		        local_pop();
		    /*%
			$$ = dispatch3(class, $2, $3, $5);
		    %*/
		    ;}
    break;

  case 305:
#line 2713 "parse.y"
    {
		    /*%%%*/
			(yyval.num) = in_def;
		        in_def = 0;
		    /*%
		        in_def = 0;
		    %*/
		    ;}
    break;

  case 306:
#line 2722 "parse.y"
    {
		    /*%%%*/
		        (yyval.num) = in_single;
		        in_single = 0;
			local_push(0);
		    /*%
		        $$ = in_single;
		        in_single = 0;
		    %*/
		    ;}
    break;

  case 307:
#line 2734 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = NEW_SCLASS((yyvsp[-5].node), (yyvsp[-1].node));
		        fixpos((yyval.node), (yyvsp[-5].node));
		        local_pop();
		        in_def = (yyvsp[-4].num);
		        in_single = (yyvsp[-2].num);
		    /*%
			$$ = dispatch2(sclass, $3, $7);
		        in_def = $<val>4;
		        in_single = $<val>6;
		    %*/
		    ;}
    break;

  case 308:
#line 2748 "parse.y"
    {
		    /*%%%*/
			if (in_def || in_single)
			    yyerror("module definition in method body");
			local_push(0);
		        (yyval.num) = ruby_sourceline;
		    /*%
			if (in_def || in_single)
			    yyerror("module definition in method body");
		    %*/
		    ;}
    break;

  case 309:
#line 2761 "parse.y"
    {
		    /*%%%*/
		        (yyval.node) = NEW_MODULE((yyvsp[-3].node), (yyvsp[-1].node));
		        nd_set_line((yyval.node), (yyvsp[-2].num));
		        local_pop();
		    /*%
			$$ = dispatch2(module, $2, $4);
		    %*/
		    ;}
    break;

  case 310:
#line 2771 "parse.y"
    {
		    /*%%%*/
			(yyval.id) = cur_mid;
			cur_mid = (yyvsp[0].id);
			in_def++;
			local_push(0);
		    /*%
			$<id>$ = cur_mid;
			cur_mid = $2;
			in_def++;
		    %*/
		    ;}
    break;

  case 311:
#line 2786 "parse.y"
    {
		    /*%%%*/
			NODE *body = remove_begin((yyvsp[-1].node));
			reduce_nodes(&body);
			(yyval.node) = NEW_DEFN((yyvsp[-4].id), (yyvsp[-2].node), body, NOEX_PRIVATE);
		        fixpos((yyval.node), (yyvsp[-2].node));
		        local_pop();
			in_def--;
			cur_mid = (yyvsp[-3].id);
		    /*%
			$$ = dispatch3(def, $2, $4, $5);
			in_def--;
			cur_mid = $<id>3;
		    %*/
		    ;}
    break;

  case 312:
#line 2801 "parse.y"
    {lex_state = EXPR_FNAME;;}
    break;

  case 313:
#line 2802 "parse.y"
    {
		    /*%%%*/
			in_single++;
			local_push(0);
		        lex_state = EXPR_END; /* force for args */
		    /*%
			in_single++;
		        lex_state = EXPR_END;
		    %*/
		    ;}
    break;

  case 314:
#line 2815 "parse.y"
    {
		    /*%%%*/
			NODE *body = remove_begin((yyvsp[-1].node));
			reduce_nodes(&body);
			(yyval.node) = NEW_DEFS((yyvsp[-7].node), (yyvsp[-4].id), (yyvsp[-2].node), body);
		        fixpos((yyval.node), (yyvsp[-7].node));
		        local_pop();
			in_single--;
		    /*%
			$$ = dispatch5(defs, $2, $3, $5, $7, $8);
			in_single--;
		    %*/
		    ;}
    break;

  case 315:
#line 2829 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BREAK(0);
		    /*%
			$$ = dispatch1(break, arg_new());
		    %*/
		    ;}
    break;

  case 316:
#line 2837 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_NEXT(0);
		    /*%
			$$ = dispatch1(next, arg_new());
		    %*/
		    ;}
    break;

  case 317:
#line 2845 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_REDO();
		    /*%
			$$ = dispatch0(redo);
		    %*/
		    ;}
    break;

  case 318:
#line 2853 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_RETRY();
		    /*%
			$$ = dispatch0(retry);
		    %*/
		    ;}
    break;

  case 319:
#line 2863 "parse.y"
    {
		    /*%%%*/
			value_expr((yyvsp[0].node));
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 326:
#line 2898 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_IF(cond((yyvsp[-3].node)), (yyvsp[-1].node), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch3(elsif, $2, $4, escape_Qundef($5));
		    %*/
		    ;}
    break;

  case 328:
#line 2910 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = dispatch1(else, $2);
		    %*/
		    ;}
    break;

  case 332:
#line 2925 "parse.y"
    {
		    /*%%%*/
			if (nd_type((yyvsp[-1].node)) != NODE_MASGN) {
			    (yyval.node) = NEW_MASGN(NEW_LIST((yyvsp[-1].node)), 0);
			}
			else {
			    (yyval.node) = (yyvsp[-1].node);
			}
		    /*%
			$$ = dispatch1(mlhs_paren, $2);
		    %*/
		    ;}
    break;

  case 333:
#line 2940 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST((yyvsp[0].node));
		    /*%
			$$ = mlhs_add(mlhs_new(), $1);
		    %*/
		    ;}
    break;

  case 334:
#line 2948 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
		    	$$ = mlhs_add($1, $3);
		    %*/
		    ;}
    break;

  case 335:
#line 2958 "parse.y"
    {
		    /*%%%*/
                        if ((yyvsp[0].node)->nd_alen == 1 && nd_type((yyvsp[0].node)->nd_head) != NODE_MASGN) {
			    (yyval.node) = (yyvsp[0].node)->nd_head;
			    rb_gc_force_recycle((VALUE)(yyvsp[0].node));
			}
			else {
			    (yyval.node) = NEW_MASGN((yyvsp[0].node), 0);
			}
		    /*%
			$$ = blockvar_new($1);
		    %*/
		    ;}
    break;

  case 336:
#line 2972 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-1].node), 0);
		    /*%
			$$ = blockvar_new($1);
		    %*/
		    ;}
    break;

  case 337:
#line 2980 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN((yyvsp[-3].node), 0));
		    /*%
			$$ = blockvar_add_block(blockvar_new($1), $4);
		    %*/
		    ;}
    break;

  case 338:
#line 2988 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN((yyvsp[-8].node), NEW_POSTARG((yyvsp[-5].node),(yyvsp[-3].node))));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), $4);
			$$ = blockvar_add_block($$, $9);
		    %*/
		    ;}
    break;

  case 339:
#line 2997 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN((yyvsp[-6].node), (yyvsp[-3].node)));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), $4);
			$$ = blockvar_add_block($$, $7);
		    %*/
		    ;}
    break;

  case 340:
#line 3006 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN((yyvsp[-5].node), -1));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), Qnil);
			$$ = blockvar_add_block($$, $6);
		    %*/
		    ;}
    break;

  case 341:
#line 3015 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN((yyvsp[-7].node), NEW_POSTARG(-1,(yyvsp[-3].node))));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), Qnil);
			$$ = blockvar_add_block($$, $8);
		    %*/
		    ;}
    break;

  case 342:
#line 3024 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-3].node), (yyvsp[0].node));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), $4);
		    %*/
		    ;}
    break;

  case 343:
#line 3032 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-5].node), NEW_POSTARG((yyvsp[-2].node),(yyvsp[0].node)));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), $4);
		    %*/
		    ;}
    break;

  case 344:
#line 3040 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-2].node), -1);
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), Qnil);
		    %*/
		    ;}
    break;

  case 345:
#line 3048 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN((yyvsp[-4].node), NEW_MASGN((yyvsp[-4].node), NEW_POSTARG(-1,(yyvsp[0].node))));
		    /*%
			$$ = blockvar_add_star(blockvar_new($1), Qnil);
		    %*/
		    ;}
    break;

  case 346:
#line 3056 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN(0, (yyvsp[-3].node)));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), $2);
			$$ = blockvar_add_block($$, $5);
		    %*/
		    ;}
    break;

  case 347:
#line 3065 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN(0, -1));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), Qnil);
			$$ = blockvar_add_block($$, $4);
		    %*/
		    ;}
    break;

  case 348:
#line 3074 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, (yyvsp[0].node));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), $2);
		    %*/
		    ;}
    break;

  case 349:
#line 3082 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, NEW_POSTARG((yyvsp[-2].node),(yyvsp[0].node)));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), $2);
		    %*/
		    ;}
    break;

  case 350:
#line 3090 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN(0, NEW_POSTARG((yyvsp[-5].node),(yyvsp[-3].node))));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), Qnil);
			$$ = blockvar_add_block($$, $7);
		    %*/
		    ;}
    break;

  case 351:
#line 3099 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, -1);
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), Qnil);
		    %*/
		    ;}
    break;

  case 352:
#line 3107 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_MASGN(0, NEW_POSTARG(-1,(yyvsp[0].node)));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), Qnil);
		    %*/
		    ;}
    break;

  case 353:
#line 3115 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), NEW_MASGN(0, NEW_POSTARG(-1,(yyvsp[-3].node))));
		    /*%
			$$ = blockvar_add_star(blockvar_new(Qnil), Qnil);
			$$ = blockvar_add_block($$, $6);
		    %*/
		    ;}
    break;

  case 354:
#line 3124 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_BLOCK_PARAM((yyvsp[0].node), (NODE*)1);
		    /*%
			$$ = blockvar_add_block(blockvar_new(Qnil), $2);
		    %*/
		    ;}
    break;

  case 355:
#line 3134 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ITER(0, 0, 0);
		    /*%
		    %*/
		    ;}
    break;

  case 357:
#line 3144 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ITER((NODE*)1, 0, (yyvsp[-1].node));
		    /*%
			$$ = blockvar_new(mlhs_new());
		    %*/
		    ;}
    break;

  case 358:
#line 3152 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ITER((NODE*)1, 0, 0);
		    /*%
			$$ = blockvar_new(mlhs_new());
		    %*/
		    ;}
    break;

  case 359:
#line 3160 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ITER((yyvsp[-2].node), 0, (yyvsp[-1].node));
		    /*%
			$$ = blockvar_new($2);
		    %*/
		    ;}
    break;

  case 361:
#line 3172 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = FIXME;
		    %*/
		    ;}
    break;

  case 362:
#line 3182 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = FIXME;
		    %*/
		    ;}
    break;

  case 363:
#line 3190 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = block_append((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			$$ = FIXME;
		    %*/
		    ;}
    break;

  case 364:
#line 3200 "parse.y"
    {
		    /*%%%*/
                        (yyval.node) = new_bv((yyvsp[0].id), NEW_NIL());
		    /*%
			$$ = FIXME;
		    %*/
		    ;}
    break;

  case 365:
#line 3209 "parse.y"
    {
		    /*%%%*/
			dyna_push();
			(yyval.num) = lpar_beg;
			lpar_beg = ++paren_nest;
		    /*%
		    %*/
		    ;}
    break;

  case 366:
#line 3219 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[-1].node);
			(yyval.node)->nd_body = block_append((yyval.node)->nd_body, (yyvsp[0].node));
			dyna_pop();
			lpar_beg = (yyvsp[-2].num);
		    /*%
			$$ = dispatch2(lambda, $2, $3);
		    %*/
		    ;}
    break;

  case 367:
#line 3232 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LAMBDA((yyvsp[-2].node), (yyvsp[-1].node));
		    /*%
			$$ = dispatch1(paren, $2);
		    %*/
		    ;}
    break;

  case 368:
#line 3240 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LAMBDA((yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 369:
#line 3250 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 370:
#line 3254 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 371:
#line 3260 "parse.y"
    {
		    /*%%%*/
			dyna_push();
			(yyvsp[0].num) = ruby_sourceline;
		    /*% %*/
		    ;}
    break;

  case 372:
#line 3267 "parse.y"
    {
		    /*%%%*/
			(yyval.num) = vtable_size(lvtbl->dvars);
		    /*% %*/
		    ;}
    break;

  case 373:
#line 3274 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-3].node)->nd_body = block_append((yyvsp[-3].node)->nd_body,
						   dyna_init((yyvsp[-1].node), (yyvsp[-2].num)));
			(yyval.node) = (yyvsp[-3].node);
			nd_set_line((yyval.node), (yyvsp[-4].num));
			dyna_pop();
		    /*%
			$$ = dispatch2(do_block, escape_Qundef($3), $5);
		    %*/
		    ;}
    break;

  case 374:
#line 3288 "parse.y"
    {
		    /*%%%*/
			block_dup_check((yyvsp[-1].node)->nd_args, (yyvsp[0].node));
			(yyvsp[0].node)->nd_iter = (yyvsp[-1].node);
			(yyval.node) = (yyvsp[0].node);
		        fixpos((yyval.node), (yyvsp[-1].node));
		    /*%
			$$ = dispatch2(iter_block, $1, $2);
		    %*/
		    ;}
    break;

  case 375:
#line 3299 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		    /*%
			$$ = dispatch3(call, $1, ripper_id2sym('.'), $3);
			$$ = method_optarg($$, $4);
		    %*/
		    ;}
    break;

  case 376:
#line 3308 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		    /*%
			$$ = dispatch3(call, $1, ripper_intern("::"), $3);
			$$ = method_optarg($$, $4);
		    %*/
		    ;}
    break;

  case 377:
#line 3319 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_FCALL((yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[0].node));
		    /*%
		        $$ = method_arg(dispatch1(fcall, $1), $2);
		    %*/
		    ;}
    break;

  case 378:
#line 3328 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch3(call, $1, ripper_id2sym('.'), $3);
			$$ = method_optarg($$, $4);
		    %*/
		    ;}
    break;

  case 379:
#line 3338 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-3].node), (yyvsp[-1].id), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch3(call, $1, ripper_id2sym('.'), $3);
			$$ = method_optarg($$, $4);
		    %*/
		    ;}
    break;

  case 380:
#line 3348 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-2].node), (yyvsp[0].id), 0);
		    /*%
			$$ = dispatch3(call, $1, ripper_intern("::"), $3);
		    %*/
		    ;}
    break;

  case 381:
#line 3356 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-2].node), rb_intern("call"), (yyvsp[0].node));
			fixpos((yyval.node), (yyvsp[-2].node));
		    /*%
			$$ = dispatch3(call, dispatch1(paren, $1),
				       ripper_id2sym('.'), rb_intern("call"));
			$$ = method_optarg($$, $3);
		    %*/
		    ;}
    break;

  case 382:
#line 3367 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CALL((yyvsp[-2].node), rb_intern("call"), (yyvsp[0].node));
			fixpos((yyval.node), (yyvsp[-2].node));
		    /*%
			$$ = dispatch3(call, dispatch1(paren, $1),
				       ripper_id2sym('.'), rb_intern("call"));
			$$ = method_optarg($$, $3);
		    %*/
		    ;}
    break;

  case 383:
#line 3378 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_SUPER((yyvsp[0].node));
		    /*%
			$$ = dispatch1(super, $2);
		    %*/
		    ;}
    break;

  case 384:
#line 3386 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ZSUPER();
		    /*%
			$$ = dispatch0(zsuper);
		    %*/
		    ;}
    break;

  case 385:
#line 3394 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[-3].node) && nd_type((yyvsp[-3].node)) == NODE_SELF)
			    (yyval.node) = NEW_FCALL(tAREF, (yyvsp[-1].node));
			else
			    (yyval.node) = NEW_CALL((yyvsp[-3].node), tAREF, (yyvsp[-1].node));
			fixpos((yyval.node), (yyvsp[-3].node));
		    /*%
			$$ = dispatch2(aref, $1, escape_Qundef($3));
		    %*/
		    ;}
    break;

  case 386:
#line 3408 "parse.y"
    {
		    /*%%%*/
			dyna_push();
			(yyvsp[0].num) = ruby_sourceline;
		    /*% %*/
		    ;}
    break;

  case 387:
#line 3415 "parse.y"
    {
		    /*%%%*/
			(yyval.num) = vtable_size(lvtbl->dvars);
		    /*%
		    %*/
		    ;}
    break;

  case 388:
#line 3422 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-3].node)->nd_body = block_append((yyvsp[-3].node)->nd_body,
						   dyna_init((yyvsp[-1].node), (yyvsp[-2].num)));
			(yyval.node) = (yyvsp[-3].node);
			nd_set_line((yyval.node), (yyvsp[-4].num));
			dyna_pop();
		    /*%
			$$ = dispatch2(brace_block, escape_Qundef($3), $5);
		    %*/
		    ;}
    break;

  case 389:
#line 3434 "parse.y"
    {
		    /*%%%*/
			dyna_push();
			(yyvsp[0].num) = ruby_sourceline;
		    /*% %*/
		    ;}
    break;

  case 390:
#line 3441 "parse.y"
    {
		    /*%%%*/
			(yyval.num) = vtable_size(lvtbl->dvars);
		    /*%
		    %*/
		    ;}
    break;

  case 391:
#line 3448 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-3].node)->nd_body = block_append((yyvsp[-3].node)->nd_body,
						   dyna_init((yyvsp[-1].node), (yyvsp[-2].num)));
			(yyval.node) = (yyvsp[-3].node);
			nd_set_line((yyval.node), (yyvsp[-4].num));
			dyna_pop();
		    /*%
			$$ = dispatch2(do_block, escape_Qundef($3), $5);
		    %*/
		    ;}
    break;

  case 392:
#line 3464 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_WHEN((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch3(when, $2, $4, escape_Qundef($5));
		    %*/
		    ;}
    break;

  case 395:
#line 3480 "parse.y"
    {
		    /*%%%*/
		        if ((yyvsp[-3].node)) {
		            (yyvsp[-3].node) = node_assign((yyvsp[-3].node), NEW_ERRINFO());
			    (yyvsp[-1].node) = block_append((yyvsp[-3].node), (yyvsp[-1].node));
			}
			(yyval.node) = NEW_RESBODY((yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[0].node));
		        fixpos((yyval.node), (yyvsp[-4].node)?(yyvsp[-4].node):(yyvsp[-1].node));
		    /*%
			$$ = dispatch4(rescue,
                                       escape_Qundef($2),
                                       escape_Qundef($3),
                                       escape_Qundef($5),
                                       escape_Qundef($6));
		    %*/
		    ;}
    break;

  case 397:
#line 3500 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIST((yyvsp[0].node));
		    /*%
		    	$$ = rb_ary_new3(1, $1);
		    %*/
		    ;}
    break;

  case 400:
#line 3512 "parse.y"
    {
			(yyval.node) = (yyvsp[0].node);
		    ;}
    break;

  case 402:
#line 3519 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = dispatch1(ensure, $2);
		    %*/
		    ;}
    break;

  case 405:
#line 3531 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_LIT(ID2SYM((yyvsp[0].id)));
		    /*%
			$$ = dispatch1(symbol_literal, $1);
		    %*/
		    ;}
    break;

  case 407:
#line 3542 "parse.y"
    {
		    /*%%%*/
			NODE *node = (yyvsp[0].node);
			if (!node) {
			    node = NEW_STR(rb_str_new(0, 0));
			}
			else {
			    node = evstr2dstr(node);
			}
			(yyval.node) = node;
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 410:
#line 3561 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch2(string_concat, $1, $2);
		    %*/
		    ;}
    break;

  case 411:
#line 3571 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[-1].node);
		    /*%
			$$ = dispatch1(string_literal, $2);
		    %*/
		    ;}
    break;

  case 412:
#line 3581 "parse.y"
    {
		    /*%%%*/
			NODE *node = (yyvsp[-1].node);
			if (!node) {
			    node = NEW_XSTR(rb_str_new(0, 0));
			}
			else {
			    switch (nd_type(node)) {
			      case NODE_STR:
				nd_set_type(node, NODE_XSTR);
				break;
			      case NODE_DSTR:
				nd_set_type(node, NODE_DXSTR);
				break;
			      default:
				node = NEW_NODE(NODE_DXSTR, rb_str_new(0, 0), 1, NEW_LIST(node));
				break;
			    }
			}
			(yyval.node) = node;
		    /*%
			$$ = dispatch1(xstring_literal, $2);
		    %*/
		    ;}
    break;

  case 413:
#line 3608 "parse.y"
    {
		    /*%%%*/
			int options = (yyvsp[0].num);
			NODE *node = (yyvsp[-1].node);
			if (!node) {
			    node = NEW_LIT(rb_reg_compile("", 0, options & ~RE_OPTION_ONCE));
			}
			else switch (nd_type(node)) {
			  case NODE_STR:
			    {
				VALUE src = node->nd_lit;
				nd_set_type(node, NODE_LIT);
				node->nd_lit = rb_reg_compile(RSTRING_PTR(src),
							      RSTRING_LEN(src),
							      options & ~RE_OPTION_ONCE);
			    }
			    break;
			  default:
			    node = NEW_NODE(NODE_DSTR, rb_str_new(0, 0), 1, NEW_LIST(node));
			  case NODE_DSTR:
			    if (options & RE_OPTION_ONCE) {
				nd_set_type(node, NODE_DREGX_ONCE);
			    }
			    else {
				nd_set_type(node, NODE_DREGX);
			    }
			    node->nd_cflag = options & ~RE_OPTION_ONCE;
			    break;
			}
			(yyval.node) = node;
		    /*%
			$$ = dispatch2(regexp_literal, $2, $3);
		    %*/
		    ;}
    break;

  case 414:
#line 3645 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ZARRAY();
		    /*%
			$$ = dispatch0(words_new);
		    %*/
		    ;}
    break;

  case 415:
#line 3653 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 416:
#line 3659 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = 0;
		    /*%
			$$ = dispatch0(words_new);
		    %*/
		    ;}
    break;

  case 417:
#line 3667 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append((yyvsp[-2].node), evstr2dstr((yyvsp[-1].node)));
		    /*%
			$$ = dispatch2(words_add, $1, $2);
		    %*/
		    ;}
    break;

  case 419:
#line 3685 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch2(word_add, $1, $2);
		    %*/
		    ;}
    break;

  case 420:
#line 3695 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ZARRAY();
		    /*%
			$$ = dispatch0(qwords_new);
		    %*/
		    ;}
    break;

  case 421:
#line 3703 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 422:
#line 3709 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = 0;
		    /*%
			$$ = dispatch0(qwords_new);
		    %*/
		    ;}
    break;

  case 423:
#line 3717 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append((yyvsp[-2].node), (yyvsp[-1].node));
		    /*%
			$$ = dispatch2(qwords_add, $1, $2);
		    %*/
		    ;}
    break;

  case 424:
#line 3727 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = 0;
		    /*%
			$$ = dispatch0(string_content);
		    %*/
		    ;}
    break;

  case 425:
#line 3735 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch2(string_add, $1, $2);
		    %*/
		    ;}
    break;

  case 426:
#line 3745 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = 0;
		    /*%
			$$ = dispatch0(xstring_new);
		    %*/
		    ;}
    break;

  case 427:
#line 3753 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = literal_concat((yyvsp[-1].node), (yyvsp[0].node));
		    /*%
			$$ = dispatch2(xstring_add, $1, $2);
		    %*/
		    ;}
    break;

  case 429:
#line 3764 "parse.y"
    {
			(yyval.node) = lex_strterm;
			lex_strterm = 0;
			lex_state = EXPR_BEG;
		    ;}
    break;

  case 430:
#line 3770 "parse.y"
    {
		    /*%%%*/
			lex_strterm = (yyvsp[-1].node);
		        (yyval.node) = NEW_EVSTR((yyvsp[0].node));
		    /*%
			lex_strterm = $<node>2;
			$$ = dispatch1(string_dvar, $3);
		    %*/
		    ;}
    break;

  case 431:
#line 3780 "parse.y"
    {
			(yyval.node) = lex_strterm;
			lex_strterm = 0;
			lex_state = EXPR_BEG;
			COND_PUSH(0);
			CMDARG_PUSH(0);
		    ;}
    break;

  case 432:
#line 3788 "parse.y"
    {
			lex_strterm = (yyvsp[-2].node);
			COND_LEXPOP();
			CMDARG_LEXPOP();
		    /*%%%*/
		        if ((yyvsp[-1].node)) (yyvsp[-1].node)->flags &= ~NODE_NEWLINE;
			(yyval.node) = new_evstr((yyvsp[-1].node));
		    /*%
			$$ = dispatch1(string_embexpr, $3);
		    %*/
		    ;}
    break;

  case 433:
#line 3802 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_GVAR((yyvsp[0].id));
		    /*%
			$$ = dispatch1(var_ref, $1);
		    %*/
		    ;}
    break;

  case 434:
#line 3810 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_IVAR((yyvsp[0].id));
		    /*%
			$$ = dispatch1(var_ref, $1);
		    %*/
		    ;}
    break;

  case 435:
#line 3818 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_CVAR((yyvsp[0].id));
		    /*%
			$$ = dispatch1(var_ref, $1);
		    %*/
		    ;}
    break;

  case 437:
#line 3829 "parse.y"
    {
		    /*%%%*/
		        lex_state = EXPR_END;
			(yyval.id) = (yyvsp[0].id);
		    /*%
		        lex_state = EXPR_END;
			$$ = dispatch1(symbol, $2);
		    %*/
		    ;}
    break;

  case 442:
#line 3847 "parse.y"
    {
		    /*%%%*/
		        lex_state = EXPR_END;
			if (!((yyval.node) = (yyvsp[-1].node))) {
			    yyerror("empty symbol literal");
			}
			else {
			    VALUE lit;

			    switch (nd_type((yyval.node))) {
			      case NODE_DSTR:
				nd_set_type((yyval.node), NODE_DSYM);
				break;
			      case NODE_STR:
				lit = (yyval.node)->nd_lit;
				if (RSTRING_LEN(lit) == 0) {
				    yyerror("empty symbol literal");
				    break;
				}
				if (strlen(RSTRING_PTR(lit)) == RSTRING_LEN(lit)) {
				    (yyval.node)->nd_lit = ID2SYM(rb_intern(RSTRING_PTR((yyval.node)->nd_lit)));
				    nd_set_type((yyval.node), NODE_LIT);
				    break;
				}
				/* fall through */
			      default:
				(yyval.node) = NEW_NODE(NODE_DSYM, rb_str_new(0, 0), 1, NEW_LIST((yyval.node)));
				break;
			    }
			}
		    /*%
		        lex_state = EXPR_END;
			$$ = dispatch1(dyna_symbol, $2);
		    %*/
		    ;}
    break;

  case 445:
#line 3887 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = negate_lit((yyvsp[0].node));
		    /*%
			$$ = dispatch2(unary, ripper_intern("-@"), $2);
		    %*/
		    ;}
    break;

  case 446:
#line 3895 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = negate_lit((yyvsp[0].node));
		    /*%
			$$ = dispatch2(unary, ripper_intern("-@"), $2);
		    %*/
		    ;}
    break;

  case 452:
#line 3909 "parse.y"
    {ifndef_ripper((yyval.id) = keyword_nil);;}
    break;

  case 453:
#line 3910 "parse.y"
    {ifndef_ripper((yyval.id) = keyword_self);;}
    break;

  case 454:
#line 3911 "parse.y"
    {ifndef_ripper((yyval.id) = keyword_true);;}
    break;

  case 455:
#line 3912 "parse.y"
    {ifndef_ripper((yyval.id) = keyword_false);;}
    break;

  case 456:
#line 3913 "parse.y"
    {ifndef_ripper((yyval.id) = keyword__FILE__);;}
    break;

  case 457:
#line 3914 "parse.y"
    {ifndef_ripper((yyval.id) = keyword__LINE__);;}
    break;

  case 458:
#line 3918 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = gettable((yyvsp[0].id));
		    /*%
			$$ = dispatch1(var_ref, $1);
		    %*/
		    ;}
    break;

  case 459:
#line 3928 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = assignable((yyvsp[0].id), 0);
		    /*%
			$$ = dispatch1(var_field, $1);
		    %*/
		    ;}
    break;

  case 462:
#line 3942 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = 0;
		    /*%
			$$ = Qnil;
		    %*/
		    ;}
    break;

  case 463:
#line 3950 "parse.y"
    {
			lex_state = EXPR_BEG;
		    ;}
    break;

  case 464:
#line 3954 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 465:
#line 3958 "parse.y"
    {
		    /*%%%*/
			yyerrok;
			(yyval.node) = 0;
		    /*%
			yyerrok;
			$$ = Qnil;
		    %*/
		    ;}
    break;

  case 466:
#line 3970 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[-1].node);
			lex_state = EXPR_BEG;
		        command_start = Qtrue;
		    /*%
			$$ = dispatch1(paren, $2);
			lex_state = EXPR_BEG;
		        command_start = Qtrue;
		    %*/
		    ;}
    break;

  case 467:
#line 3982 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 468:
#line 3988 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-5].val), (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, $3, $5, Qnil, escape_Qundef($6));
		    %*/
		    ;}
    break;

  case 469:
#line 3996 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-7].val), (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, $3, $5, $7, escape_Qundef($8));
		    %*/
		    ;}
    break;

  case 470:
#line 4004 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-3].val), (yyvsp[-1].node), 0, 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, $3, Qnil, Qnil, escape_Qundef($4));
		    %*/
		    ;}
    break;

  case 471:
#line 4012 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-5].val), (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, $3, Qnil, $5, escape_Qundef($6));
		    %*/
		    ;}
    break;

  case 472:
#line 4020 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-3].val), 0, (yyvsp[-1].id), 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, Qnil, $3, Qnil, escape_Qundef($4));
		    %*/
		    ;}
    break;

  case 473:
#line 4028 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-5].val), 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, Qnil, $3, $5, escape_Qundef($6));
		    %*/
		    ;}
    break;

  case 474:
#line 4036 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args((yyvsp[-1].val), 0, 0, 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, $1, Qnil, Qnil, Qnil, escape_Qundef($2));
		    %*/
		    ;}
    break;

  case 475:
#line 4044 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, (yyvsp[-3].node), (yyvsp[-1].id), 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, $1, $3, Qnil, escape_Qundef($4));
		    %*/
		    ;}
    break;

  case 476:
#line 4052 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, (yyvsp[-5].node), (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, $1, $3, $5, escape_Qundef($6));
		    %*/
		    ;}
    break;

  case 477:
#line 4060 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, (yyvsp[-1].node), 0, 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, $1, Qnil, Qnil, escape_Qundef($2));
		    %*/
		    ;}
    break;

  case 478:
#line 4068 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, (yyvsp[-3].node), 0, (yyvsp[-1].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, $1, Qnil, $3, escape_Qundef($4));
		    %*/
		    ;}
    break;

  case 479:
#line 4076 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, 0, (yyvsp[-1].id), 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, Qnil, $1, Qnil, escape_Qundef($2));
		    %*/
		    ;}
    break;

  case 480:
#line 4084 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, 0, (yyvsp[-3].id), (yyvsp[-1].node), (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, Qnil, $1, $3, escape_Qundef($4));
		    %*/
		    ;}
    break;

  case 481:
#line 4092 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, 0, 0, 0, (yyvsp[0].id));
		    /*%
			$$ = dispatch5(params, Qnil, Qnil, Qnil, Qnil, $1);
		    %*/
		    ;}
    break;

  case 482:
#line 4100 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = new_args(0, 0, 0, 0, 0);
		    /*%
			$$ = dispatch5(params, Qnil, Qnil, Qnil, Qnil, Qnil);
		    %*/
		    ;}
    break;

  case 483:
#line 4110 "parse.y"
    {
		    /*%%%*/
			yyerror("formal argument cannot be a constant");
		    /*%
			$$ = dispatch1(param_error, $1);
		    %*/
		    ;}
    break;

  case 484:
#line 4118 "parse.y"
    {
		    /*%%%*/
                        yyerror("formal argument cannot be an instance variable");
		    /*%
			$$ = dispatch1(param_error, $1);
		    %*/
		    ;}
    break;

  case 485:
#line 4126 "parse.y"
    {
		    /*%%%*/
                        yyerror("formal argument cannot be a global variable");
		    /*%
			$$ = dispatch1(param_error, $1);
		    %*/
		    ;}
    break;

  case 486:
#line 4134 "parse.y"
    {
		    /*%%%*/
                        yyerror("formal argument cannot be a class variable");
		    /*%
			$$ = dispatch1(param_error, $1);
		    %*/
		    ;}
    break;

  case 487:
#line 4142 "parse.y"
    {
		    /*%%%*/
			if (!is_local_id((yyvsp[0].id)))
			    yyerror("formal argument must be local variable");
			shadowing_lvar((yyvsp[0].id));
			(yyval.id) = (yyvsp[0].id);
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 488:
#line 4155 "parse.y"
    {
                    /*%%%*/
		        (yyval.val) = 1;
                    /*%
                        $$ = rb_ary_new();
                    %*/
		    ;}
    break;

  case 489:
#line 4163 "parse.y"
    {
                    /*%%%*/
		        (yyval.val) = (yyvsp[-2].val) + 1;
                    /*%
                        rb_ary_push($$, $3);
                    %*/
		    ;}
    break;

  case 490:
#line 4173 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = NEW_ARGS_AUX((yyvsp[0].id), 1);
		    /*%
			$$ = mlhs_add(mlhs_new(), $1);
		    %*/
		    ;}
    break;

  case 491:
#line 4181 "parse.y"
    {
		    /*%%%*/
			(yyvsp[-2].node)->nd_alen++;
			(yyval.node) = (yyvsp[-2].node);
		    /*%
		        $$ = mlhs_add($1, $3);
		    %*/
		    ;}
    break;

  case 492:
#line 4192 "parse.y"
    {
		    /*%%%*/
			if (!is_local_id((yyvsp[-2].id)))
			    yyerror("formal argument must be local variable");
		        shadowing_lvar((yyvsp[-2].id));
		        (yyval.node) = NEW_OPT_ARG(0, assignable((yyvsp[-2].id), (yyvsp[0].node)));
		    /*%
			$$ = rb_assoc_new($1, $3);
		    %*/
		    ;}
    break;

  case 493:
#line 4205 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = (yyvsp[0].node);
		    /*%
			$$ = rb_ary_new3(1, $1);
		    %*/
		    ;}
    break;

  case 494:
#line 4213 "parse.y"
    {
		    /*%%%*/
			NODE *opts = (yyvsp[-2].node);

			while (opts->nd_next) {
			    opts = opts->nd_next;
			}
			opts->nd_next = (yyvsp[0].node);
			(yyval.node) = (yyvsp[-2].node);
		    /*%
			$$ = rb_ary_push($1, $3);
		    %*/
		    ;}
    break;

  case 497:
#line 4233 "parse.y"
    {
		    /*%%%*/
			if (!is_local_id((yyvsp[0].id)))
			    yyerror("rest argument must be local variable");
		        shadowing_lvar((yyvsp[0].id));
			(yyval.id) = (yyvsp[0].id);
		    /*%
			$$ = dispatch1(restparam, $2);
		    %*/
		    ;}
    break;

  case 498:
#line 4244 "parse.y"
    {
		    /*%%%*/
			if (dyna_in_block()) {
			    (yyval.id) = internal_id();
			}
			else {
			    local_append(0);
			    (yyval.id) = -1;
			}
		    /*%
			$$ = dispatch1(restparam, Qnil);
		    %*/
		    ;}
    break;

  case 501:
#line 4264 "parse.y"
    {
		    /*%%%*/
			if (!is_local_id((yyvsp[0].id)))
			    yyerror("block argument must be local variable");
			else if (!dyna_in_block() && local_id((yyvsp[0].id)))
			    yyerror("duplicated block argument name");
		        shadowing_lvar((yyvsp[0].id));
			(yyval.id) = (yyvsp[0].id);
		    /*%
			$$ = $2;
		    %*/
		    ;}
    break;

  case 502:
#line 4279 "parse.y"
    {
			(yyval.id) = (yyvsp[0].id);
		    ;}
    break;

  case 503:
#line 4283 "parse.y"
    {
                    /*%%%*/
			(yyval.id) = 0;
                    /*%
                        $$ = Qundef;
                    %*/
		    ;}
    break;

  case 504:
#line 4293 "parse.y"
    {
		    /*%%%*/
			    (yyval.node) = (yyvsp[0].node);
		            value_expr((yyval.node));
		    /*%
			$$ = $1;
		    %*/
		    ;}
    break;

  case 505:
#line 4301 "parse.y"
    {lex_state = EXPR_BEG;;}
    break;

  case 506:
#line 4302 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[-1].node) == 0) {
			    yyerror("can't define singleton method for ().");
			}
			else {
			    switch (nd_type((yyvsp[-1].node))) {
			      case NODE_STR:
			      case NODE_DSTR:
			      case NODE_XSTR:
			      case NODE_DXSTR:
			      case NODE_DREGX:
			      case NODE_LIT:
			      case NODE_ARRAY:
			      case NODE_ZARRAY:
				yyerror("can't define singleton method for literals");
			      default:
				value_expr((yyvsp[-1].node));
				break;
			    }
			}
			(yyval.node) = (yyvsp[-1].node);
		    /*%
			$$ = dispatch1(paren, $3);
		    %*/
		    ;}
    break;

  case 508:
#line 4332 "parse.y"
    {
			(yyval.node) = (yyvsp[-1].node);
		    ;}
    break;

  case 509:
#line 4336 "parse.y"
    {
		    /*%%%*/
			if ((yyvsp[-1].node)->nd_alen%2 != 0) {
			    yyerror("odd number list for Hash");
			}
			(yyval.node) = (yyvsp[-1].node);
		    /*%
		    	$$ = dispatch1(assoclist_from_args, $1);
		    %*/
		    ;}
    break;

  case 511:
#line 4356 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_concat((yyvsp[-2].node), (yyvsp[0].node));
		    /*%
			rb_ary_push($$, $3);
		    %*/
		    ;}
    break;

  case 512:
#line 4366 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append(NEW_LIST((yyvsp[-2].node)), (yyvsp[0].node));
		    /*%
			$$ = dispatch2(assoc_new, $1, $3);
		    %*/
		    ;}
    break;

  case 513:
#line 4374 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = list_append(NEW_LIST(NEW_LIT(ID2SYM((yyvsp[-1].id)))), (yyvsp[0].node));
		    /*%
		    	$$ = dispatch2(assoc_new, $1, $2);
		    %*/
		    ;}
    break;

  case 535:
#line 4430 "parse.y"
    {yyerrok;;}
    break;

  case 538:
#line 4435 "parse.y"
    {yyerrok;;}
    break;

  case 539:
#line 4439 "parse.y"
    {
		    /*%%%*/
			(yyval.node) = 0;
		    /*%
		    	$$ = Qundef;
		    %*/
		    ;}
    break;


      default: break;
    }

/* Line 1126 of yacc.c.  */
#line 9055 "parse.c"

  yyvsp -= yylen;
  yyssp -= yylen;


  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  int yytype = YYTRANSLATE (yychar);
	  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
	  YYSIZE_T yysize = yysize0;
	  YYSIZE_T yysize1;
	  int yysize_overflow = 0;
	  char *yymsg = 0;
#	  define YYERROR_VERBOSE_ARGS_MAXIMUM 5
	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
	  int yyx;

#if 0
	  /* This is so xgettext sees the translatable formats that are
	     constructed on the fly.  */
	  YY_("syntax error, unexpected %s");
	  YY_("syntax error, unexpected %s, expecting %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s");
	  YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
#endif
	  char *yyfmt;
	  char const *yyf;
	  static char const yyunexpected[] = "syntax error, unexpected %s";
	  static char const yyexpecting[] = ", expecting %s";
	  static char const yyor[] = " or %s";
	  char yyformat[sizeof yyunexpected
			+ sizeof yyexpecting - 1
			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
			   * (sizeof yyor - 1))];
	  char const *yyprefix = yyexpecting;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 1;

	  yyarg[0] = yytname[yytype];
	  yyfmt = yystpcpy (yyformat, yyunexpected);

	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
		  {
		    yycount = 1;
		    yysize = yysize0;
		    yyformat[sizeof yyunexpected - 1] = '\0';
		    break;
		  }
		yyarg[yycount++] = yytname[yyx];
		yysize1 = yysize + yytnamerr (0, yytname[yyx]);
		yysize_overflow |= yysize1 < yysize;
		yysize = yysize1;
		yyfmt = yystpcpy (yyfmt, yyprefix);
		yyprefix = yyor;
	      }

	  yyf = YY_(yyformat);
	  yysize1 = yysize + yystrlen (yyf);
	  yysize_overflow |= yysize1 < yysize;
	  yysize = yysize1;

	  if (!yysize_overflow && yysize <= YYSTACK_ALLOC_MAXIMUM)
	    yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg)
	    {
	      /* Avoid sprintf, as that infringes on the user's name space.
		 Don't have undefined behavior even if the translation
		 produced a string with the wrong number of "%s"s.  */
	      char *yyp = yymsg;
	      int yyi = 0;
	      while ((*yyp = *yyf))
		{
		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		    {
		      yyp += yytnamerr (yyp, yyarg[yyi++]);
		      yyf += 2;
		    }
		  else
		    {
		      yyp++;
		      yyf++;
		    }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    {
	      yyerror (YY_("syntax error"));
	      goto yyexhaustedlab;
	    }
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror (YY_("syntax error"));
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
        }
      else
	{
	  yydestruct ("Error: discarding", yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (0)
     goto yyerrorlab;

yyvsp -= yylen;
  yyssp -= yylen;
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping", yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token. */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK;
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 4447 "parse.y"

# undef parser
# undef yylex
# undef yylval
# define yylval  (*((YYSTYPE*)(parser->parser_yylval)))

static int parser_regx_options(struct parser_params*);
static int parser_tokadd_string(struct parser_params*,int,int,int,long*);
static int parser_parse_string(struct parser_params*,NODE*);
static int parser_here_document(struct parser_params*,NODE*);

# define nextc()                   parser_nextc(parser)
# define pushback(c)               parser_pushback(parser, c)
# define newtok()                  parser_newtok(parser)
# define tokadd(c)                 parser_tokadd(parser, c)
# define read_escape()             parser_read_escape(parser)
# define tokadd_escape(t)          parser_tokadd_escape(parser, t)
# define regx_options()            parser_regx_options(parser)
# define tokadd_string(f,t,p,n)    parser_tokadd_string(parser,f,t,p,n)
# define parse_string(n)           parser_parse_string(parser,n)
# define here_document(n)          parser_here_document(parser,n)
# define heredoc_identifier()      parser_heredoc_identifier(parser)
# define heredoc_restore(n)        parser_heredoc_restore(parser,n)
# define whole_match_p(e,l,i)      parser_whole_match_p(parser,e,l,i)

#ifdef RIPPER
/* FIXME */
# define local_cnt(x)      3
# define local_id(x)       1
# define dyna_in_block()   1
#endif /* RIPPER */

#ifndef RIPPER
# define set_yylval_str(x) yylval.node = NEW_STR(x)
# define set_yylval_num(x) yylval.num = x
# define set_yylval_id(x)  yylval.id = x
# define set_yylval_literal(x) yylval.node = NEW_LIT(x)
# define set_yylval_node(x) yylval.node = x
# define yylval_id() yylval.id
#else
# define set_yylval_str(x) (void)(x)
# define set_yylval_num(x) (void)(x)
# define set_yylval_id(x) (void)(x)
# define set_yylval_literal(x) (void)(x)
# define set_yylval_node(x) (void)(x)
# define yylval_id() SYM2ID(yylval.val)
#endif

#ifdef RIPPER
#define ripper_flush(p) (p->tokp = p->parser_lex_p)

static void
ripper_dispatch_scan_event(struct parser_params *parser, int t)
{
    VALUE str;

    if (lex_p < parser->tokp) rb_raise(rb_eRuntimeError, "lex_p < tokp");
    if (lex_p == parser->tokp) return;
    str = rb_str_new(parser->tokp, lex_p - parser->tokp);
    yylval.val = ripper_dispatch1(parser, ripper_token2eventid(t), str);
    ripper_flush(parser);
}

static void
ripper_dispatch_delayed_token(struct parser_params *parser, int t)
{
    int saved_line = ruby_sourceline;
    const char *saved_tokp = parser->tokp;

    ruby_sourceline = parser->delayed_line;
    parser->tokp = lex_pbeg + parser->delayed_col;
    yylval.val = ripper_dispatch1(parser, ripper_token2eventid(t), parser->delayed);
    parser->delayed = Qnil;
    ruby_sourceline = saved_line;
    parser->tokp = saved_tokp;
}
#endif /* RIPPER */

#include "regex.h"
#include "util.h"

/* We remove any previous definition of `SIGN_EXTEND_CHAR',
   since ours (we hope) works properly with all combinations of
   machines, compilers, `char' and `unsigned char' argument types.
   (Per Bothner suggested the basic approach.)  */
#undef SIGN_EXTEND_CHAR
#if __STDC__
# define SIGN_EXTEND_CHAR(c) ((signed char)(c))
#else  /* not __STDC__ */
/* As in Harbison and Steele.  */
# define SIGN_EXTEND_CHAR(c) ((((unsigned char)(c)) ^ 128) - 128)
#endif
#define is_identchar(c) (SIGN_EXTEND_CHAR(c)!=-1&&(ISALNUM(c) || (c) == '_' || ismbchar(c)))

static int
parser_yyerror(struct parser_params *parser, const char *msg)
{
#ifndef RIPPER
    const char *p, *pe;
    char *buf;
    int len, i;

    rb_compile_error("%s", msg);
    p = lex_p;
    while (lex_pbeg <= p) {
	if (*p == '\n') break;
	p--;
    }
    p++;

    pe = lex_p;
    while (pe < lex_pend) {
	if (*pe == '\n') break;
	pe++;
    }

    len = pe - p;
    if (len > 4) {
	char *p2;
	buf = ALLOCA_N(char, len+2);
	MEMCPY(buf, p, char, len);
	buf[len] = '\0';
	rb_compile_error_append("%s", buf);

	i = lex_p - p;
	p2 = buf; pe = buf + len;

	while (p2 < pe) {
	    if (*p2 != '\t') *p2 = ' ';
	    p2++;
	}
	buf[i] = '^';
	buf[i+1] = '\0';
	rb_compile_error_append("%s", buf);
    }
#else
    dispatch1(parse_error, rb_str_new2(msg));
#endif /* !RIPPER */
    return 0;
}

static void parser_prepare(struct parser_params *parser);

#ifndef RIPPER
static NODE*
yycompile(struct parser_params *parser, const char *f, int line)
{
    int n;
    const char *kcode_save;

    if (!compile_for_eval && rb_safe_level() == 0 &&
	rb_const_defined(rb_cObject, rb_intern("SCRIPT_LINES__"))) {
	VALUE hash, fname;

	hash = rb_const_get(rb_cObject, rb_intern("SCRIPT_LINES__"));
	if (TYPE(hash) == T_HASH) {
	    fname = rb_str_new2(f);
	    ruby_debug_lines = rb_hash_aref(hash, fname);
	    if (NIL_P(ruby_debug_lines)) {
		ruby_debug_lines = rb_ary_new();
		rb_hash_aset(hash, fname, ruby_debug_lines);
	    }
	}
	if (line > 1) {
	    VALUE str = rb_str_new(0,0);
	    n = line - 1;
	    do {
		rb_ary_push(ruby_debug_lines, str);
	    } while (--n);
	}
    }

    kcode_save = rb_get_kcode();
    ruby_current_node = 0;
    ruby_sourcefile = rb_source_filename(f);
    ruby_sourceline = line - 1;
    parser_prepare(parser);
    n = yyparse((void*)parser);
    ruby_debug_lines = 0;
    compile_for_eval = 0;
    rb_set_kcode(kcode_save);

    lex_strterm = 0;
    if (ruby_eval_tree_begin) {
	return NEW_PRELUDE(ruby_eval_tree_begin, ruby_eval_tree);
    }
    else {
	return ruby_eval_tree;
    }
}
#endif /* !RIPPER */

static VALUE
lex_get_str(struct parser_params *parser, VALUE s)
{
    char *beg, *end, *pend;

    beg = RSTRING_PTR(s);
    if (lex_gets_ptr) {
	if (RSTRING_LEN(s) == lex_gets_ptr) return Qnil;
	beg += lex_gets_ptr;
    }
    pend = RSTRING_PTR(s) + RSTRING_LEN(s);
    end = beg;
    while (end < pend) {
	if (*end++ == '\n') break;
    }
    lex_gets_ptr = end - RSTRING_PTR(s);
    return rb_str_new(beg, end - beg);
}

static VALUE
lex_getline(struct parser_params *parser)
{
    VALUE line = (*parser->parser_lex_gets)(parser, parser->parser_lex_input);
#ifndef RIPPER
    if (ruby_debug_lines && !NIL_P(line)) {
	rb_ary_push(ruby_debug_lines, line);
    }
#endif
    return line;
}

#ifndef RIPPER
NODE*
rb_compile_string(const char *f, VALUE s, int line)
{
    VALUE volatile vparser = rb_parser_new();

    return rb_parser_compile_string(vparser, f, s, line);
}

int rb_parse_in_eval(void);

NODE*
rb_parser_compile_string(volatile VALUE vparser, const char *f, VALUE s, int line)
{
    struct parser_params *parser;
    NODE *node;
    volatile VALUE tmp;
    
    Data_Get_Struct(vparser, struct parser_params, parser);
    lex_gets = lex_get_str;
    lex_gets_ptr = 0;
    lex_input = s;
    lex_pbeg = lex_p = lex_pend = 0;
    compile_for_eval = rb_parse_in_eval();

    node = yycompile(parser, f, line);
    tmp = vparser; /* prohibit tail call optimization */

    return node;
}

NODE*
rb_compile_cstr(const char *f, const char *s, int len, int line)
{
    return rb_compile_string(f, rb_str_new(s, len), line);
}

NODE*
rb_parser_compile_cstr(volatile VALUE vparser, const char *f, const char *s, int len, int line)
{
    return rb_parser_compile_string(vparser, f, rb_str_new(s, len), line);
}

static VALUE
lex_io_gets(struct parser_params *parser, VALUE io)
{
    return rb_io_gets(io);
}

NODE*
rb_compile_file(const char *f, VALUE file, int start)
{
    VALUE volatile vparser = rb_parser_new();

    return rb_parser_compile_file(vparser, f, file, start);
}

NODE*
rb_parser_compile_file(volatile VALUE vparser, const char *f, VALUE file, int start)
{
    struct parser_params *parser;
    volatile VALUE tmp;
    NODE *node;
    
    Data_Get_Struct(vparser, struct parser_params, parser);
    lex_gets = lex_io_gets;
    lex_input = file;
    lex_pbeg = lex_p = lex_pend = 0;

    node = yycompile(parser, f, start);
    tmp = vparser; /* prohibit tail call optimization */

    return node;
}
#endif  /* !RIPPER */

static inline int
parser_nextc(struct parser_params *parser)
{
    int c;

    if (lex_p == lex_pend) {
        if (parser->eofp)
            return -1;
	if (lex_input) {
	    VALUE v = lex_getline(parser);

	    if (NIL_P(v)) {
                parser->eofp = Qtrue;
                return -1;
            }
#ifdef RIPPER
	    if (parser->tokp < lex_pend) {
		if (NIL_P(parser->delayed)) {
		    parser->delayed = rb_str_buf_new(1024);
		    rb_str_buf_cat(parser->delayed,
				   parser->tokp, lex_pend - parser->tokp);
		    parser->delayed_line = ruby_sourceline;
		    parser->delayed_col = parser->tokp - lex_pbeg;
		}
		else {
		    rb_str_buf_cat(parser->delayed,
				   parser->tokp, lex_pend - parser->tokp);
		}
	    }
#endif
	    if (heredoc_end > 0) {
		ruby_sourceline = heredoc_end;
		heredoc_end = 0;
	    }
	    ruby_sourceline++;
	    parser->line_count++;
	    lex_pbeg = lex_p = RSTRING_PTR(v);
	    lex_pend = lex_p + RSTRING_LEN(v);
#ifdef RIPPER
	    ripper_flush(parser);
#endif
	    lex_lastline = v;
	}
	else {
	    lex_lastline = 0;
	    return -1;
	}
    }
    c = (unsigned char)*lex_p++;
    if (c == '\r' && lex_p < lex_pend && *lex_p == '\n') {
	lex_p++;
	c = '\n';
    }

    return c;
}

static void
parser_pushback(struct parser_params *parser, int c)
{
    if (c == -1) return;
    lex_p--;
    if (lex_p > lex_pbeg && lex_p[0] == '\n' && lex_p[-1] == '\r') {
	lex_p--;
    }
}

#define lex_goto_eol(parser) (parser->parser_lex_p = parser->parser_lex_pend)
#define was_bol() (lex_p == lex_pbeg + 1)
#define peek(c) (lex_p != lex_pend && (c) == *lex_p)

#define tokfix() (tokenbuf[tokidx]='\0')
#define tok() tokenbuf
#define toklen() tokidx
#define toklast() (tokidx>0?tokenbuf[tokidx-1]:0)

static char*
parser_newtok(struct parser_params *parser)
{
    tokidx = 0;
    if (!tokenbuf) {
	toksiz = 60;
	tokenbuf = ALLOC_N(char, 60);
    }
    if (toksiz > 4096) {
	toksiz = 60;
	REALLOC_N(tokenbuf, char, 60);
    }
    return tokenbuf;
}

static void
parser_tokadd(struct parser_params *parser, int c)
{
    tokenbuf[tokidx++] = (char)c;
    if (tokidx >= toksiz) {
	toksiz *= 2;
	REALLOC_N(tokenbuf, char, toksiz);
    }
}

static int
parser_read_escape(struct parser_params *parser)
{
    int c;

    switch (c = nextc()) {
      case '\\':	/* Backslash */
	return c;

      case 'n':	/* newline */
	return '\n';

      case 't':	/* horizontal tab */
	return '\t';

      case 'r':	/* carriage-return */
	return '\r';

      case 'f':	/* form-feed */
	return '\f';

      case 'v':	/* vertical tab */
	return '\13';

      case 'a':	/* alarm(bell) */
	return '\007';

      case 'e':	/* escape */
	return 033;

      case '0': case '1': case '2': case '3': /* octal constant */
      case '4': case '5': case '6': case '7':
	{
	    int numlen;

	    pushback(c);
	    c = scan_oct(lex_p, 3, &numlen);
	    lex_p += numlen;
	}
	return c;

      case 'x':	/* hex constant */
	{
	    int numlen;

	    c = scan_hex(lex_p, 2, &numlen);
	    if (numlen == 0) {
		yyerror("Invalid escape character syntax");
		return 0;
	    }
	    lex_p += numlen;
	}
	return c;

      case 'b':	/* backspace */
	return '\010';

      case 's':	/* space */
	return ' ';

      case 'M':
	if ((c = nextc()) != '-') {
	    yyerror("Invalid escape character syntax");
	    pushback(c);
	    return '\0';
	}
	if ((c = nextc()) == '\\') {
	    return read_escape() | 0x80;
	}
	else if (c == -1) goto eof;
	else {
	    return ((c & 0xff) | 0x80);
	}

      case 'C':
	if ((c = nextc()) != '-') {
	    yyerror("Invalid escape character syntax");
	    pushback(c);
	    return '\0';
	}
      case 'c':
	if ((c = nextc())== '\\') {
	    c = read_escape();
	}
	else if (c == '?')
	    return 0177;
	else if (c == -1) goto eof;
	return c & 0x9f;

      eof:
      case -1:
        yyerror("Invalid escape character syntax");
	return '\0';

      default:
	return c;
    }
}

static int
parser_tokadd_escape(struct parser_params *parser, int term)
{
    int c;

    switch (c = nextc()) {
      case '\n':
	return 0;		/* just ignore */

      case '0': case '1': case '2': case '3': /* octal constant */
      case '4': case '5': case '6': case '7':
	{
	    int i;

	    tokadd('\\');
	    tokadd(c);
	    for (i=0; i<2; i++) {
		c = nextc();
		if (c == -1) goto eof;
		if (c < '0' || '7' < c) {
		    pushback(c);
		    break;
		}
		tokadd(c);
	    }
	}
	return 0;

      case 'x':	/* hex constant */
	{
	    int numlen;

	    tokadd('\\');
	    tokadd(c);
	    scan_hex(lex_p, 2, &numlen);
	    if (numlen == 0) {
		yyerror("Invalid escape character syntax");
		return -1;
	    }
	    while (numlen--)
		tokadd(nextc());
	}
	return 0;

      case 'M':
	if ((c = nextc()) != '-') {
	    yyerror("Invalid escape character syntax");
	    pushback(c);
	    return 0;
	}
	tokadd('\\'); tokadd('M'); tokadd('-');
	goto escaped;

      case 'C':
	if ((c = nextc()) != '-') {
	    yyerror("Invalid escape character syntax");
	    pushback(c);
	    return 0;
	}
	tokadd('\\'); tokadd('C'); tokadd('-');
	goto escaped;

      case 'c':
	tokadd('\\'); tokadd('c');
      escaped:
	if ((c = nextc()) == '\\') {
	    return tokadd_escape(term);
	}
	else if (c == -1) goto eof;
	tokadd(c);
	return 0;

      eof:
      case -1:
        yyerror("Invalid escape character syntax");
	return -1;

      default:
	if (c != '\\' || c != term)
	    tokadd('\\');
	tokadd(c);
    }
    return 0;
}

static int
parser_regx_options(struct parser_params *parser)
{
    extern int rb_char_to_option_kcode(int c, int *option, int *kcode);

    int kcode   = 0;
    int options = 0;
    int c, opt, kc;

    newtok();
    while (c = nextc(), ISALPHA(c)) {
        if (c == 'o') {
            options |= RE_OPTION_ONCE;
        }
        else if (rb_char_to_option_kcode(c, &opt, &kc)) {
            options |= opt;
            if (kc != 0) kcode = kc;
        }
        else {
	    tokadd(c);
        }
    }
    pushback(c);
    if (toklen()) {
	tokfix();
	compile_error(PARSER_ARG "unknown regexp option%s - %s",
		  toklen() > 1 ? "s" : "", tok());
    }
    return options | kcode;
}

#define STR_FUNC_ESCAPE 0x01
#define STR_FUNC_EXPAND 0x02
#define STR_FUNC_REGEXP 0x04
#define STR_FUNC_QWORDS 0x08
#define STR_FUNC_SYMBOL 0x10
#define STR_FUNC_INDENT 0x20

enum string_type {
    str_squote = (0),
    str_dquote = (STR_FUNC_EXPAND),
    str_xquote = (STR_FUNC_EXPAND),
    str_regexp = (STR_FUNC_REGEXP|STR_FUNC_ESCAPE|STR_FUNC_EXPAND),
    str_sword  = (STR_FUNC_QWORDS),
    str_dword  = (STR_FUNC_QWORDS|STR_FUNC_EXPAND),
    str_ssym   = (STR_FUNC_SYMBOL),
    str_dsym   = (STR_FUNC_SYMBOL|STR_FUNC_EXPAND),
};

static void
dispose_string(VALUE str)
{
    /* TODO: should use another API? */
    if (RBASIC(str)->flags & RSTRING_NOEMBED)
	xfree(RSTRING_PTR(str));
    rb_gc_force_recycle(str);
}

static int
parser_tokadd_string(struct parser_params *parser,
    int func, int term, int paren, long *nest)
{
    int c;
    unsigned char uc;

    while ((c = nextc()) != -1) {
        uc = (unsigned char)c;
	if (paren && c == paren) {
	    ++*nest;
	}
	else if (c == term) {
	    if (!nest || !*nest) {
		pushback(c);
		break;
	    }
	    --*nest;
	}
	else if ((func & STR_FUNC_EXPAND) && c == '#' && lex_p < lex_pend) {
	    int c2 = *lex_p;
	    if (c2 == '$' || c2 == '@' || c2 == '{') {
		pushback(c);
		break;
	    }
	}
	else if (c == '\\') {
	    c = nextc();
	    switch (c) {
	      case '\n':
		if (func & STR_FUNC_QWORDS) break;
		if (func & STR_FUNC_EXPAND) continue;
		tokadd('\\');
		break;

	      case '\\':
		if (func & STR_FUNC_ESCAPE) tokadd(c);
		break;

	      default:
		if (func & STR_FUNC_REGEXP) {
		    pushback(c);
		    if (tokadd_escape(term) < 0)
			return -1;
		    continue;
		}
		else if (func & STR_FUNC_EXPAND) {
		    pushback(c);
		    if (func & STR_FUNC_ESCAPE) tokadd('\\');
		    c = read_escape();
		}
		else if ((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
		    /* ignore backslashed spaces in %w */
		}
		else if (c != term && !(paren && c == paren)) {
		    tokadd('\\');
		}
	    }
	}
	else if (ismbchar(uc)) {
	    int i, len = mbclen(uc)-1;

	    for (i = 0; i < len; i++) {
		tokadd(c);
		c = nextc();
	    }
	}
	else if ((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
	    pushback(c);
	    break;
	}
	if (!c && (func & STR_FUNC_SYMBOL)) {
	    func &= ~STR_FUNC_SYMBOL;
	    rb_compile_error(PARSER_ARG  "symbol cannot contain '\\0'");
	    continue;
	}
	tokadd(c);
    }
    return c;
}

#define NEW_STRTERM0(func, term, paren) \
	rb_node_newnode(NODE_STRTERM, (func), (term) | ((paren) << (CHAR_BIT * 2)), 0)
#ifndef RIPPER
# define NEW_STRTERM(func, term, paren) NEW_STRTERM0(func, term, paren)
#else
# define NEW_STRTERM(func, term, paren) ripper_new_strterm(parser, func, term, paren)
static NODE *
ripper_new_strterm(struct parser_params *parser, VALUE func, VALUE term, VALUE paren)
{
    NODE *node = NEW_STRTERM0(func, term, paren);
    nd_set_line(node, ruby_sourceline);
    return node;
}
#endif

static int
parser_parse_string(struct parser_params *parser, NODE *quote)
{
    int func = quote->nd_func;
    int term = nd_term(quote);
    int paren = nd_paren(quote);
    int c, space = 0;

    if (func == -1) return tSTRING_END;
    c = nextc();
    if ((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
	do {c = nextc();} while (ISSPACE(c));
	space = 1;
    }
    if (c == term && !quote->nd_nest) {
	if (func & STR_FUNC_QWORDS) {
	    quote->nd_func = -1;
	    return ' ';
	}
	if (!(func & STR_FUNC_REGEXP)) return tSTRING_END;
        set_yylval_num(regx_options());
	return tREGEXP_END;
    }
    if (space) {
	pushback(c);
	return ' ';
    }
    newtok();
    if ((func & STR_FUNC_EXPAND) && c == '#') {
	switch (c = nextc()) {
	  case '$':
	  case '@':
	    pushback(c);
	    return tSTRING_DVAR;
	  case '{':
	    return tSTRING_DBEG;
	}
	tokadd('#');
    }
    pushback(c);
    if (tokadd_string(func, term, paren, &quote->nd_nest) == -1) {
       if (func & STR_FUNC_REGEXP) {
           ruby_sourceline = nd_line(quote);
           rb_compile_error(PARSER_ARG  "unterminated regexp meets end of file");
           return tREGEXP_END;
       }
       else {
	ruby_sourceline = nd_line(quote);
	rb_compile_error(PARSER_ARG  "unterminated string meets end of file");
	return tSTRING_END;
    }
    }

    tokfix();
    set_yylval_str(rb_str_new(tok(), toklen()));
    return tSTRING_CONTENT;
}

static int
parser_heredoc_identifier(struct parser_params *parser)
{
    int c = nextc(), term, func = 0, len;
    unsigned int uc;

    if (c == '-') {
	c = nextc();
	func = STR_FUNC_INDENT;
    }
    switch (c) {
      case '\'':
	func |= str_squote; goto quoted;
      case '"':
	func |= str_dquote; goto quoted;
      case '`':
	func |= str_xquote;
      quoted:
	newtok();
	tokadd(func);
	term = c;
	while ((c = nextc()) != -1 && c != term) {
            uc = (unsigned int)c;
	    len = mbclen(uc);
	    do {tokadd(c);} while (--len > 0 && (c = nextc()) != -1);
	}
	if (c == -1) {
	    rb_compile_error(PARSER_ARG  "unterminated here document identifier");
	    return 0;
	}
	break;

      default:
        uc = (unsigned int)c;
	if (!is_identchar(uc)) {
	    pushback(c);
	    if (func & STR_FUNC_INDENT) {
		pushback('-');
	    }
	    return 0;
	}
	newtok();
	term = '"';
	tokadd(func |= str_dquote);
	do {
            uc = (unsigned int)c;
	    len = mbclen(uc);
	    do {tokadd(c);} while (--len > 0 && (c = nextc()) != -1);
	} while ((c = nextc()) != -1 &&
		 (uc = (unsigned char)c, is_identchar(uc)));
	pushback(c);
	break;
    }

    tokfix();
#ifdef RIPPER
    ripper_dispatch_scan_event(parser, tHEREDOC_BEG);
#endif
    len = lex_p - lex_pbeg;
    lex_goto_eol(parser);
    lex_strterm = rb_node_newnode(NODE_HEREDOC,
				  rb_str_new(tok(), toklen()),	/* nd_lit */
				  len,				/* nd_nth */
				  lex_lastline);		/* nd_orig */
    nd_set_line(lex_strterm, ruby_sourceline);
#ifdef RIPPER
    ripper_flush(parser);
#endif
    return term == '`' ? tXSTRING_BEG : tSTRING_BEG;
}

static void
parser_heredoc_restore(struct parser_params *parser, NODE *here)
{
    VALUE line;

#ifdef RIPPER
    if (!NIL_P(parser->delayed))
	ripper_dispatch_delayed_token(parser, tSTRING_CONTENT);
    lex_goto_eol(parser);
    ripper_dispatch_scan_event(parser, tHEREDOC_END);
#endif
    line = here->nd_orig;
    lex_lastline = line;
    lex_pbeg = RSTRING_PTR(line);
    lex_pend = lex_pbeg + RSTRING_LEN(line);
    lex_p = lex_pbeg + here->nd_nth;
    heredoc_end = ruby_sourceline;
    ruby_sourceline = nd_line(here);
    dispose_string(here->nd_lit);
    rb_gc_force_recycle((VALUE)here);
#ifdef RIPPER
    ripper_flush(parser);
#endif
}

static int
parser_whole_match_p(struct parser_params *parser,
    const char *eos, int len, int indent)
{
    const char *p = lex_pbeg;
    int n;

    if (indent) {
	while (*p && ISSPACE(*p)) p++;
    }
    n= lex_pend - (p + len);
    if (n < 0 || (n > 0 && p[len] != '\n' && p[len] != '\r')) return Qfalse;
    if (strncmp(eos, p, len) == 0) return Qtrue;
    return Qfalse;
}

static int
parser_here_document(struct parser_params *parser, NODE *here)
{
    int c, func, indent = 0;
    const char *eos, *p, *pend;
    long len;
    VALUE str = 0;

    eos = RSTRING_PTR(here->nd_lit);
    len = RSTRING_LEN(here->nd_lit) - 1;
    indent = (func = *eos++) & STR_FUNC_INDENT;

    if ((c = nextc()) == -1) {
      error:
	rb_compile_error(PARSER_ARG  "can't find string \"%s\" anywhere before EOF", eos);
	heredoc_restore(lex_strterm);
	lex_strterm = 0;
	return 0;
    }
    if (was_bol() && whole_match_p(eos, len, indent)) {
	heredoc_restore(lex_strterm);
	return tSTRING_END;
    }

    if (!(func & STR_FUNC_EXPAND)) {
	do {
	    p = RSTRING_PTR(lex_lastline);
	    pend = lex_pend;
	    if (pend > p) {
		switch (pend[-1]) {
		  case '\n':
		    if (--pend == p || pend[-1] != '\r') {
			pend++;
			break;
		    }
		  case '\r':
		    --pend;
		}
	    }
	    if (str)
		rb_str_cat(str, p, pend - p);
	    else
		str = rb_str_new(p, pend - p);
	    if (pend < lex_pend) rb_str_cat(str, "\n", 1);
	    lex_goto_eol(parser);
	    if (nextc() == -1) {
		if (str) dispose_string(str);
		goto error;
	    }
	} while (!whole_match_p(eos, len, indent));
    }
    else {
	newtok();
	if (c == '#') {
	    switch (c = nextc()) {
	      case '$':
	      case '@':
		pushback(c);
		return tSTRING_DVAR;
	      case '{':
		return tSTRING_DBEG;
	    }
	    tokadd('#');
	}
	do {
	    pushback(c);
	    if ((c = tokadd_string(func, '\n', 0, NULL)) == -1) goto error;
	    if (c != '\n') {
                set_yylval_str(rb_str_new(tok(), toklen()));
		return tSTRING_CONTENT;
	    }
	    tokadd(nextc());
	    if ((c = nextc()) == -1) goto error;
	} while (!whole_match_p(eos, len, indent));
	str = rb_str_new(tok(), toklen());
    }
    heredoc_restore(lex_strterm);
    lex_strterm = NEW_STRTERM(-1, 0, 0);
    set_yylval_str(str);
    return tSTRING_CONTENT;
}

#include "lex.c"

#ifndef RIPPER
static void
arg_ambiguous(void)
{
    rb_warning("ambiguous first argument; put parentheses or even spaces");
}
#else
static void
ripper_arg_ambiguous(struct parser_params *parser)
{
    dispatch0(arg_ambiguous);
}
#define arg_ambiguous() ripper_arg_ambiguous(parser)
#endif

static int
lvar_defined_gen(struct parser_params *parser, ID id)
{
#ifndef RIPPER
    return (dyna_in_block() && dvar_defined(id)) || local_id(id);
#else
    return 0;
#endif
}

/* emacsen -*- hack */
#ifndef RIPPER
typedef void (*rb_pragma_setter_t)(struct parser_params *parser, const char *name, const char *val);

static void
pragma_encoding(struct parser_params *parser, const char *name, const char *val)
{
    if (parser && parser->line_count != (parser->has_shebang ? 2 : 1))
	return;
    rb_set_kcode(val);
}

struct pragma {
    const char *name;
    rb_pragma_setter_t func;
};

static const struct pragma pragmas[] = {
    {"coding", pragma_encoding},
};
#endif

static const char *
pragma_marker(const char *str, int len)
{
    int i = 2;

    while (i < len) {
	switch (str[i]) {
	  case '-':
	    if (str[i-1] == '*' && str[i-2] == '-') {
		return str + i + 1;
	    }
	    i += 2;
	    break;
	  case '*':
	    if (i + 1 >= len) return 0;
	    if (str[i+1] != '-') {
		i += 4;
	    }
	    else if (str[i-1] != '-') {
		i += 2;
	    }
	    else {
		return str + i + 2;
	    }
	    break;
	  default:
	    i += 3;
	    break;
	}
    }
    return 0;
}

static int
parser_pragma(struct parser_params *parser, const char *str, int len)
{
    VALUE name = 0, val = 0;
    const char *beg, *end, *vbeg, *vend;
#define str_copy(_s, _p, _n) ((_s) \
	? (rb_str_resize((_s), (_n)), \
	   MEMCPY(RSTRING_PTR(_s), (_p), char, (_n)), (_s)) \
	: ((_s) = rb_str_new((_p), (_n))))

    if (len <= 7) return Qfalse;
    if (!(beg = pragma_marker(str, len))) return Qfalse;
    if (!(end = pragma_marker(beg, str + len - beg))) return Qfalse;
    str = beg;
    len = end - beg - 3;
    
    /* %r"([^\\s\'\":;]+)\\s*:\\s*(\"(?:\\\\.|[^\"])*\"|[^\"\\s;]+)[\\s;]*" */
    while (len > 0) {
#ifndef RIPPER
	const struct pragma *p = pragmas;
#endif
	int n = 0;

	for (; len > 0 && *str; str++, --len) {
	    switch (*str) {
	      case '\'': case '"': case ':': case ';':
		continue;
	    }
	    if (!ISSPACE(*str)) break;
	}
	for (beg = str; len > 0; str++, --len) {
	    switch (*str) {
	      case '\'': case '"': case ':': case ';':
		break;
	      default:
		if (ISSPACE(*str)) break;
		continue;
	    }
	    break;
	}
	for (end = str; len > 0 && ISSPACE(*str); str++, --len);
	if (!len) break;
	if (*str != ':') continue;

	do str++; while (--len > 0 && ISSPACE(*str));
	if (!len) break;
	if (*str == '"') {
	    for (vbeg = ++str; --len > 0 && *str != '"'; str++) {
		if (*str == '\\') {
		    --len;
		    ++str;
		}
	    }
	    vend = str;
	    if (len) {
		--len;
		++str;
	    }
	}
	else {
	    for (vbeg = str; len > 0 && *str != '"' && !ISSPACE(*str); --len, str++);
	    vend = str;
	}
	while (len > 0 && (*str == ';' || ISSPACE(*str))) --len, str++;

	n = end - beg;
	str_copy(name, beg, n);
	rb_funcall(name, rb_intern("downcase!"), 0);
#ifndef RIPPER
	do {
	    if (strncmp(p->name, RSTRING_PTR(name), n) == 0) {
		str_copy(val, vbeg, vend - vbeg);
		(*p->func)(parser, RSTRING_PTR(name), RSTRING_PTR(val));
		break;
	    }
	} while (++p < pragmas + sizeof(pragmas) / sizeof(*p));
#else
	dispatch2(pragma, name, val);
#endif
    }

    return Qtrue;
}

static void
parser_prepare(struct parser_params *parser)
{
    int c = nextc();
    switch (c) {
      case '#':
	if (peek('!')) parser->has_shebang = 1;
	break;
      case 0xef:		/* UTF-8 BOM marker */
	if (lex_pend - lex_p >= 2 &&
	    (unsigned char)lex_p[0] == 0xbb &&
	    (unsigned char)lex_p[1] == 0xbf) {
	    rb_set_kcode("UTF-8");
	    lex_p += 2;
	    return;
	}
	break;
      case EOF:
	return;
    }
    pushback(c);
}

#define IS_ARG() (lex_state == EXPR_ARG || lex_state == EXPR_CMDARG)
#define IS_BEG() (lex_state == EXPR_BEG || lex_state == EXPR_MID || lex_state == EXPR_VALUE || lex_state == EXPR_CLASS)

static int
parser_yylex(struct parser_params *parser)
{
    register int c;
    int space_seen = 0;
    int cmd_state;
    unsigned char uc;
    enum lex_state_e last_state;
#ifdef RIPPER
    int fallthru = Qfalse;
#endif

    if (lex_strterm) {
	int token;
	if (nd_type(lex_strterm) == NODE_HEREDOC) {
	    token = here_document(lex_strterm);
	    if (token == tSTRING_END) {
		lex_strterm = 0;
		lex_state = EXPR_END;
	    }
	}
	else {
	    token = parse_string(lex_strterm);
	    if (token == tSTRING_END || token == tREGEXP_END) {
		rb_gc_force_recycle((VALUE)lex_strterm);
		lex_strterm = 0;
		lex_state = EXPR_END;
	    }
	}
	return token;
    }
    cmd_state = command_start;
    command_start = Qfalse;
  retry:
#ifdef RIPPER
    while ((c = nextc())) {
        switch (c) {
          case ' ': case '\t': case '\f': case '\r':
          case '\13': /* '\v' */
            space_seen++;
            break;
          default:
            goto outofloop;
        }
    }
  outofloop:
    pushback(c);
    ripper_dispatch_scan_event(parser, tSP);
#endif
    switch (c = nextc()) {
      case '\0':		/* NUL */
      case '\004':		/* ^D */
      case '\032':		/* ^Z */
      case -1:			/* end of script. */
	return 0;

	/* white spaces */
      case ' ': case '\t': case '\f': case '\r':
      case '\13': /* '\v' */
	space_seen++;
	goto retry;

      case '#':		/* it's a comment */
	if (!parser->has_shebang || parser->line_count != 1) {
	    /* no pragma in shebang line */
	    parser_pragma(parser, lex_p, lex_pend - lex_p);
	}
	lex_p = lex_pend;
#ifdef RIPPER
        ripper_dispatch_scan_event(parser, tCOMMENT);
        fallthru = Qtrue;
#endif
	/* fall through */
      case '\n':
	switch (lex_state) {
	  case EXPR_BEG:
	  case EXPR_FNAME:
	  case EXPR_DOT:
	  case EXPR_CLASS:
	  case EXPR_VALUE:
#ifdef RIPPER
            if (!fallthru) {
                ripper_dispatch_scan_event(parser, tIGNORED_NL);
            }
            fallthru = Qfalse;
#endif
	    goto retry;
	  default:
	    break;
	}
	command_start = Qtrue;
	lex_state = EXPR_BEG;
	return '\n';

      case '*':
	if ((c = nextc()) == '*') {
	    if ((c = nextc()) == '=') {
                set_yylval_id(tPOW);
		lex_state = EXPR_BEG;
		return tOP_ASGN;
	    }
	    pushback(c);
	    c = tPOW;
	}
	else {
	    if (c == '=') {
                set_yylval_id('*');
		lex_state = EXPR_BEG;
		return tOP_ASGN;
	    }
	    pushback(c);
	    if (IS_ARG() && space_seen && !ISSPACE(c)){
		rb_warning0("`*' interpreted as argument prefix");
		c = tSTAR;
	    }
	    else if (IS_BEG()) {
		c = tSTAR;
	    }
	    else {
		c = '*';
	    }
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	return c;

      case '!':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '=') {
	    return tNEQ;
	}
	if (c == '~') {
	    return tNMATCH;
	}
	pushback(c);
	return '!';

      case '=':
	if (was_bol()) {
	    /* skip embedded rd document */
	    if (strncmp(lex_p, "begin", 5) == 0 && ISSPACE(lex_p[5])) {
#ifdef RIPPER
                int first_p = Qtrue;

                lex_goto_eol(parser);
                ripper_dispatch_scan_event(parser, tEMBDOC_BEG);
#endif
		for (;;) {
		    lex_goto_eol(parser);
#ifdef RIPPER
                    if (!first_p) {
                        ripper_dispatch_scan_event(parser, tEMBDOC);
                    }
                    first_p = Qfalse;
#endif
		    c = nextc();
		    if (c == -1) {
			rb_compile_error(PARSER_ARG  "embedded document meets end of file");
			return 0;
		    }
		    if (c != '=') continue;
		    if (strncmp(lex_p, "end", 3) == 0 &&
			(lex_p + 3 == lex_pend || ISSPACE(lex_p[3]))) {
			break;
		    }
		}
		lex_goto_eol(parser);
#ifdef RIPPER
                ripper_dispatch_scan_event(parser, tEMBDOC_END);
#endif
		goto retry;
	    }
	}

	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	if ((c = nextc()) == '=') {
	    if ((c = nextc()) == '=') {
		return tEQQ;
	    }
	    pushback(c);
	    return tEQ;
	}
	if (c == '~') {
	    return tMATCH;
	}
	else if (c == '>') {
	    return tASSOC;
	}
	pushback(c);
	return '=';

      case '<':
	c = nextc();
	if (c == '<' &&
	    lex_state != EXPR_END &&
	    lex_state != EXPR_DOT &&
	    lex_state != EXPR_ENDARG &&
	    lex_state != EXPR_CLASS &&
	    (!IS_ARG() || space_seen)) {
	    int token = heredoc_identifier();
	    if (token) return token;
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	if (c == '=') {
	    if ((c = nextc()) == '>') {
		return tCMP;
	    }
	    pushback(c);
	    return tLEQ;
	}
	if (c == '<') {
	    if ((c = nextc()) == '=') {
                set_yylval_id(tLSHFT);
		lex_state = EXPR_BEG;
		return tOP_ASGN;
	    }
	    pushback(c);
	    return tLSHFT;
	}
	pushback(c);
	return '<';

      case '>':
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	if ((c = nextc()) == '=') {
	    return tGEQ;
	}
	if (c == '>') {
	    if ((c = nextc()) == '=') {
                set_yylval_id(tRSHFT);
		lex_state = EXPR_BEG;
		return tOP_ASGN;
	    }
	    pushback(c);
	    return tRSHFT;
	}
	pushback(c);
	return '>';

      case '"':
	lex_strterm = NEW_STRTERM(str_dquote, '"', 0);
	return tSTRING_BEG;

      case '`':
	if (lex_state == EXPR_FNAME) {
	    lex_state = EXPR_END;
	    return c;
	}
	if (lex_state == EXPR_DOT) {
	    if (cmd_state)
		lex_state = EXPR_CMDARG;
	    else
		lex_state = EXPR_ARG;
	    return c;
	}
	lex_strterm = NEW_STRTERM(str_xquote, '`', 0);
	return tXSTRING_BEG;

      case '\'':
	lex_strterm = NEW_STRTERM(str_squote, '\'', 0);
	return tSTRING_BEG;

      case '?':
	if (lex_state == EXPR_END ||
	    lex_state == EXPR_ENDARG) {
	    lex_state = EXPR_VALUE;
	    return '?';
	}
	c = nextc();
	if (c == -1) {
	    rb_compile_error(PARSER_ARG  "incomplete character syntax");
	    return 0;
	}
        uc = (unsigned char)c;
	if (ISSPACE(c)){
	    if (!IS_ARG()){
		int c2 = 0;
		switch (c) {
		  case ' ':
		    c2 = 's';
		    break;
		  case '\n':
		    c2 = 'n';
		    break;
		  case '\t':
		    c2 = 't';
		    break;
		  case '\v':
		    c2 = 'v';
		    break;
		  case '\r':
		    c2 = 'r';
		    break;
		  case '\f':
		    c2 = 'f';
		    break;
		}
		if (c2) {
		    rb_warnI("invalid character syntax; use ?\\%c", c2);
		}
	    }
	  ternary:
	    pushback(c);
	    lex_state = EXPR_VALUE;
	    return '?';
	}
	newtok();
	if (ismbchar(uc)) {
	    int i, len = mbclen(uc)-1;

	    tokadd(c);
	    for (i = 0; i < len; i++) {
		c = nextc();
		tokadd(c);
	    }
	}
	else if ((ISALNUM(c) || c == '_') && lex_p < lex_pend && is_identchar(*lex_p)) {
	    goto ternary;
	}
	else if (c == '\\') {
	    c = read_escape();
	    tokadd(c);
	}
	else {
	    tokadd(c);
	}
	tokfix();
	set_yylval_str(rb_str_new(tok(), toklen()));
	lex_state = EXPR_END;
	return tCHAR;

      case '&':
	if ((c = nextc()) == '&') {
	    lex_state = EXPR_BEG;
	    if ((c = nextc()) == '=') {
                set_yylval_id(tANDOP);
		lex_state = EXPR_BEG;
		return tOP_ASGN;
	    }
	    pushback(c);
	    return tANDOP;
	}
	else if (c == '=') {
            set_yylval_id('&');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	pushback(c);
	if (IS_ARG() && space_seen && !ISSPACE(c)){
	    rb_warning0("`&' interpreted as argument prefix");
	    c = tAMPER;
	}
	else if (IS_BEG()) {
	    c = tAMPER;
	}
	else {
	    c = '&';
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG;
	}
	return c;

      case '|':
	if ((c = nextc()) == '|') {
	    lex_state = EXPR_BEG;
	    if ((c = nextc()) == '=') {
                set_yylval_id(tOROP);
		lex_state = EXPR_BEG;
		return tOP_ASGN;
	    }
	    pushback(c);
	    return tOROP;
	}
	if (c == '=') {
            set_yylval_id('|');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
	    lex_state = EXPR_ARG;
	}
	else {
	    lex_state = EXPR_BEG;
	}
	pushback(c);
	return '|';

      case '+':
	c = nextc();
	if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
	    lex_state = EXPR_ARG;
	    if (c == '@') {
		return tUPLUS;
	    }
	    pushback(c);
	    return '+';
	}
	if (c == '=') {
            set_yylval_id('+');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	if (IS_BEG() ||
	    (IS_ARG() && space_seen && !ISSPACE(c))) {
	    if (IS_ARG()) arg_ambiguous();
	    lex_state = EXPR_BEG;
	    pushback(c);
	    if (ISDIGIT(c)) {
		c = '+';
		goto start_num;
	    }
	    return tUPLUS;
	}
	lex_state = EXPR_BEG;
	pushback(c);
	return '+';

      case '-':
	c = nextc();
	if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
	    lex_state = EXPR_ARG;
	    if (c == '@') {
		return tUMINUS;
	    }
	    pushback(c);
	    return '-';
	}
	if (c == '=') {
            set_yylval_id('-');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	if (c == '>') {
	    lex_state = EXPR_ARG;
		return tLAMBDA;
	    }
	if (IS_BEG() ||
	    (IS_ARG() && space_seen && !ISSPACE(c))) {
	    if (IS_ARG()) arg_ambiguous();
	    lex_state = EXPR_BEG;
	    pushback(c);
	    if (ISDIGIT(c)) {
		return tUMINUS_NUM;
	    }
	    return tUMINUS;
	}
	lex_state = EXPR_BEG;
	pushback(c);
	return '-';

      case '.':
	lex_state = EXPR_BEG;
	if ((c = nextc()) == '.') {
	    if ((c = nextc()) == '.') {
		return tDOT3;
	    }
	    pushback(c);
	    return tDOT2;
	}
	pushback(c);
	if (ISDIGIT(c)) {
	    yyerror("no .<digit> floating literal anymore; put 0 before dot");
	}
	lex_state = EXPR_DOT;
	return '.';

      start_num:
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
	{
	    int is_float, seen_point, seen_e, nondigit;

	    is_float = seen_point = seen_e = nondigit = 0;
	    lex_state = EXPR_END;
	    newtok();
	    if (c == '-' || c == '+') {
		tokadd(c);
		c = nextc();
	    }
	    if (c == '0') {
		int start = toklen();
		c = nextc();
		if (c == 'x' || c == 'X') {
		    /* hexadecimal */
		    c = nextc();
		    if (ISXDIGIT(c)) {
			do {
			    if (c == '_') {
				if (nondigit) break;
				nondigit = c;
				continue;
			    }
			    if (!ISXDIGIT(c)) break;
			    nondigit = 0;
			    tokadd(c);
			} while ((c = nextc()) != -1);
		    }
		    pushback(c);
		    tokfix();
		    if (toklen() == start) {
			yyerror("numeric literal without digits");
		    }
		    else if (nondigit) goto trailing_uc;
                    set_yylval_literal(rb_cstr_to_inum(tok(), 16, Qfalse));
		    return tINTEGER;
		}
		if (c == 'b' || c == 'B') {
		    /* binary */
		    c = nextc();
		    if (c == '0' || c == '1') {
			do {
			    if (c == '_') {
				if (nondigit) break;
				nondigit = c;
				continue;
			    }
			    if (c != '0' && c != '1') break;
			    nondigit = 0;
			    tokadd(c);
			} while ((c = nextc()) != -1);
		    }
		    pushback(c);
		    tokfix();
		    if (toklen() == start) {
			yyerror("numeric literal without digits");
		    }
		    else if (nondigit) goto trailing_uc;
                    set_yylval_literal(rb_cstr_to_inum(tok(), 2, Qfalse));
		    return tINTEGER;
		}
		if (c == 'd' || c == 'D') {
		    /* decimal */
		    c = nextc();
		    if (ISDIGIT(c)) {
			do {
			    if (c == '_') {
				if (nondigit) break;
				nondigit = c;
				continue;
			    }
			    if (!ISDIGIT(c)) break;
			    nondigit = 0;
			    tokadd(c);
			} while ((c = nextc()) != -1);
		    }
		    pushback(c);
		    tokfix();
		    if (toklen() == start) {
			yyerror("numeric literal without digits");
		    }
		    else if (nondigit) goto trailing_uc;
                    set_yylval_literal(rb_cstr_to_inum(tok(), 10, Qfalse));
		    return tINTEGER;
		}
		if (c == '_') {
		    /* 0_0 */
		    goto octal_number;
		}
		if (c == 'o' || c == 'O') {
		    /* prefixed octal */
		    c = nextc();
		    if (c == '_') {
			yyerror("numeric literal without digits");
		    }
		}
		if (c >= '0' && c <= '7') {
		    /* octal */
		  octal_number:
	            do {
			if (c == '_') {
			    if (nondigit) break;
			    nondigit = c;
			    continue;
			}
			if (c < '0' || c > '7') break;
			nondigit = 0;
			tokadd(c);
		    } while ((c = nextc()) != -1);
		    if (toklen() > start) {
			pushback(c);
			tokfix();
			if (nondigit) goto trailing_uc;
                        set_yylval_literal(rb_cstr_to_inum(tok(), 8, Qfalse));
			return tINTEGER;
		    }
		    if (nondigit) {
			pushback(c);
			goto trailing_uc;
		    }
		}
		if (c > '7' && c <= '9') {
		    yyerror("Illegal octal digit");
		}
		else if (c == '.' || c == 'e' || c == 'E') {
		    tokadd('0');
		}
		else {
		    pushback(c);
                    set_yylval_literal(INT2FIX(0));
		    return tINTEGER;
		}
	    }

	    for (;;) {
		switch (c) {
		  case '0': case '1': case '2': case '3': case '4':
		  case '5': case '6': case '7': case '8': case '9':
		    nondigit = 0;
		    tokadd(c);
		    break;

		  case '.':
		    if (nondigit) goto trailing_uc;
		    if (seen_point || seen_e) {
			goto decode_num;
		    }
		    else {
			int c0 = nextc();
			if (!ISDIGIT(c0)) {
			    pushback(c0);
			    goto decode_num;
			}
			c = c0;
		    }
		    tokadd('.');
		    tokadd(c);
		    is_float++;
		    seen_point++;
		    nondigit = 0;
		    break;

		  case 'e':
		  case 'E':
		    if (nondigit) {
			pushback(c);
			c = nondigit;
			goto decode_num;
		    }
		    if (seen_e) {
			goto decode_num;
		    }
		    tokadd(c);
		    seen_e++;
		    is_float++;
		    nondigit = c;
		    c = nextc();
		    if (c != '-' && c != '+') continue;
		    tokadd(c);
		    nondigit = c;
		    break;

		  case '_':	/* `_' in number just ignored */
		    if (nondigit) goto decode_num;
		    nondigit = c;
		    break;

		  default:
		    goto decode_num;
		}
		c = nextc();
	    }

	  decode_num:
	    pushback(c);
	    tokfix();
	    if (nondigit) {
		char tmp[30];
	      trailing_uc:
		sprintf(tmp, "trailing `%c' in number", nondigit);
		yyerror(tmp);
	    }
	    if (is_float) {
		double d = strtod(tok(), 0);
		if (errno == ERANGE) {
		    rb_warnS("Float %s out of range", tok());
		    errno = 0;
		}
                set_yylval_literal(rb_float_new(d));
		return tFLOAT;
	    }
            set_yylval_literal(rb_cstr_to_inum(tok(), 10, Qfalse));
	    return tINTEGER;
	}

      case ')':
      case ']':
	paren_nest--;
      case '}':
	COND_LEXPOP();
	CMDARG_LEXPOP();
	lex_state = EXPR_END;
	return c;

      case ':':
	c = nextc();
	if (c == ':') {
	    if (IS_BEG() ||
		lex_state == EXPR_CLASS || (IS_ARG() && space_seen)) {
		lex_state = EXPR_BEG;
		return tCOLON3;
	    }
	    lex_state = EXPR_DOT;
	    return tCOLON2;
	}
	if (lex_state == EXPR_END || 
	    lex_state == EXPR_ENDARG || ISSPACE(c)) {
	    pushback(c);
	    lex_state = EXPR_BEG;
	    return ':';
	}
	switch (c) {
	  case '\'':
	    lex_strterm = NEW_STRTERM(str_ssym, c, 0);
	    break;
	  case '"':
	    lex_strterm = NEW_STRTERM(str_dsym, c, 0);
	    break;
	  default:
	    pushback(c);
	    break;
	}
	lex_state = EXPR_FNAME;
	return tSYMBEG;

      case '/':
	if (IS_BEG()) {
	    lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
	    return tREGEXP_BEG;
	}
	if ((c = nextc()) == '=') {
            set_yylval_id('/');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	pushback(c);
	if (IS_ARG() && space_seen) {
	    if (!ISSPACE(c)) {
		arg_ambiguous();
		lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
		return tREGEXP_BEG;
	    }
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	return '/';

      case '^':
	if ((c = nextc()) == '=') {
            set_yylval_id('^');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	pushback(c);
	return '^';

      case ';':
	lex_state = EXPR_BEG;
	command_start = Qtrue;
	return ';';

      case ',':
	lex_state = EXPR_BEG;
	return ',';

      case '~':
	if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
	    if ((c = nextc()) != '@') {
		pushback(c);
	    }
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	return '~';

      case '(':
	if (IS_BEG()) {
	    c = tLPAREN;
	}
	else if (space_seen) {
	    if (lex_state == EXPR_CMDARG) {
		c = tLPAREN_ARG;
	    }
	    else if (lex_state == EXPR_ARG) {
		rb_warning0("don't put space before argument parentheses");
		c = '(';
	    }
	}
	paren_nest++;
	COND_PUSH(0);
	CMDARG_PUSH(0);
	lex_state = EXPR_BEG;
	return c;

      case '[':
	paren_nest++;
	if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
	    lex_state = EXPR_ARG;
	    if ((c = nextc()) == ']') {
		if ((c = nextc()) == '=') {
		    return tASET;
		}
		pushback(c);
		return tAREF;
	    }
	    pushback(c);
	    return '[';
	}
	else if (IS_BEG()) {
	    c = tLBRACK;
	}
	else if (IS_ARG() && space_seen) {
	    c = tLBRACK;
	}
	lex_state = EXPR_BEG;
	COND_PUSH(0);
	CMDARG_PUSH(0);
	return c;

      case '{':
	if (lpar_beg && lpar_beg == paren_nest) {
	    lex_state = EXPR_BEG;
	    lpar_beg = 0;
	    --paren_nest;
	    return tLAMBEG;
	}
	if (IS_ARG() || lex_state == EXPR_END)
	    c = '{';          /* block (primary) */
	else if (lex_state == EXPR_ENDARG)
	    c = tLBRACE_ARG;  /* block (expr) */
	else
	    c = tLBRACE;      /* hash */
	COND_PUSH(0);
	CMDARG_PUSH(0);
	lex_state = EXPR_BEG;
	return c;

      case '\\':
	c = nextc();
	if (c == '\n') {
	    space_seen = 1;
#ifdef RIPPER
	    ripper_dispatch_scan_event(parser, tSP);
#endif
	    goto retry; /* skip \\n */
	}
	pushback(c);
	return '\\';

      case '%':
	if (IS_BEG()) {
	    int term;
	    int paren;

	    c = nextc();
	  quotation:
	    if (!ISALNUM(c)) {
		term = c;
		c = 'Q';
	    }
	    else {
		term = nextc();
                uc = (unsigned char)c;
		if (ISALNUM(term) || ismbchar(uc)) {
		    yyerror("unknown type of %string");
		    return 0;
		}
	    }
	    if (c == -1 || term == -1) {
		rb_compile_error(PARSER_ARG  "unterminated quoted string meets end of file");
		return 0;
	    }
	    paren = term;
	    if (term == '(') term = ')';
	    else if (term == '[') term = ']';
	    else if (term == '{') term = '}';
	    else if (term == '<') term = '>';
	    else paren = 0;

	    switch (c) {
	      case 'Q':
		lex_strterm = NEW_STRTERM(str_dquote, term, paren);
		return tSTRING_BEG;

	      case 'q':
		lex_strterm = NEW_STRTERM(str_squote, term, paren);
		return tSTRING_BEG;

	      case 'W':
		lex_strterm = NEW_STRTERM(str_dword, term, paren);
		do {c = nextc();} while (ISSPACE(c));
		pushback(c);
		return tWORDS_BEG;

	      case 'w':
		lex_strterm = NEW_STRTERM(str_sword, term, paren);
		do {c = nextc();} while (ISSPACE(c));
		pushback(c);
		return tQWORDS_BEG;

	      case 'x':
		lex_strterm = NEW_STRTERM(str_xquote, term, paren);
		return tXSTRING_BEG;

	      case 'r':
		lex_strterm = NEW_STRTERM(str_regexp, term, paren);
		return tREGEXP_BEG;

	      case 's':
		lex_strterm = NEW_STRTERM(str_ssym, term, paren);
		lex_state = EXPR_FNAME;
		return tSYMBEG;

	      default:
		yyerror("unknown type of %string");
		return 0;
	    }
	}
	if ((c = nextc()) == '=') {
            set_yylval_id('%');
	    lex_state = EXPR_BEG;
	    return tOP_ASGN;
	}
	if (IS_ARG() && space_seen && !ISSPACE(c)) {
	    goto quotation;
	}
	switch (lex_state) {
	  case EXPR_FNAME: case EXPR_DOT:
	    lex_state = EXPR_ARG; break;
	  default:
	    lex_state = EXPR_BEG; break;
	}
	pushback(c);
	return '%';

      case '$':
	last_state = lex_state;
	lex_state = EXPR_END;
	newtok();
	c = nextc();
	switch (c) {
	  case '_':		/* $_: last read line string */
	    c = nextc();
            uc = (unsigned char)c;
	    if (is_identchar(uc)) {
		tokadd('$');
		tokadd('_');
		break;
	    }
	    pushback(c);
	    c = '_';
	    /* fall through */
	  case '~':		/* $~: match-data */
	    (void)local_cnt(c);
	    /* fall through */
	  case '*':		/* $*: argv */
	  case '$':		/* $$: pid */
	  case '?':		/* $?: last status */
	  case '!':		/* $!: error string */
	  case '@':		/* $@: error position */
	  case '/':		/* $/: input record separator */
	  case '\\':		/* $\: output record separator */
	  case ';':		/* $;: field separator */
	  case ',':		/* $,: output field separator */
	  case '.':		/* $.: last read line number */
	  case '=':		/* $=: ignorecase */
	  case ':':		/* $:: load path */
	  case '<':		/* $<: reading filename */
	  case '>':		/* $>: default output handle */
	  case '\"':		/* $": already loaded files */
	    tokadd('$');
	    tokadd(c);
	    tokfix();
            set_yylval_id(rb_intern(tok()));
	    return tGVAR;

	  case '-':
	    tokadd('$');
	    tokadd(c);
	    c = nextc();
	    uc = (unsigned char)c;
	    if (is_identchar(uc)) {
	    tokadd(c);
	    }
	    else {
		pushback(c);
	    }
	  gvar:
	    tokfix();
            set_yylval_id(rb_intern(tok()));
	    if (!is_global_id(yylval_id())) {
	    	rb_compile_error(PARSER_ARG  "invalid global variable `%s'", rb_id2name(yylval.id));
		return 0;
	    }
	    return tGVAR;

	  case '&':		/* $&: last match */
	  case '`':		/* $`: string before last match */
	  case '\'':		/* $': string after last match */
	  case '+':		/* $+: string matches last paren. */
	    if (last_state == EXPR_FNAME) {
		tokadd('$');
		tokadd(c);
		goto gvar;
	    }
	    set_yylval_node(NEW_BACK_REF(c));
	    return tBACK_REF;

	  case '1': case '2': case '3':
	  case '4': case '5': case '6':
	  case '7': case '8': case '9':
	    tokadd('$');
	    do {
		tokadd(c);
		c = nextc();
	    } while (ISDIGIT(c));
	    pushback(c);
	    if (last_state == EXPR_FNAME) goto gvar;
	    tokfix();
	    set_yylval_node(NEW_NTH_REF(atoi(tok()+1)));
	    return tNTH_REF;

	  default:
            uc = (unsigned char)c;
	    if (!is_identchar(uc)) {
		pushback(c);
		return '$';
	    }
	  case '0':
	    tokadd('$');
	}
	break;

      case '@':
	c = nextc();
	newtok();
	tokadd('@');
	if (c == '@') {
	    tokadd('@');
	    c = nextc();
	}
	if (ISDIGIT(c)) {
	    if (tokidx == 1) {
		rb_compile_error(PARSER_ARG  "`@%c' is not allowed as an instance variable name", c);
	    }
	    else {
		rb_compile_error(PARSER_ARG  "`@@%c' is not allowed as a class variable name", c);
	    }
	}
        uc = (unsigned char)c;
	if (!is_identchar(uc)) {
	    pushback(c);
	    return '@';
	}
	break;

      case '_':
	if (was_bol() && whole_match_p("__END__", 7, 0)) {
	    ruby__end__seen = 1;
	    lex_lastline = 0;
#ifndef RIPPER
	    return -1;
#else
            lex_goto_eol(parser);
            ripper_dispatch_scan_event(parser, k__END__);
            return 0;
#endif
	}
	newtok();
	break;

      default:
	uc = (unsigned char)c;
	if (!is_identchar(uc)) {
	    rb_compile_error(PARSER_ARG  "Invalid char `\\%03o' in expression", c);
	    goto retry;
	}

	newtok();
	break;
    }

    uc = (unsigned char)c;
    do {
	tokadd(c);
	if (ismbchar(uc)) {
	    int i, len = mbclen(uc)-1;

	    for (i = 0; i < len; i++) {
		c = nextc();
		tokadd(c);
	    }
	}
	c = nextc();
        uc = (unsigned char)c;
    } while (is_identchar(uc));
    if ((c == '!' || c == '?') && is_identchar(tok()[0]) && !peek('=')) {
	tokadd(c);
    }
    else {
	pushback(c);
    }
    tokfix();

    {
	int result = 0;

	last_state = lex_state;
	switch (tok()[0]) {
	  case '$':
	    lex_state = EXPR_END;
	    result = tGVAR;
	    break;
	  case '@':
	    lex_state = EXPR_END;
	    if (tok()[1] == '@')
		result = tCVAR;
	    else
		result = tIVAR;
	    break;

	  default:
	    if (toklast() == '!' || toklast() == '?') {
		result = tFID;
	    }
	    else {
		if (lex_state == EXPR_FNAME) {
		    if ((c = nextc()) == '=' && !peek('~') && !peek('>') &&
			(!peek('=') || (lex_p + 1 < lex_pend && lex_p[1] == '>'))) {
			result = tIDENTIFIER;
			tokadd(c);
			tokfix();
		    }
		    else {
			pushback(c);
		    }
		}
		if (result == 0 && ISUPPER(tok()[0])) {
		    result = tCONSTANT;
		}
		else {
		    result = tIDENTIFIER;
		}
	    }

	    if (lex_state != EXPR_DOT) {
		const struct kwtable *kw;

		/* See if it is a reserved word.  */
		kw = rb_reserved_word(tok(), toklen());
		if (kw) {
		    enum lex_state_e state = lex_state;
		    lex_state = kw->state;
		    if (state == EXPR_FNAME) {
                        set_yylval_id(rb_intern(kw->name));
			return kw->id[0];
		    }
		    if (kw->id[0] == keyword_do) {
			if (lpar_beg && lpar_beg == paren_nest) {
			    lpar_beg = 0;
			    --paren_nest;
			    return keyword_do_LAMBDA;
			}
			if (COND_P()) return keyword_do_cond;
			if (CMDARG_P() && state != EXPR_CMDARG)
			    return keyword_do_block;
			if (state == EXPR_ENDARG || state == EXPR_BEG)
			    return keyword_do_block;
			return keyword_do;
		    }
		    if (state == EXPR_BEG || state == EXPR_VALUE)
			return kw->id[0];
		    else {
			if (kw->id[0] != kw->id[1])
			    lex_state = EXPR_BEG;
			return kw->id[1];
		    }
		}
	    }

	    if ((lex_state == EXPR_BEG && !cmd_state) ||
		lex_state == EXPR_ARG ||
		lex_state == EXPR_CMDARG) {
		if (peek(':') && !(lex_p + 1 < lex_pend && lex_p[1] == ':')) {
		    lex_state = EXPR_BEG;
		    nextc();
		    set_yylval_id(rb_intern(tok()));
		    return tLABEL;
		}
	    }
	    if (IS_BEG() ||
		lex_state == EXPR_DOT ||
		IS_ARG()) {
		if (cmd_state) {
		    lex_state = EXPR_CMDARG;
		}
		else {
		    lex_state = EXPR_ARG;
		}
	    }
	    else {
		lex_state = EXPR_END;
	    }
	}
        {
            ID ident = rb_intern(tok());

            set_yylval_id(ident);
            if (last_state != EXPR_DOT && is_local_id(ident) && lvar_defined(ident)) {
                lex_state = EXPR_END;
            }
        }
	return result;
    }
}

#if YYPURE
static int
yylex(void *lval, void *p)
#else
yylex(void *p)
#endif
{
    struct parser_params *parser = (struct parser_params*)p;
    int t;

#if YYPURE
    parser->parser_yylval = (union tmpyystype*)lval;
    parser->parser_yylval->val = Qundef;
#endif
    t = parser_yylex(parser);
#ifdef RIPPER
    if (!NIL_P(parser->delayed)) {
	ripper_dispatch_delayed_token(parser, t);
	return t;
    }
    if (t != 0)
	ripper_dispatch_scan_event(parser, t);
#endif

    return t;
}

#ifndef RIPPER
NODE*
rb_node_newnode(enum node_type type, VALUE a0, VALUE a1, VALUE a2)
{
    NODE *n = (NODE*)rb_newobj();

    n->flags |= T_NODE;
    nd_set_type(n, type);
    nd_set_line(n, ruby_sourceline);
    n->nd_file = ruby_sourcefile;

    n->u1.value = a0;
    n->u2.value = a1;
    n->u3.value = a2;

    return n;
}

enum node_type
nodetype(NODE *node)			/* for debug */
{
    return (enum node_type)nd_type(node);
}

int
nodeline(NODE *node)
{
    return nd_line(node);
}

static NODE*
newline_node(NODE *node)
{
    if (node) {
	node->flags |= NODE_NEWLINE;
    }
    return node;
}

static void
fixpos(NODE *node, NODE *orig)
{
    if (!node) return;
    if (!orig) return;
    if (orig == (NODE*)1) return;
    node->nd_file = orig->nd_file;
    nd_set_line(node, nd_line(orig));
}

static void
parser_warning(NODE *node, const char *mesg)
{
    int line = ruby_sourceline;
    ruby_sourceline = nd_line(node);
    rb_warning("%s", mesg);
    ruby_sourceline = line;
}

static void
parser_warn(NODE *node, const char *mesg)
{
    int line = ruby_sourceline;
    ruby_sourceline = nd_line(node);
    rb_warn("%s", mesg);
    ruby_sourceline = line;
}

static NODE*
block_append(NODE *head, NODE *tail)
{
    NODE *end, *h = head, *nd;

    if (tail == 0) return head;

    if (h == 0) return tail;
    switch (nd_type(h)) {
      case NODE_LIT:
      case NODE_STR:
      case NODE_SELF:
      case NODE_TRUE:
      case NODE_FALSE:
      case NODE_NIL:
	parser_warning(h, "unused literal ignored");
	return tail;
      default:
	h = end = NEW_BLOCK(head);
	end->nd_end = end;
	fixpos(end, head);
	head = end;
	break;
      case NODE_BLOCK:
	end = h->nd_end;
	break;
    }

    nd = end->nd_head;
    switch (nd_type(nd)) {
      case NODE_RETURN:
      case NODE_BREAK:
      case NODE_NEXT:
      case NODE_REDO:
      case NODE_RETRY:
	if (RTEST(ruby_verbose)) {
	    parser_warning(nd, "statement not reached");
	}
	break;

      default:
	break;
    }

    if (nd_type(tail) != NODE_BLOCK) {
	tail = NEW_BLOCK(tail);
	tail->nd_end = tail;
    }
    end->nd_next = tail;
    h->nd_end = tail->nd_end;
    return head;
}

/* append item to the list */
static NODE*
list_append(NODE *list, NODE *item)
{
    NODE *last;

    if (list == 0) return NEW_LIST(item);
    if (list->nd_next) {
	last = list->nd_next->nd_end;
    }
    else {
	last = list;
    }

    list->nd_alen += 1;
    last->nd_next = NEW_LIST(item);
    list->nd_next->nd_end = last->nd_next;
    return list;
}

/* concat two lists */
static NODE*
list_concat(NODE *head, NODE *tail)
{
    NODE *last;

    if (head->nd_next) {
	last = head->nd_next->nd_end;
    }
    else {
	last = head;
    }

    head->nd_alen += tail->nd_alen;
    last->nd_next = tail;
    if (tail->nd_next) {
	head->nd_next->nd_end = tail->nd_next->nd_end;
    }
    else {
	head->nd_next->nd_end = tail;
    }

    return head;
}

/* concat two string literals */
static NODE *
literal_concat(NODE *head, NODE *tail)
{
    enum node_type htype;

    if (!head) return tail;
    if (!tail) return head;

    htype = nd_type(head);
    if (htype == NODE_EVSTR) {
	NODE *node = NEW_DSTR(rb_str_new(0, 0));
	head = list_append(node, head);
    }
    switch (nd_type(tail)) {
      case NODE_STR:
	if (htype == NODE_STR) {
	    rb_str_concat(head->nd_lit, tail->nd_lit);
	    rb_gc_force_recycle((VALUE)tail);
	}
	else {
	    list_append(head, tail);
	}
	break;

      case NODE_DSTR:
	if (htype == NODE_STR) {
	    rb_str_concat(head->nd_lit, tail->nd_lit);
	    tail->nd_lit = head->nd_lit;
	    rb_gc_force_recycle((VALUE)head);
	    head = tail;
	}
	else {
	    nd_set_type(tail, NODE_ARRAY);
	    tail->nd_head = NEW_STR(tail->nd_lit);
	    list_concat(head, tail);
	}
	break;

      case NODE_EVSTR:
	if (htype == NODE_STR) {
	    nd_set_type(head, NODE_DSTR);
	    head->nd_alen = 1;
	}
	list_append(head, tail);
	break;
    }
    return head;
}

static NODE *
evstr2dstr(NODE *node)
{
    if (nd_type(node) == NODE_EVSTR) {
	node = list_append(NEW_DSTR(rb_str_new(0, 0)), node);
    }
    return node;
}

static NODE *
new_evstr(NODE *node)
{
    NODE *head = node;

    if (node) {
	switch (nd_type(node)) {
	  case NODE_STR: case NODE_DSTR: case NODE_EVSTR:
	    return node;
	}
    }
    return NEW_EVSTR(head);
}

static NODE *
call_op_gen(struct parser_params *parser, NODE *recv, ID id, int narg, NODE *arg1)
{
    value_expr(arg1);
    if (narg == 1) {
	value_expr(arg1);
	arg1 = NEW_LIST(arg1);
    }
    else {
	arg1 = 0;
    }
    return NEW_CALL(recv, id, arg1);
}

static NODE*
match_op_gen(struct parser_params *parser, NODE *node1, NODE *node2)
{
    local_cnt('~');

    value_expr(node1);
    value_expr(node2);
    if (node1) {
	switch (nd_type(node1)) {
	  case NODE_DREGX:
	  case NODE_DREGX_ONCE:
	    return NEW_MATCH2(node1, node2);

	  case NODE_LIT:
	    if (TYPE(node1->nd_lit) == T_REGEXP) {
		return NEW_MATCH2(node1, node2);
	    }
	}
    }

    if (node2) {
	switch (nd_type(node2)) {
	  case NODE_DREGX:
	  case NODE_DREGX_ONCE:
	    return NEW_MATCH3(node2, node1);

	  case NODE_LIT:
	    if (TYPE(node2->nd_lit) == T_REGEXP) {
		return NEW_MATCH3(node2, node1);
	    }
	}
    }

    return NEW_CALL(node1, tMATCH, NEW_LIST(node2));
}

static NODE*
gettable_gen(struct parser_params *parser, ID id)
{
    if (id == keyword_self) {
	return NEW_SELF();
    }
    else if (id == keyword_nil) {
	return NEW_NIL();
    }
    else if (id == keyword_true) {
	return NEW_TRUE();
    }
    else if (id == keyword_false) {
	return NEW_FALSE();
    }
    else if (id == keyword__FILE__) {
	return NEW_STR(rb_str_new2(ruby_sourcefile));
    }
    else if (id == keyword__LINE__) {
	return NEW_LIT(INT2FIX(ruby_sourceline));
    }
    else if (is_local_id(id)) {
	if (dyna_in_block() && dvar_defined(id)) return NEW_DVAR(id);
	if (local_id(id)) return NEW_LVAR(id);
	/* method call without arguments */
	return NEW_VCALL(id);
    }
    else if (is_global_id(id)) {
	return NEW_GVAR(id);
    }
    else if (is_instance_id(id)) {
	return NEW_IVAR(id);
    }
    else if (is_const_id(id)) {
	return NEW_CONST(id);
    }
    else if (is_class_id(id)) {
	return NEW_CVAR(id);
    }
    rb_compile_error("identifier %s is not valid", rb_id2name(id));
    return 0;
}

static NODE*
assignable_gen(struct parser_params *parser, ID id, NODE *val)
{
    value_expr(val);
    if (id == keyword_self) {
	yyerror("Can't change the value of self");
    }
    else if (id == keyword_nil) {
	yyerror("Can't assign to nil");
    }
    else if (id == keyword_true) {
	yyerror("Can't assign to true");
    }
    else if (id == keyword_false) {
	yyerror("Can't assign to false");
    }
    else if (id == keyword__FILE__) {
	yyerror("Can't assign to __FILE__");
    }
    else if (id == keyword__LINE__) {
	yyerror("Can't assign to __LINE__");
    }
    else if (is_local_id(id)) {
	if (dvar_curr(id)) {
	    return NEW_DASGN_CURR(id, val);
	}
	else if (dvar_defined(id)) {
	    return NEW_DASGN(id, val);
	}
	else if (local_id(id) || !dyna_in_block()) {
	    return NEW_LASGN(id, val);
	}
	else{
	    dyna_var(id);
	    return NEW_DASGN_CURR(id, val);
	}
    }
    else if (is_global_id(id)) {
	return NEW_GASGN(id, val);
    }
    else if (is_instance_id(id)) {
	return NEW_IASGN(id, val);
    }
    else if (is_const_id(id)) {
	if (in_def || in_single)
	    yyerror("dynamic constant assignment");
	return NEW_CDECL(id, val, 0);
    }
    else if (is_class_id(id)) {
	return NEW_CVASGN(id, val);
    }
    else {
	rb_compile_error("identifier %s is not valid", rb_id2name(id));
    }
    return 0;
}

static void
shadowing_lvar_gen(struct parser_params *parser, ID name)
{
     if (dyna_in_block()) {
	 if (dvar_curr(name)) {
	     yyerror("duplicated argument name");
	 }
	 else if (dvar_defined(name) || local_id(name)) {
	     rb_warningS("shadowing outer local variable - %s", rb_id2name(name));
	 }
	 dyna_var(name);
     }
     else {
	 if (local_id(name)) {
	     yyerror("duplicated argument name");
	 }
	 local_cnt(name);
     }
}

static NODE*
new_bv_gen(struct parser_params *parser, ID name, NODE *val)
{
    if (!is_local_id(name)) {
	compile_error(PARSER_ARG "invalid local variable - %s",
		      rb_id2name(name));
	return 0;
    }
    shadowing_lvar(name);
    dyna_var(name);
    return NEW_DASGN_CURR(name, val);
}

static NODE *
aryset_gen(struct parser_params *parser, NODE *recv, NODE *idx)
{
    if (recv && nd_type(recv) == NODE_SELF)
	recv = (NODE *)1;
    else
	value_expr(recv);
    return NEW_ATTRASGN(recv, tASET, idx);
}

static void
block_dup_check(NODE *node1, NODE *node2)
{
    if (node2 && node1 && nd_type(node1) == NODE_BLOCK_PASS) {
	compile_error("both block arg and actual block given");
    }
}

ID
rb_id_attrset(ID id)
{
    id &= ~ID_SCOPE_MASK;
    id |= ID_ATTRSET;
    return id;
}

static NODE *
attrset_gen(struct parser_params *parser, NODE *recv, ID id)
{
    if (recv && nd_type(recv) == NODE_SELF)
	recv = (NODE *)1;
    else
	value_expr(recv);
    return NEW_ATTRASGN(recv, rb_id_attrset(id), 0);
}

static void
rb_backref_error(NODE *node)
{
    switch (nd_type(node)) {
      case NODE_NTH_REF:
	rb_compile_error("Can't set variable $%ld", node->nd_nth);
	break;
      case NODE_BACK_REF:
	rb_compile_error("Can't set variable $%c", (int)node->nd_nth);
	break;
    }
}

static NODE *
arg_concat(NODE *node1, NODE *node2)
{
    if (!node2) return node1;
    if (nd_type(node1) == NODE_BLOCK_PASS) {
	node1->nd_iter = arg_concat(node1->nd_iter, node2);
	return node1;
    }
    return NEW_ARGSCAT(node1, node2);
}

static NODE *
arg_append(NODE *node1, NODE *node2)
{
    if (!node1) return NEW_LIST(node2);
    switch (nd_type(node1))  {
      case NODE_ARRAY:
	return list_append(node1, node2);
      case NODE_BLOCK_PASS:
	node1->nd_head = arg_append(node1->nd_head, node2);
	return node1;
      default:
	return NEW_ARGSPUSH(node1, node2);
    }
}

static NODE *
arg_add(NODE *node1, NODE *node2)
{
    if (!node1) return NEW_LIST(node2);
    switch (nd_type(node1))  {
      case NODE_ARRAY:
	return list_append(node1, node2);
      case NODE_BLOCK_PASS:
	node1->nd_head = arg_add(node1->nd_head, node2);
	return node1;
      default:
	return NEW_ARGSPUSH(node1, node2);
    }
}

static NODE*
node_assign_gen(struct parser_params *parser, NODE *lhs, NODE *rhs)
{
    if (!lhs) return 0;

    value_expr(rhs);
    switch (nd_type(lhs)) {
      case NODE_GASGN:
      case NODE_IASGN:
      case NODE_IASGN2:
      case NODE_LASGN:
      case NODE_DASGN:
      case NODE_DASGN_CURR:
      case NODE_MASGN:
      case NODE_CDECL:
      case NODE_CVASGN:
	lhs->nd_value = rhs;
	break;

      case NODE_ATTRASGN:
      case NODE_CALL:
	lhs->nd_args = arg_add(lhs->nd_args, rhs);
	break;

      default:
	/* should not happen */
	break;
    }

    return lhs;
}

static int
value_expr_gen(struct parser_params *parser, NODE *node)
{
    int cond = 0;

    while (node) {
	switch (nd_type(node)) {
	  case NODE_DEFN:
	  case NODE_DEFS:
	    parser_warning(node, "void value expression");
	    return Qfalse;

	  case NODE_RETURN:
	  case NODE_BREAK:
	  case NODE_NEXT:
	  case NODE_REDO:
	  case NODE_RETRY:
	    if (!cond) yyerror("void value expression");
	    /* or "control never reach"? */
	    return Qfalse;

	  case NODE_BLOCK:
	    while (node->nd_next) {
		node = node->nd_next;
	    }
	    node = node->nd_head;
	    break;

	  case NODE_BEGIN:
	    node = node->nd_body;
	    break;

	  case NODE_IF:
	    if (!value_expr(node->nd_body)) return Qfalse;
	    node = node->nd_else;
	    break;

	  case NODE_AND:
	  case NODE_OR:
	    cond = 1;
	    node = node->nd_2nd;
	    break;

	  default:
	    return Qtrue;
	}
    }

    return Qtrue;
}

static void
void_expr_gen(struct parser_params *parser, NODE *node)
{
    const char *useless = 0;

    if (!RTEST(ruby_verbose)) return;

    if (!node) return;
    switch (nd_type(node)) {
      case NODE_CALL:
	switch (node->nd_mid) {
	  case '+':
	  case '-':
	  case '*':
	  case '/':
	  case '%':
	  case tPOW:
	  case tUPLUS:
	  case tUMINUS:
	  case '|':
	  case '^':
	  case '&':
	  case tCMP:
	  case '>':
	  case tGEQ:
	  case '<':
	  case tLEQ:
	  case tEQ:
	  case tNEQ:
	    useless = rb_id2name(node->nd_mid);
	    break;
	}
	break;

      case NODE_LVAR:
      case NODE_DVAR:
      case NODE_GVAR:
      case NODE_IVAR:
      case NODE_CVAR:
      case NODE_NTH_REF:
      case NODE_BACK_REF:
	useless = "a variable";
	break;
      case NODE_CONST:
      case NODE_CREF:
	useless = "a constant";
	break;
      case NODE_LIT:
      case NODE_STR:
      case NODE_DSTR:
      case NODE_DREGX:
      case NODE_DREGX_ONCE:
	useless = "a literal";
	break;
      case NODE_COLON2:
      case NODE_COLON3:
	useless = "::";
	break;
      case NODE_DOT2:
	useless = "..";
	break;
      case NODE_DOT3:
	useless = "...";
	break;
      case NODE_SELF:
	useless = "self";
	break;
      case NODE_NIL:
	useless = "nil";
	break;
      case NODE_TRUE:
	useless = "true";
	break;
      case NODE_FALSE:
	useless = "false";
	break;
      case NODE_DEFINED:
	useless = "defined?";
	break;
    }

    if (useless) {
	int line = ruby_sourceline;

	ruby_sourceline = nd_line(node);
	rb_warn("useless use of %s in void context", useless);
	ruby_sourceline = line;
    }
}

static void
void_stmts_gen(struct parser_params *parser, NODE *node)
{
    if (!RTEST(ruby_verbose)) return;
    if (!node) return;
    if (nd_type(node) != NODE_BLOCK) return;

    for (;;) {
	if (!node->nd_next) return;
	void_expr(node->nd_head);
	node = node->nd_next;
    }
}

static NODE *
remove_begin(NODE *node)
{
    NODE **n = &node;
    while (*n) {
	if (nd_type(*n) != NODE_BEGIN) {
	    return node;
	}
	*n = (*n)->nd_body;
    }
    return node;
}

static void
reduce_nodes(NODE **body)
{
    NODE *node = *body;

    if (!node) {
	*body = NEW_NIL();
	return;
    }
#define subnodes(n1, n2) \
    ((!node->n1) ? (node->n2 ? (body = &node->n2, 1) : 0) : \
     (!node->n2) ? (body = &node->n1, 1) : \
     (reduce_nodes(&node->n1), body = &node->n2, 1))

    while (node) {
	switch (nd_type(node)) {
	  end:
	  case NODE_NIL:
	    *body = 0;
	    return;
	  case NODE_RETURN:
	    *body = node = node->nd_stts;
	    continue;
	  case NODE_BEGIN:
	    *body = node = node->nd_body;
	    continue;
	  case NODE_BLOCK:
	    body = &node->nd_end->nd_head;
	    break;
	  case NODE_IF:
	    if (subnodes(nd_body, nd_else)) break;
	    return;
	  case NODE_CASE:
	    body = &node->nd_body;
	    break;
	  case NODE_WHEN:
	    if (!subnodes(nd_body, nd_next)) goto end;
	    break;
	  case NODE_ENSURE:
	    if (!subnodes(nd_head, nd_resq)) goto end;
	    break;
	  case NODE_RESCUE:
	    if (!subnodes(nd_head, nd_resq)) goto end;
	    break;
	  default:
	    return;
	}
	node = *body;
    }

#undef subnodes
}

static int
assign_in_cond(struct parser_params *parser, NODE *node)
{
    switch (nd_type(node)) {
      case NODE_MASGN:
	yyerror("multiple assignment in conditional");
	return 1;

      case NODE_LASGN:
      case NODE_DASGN:
      case NODE_GASGN:
      case NODE_IASGN:
	break;

      default:
	return 0;
    }

    switch (nd_type(node->nd_value)) {
      case NODE_LIT:
      case NODE_STR:
      case NODE_NIL:
      case NODE_TRUE:
      case NODE_FALSE:
	/* reports always */
	parser_warn(node->nd_value, "found = in conditional, should be ==");
	return 1;

      case NODE_DSTR:
      case NODE_XSTR:
      case NODE_DXSTR:
      case NODE_EVSTR:
      case NODE_DREGX:
      default:
	break;
    }
    return 1;
}

static int
e_option_supplied(void)
{
    if (strcmp(ruby_sourcefile, "-e") == 0)
	return Qtrue;
    return Qfalse;
}

static void
warn_unless_e_option(NODE *node, const char *str)
{
    if (!e_option_supplied()) parser_warn(node, str);
}

static void
warning_unless_e_option(NODE *node, const char *str)
{
    if (!e_option_supplied()) parser_warning(node, str);
}

static NODE *cond0(struct parser_params*,NODE*);

static NODE*
range_op(struct parser_params *parser, NODE *node)
{
    enum node_type type;

    if (!e_option_supplied()) return node;
    if (node == 0) return 0;

    value_expr(node);
    node = cond0(parser, node);
    type = nd_type(node);
    if (type == NODE_LIT && FIXNUM_P(node->nd_lit)) {
	warn_unless_e_option(node, "integer literal in conditional range");
	return call_op(node,tEQ,1,NEW_GVAR(rb_intern("$.")));
    }
    return node;
}

static int
literal_node(NODE *node)
{
    if (!node) return 1;	/* same as NODE_NIL */
    switch (nd_type(node)) {
      case NODE_LIT:
      case NODE_STR:
      case NODE_DSTR:
      case NODE_EVSTR:
      case NODE_DREGX:
      case NODE_DREGX_ONCE:
      case NODE_DSYM:
	return 2;
      case NODE_TRUE:
      case NODE_FALSE:
      case NODE_NIL:
	return 1;
    }
    return 0;
}

static NODE*
cond0(struct parser_params *parser, NODE *node)
{
    if (node == 0) return 0;
    assign_in_cond(parser, node);

    switch (nd_type(node)) {
      case NODE_DSTR:
      case NODE_EVSTR:
      case NODE_STR:
	rb_warn("string literal in condition");
	break;

      case NODE_DREGX:
      case NODE_DREGX_ONCE:
	warning_unless_e_option(node, "regex literal in condition");
	local_cnt('_');
	local_cnt('~');
	return NEW_MATCH2(node, NEW_GVAR(rb_intern("$_")));

      case NODE_AND:
      case NODE_OR:
	node->nd_1st = cond0(parser, node->nd_1st);
	node->nd_2nd = cond0(parser, node->nd_2nd);
	break;

      case NODE_DOT2:
      case NODE_DOT3:
	node->nd_beg = range_op(parser, node->nd_beg);
	node->nd_end = range_op(parser, node->nd_end);
	if (nd_type(node) == NODE_DOT2) nd_set_type(node,NODE_FLIP2);
	else if (nd_type(node) == NODE_DOT3) nd_set_type(node, NODE_FLIP3);
	node->nd_cnt = local_append(internal_id());
	if (!e_option_supplied()) {
	    int b = literal_node(node->nd_beg);
	    int e = literal_node(node->nd_end);
	    if ((b == 1 && e == 1) || (b + e >= 2 && RTEST(ruby_verbose))) {
		parser_warn(node, "range literal in condition");
	    }
	}
	break;

      case NODE_DSYM:
	parser_warning(node, "literal in condition");
	break;

      case NODE_LIT:
	if (TYPE(node->nd_lit) == T_REGEXP) {
	    warn_unless_e_option(node, "regex literal in condition");
	    nd_set_type(node, NODE_MATCH);
	    local_cnt('_');
	    local_cnt('~');
	}
	else {
	    parser_warning(node, "literal in condition");
	}
      default:
	break;
    }
    return node;
}

static NODE*
cond_gen(struct parser_params *parser, NODE *node)
{
    if (node == 0) return 0;
    value_expr(node);
    return cond0(parser, node);
}

static NODE*
logop_gen(struct parser_params *parser, enum node_type type, NODE *left, NODE *right)
{
    value_expr(left);
    if (left && nd_type(left) == type) {
	NODE *node = left, *second;
	while ((second = node->nd_2nd) != 0 && nd_type(second) == type) {
	    node = second;
	}
	node->nd_2nd = NEW_NODE(type, second, right, 0);
	return left;
    }
    return NEW_NODE(type, left, right, 0);
}

static int
cond_negative(NODE **nodep)
{
    NODE *c = *nodep;

    if (!c) return 0;
    switch (nd_type(c)) {
      case NODE_NOT:
	*nodep = c->nd_body;
	return 1;
    }
    return 0;
}

static void
no_blockarg(NODE *node)
{
    if (node && nd_type(node) == NODE_BLOCK_PASS) {
	rb_compile_error("block argument should not be given");
    }
}

static NODE *
ret_args(NODE *node)
{
    if (node) {
	no_blockarg(node);
	if (nd_type(node) == NODE_ARRAY) {
	    if (node->nd_next == 0) {
		node = node->nd_head;
	    }
	    else {
		nd_set_type(node, NODE_VALUES);
	    }
	}
    }
    return node;
}

static NODE *
new_yield(NODE *node)
{
    long state = Qtrue;

    if (node) {
        no_blockarg(node);
        if (nd_type(node) == NODE_ARRAY && node->nd_next == 0) {
            node = node->nd_head;
            state = Qfalse;
        }
        else if (node && nd_type(node) == NODE_SPLAT) {
            state = Qtrue;
        }
    }
    else {
        state = Qfalse;
    }
    return NEW_YIELD(node, state);
}

static NODE*
negate_lit(NODE *node)
{
    switch (TYPE(node->nd_lit)) {
      case T_FIXNUM:
	node->nd_lit = LONG2FIX(-FIX2LONG(node->nd_lit));
	break;
      case T_BIGNUM:
	node->nd_lit = rb_funcall(node->nd_lit,tUMINUS,0,0);
	break;
      case T_FLOAT:
	RFLOAT(node->nd_lit)->value = -RFLOAT(node->nd_lit)->value;
	break;
      default:
	break;
    }
    return node;
}

static NODE *
arg_blk_pass(NODE *node1, NODE *node2)
{
    if (node2) {
	node2->nd_head = node1;
	return node2;
    }
    return node1;
}

static int
arg_dup_check(ID vid, VALUE m, VALUE list, NODE *node)
{
    VALUE sym;

    if (!vid) return 0;
    if (is_junk_id(vid)) return 0;
    sym = ID2SYM(vid);
    if ((m && rb_ary_includes(m, sym)) || rb_ary_includes(list, sym)) {
	ruby_sourceline = nd_line(node);
	return 1;
    }
    rb_ary_push(list, sym);		  
    return 0;
}

static NODE*
new_args_gen(struct parser_params *parser, int m, NODE *o, ID r, NODE *p, ID b)
{
    int saved_line = ruby_sourceline;
    NODE *node = NEW_ARGS(m, o);

    node->nd_next = NEW_ARGS_AUX(r, b);
    if (p) {
	node->nd_next->nd_next = p;
    }
    ruby_sourceline = saved_line;
    return node;
}

static void
local_push_gen(struct parser_params *parser, int inherit_dvars)
{
    struct local_vars *local;

    local = ALLOC(struct local_vars);
    local->prev = lvtbl;
    local->tbl = 0;
    local->dvars = inherit_dvars ? DVARS_INHERIT : DVARS_TOPSCOPE;
    lvtbl = local;
}

static void
local_pop_gen(struct parser_params *parser)
{
    struct local_vars *local = lvtbl->prev;
    vtable_free(lvtbl->tbl);
    vtable_free(lvtbl->dvars);
    xfree(lvtbl);
    lvtbl = local;
}

static ID*
vtable_to_tbl(struct vtable *src)
{
    int i, cnt = vtable_size(src);

    if (cnt > 0) {
        ID *tbl = ALLOC_N(ID, cnt + 1);
        tbl[0] = cnt;
        for (i = 0; i < cnt; i++) {
            tbl[i+1] = src->tbl[i];
        }
        return tbl;
    }
    return 0;
}

static ID*
local_tbl_gen(struct parser_params *parser)
{
    return vtable_to_tbl(lvtbl->tbl);
}

static ID*
dyna_tbl_gen(struct parser_params *parser)
{
    return vtable_to_tbl(lvtbl->dvars);
}

static int
local_append_gen(struct parser_params *parser, ID id)
{
    if (lvtbl->tbl == 0) {
	lvtbl->tbl = vtable_alloc(0);
	vtable_add(lvtbl->tbl, '_');
	vtable_add(lvtbl->tbl, '~');
	if (id == '_') return 0;
	if (id == '~') return 1;
    }
    vtable_add(lvtbl->tbl, id);
    return vtable_size(lvtbl->tbl) - 1;
}

static int
local_cnt_gen(struct parser_params *parser, ID id)
{
  int cnt, max;
  if (id == 0) return vtable_size(lvtbl->tbl);

  for (cnt=0, max=vtable_size(lvtbl->tbl); cnt<max;cnt++) {
    if (lvtbl->tbl->tbl[cnt] == id) {
      return cnt;
    }
  }
  return local_append(id);
}

static int
local_id_gen(struct parser_params *parser, ID id)
{
    if (lvtbl == 0) return Qfalse;
    return vtable_included(lvtbl->tbl, id);
}

extern int rb_dvar_current(void);
extern int rb_scope_base_local_tbl_size(void);
extern ID  rb_scope_base_local_tbl_id(int i);
extern void rb_scope_setup_top_local_tbl(ID *tbl);

static void
top_local_init_gen(struct parser_params *parser)
{
    int i, cnt;

    local_push(rb_dvar_current());
    if (cnt = rb_scope_base_local_tbl_size()) {
        if (lvtbl->tbl == 0) {
            lvtbl->tbl = vtable_alloc(0);
        }
        for (i = 0; i < cnt; i++) {
            vtable_add(lvtbl->tbl, rb_scope_base_local_tbl_id(i));
        }
    }
}

static void
top_local_setup_gen(struct parser_params *parser)
{
    if (lvtbl->dvars != 0) {
        /* eval */
        rb_scope_setup_top_local_tbl(dyna_tbl());
    }
    else {
        rb_scope_setup_top_local_tbl(local_tbl());
    }
    local_pop();
}

static void
dyna_var_gen(struct parser_params *parser, ID id)
{
    if (!POINTER_P(lvtbl->dvars)) {
        lvtbl->dvars = vtable_alloc(lvtbl->dvars);
    }
    vtable_add(lvtbl->dvars, id);
}

static void
dyna_push_gen(struct parser_params *parser)
{
    lvtbl->dvars = vtable_alloc(lvtbl->dvars);
}

static void
dyna_pop_gen(struct parser_params *parser)
{
    struct vtable *tmp = lvtbl->dvars;
    lvtbl->dvars = lvtbl->dvars->prev;
    vtable_free(tmp);
}

static int
dyna_in_block_gen(struct parser_params *parser)
{
    return lvtbl->dvars != DVARS_TOPSCOPE;
}

static NODE *
dyna_init_gen(struct parser_params *parser, NODE *node, int pre_cnt)
{
    NODE *var;
    int post_cnt = vtable_size(lvtbl->dvars);

    if (!node || pre_cnt == post_cnt) return node;
    for (var = 0; post_cnt != pre_cnt; post_cnt--) {
	var = NEW_DASGN_CURR(lvtbl->dvars->tbl[post_cnt-1], var);
    }
    return block_append(var, node);
}

static int
dvar_defined_gen(struct parser_params *parser, ID id)
{
    struct vtable *dvars = lvtbl->dvars;
    while(POINTER_P(dvars)){
      if(vtable_included(dvars, id)){
          return 1;
      }
      dvars = dvars->prev;
    }
    if(dvars == DVARS_INHERIT){
        return rb_dvar_defined(id);
    }
    return 0;
}

static int
dvar_curr_gen(struct parser_params *parser, ID id)
{
    return vtable_included(lvtbl->dvars, id);
}

void
rb_gc_mark_parser(void)
{
}

NODE*
rb_parser_append_print(NODE *node)
{
    NODE *prelude = 0;

    if (node && (nd_type(node) == NODE_PRELUDE)) {
	prelude = node;
	node = node->nd_body;
    }
    node = block_append(node,
			NEW_FCALL(rb_intern("print"),
				  NEW_ARRAY(NEW_GVAR(rb_intern("$_")))));
    if (prelude) {
	prelude->nd_body = node;
	return prelude;
    }
    return node;
}

NODE *
rb_parser_while_loop(NODE *node, int chop, int split)
{
    NODE *prelude = 0;

    if (node && (nd_type(node) == NODE_PRELUDE)) {
	prelude = node;
	node = node->nd_body;
    }
    if (split) {
	node = block_append(NEW_GASGN(rb_intern("$F"),
				      NEW_CALL(NEW_GVAR(rb_intern("$_")),
					       rb_intern("split"), 0)),
			    node);
    }
    if (chop) {
	node = block_append(NEW_CALL(NEW_GVAR(rb_intern("$_")),
				     rb_intern("chop!"), 0), node);
    }
    node = NEW_OPT_N(node);
    if (prelude) {
	prelude->nd_body = node;
	return prelude;
    }
    return node;
}

static const struct {
    ID token;
    const char *name;
} op_tbl[] = {
    {tDOT2,	".."},
    {tDOT3,	"..."},
    {'+',	"+"},
    {'-',	"-"},
    {'+',	"+(binary)"},
    {'-',	"-(binary)"},
    {'*',	"*"},
    {'/',	"/"},
    {'%',	"%"},
    {tPOW,	"**"},
    {tUPLUS,	"+@"},
    {tUMINUS,	"-@"},
    {tUPLUS,	"+(unary)"},
    {tUMINUS,	"-(unary)"},
    {'|',	"|"},
    {'^',	"^"},
    {'&',	"&"},
    {tCMP,	"<=>"},
    {'>',	">"},
    {tGEQ,	">="},
    {'<',	"<"},
    {tLEQ,	"<="},
    {tEQ,	"=="},
    {tEQQ,	"==="},
    {tNEQ,	"!="},
    {tMATCH,	"=~"},
    {tNMATCH,	"!~"},
    {'!',	"!"},
    {'~',	"~"},
    {'!',	"!(unary)"},
    {'~',	"~(unary)"},
    {'!',	"!@"},
    {'~',	"~@"},
    {tAREF,	"[]"},
    {tASET,	"[]="},
    {tLSHFT,	"<<"},
    {tRSHFT,	">>"},
    {tCOLON2,	"::"},
    {'`',	"`"},
    {0,	0}
};

static struct symbols {
    ID last_id;
    st_table *sym_id;
    st_table *id_str;
    st_table *ivar2_id;
    st_table *id_ivar2;
    VALUE op_sym[tLAST_TOKEN];
} global_symbols = {tLAST_TOKEN};

static struct st_hash_type symhash = {
    rb_str_cmp,
    rb_str_hash,
};

struct ivar2_key {
    ID id;
    VALUE klass;
};

static int
ivar2_cmp(struct ivar2_key *key1, struct ivar2_key *key2)
{
    if (key1->id == key2->id && key1->klass == key2->klass) {
	return 0;
    }
    return 1;
}

static int
ivar2_hash(struct ivar2_key *key)
{
    return (key->id << 8) ^ (key->klass >> 2);
}

static struct st_hash_type ivar2_hash_type = {
    ivar2_cmp,
    ivar2_hash,
};

void
Init_sym(void)
{
    global_symbols.sym_id = st_init_table_with_size(&symhash, 1000);
    global_symbols.id_str = st_init_numtable_with_size(1000);
    global_symbols.ivar2_id = st_init_table_with_size(&ivar2_hash_type, 1000);
    global_symbols.id_ivar2 = st_init_numtable_with_size(1000);
}

void
rb_gc_mark_symbols(void)
{
    rb_mark_tbl(global_symbols.id_str);
    rb_gc_mark_locations(global_symbols.op_sym,
			 global_symbols.op_sym + tLAST_TOKEN);
}

static ID
internal_id(void)
{
    return ID_INTERNAL | (++global_symbols.last_id << ID_SCOPE_SHIFT);
}

static int
is_special_global_name(const char *m)
{
    switch (*m) {
      case '~': case '*': case '$': case '?': case '!': case '@':
      case '/': case '\\': case ';': case ',': case '.': case '=':
      case ':': case '<': case '>': case '\"':
      case '&': case '`': case '\'': case '+':
      case '0':
	++m;
	break;
      case '-':
	++m;
	if (is_identchar(*m)) m += mbclen(*m);
	break;
      default:
	if (!ISDIGIT(*m)) return 0;
	do ++m; while (ISDIGIT(*m));
    }
    return !*m;
}

int
rb_symname_p(const char *name)
{
    const char *m = name;
    int localid = Qfalse;

    if (!m) return Qfalse;
    switch (*m) {
      case '\0':
	return Qfalse;

      case '$':
	if (is_special_global_name(++m)) return Qtrue;
	goto id;

      case '@':
	if (*++m == '@') ++m;
	goto id;

      case '<':
	switch (*++m) {
	  case '<': ++m; break;
	  case '=': if (*++m == '>') ++m; break;
	  default: break;
	}
	break;

      case '>':
	switch (*++m) {
	  case '>': case '=': ++m; break;
	}
	break;

      case '=':
	switch (*++m) {
	  case '~': ++m; break;
	  case '=': if (*++m == '=') ++m; break;
	  default: return Qfalse;
	}
	break;

      case '*':
	if (*++m == '*') ++m;
	break;

      case '+': case '-':
	if (*++m == '@') ++m;
	break;

      case '|': case '^': case '&': case '/': case '%': case '~': case '`':
	++m;
	break;

      case '[':
	if (*++m != ']') return Qfalse;
	if (*++m == '=') ++m;
	break;

      default:
	localid = !ISUPPER(*m);
      id:
	if (*m != '_' && !ISALPHA(*m) && !ismbchar(*m)) return Qfalse;
	while (is_identchar(*m)) m += mbclen(*m);
	if (localid) {
	    switch (*m) {
	      case '!': case '?': case '=': ++m;
	    }
	}
	break;
    }
    return *m ? Qfalse : Qtrue;
}

ID
rb_intern2(const char *name, long len)
{
    const char *m = name;
    VALUE str = rb_str_new(name, len);
    ID id;
    int last;

    if (st_lookup(global_symbols.sym_id, (st_data_t)str, (st_data_t *)&id))
	return id;

    last = len-1;
    id = 0;
    switch (*name) {
      case '$':
	id |= ID_GLOBAL;
	if (is_special_global_name(++m)) goto new_id;
	break;
      case '@':
	if (name[1] == '@') {
	    m++;
	    id |= ID_CLASS;
	}
	else {
	    id |= ID_INSTANCE;
	}
	m++;
	break;
      default:
	if (name[0] != '_' && ISASCII(name[0]) && !ISALNUM(name[0])) {
	    /* operators */
	    int i;

	    for (i=0; op_tbl[i].token; i++) {
		if (*op_tbl[i].name == *name &&
		    strcmp(op_tbl[i].name, name) == 0) {
		    id = op_tbl[i].token;
		    goto id_register;
		}
	    }
	}

	if (name[last] == '=') {
	    /* attribute assignment */
	    char *buf = ALLOCA_N(char,last+1);

	    strncpy(buf, name, last);
	    buf[last] = '\0';
	    id = rb_intern(buf);
	    if (id > tLAST_TOKEN && !is_attrset_id(id)) {
		id = rb_id_attrset(id);
		goto id_register;
	    }
	    id = ID_ATTRSET;
	}
	else if (ISUPPER(name[0])) {
	    id = ID_CONST;
        }
	else {
	    id = ID_LOCAL;
	}
	break;
    }
    if (!ISDIGIT(*m)) {
    while (m <= name + last && is_identchar(*m)) {
	m += mbclen(*m);
    }
    }
    if (*m) id = ID_JUNK;
  new_id:
    id |= ++global_symbols.last_id << ID_SCOPE_SHIFT;
  id_register:
    OBJ_FREEZE(str);
    st_add_direct(global_symbols.sym_id, (st_data_t)str, id);
    st_add_direct(global_symbols.id_str, id, (st_data_t)str);
    return id;
}

ID
rb_intern(const char *name)
{
    return rb_intern2(name, strlen(name));
}

VALUE
rb_id2str(ID id)
{
    const char *name;
    st_data_t data;

    if (id < tLAST_TOKEN) {
	int i = 0;

	for (i=0; op_tbl[i].token; i++) {
	    if (op_tbl[i].token == id) {
		VALUE str = global_symbols.op_sym[i];
		if (!str) {
		    str = rb_str_new2(op_tbl[i].name);
		    OBJ_FREEZE(str);
		    global_symbols.op_sym[i] = str;
		}
		return str;
	    }
	}
    }

    if (st_lookup(global_symbols.id_str, id, &data))
	return (VALUE)data;

    if (is_attrset_id(id)) {
	ID id2 = (id & ~ID_SCOPE_MASK) | ID_LOCAL;

      again:
	name = rb_id2name(id2);
	if (name) {
	    char *buf = ALLOCA_N(char, strlen(name)+2);

	    strcpy(buf, name);
	    strcat(buf, "=");
	    rb_intern(buf);
	    return rb_id2str(id);
	}
	if (is_local_id(id2)) {
	    id2 = (id & ~ID_SCOPE_MASK) | ID_CONST;
	    goto again;
	}
    }
    return 0;
}

const char *
rb_id2name(ID id)
{
    VALUE str = rb_id2str(id);

    if (!str) return 0;
    return RSTRING_PTR(str);
}

static int
symbols_i(VALUE sym, ID value, VALUE ary)
{
    rb_ary_push(ary, ID2SYM(value));
    return ST_CONTINUE;
}

/*
 *  call-seq:
 *     Symbol.all_symbols    => array
 *  
 *  Returns an array of all the symbols currently in Ruby's symbol
 *  table.
 *     
 *     Symbol.all_symbols.size    #=> 903
 *     Symbol.all_symbols[1,20]   #=> [:floor, :ARGV, :Binding, :symlink,
 *                                     :chown, :EOFError, :$;, :String, 
 *                                     :LOCK_SH, :"setuid?", :$<, 
 *                                     :default_proc, :compact, :extend, 
 *                                     :Tms, :getwd, :$=, :ThreadGroup,
 *                                     :wait2, :$>]
 */

VALUE
rb_sym_all_symbols(void)
{
    VALUE ary = rb_ary_new2(global_symbols.sym_id->num_entries);

    st_foreach(global_symbols.sym_id, symbols_i, ary);
    return ary;
}

int
rb_is_const_id(ID id)
{
    if (is_const_id(id)) return Qtrue;
    return Qfalse;
}

int
rb_is_class_id(ID id)
{
    if (is_class_id(id)) return Qtrue;
    return Qfalse;
}

int
rb_is_instance_id(ID id)
{
    if (is_instance_id(id)) return Qtrue;
    return Qfalse;
}

int
rb_is_local_id(ID id)
{
    if (is_local_id(id)) return Qtrue;
    return Qfalse;
}

int
rb_is_junk_id(ID id)
{
    if (is_junk_id(id)) return Qtrue;
    return Qfalse;
}

#endif /* !RIPPER */

static void
parser_initialize(struct parser_params *parser)
{
    parser->eofp = Qfalse;

    parser->parser_lex_strterm = 0;
    parser->parser_cond_stack = 0;
    parser->parser_cmdarg_stack = 0;
    parser->parser_class_nest = 0;
    parser->parser_paren_nest = 0;
    parser->parser_lpar_beg = 0;
    parser->parser_in_single = 0;
    parser->parser_in_def = 0;
    parser->parser_in_defined = 0;
    parser->parser_compile_for_eval = 0;
    parser->parser_cur_mid = 0;
    parser->parser_tokenbuf = NULL;
    parser->parser_tokidx = 0;
    parser->parser_toksiz = 0;
    parser->parser_heredoc_end = 0;
    parser->parser_command_start = Qtrue;
    parser->parser_lex_pbeg = 0;
    parser->parser_lex_p = 0;
    parser->parser_lex_pend = 0;
    parser->parser_lvtbl = 0;
    parser->parser_ruby__end__seen = 0;
#ifndef RIPPER
    parser->parser_eval_tree_begin = 0;
    parser->parser_eval_tree = 0;
#else
    parser->parser_ruby_sourcefile = Qnil;
    parser->delayed = Qnil;

    parser->result = Qnil;
    parser->parsing_thread = Qnil;
    parser->toplevel_p = Qtrue;
#endif
#ifdef YYMALLOC
    parser->heap = NULL;
#endif
}

static void
parser_mark(void *ptr)
{
    struct parser_params *p = (struct parser_params*)ptr;

    rb_gc_mark((VALUE)p->parser_lex_strterm);
    rb_gc_mark(p->parser_lex_input);
    rb_gc_mark(p->parser_lex_lastline);
#ifndef RIPPER
    rb_gc_mark((VALUE)p->parser_eval_tree_begin) ;
    rb_gc_mark((VALUE)p->parser_eval_tree) ;
    rb_gc_mark(p->debug_lines);
#else
    rb_gc_mark(p->parser_ruby_sourcefile);
    rb_gc_mark(p->delayed);
    rb_gc_mark(p->value);
    rb_gc_mark(p->result);
    rb_gc_mark(p->parsing_thread);
#endif
#ifdef YYMALLOC
    rb_gc_mark((VALUE)p->heap);
#endif
}

static void
parser_free(void *ptr)
{
    struct parser_params *p = (struct parser_params*)ptr;
    struct local_vars *local, *prev;

    if (p->parser_tokenbuf) {
        xfree(p->parser_tokenbuf);
    }
    for (local = p->parser_lvtbl; local; local = prev) {
	if (local->tbl) xfree(local->tbl);
	prev = local->prev;
	xfree(local);
    }
    xfree(p);
}

#ifndef RIPPER
static struct parser_params *
parser_new(void)
{
    struct parser_params *p;

    p = ALLOC_N(struct parser_params, 1);
    MEMZERO(p, struct parser_params, 1);
    parser_initialize(p);
    return p;
}

VALUE
rb_parser_new(void)
{
    struct parser_params *p = parser_new();

    return Data_Wrap_Struct(0, parser_mark, parser_free, p);
}

/*
 *  call-seq:
 *    ripper#end_seen?   -> Boolean
 *
 *  Return if parsed source ended by +\_\_END\_\_+.
 *  This number starts from 1.
 */
VALUE
rb_parser_end_seen_p(VALUE vparser)
{
    struct parser_params *parser;

    Data_Get_Struct(vparser, struct parser_params, parser);
    return ruby__end__seen ? Qtrue : Qfalse;
}

#ifdef YYMALLOC
#define HEAPCNT(n, size) ((n) * (size) / sizeof(YYSTYPE))
#define NEWHEAP() rb_node_newnode(NODE_ALLOCA, 0, (VALUE)parserp->heap, 0)
#define ADD2HEAP(n, c, p) ((parserp->heap = (n))->u1.node = (p), \
			   (n)->u3.cnt = (c), (p))

void *
rb_parser_malloc(struct parser_params *parserp, size_t size)
{
    size_t cnt = HEAPCNT(1, size);
    NODE *n = NEWHEAP();
    void *ptr = xmalloc(size);

    return ADD2HEAP(n, cnt, ptr);
}

void *
rb_parser_calloc(struct parser_params *parserp, size_t nelem, size_t size)
{
    size_t cnt = HEAPCNT(nelem, size);
    NODE *n = NEWHEAP();
    void *ptr = xcalloc(nelem, size);

    return ADD2HEAP(n, cnt, ptr);
}

void *
rb_parser_realloc(struct parser_params *parserp, void *ptr, size_t size)
{
    NODE *n;
    size_t cnt = HEAPCNT(1, size);

    if (ptr && (n = parserp->heap) != NULL) {
	do {
	    if (n->u1.node == ptr) {
		n->u1.node = ptr = xrealloc(ptr, size);
		if (n->u3.cnt) n->u3.cnt = cnt;
		return ptr;
	    }
	} while ((n = n->u2.node) != NULL);
    }
    n = NEWHEAP();
    ptr = xrealloc(ptr, size);
    return ADD2HEAP(n, cnt, ptr);
}

void
rb_parser_free(struct parser_params *parserp, void *ptr)
{
    NODE **prev = &parserp->heap, *n;

    while ((n = *prev) != NULL) {
	if (n->u1.node == ptr) {
	    *prev = n->u2.node;
	    rb_gc_force_recycle((VALUE)n);
	    break;
	}
	prev = &n->u2.node;
    }
    xfree(ptr);
}
#endif
#endif

#ifdef RIPPER
#ifdef RIPPER_DEBUG
extern int rb_is_pointer_to_heap(VALUE);

/* :nodoc: */
static VALUE
ripper_validate_object(VALUE self, VALUE x)
{
    if (x == Qfalse) return x;
    if (x == Qtrue) return x;
    if (x == Qnil) return x;
    if (x == Qundef)
        rb_raise(rb_eArgError, "Qundef given");
    if (FIXNUM_P(x)) return x;
    if (SYMBOL_P(x)) return x;
    if (!rb_is_pointer_to_heap(x))
        rb_raise(rb_eArgError, "invalid pointer: %p", x);
    switch (TYPE(x)) {
      case T_STRING:
      case T_OBJECT:
      case T_ARRAY:
      case T_BIGNUM:
      case T_FLOAT:
        return x;
      case T_NODE:
        rb_raise(rb_eArgError, "NODE given: %p", x);
      default:
        rb_raise(rb_eArgError, "wrong type of ruby object: %p (%s)",
                 x, rb_obj_classname(x));
    }
    return x;
}
#endif

#define validate(x)

static VALUE
ripper_dispatch0(struct parser_params *parser, ID mid)
{
    return rb_funcall(parser->value, mid, 0);
}

static VALUE
ripper_dispatch1(struct parser_params *parser, ID mid, VALUE a)
{
    validate(a);
    return rb_funcall(parser->value, mid, 1, a);
}

static VALUE
ripper_dispatch2(struct parser_params *parser, ID mid, VALUE a, VALUE b)
{
    validate(a);
    validate(b);
    return rb_funcall(parser->value, mid, 2, a, b);
}

static VALUE
ripper_dispatch3(struct parser_params *parser, ID mid, VALUE a, VALUE b, VALUE c)
{
    validate(a);
    validate(b);
    validate(c);
    return rb_funcall(parser->value, mid, 3, a, b, c);
}

static VALUE
ripper_dispatch4(struct parser_params *parser, ID mid, VALUE a, VALUE b, VALUE c, VALUE d)
{
    validate(a);
    validate(b);
    validate(c);
    validate(d);
    return rb_funcall(parser->value, mid, 4, a, b, c, d);
}

static VALUE
ripper_dispatch5(struct parser_params *parser, ID mid, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e)
{
    validate(a);
    validate(b);
    validate(c);
    validate(d);
    validate(e);
    return rb_funcall(parser->value, mid, 5, a, b, c, d, e);
}

static struct kw_assoc {
    ID id;
    const char *name;
} keyword_to_name[] = {
    {keyword_class,	"class"},
    {keyword_module,	"module"},
    {keyword_def,	"def"},
    {keyword_undef,	"undef"},
    {keyword_begin,	"begin"},
    {keyword_rescue,	"rescue"},
    {keyword_ensure,	"ensure"},
    {keyword_end,	"end"},
    {keyword_if,	"if"},
    {keyword_unless,	"unless"},
    {keyword_then,	"then"},
    {keyword_elsif,	"elsif"},
    {keyword_else,	"else"},
    {keyword_case,	"case"},
    {keyword_when,	"when"},
    {keyword_while,	"while"},
    {keyword_until,	"until"},
    {keyword_for,	"for"},
    {keyword_break,	"break"},
    {keyword_next,	"next"},
    {keyword_redo,	"redo"},
    {keyword_retry,	"retry"},
    {keyword_in,	"in"},
    {keyword_do,	"do"},
    {keyword_do_cond,	"do"},
    {keyword_do_block,	"do"},
    {keyword_return,	"return"},
    {keyword_yield,	"yield"},
    {keyword_super,	"super"},
    {keyword_self,	"self"},
    {keyword_nil,	"nil"},
    {keyword_true,	"true"},
    {keyword_false,	"false"},
    {keyword_and,	"and"},
    {keyword_or,	"or"},
    {keyword_not,	"not"},
    {modifier_if,	"if"},
    {modifier_unless,	"unless"},
    {modifier_while,	"while"},
    {modifier_until,	"until"},
    {modifier_rescue,	"rescue"},
    {keyword_alias,	"alias"},
    {keyword_defined,	"defined?"},
    {keyword_BEGIN,	"BEGIN"},
    {keyword_END,	"END"},
    {keyword__LINE__,	"__LINE__"},
    {keyword__FILE__,	"__FILE__"},
    {0, NULL}
};

static const char*
keyword_id_to_str(ID id)
{
    struct kw_assoc *a;

    for (a = keyword_to_name; a->id; a++) {
        if (a->id == id)
            return a->name;
    }
    return NULL;
}

static VALUE
ripper_id2sym(ID id)
{
    const char *name;
    char buf[8];

    if (id <= 256) {
        buf[0] = id;
        buf[1] = '\0';
        return ID2SYM(rb_intern(buf));
    }
    if ((name = keyword_id_to_str(id))) {
        return ID2SYM(rb_intern(name));
    }
    switch (id) {
    case tOROP:
        name = "||";
        break;
    case tANDOP:
        name = "&&";
        break;
    default:
        name = rb_id2name(id);
        if (!name) {
            rb_bug("cannot convert ID to string: %ld", (unsigned long)id);
        }
        break;
    }
    return ID2SYM(rb_intern(name));
}

static VALUE
ripper_intern(const char *s)
{
    return ID2SYM(rb_intern(s));
}

static void
ripper_compile_error(struct parser_params *parser, const char *fmt, ...)
{
    VALUE str;
    va_list args;

    va_start(args, fmt);
    str = rb_vsprintf(fmt, args);
    va_end(args);
    rb_funcall(parser->value, rb_intern("compile_error"), 1, str);
}

static void
ripper_warn0(struct parser_params *parser, const char *fmt)
{
    rb_funcall(parser->value, rb_intern("warn"), 1, rb_str_new2(fmt));
}

static void
ripper_warnI(struct parser_params *parser, const char *fmt, int a)
{
    rb_funcall(parser->value, rb_intern("warn"), 2,
               rb_str_new2(fmt), INT2NUM(a));
}

static void
ripper_warnS(struct parser_params *parser, const char *fmt, const char *str)
{
    rb_funcall(parser->value, rb_intern("warn"), 2,
    	       rb_str_new2(fmt), rb_str_new2(str));
}

static void
ripper_warning0(struct parser_params *parser, const char *fmt)
{
    rb_funcall(parser->value, rb_intern("warning"), 1, rb_str_new2(fmt));
}

static void
ripper_warningS(struct parser_params *parser, const char *fmt, const char *str)
{
    rb_funcall(parser->value, rb_intern("warning"), 2,
    	       rb_str_new2(fmt), rb_str_new2(str));
}

static VALUE
ripper_lex_get_generic(struct parser_params *parser, VALUE src)
{
    return rb_funcall(src, ripper_id_gets, 0);
}

static VALUE
ripper_s_allocate(VALUE klass)
{
    struct parser_params *p;
    VALUE self;

    p = ALLOC_N(struct parser_params, 1);
    MEMZERO(p, struct parser_params, 1);
    self = Data_Wrap_Struct(klass, parser_mark, parser_free, p);
    p->value = self;
    return self;
}

#define ripper_initialized_p(r) ((r)->parser_lex_input != 0)

/*
 *  call-seq:
 *    Ripper.new(src, filename="(ripper)", lineno=1) -> ripper
 *
 *  Create a new Ripper object.
 *  _src_ must be a String, a IO, or an Object which has #gets method.
 *
 *  This method does not starts parsing.
 *  See also Ripper#parse and Ripper.parse.
 */
static VALUE
ripper_initialize(int argc, VALUE *argv, VALUE self)
{
    struct parser_params *parser;
    VALUE src, fname, lineno;

    Data_Get_Struct(self, struct parser_params, parser);
    rb_scan_args(argc, argv, "12", &src, &fname, &lineno);
    if (rb_obj_respond_to(src, ripper_id_gets, 0)) {
        parser->parser_lex_gets = ripper_lex_get_generic;
    }
    else {
        StringValue(src);
        parser->parser_lex_gets = lex_get_str;
    }
    parser->parser_lex_input = src;
    parser->eofp = Qfalse;
    if (NIL_P(fname)) {
        fname = rb_str_new2("(ripper)");
    }
    else {
        StringValue(fname);
    }
    parser_initialize(parser);
    parser->parser_ruby_sourcefile = fname;
    parser->parser_ruby_sourceline = NIL_P(lineno) ? 0 : NUM2INT(lineno) - 1;

    return Qnil;
}

/*
 *  call-seq:
 *    Ripper.yydebug   -> true or false
 *
 *  Get yydebug.
 */
static VALUE
ripper_s_get_yydebug(VALUE self)
{
    return ripper_yydebug ? Qtrue : Qfalse;
}

/*
 *  call-seq:
 *    Ripper.yydebug = flag
 *
 *  Set yydebug.
 */
static VALUE
ripper_s_set_yydebug(VALUE self, VALUE flag)
{
    ripper_yydebug = RTEST(flag);
    return flag;
}

extern VALUE rb_thread_pass(void);

struct ripper_args {
    struct parser_params *parser;
    int argc;
    VALUE *argv;
};

static VALUE
ripper_parse0(VALUE parser_v)
{
    struct parser_params *parser;

    Data_Get_Struct(parser_v, struct parser_params, parser);
    parser_prepare(parser);
    ripper_yyparse((void*)parser);
    return parser->result;
}

static VALUE
ripper_ensure(VALUE parser_v)
{
    struct parser_params *parser;

    Data_Get_Struct(parser_v, struct parser_params, parser);
    parser->parsing_thread = Qnil;
    return Qnil;
}

/*
 *  call-seq:
 *    ripper#parse
 *
 *  Start parsing and returns the value of the root action.
 */
static VALUE
ripper_parse(VALUE self)
{
    struct parser_params *parser;

    Data_Get_Struct(self, struct parser_params, parser);
    if (!ripper_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    if (!NIL_P(parser->parsing_thread)) {
        if (parser->parsing_thread == rb_thread_current())
            rb_raise(rb_eArgError, "Ripper#parse is not reentrant");
        else
            rb_raise(rb_eArgError, "Ripper#parse is not multithread-safe");
    }
    parser->parsing_thread = rb_thread_current();
    rb_ensure(ripper_parse0, self, ripper_ensure, self);

    return parser->result;
}

/*
 *  call-seq:
 *    ripper#column   -> Integer
 *
 *  Return column number of current parsing line.
 *  This number starts from 0.
 */
static VALUE
ripper_column(VALUE self)
{
    struct parser_params *parser;
    long col;

    Data_Get_Struct(self, struct parser_params, parser);
    if (!ripper_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    if (NIL_P(parser->parsing_thread)) return Qnil;
    col = parser->tokp - parser->parser_lex_pbeg;
    return LONG2NUM(col);
}

/*
 *  call-seq:
 *    ripper#lineno   -> Integer
 *
 *  Return line number of current parsing line.
 *  This number starts from 1.
 */
static VALUE
ripper_lineno(VALUE self)
{
    struct parser_params *parser;

    Data_Get_Struct(self, struct parser_params, parser);
    if (!ripper_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    if (NIL_P(parser->parsing_thread)) return Qnil;
    return INT2NUM(parser->parser_ruby_sourceline);
}

#ifdef RIPPER_DEBUG
/* :nodoc: */
static VALUE
ripper_assert_Qundef(VALUE self, VALUE obj, VALUE msg)
{
    StringValue(msg);
    if (obj == Qundef) {
        rb_raise(rb_eArgError, "%s", RSTRING_PTR(msg));
    }
    return Qnil;
}

/* :nodoc: */
static VALUE
ripper_value(VALUE self, VALUE obj)
{
    return ULONG2NUM(obj);
}
#endif

void
Init_ripper(void)
{
    VALUE Ripper;

    Ripper = rb_define_class("Ripper", rb_cObject);
    rb_define_const(Ripper, "Version", rb_str_new2(RIPPER_VERSION));
    rb_define_singleton_method(Ripper, "yydebug", ripper_s_get_yydebug, 0);
    rb_define_singleton_method(Ripper, "yydebug=", ripper_s_set_yydebug, 1);
    rb_define_alloc_func(Ripper, ripper_s_allocate);
    rb_define_method(Ripper, "initialize", ripper_initialize, -1);
    rb_define_method(Ripper, "parse", ripper_parse, 0);
    rb_define_method(Ripper, "column", ripper_column, 0);
    rb_define_method(Ripper, "lineno", ripper_lineno, 0);
    rb_define_method(Ripper, "end_seen?", rb_parser_end_seen_p, 0);
#ifdef RIPPER_DEBUG
    rb_define_method(rb_mKernel, "assert_Qundef", ripper_assert_Qundef, 2);
    rb_define_method(rb_mKernel, "rawVALUE", ripper_value, 1);
    rb_define_method(rb_mKernel, "validate_object", ripper_validate_object, 1);
#endif

    ripper_id_gets = rb_intern("gets");
    ripper_init_eventids1(Ripper);
    ripper_init_eventids2(Ripper);
    /* ensure existing in symbol table */
    rb_intern("||");
    rb_intern("&&");
}
#endif /* RIPPER */


