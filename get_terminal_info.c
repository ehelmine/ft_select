/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_terminal_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:08:07 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/11 11:59:33 by ehelmine         ###   ########.fr       */
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
** This function finds the description and remembers it internally so that
** you can interrogate it about specific terminal capabilities
** The return value of tgetent is -1 if there is some difficulty accessing
** the data base of terminal types, 0 if the data base is accessible but
** the specified type is not defined in it, and some other value otherwise.
*/

int	get_terminal_info(t_select *data)
{
	int	check;
	
	if (isatty(ttyslot()))
		data->device_name = ttyname(ttyslot());
	else
		return (output_error(0));
	if (data->device_name == NULL)
		return (output_error(0));
	data->terminal_envname = getenv("TERM");
	if (data->terminal_envname == NULL)
		return (output_error(1));
	check = tgetent(data->terminal_description, data->terminal_envname);
	if (check == -1)
		return (output_error(2));
	else if (check == 0)
		return (output_error(3));
	get_terminal_capabilites(data);
	ft_printf("device_name %s envname %s\n", data->device_name, data->terminal_envname);
	return (1);
}