/**********************************************************************

  rubyio.h -

  $Author: nobu $
  $Date: 2007-02-25 10:16:58 +0900 (日, 25 2 2007) $
  created at: Fri Nov 12 16:47:09 JST 1993

  Copyright (C) 1993-2003 Yukihiro Matsumoto

**********************************************************************/

#ifndef RUBYIO_H
#define RUBYIO_H

#include <stdio.h>
#include <errno.h>

#if defined(HAVE_STDIO_EXT_H)
#include <stdio_ext.h>
#endif

typedef struct rb_io_t {
    int fd;                     /* file descriptor */
    FILE *stdio_file;		/* stdio ptr for read/write if available */
    int mode;			/* mode flags */
    rb_pid_t pid;		/* child's pid (for pipes) */
    int lineno;			/* number of lines read */
    char *path;			/* pathname for file */
    void (*finalize)(struct rb_io_t*,int); /* finalize proc */
    long refcnt;
    char *wbuf;                 /* wbuf_off + wbuf_len <= wbuf_capa */
    int wbuf_off;
    int wbuf_len;
    int wbuf_capa;
    char *rbuf;                 /* rbuf_off + rbuf_len <= rbuf_capa */
    int rbuf_off;
    int rbuf_len;
    int rbuf_capa;
} rb_io_t;

#define HAVE_RB_IO_T 1

#define FMODE_READABLE  1
#define FMODE_WRITABLE  2
#define FMODE_READWRITE 3
#define FMODE_APPEND   64
#define FMODE_CREATE  128
#define FMODE_BINMODE   4
#define FMODE_SYNC      8
#define FMODE_TTY      16
#define FMODE_DUPLEX   32
#define FMODE_WSPLIT  0x200
#define FMODE_WSPLIT_INITIALIZED  0x400

#define GetOpenFile(obj,fp) rb_io_check_closed((fp) = RFILE(rb_io_taint_check(obj))->fptr)

#define MakeOpenFile(obj, fp) do {\
    if (RFILE(obj)->fptr) {\
	rb_io_close(obj);\
	free(RFILE(obj)->fptr);\
	RFILE(obj)->fptr = 0;\
    }\
    fp = 0;\
    fp = RFILE(obj)->fptr = ALLOC(rb_io_t);\
    fp->fd = -1;\
    fp->stdio_file = NULL;\
    fp->mode = 0;\
    fp->pid = 0;\
    fp->lineno = 0;\
    fp->path = NULL;\
    fp->finalize = 0;\
    fp->refcnt = 1;\
    fp->wbuf = NULL;\
    fp->wbuf_off = 0;\
    fp->wbuf_len = 0;\
    fp->wbuf_capa = 0;\
    fp->rbuf = NULL;\
    fp->rbuf_off = 0;\
    fp->rbuf_len = 0;\
    fp->rbuf_capa = 0;\
} while (0)

FILE *rb_io_stdio_file(rb_io_t *fptr);

FILE *rb_fopen(const char*, const char*);
FILE *rb_fdopen(int, const char*);
int  rb_io_mode_flags(const char*);
int  rb_io_modenum_flags(int);
void rb_io_check_writable(rb_io_t*);
void rb_io_check_readable(rb_io_t*);
int rb_io_fptr_finalize(rb_io_t*);
void rb_io_synchronized(rb_io_t*);
void rb_io_check_initialized(rb_io_t*);
void rb_io_check_closed(rb_io_t*);
int rb_io_wait_readable(int);
int rb_io_wait_writable(int);
void rb_io_set_nonblock(rb_io_t *fptr);

VALUE rb_io_taint_check(VALUE);
NORETURN(void rb_eof_error(void));

void rb_io_read_check(rb_io_t*);
int rb_io_read_pending(rb_io_t*);
void rb_read_check(FILE*);

DEPRECATED(int rb_getc(FILE*));
DEPRECATED(long rb_io_fread(char *, long, FILE *));
DEPRECATED(long rb_io_fwrite(const char *, long, FILE *));
DEPRECATED(int rb_read_pending(FILE*));
#endif
