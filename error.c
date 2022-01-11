/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:30:24 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/11 10:34:06 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"

int	output_error(int i)
{
	if (i == 0)
	{
		write(1, "The fd argument is not a valid file descriptor or \
			the file associated with fd is not a terminal.\n", 100);
	}
	else if (i == 1)
		write(1, "Environment variable TERM was not found.\n", 41);
	else if (i == 2)
		write(1, "Some difficulty accessing the data base.\n", 41);
	else if (i == 3)
		write(1, "This terminal type is not defined.\n", 35);
	return (-1);
}