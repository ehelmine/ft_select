/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 12:35:40 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:17:52 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The strcat() and strncat() functions append a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then add a termi-
** nating `\0'.  The string s1 must have sufficient space to hold the
** result.
**
** The strncat() function appends not more than n characters from s2, and
** then adds a terminating `\0'.
**
** The source and destination strings should not overlap, as the behavior is
** undefined.
** RETURN VALUES
** The strcat() and strncat() functions return the pointer s1.
*/

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int				destlen;
	unsigned int	i;

	destlen = 0;
	while (dest[destlen] != '\0')
		destlen++;
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[destlen] = src[i];
		destlen++;
		i++;
	}
	dest[destlen] = '\0';
	return (dest);
}
