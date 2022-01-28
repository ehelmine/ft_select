/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:10 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/28 15:31:51 by ehelmine         ###   ########.fr       */
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
	int		total;
	int		times;

	if (data->cursor_pos != NULL)
		ft_memdel((void *)&data->cursor_pos);
	x = NULL;
	y = NULL;
	tmp = NULL;
	if (data->cursor_y > data->window_rows)
	{
		times = 0;
		i = data->cursor_y;
		while (i > data->window_rows)
		{
			times++;
			i -= data->window_rows;
		}
		y = ft_itoa(i);
		i = 0;
		total = (times * 7);
		while (times > 0)
		{
			total += data->col_lengths[i++];
			times--;
		}
		x = ft_itoa(total + 2);
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
