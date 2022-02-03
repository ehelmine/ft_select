/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:45:12 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/03 13:29:32 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select	*g_plus;

void	handle_tstp(int signal_num)
{
	if (signal_num == SIGTSTP)
	{
		if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_orig_t) == -1)
		{
			write(STDOUT_FILENO, "error in exit with tcsetattr\n", 29);
			exit (1);
		}
		g_plus->raw = 0;
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
		tputs(g_plus->term_cl_clear_screen, g_plus->window_rows, &f_putc);
	}
}

void	handle_cont(int signal_num)
{
	if (signal_num == SIGCONT)
	{
		g_plus->raw = 1;
		get_terminal_info(g_plus, 0);
		if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_raw_t) == -1)
		{
			stop_raw_mode(g_plus->d_orig_t, g_plus);
			write(STDOUT_FILENO, "error in begin with tcsetattr\n", 30);
			exit (1);
		}
		signal(SIGTSTP, handle_tstp);
		get_window_size(g_plus, 1);
		fill_output(g_plus);
		if (g_plus->output)
			write(g_plus->fd_out, g_plus->output, ft_strlen(g_plus->output));
	}
}
