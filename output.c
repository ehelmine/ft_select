/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:53:47 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/25 15:52:32 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	write_options(t_select *data, struct termios orig_t)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	tputs(data->term_cl_clear_screen, data->window_rows - 1, &f_putc);
	if (data->output != NULL)
		ft_memdel((void *)&data->output);
	stop_raw_mode(orig_t);
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
	write(STDOUT_FILENO, &c, 1);
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
	while (i < data->amount_of_input)
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
		if (i == data->window_rows - 1)
			break ;
		if (i < data->amount_of_input - 1 || i == 0)
			append_to_str(data, "\r\n");
		i++;
	}
	cursor_position(data);
	append_to_str(data, data->cursor_pos);
}
