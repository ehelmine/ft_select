/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:58:56 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/27 13:09:48 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

t_select *data_plus;

/*
** Write the arguments we just got as input to output.
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

int	main(int argc, char **argv)
{
	t_select		data;
	struct termios	orig_t;

	if (argc < 2)
		write(1, "usage: ./ft_select <arg1> .. <argN>\n", 36);
	else
	{
		ft_memset(&data, 0, sizeof(t_select));
		data_plus = &data;
		args_to_struct(argc, argv, &data);
		if (get_terminal_info(&data) != -1)
		{
			orig_t = enter_raw_mode(&data);
			read_loop(orig_t, &data);
		}
	}
	return (0);
}
