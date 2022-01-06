/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:28:05 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/30 14:29:50 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	free_arr(void ***arr)
{
	size_t	i;

	i = 0;
	if (*arr != NULL)
	{
		while ((*arr)[i] != NULL)
			ft_memdel((void **)&(*arr)[i++]);
		free(*arr);
	}
	*arr = NULL;
}
