/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:47 by ehelmine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/26 13:09:24 by ehelmine         ###   ########.fr       */
=======
/*   Updated: 2022/02/10 15:51:17 by ehelmine         ###   ########.fr       */
>>>>>>> 398ec6d825907fda58380f32fdb29620bcdeedae
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

static void	construct_extra_line(t_select *data, char *spaces, int i)
{
	append_to_str(data, spaces);
	if (i == data->cursor_y - 1)
		append_to_str(data, data->term_us_start_uline);
	if (data->input_info[i][0] == 1)
	{
		append_to_str(data, data->term_mr_video);
		append_to_str(data, "[x] ");
	}
	else
		append_to_str(data, "[ ] ");
	append_to_str(data, data->input[i]);
	if (i == data->cursor_y - 1)
		append_to_str(data, data->term_ue_stop_uline);
	if (data->input_info[i][0] == 1)
		append_to_str(data, data->term_me_off_app);
}

static void	fill_extra_cols(t_select *data, int i, int x, int len)
{
	int		y;
	char	*spaces;
	int		times;
	int		tmp;

	i += data->window_rows * (x + 1);
	times = 0;
	tmp = i;
	while (tmp >= data->window_rows)
	{
		times++;
		tmp -= data->window_rows;
	}
	y = data->col_lengths[times - 1]
		- data->input_info[i - data->window_rows][1] + 3;
	spaces = (char *)malloc(sizeof(char) * (y + 1));
	if (spaces == NULL)
		output_error(data, 4);
	len = 0;
	while (len < y)
		spaces[len++] = ' ';
	spaces[len] = '\0';
	if (data->input[i][0] != '\0')
		construct_extra_line(data, spaces, i);
	ft_memdel((void *)&spaces);
}

static int	construct_one_line(t_select *data, int x, int i)
{
	if (i == data->cursor_y - 1)
		append_to_str(data, data->term_us_start_uline);
	if (data->input_info[i][0] == 1)
	{
		append_to_str(data, data->term_mr_video);
		append_to_str(data, "[x] ");
	}
	else
		append_to_str(data, "[ ] ");
	append_to_str(data, data->input[i]);
	if (i == data->cursor_y - 1)
		append_to_str(data, data->term_ue_stop_uline);
	if (data->input_info[i][0] == 1)
		append_to_str(data, data->term_me_off_app);
	while (x < data->output_cols - 1)
		fill_extra_cols(data, i, x++, 0);
	if (i == data->window_rows - 1)
		return (-1);
	if (i < data->amount_of_input - 1 || i == 0)
		append_to_str(data, "\r\n");
	return (1);
}

void	fill_output(t_select *data)
{
	int	i;

	i = 0;
	ft_memdel((void *)&data->output);
	data->output_len = 0;
	append_to_str(data, data->term_cl_clear_screen);
	while (i < data->amount_of_input)
	{
		if (construct_one_line(data, 0, i) == -1)
			break ;
		i++;
	}
	cursor_position(data);
	append_to_str(data, data->cursor_pos);
}
