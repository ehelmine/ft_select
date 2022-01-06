/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:14:11 by ehelmine          #+#    #+#             */
/*   Updated: 2021/11/13 16:12:29 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The stpncpy() and strncpy() functions copy at most len characters from
**   src into dst.  If src is less than len characters long, the remainder of
**   dst is filled with `\0' characters.  Otherwise, dst is not terminated.
**
**   The source and destination strings should not overlap, as the behavior is
**   undefined.
**
** RETURN VALUES
**   The strcpy() and strncpy() functions return dst.
*/

#include "includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	unsigned int	i;

	if (len == 0)
		return (dest);
	i = 0;
	while (i < len && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
