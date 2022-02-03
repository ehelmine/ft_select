/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:58:56 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/03 18:27:35 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

t_select	*g_plus;

/*
** Write the arguments we got as input to data->input[][] array.
** 
*/

static void	args_to_struct(int argc, char **argv, t_select *data)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i < argc && x < MAX_INPUT_LEN - 1)
	{
		ft_strcpy(data->input[x], argv[i]);
		i++;
		x++;
	}
	data->input[x][0] = '\0';
	data->amount_of_input = x;
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

     17    SIGSTOP      stop process         stop (cannot be caught or ignored)
     21    SIGTTIN      stop process         background read attempted from control terminal
     22    SIGTTOU      stop process         background write attempted to control terminal

     16    SIGURG       discard signal       urgent condition present on socket
     20    SIGCHLD      discard signal       child status has changed
     23    SIGIO        discard signal       I/O is possible on a descriptor (see fcntl(2))
     29    SIGINFO      discard signal       status request from keyboard
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

int	main(int argc, char **argv)
{
	t_select	data;

	if (argc < 2)
		write(1, "usage: ./ft_select <arg1> .. <argN>\n", 36);
	else
	{
		ft_memset(&data, 0, sizeof(t_select));
		g_plus = &data;
		check_signals();
		args_to_struct(argc, argv, &data);
		get_terminal_info(&data, 0);
		get_terminal_capabilities(&data);
		enter_raw_mode(&data);
		read_loop(data.d_orig_t, &data);
	}
	return (0);
}
