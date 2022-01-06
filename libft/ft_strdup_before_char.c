/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_before_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:13:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/11/12 13:10:21 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*return_string_before_given_char(char *str, char c)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	if (c == '\0')
		return (ft_strdup(str));
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (ft_strndup(str, i));
		i++;
	}
	return (NULL);
}
