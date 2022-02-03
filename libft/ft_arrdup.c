/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:02:36 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/03 18:28:33 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** Takes in array, which has been allocated before.
** Count length of array, allocate sufficient space for it,
** make duplicate of every line to the new allocated array with
** ft_strdup -function and at the same time delete memory of the 
** old array line by line. In the end free old array and return the new
** allocated array.
*/

char	**ft_arrdup(char **arr)
{
	int		rows;
	int		i;
	char	**copy_of_arr;

	rows = 0;
	while (arr[rows] != NULL)
		rows++;
	copy_of_arr = (char **)malloc(sizeof(char *) * (rows + 1));
	if (copy_of_arr == NULL)
		exit (EXIT_FAILURE);
	i = 0;
	while (arr[i] != NULL)
	{
		copy_of_arr[i] = ft_strdup(arr[i]);
		if (copy_of_arr[i] == NULL)
			exit (EXIT_FAILURE);
		ft_memdel((void *)&arr[i++]);
	}
	free(arr);
	copy_of_arr[i] = NULL;
	return (copy_of_arr);
}
