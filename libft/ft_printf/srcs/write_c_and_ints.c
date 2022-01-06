/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_c_and_ints.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:58 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/03 13:43:04 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	real_width(int num_len, int input_width, int precision)
{
	if ((num_len == input_width && input_width == precision) || (num_len
			>= input_width && num_len >= precision))
		return (num_len);
	else if (num_len <= input_width && input_width >= precision)
		return (input_width);
	else if (precision >= input_width && num_len <= precision)
		return (precision);
	return (-1);
}

void	write_d_and_i_left_ad(t_val *all)
{
	if (all->num < 0)
	{
		write(1, "-", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->space_flag == 1 && all->num >= 0)
	{
		write(1, " ", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->plus_flag == 1)
	{
		write(1, "+", 1);
		all->output_len++;
		all->real_len--;
	}
	write_d_and_i_left_ad_2(all);
}

int	write_d_and_i(t_val *all)
{
	all->fill_char = '0';
	if (all->space_flag == 1 && all->plus_flag == 1)
		all->space_flag = 0;
	if (all->plus_flag == 1 && all->num < 0)
		all->plus_flag = 0;
	all->len = ft_check_int_len(all->num);
	if (all->num < 0)
		all->len -= 1;
	all->real_len = all->len;
	if (all->precision != -1 || all->width != -1)
		all->real_len = real_width(all->len, all->width, all->precision);
	if (all->zero_num == 1 && all->precision == 0)
	{
		write_zero(all);
		return (1);
	}
	while (all->real_len > 0)
	{
		if (all->minus_flag == 1)
			write_d_and_i_left_ad(all);
		else
			return (write_d_and_i_right_ad(all));
	}
	return (1);
}

void	write_c(t_val *all)
{
	all->fill_char = ' ';
	if (all->minus_flag < 1 && all->zero_flag == 1)
		all->fill_char = '0';
	if (all->new_flags[0] != '-')
	{
		while (all->width - 1 > 0)
		{
			write(1, &all->fill_char, 1);
			all->output_len++;
			all->width--;
		}
		write(1, &all->c, 1);
		all->output_len++;
	}
	else
	{
		write(1, &all->c, 1);
		all->output_len++;
		while (all->width - 1 > 0)
		{
			write(1, &all->fill_char, 1);
			all->output_len++;
			all->width--;
		}
	}
}
