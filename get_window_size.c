/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:36 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/17 21:09:53 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

/*
** TIOCGWINSZ
** Terminal IOCtl (stands for Input/Output Control) Get WINdow SiZe
*/

int	get_window_size(t_select *data, int when)
{
	struct winsize	window;

	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window) != -1)
	{
		if (when > 0 && (data->window_rows != window.ws_row
			|| data->window_columns != window.ws_col))
		{
			data->window_rows = window.ws_row;
			data->window_columns = window.ws_col;
			return (-1);
		}
		data->window_rows = window.ws_row;
		data->window_columns = window.ws_col;
		return (1);
		//ft_printf("lines %i columns %i\r\n", window.ws_row, window.ws_col);
	}
	ft_printf("check rows and columns\n");
	data->window_rows = 25;
	data->window_columns = 50;
	return (1);
	// add here the window size checking with the hard way
	// kind of looping through the window with esc sequence commands
}
