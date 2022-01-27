/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:30:24 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/27 10:10:53 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

extern t_select *data_plus;

void	output_error(int i)
{
	if (i == 0)
	{
		write(STDOUT_FILENO, "The fd argument is not a valid file \
		descriptor or the file associated with fd is not a terminal.\n", 100);
	}
	else if (i == 1)
		write(STDOUT_FILENO, "Environment variable TERM was not found.\n", 41);
	else if (i == 2)
		write(STDOUT_FILENO, "Some difficulty accessing the data base.\n", 41);
	else if (i == 3)
		write(STDOUT_FILENO, "This terminal type is not defined.\n", 35);
	exit (1);
}
