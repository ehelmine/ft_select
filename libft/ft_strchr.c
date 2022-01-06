/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 14:54:41 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:17:19 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The strchr() function locates the first occurrence of c (converted to a
**   char) in the string pointed to by s.  The terminating null character is
**   considered to be part of the string; therefore if c is `\0', the func-
**   tions locate the terminating `\0'.
**
**   The strrchr() function is identical to strchr(), except it locates the
**   last occurrence of c.
**
** RETURN VALUES
**  The functions strchr() and strrchr() return a pointer to the located
**  character, or NULL if the character does not appear in the string.
*/

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	y;

	y = c;
	i = 0;
	if (s[i] == y)
		return ((char *)s);
	while (s[i] != '\0')
	{
		if (s[i] == y)
		{
			return ((char *)s + i);
		}
		else
			i++;
	}
	if (s[i] == y)
		return ((char *)s + i);
	return (NULL);
}
