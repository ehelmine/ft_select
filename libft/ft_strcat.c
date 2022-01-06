/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 11:34:55 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:17:13 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int	ed;
	int	len;
	int	i;

	len = 0;
	while (src[len] != '\0')
		len++;
	ed = 0;
	while (dest[ed] != '\0')
		ed++;
	i = 0;
	while (i < len)
	{
		dest[ed] = src[i];
		ed++;
		i++;
	}
	dest[ed] = '\0';
	return (dest);
}
