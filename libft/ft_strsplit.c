/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 11:01:03 by ehelmine          #+#    #+#             */
/*   Updated: 2021/09/08 11:34:04 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including the array itself) obtained by
** spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL. Example:
** ft_strsplit("*hello*fellow***students*", ’*’)
** returns the array ["hello", "fellow", "students"].
*/

#include "includes/libft.h"

static char	**free_array(int x, char **array)
{
	int	i;

	i = 0;
	while (i < x)
		free(array[i++]);
	return (NULL);
}

static void	ft_addchar(int i, int w, char **same, const char *s)
{
	int	ii;
	int	y;
	int	x;

	ii = i - w;
	y = 0;
	x = 0;
	while (y < w)
	{
		same[x][y] = s[ii];
		y++;
		ii++;
	}
	same[x][y] = '\0';
	x++;
	return ;
}

static char	**ft_thersplit(int wrds, char c, char **same, const char *s)
{
	int	x;
	int	w;
	int	y;
	int	i;

	i = 0;
	x = 0;
	while (x < wrds)
	{
		w = 0;
		y = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			w++;
			i++;
		}
		same[x] = (char *)malloc(sizeof(char) * (w + 1));
		if (same == NULL)
			return (free_array(x, same));
		ft_addchar(i, w, &same[x], s);
		x++;
	}
	return (same);
}

static int	ft_counting_words(const char *s, char c)
{
	int	i;
	int	wrds;

	i = 0;
	wrds = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			wrds++;
		if (i > 0 && s[i] != c && s[i - 1] == c)
			wrds++;
		i++;
	}
	return (wrds);
}

char	**ft_strsplit(char const *s, char c)
{
	int		wrds;
	char	**same;

	wrds = ft_counting_words(s, c);
	same = (char **)malloc(sizeof(char *) * (wrds + 1));
	if (same == NULL)
		return (NULL);
	same = ft_thersplit(wrds, c, same, s);
	if (same == NULL)
		return (NULL);
	same[wrds] = NULL;
	return (same);
}
