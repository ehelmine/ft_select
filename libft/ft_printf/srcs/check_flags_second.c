/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_second.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:20:12 by ehelmine          #+#    #+#             */
/*   Updated: 2021/06/02 13:40:35 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_width_and_precision(t_val *all, char *flags, int i)
{
	if (flags[i] >= '0' && flags[i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		i += ft_check_int_len(all->width);
	}
	if (flags[i] == '.')
	{
		if (!(ft_isdigit((int)flags[i + 1])))
		{
			all->precision = 0;
			i++;
			if (flags[i] == '-' && (flags[i + 1] >= '1' && flags[i + 1] <= '9'))
				i += ft_check_int_len(ft_atoi(flags + i + 1));
		}
		else
		{
			all->precision = ft_atoi(flags + i + 1);
			i += ft_check_int_len(all->precision) + 1;
		}
	}
	return (i);
}

int	check_flags_c(t_val *all, char *flags, char c, int i)
{
	if (c == '%')
		return (check_flags_percentage(all, flags, i));
	while (flags[i] == '+' || flags[i] == '-' || flags[i] == ' '
		|| flags[i] == '#' || flags[i] == '0')
	{
		if (flags[i] == '-')
			all->minus_flag = 1;
		i++;
	}
	if (flags[i] >= '1' && flags[i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		flags += ft_check_int_len(all->width) + i;
	}
	if (*flags == '.')
		flags++;
	while (*flags >= '1' && *flags <= '9')
		flags++;
	return (1);
}

int	check_flags_p_and_s(t_val *all, char *flags, int i)
{
	if (flags[i + 1] == '\0')
	{
		all->no_flags = 1;
		return (1);
	}
	while (flags[i] == '-' || flags[i] == '+'
		|| flags[i] == ' ' || flags[i] == '#' || flags[i] == '0')
	{
		if (flags[i] == '-')
			all->minus_flag = 1;
		i++;
	}
	i = check_width_and_precision(all, flags, i);
	return (1);
}

void	set_values(t_val *all, char *flags, char c)
{
	all->new_flags = flags;
	all->zero_flag = 0;
	all->minus_flag = 0;
	all->hash_flag = 0;
	all->plus_flag = 0;
	all->space_flag = 0;
	all->asterisk_flag = 0;
	all->l = 0;
	all->ll = 0;
	all->big_l = 0;
	all->h = 0;
	all->hh = 0;
	all->zero_num = 0;
	all->big_x = 0;
	all->precision = 0;
	all->width = 0;
	all->minimum_width = 0;
	if (c == 's' || c == '%' || c == 'd' || c == 'i' || c == 'x'
		|| c == 'X' || c == 'u' || c == 'o' || c == 'p')
		all->precision = -1;
	if (c == 'd' || c == 'i' || c == 'p' || c == 'x' || c == 'X'
		|| c == 'u' || c == 'o' || c == 'f')
		all->width = -1;
	if (c == 'f')
		all->precision = 6;
}
