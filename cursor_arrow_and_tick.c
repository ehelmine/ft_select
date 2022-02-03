/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_arrow_and_tick.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:10 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/03 18:44:31 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	arrow_move_or_tick_box(t_select *data, char letter)
{
	if (letter == 'A')
	{
		if (data->cursor_y == 1)
			data->cursor_y = data->amount_of_input;
		else
			data->cursor_y--;
	}
	else if (letter == 'B')
	{
		if (data->cursor_y == data->amount_of_input)
			data->cursor_y = 1;
		else
			data->cursor_y++;
	}
	else if (letter == ' ')
	{
		if (data->input_info[data->cursor_y - 1][0] == 0)
			data->input_info[data->cursor_y - 1][0] = 1;
		else
			data->input_info[data->cursor_y - 1][0] = 0;
		if (data->cursor_y == data->amount_of_input)
			data->cursor_y = 1;
		else
			data->cursor_y++;
	}
}

static void	more_input_than_window_rows(t_select *data, char **x, char **y)
{
	int	times;
	int	i;
	int	total;

	times = 0;
	i = data->cursor_y;
	while (i > data->window_rows)
	{
		times++;
		i -= data->window_rows;
	}
	*y = ft_itoa(i);
	i = 0;
	total = (times * 7);
	while (times > 0)
	{
		total += data->col_lengths[i++];
		times--;
	}
	*x = ft_itoa(total + 2);
}

void	cursor_position(t_select *data)
{
	char	*x;
	char	*y;
	char	*tmp;

	ft_memdel((void *)&data->cursor_pos);
	x = NULL;
	y = NULL;
	tmp = NULL;
	if (data->cursor_y > data->window_rows)
		more_input_than_window_rows(data, &x, &y);
	else
	{
		x = ft_itoa(data->cursor_x);
		y = ft_itoa(data->cursor_y);
	}
	if (x != NULL && y != NULL)
	{
		tmp = ft_strjoin_three("\x1b[", y, ";");
		data->cursor_pos = ft_strjoin_three(tmp, x, "H");
		ft_memdel((void *)&tmp);
	}
	else
		data->cursor_pos = ft_strdup("");
	ft_memdel_two((void *)&x, (void *)&y);
}
