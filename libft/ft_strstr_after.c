/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 17:24:24 by ehelmine          #+#    #+#             */
/*   Updated: 2021/08/30 21:40:36 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr_after(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (haystack[i + x] == needle[x])
		{
			x++;
			if (x == ft_strlen(needle))
				return ((char *)haystack + i + x);
		}
		i++;
		x = 0;
	}
	return (NULL);
}
