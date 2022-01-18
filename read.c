/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:39:27 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/18 18:59:33 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static int	read_escape_character(char c, t_select *data)
{
	// READ THREE CHARS? maybe yes.
	// char buf[3];

	// if ()
	//check = read(STDIN_FILENO, &buf, 3);
	//if (check > 0)
	// if (buf[0] == '[')
	//	{
	//		if buf[1] check here all keys that have in the beginning
	//		esc chars
	//	}
}

static int	check_read_character(struct termios orig_t, char c, t_select *data)
{
	int	x;

	x = 0;
	data->i = 0;
	if (c == '\x1b')
		read_escape_character(c, data);
	if (c == 'q')
	{
		write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);
		stop_raw_mode(orig_t);
		return (-1);
	}
	if (ft_isprint(c) == 1)
		write(STDOUT_FILENO, "\x1b[2J\x1b[H", 7);
	else
		return (0);
	return (1);
}

static int	reading(struct termios orig_t, t_select *data)
{
	char	c;
	int		check;

	c = '\0';
	check = read(STDIN_FILENO, &c, 1);
	if (check > 0)
		return (check_read_character(orig_t, c, data));
	else if (check == 0)
		return (1);
	return (-1);
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

int	read_loop(struct termios orig_t, t_select *data)
{
	int		i;
	int		check;

	i = 0;
	get_window_size(data, 0);
	data->cursor_x = 2;
	data->cursor_y = 1;
	write(STDOUT_FILENO, "\x1b[2J", 4);
	fill_output(data);
	while (1)
	{
		if (get_window_size(data, 1) == -1)
			fill_output(data);
		write(STDOUT_FILENO, data->output, ft_strlen(data->output));
		check = reading(orig_t, data);
		if (check == -1)
			break ;
	}
	if (data->output != NULL)
		ft_memdel((void *)&data->output);
	return (1);
}
