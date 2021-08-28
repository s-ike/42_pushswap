/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikeda <sikeda@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 22:25:28 by sikeda            #+#    #+#             */
/*   Updated: 2021/08/27 02:59:49 by sikeda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void
	safe_free(char **ptr)
{
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

static void
	w_safe_free(char **ptr1, char **ptr2)
{
	safe_free(ptr1);
	safe_free(ptr2);
}

static void
	read_fd(int fd, char **buff, char **str, char **find)
{
	char	*tmp;
	ssize_t	read_count;

	while (1)
	{
		read_count = read(fd, *buff, BUFFER_SIZE);
		if (read_count < 0)
			break ;
		(*buff)[read_count] = '\0';
		if (*str == NULL)
			*str = ft_strdup(*buff);
		else
		{
			tmp = *str;
			*str = ft_strjoin(*str, *buff);
			safe_free(&tmp);
		}
		*find = ft_strchr(*str, '\n');
		if (*find || !read_count || !*str)
			break ;
	}
}

static int
	make_line(char **str, char *find, char **line)
{
	char	*tmp;
	int		result;

	result = GNL_EXIST;
	if (find)
	{
		tmp = *str;
		*line = ft_substr(*str, 0, find - *str);
		*str = ft_strdup(find + 1);
		if (!(*str))
			result = GNL_ERROR;
		safe_free(&tmp);
	}
	else
	{
		*line = ft_strdup(*str);
		safe_free(str);
		result = GNL_EOF;
	}
	if (!*line || result == GNL_ERROR)
	{
		w_safe_free(line, str);
		result = GNL_ERROR;
	}
	return (result);
}

int
	get_next_line(int fd, char **line)
{
	static char	*strs[MAX_FD];
	char		*buff;
	char		*find;

	if (line)
		*line = NULL;
	if (BUFFER_SIZE <= 0 || SIZE_MAX == BUFFER_SIZE || fd < 0 || MAX_FD <= fd)
		return (GNL_ERROR);
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!line || !buff || read(fd, buff, 0) < 0)
	{
		safe_free(&strs[fd]);
		safe_free(&buff);
		return (GNL_ERROR);
	}
	find = NULL;
	if (strs[fd])
		find = ft_strchr(strs[fd], '\n');
	if (!find)
		read_fd(fd, &buff, &strs[fd], &find);
	safe_free(&buff);
	if (!strs[fd])
		return (GNL_ERROR);
	return (make_line(&strs[fd], find, line));
}
