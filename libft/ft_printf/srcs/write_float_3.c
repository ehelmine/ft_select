/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:23 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/22 15:41:45 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_float_output_3(t_val *all, int i)
{
	while (all->len < all->width)
	{
		if (all->minus_flag == 1)
			all->str[i++] = ' ';
		else
		{
			if (all->zero_flag == 1)
			{
				if (all->str[0] == '+' || all->str[0] == '-'
					|| all->str[0] == ' ')
				{
					ft_putchar(all->str[0]);
					all->str++;
				}
				ft_putchar('0');
			}
			else
				ft_putchar(' ');
		}
		all->len++;
	}
}

static int	write_float_output_2(t_val *all, int i)
{
	int	ii;
	int	x;

	ii = 0;
	while (all->begin_str[ii] != '\0')
		all->str[i++] = all->begin_str[ii++];
	all->str[i] = '\0';
	if (all->orig_precision != 0 || all->hash_flag == 1)
		all->str[i++] = '.';
	if (all->orig_precision != 0)
	{
		x = ft_strlen(all->end_str);
		while (x < all->orig_precision)
		{
			all->str[i++] = '0';
			x++;
		}
		ii = 0;
		while (all->end_str[ii] != '\0')
			all->str[i++] = all->end_str[ii++];
		all->str[i] = '\0';
	}
	return (i);
}

int	write_float_output(t_val *all)
{
	all->end_str = ft_itoa(all->end_i);
	if (all->end_str == NULL)
		return (-1);
	all->str = (char *)ft_memalloc(1000);
	if (all->str == NULL)
		return (-1);
	all->tmp = all->str;
	all->y = 0;
	if (all->space_flag == 1 && all->negative_val < 1)
		all->str[all->y++] = ' ';
	if (all->negative_val == 1)
		all->str[all->y++] = '-';
	if (all->negative_val < 1 && all->plus_flag == 1 && all->space_flag < 1)
		all->str[all->y++] = '+';
	all->y = write_float_output_2(all, all->y);
	all->len = ft_strlen(all->str);
	if (all->len < all->width)
		write_float_output_3(all, all->y);
	all->output_len += all->len;
	ft_putstr(all->str);
	free(all->end_str);
	free(all->begin_str);
	free(all->tmp);
	return (1);
}

int	write_float_9(t_val *all)
{
	free(all->end_str);
	all->end_str = ft_itoa(all->end_i);
	if (all->end_str == NULL)
		return (-1);
	all->y = ft_strlen(all->end_str) - 1;
	while (all->y >= 0 && all->end_str[all->y] == '9')
		all->y--;
	all->end_str[all->y] = all->end_str[all->y] + 1;
	all->y++;
	while (all->end_str[all->y] != '\0')
		all->end_str[all->y++] = '0';
	all->end_i = ft_atoi(all->end_str);
	free(all->end_str);
	return (1);
}

void	write_float_8_second(t_val *all)
{
	if (all->big_l == 1)
	{
		if (all->extra_zero == 1)
			all->end_i = all->end_i;
		else
		{
			all->am_of_decimals = 1;
			all->precision = all->orig_precision + 1;
			while (all->precision != 0)
			{
				all->am_of_decimals *= 5;
				all->precision--;
			}
			if ((all->end_i * 10 + 5) % (int)all->am_of_decimals == 0)
			{
				if ((int)all->end_i % 2 != 0)
					all->end_i++;
			}
		}
	}
}
