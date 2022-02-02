/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:45:12 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/02 13:37:59 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select	*g_plus;

void	handle_signals(int signal_num)
{
	if (signal_num == SIGCONT)
	{
		if (g_plus->stop == 1)
		{
			g_plus->stop = 0;
			get_terminal_info(g_plus);
			if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_raw_t) == -1)
			{
				stop_raw_mode(g_plus->d_orig_t, g_plus);
				write(STDOUT_FILENO, "error in begin with tcsetattr\n", 30);
				exit (1);
			}
			g_plus->output = NULL;
			g_plus->cursor_x = 2;
			g_plus->cursor_y = 1;
			get_window_size(g_plus, 1);
			fill_output(g_plus);
		}
	}
	if (signal_num == SIGTSTP)
	{
		g_plus->stop = 1;
		if (tcsetattr(g_plus->fd_out, TCSAFLUSH, &g_plus->d_orig_t) == -1)
		{
			write(STDOUT_FILENO, "error in exit with tcsetattr\n", 29);
			exit (1);
		}
	//	signal(SIGTSTP, SIG_DFL);
	//	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	//	tputs(g_plus->term_cl_clear_screen, g_plus->window_rows - 1, &f_putc);
	}
}
