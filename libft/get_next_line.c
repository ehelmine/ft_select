/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:56:07 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/20 13:36:12 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	check_line_break(char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			break ;
		i++;
	}
	return (i);
}

static char	*ft_there_is_newline(char **line, char *end, size_t lb, char *temp)
{
	if (lb != 0)
	{
		*line = ft_strndup(end, lb);
		if (lb != ft_strlen(end) - 1)
		{
			temp = ft_strdup(end + lb + 1);
			free(end);
			end = temp;
		}
	}
	else
	{
		*line = ft_strnew(0);
		if (end[lb + 1] != '\0')
		{
			temp = ft_strdup(end + 1);
			free(end);
			end = temp;
		}
	}
	if (end != temp)
		ft_strdel(&end);
	return (end);
}

static char	*ft_check_newline(char **line, char *end)
{
	size_t	lb;
	char	*temp;

	temp = NULL;
	if (ft_strchr(end, '\n') == NULL)
	{
		if (ft_strlen(end) == 0)
			*line = ft_strnew(0);
		else
			*line = ft_strdup(end);
		ft_strdel(&end);
	}
	else
	{
		lb = check_line_break(end);
		end = ft_there_is_newline(line, end, lb, temp);
	}
	return (end);
}

int	call_check_newline(const int fd, char **line, char **end)
{
	while (end[fd] != NULL)
	{
		end[fd] = ft_check_newline(line, end[fd]);
		return (1);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	static char	*end[MAX_FD];
	char		*temp;
	int			x;

	x = read(fd, buf, BUFF_SIZE);
	while (x > 0 && line != NULL && fd > -1)
	{
		buf[x] = '\0';
		if (end[fd] != NULL)
		{
			temp = ft_strjoin(end[fd], buf);
			free(end[fd]);
			end[fd] = temp;
		}
		else
			end[fd] = ft_strdup(buf);
		x = read(fd, buf, BUFF_SIZE);
	}
	if (x == -1 || line == NULL || fd < 0 || fd >= MAX_FD)
		return (-1);
	return (call_check_newline(fd, line, end));
}
