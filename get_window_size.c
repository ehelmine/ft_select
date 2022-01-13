/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:53:36 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/13 16:54:39 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	get_window_size(t_select *data)
{
	struct winsize	window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
	data->window_rows = window.ws_row;
	data->window_columns = window.ws_col;
	ft_printf("lines %i columns %i\r\n", window.ws_row, window.ws_col);
}
