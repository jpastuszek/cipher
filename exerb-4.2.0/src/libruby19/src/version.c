/**********************************************************************

  version.c -

  $Author: shyouhei $
  $Date: 2007-02-13 08:01:19 +0900 (火, 13 2 2007) $
  created at: Thu Sep 30 20:08:01 JST 1993

  Copyright (C) 1993-2003 Yukihiro Matsumoto

**********************************************************************/

#include "ruby.h"
#include "version.h"
#include <stdio.h>

const char ruby_version[] = RUBY_VERSION;
const char ruby_release_date[] = RUBY_RELEASE_DATE;
const char ruby_platform[] = RUBY_PLATFORM;
const int ruby_patchlevel = RUBY_PATCHLEVEL;

void
Init_version(void)
{
    VALUE v = rb_obj_freeze(rb_str_new2(ruby_version));
    VALUE d = rb_obj_freeze(rb_str_new2(ruby_release_date));
    VALUE p = rb_obj_freeze(rb_str_new2(ruby_platform));

    rb_define_global_const("RUBY_VERSION", v);
    rb_define_global_const("RUBY_RELEASE_DATE", d);
    rb_define_global_const("RUBY_PLATFORM", p);
    rb_define_global_const("RUBY_PATCHLEVEL", INT2FIX(RUBY_PATCHLEVEL));
}

void
ruby_show_version(void)
{
    printf("ruby %s (%s patchlevel %d) [%s]\n", RUBY_VERSION, RUBY_RELEASE_DATE, RUBY_PATCHLEVEL, RUBY_PLATFORM);
    fflush(stdout);
}

void
ruby_show_copyright(void)
{
    printf("ruby - Copyright (C) 1993-%d Yukihiro Matsumoto\n", RUBY_RELEASE_YEAR);
    exit(0);
}
