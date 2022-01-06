/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:05:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/06/07 17:54:38 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_num_type(t_val *all)
{
	if (all->h == 1)
	{
		if (all->num < -32768)
			all->num = 0;
		else if (all->num > 32767)
			all->num = -32768;
	}
	else if (all->hh == 1)
	{
		if (all->num < -128)
			all->num = 127;
		else if (all->num > 127)
			all->num = -128;
	}
	return (1);
}

int	get_arg_unsigned_int(t_val *all, va_list args)
{
	if (all->asterisk_flag)
		return (write_asterisk(all, args));
	if (all->conv == 'u')
		all->base = 10;
	if (all->conv == 'o')
		all->base = 8;
	if (all->conv == 'x' || all->conv == 'X')
	{
		all->base = 16;
		if (all->conv == 'X')
			all->big_x = 1;
	}
	if (all->h == 1)
		all->unum = (unsigned short)va_arg(args, unsigned int);
	else if (all->l == 1)
		all->unum = (unsigned long)va_arg(args, unsigned long);
	else if (all->ll == 1)
		all->unum = (unsigned long long)va_arg(args, unsigned long long);
	else if (all->hh == 1)
		all->unum = (unsigned char)va_arg(args, unsigned int);
	else
		all->unum = va_arg(args, unsigned int);
	if (all->unum == 0)
		all->zero_num = 1;
	return (write_unsigned(all));
}

int	get_arg_signed_int(t_val *all, va_list args)
{
	if (all->asterisk_flag)
		return (write_asterisk(all, args));
	if (all->h == 1)
		all->num = (short int)va_arg(args, int);
	else if (all->ll == 1 || all->l == 1)
	{
		all->num = (long long int)va_arg(args, long long int);
		if ((long long int)all->num == -9223372036854775807 - 1)
		{
			write(1, "-9223372036854775808", 20);
			all->output_len += 20;
			return (1);
		}
	}
	else if (all->hh == 1)
		all->num = (signed char)va_arg(args, int);
	else
		all->num = va_arg(args, signed int);
	if (all->num == 0)
		all->zero_num = 1;
	if (all->no_flags == 1)
		return (write_no_flags(all));
	if (check_num_type(all))
		return (write_d_and_i(all));
	return (1);
}

int	get_arg_s_and_p(t_val *all, va_list args, char x)
{
	if (x == 's')
	{
		all->str = va_arg(args, char *);
		if (all->no_flags == 1)
			return (write_no_flags(all));
		return (write_s(all));
	}
	else if (x == 'p')
	{
		all->vd_ptr = va_arg(args, void *);
		all->num = (intmax_t)all->vd_ptr;
		if (all->num == 0)
			all->zero_num = 1;
		all->y = 0;
		return (write_p(all));
	}
	return (1);
}

int	get_arg(t_val *all, va_list args, char x)
{
	if (x == 'c' || x == '%')
	{
		if (x == 'c')
			all->c = (char)va_arg(args, int);
		if (x == '%')
			all->c = '%';
		write_c(all);
	}
	else if (x == 'f')
	{
		all->d_num = va_arg(args, double);
		if (all->big_l == 1)
			all->d_num = va_arg(args, long double);
		all->begin_str = NULL;
		all->end_str = NULL;
		all->str = NULL;
		return (write_float(all, 0, 0, 0));
	}
	else if (x == 'i' || x == 'd')
		return (get_arg_signed_int(all, args));
	else if (x == 's' || x == 'p')
		return (get_arg_s_and_p(all, args, x));
	else if (x == 'o' || x == 'x' || x == 'X' || x == 'u')
		return (get_arg_unsigned_int(all, args));
	return (1);
}
