/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:23:20 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/30 14:14:19 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	free_two(void **ptr1, void **ptr2)
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
