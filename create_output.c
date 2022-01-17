/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:56:01 by ehelmine          #+#    #+#             */
/*   Updated: 2022/01/17 20:50:50 by ehelmine         ###   ########.fr       */
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

static void	fill_with_options(char *output, char input[1024][1024], int amount_of_input,
		int cols)
{
	int	x;
	int	i;
	int	ii;
	int	times;

	x = 0;
	times = 1;
	i = 0;
	while (i < amount_of_input)
	{
		output[x++] = '[';
		x++;
		output[x++] = ']';
		x++;
		ii = 0;
		while (input[i][ii] != '\0')
			output[x++] = input[i][ii++];
		x = cols * times++;
		i++;
	}
}

static void	fill_with_spaces_and_newlines(char *output, int total, int cols, int x)
{
	int	i;
	
	while (x <= total)
	{
		i = 0;
		while (i < cols - 2 && x <= total)
		{
			output[x++] = ' ';
			i++;
		}
		output[x - 1] = '%';
	//	ft_printf("x now: %i\r\n", x - 1);
		if (x + 2 < total)
		{
			output[x++] = '\r';
			output[x++] = '\n';
		}
		else
			break ;
	}
	output[x] = '\0';
}

void	create_output_str(t_select *data)
{
	int	total;
	
	total = data->window_rows * data->window_columns;
//	ft_printf("c %i r %i\r\n", data->window_columns, data->window_rows);
	data->output = (char *)ft_memalloc(total + 1);
	if (data->output == NULL)
		return ;
	fill_with_spaces_and_newlines(data->output, total, data->window_columns, 0);
	fill_with_options(data->output, data->input, data->amount_of_input, data->window_columns);
}