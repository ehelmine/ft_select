/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:40:48 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/14 11:34:09 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	stop_raw_mode(struct termios orig_t)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_t) == -1)
	{
		ft_printf("error with tcsetattr\n");
		exit (1);
	}
}

/*
** ICRNL flag turn off = stops terminal translating any carriage return
** (13, '\r') that are gotten as input from user into newlines (10, '\n')
** When flag is on, Ctrl-M is read as 10 (we expect it to be 13 (13th letter
** of the alphabet)), also Ctrl-J already is 10. Also enter key is 10.
** After turning off the flag: Ctrl-M is 13 (carriage return) and
** also enter key is 13.
**
** IXON flag turn off = 
**
** OPOST flag turn off = turns off all output processing features
**
** ECHO flag turn off = doesn't echo read input
**
** ICANON flag turn off = 
**
** IEXTEN flag turn off = Ctrl-V is now read as 22 and Ctrl-O (mac) is 15.
** Without turning off the flag on some systems with Ctrl-V,
** terminal waits for another character input and in mac terminal driver is
** set to discard Ctrl-O.
**
** ISIG flag turn off = 
*/

struct termios	enter_raw_mode(void)
{
	struct termios	orig_t;
	struct termios	raw_t;

	if (tcgetattr(STDIN_FILENO, &orig_t) == -1)
	{
		ft_printf("error with tcgetattr\n");
		exit (1);
	}
	raw_t = orig_t;
	raw_t.c_iflag &= ~(ICRNL | IXON);
	raw_t.c_oflag &= ~(OPOST);
	raw_t.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw_t) == -1)
	{
		ft_printf("error with tcsetattr\n");
		exit (1);
	}
	return (orig_t);
}
