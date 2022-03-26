/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_signed_ints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:28:37 by ehelmine          #+#    #+#             */
/*   Updated: 2022/03/26 15:28:38 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	write_d_and_i_right_ad_4(t_val *all, char *output, int x)
{
	while (all->real_len > 0)
	{
		if (all->zero_flag && all->precision < 0)
		{
			if (all->num == 0 && all->zero_flag)
			{
				output[x++] = '0';
				output[x] = '\0';
			}
			else
				write(1, "0", 1);
		}
		else
			write(1, " ", 1);
		all->real_len--;
		all->output_len++;
	}
}

int	write_d_and_i_right_ad_3(t_val *all, char *num_str, char *output, int x)
{
	while (all->precision > all->len)
	{
		output[x++] = all->fill_char;
		all->output_len++;
		all->real_len--;
		all->precision--;
	}
	output[x] = '\0';
	num_str = ft_itoa(all->num);
	if (num_str == NULL)
		return (-1);
	all->tmp = num_str;
	all->output_len += all->len;
	all->real_len -= all->len;
	write_d_and_i_right_ad_4(all, output, x);
	ft_putstr(output);
	if (all->num < 0)
		num_str++;
	ft_putstr(num_str);
	free(all->tmp);
	free(output);
	return (1);
}

int	write_d_and_i_right_ad_2(t_val *all, char *output, int x)
{
	if (all->num >= 0)
	{
		if (all->zero_flag)
			write(1, "+", 1);
		if (!(all->zero_flag))
			output[x++] = '+';
		all->output_len++;
		all->real_len--;
	}
	if (all->num < 0)
	{
		if (all->precision == -1 && all->zero_flag)
			write(1, "-", 1);
		else
			output[x++] = '-';
		all->real_len--;
		all->output_len++;
	}
	return (x);
}

int	write_d_and_i_right_ad(t_val *all)
{
	char	*output;
	char	*num_str;
	int		x;

	x = 0;
	output = (char *)malloc(sizeof(char) * 10000);
	if (output == NULL)
		return (-1);
	if (all->space_flag && all->num >= 0)
	{
		output[x++] = ' ';
		all->output_len++;
		all->real_len--;
	}
	if ((all->plus_flag && all->num >= 0) || (all->num < 0))
		x = write_d_and_i_right_ad_2(all, output, x);
	num_str = NULL;
	return (write_d_and_i_right_ad_3(all, num_str, output, x));
}

void	write_d_and_i_left_ad_2(t_val *all)
{
	while (all->precision > all->len)
	{
		write(1, "0", 1);
		all->output_len++;
		all->real_len--;
		all->precision--;
	}
	if (all->num < 0)
		all->num = all->num * -1;
	ft_putnbr(all->num);
	all->output_len += ft_check_int_len(all->num);
	all->real_len -= ft_check_int_len(all->num);
	while (all->real_len > 0)
	{
		write(1, " ", 1);
		all->real_len--;
		all->output_len++;
	}
}
