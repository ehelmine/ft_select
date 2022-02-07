/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:45:12 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/07 12:02:49 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select	*g_plus;

static void	handle_winch(int signal_num)
{
	if (signal_num)
	{
		get_window_size(g_plus, 1);
		fill_output(g_plus);
	}
}

static void	handle_quit(int signal_num)
{
	if (signal_num)
	{
		if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_orig_t) == -1)
		{
			write(STDERR_FILENO, "error in exit with tcsetattr\n", 29);
			exit (EXIT_FAILURE);
		}
		ft_memdel((void *)&g_plus->output);
		tputs(g_plus->term_cl_clear_screen, g_plus->window_rows - 1, &f_putc);
		exit(EXIT_SUCCESS);
	}
}

static void	handle_tstp(int signal_num)
{
	if (signal_num == SIGTSTP)
	{
		if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_orig_t) == -1)
		{
			write(STDERR_FILENO, "error in exit with tcsetattr\n", 29);
			exit (EXIT_FAILURE);
		}
		g_plus->raw = 0;
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
		tputs(g_plus->term_cl_clear_screen, g_plus->window_rows, &f_putc);
	}
}

static void	handle_cont(int signal_num)
{
	if (signal_num == SIGCONT)
	{
		g_plus->raw = 1;
		get_terminal_info(g_plus, 0);
		if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_raw_t) == -1)
		{
			stop_raw_mode(g_plus->d_orig_t, g_plus);
			write(STDERR_FILENO, "error in begin with tcsetattr\n", 30);
			exit (EXIT_FAILURE);
		}
		signal(SIGTSTP, handle_tstp);
		get_window_size(g_plus, 1);
		fill_output(g_plus);
		if (g_plus->output)
			write(g_plus->fd_out, g_plus->output, ft_strlen(g_plus->output));
	}
}

/*
** Signals
**
** 18	SIGTSTP	stop signal gen. from keyboard	- stop process - Ctrl+Z
** 19	SIGCONT	continue after stop				- discard signal - fg
** 2	SIGINT	interrupt program				- terminate process	- Ctrl+C
** 3	SIGQUIT	quit program					- create core image	- Ctrl+\
** 28  SIGWINCH Window size change				- discard signal
** 
** with all these terminate process -> call handle_quit
** 1	SIGHUP	terminal line hangup
** 13	SIGPIPE	write on a pipe with no reader
** 14	SIGALRM	real-time timer expired
** 15	SIGTERM	software termination signal
** 24	SIGXCPU	cpu time limit exceeded (see setitimer(2))
** 25	SIGXFSZ	file size limit exceeded (see setitimer(2))
** 26 SIGVTALRM	virtual time alarm (see setitimer(2))
** 27	SIGPROF	profiling timer alarm (see setitimer(2))
** 30	SIGUSR1	User defined signal 1
** 31	SIGUSR2	User defined signal 2
 
     4     SIGILL       create core image    illegal instruction
     5     SIGTRAP      create core image    trace trap
     6     SIGABRT      create core image    abort program (formerly SIGIOT)
     7     SIGEMT       create core image    emulate instruction executed
     8     SIGFPE       create core image    floating-point exception
     10    SIGBUS       create core image    bus error
     11    SIGSEGV      create core image    segmentation violation
     12    SIGSYS       create core image    non-existent system call invoked

** 17	SIGSTOP	stop process	stop (cannot be caught or ignored)
** 21	SIGTTIN	stop process	background read attempted from control terminal
** 22	SIGTTOU	stop process	background write attempted to control terminal

** 16	SIGURG	discard signal	urgent condition present on socket
** 20	SIGCHLD	discard signal	child status has changed
** 23	SIGIO	discard signal	I/O is possible on a descriptor (see fcntl(2))
** 29	SIGINFO	discard signal	status request from keyboard
**
**
**
*/

void	check_signals(void)
{
	if (signal(SIGTSTP, handle_tstp) == SIG_ERR
		|| signal(SIGCONT, handle_cont) == SIG_ERR
		|| signal(SIGWINCH, handle_winch) == SIG_ERR)
	{
		stop_raw_mode(g_plus->d_orig_t, g_plus);
		exit (EXIT_FAILURE);
	}
	if (signal(SIGQUIT, handle_quit) == SIG_ERR || signal(SIGINT, handle_quit)
		== SIG_ERR || signal(SIGHUP, handle_quit) == SIG_ERR
		|| signal(SIGPIPE, handle_quit) == SIG_ERR
		|| signal(SIGALRM, handle_quit) == SIG_ERR
		|| signal(SIGTERM, handle_quit) == SIG_ERR
		|| signal(SIGXCPU, handle_quit) == SIG_ERR
		|| signal(SIGXFSZ, handle_quit) == SIG_ERR
		|| signal(SIGVTALRM, handle_quit) == SIG_ERR
		|| signal(SIGPROF, handle_quit) == SIG_ERR
		|| signal(SIGUSR1, handle_quit) == SIG_ERR
		|| signal(SIGUSR2, handle_quit) == SIG_ERR)
	{
		stop_raw_mode(g_plus->d_orig_t, g_plus);
		exit (EXIT_FAILURE);
	}
}
