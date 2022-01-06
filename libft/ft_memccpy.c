/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:12:55 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:15:55 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The memccpy() function copies bytes from string src to string dst.  If
**   the character c (as converted to an unsigned char) occurs in the string
**   src, the copy stops and a pointer to the byte after the copy of c in the
**   string dst is returned.  Otherwise, n bytes are copied, and a NULL
**   pointer is returned.
**
**   The source and destination strings should not overlap, as the behavior is
**   undefined.
*/

#include "includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*dsst;
	unsigned const char	*srrc;
	unsigned char		x;

	dsst = (unsigned char *)dst;
	srrc = (unsigned const char *)src;
	i = 0;
	x = c;
	while (i < n)
	{
		dsst[i] = srrc[i];
		if (dsst[i] == x)
			return ((unsigned char *)dst + i + 1);
		i++;
	}
	return (0);
}
