/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:39:27 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/07 19:15:50 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

static int	check_read_character(struct termios orig_t, char *str, char c, int i)
{
	if (ft_isprint(c) == 1)
	{
		ft_printf("%d and %c\n\n", c, c);
	}
	else
	{
		ft_printf("--> %d <---\n\n", c);
	}
	str[i] = c;
	str[i + 1] = '\0';
	ft_printf("str here: |%s| i %i\n", str, i);
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

int	read_loop(int argc, char **argv, struct termios orig_t)
{
	char			*str;
	struct winsize	window;
	int				i;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	ft_printf("argc %i argv[0] name of program %s\n", argc, argv[0]);
	str = ft_memalloc(MAX_INPUT_LEN);
	i = 0;
	while (1)
	{
		//ft_printf("lines %i columns %i\n", window.ws_row, window.ws_col);
		if (reading(orig_t, str, i) == -1)
			break ;
		i++;
	}
	ft_printf("str end: |%s|\n", str);
	ft_memdel((void *)&str);
	return (1);
}
