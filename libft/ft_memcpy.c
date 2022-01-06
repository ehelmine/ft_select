/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 12:20:09 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:16:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The memcpy() function copies n bytes from memory area src to memory area
**   dst.  If dst and src overlap, behavior is undefined.  Applications in
**   which dst and src might overlap should use memmove(3) instead.
**
** RETURN VALUES
**   The memcpy() function returns the original value of dst.
*/

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int		i;
	unsigned char		*dsst;
	unsigned const char	*srrc;

	dsst = (unsigned char *)dst;
	srrc = (unsigned const char *)src;
	i = 0;
	if (dst || src)
	{
		while (i < n)
		{
			dsst[i] = srrc[i];
			i++;
		}
	}
	return (dst);
}
