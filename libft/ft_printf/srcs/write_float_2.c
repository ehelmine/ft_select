/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:03:30 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/08 16:10:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	write_float_8(t_val *all, int x, int i)
{
	while (x < 18)
	{
		all->d_num = (all->d_num - (int)all->d_num) * 10;
		if ((int)all->d_num != 0)
		{
			all->end_i++;
			free(all->end_str);
			all->end_str = ft_itoa(all->end_i);
			if (all->end_str == NULL)
				return (-1);
			i = (int)ft_strlen(all->end_str) - 1;
			if (all->big_l == 1)
				write_float_8_second(all);
			else if ((all->begin_i == 0 && all->end_i == 0)
				|| (int)all->end_str[i] % 2 != 0)
				all->end_i++;
			if ((int)all->end_str[i] % 2 != 0)
				all->d_num = 0;
			free(all->end_str);
			break ;
		}
		x++;
	}
	return (1);
}

void	write_float_7(t_val *all)
{
	if (all->big_l == 1 && all->orig_precision == 1 && (int)all->d_num == 5)
	{
		if (all->end_i == 0 || all->end_i == 1 || all->end_i == 5
			|| all->end_i == 8 || all->end_i == 7)
		{
			all->end_i++;
			all->d_num = 0;
		}
	}
	if ((int)all->d_num == 4 && all->big_l == 1)
	{
		all->d_num -= (int)all->d_num;
		all->d_num *= 10;
		if ((int)all->d_num == 9)
		{
			while ((int)all->d_num == 9)
				all->d_num = (all->d_num - (int)all->d_num) * 10;
			if ((int)all->d_num >= 0)
				all->d_num = 5;
			else
				all->d_num = 4;
		}
	}
}

static int	write_float_6(t_val *all)
{
	all->i = 0;
	all->ii = 0;
	while (all->i < 7)
	{
		all->d_num -= (int)all->d_num;
		all->d_num *= 10;
		if ((int)all->d_num >= 5)
		{
			free(all->begin_str);
			all->begin_str = ft_itoa(all->begin_i + 1);
			if (all->begin_str == NULL)
				return (-1);
			all->end_i = 0;
			all->ii = 1;
			break ;
		}
		else if ((int)all->d_num > 0 && (int)all->d_num < 5)
		{
			all->ii = 1;
			break ;
		}
		all->i++;
	}
	return (all->ii);
}

static int	write_float_5_second(t_val *all)
{
	int	out;

	out = write_float_6(all);
	if (out == -1)
		return (-1);
	if (out != 1 && all->begin_i % 2 != 0)
	{
		free(all->begin_str);
		all->begin_str = ft_itoa(all->begin_i + 1);
		if (all->begin_str == NULL)
			return (-1);
		all->d_num = 0;
	}
	return (1);
}

int	write_float_5(t_val *all, int out)
{
	out = 0;
	if ((int)all->d_num > 5)
	{
		free(all->begin_str);
		all->begin_str = ft_itoa(all->begin_i + 1);
		if (all->begin_str == NULL)
			return (-1);
		all->d_num = 0;
	}
	else if ((int)all->d_num == 5)
	{
		if (write_float_5_second(all) == -1)
			return (-1);
	}
	else if (all->end_i > 5)
	{
		free(all->begin_str);
		all->begin_str = ft_itoa(all->begin_i + 1);
		if (all->begin_str == NULL)
			return (-1);
		all->end_i = 0;
		all->d_num = 0;
	}
	return (1);
}
