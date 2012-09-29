/**********************************************************************

  signal.c -

  $Author: ko1 $
  $Date: 2007-02-25 11:43:43 +0900 (日, 25 2 2007) $
  created at: Tue Dec 20 10:13:44 JST 1994

  Copyright (C) 1993-2003 Yukihiro Matsumoto
  Copyright (C) 2000  Network Applied Communication Laboratory, Inc.
  Copyright (C) 2000  Information-technology Promotion Agency, Japan

**********************************************************************/

#include "ruby.h"
#include "rubysig.h"
#include <signal.h>
#include <stdio.h>

#ifdef __BEOS__
#undef SIGBUS
#endif

#ifndef NSIG
# ifdef DJGPP
#  define NSIG SIGMAX
# else
#  define NSIG (_SIGMAX + 1)      /* For QNX */
# endif
#endif

static struct signals {
    const char *signm;
    int  signo;
} siglist [] = {
    {"EXIT", 0},
#ifdef SIGHUP
    {"HUP", SIGHUP},
#endif
    {"INT", SIGINT},
#ifdef SIGQUIT
    {"QUIT", SIGQUIT},
#endif
#ifdef SIGILL
    {"ILL", SIGILL},
#endif
#ifdef SIGTRAP
    {"TRAP", SIGTRAP},
#endif
#ifdef SIGIOT
    {"IOT", SIGIOT},
#endif
#ifdef SIGABRT
    {"ABRT", SIGABRT},
#endif
#ifdef SIGEMT
    {"EMT", SIGEMT},
#endif
#ifdef SIGFPE
    {"FPE", SIGFPE},
#endif
#ifdef SIGKILL
    {"KILL", SIGKILL},
#endif
#ifdef SIGBUS
    {"BUS", SIGBUS},
#endif
#ifdef SIGSEGV
    {"SEGV", SIGSEGV},
#endif
#ifdef SIGSYS
    {"SYS", SIGSYS},
#endif
#ifdef SIGPIPE
    {"PIPE", SIGPIPE},
#endif
#ifdef SIGALRM
    {"ALRM", SIGALRM},
#endif
#ifdef SIGTERM
    {"TERM", SIGTERM},
#endif
#ifdef SIGURG
    {"URG", SIGURG},
#endif
#ifdef SIGSTOP
    {"STOP", SIGSTOP},
#endif
#ifdef SIGTSTP
    {"TSTP", SIGTSTP},
#endif
#ifdef SIGCONT
    {"CONT", SIGCONT},
#endif
#ifdef SIGCHLD
    {"CHLD", SIGCHLD},
#endif
#ifdef SIGCLD
    {"CLD", SIGCLD},
#else
# ifdef SIGCHLD
    {"CLD", SIGCHLD},
# endif
#endif
#ifdef SIGTTIN
    {"TTIN", SIGTTIN},
#endif
#ifdef SIGTTOU
    {"TTOU", SIGTTOU},
#endif
#ifdef SIGIO
    {"IO", SIGIO},
#endif
#ifdef SIGXCPU
    {"XCPU", SIGXCPU},
#endif
#ifdef SIGXFSZ
    {"XFSZ", SIGXFSZ},
#endif
#ifdef SIGVTALRM
    {"VTALRM", SIGVTALRM},
#endif
#ifdef SIGPROF
    {"PROF", SIGPROF},
#endif
#ifdef SIGWINCH
    {"WINCH", SIGWINCH},
#endif
#ifdef SIGUSR1
    {"USR1", SIGUSR1},
#endif
#ifdef SIGUSR2
    {"USR2", SIGUSR2},
#endif
#ifdef SIGLOST
    {"LOST", SIGLOST},
#endif
#ifdef SIGMSG
    {"MSG", SIGMSG},
#endif
#ifdef SIGPWR
    {"PWR", SIGPWR},
#endif
#ifdef SIGPOLL
    {"POLL", SIGPOLL},
#endif
#ifdef SIGDANGER
    {"DANGER", SIGDANGER},
#endif
#ifdef SIGMIGRATE
    {"MIGRATE", SIGMIGRATE},
#endif
#ifdef SIGPRE
    {"PRE", SIGPRE},
#endif
#ifdef SIGGRANT
    {"GRANT", SIGGRANT},
#endif
#ifdef SIGRETRACT
    {"RETRACT", SIGRETRACT},
#endif
#ifdef SIGSOUND
    {"SOUND", SIGSOUND},
#endif
#ifdef SIGINFO
    {"INFO", SIGINFO},
#endif
    {NULL, 0}
};

static int
signm2signo(const char *nm)
{
    struct signals *sigs;

    for (sigs = siglist; sigs->signm; sigs++)
	if (strcmp(sigs->signm, nm) == 0)
	    return sigs->signo;
    return 0;
}

static const char*
signo2signm(int no)
{
    struct signals *sigs;

    for (sigs = siglist; sigs->signm; sigs++)
	if (sigs->signo == no)
	    return sigs->signm;
    return 0;
}

const char *
ruby_signal_name(int no)
{
    return signo2signm(no);
}

/*
 *  call-seq:
 *     Process.kill(signal, pid, ...)    => fixnum
 *  
 *  Sends the given signal to the specified process id(s), or to the
 *  current process if _pid_ is zero. _signal_ may be an
 *  integer signal number or a POSIX signal name (either with or without
 *  a +SIG+ prefix). If _signal_ is negative (or starts
 *  with a minus sign), kills process groups instead of
 *  processes. Not all signals are available on all platforms.
 *     
 *     pid = fork do
 *        Signal.trap("HUP") { puts "Ouch!"; exit }
 *        # ... do some work ...
 *     end
 *     # ...
 *     Process.kill("HUP", pid)
 *     Process.wait
 *     
 *  <em>produces:</em>
 *     
 *     Ouch!
 */

VALUE
rb_f_kill(int argc, VALUE *argv)
{
    int negative = 0;
    int sig;
    int i;
    const char *s;

    rb_secure(2);
    if (argc < 2)
	rb_raise(rb_eArgError, "wrong number of arguments -- kill(sig, pid...)");
    switch (TYPE(argv[0])) {
      case T_FIXNUM:
	sig = FIX2INT(argv[0]);
	break;

      case T_SYMBOL:
	s = rb_id2name(SYM2ID(argv[0]));
	if (!s) rb_raise(rb_eArgError, "bad signal");
	goto str_signal;

      case T_STRING:
	s = RSTRING_PTR(argv[0]);
	if (s[0] == '-') {
	    negative++;
	    s++;
	}
      str_signal:
	if (strncmp("SIG", s, 3) == 0)
	    s += 3;
	if((sig = signm2signo(s)) == 0)
	    rb_raise(rb_eArgError, "unsupported name `SIG%s'", s);

	if (negative)
	    sig = -sig;
	break;

      default:
        {
	    VALUE str;

	    str = rb_check_string_type(argv[0]);
	    if (!NIL_P(str)) {
		s = RSTRING_PTR(str);
		goto str_signal;
	    }
	    rb_raise(rb_eArgError, "bad signal type %s",
		     rb_obj_classname(argv[0]));
	}
	break;
    }

    if (sig < 0) {
	sig = -sig;
	for (i=1; i<argc; i++) {
	    int pid = NUM2INT(argv[i]);
#ifdef HAS_KILLPG
	    if (killpg(pid, sig) < 0)
#else
	    if (kill(-pid, sig) < 0)
#endif
		rb_sys_fail(0);
	}
    }
    else {
	for (i=1; i<argc; i++) {
	    Check_Type(argv[i], T_FIXNUM);
	    if (kill(FIX2INT(argv[i]), sig) < 0)
		rb_sys_fail(0);
	}
    }
    return INT2FIX(i-1);
}

static struct {
    VALUE cmd;
    int safe;
} trap_list[NSIG];
static rb_atomic_t trap_pending_list[NSIG];
static char rb_trap_accept_nativethreads[NSIG];
rb_atomic_t rb_trap_pending;
rb_atomic_t rb_trap_immediate;
int rb_prohibit_interrupt = 1;

VALUE
rb_get_trap_cmd(int sig)
{
    return trap_list[sig].cmd;
}

void
rb_gc_mark_trap_list(void)
{
#ifndef MACOS_UNUSE_SIGNAL
    int i;

    for (i=0; i<NSIG; i++) {
	if (trap_list[i].cmd)
	    rb_gc_mark(trap_list[i].cmd);
    }
#endif /* MACOS_UNUSE_SIGNAL */
}

#ifdef __dietlibc__
#define sighandler_t sh_t
#endif

typedef RETSIGTYPE (*sighandler_t)(int);

#ifdef POSIX_SIGNAL
static sighandler_t
ruby_signal(int signum, sighandler_t handler)
{
    struct sigaction sigact, old;

    rb_trap_accept_nativethreads[signum] = 0;

    sigact.sa_handler = handler;
    sigemptyset(&sigact.sa_mask);
    sigact.sa_flags = 0;
#ifdef SA_NOCLDWAIT
    if (signum == SIGCHLD && handler == SIG_IGN)
	sigact.sa_flags |= SA_NOCLDWAIT;
#endif
    sigaction(signum, &sigact, &old);
    return old.sa_handler;
}

void
posix_signal(int signum, sighandler_t handler)
{
    ruby_signal(signum, handler);
}

#else /* !POSIX_SIGNAL */
#define ruby_signal(sig,handler) (rb_trap_accept_nativethreads[sig] = 0, signal((sig),(handler)))
#ifdef HAVE_NATIVETHREAD
static sighandler_t
ruby_nativethread_signal(int signum, sighandler_t handler)
{
    sighandler_t old;

    old = signal(signum, handler);
    rb_trap_accept_nativethreads[signum] = 1;
    return old;
}
#endif
#endif

#include <node.h>
#include "yarvcore.h"

static RETSIGTYPE
sighandler(int sig)
{
    rb_vm_t *vm = GET_VM(); /* fix me for Multi-VM */
    ATOMIC_INC(vm->signal_buff[sig]);
    ATOMIC_INC(vm->bufferd_signal_size);

#if !defined(BSD_SIGNAL) && !defined(POSIX_SIGNAL)
    ruby_signal(sig, sighandler);
#endif
}

# ifdef HAVE_SIGPROCMASK
static sigset_t trap_last_mask;
# else
static int trap_last_mask;
# endif


#if HAVE_PTHREAD_H
#include <pthread.h>
#endif

void
rb_disable_interrupt(void)
{
#ifndef _WIN32
    sigset_t mask;
    sigfillset(&mask);
    sigdelset(&mask, SIGVTALRM);
    sigdelset(&mask, SIGSEGV);
    pthread_sigmask(SIG_SETMASK, &mask, NULL);
#endif
}

void
rb_enable_interrupt(void)
{
#ifndef _WIN32
    sigset_t mask;
    sigemptyset(&mask);
    pthread_sigmask(SIG_SETMASK, &mask, NULL);
#endif
}

int
rb_get_next_signal(rb_vm_t *vm)
{
    int i, sig = 0;

    for (i=1; i<RUBY_NSIG; i++) {
	if (vm->signal_buff[i] > 0) {
	    rb_disable_interrupt();
	    {
		ATOMIC_DEC(vm->signal_buff[i]);
		ATOMIC_DEC(vm->bufferd_signal_size);
	    }
	    rb_enable_interrupt();
	    sig = i;
	    break;
	}
    }
    return sig;
}

#ifdef SIGBUS
static RETSIGTYPE
sigbus(int sig)
{
    rb_bug("Bus Error");
}
#endif

#ifdef SIGSEGV
static int segv_received = 0;
static RETSIGTYPE
sigsegv(int sig)
{
    if (segv_received) {
	fprintf(stderr, "SEGV recieved in SEGV handler\n");
	exit(1);
    }
    else {
	segv_received = 1;
	rb_bug("Segmentation fault");
    }
}
#endif

#ifdef SIGPIPE
static RETSIGTYPE
sigpipe(int sig)
{
    /* do nothing */
}
#endif

void
rb_trap_exit(void)
{
#ifndef MACOS_UNUSE_SIGNAL
    if (trap_list[0].cmd) {
	VALUE trap_exit = trap_list[0].cmd;

	trap_list[0].cmd = 0;
	rb_eval_cmd(trap_exit, rb_ary_new3(1, INT2FIX(0)), trap_list[0].safe);
    }
#endif
}

void
rb_signal_exec(rb_thread_t *th, int sig)
{
    VALUE cmd = rb_get_trap_cmd(sig);

    if (cmd == 0) {
	switch (sig) {
	  case SIGINT:
	    rb_interrupt();
	    break;
#ifdef SIGHUP
	  case SIGHUP:
#endif
#ifdef SIGQUIT
	  case SIGQUIT:
#endif
#ifdef SIGALRM
	  case SIGALRM:
#endif
#ifdef SIGUSR1
	  case SIGUSR1:
#endif
#ifdef SIGUSR2
	  case SIGUSR2:
#endif
	    rb_thread_signal_raise(th, signo2signm(sig));
	    break;
	}
    }
    else if (cmd == Qundef) {
	rb_thread_signal_exit(th);
    }
    else {
	rb_proc_t *proc;
	VALUE signum = INT2FIX(sig);
	GetProcPtr(cmd, proc);
	th_invoke_proc(th, proc, proc->block.self, 1, &signum);
    }
}

void
rb_trap_exec(void)
{
#ifndef MACOS_UNUSE_SIGNAL
    int i;

    for (i=0; i<NSIG; i++) {
	if (trap_pending_list[i]) {
	    trap_pending_list[i] = 0;
	    rb_signal_exec(GET_THREAD(), i);
	}
    }
#endif /* MACOS_UNUSE_SIGNAL */
    rb_trap_pending = 0;
}

struct trap_arg {
#ifndef _WIN32
# ifdef HAVE_SIGPROCMASK
    sigset_t mask;
# else
    int mask;
# endif
#endif
    VALUE sig, cmd;
};

static VALUE
trap(struct trap_arg *arg)
{
    sighandler_t func, oldfunc;
    VALUE command, oldcmd;
    int sig = -1;
    const char *s;

    func = sighandler;
    if (NIL_P(arg->cmd)) {
	func = SIG_IGN;
    }
    else {
	command = rb_check_string_type(arg->cmd);
	if (!NIL_P(command)) {
	    SafeStringValue(command);	/* taint check */
	    switch (RSTRING_LEN(command)) {
	      case 0:
		func = SIG_IGN;
		break;
	      case 7:
		if (strncmp(RSTRING_PTR(command), "SIG_IGN", 7) == 0) {
		    func = SIG_IGN;
		}
		else if (strncmp(RSTRING_PTR(command), "SIG_DFL", 7) == 0) {
		    func = SIG_DFL;
		}
		else if (strncmp(RSTRING_PTR(command), "DEFAULT", 7) == 0) {
		    func = SIG_DFL;
		}
		break;
	      case 6:
		if (strncmp(RSTRING_PTR(command), "IGNORE", 6) == 0) {
		    func = SIG_IGN;
		}
		break;
	      case 4:
		if (strncmp(RSTRING_PTR(command), "EXIT", 4) == 0) {
		    arg->cmd = Qundef;
		}
		break;
	    }
	}
    }
    if (func == SIG_IGN || func == SIG_DFL) {
	command = 0;
    }
    else {
	command = arg->cmd;
    }

    switch (TYPE(arg->sig)) {
      case T_FIXNUM:
	sig = FIX2INT(arg->sig);
	break;

      case T_SYMBOL:
	s = rb_id2name(SYM2ID(arg->sig));
	if (!s) rb_raise(rb_eArgError, "bad signal");
	goto str_signal;

      case T_STRING:
	s = RSTRING_PTR(arg->sig);

      str_signal:
	if (strncmp("SIG", s, 3) == 0)
	    s += 3;
	sig = signm2signo(s);
	if (sig == 0 && strcmp(s, "EXIT") != 0)
	    rb_raise(rb_eArgError, "unsupported signal SIG%s", s);
    }

    if (sig < 0 || sig >= NSIG) {
	rb_raise(rb_eArgError, "invalid signal number (%d)", sig);
    }
#if defined(HAVE_SETITIMER)
    if (sig == SIGVTALRM) {
	rb_raise(rb_eArgError, "SIGVTALRM reserved for Thread; can't set handler");
    }
#endif
    if (func == SIG_DFL) {
	switch (sig) {
	  case SIGINT:
#ifdef SIGHUP
	  case SIGHUP:
#endif
#ifdef SIGQUIT
	  case SIGQUIT:
#endif
#ifdef SIGALRM
	  case SIGALRM:
#endif
#ifdef SIGUSR1
	  case SIGUSR1:
#endif
#ifdef SIGUSR2
	  case SIGUSR2:
#endif
	    func = sighandler;
	    break;
#ifdef SIGBUS
	  case SIGBUS:
	    func = sigbus;
	    break;
#endif
#ifdef SIGSEGV
	  case SIGSEGV:
	    func = sigsegv;
	    break;
#endif
#ifdef SIGPIPE
	  case SIGPIPE:
	    func = sigpipe;
	    break;
#endif
	}
    }
    oldfunc = ruby_signal(sig, func);
    oldcmd = trap_list[sig].cmd;
    if (!oldcmd) {
	if (oldfunc == SIG_IGN) oldcmd = rb_str_new2("IGNORE");
	else if (oldfunc == sighandler) oldcmd = rb_str_new2("DEFAULT");
	else oldcmd = Qnil;
    }

    trap_list[sig].cmd = command;
    trap_list[sig].safe = rb_safe_level();
    /* enable at least specified signal. */
#ifndef _WIN32
#ifdef HAVE_SIGPROCMASK
    sigdelset(&arg->mask, sig);
#else
    arg->mask &= ~sigmask(sig);
#endif
#endif
    return oldcmd;
}

#ifndef _WIN32
static VALUE
trap_ensure(struct trap_arg *arg)
{
    /* enable interrupt */
#ifdef HAVE_SIGPROCMASK
    sigprocmask(SIG_SETMASK, &arg->mask, NULL);
#else
    sigsetmask(arg->mask);
#endif
    trap_last_mask = arg->mask;
    return 0;
}
#endif

void
rb_trap_restore_mask(void)
{
#ifndef _WIN32
# ifdef HAVE_SIGPROCMASK
    sigprocmask(SIG_SETMASK, &trap_last_mask, NULL);
# else
    sigsetmask(trap_last_mask);
# endif
#endif
}

/*
 * call-seq:
 *   Signal.trap( signal, proc ) => obj
 *   Signal.trap( signal ) {| | block } => obj
 *
 * Specifies the handling of signals. The first parameter is a signal
 * name (a string such as ``SIGALRM'', ``SIGUSR1'', and so on) or a
 * signal number. The characters ``SIG'' may be omitted from the
 * signal name. The command or block specifies code to be run when the
 * signal is raised. If the command is the string ``IGNORE'' or
 * ``SIG_IGN'', the signal will be ignored. If the command is
 * ``DEFAULT'' or ``SIG_DFL'', the operating system's default handler
 * will be invoked. If the command is ``EXIT'', the script will be
 * terminated by the signal. Otherwise, the given command or block
 * will be run.
 * The special signal name ``EXIT'' or signal number zero will be
 * invoked just prior to program termination.
 * trap returns the previous handler for the given signal.
 *
 *     Signal.trap(0, proc { puts "Terminating: #{$$}" })
 *     Signal.trap("CLD")  { puts "Child died" }
 *     fork && Process.wait
 *
 * produces:
 *     Terminating: 27461
 *     Child died
 *     Terminating: 27460
 */
static VALUE
sig_trap(int argc, VALUE *argv)
{
    struct trap_arg arg;

    rb_secure(2);
    if (argc == 0 || argc > 2) {
	rb_raise(rb_eArgError, "wrong number of arguments -- trap(sig, cmd)/trap(sig){...}");
    }

    arg.sig = argv[0];
    if (argc == 1) {
	arg.cmd = rb_block_proc();
    }
    else if (argc == 2) {
	arg.cmd = argv[1];
    }

    if (OBJ_TAINTED(arg.cmd)) {
	rb_raise(rb_eSecurityError, "Insecure: tainted signal trap");
    }
#ifndef _WIN32
    /* disable interrupt */
# ifdef HAVE_SIGPROCMASK
    sigfillset(&arg.mask);
    sigprocmask(SIG_BLOCK, &arg.mask, &arg.mask);
# else
    arg.mask = sigblock(~0);
# endif

    return rb_ensure(trap, (VALUE)&arg, trap_ensure, (VALUE)&arg);
#else
    return trap(&arg);
#endif
}

/*
 * call-seq:
 *   Signal.list => a_hash
 *
 * Returns a list of signal names mapped to the corresponding
 * underlying signal numbers.
 *
 * Signal.list   #=> {"ABRT"=>6, "ALRM"=>14, "BUS"=>7, "CHLD"=>17, "CLD"=>17, "CONT"=>18, "FPE"=>8, "HUP"=>1, "ILL"=>4, "INT"=>2, "IO"=>29, "IOT"=>6, "KILL"=>9, "PIPE"=>13, "POLL"=>29, "PROF"=>27, "PWR"=>30, "QUIT"=>3, "SEGV"=>11, "STOP"=>19, "SYS"=>31, "TERM"=>15, "TRAP"=>5, "TSTP"=>20, "TTIN"=>21, "TTOU"=>22, "URG"=>23, "USR1"=>10, "USR2"=>12, "VTALRM"=>26, "WINCH"=>28, "XCPU"=>24, "XFSZ"=>25}
 */
static VALUE
sig_list(void)
{
    VALUE h = rb_hash_new();
    struct signals *sigs;

    for (sigs = siglist; sigs->signm; sigs++) {
	rb_hash_aset(h, rb_str_new2(sigs->signm), INT2FIX(sigs->signo));
    }
    return h;
}

static void
install_sighandler(int signum, sighandler_t handler)
{
    sighandler_t old;

    old = ruby_signal(signum, handler);
    if (old != SIG_DFL) {
	ruby_signal(signum, old);
    }
}

static void
init_sigchld(int sig)
{
    sighandler_t oldfunc;
#ifndef _WIN32
# ifdef HAVE_SIGPROCMASK
    sigset_t mask;
# else
    int mask;
# endif
#endif

#ifndef _WIN32
    /* disable interrupt */
# ifdef HAVE_SIGPROCMASK
    sigfillset(&mask);
    sigprocmask(SIG_BLOCK, &mask, &mask);
# else
    mask = sigblock(~0);
# endif
#endif

    oldfunc = ruby_signal(sig, SIG_DFL);
    if (oldfunc != SIG_DFL && oldfunc != SIG_IGN) {
	ruby_signal(sig, oldfunc);
    } else {
	trap_list[sig].cmd = 0;
    }

#ifndef _WIN32
#ifdef HAVE_SIGPROCMASK
    sigdelset(&mask, sig);
    sigprocmask(SIG_SETMASK, &mask, NULL);
#else
    mask &= ~sigmask(sig);
    sigsetmask(mask);
#endif
    trap_last_mask = mask;
#endif
}

/*
 * Many operating systems allow signals to be sent to running
 * processes. Some signals have a defined effect on the process, while
 * others may be trapped at the code level and acted upon. For
 * example, your process may trap the USR1 signal and use it to toggle
 * debugging, and may use TERM to initiate a controlled shutdown.
 *
 *     pid = fork do
 *       Signal.trap("USR1") do
 *         $debug = !$debug
 *         puts "Debug now: #$debug"
 *       end
 *       Signal.trap("TERM") do
 *         puts "Terminating..."
 *         shutdown()
 *       end
 *       # . . . do some work . . .
 *     end
 *
 *     Process.detach(pid)
 *
 *     # Controlling program:
 *     Process.kill("USR1", pid)
 *     # ...
 *     Process.kill("USR1", pid)
 *     # ...
 *     Process.kill("TERM", pid)
 *
 * produces:
 *     Debug now: true
 *     Debug now: false
 *    Terminating...
 *
 * The list of available signal names and their interpretation is
 * system dependent. Signal delivery semantics may also vary between
 * systems; in particular signal delivery may not always be reliable.
 */
void
Init_signal(void)
{
#ifndef MACOS_UNUSE_SIGNAL
    VALUE mSignal = rb_define_module("Signal");

    rb_define_global_function("trap", sig_trap, -1);
    rb_define_module_function(mSignal, "trap", sig_trap, -1);
    rb_define_module_function(mSignal, "list", sig_list, 0);

    install_sighandler(SIGINT, sighandler);
#ifdef SIGHUP
    install_sighandler(SIGHUP, sighandler);
#endif
#ifdef SIGQUIT
    install_sighandler(SIGQUIT, sighandler);
#endif
#ifdef SIGTERM
    install_sighandler(SIGTERM, sighandler);
#endif
#ifdef SIGALRM
    install_sighandler(SIGALRM, sighandler);
#endif
#ifdef SIGUSR1
    install_sighandler(SIGUSR1, sighandler);
#endif
#ifdef SIGUSR2
    install_sighandler(SIGUSR2, sighandler);
#endif

#ifdef SIGBUS
    install_sighandler(SIGBUS, sigbus);
#endif
#ifdef SIGSEGV
    install_sighandler(SIGSEGV, sigsegv);
#endif
#ifdef SIGPIPE
    install_sighandler(SIGPIPE, sigpipe);
#endif

#if defined(SIGCLD)
    init_sigchld(SIGCLD);
#elif defined(SIGCHLD)
    init_sigchld(SIGCHLD);
#endif

#endif /* MACOS_UNUSE_SIGNAL */
}
