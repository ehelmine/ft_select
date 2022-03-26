/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:36:02 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/19 14:23:06 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_correct_flags(char *flags, va_list args, t_val *all)
{
	int	i;
	int	ii;

	ii = 0;
	all->no_flags = 0;
	i = ft_strlen(flags) - 1;
	all->conv = flags[i];
	all->zero_x = 0;
	set_values(all, flags, flags[i]);
	if (flags[i] == 's' || flags[i] == 'p')
		check_flags_p_and_s(all, flags, ii);
	else if (flags[i] == 'c' || flags[i] == '%')
		check_flags_c(all, flags, flags[i], ii);
	else if (flags[i] == 'i' || flags[i] == 'd' || flags[i] == 'o'
		|| flags[i] == 'x' || flags[i] == 'X' || flags[i] == 'u')
		check_flags_int(all, flags, ii, flags[i]);
	else if (flags[i] == 'f')
		check_flags_float(all, flags, ii);
	return (get_arg(all, args, flags[i]));
}

int	loop_flags(const char *ptr, t_val *all, char *flags)
{
	int	i;
	int	x;

	i = 0;
	all->move = 0;
	x = 0;
	while (*ptr != '\0')
	{
		flags[i++] = *ptr;
		if (*ptr == 's' || *ptr == 'c' || *ptr == 'p' || *ptr == 'd'
			|| *ptr == 'i' || *ptr == 'o' || *ptr == 'u' || *ptr == 'x'
			|| *ptr == 'X' || *ptr == 'f' || *ptr == '%')
		{
			x = 1;
			break ;
		}
		ptr++;
		all->move++;
	}
	all->move++;
	flags[i] = '\0';
	if (x == 1)
		return (1);
	else
		return (0);
}

int	loop_parameters(const char *ptr, va_list args, t_val *all, char *flags)
{
	int	x;

	x = 0;
	while (*ptr != '\0')
	{
		while (*ptr != '%' && *ptr != '\0')
		{
			write(1, (const void *)ptr, 1);
			all->output_len++;
			ptr++;
		}
		if (*ptr == '\0')
			break ;
		ptr++;
		x = loop_flags(ptr, all, flags);
		if (x == 0)
			break ;
		if (check_correct_flags(flags, args, all) == -1)
			return (-1);
		ptr = ptr + all->move;
	}
	return (1);
}

int	ft_printf(const char *begin, ...)
{
	va_list	args;
	t_val	all;
	int		len;
	char	*flags;

	all.check = 0;
	va_start(args, begin);
	flags = (char *)malloc(sizeof(char) * 100);
	if (flags == NULL)
		return (-1);
	all.output_len = 0;
	if (loop_parameters(begin, args, &all, flags) == -1)
		return (-1);
	va_end(args);
	len = all.output_len;
	free(flags);
	return (len);
}
