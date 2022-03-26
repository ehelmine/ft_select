/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 14:22:17 by ehelmine          #+#    #+#             */
/*   Updated: 2022/03/24 11:22:33 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The strchr() function locates the first occurrence of c (converted to a
**   char) in the string pointed to by s.  The terminating null character is
**  considered to be part of the string; therefore if c is `\0', the func-
**   tions locate the terminating `\0'.
**
**   The strrchr() function is identical to strchr(), except it locates the
**   last occurrence of c.
**
** RETURN VALUES
**   The functions strchr() and strrchr() return a pointer to the located
**  character, or NULL if the character does not appear in the string.
*/

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		x;
	char	y;

	x = ft_strlen(s);
	y = c;
	while (x > 0)
	{
		if (s[x] == y)
			return ((char *)s + x);
		x--;
	}
	if (s[x] == y)
		return ((char *)s);
	return (NULL);
}
