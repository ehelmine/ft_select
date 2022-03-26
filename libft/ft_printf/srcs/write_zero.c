/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:20:13 by ehelmine          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/24 11:19:50 by ehelmine         ###   ########.fr       */
=======
/*   Updated: 2022/02/10 15:04:23 by ehelmine         ###   ########.fr       */
>>>>>>> 398ec6d825907fda58380f32fdb29620bcdeedae
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_zero_2(t_val *all)
{
	while (all->real_len > 1)
	{
		write(1, " ", 1);
		all->real_len--;
		all->output_len++;
	}
	if (all->conv == 'o' && all->hash_flag && all->width <= 1
		&& all->real_len == 1)
	{
		write(1, "0", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->width != -1 && all->real_len == 1)
	{
		write(1, " ", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->plus_flag && !all->minus_flag)
	{
		write(1, "+", 1);
		all->output_len++;
		all->real_len--;
	}
}

void	write_zero(t_val *all)
{
	if (all->width == -1 && ((all->conv == 'o' && !all->hash_flag)
			|| (all->conv == 'x' || all->conv == 'X')))
		all->real_len -= 1;
	if (all->plus_flag && all->minus_flag)
	{
		write(1, "+", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->space_flag)
	{
		write(1, " ", 1);
		all->output_len++;
		all->real_len--;
	}
	write_zero_2(all);
}
