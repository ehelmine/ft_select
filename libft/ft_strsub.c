/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 09:42:02 by ehelmine          #+#    #+#             */
/*   Updated: 2021/07/02 15:58:47 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a “fresh” substring
** from the string given as argument. The substring begins at
** indexstart and is of size len. If start and len aren’t refering to a valid
** substring, the behavior is undefined. If the allocation fails,
** the function returns NULL.
*/

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*nwstr;
	unsigned int	i;

	nwstr = (char *)malloc(sizeof(char) * (len + 1));
	if (nwstr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		nwstr[i] = s[start];
		i++;
		start++;
	}
	nwstr[i] = '\0';
	return (nwstr);
}
