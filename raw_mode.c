/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:40:48 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/10 15:56:12 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	stop_raw_mode(struct termios orig_t, t_select *data)
{
	tputs(data->term_te_stop, 1, f_putc);
	if (data && data->raw)
	{
		if (tcsetattr(data->fd_out, TCSAFLUSH, &orig_t) == -1)
		{
			write(STDERR_FILENO, "error in exit with tcsetattr\n", 29);
			exit(EXIT_FAILURE);
		}
	}
}

/*
**
** ICRNL flag turn off = stops terminal translating any carriage return
** (13, '\r') that are gotten as input from user into newlines (10, '\n')
** When flag is on, Ctrl-M is read as 10 (we expect it to be 13 (13th letter
** of the alphabet)), also Ctrl-J already is 10. Also enter key is 10.
** After turning off the flag: Ctrl-M is 13 (carriage return) and
** also enter key is 13.
**
** IXON flag turn off = Ctrl-S and Ctrl-Q are used for software flow control.
** Ctrl-S stops data from being transmitted to the terminal until you press
** Ctrl-QXON comes from the names of the two control characters that Ctrl-S
** and Ctrl-Q produce: XOFF to pause transmission and XON to resume transmission.
**
** OPOST flag turn off = turns off all output processing features
**
** ECHO flag turn off = doesn't echo read input
**
** ICANON flag turn off = operate in noncanonical mode
**
** IEXTEN flag turn off = Ctrl-V is now read as 22 and Ctrl-O (mac) is 15.
** Without turning off the flag on some systems with Ctrl-V,
** terminal waits for another character input and in mac terminal driver is
** set to discard Ctrl-O.
**
** VMIN = Minimum number of characters for noncanonical read (MIN).
** VTIME = Timeout in deciseconds for noncanonical read (TIME).
**
*/

void	enter_raw_mode(t_select *data)
{
	struct termios	orig_t;
	struct termios	raw_t;

	if (tcgetattr(STDIN_FILENO, &orig_t) == -1
		|| tcgetattr(STDIN_FILENO, &raw_t) == -1)
	{
		write(STDERR_FILENO, "error with tcgetattr\n", 21);
		exit(EXIT_FAILURE);
	}
	raw_t.c_iflag &= ~(ICRNL | IXON);
	raw_t.c_oflag &= ~(OPOST);
	raw_t.c_lflag &= ~(ECHO | ICANON | IEXTEN);
	raw_t.c_cc[VMIN] = 0;
	raw_t.c_cc[VTIME] = 1;
	if (tcsetattr(data->fd_out, TCSAFLUSH, &raw_t) == -1)
	{
		stop_raw_mode(orig_t, data);
		write(STDERR_FILENO, "error in begin with tcsetattr\n", 30);
		exit(EXIT_FAILURE);
	}
	data->raw = 1;
	data->d_orig_t = orig_t;
	data->d_raw_t = raw_t;
	tputs(data->term_ti_start, 1, f_putc);
	return ;
}
