/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 09:58:56 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/14 10:11:31 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

/*
** Write the arguments we just got as input to output.
**
*/

static void	args_to_output(int argc, char **argv, t_select *data)
{
	int	i;
	int	x;

	i = 1;
	x = 0;
	while (i < argc && x < MAX_INPUT_LEN - 1)
	{
		//write(1, argv[i], ft_strlen(argv[i]));
		//write(1, "\r\n", 2);
		ft_strcpy(data->input[x], argv[i]);
		ft_strlcat(data->input[x++], "\r\n", MAX_INPUT_LEN);
		i++;
	}
	data->input[x][0] = '\0';
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
		args_to_output(argc, argv, &data);
		if (get_terminal_info(&data) != -1)
		{
			orig_t = enter_raw_mode();
			read_loop(argc, argv, orig_t, &data);
		}
	}
	return (0);
}
