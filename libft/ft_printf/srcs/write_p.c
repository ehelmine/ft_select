/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:58:06 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/10 15:06:51 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	write_p_3(t_val *all, char *output, char *number, int i)
{
	int	a;

	a = all->len - 1;
	while (a >= 0)
	{
		output[i++] = number[a--];
		all->output_len++;
	}
	if (all->minus_flag)
	{
		while (i < all->real_len)
		{
			output[i++] = ' ';
			all->output_len++;
		}
	}
	output[i] = '\0';
	ft_putstr(output);
	free(number);
	free(output);
	return (1);
}

static void	write_p_2(t_val *all, char *number, char *abc)
{
	int	a;
	int	x;

	a = 0;
	if (all->num == 0 && all->precision != 0)
		number[a++] = '0';
	while (all->num != 0)
	{
		x = all->num % 16;
		number[a++] = abc[x];
		all->num /= 16;
	}
	number[a++] = 'x';
	number[a++] = '0';
	number[a] = '\0';
	all->len = a;
	all->real_len = all->len;
	if (all->width > all->len)
		all->real_len = all->width;
	return ;
}

int	write_p(t_val *all)
{
	char	*abc;
	char	*output;
	char	*number;

	abc = "0123456789abcdef";
	number = (char *)malloc(sizeof(char) * 1000);
	if (number == NULL)
		return (-1);
	write_p_2(all, number, abc);
	output = (char *)malloc(sizeof(char) * (all->real_len + 1));
	if (output == NULL)
	{
		free(number);
		return (-1);
	}
	if (!all->minus_flag)
	{
		while (all->y < all->real_len - all->len)
		{
			output[all->y++] = ' ';
			all->output_len++;
		}
	}
	return (write_p_3(all, output, number, all->y));
}
