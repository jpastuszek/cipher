/**********************************************************************

  re.h -

  $Author: shyouhei $
  $Date: 2007-02-13 08:01:19 +0900 (火, 13 2 2007) $
  created at: Thu Sep 30 14:18:32 JST 1993

  Copyright (C) 1993-2003 Yukihiro Matsumoto

**********************************************************************/

#ifndef RE_H
#define RE_H

#include <sys/types.h>
#include <stdio.h>

#include "regex.h"

typedef struct re_pattern_buffer Regexp;

struct RMatch {
    struct RBasic basic;
    VALUE str;
    struct re_registers *regs;
    VALUE regexp;  /* RRegexp */
};

#define RMATCH(obj)  (R_CAST(RMatch)(obj))

VALUE rb_reg_regcomp(VALUE);
long rb_reg_search(VALUE, VALUE, long, long);
VALUE rb_reg_regsub(VALUE, VALUE, struct re_registers *, VALUE);
long rb_reg_adjust_startpos(VALUE, VALUE, long, long);
void rb_match_busy(VALUE);
VALUE rb_reg_quote(VALUE);

RUBY_EXTERN int ruby_ignorecase;

int rb_reg_mbclen2(unsigned int, VALUE);
#define mbclen2(c,re) rb_reg_mbclen2((c),(re))
#endif
