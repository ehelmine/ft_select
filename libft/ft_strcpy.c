/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 16:42:06 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:17:52 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The stpcpy() and strcpy() functions copy the string src to dst (including
**   the terminating `\0' character.)
**
**   The source and destination strings should not overlap, as the behavior is
**   undefined.
**
** RETURN VALUES
**   The strcpy() and strncpy() functions return dst.
*/

#include "includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
