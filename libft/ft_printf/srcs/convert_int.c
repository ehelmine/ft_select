/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:22:11 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/03 16:09:23 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*convert_num_3(t_val *all, char *number, int a)
{
	int	x;

	if (all->hash_flag && !all->zero_num && (all->conv == 'x'
			|| all->conv == 'X'))
	{
		number[a++] = all->conv;
		number[a++] = '0';
		all->zero_x = 1;
	}
	if (all->conv == 'o' && all->hash_flag)
		number[a++] = '0';
	number[a] = '\0';
	if (all->precision && (all->conv == 'o' || all->conv == 'u'))
	{
		x = all->precision;
		while ((int)ft_strlen(number) < x)
		{
			number[a] = '0';
			number[++a] = '\0';
		}
	}
	all->len = a;
	return (number);
}

static char	*convert_num_2(t_val *all, char *number, int a)
{
	number[a] = '\0';
	if (all->precision && (all->conv == 'u' || all->conv == 'x'
			|| all->conv == 'X'))
	{
		while ((int)ft_strlen(number) < all->precision)
		{
			number[a++] = '0';
			number[a] = '\0';
		}
	}
	if (all->hash_flag && (all->conv == 'x' || all->conv == 'X')
		&& !all->minus_flag && all->zero_flag)
	{
		while ((int)ft_strlen(number) < all->width - 2)
		{
			number[a++] = '0';
			number[a] = '\0';
		}
	}
	return (convert_num_3(all, number, a));
}

char	*convert_num(t_val *all)
{
	char	*number;
	char	*abc;
	int		a;
	int		x;

	abc = "0123456789abcdef";
	number = (char *)malloc(sizeof(char) * 1000);
	if (number == NULL)
		return (NULL);
	a = 0;
	if (all->unum == 0)
	{
		number[a++] = '0';
		all->len = a;
		return (number);
	}
	while (all->unum != 0)
	{
		x = all->unum % all->base;
		number[a++] = abc[x];
		all->unum /= all->base;
	}
	return (convert_num_2(all, number, a));
}
