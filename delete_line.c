/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:36:18 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/21 11:55:13 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	move_lines_one_up(t_select *data)
{
	char	tmp[MAX_INPUT_LEN];
	int		i;
	int		i_tmp;

	ft_memset(data->input[data->cursor_y - 1], 0, MAX_INPUT_LEN);
	i = data->cursor_y - 1;
	while (i < data->amount_of_input - 1)
	{
		ft_strcpy(data->input[i], data->input[i + 1]);
		ft_strcpy(tmp, data->input[i + 1]);
		ft_memset(data->input[i + 1], 0, MAX_INPUT_LEN);
		i++;
	}
	data->input_info[data->cursor_y - 1][0] = 0;
	i = data->cursor_y - 1;
	while (i < data->amount_of_input - 1)
	{
		data->input_info[i][0] = data->input_info[i + 1][0];
		i_tmp = data->input_info[i + 1][0];
		data->input_info[i + 1][0] = 0;
		i++;
	}
	data->amount_of_input--;
}

void	delete_option(t_select *data, struct termios orig_t)
{
	move_lines_one_up(data);
	if (data->cursor_y == data->amount_of_input + 1)
		data->cursor_y = 1;
	if (data->amount_of_input == 0)
	{
		tputs(data->term_cl_clear_screen, data->window_rows - 1, &f_putc);
		stop_raw_mode(orig_t);
		if (data->output != NULL)
			ft_memdel((void *)&data->output);
		exit (0);
	}
}