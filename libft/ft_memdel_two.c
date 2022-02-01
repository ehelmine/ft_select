/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 14:55:21 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/01 14:55:22 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_memdel_two(void **ptr1, void **ptr2)
{
	if (*ptr1 != NULL)
	{
		free(*ptr1);
		*ptr1 = NULL;
	}
	if (*ptr2 != NULL)
	{
		free(*ptr2);
		*ptr2 = NULL;
	}
}
