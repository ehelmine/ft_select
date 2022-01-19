/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:56:01 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/19 22:04:42 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static void	append_to_str(t_select *data, char *new)
{
	char	*tmp;

	tmp = NULL;
	if (data->output == NULL)
		data->output = ft_strdup(new);
	else
	{
		tmp = ft_strdup(data->output);
		ft_memdel((void *)&data->output);
		data->output = ft_strjoin(tmp, new);
		ft_memdel((void *)&tmp);
	}
	data->output_len += ft_strlen(new);
}

// \x1b[?25l = hide cursor
// \x1b[?25h = show cursor

void	fill_output(t_select *data)
{
	int	i;

	i = 0;
	if (data->output != NULL)
		ft_memdel((void *)&data->output);
	data->output_len = 0;
	append_to_str(data, data->term_cl_clear_screen);
	//append_to_str(data, data->term_cm_position);
	//append_to_str(data, "\r\n");
	while (i < data->amount_of_input)
	{
		if (data->input_info[i][0] == 1)
			append_to_str(data, "[x] ");
		else
			append_to_str(data, "[ ] ");
		append_to_str(data, data->input[i]);
		if (i < data->amount_of_input - 1)
			append_to_str(data, "\r\n");
		i++;
	}
	cursor_position(data);
	append_to_str(data, data->cursor_pos);
}

// if (data->input_check == 1)
		//		append_to_str(data, "[x] ");