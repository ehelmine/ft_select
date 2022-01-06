/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:24:48 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:17:52 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The strlcpy() and strlcat() functions copy and concatenate strings with
**   the same input parameters and output result as snprintf(3).  They are
**   designed to be safer, more consistent, and less error prone replacements
**   for the easily misused functions strncpy(3) and strncat(3).
**
**   strlcpy() and strlcat() take the full size of the destination buffer and
**   guarantee NUL-termination if there is room.  Note that room for the NUL
**   should be included in dstsize.
**
**   strlcat() appends string src to the end of dst.  It will append at most
**   dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
**   dstsize is 0 or the original dst string was longer than dstsize (in prac-
**   tice this should not happen as it means that either dstsize is incorrect
**   or that dst is not a proper string).
**
**   If the src and dst strings overlap, the behavior is undefined.
**
** RETURN VALUES
**   Like snprintf(3), the strlcpy() and strlcat() functions return the total
**   length of the string they tried to create.  For strlcpy() that means the
**   length of src.  For strlcat() that means the initial length of dst plus
**   the length of src.
**
**   If the return value is >= dstsize, the output string has been truncated.
**     It is the caller's responsibility to handle this.
*/

#include "includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	srclen;
	size_t	destlen;
	size_t	res;
	size_t	i;

	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	res = 0;
	if (n <= destlen)
		res = srclen + n;
	else
		res = srclen + destlen;
	i = 0;
	while (src[i] != '\0' && destlen + 1 < n)
	{
		dest[destlen] = src[i];
		i++;
		destlen++;
	}
	dest[destlen] = '\0';
	return (res);
}
