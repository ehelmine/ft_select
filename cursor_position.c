/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:10 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/19 17:11:58 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	cursor_position(t_select *data)
{
	char	*x;
	char	*y;
	char	*tmp;

	if (data->cursor_pos != NULL)
		ft_memdel((void *)&data->cursor_pos);
	x = NULL;
	y = NULL;
	tmp = NULL;
	x = ft_itoa(data->cursor_x);
	y = ft_itoa(data->cursor_y);
	if (x != NULL & y != NULL)
	{
		tmp = ft_strjoin("\x1b[", y);
		ft_memdel((void *)&y);
		y = ft_strjoin(tmp, ";");
		ft_memdel((void *)&tmp);
		data->cursor_pos = ft_strjoin_three(y, x, "H");
		ft_memdel_two((void *)&x, (void *)&y);
	}
	else
	{
		data->cursor_pos = ft_strdup("");
		ft_memdel_two((void *)&x, (void *)&y);
	}
}
