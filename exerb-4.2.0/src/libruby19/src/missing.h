/************************************************

  missing.h - prototype for *.c in ./missing, and
  	      for missing timeval struct

  $Author: shyouhei $
  $Date: 2007-02-13 08:01:19 +0900 (火, 13 2 2007) $
  created at: Sat May 11 23:46:03 JST 2002

************************************************/

#ifndef MISSING_H
#define MISSING_H

#if defined(HAVE_SYS_TIME_H)
#  include <sys/time.h>
#elif !defined(_WIN32)
#  define time_t long
struct timeval {
    time_t tv_sec;	/* seconds */
    time_t tv_usec;	/* microseconds */
};
#endif
#if defined(HAVE_SYS_TYPES_H)
#  include <sys/types.h>
#endif

#ifndef HAVE_ACOSH
extern double acosh(double);
extern double asinh(double);
extern double atanh(double);
#endif

#ifndef HAVE_CRYPT
extern char *crypt(const char *, const char *);
#endif

#ifndef HAVE_DUP2
extern int dup2(int, int);
#endif

#ifndef HAVE_EACCESS
extern int eaccess(const char*, int);
#endif

#ifndef HAVE_FINITE
extern int finite(double);
#endif

#ifndef HAVE_FLOCK
extern int flock(int, int);
#endif

/*
#ifndef HAVE_FREXP
extern double frexp(double, int *);
#endif
*/

#ifndef HAVE_HYPOT
extern double hypot(double, double);
#endif

#ifndef HAVE_ERF
extern double erf(double);
extern double erfc(double);
#endif

#ifndef isinf
# ifndef HAVE_ISINF
#  if defined(HAVE_FINITE) && defined(HAVE_ISNAN)
#  define isinf(x) (!finite(x) && !isnan(x))
#  else
extern int isinf(double);
#  endif
# endif
#endif

#ifndef HAVE_ISNAN
extern int isnan(double);
#endif

/*
#ifndef HAVE_MEMCMP
extern int memcmp(const void *, const void *, size_t);
#endif
*/

#ifndef HAVE_MEMMOVE
extern void *memmove(void *, const void *, size_t);
#endif

/*
#ifndef HAVE_MODF
extern double modf(double, double *);
#endif
*/

#ifndef HAVE_STRCASECMP
extern int strcasecmp(const char *, const char *);
#endif

#ifndef HAVE_STRNCASECMP
extern int strncasecmp(const char *, const char *, size_t);
#endif

#ifndef HAVE_STRCHR
extern char *strchr(const char *, int);
extern char *strrchr(const char *, int);
#endif

#ifndef HAVE_STRERROR
extern char *strerror(int);
#endif

#ifndef HAVE_STRFTIME
extern size_t strftime(char *, size_t, const char *, const struct tm *);
#endif

#ifndef HAVE_STRSTR
extern char *strstr(const char *, const char *);
#endif

/*
#ifndef HAVE_STRTOL
extern long strtol(const char *, char **, int);
#endif
*/

#ifndef HAVE_STRTOUL
extern unsigned long strtoul(const char *, char **, int);
#endif

#ifndef HAVE_VSNPRINTF
# include <stdarg.h>
extern int snprintf(char *, size_t n, char const *, ...);
extern int vsnprintf(char *, size_t n, char const *, va_list);
#endif

#endif /* MISSING_H */
