/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 15:21:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/06/02 13:42:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** %[flags in any order:#+-0 ]
** [min field width][.precision][conversion specifier]
*/

void	check_h_and_l(t_val *all, char *flags, int i)
{
	if (flags[i] == 'h')
	{
		i++;
		if (flags[i] == 'h')
		{
			all->hh = 1;
			i++;
		}
		else
			all->h = 1;
	}
	if (flags[i] == 'l')
	{
		i++;
		if (flags[i] == 'l')
		{
			all->ll = 1;
			i++;
		}
		else
			all->l = 1;
	}
	return ;
}

int	check_flags_float(t_val *all, char *flags, int i)
{
	while (flags[i] == '+' || flags[i] == '-'
		|| flags[i] == ' ' || flags[i] == '#' || flags[i] == '0')
	{
		if (flags[i] == '+')
			all->plus_flag = 1;
		else if (flags[i] == '-')
			all->minus_flag = 1;
		else if (flags[i] == ' ')
			all->space_flag = 1;
		else if (flags[i] == '0')
			all->zero_flag = 1;
		else if (flags[i] == '#')
			all->hash_flag = 1;
		i++;
	}
	i = check_width_and_precision(all, flags, i);
	if (flags[i] == 'l' || flags[i] == 'L')
	{
		if (flags[i] == 'l')
			all->l = 1;
		else if (flags[i] == 'L')
			all->big_l = 1;
		i++;
	}
	return (1);
}

int	check_flags_int(t_val *all, char *f, int i, char c)
{
	if (f[i + 1] == '\0')
	{
		all->no_flags = 1;
		return (1);
	}
	while (f[i] == '+' || f[i] == '-' || f[i] == ' ' || f[i] == '#'
		|| f[i] == '0' || f[i] == '*')
	{
		if (f[i] == '+' && (c == 'd' || c == 'i'))
			all->plus_flag = 1;
		else if (f[i] == '-')
			all->minus_flag = 1;
		else if (f[i] == ' ' && (c == 'd' || c == 'i'))
			all->space_flag = 1;
		else if (f[i] == '0')
			all->zero_flag = 1;
		else if (f[i] == '#')
			all->hash_flag = 1;
		else if (f[i] == '*')
			all->asterisk_flag = 1;
		i++;
	}
	i = check_width_and_precision(all, f, i);
	check_h_and_l(all, f, i);
	return (1);
}

int	check_flags_percentage(t_val *all, char *flags, int i)
{
	if (flags[i] == '%' && flags[i + 1] == '\0')
		return (1);
	while (flags[i] == '-' || flags[i] == '0' || flags[i] == '+'
		|| flags[i] == ' ' || flags[i] == '#')
	{
		if (flags[i] == '+')
			all->plus_flag = 1;
		else if (flags[i] == '-')
			all->minus_flag = 1;
		else if (flags[i] == ' ')
			all->space_flag = 1;
		else if (flags[i] == '0')
			all->zero_flag = 1;
		i++;
	}
	i = check_width_and_precision(all, flags, i);
	return (1);
}
