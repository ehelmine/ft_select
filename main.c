/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:58:56 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/11 09:32:27 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

/*
** Write the arguments we just got as input to output.
**
*/

static void	args_to_output(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		write(1, argv[i], ft_strlen(argv[i]));
		write(1, "\n", 1);
		i++;
	}
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
		args_to_output(argc, argv);
		if (get_terminal_info(&data) != -1)
		{
			orig_t = enter_raw_mode();
			read_loop(argc, argv, orig_t);
		}
	}
	return (0);
}
