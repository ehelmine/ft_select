/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:39:27 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/20 12:26:32 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int	f_putc(int c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}

static int	read_escape_character(t_select *data)
{
	char	buf[3];

	ft_bzero(buf, 3);
	if (read(STDIN_FILENO, &buf[0], 1) != 1)
		return (-1);
	if (read(STDIN_FILENO, &buf[1], 1) != 1)
		return (-1);
	if (buf[0] == '[' && buf[1] == 'A')
	{
		if (data->cursor_y == 1)
			data->cursor_y = data->amount_of_input;
		else
			data->cursor_y--;
	}
	else if (buf[0] == '[' && buf[1] == 'B')
	{
		if (data->cursor_y == data->amount_of_input)
			data->cursor_y = 1;
		else
			data->cursor_y++;
	}
	else
		return (-1);
	return (1);
}

static int	check_read_character(struct termios orig_t, char c, t_select *data)
{
	if (c == '\x1b')
	{
		if (read_escape_character(data) == 1)
			fill_output(data);
	}
	else if (c == ' ')
	{
		if (data->input_info[data->cursor_y - 1][0] == 0)
			data->input_info[data->cursor_y - 1][0] = 1;
		else
			data->input_info[data->cursor_y - 1][0] = 0;
		if (data->cursor_y == data->amount_of_input)
			data->cursor_y = 1;
		else
			data->cursor_y++;
		fill_output(data);
	}
	else if (c == 'q')
	{
		tputs(data->term_cl_clear_screen, data->window_rows - 1, &f_putc);
		stop_raw_mode(orig_t);
		return (-1);
	}
	else if (ft_isprint(c) == 1)
		tputs(data->term_cl_clear_screen, data->window_rows - 1, &f_putc);
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

static void	set_start_values(t_select *data)
{
	int	i;

	i = 0;
	data->output = NULL;
	data->cursor_x = 2;
	data->cursor_y = 1;
	data->down = 0;
	while (i < MAX_INPUT_LEN)
		ft_memset(data->input_info[i++], 0, MAX_INPUT_LEN);
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
	set_start_values(data);
	fill_output(data);
	while (1)
	{
		if (get_window_size(data, 1) == -1)
			fill_output(data);
		if (data->output)
			write(STDOUT_FILENO, data->output, ft_strlen(data->output));
		check = reading(orig_t, data);
		if (check == -1)
			break ;
	}
	if (data->output != NULL)
		ft_memdel((void *)&data->output);
	return (1);
}
