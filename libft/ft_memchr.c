/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:57:18 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:16:03 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**    The memchr() function locates the first occurrence of c (converted to an
**   unsigned char) in string s.
**
** RETURN VALUES
**   The memchr() function returns a pointer to the byte located, or NULL if
**   no such byte exists within n bytes.
*/

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tem;
	unsigned char	y;

	tem = (unsigned char *)s;
	y = c;
	i = 0;
	while (i < n)
	{
		if (tem[i] == y)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}
