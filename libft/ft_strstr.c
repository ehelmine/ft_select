/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 13:44:34 by ehelmine          #+#    #+#             */
/*   Updated: 2021/08/24 18:01:46 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The strstr() function locates the first occurrence of the null-terminated
**   string needle in the null-terminated string haystack.
**
** RETURN VALUES
**  If needle is an empty string, haystack is returned; if needle occurs
**   nowhere in haystack, NULL is returned; otherwise a pointer to the first
**   character of the first occurrence of needle is returned.
*/

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
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
				return ((char *)haystack + i);
		}
		i++;
		x = 0;
	}
	return (NULL);
}
