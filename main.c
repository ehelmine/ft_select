/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:58:56 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/10 12:56:57 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

t_select	*g_plus;

/*
** Write the arguments we got as input to data->input[][] array.
*/

static void	args_to_struct(int argc, char **argv, t_select *data)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i < argc && x < MAX_INPUT_LEN - 1)
	{
		if ((int)ft_strlen(argv[i]) >= MAX_INPUT_LEN)
		{
			write(STDERR_FILENO, "Argument too long, max length is 2048\n", 38);
			exit(EXIT_FAILURE);
		}
		ft_memcpy(data->input[x], argv[i], ft_strlen(argv[i]));
		i++;
		x++;
	}
	data->input[x][0] = '\0';
	data->amount_of_input = x;
}

int	main(int argc, char **argv)
{
	t_select	*data;

	if (argc < 2)
		write(1, "usage: ./ft_select <arg1> .. <argN>\n", 36);
	else
	{
		data = (t_select *)malloc(sizeof(t_select));
		if (!data)
			output_error(data, 4);
		ft_memset(data, 0, sizeof(t_select));
		g_plus = data;
		check_signals();
		args_to_struct(argc, argv, data);
		get_terminal_info(data, 0);
		get_terminal_capabilities(data);
		enter_raw_mode(data);
		read_loop(data->d_orig_t, data);
	}
	return (0);
}
