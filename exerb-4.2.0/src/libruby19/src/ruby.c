/**********************************************************************

  ruby.c -

  $Author: shyouhei $
  $Date: 2007-02-13 08:01:19 +0900 (火, 13 2 2007) $
  created at: Tue Aug 10 12:47:31 JST 1993

  Copyright (C) 1993-2003 Yukihiro Matsumoto
  Copyright (C) 2000  Network Applied Communication Laboratory, Inc.
  Copyright (C) 2000  Information-technology Promotion Agency, Japan

**********************************************************************/

#ifdef __CYGWIN__
#include <windows.h>
#endif
#ifdef _WIN32_WCE
#include <winsock.h>
#include "wince.h"
#endif
#include "ruby.h"
#include "dln.h"
#include "node.h"
#include <stdio.h>
#include <sys/types.h>
#include <ctype.h>

#ifdef __hpux
#include <sys/pstat.h>
#endif

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif
#ifdef HAVE_SYS_PARAM_H
# include <sys/param.h>
#endif
#ifndef MAXPATHLEN
# define MAXPATHLEN 1024
#endif

#include "util.h"

#ifndef HAVE_STDLIB_H
char *getenv();
#endif

VALUE ruby_debug = Qfalse;
VALUE ruby_verbose = Qfalse;
static int sflag = 0;
static int xflag = 0;
extern int ruby_yydebug;

char *ruby_inplace_mode = Qfalse;

static void load_stdin(void);
static NODE *load_file(const char *, int);
static void forbid_setid(const char *);

static VALUE do_loop = Qfalse, do_print = Qfalse;
static VALUE do_check = Qfalse, do_line = Qfalse;
static VALUE do_split = Qfalse;

static int origargc;
static char **origargv;

static void
usage(const char *name)
{
    /* This message really ought to be max 23 lines.
     * Removed -h because the user already knows that option. Others? */

    static const char *usage_msg[] = {
	"-0[octal]       specify record separator (\\0, if no argument)",
	"-a              autosplit mode with -n or -p (splits $_ into $F)",
	"-c              check syntax only",
	"-Cdirectory     cd to directory, before executing your script",
	"-d              set debugging flags (set $DEBUG to true)",
	"-e 'command'    one line of script. Several -e's allowed. Omit [programfile]",
	"-Fpattern       split() pattern for autosplit (-a)",
	"-i[extension]   edit ARGV files in place (make backup if extension supplied)",
	"-Idirectory     specify $LOAD_PATH directory (may be used more than once)",
	"-Kkcode         specifies KANJI (Japanese) code-set",
	"-l              enable line ending processing",
	"-n              assume 'while gets(); ... end' loop around your script",
	"-p              assume loop like -n but print line also like sed",
	"-rlibrary       require the library, before executing your script",
	"-s              enable some switch parsing for switches after script name",
	"-S              look for the script using PATH environment variable",
	"-T[level]       turn on tainting checks",
	"-v              print version number, then turn on verbose mode",
	"-w              turn warnings on for your script",
	"-W[level]       set warning level; 0=silence, 1=medium, 2=verbose (default)",
	"-x[directory]   strip off text before #!ruby line and perhaps cd to directory",
	"--copyright     print the copyright",
	"--version       print the version",
	NULL
    };
    const char **p = usage_msg;

    printf("Usage: %s [switches] [--] [programfile] [arguments]\n", name);
    while (*p)
	printf("  %s\n", *p++);
}

extern VALUE rb_load_path;

#define STATIC_FILE_LENGTH 255

#if defined _WIN32 || defined __CYGWIN__ || defined __DJGPP__
static char *
rubylib_mangle(const char *s, unsigned int l)
{
    static char *newp, *oldp;
    static int newl, oldl, notfound;
    static char newsub[STATIC_FILE_LENGTH + 1];

    if (!newp && !notfound) {
	newp = getenv("RUBYLIB_PREFIX");
	if (newp) {
	    char *s;

	    oldp = newp;
	    while (*newp && !ISSPACE(*newp) && *newp != ';') {
		newp++;
		oldl++;		/* Skip digits. */
	    }
	    while (*newp && (ISSPACE(*newp) || *newp == ';')) {
		newp++;			/* Skip whitespace. */
	    }
	    newl = strlen(newp);
	    if (newl == 0 || oldl == 0 || newl > STATIC_FILE_LENGTH) {
		rb_fatal("malformed RUBYLIB_PREFIX");
	    }
	    strcpy(newsub, newp);
	    s = newsub;
	    while (*s) {
		if (*s == '\\')
		    *s = '/';
		s++;
	    }
	}
	else {
	    notfound = 1;
	}
    }
    if (l == 0) {
	l = strlen(s);
    }
    if (!newp || l < oldl || strncasecmp(oldp, s, oldl) != 0) {
	static char ret[STATIC_FILE_LENGTH + 1];
	strncpy(ret, s, l);
	ret[l] = 0;
	return ret;
    }
    if (l + newl - oldl > STATIC_FILE_LENGTH || newl > STATIC_FILE_LENGTH) {
	rb_fatal("malformed RUBYLIB_PREFIX");
    }
    strcpy(newsub + newl, s + oldl);
    newsub[l + newl - oldl] = 0;
    return newsub;
}

#define rubylib_mangled_path(s, l) rb_str_new2(rubylib_mangle((s), (l)))
#define rubylib_mangled_path2(s) rb_str_new2(rubylib_mangle((s), 0))
#else
#define rubylib_mangled_path(s, l) rb_str_new((s), (l))
#define rubylib_mangled_path2(s) rb_str_new2(s)
#endif

void
ruby_push_include(const char *path, VALUE (*filter) (VALUE))
{
    const char sep = PATH_SEP_CHAR;

    if (path == 0)
	return;
#if defined(__CYGWIN__)
    {
	char rubylib[FILENAME_MAX];
	conv_to_posix_path(path, rubylib, FILENAME_MAX);
	path = rubylib;
    }
#endif
    if (strchr(path, sep)) {
	const char *p, *s;
	VALUE ary = rb_ary_new();

	p = path;
	while (*p) {
	    while (*p == sep)
		p++;
	    if ((s = strchr(p, sep)) != 0) {
		rb_ary_push(ary,
			    (*filter) (rubylib_mangled_path
				       (p, (int)(s - p))));
		p = s + 1;
	    }
	    else {
		rb_ary_push(ary, (*filter) (rubylib_mangled_path2(p)));
		break;
	    }
	}
	rb_ary_concat(rb_load_path, ary);
    }
    else {
	rb_ary_push(rb_load_path, (*filter) (rubylib_mangled_path2(path)));
    }
}

static VALUE
identical_path(VALUE path)
{
    return path;
}

void 
ruby_incpush(const char *path)
{
    ruby_push_include(path, identical_path);
}

static VALUE
expand_include_path(VALUE path)
{
    char *p = RSTRING_PTR(path);
    if (!p)
	return path;
    if (*p == '.' && p[1] == '/')
	return path;
    return rb_file_expand_path(path, Qnil);
}


void 
ruby_incpush_expand(const char *path)
{
    ruby_push_include(path, expand_include_path);
}

#if defined DOSISH || defined __CYGWIN__
#define LOAD_RELATIVE 1
#endif

#if defined DOSISH || defined __CYGWIN__
static inline void
translate_char(char *p, int from, int to)
{
    while (*p) {
	if ((unsigned char)*p == from)
	    *p = to;
#ifdef CharNext		/* defined as CharNext[AW] on Windows. */
	p = CharNext(p);
#else
	p += mblen(p, RUBY_MBCHAR_MAXSIZE);
#endif
    }
}
#endif

void
ruby_init_loadpath(void)
{
#if defined LOAD_RELATIVE
    char libpath[MAXPATHLEN + 1];
    char *p;
    int rest;
#if defined _WIN32 || defined __CYGWIN__
    HMODULE libruby = NULL;
    MEMORY_BASIC_INFORMATION m;

#ifndef _WIN32_WCE
    memset(&m, 0, sizeof(m));
    if (VirtualQuery(ruby_init_loadpath, &m, sizeof(m))
	&& m.State == MEM_COMMIT)
	libruby = (HMODULE) m.AllocationBase;
#endif
    GetModuleFileName(libruby, libpath, sizeof libpath);
#elif defined(DJGPP)
    extern char *__dos_argv0;
    strncpy(libpath, __dos_argv0, sizeof(libpath) - 1);
#elif defined(__human68k__)
    extern char **_argv;
    strncpy(libpath, _argv[0], sizeof(libpath) - 1);
#elif defined(__EMX__)
    _execname(libpath, sizeof(libpath) - 1);
#endif

    libpath[sizeof(libpath) - 1] = '\0';
#if defined DOSISH || defined __CYGWIN__
    translate_char(libpath, '\\', '/');
#endif
    p = strrchr(libpath, '/');
    if (p) {
	*p = 0;
	if (p - libpath > 3 && !strcasecmp(p - 4, "/bin")) {
	    p -= 4;
	    *p = 0;
	}
    }
    else {
	strcpy(libpath, ".");
	p = libpath + 1;
    }

    rest = sizeof(libpath) - 1 - (p - libpath);

#define RUBY_RELATIVE(path) (strncpy(p, (path), rest), libpath)
#else
#define RUBY_RELATIVE(path) (path)
#endif

    if (rb_safe_level() == 0) {
	ruby_incpush(getenv("RUBYLIB"));
    }

#ifdef RUBY_SEARCH_PATH
    ruby_incpush(RUBY_RELATIVE(RUBY_SEARCH_PATH));
#endif

    ruby_incpush(RUBY_RELATIVE(RUBY_SITE_LIB2));
#ifdef RUBY_SITE_THIN_ARCHLIB
    ruby_incpush(RUBY_RELATIVE(RUBY_SITE_THIN_ARCHLIB));
#endif
    ruby_incpush(RUBY_RELATIVE(RUBY_SITE_ARCHLIB));
    ruby_incpush(RUBY_RELATIVE(RUBY_SITE_LIB));

    ruby_incpush(RUBY_RELATIVE(RUBY_LIB));
#ifdef RUBY_THIN_ARCHLIB
    ruby_incpush(RUBY_RELATIVE(RUBY_THIN_ARCHLIB));
#endif
    ruby_incpush(RUBY_RELATIVE(RUBY_ARCHLIB));

    if (rb_safe_level() == 0) {
	ruby_incpush(".");
    }
}

struct req_list {
    char *name;
    struct req_list *next;
};
static struct req_list req_list_head, *req_list_last = &req_list_head;

static void
add_modules(const char *mod)
{
    struct req_list *list;

    list = ALLOC(struct req_list);
    list->name = ALLOC_N(char, strlen(mod) + 1);
    strcpy(list->name, mod);
    list->next = 0;
    req_list_last->next = list;
    req_list_last = list;
}

extern void Init_ext(void);

static void
require_libraries(void)
{
    extern NODE *ruby_eval_tree;
    NODE *save[3];
    struct req_list *list = req_list_head.next;
    struct req_list *tmp;

    save[0] = ruby_eval_tree;
    save[1] = NEW_BEGIN(0);
    ruby_eval_tree = 0;
    ruby_current_node = 0;
    Init_ext();		/* should be called here for some reason :-( */
    ruby_current_node = save[1];
    ruby_set_current_source();
    req_list_last = 0;
    while (list) {
	int state;

	ruby_current_node = 0;
	rb_protect((VALUE (*)(VALUE))rb_require, (VALUE)list->name, &state);
	if (state)
	    rb_jump_tag(state);
	tmp = list->next;
	free(list->name);
	free(list);
	list = tmp;
	ruby_current_node = save[1];
	ruby_set_current_source();
    }
    req_list_head.next = 0;
    ruby_eval_tree = save[0];
    rb_gc_force_recycle((VALUE)save[1]);
    ruby_current_node = 0;
}

static void
process_sflag(void)
{
    if (sflag) {
	long n;
	VALUE *args;

	n = RARRAY_LEN(rb_argv);
	args = RARRAY_PTR(rb_argv);
	while (n > 0) {
	    VALUE v = *args++;
	    char *s = StringValuePtr(v);
	    char *p;
	    int hyphen = Qfalse;

	    if (s[0] != '-')
		break;
	    n--;
	    if (s[1] == '-' && s[2] == '\0')
		break;

	    v = Qtrue;
	    /* check if valid name before replacing - with _ */
	    for (p = s + 1; *p; p++) {
		if (*p == '=') {
		    *p++ = '\0';
		    v = rb_str_new2(p);
		    break;
		}
		if (*p == '-') {
		    hyphen = Qtrue;
		}
		else if (*p != '_' && !ISALNUM(*p)) {
		    VALUE name_error[2];
		    name_error[0] =
			rb_str_new2("invalid name for global variable - ");
		    if (!(p = strchr(p, '='))) {
			rb_str_cat2(name_error[0], s);
		    }
		    else {
			rb_str_cat(name_error[0], s, p - s);
		    }
		    name_error[1] = args[-1];
		    rb_exc_raise(rb_class_new_instance
				 (2, name_error, rb_eNameError));
		}
	    }
	    s[0] = '$';
	    if (hyphen) {
		for (p = s + 1; *p; ++p) {
		    if (*p == '-')
			*p = '_';
		}
	    }
	    rb_gv_set(s, v);
	}
	n = RARRAY_LEN(rb_argv) - n;
	while (n--) {
	    rb_ary_shift(rb_argv);
	}
    }
    sflag = 0;
}

static void proc_options(int argc, char **argv);

static char *
moreswitches(const char *s)
{
    int argc;
    char *argv[3];
    const char *p = s;

    argc = 2;
    argv[0] = argv[2] = 0;
    while (*s && !ISSPACE(*s))
	s++;
    argv[1] = ALLOCA_N(char, s - p + 2);
    argv[1][0] = '-';
    strncpy(argv[1] + 1, p, s - p);
    argv[1][s - p + 1] = '\0';
    proc_options(argc, argv);
    while (*s && ISSPACE(*s))
	s++;
    return (char *)s;
}

NODE *ruby_eval_tree;

static void
proc_options(int argc, char **argv)
{
    char *argv0 = argv[0];
    int do_search;
    const char *s;
    char *script = 0;
    NODE *volatile script_node = 0;

    int version = 0;
    int copyright = 0;
    int verbose = 0;
    VALUE e_script = Qfalse;

    if (argc == 0)
	return;

    do_search = Qfalse;

    for (argc--, argv++; argc > 0; argc--, argv++) {
	if (argv[0][0] != '-' || !argv[0][1])
	    break;

	s = argv[0] + 1;
      reswitch:
	switch (*s) {
	  case 'a':
	    do_split = Qtrue;
	    s++;
	    goto reswitch;

	  case 'p':
	    do_print = Qtrue;
	    /* through */
	  case 'n':
	    do_loop = Qtrue;
	    s++;
	    goto reswitch;

	  case 'd':
	    ruby_debug = Qtrue;
	    ruby_verbose = Qtrue;
	    s++;
	    goto reswitch;

	  case 'y':
	    ruby_yydebug = 1;
	    s++;
	    goto reswitch;

	  case 'v':
	    if (argv0 == 0 || verbose) {
		s++;
		goto reswitch;
	    }
	    ruby_show_version();
	    verbose = 1;
	  case 'w':
	    ruby_verbose = Qtrue;
	    s++;
	    goto reswitch;

	  case 'W':
	    {
		int numlen;
		int v = 2;	/* -W as -W2 */

		if (*++s) {
		    v = scan_oct(s, 1, &numlen);
		    if (numlen == 0)
			v = 1;
		    s += numlen;
		}
		switch (v) {
		  case 0:
		    ruby_verbose = Qnil;
		    break;
		  case 1:
		    ruby_verbose = Qfalse;
		    break;
		  default:
		    ruby_verbose = Qtrue;
		    break;
		}
	    }
	    goto reswitch;

	  case 'c':
	    do_check = Qtrue;
	    s++;
	    goto reswitch;

	  case 's':
	    forbid_setid("-s");
	    sflag = 1;
	    s++;
	    goto reswitch;

	  case 'h':
	    usage(origargv[0]);
	    exit(0);

	  case 'l':
	    do_line = Qtrue;
	    rb_output_rs = rb_rs;
	    s++;
	    goto reswitch;

	  case 'S':
	    forbid_setid("-S");
	    do_search = Qtrue;
	    s++;
	    goto reswitch;

	  case 'e':
	    forbid_setid("-e");
	    if (!*++s) {
		s = argv[1];
		argc--, argv++;
	    }
	    if (!s) {
		fprintf(stderr, "%s: no code specified for -e\n",
			origargv[0]);
		exit(2);
	    }
	    if (!e_script) {
		e_script = rb_str_new(0, 0);
		if (script == 0)
		    script = "-e";
	    }
	    rb_str_cat2(e_script, s);
	    rb_str_cat2(e_script, "\n");
	    break;

	  case 'r':
	    forbid_setid("-r");
	    if (*++s) {
		add_modules(s);
	    }
	    else if (argv[1]) {
		add_modules(argv[1]);
		argc--, argv++;
	    }
	    break;

	  case 'i':
	    forbid_setid("-i");
	    if (ruby_inplace_mode)
		free(ruby_inplace_mode);
	    ruby_inplace_mode = strdup(s + 1);
	    break;

	  case 'x':
	    xflag = Qtrue;
	    s++;
	    if (*s && chdir(s) < 0) {
		rb_fatal("Can't chdir to %s", s);
	    }
	    break;

	  case 'C':
	  case 'X':
	    s++;
	    if (!*s) {
		s = argv[1];
		argc--, argv++;
	    }
	    if (!s || !*s) {
		rb_fatal("Can't chdir");
	    }
	    if (chdir(s) < 0) {
		rb_fatal("Can't chdir to %s", s);
	    }
	    break;

	  case 'F':
	    if (*++s) {
		rb_fs = rb_reg_new(s, strlen(s), 0);
	    }
	    break;

	  case 'K':
	    if (*++s) {
		rb_set_kcode(s);
		s++;
	    }
	    goto reswitch;

	  case 'T':
	    {
		int numlen;
		int v = 1;

		if (*++s) {
		    v = scan_oct(s, 2, &numlen);
		    if (numlen == 0)
			v = 1;
		    s += numlen;
		}
		rb_set_safe_level(v);
	    }
	    goto reswitch;

	  case 'I':
	    forbid_setid("-I");
	    if (*++s)
		ruby_incpush_expand(s);
	    else if (argv[1]) {
		ruby_incpush_expand(argv[1]);
		argc--, argv++;
	    }
	    break;

	  case '0':
	    {
		int numlen;
		int v;
		char c;

		v = scan_oct(s, 4, &numlen);
		s += numlen;
		if (v > 0377)
		    rb_rs = Qnil;
		else if (v == 0 && numlen >= 2) {
		    rb_rs = rb_str_new2("\n\n");
		}
		else {
		    c = v & 0xff;
		    rb_rs = rb_str_new(&c, 1);
		}
	    }
	    goto reswitch;

	  case '-':
	    if (!s[1] || (s[1] == '\r' && !s[2])) {
		argc--, argv++;
		goto switch_end;
	    }
	    s++;
	    if (strcmp("copyright", s) == 0)
		copyright = 1;
	    else if (strcmp("debug", s) == 0) {
		ruby_debug = Qtrue;
                ruby_verbose = Qtrue;
            }
	    else if (strcmp("version", s) == 0)
		version = 1;
	    else if (strcmp("verbose", s) == 0) {
		verbose = 1;
		ruby_verbose = Qtrue;
	    }
	    else if (strcmp("yydebug", s) == 0)
		ruby_yydebug = 1;
	    else if (strcmp("help", s) == 0) {
		usage(origargv[0]);
		exit(0);
	    }
	    else {
		fprintf(stderr,
			"%s: invalid option --%s  (-h will show valid options)\n",
			origargv[0], s);
		exit(2);
	    }
	    break;

	  case '\r':
	    if (!s[1])
		break;

	  default:
	    {
		const char *format;
		if (ISPRINT(*s)) {
		    format =
			"%s: invalid option -%c  (-h will show valid options)\n";
		}
		else {
		    format =
			"%s: invalid option -\\%03o  (-h will show valid options)\n";
		}
		fprintf(stderr, format, origargv[0], (int)(unsigned char)*s);
	    }
	    exit(2);

	  case 0:
	    break;
	}
    }

  switch_end:
    if (argv0 == 0)
	return;

    if (rb_safe_level() == 0 && (s = getenv("RUBYOPT"))) {
	while (ISSPACE(*s))
	    s++;
	if (*s == 'T' || (*s == '-' && *(s + 1) == 'T')) {
	    int numlen;
	    int v = 1;

	    if (*s != 'T')
		++s;
	    if (*++s) {
		v = scan_oct(s, 2, &numlen);
		if (numlen == 0)
		    v = 1;
	    }
	    rb_set_safe_level(v);
	}
	else {
	    while (s && *s) {
		if (*s == '-') {
		    s++;
		    if (ISSPACE(*s)) {
			do {
			    s++;
			} while (ISSPACE(*s));
			continue;
		    }
		}
		if (!*s)
		    break;
		if (!strchr("IdvwrK", *s))
		    rb_raise(rb_eRuntimeError,
			     "illegal switch in RUBYOPT: -%c", *s);
		s = moreswitches(s);
	    }
	}
    }

    if (version) {
	ruby_show_version();
	exit(0);
    }
    if (copyright) {
	ruby_show_copyright();
    }

    if (rb_safe_level() >= 4) {
	OBJ_TAINT(rb_argv);
	OBJ_TAINT(rb_load_path);
    }

    if (!e_script) {
	if (argc == 0) {	/* no more args */
	    if (verbose)
		exit(0);
	    script = "-";
	}
	else {
	    script = argv[0];
	    if (script[0] == '\0') {
		script = "-";
	    }
	    else if (do_search) {
		char *path = getenv("RUBYPATH");

		script = 0;
		if (path) {
		    script = dln_find_file(argv[0], path);
		}
		if (!script) {
		    script = dln_find_file(argv[0], getenv(PATH_ENV));
		}
		if (!script)
		    script = argv[0];
		script = ruby_sourcefile = rb_source_filename(script);
		script_node = NEW_BEGIN(0);
	    }
#if defined DOSISH || defined __CYGWIN__
	    /* assume that we can change argv[n] if never change its length. */
	    translate_char(script, '\\', '/');
#endif
	    argc--;
	    argv++;
	}
    }

    ruby_script(script);
    ruby_set_argv(argc, argv);
    process_sflag();

    ruby_init_loadpath();
    ruby_sourcefile = rb_source_filename(argv0);
    if (e_script) {
	require_libraries();
	ruby_eval_tree = rb_compile_string(script, e_script, 1);
    }
    else if (strlen(script) == 1 && script[0] == '-') {
	load_stdin();
    }
    else {
	load_file(script, 1);
    }

    process_sflag();
    xflag = 0;

    if (rb_safe_level() >= 4) {
	FL_UNSET(rb_argv, FL_TAINT);
	FL_UNSET(rb_load_path, FL_TAINT);
    }
}

static NODE *
load_file(const char *fname, int script)
{
    extern VALUE rb_stdin;
    volatile VALUE parser;
    VALUE f;
    int line_start = 1;
    NODE *tree = 0;

    if (!fname)
	rb_load_fail(fname);
    if (strcmp(fname, "-") == 0) {
	f = rb_stdin;
    }
    else {
	FILE *fp = fopen(fname, "r");

	if (fp == NULL) {
	    rb_load_fail(fname);
	}
	fclose(fp);

	f = rb_file_open(fname, "r");
#if defined DOSISH || defined __CYGWIN__
	{
	    char *ext = strrchr(fname, '.');
	    if (ext && strcasecmp(ext, ".exe") == 0)
		rb_io_binmode(f);
	}
#endif
    }

    if (script) {
	VALUE c = 1;		/* something not nil */
	VALUE line;
	char *p;

	if (xflag) {
	    forbid_setid("-x");
	    xflag = Qfalse;
	    while (!NIL_P(line = rb_io_gets(f))) {
		line_start++;
		if (RSTRING_LEN(line) > 2
		    && RSTRING_PTR(line)[0] == '#'
		    && RSTRING_PTR(line)[1] == '!') {
		    if ((p = strstr(RSTRING_PTR(line), "ruby")) != 0) {
			goto start_read;
		    }
		}
	    }
	    rb_raise(rb_eLoadError, "no Ruby script found in input");
	}

	c = rb_io_getc(f);
	if (c == INT2FIX('#')) {
	    c = rb_io_getc(f);
	    if (c == INT2FIX('!')) {
		line = rb_io_gets(f);
		if (NIL_P(line))
		    return 0;

		if ((p = strstr(RSTRING_PTR(line), "ruby")) == 0) {
		    /* not ruby script, kick the program */
		    char **argv;
		    char *path;
		    char *pend = RSTRING_PTR(line) + RSTRING_LEN(line);

		    p = RSTRING_PTR(line);	/* skip `#!' */
		    if (pend[-1] == '\n')
			pend--;	/* chomp line */
		    if (pend[-1] == '\r')
			pend--;
		    *pend = '\0';
		    while (p < pend && ISSPACE(*p))
			p++;
		    path = p;	/* interpreter path */
		    while (p < pend && !ISSPACE(*p))
			p++;
		    *p++ = '\0';
		    if (p < pend) {
			argv = ALLOCA_N(char *, origargc + 3);
			argv[1] = p;
			MEMCPY(argv + 2, origargv + 1, char *, origargc);
		    }
		    else {
			argv = origargv;
		    }
		    argv[0] = path;
		    execv(path, argv);

		    ruby_sourcefile = rb_source_filename(fname);
		    ruby_sourceline = 1;
		    rb_fatal("Can't exec %s", path);
		}

	      start_read:
		p += 4;
		RSTRING_PTR(line)[RSTRING_LEN(line) - 1] = '\0';
		if (RSTRING_PTR(line)[RSTRING_LEN(line) - 2] == '\r')
		    RSTRING_PTR(line)[RSTRING_LEN(line) - 2] = '\0';
		if ((p = strstr(p, " -")) != 0) {
		    p++;	/* skip space before `-' */
		    while (*p == '-') {
			p = moreswitches(p + 1);
		    }
		}

		/* push back shebang for pragma may exist in next line */
		rb_io_ungetc(f, INT2FIX('\n'));
		rb_io_ungetc(f, INT2FIX('!'));
	    }
	    else if (!NIL_P(c)) {
		rb_io_ungetc(f, c);
	    }
	    rb_io_ungetc(f, INT2FIX('#'));
	}
	else if (!NIL_P(c)) {
	    rb_io_ungetc(f, c);
	}
	require_libraries();	/* Why here? unnatural */
	if (NIL_P(c))
	    return 0;
    }
    parser = rb_parser_new();
    ruby_eval_tree = tree = (NODE *)rb_parser_compile_file(parser, fname, f, line_start);
    if (script && rb_parser_end_seen_p(parser)) {
	rb_define_global_const("DATA", f);
    }
    else if (f != rb_stdin) {
	rb_io_close(f);
    }
    return tree;
}

void *
rb_load_file(const char *fname)
{
    return load_file(fname, 0);
}

static void
load_stdin(void)
{
    forbid_setid("program input from stdin");
    load_file("-", 1);
}

VALUE rb_progname;
VALUE rb_argv;
VALUE rb_argv0;

#if defined(PSTAT_SETCMD) || defined(HAVE_SETPROCTITLE)
#elif defined(_WIN32)
#elif defined(HAVE_SETENV) && defined(HAVE_UNSETENV)
#else
#define USE_ENVSPACE_FOR_ARG0
#endif

#ifdef USE_ENVSPACE_FOR_ARG0
static struct {
    char *begin, *end;
} envspace;
extern char **environ;

static void
set_arg0space()
{
    char *s;
    int i;

    if (!environ || (s = environ[0]) == NULL)
	return;
    envspace.begin = s;
    s += strlen(s);
    for (i = 1; environ[i]; i++) {
	if (environ[i] == s + 1) {
	    s++;
	    s += strlen(s);	/* this one is ok too */
	}
    }
    envspace.end = s;
}
#else
#define set_arg0space() ((void)0)
#endif

static void
set_arg0(VALUE val, ID id)
{
    char *s;
    long i;
#if !defined(PSTAT_SETCMD) && !defined(HAVE_SETPROCTITLE)
    static int len;
#endif

    if (origargv == 0)
	rb_raise(rb_eRuntimeError, "$0 not initialized");
    StringValue(val);
    s = RSTRING_PTR(val);
    i = RSTRING_LEN(val);
#if defined(PSTAT_SETCMD)
    if (i >= PST_CLEN) {
	union pstun j;
	j.pst_command = s;
	i = PST_CLEN;
	RSTRING_LEN(val) = i;
	*(s + i) = '\0';
	pstat(PSTAT_SETCMD, j, PST_CLEN, 0, 0);
    }
    else {
	union pstun j;
	j.pst_command = s;
	pstat(PSTAT_SETCMD, j, i, 0, 0);
    }
    rb_progname = rb_tainted_str_new(s, i);
#elif defined(HAVE_SETPROCTITLE)
    setproctitle("%.*s", (int)i, s);
    rb_progname = rb_tainted_str_new(s, i);
#else
    if (len == 0) {
	char *s = origargv[0];
	int i;

	s += strlen(s);
	/* See if all the arguments are contiguous in memory */
	for (i = 1; i < origargc; i++) {
	    if (origargv[i] == s + 1) {
		s++;
		s += strlen(s);	/* this one is ok too */
	    }
	    else {
		break;
	    }
	}
#if defined(USE_ENVSPACE_FOR_ARG0)
	if (s + 1 == envspace.begin) {
	    s = envspace.end;
	    ruby_setenv("", NULL); /* duplicate environ vars */
	}
#endif
	len = s - origargv[0];
    }

    if (i >= len) {
	i = len;
    }

    memcpy(origargv[0], s, i);
    s = origargv[0] + i;
    *s = '\0';
    if (++i < len) memset(s + 1, ' ', len - i);
    for (i = 1; i < origargc; i++)
      origargv[i] = s;
    rb_progname = rb_tainted_str_new2(origargv[0]);
#endif
}

void
ruby_script(const char *name)
{
    if (name) {
	rb_progname = rb_tainted_str_new2(name);
	ruby_sourcefile = rb_source_filename(name);
    }
}

static int uid, euid, gid, egid;

static void
init_ids(void)
{
    uid = (int)getuid();
    euid = (int)geteuid();
    gid = (int)getgid();
    egid = (int)getegid();
#ifdef VMS
    uid |= gid << 16;
    euid |= egid << 16;
#endif
    if (uid && (euid != uid || egid != gid)) {
	rb_set_safe_level(1);
    }
}

static void
forbid_setid(const char *s)
{
    if (euid != uid)
        rb_raise(rb_eSecurityError, "no %s allowed while running setuid", s);
    if (egid != gid)
        rb_raise(rb_eSecurityError, "no %s allowed while running setgid", s);
    if (rb_safe_level() > 0)
        rb_raise(rb_eSecurityError, "no %s allowed in tainted mode", s);
}

static void
verbose_setter(VALUE val, ID id, VALUE *variable)
{
    ruby_verbose = RTEST(val) ? Qtrue : val;
}

static VALUE
opt_W_getter(VALUE val, ID id)
{
    if (ruby_verbose == Qnil)
	return INT2FIX(0);
    if (ruby_verbose == Qfalse)
	return INT2FIX(1);
    if (ruby_verbose == Qtrue)
	return INT2FIX(2);
    return Qnil;		/* not reached */
}

void
ruby_prog_init(void)
{
    init_ids();

    ruby_sourcefile = rb_source_filename("ruby");
    rb_define_hooked_variable("$VERBOSE", &ruby_verbose, 0, verbose_setter);
    rb_define_hooked_variable("$-v", &ruby_verbose, 0, verbose_setter);
    rb_define_hooked_variable("$-w", &ruby_verbose, 0, verbose_setter);
    rb_define_virtual_variable("$-W", opt_W_getter, 0);
    rb_define_variable("$DEBUG", &ruby_debug);
    rb_define_variable("$-d", &ruby_debug);
    rb_define_readonly_variable("$-p", &do_print);
    rb_define_readonly_variable("$-l", &do_line);

    rb_define_hooked_variable("$0", &rb_progname, 0, set_arg0);
    rb_define_hooked_variable("$PROGRAM_NAME", &rb_progname, 0, set_arg0);

    rb_define_readonly_variable("$*", &rb_argv);
    rb_argv = rb_ary_new();
    rb_define_global_const("ARGV", rb_argv);
    rb_define_readonly_variable("$-a", &do_split);
    rb_global_variable(&rb_argv0);

#ifdef MSDOS
    /*
     * There is no way we can refer to them from ruby, so close them to save
     * space.
     */
    (void)fclose(stdaux);
    (void)fclose(stdprn);
#endif
}

void
ruby_set_argv(int argc, char **argv)
{
    int i;

#if defined(USE_DLN_A_OUT)
    if (origargv)
	dln_argv0 = origargv[0];
    else
	dln_argv0 = argv[0];
#endif
    rb_ary_clear(rb_argv);
    for (i = 0; i < argc; i++) {
	VALUE arg = rb_tainted_str_new2(argv[i]);

	OBJ_FREEZE(arg);
	rb_ary_push(rb_argv, arg);
    }
}

NODE *rb_parser_append_print(NODE *);
NODE *rb_parser_while_loop(NODE *, int, int);

void
ruby_process_options(int argc, char **argv)
{
    origargc = argc;
    origargv = argv;

    ruby_script(argv[0]);	/* for the time being */
    rb_argv0 = rb_progname;
#if defined(USE_DLN_A_OUT)
    dln_argv0 = argv[0];
#endif
    set_arg0space();
    proc_options(argc, argv);

    if (do_check && ruby_nerrs == 0) {
	printf("Syntax OK\n");
	exit(0);
    }
    if (do_print) {
	ruby_eval_tree = rb_parser_append_print(ruby_eval_tree);
    }
    if (do_loop) {
	ruby_eval_tree =
	    rb_parser_while_loop(ruby_eval_tree, do_line, do_split);
    }
}
