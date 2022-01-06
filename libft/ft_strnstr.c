/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 16:20:34 by ehelmine          #+#    #+#             */
/*   Updated: 2021/07/02 15:55:11 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	if (ft_strlen(needle) == 0)
	{
		return ((char *)haystack);
	}
	while (i < len && haystack[i] != '\0')
	{
		while (haystack[i + x] == needle[x])
		{
			x++;
			if (i + x > len)
				return (NULL);
			if (x == ft_strlen(needle))
				return ((char *)haystack + i);
		}
		i++;
		x = 0;
	}
	return (NULL);
}
