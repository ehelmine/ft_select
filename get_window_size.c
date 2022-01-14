/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:36 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/14 15:11:11 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

/*
** TIOCGWINSZ
** Terminal IOCtl (stands for Input/Output Control) Get WINdow SiZe
*/

void	get_window_size(t_select *data)
{
	struct winsize	window;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window) != -1)
	{
		data->window_rows = window.ws_row;
		data->window_columns = window.ws_col;
		ft_printf("lines %i columns %i\r\n", window.ws_row, window.ws_col);
	}
	else
	{
		ft_printf("check rows and columns\n");
		data->window_rows = 25;
		data->window_columns = 50;
		// add here the window size checking with the hard way
		// kind of looping through the window with esc sequence commands
	}
}
