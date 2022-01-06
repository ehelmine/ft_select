/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:02:38 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/22 15:41:27 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_float_4(t_val *all)
{
	if ((int)all->d_num == 9 && all->orig_precision > 1 && all->big_l == 1)
	{
		all->d_num -= (int)all->d_num;
		all->d_num *= 10;
		while ((int)all->d_num == 9)
		{
			all->d_num -= (int)all->d_num;
			all->d_num *= 10;
		}
		if ((int)all->d_num >= 0)
		{
			if (all->end_i == 0)
				all->d_num = 10;
			else
			{
				all->end_i++;
				all->d_num = 0;
			}
		}
	}
}

static void	write_float_3(t_val *all)
{
	if (all->big_l == 1 && all->orig_precision == 1 && all->end_i != 0
		&& all->end_i < 10)
	{
		all->i = 1;
		all->precision = all->orig_precision + 1;
		while (all->precision != 0)
		{
			all->i *= 10;
			all->precision--;
		}
		all->yy = (double)5 / (double)all->i;
		all->d_num -= all->yy;
		all->extra_zero = 1;
	}
	while (all->am_of_decimals != 1)
	{
		all->d_num *= 10;
		all->am_of_decimals /= 10;
	}
	all->end_i = (intmax_t)all->d_num;
	all->d_num -= all->end_i;
	all->d_num *= 10;
}

static int	write_float_2(t_val *all)
{
	if (all->space_flag == 1 && all->plus_flag == 1)
		all->space_flag = 0;
	all->negative_val = 0;
	if (all->d_num < 0 || (all->d_num == 0 && 1.0 / all->d_num < 0))
	{
		all->d_num *= -1;
		all->negative_val = 1;
	}
	all->begin_i = (signed long int)all->d_num;
	all->am_of_decimals = 1;
	all->orig_precision = all->precision;
	while (all->precision != 0)
	{
		all->am_of_decimals *= 10;
		all->precision--;
	}
	all->begin_str = ft_itoa(all->begin_i);
	if (all->begin_str == NULL)
		return (-1);
	all->d_num -= all->begin_i;
	all->extra_zero = 0;
	return (1);
}

int	write_float_second(t_val *all, int out)
{
	out = 0;
	if ((int)all->end_i % 10 == 9)
	{
		if (write_float_9(all) == -1)
			return (-1);
	}
	else
	{
		all->end_i++;
		all->d_num = 0;
	}
	return (1);
}

int	write_float(t_val *all, int i, int x, int out)
{
	if (write_float_2(all) == -1)
		return (-1);
	write_float_3(all);
	write_float_4(all);
	if (all->orig_precision == 0)
	{
		if (write_float_5(all, out) == -1)
			return (-1);
	}
	else if (all->orig_precision > 0)
	{
		write_float_7(all);
		if ((int)all->d_num == 5)
		{
			if (write_float_8(all, x, i) == -1)
				return (-1);
		}
		else if ((int)all->d_num > 5)
		{
			if (write_float_second(all, out) == -1)
				return (-1);
		}
	}
	return (write_float_output(all));
}
