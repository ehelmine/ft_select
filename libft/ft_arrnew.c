/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:13:22 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/14 15:27:35 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Allocate new char array. Use given rows as the number of rows to allocate
** the space for rows, and use given first_row_len to allocate the space
** for first row. Return array.
*/

char	**ft_arrnew(size_t rows, size_t first_row_len)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * (rows + 1));
	if (array == NULL)
		exit (1);
	array[0] = (char *)malloc(sizeof(char) * (first_row_len + 1));
	if (array[0] == NULL)
		exit(1);
	return (array);
}
