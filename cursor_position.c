/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:10 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/18 18:09:56 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	cursor_position(t_select *data)
{
	char *x;
	char *y;
	char *tmp;

	if (data->cursor_pos != NULL)
		ft_memdel((void *)data->cursor_pos);
	x = ft_itoa(data->cursor_x);
	y = ft_itoa(data->cursor_y);
	if (x != NULL & y != NULL)
	{
		tmp = ft_strjoin("\x1b[", y);
		free(y);
		y = ft_strjoin(tmp, ";");
		free(tmp);
		data->cursor_pos = ft_strjoin_three(y, x, "H");
		free(x);
	}
	else
		data->cursor_pos = ft_strdup("");
}