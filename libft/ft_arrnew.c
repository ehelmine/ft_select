/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 12:13:22 by ehelmine          #+#    #+#             */
/*   Updated: 2021/08/30 21:39:44 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

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
