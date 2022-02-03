/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:30:24 by ehelmine          #+#    #+#             */
/*   Updated: 2022/02/03 18:42:26 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

void	output_error(t_select *data, int i)
{
	stop_raw_mode(data->d_orig_t, data);
	if (i == 1)
		write(STDOUT_FILENO, "Environment variable TERM was not found.\n", 41);
	else if (i == 2)
		write(STDOUT_FILENO, "Some difficulty accessing the data base.\n", 41);
	else if (i == 3)
		write(STDOUT_FILENO, "This terminal type is not defined.\n", 35);
	exit (EXIT_FAILURE);
}
