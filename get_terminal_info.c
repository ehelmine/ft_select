/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminal_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:08:07 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/10 16:24:34 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

/*
** isatty function determines if the file descriptor fd refers to a
** valid terminal type device.
**
** ttyname() function gets the related device name of a file descriptor
** for which isatty() is true.
** The ttyname() function returns the name stored in a static buffer which
** will be overwritten on subsequent calls.
**
** int tgetent (char *buffer, char *termtype);
**
*/

void	get_terminal_info(t_select *data)
{
	if (isatty(0))
		data->terminal_dname = ttyname(0);
	// error management if isatty and/or ttyname fails
	data->terminal_envname = getenv("TERM");
	// error management if getenv doesnt return anything good
	ft_printf("terminal dname %s envname %s\n", data->terminal_dname, data->terminal_envname);
	ttyslot();
	
}