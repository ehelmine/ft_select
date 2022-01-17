/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:56:01 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/17 12:45:10 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_select.h"
/*
void	append_to_str(t_select *data, char *new)
{
	char *tmp;

	tmp = ft_strdup(data->output);
	free(data->output);
	data->output = ft_strjoin(tmp, new);
	free(tmp);
	tmp = NULL;
}
*/
void	create_output_str(t_select *data)
{
	int		i;
	int		total;
	int		x;
	char	c;

	i = 0;
	x = 0;
	total = data->window_rows * data->window_columns;
	data->output = (char *)malloc(sizeof(char) * (total + 1));
	c = '~';
	if (data->output)
	{
		while (x < total)
		{
			i = 0;
			while (i < data->window_columns - 2)
			{
				data->output[x++] = c;
				i++;
			}
			if (x + 2 < total)
			{
				data->output[x++] = '\r';
				data->output[x++] = '\n';
			}
			else
				break ;
			if (c == '~')
				c = '?';
			else if (c == '?')
				c = '~';
		}
		data->output[x] = '\0';
	}
}