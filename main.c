/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:58:56 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/01 13:59:58 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

t_select	*g_plus;

/*
** Write the arguments we got as input to data->input[][] array.
** 
*/

static void	args_to_struct(int argc, char **argv, t_select *data)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i < argc && x < MAX_INPUT_LEN - 1)
	{
		ft_strcpy(data->input[x], argv[i]);
		i++;
		x++;
	}
	data->input[x][0] = '\0';
	data->amount_of_input = x;
}

void	handle_signals(int signal_num)
{
	if (signal_num == SIGTSTP)
	{
		stop_raw_mode(g_plus->d_orig_t, g_plus);
		g_plus->stop = 1;
	}
	if (signal_num == SIGCONT)
	{
		if (g_plus->stop == 1)
		{
			enter_raw_mode(g_plus);
		}
	}
}

int	main(int argc, char **argv)
{
	int				signal_num;
	t_select		data;

	signal_num = 0;
	signal(signal_num, handle_signals);
	if (argc < 2)
		write(1, "usage: ./ft_select <arg1> .. <argN>\n", 36);
	else
	{
		ft_memset(&data, 0, sizeof(t_select));
		g_plus = &data;
		args_to_struct(argc, argv, &data);
		get_terminal_info(&data);
		enter_raw_mode(&data);
		read_loop(data.d_orig_t, &data);
	}
	return (0);
}
