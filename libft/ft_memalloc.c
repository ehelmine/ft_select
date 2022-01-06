/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 12:17:00 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:15:51 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype void * ft_memalloc(size_t size);
** Description Allocates (with malloc(3)) and returns a “fresh” memory area.
** The memory allocated is initialized to 0.
** If the allocation fails, the function returns NULL.
** Param. #1 The size of the memory that needs to be allocated.
*/
#include "includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	str = (void *)malloc(sizeof(str) * size);
	if (str != NULL)
	{
		ft_bzero(str, size);
		return (str);
	}
	return (NULL);
}
