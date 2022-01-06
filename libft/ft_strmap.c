/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 09:14:37 by ehelmine          #+#    #+#             */
/*   Updated: 2021/07/14 16:06:40 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Description Applies the function f to each character of the string given
** as argument to create a “fresh” new string (with malloc(3))
** resulting from the successive applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s.
** Return value The “fresh” string created from the successive applications of
** f.
*/

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*nwstr;
	char	*ss;

	ss = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ss == NULL)
		return (NULL);
	ss = ft_strcpy(ss, s);
	i = 0;
	while (ss[i] != '\0')
	{
		ss[i] = f(ss[i]);
		i++;
	}
	nwstr = (char *)malloc(sizeof(char) * (i + 1));
	if (nwstr == NULL)
		return (NULL);
	ft_strcpy(nwstr, ss);
	return (nwstr);
}
