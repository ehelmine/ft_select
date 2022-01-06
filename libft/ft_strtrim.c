/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 09:46:34 by ehelmine          #+#    #+#             */
/*   Updated: 2021/07/14 16:05:54 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string. Will be considered as whitespaces the
** following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces at the
** beginning or at the end, the function returns a copy of s.
** If the allocation fails the function returns NULL.
*/

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		z;
	int		y;
	int		i;
	char	*cpy;

	i = 0;
	z = ft_strlen(s);
	if (z == 0)
		return (ft_strnew(0));
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[z - 1] == ' ' || s[z - 1] == '\n' || s[z - 1] == '\t') && i != z)
		z--;
	cpy = (char *)malloc(sizeof(char) * (z - i + 1));
	if (cpy == NULL)
		return (NULL);
	y = 0;
	while (i < z && z > 0)
		cpy[y++] = s[i++];
	cpy[y] = '\0';
	return (cpy);
}
