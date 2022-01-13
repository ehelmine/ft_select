/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:39:27 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/13 16:54:43 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static int	check_read_character(struct termios orig_t, char *str, char c, int i)
{
	if (ft_isprint(c) == 1)
	{
		ft_printf("%d and %c\r\n", c, c);
		str[i] = c;
		str[i + 1] = '\0';
	}
	else
	{
		ft_printf("--> %d <---\r\n", c);
	//	write(STDOUT_FILENO, "\x1b[2J", 4);
		return (0);
	}
//	ft_printf("str here: |%s| i %i\n", str, i);
	if (c == 'q')
	{
		stop_raw_mode(orig_t);
		return (-1);
	}
	return (1);
}

static int	reading(struct termios orig_t, char *str, int i)
{
	char	c;

	if (read(STDIN_FILENO, &c, 1) > 0)
		return (check_read_character(orig_t, str, c, i));
	return (-1);
}

int	read_loop(int argc, char **argv, struct termios orig_t, t_select *data)
{
	char	*str;
	int		i;
	int		check;

	ft_printf("argc %i argv[0] name of program %s\r\n", argc, argv[0]);
	str = ft_memalloc(MAX_INPUT_LEN);
	i = 0;
	while (1)
	{
		get_window_size(data);
		check = reading(orig_t, str, i);
		if (check == -1)
			break ;
		if (check == 1)
			i++;
	}
	ft_printf("str end: |%s|\n", str);
	ft_memdel((void *)&str);
	return (1);
}
