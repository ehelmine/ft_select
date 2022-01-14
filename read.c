/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:39:27 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/14 15:18:05 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static int	check_read_character(struct termios orig_t, char c, t_select *data)
{
	int	x;

	x = 0;
	if (ft_isprint(c) == 1)
	{
	//	ft_printf("%d and %c\r\n", c, c);
		write(STDOUT_FILENO, "\x1b[2J", 4);
		write(STDOUT_FILENO, "\x1b[H", 3);
		while (x < data->window_rows)
		{
			write(STDIN_FILENO, "=\r\n", 3);
			x++;
		}
	}
	else
	{
	//	ft_printf("--> %d <---\r\n", c);
		return (0);
	}
	if (c == 'q')
	{
		stop_raw_mode(orig_t);
		return (-1);
	}
	return (1);
}

/*
** \x1b[2J explanation:
** \x1b is escape character (27)
** \x1b and [ are together called escape sequence
** J means clear the screen
** escape sequence takes arguments and args come before the command, so in this
** case number 2 before character J tells to do clearing for the whole screen
**
** \x1b[H
** H tells us to position cursor on the top left corner
**
*/

static int	reading(struct termios orig_t, t_select *data)
{
	char	c;

	c = '\0';
	if (read(STDIN_FILENO, &c, 1) > 0)
	{
		return (check_read_character(orig_t, c, data));
	}
	return (-1);
}

int	read_loop(int argc, char **argv, struct termios orig_t, t_select *data)
{
	int		i;
	int		check;

	ft_printf("argc %i argv[0] name of program %s\r\n", argc, argv[0]);
	i = 0;
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	while (1)
	{
		get_window_size(data);
		check = reading(orig_t, data);
		if (check == -1)
			break ;
	}
	return (1);
}
