/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:10 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/27 13:23:19 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select *data_plus;

void	cursor_position(t_select *data)
{
	char	*x;
	char	*y;
	char	*tmp;
	int		i;

	if (data->cursor_pos != NULL)
		ft_memdel((void *)&data->cursor_pos);
	x = NULL;
	y = NULL;
	tmp = NULL;
	if (data->cursor_y > data->window_rows)
	{
		x = ft_itoa(2 + (int)ft_strlen(data->input[data->cursor_y - data->window_rows]) + 3 + 4);
		i = data->cursor_y;
		while (i > data->window_rows)
			i -= data->window_rows;
		y = ft_itoa(i);
	}
	else
	{
		x = ft_itoa(data->cursor_x);
		y = ft_itoa(data->cursor_y);
	}
	if (x != NULL && y != NULL)
	{
		tmp = ft_strjoin("\x1b[", y);
		ft_memdel((void *)&y);
		y = ft_strjoin(tmp, ";");
		ft_memdel((void *)&tmp);
		data->cursor_pos = ft_strjoin_three(y, x, "H");
	}
	else
		data->cursor_pos = ft_strdup("");
	ft_memdel_two((void *)&x, (void *)&y);
}
