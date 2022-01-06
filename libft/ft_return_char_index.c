/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_char_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:39:56 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/15 13:07:40 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_return_char_index(char *str, char c, char startpoint)
{
	size_t	i;

	i = 0;
	if (startpoint == 'b')
	{
		while (str[i] != '\0')
		{
			if (str[i] == c)
				return (i);
			i++;
		}
	}
	else if (startpoint == 'e')
	{
		i = ft_strlen(str);
		while (i >= 0)
		{
			if (str[i] == c)
				return (i);
			i--;
		}
	}
	return (-1);
}
