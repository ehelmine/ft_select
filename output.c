/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:47 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/28 11:38:56 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select *data_plus;

void	write_options(t_select *data, struct termios orig_t)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	tputs(data->term_cl_clear_screen, data->window_rows - 1, &f_putc);
	if (data->output != NULL)
		ft_memdel((void *)&data->output);
	stop_raw_mode(orig_t, data);
	while (data->input[i][0] != '\0')
	{
		if (data->input_info[i][0] == 1)
		{
			if (first != 0)
				write(STDOUT_FILENO, " ", 1);
			first = 1;
			write(STDOUT_FILENO, &data->input[i], ft_strlen(data->input[i]));
		}
		i++;
	}
	write(STDOUT_FILENO, "\n", 1);
	exit (0);
}

int	f_putc(int c)
{
	write(data_plus->fd_out, &c, 1);
	return (1);
}

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

void	fill_extra_cols(t_select *data, int i, int x)
{
	int		y;
	int		len;
	char	*spaces;
	int		z;

	len = 0;
	i += data->window_rows * (x + 1);
	y = i - 1;
	while (y >= data->window_rows * ((x - 1 + 1)))
	{
		if (data->input_info[y][1] > len)
			len = data->input_info[y][1];
		y--;
	}
	z = i - data->window_rows;
	y = len - data->input_info[z][1] + 3;
	spaces = (char *)malloc(sizeof(char) * (y + 1));
	len = 0;
	while (len < y)
		spaces[len++] = ' ';
	spaces[len] = '\0';
	if (data->input[i][0] != '\0')
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
	ft_memdel((void *)&spaces);
}

// \x1b[?25l = hide cursor
// \x1b[?25h = show cursor

void	fill_output(t_select *data)
{
	int	i;
	int	x;

	i = 0;
	if (data->output != NULL)
		ft_memdel((void *)&data->output);
	data->output_len = 0;
	append_to_str(data, data->term_cl_clear_screen);
	while (i < data->amount_of_input)
	{
		x = 0;
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
			fill_extra_cols(data, i, x++);
		if (i == data->window_rows - 1)
			break ;
		if (i < data->amount_of_input - 1 || i == 0)
			append_to_str(data, "\r\n");
		i++;
	}
	cursor_position(data);
	append_to_str(data, data->cursor_pos);
}
