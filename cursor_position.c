/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:01:10 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/28 12:05:51 by ehelmine         ###   ########.fr       */
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
	int		b_len;
	int		total;
	int		times;

	if (data->cursor_pos != NULL)
		ft_memdel((void *)&data->cursor_pos);
	x = NULL;
	y = NULL;
	tmp = NULL;
	if (data->cursor_y > data->window_rows)
	{
		i = data->cursor_y;
		while (i > data->window_rows)
			i -= data->window_rows;
		y = ft_itoa(i);
		total = 0;
		times = 1;
		while (i < data->cursor_y)
		{
			b_len = 0;
			while (i < data->window_rows * times && i < data->cursor_y)
			{
				if (data->input_info[i][1] > b_len)
					b_len = data->input_info[i][1];
				i++;
			}
			total += b_len;
			times++;
		}
		x = ft_itoa(2 + b_len + 3 + 4);
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
