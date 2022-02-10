/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:15:41 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/10 10:37:17 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select	*g_plus;

void	write_options(t_select *data, struct termios orig_t)
{
	int	i;
	int	first;

	i = 0;
	first = 0;
	tputs(data->term_cl_clear_screen, data->window_rows - 1, f_putc);
	ft_memdel((void *)&data->output);
	stop_raw_mode(orig_t, data);
	while (data->input[i][0] != '\0')
	{
		if (data->input_info[i][0] == 1)
		{
			if (first != 0)
				write(STDOUT_FILENO, " ", 1);
			first = 1;
			write(STDOUT_FILENO, &data->input[i], data->input_info[i][1]);
		}
		i++;
	}
	exit (EXIT_SUCCESS);
}

int	f_putc(int c)
{
	write(g_plus->fd_out, &c, 1);
	return (1);
}
