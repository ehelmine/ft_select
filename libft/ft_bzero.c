/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 11:05:35 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:17:52 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** The bzero() function writes n zeroed bytes to the string s. If n is
** zero, bzero() does nothing.
*/

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*temp;
	unsigned int	i;

	i = 0;
	temp = s;
	if (n == 0)
		return ;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
