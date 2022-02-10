/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 13:17:33 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/10 12:57:44 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Allocates (with malloc(3)) and returns a “fresh” string ending
**  with ’\0’, result of the concatenation of s1 and s2. If
** the allocation fails the function returns NULL.
** Param. #1 The prefix string.
** Param. #2 The suffix string.
** Return value The “fresh” string result of the concatenation of the 2 strings.
*/

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*nwstr;
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	ii;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	nwstr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (nwstr == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (s1[i] != '\0')
	{
		nwstr[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2[ii] != '\0')
		nwstr[i++] = s2[ii++];
	nwstr[i] = '\0';
	return (nwstr);
}
