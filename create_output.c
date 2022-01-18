/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:56:01 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/18 18:13:47 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static void	append_to_str(t_select *data, char *new)
{
	char *tmp;

	if (data->output == NULL)
		data->output = ft_strdup(new);
	else
	{
		tmp = ft_strdup(data->output);
		ft_memdel((void*)&data->output);
		data->output = ft_strjoin(tmp, new);
		ft_memdel((void*)&tmp);
	}
	data->output_len += ft_strlen(new);
}

//void	add_

void	fill_output(t_select *data)
{
	int	i;

	i = 0;
	if (data->output)
		ft_memdel((void *)&data->output);
	data->output_len = 0;
	append_to_str(data, "\x1b[?25l\x1b[2J\x1b[H");
	while (i < data->amount_of_input)
	{
		append_to_str(data, "[ ] ");
		append_to_str(data, data->input[i]);
		if (i < data->amount_of_input - 1)
			append_to_str(data, "\r\n");
		i++;
	}
	cursor_position(data);
	append_to_str(data, data->cursor_pos);
	append_to_str(data, "\x1b[?25h");
}

// if (data->input_check == 1)
		//		append_to_str(data, "[x] ");