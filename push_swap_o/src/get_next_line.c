/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarrah <mbarrah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:36:04 by mbarrah           #+#    #+#             */
/*   Updated: 2024/11/23 10:58:16 by mbarrah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**get_splits_line(char *cursor)
{
	ssize_t	index;
	char	**split_lines;

	index = check_cursor(cursor);
	if (index == -1)
		return (NULL);
	split_lines = malloc(2 * sizeof(char *));
	if (!split_lines)
		return (NULL);
	split_lines[0] = ft_strndup(cursor, index + 1);
	if (!split_lines[0])
	{
		free(split_lines);
		return (NULL);
	}
	split_lines[1] = ft_strndup(cursor + index + 1, ft_strlen(cursor + index
				+ 1));
	if (!split_lines[1])
	{
		free(split_lines[0]);
		free(split_lines);
		return (NULL);
	}
	return (split_lines);
}

static char	*read_from_file(int fd)
{
	char	*buffer;
	ssize_t	read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[read_bytes] = '\0';
	return (buffer);
}

static char	*ft_str_join(char *cursor, char *buffer)
{
	int		cursor_len;
	int		buffer_len;
	char	*res;

	if (cursor)
		cursor_len = ft_strlen(cursor);
	else
		cursor_len = 0;
	buffer_len = ft_strlen(buffer);
	res = malloc(cursor_len + buffer_len + 1);
	if (!res)
	{
		free(cursor);
		return (NULL);
	}
	if (cursor)
	{
		ft_strncpy(res, cursor, cursor_len);
		free(cursor);
	}
	if (cursor_len > 0)
		res[cursor_len] = '\0';
	ft_strncpy(res + cursor_len, buffer, buffer_len);
	res[cursor_len + buffer_len] = '\0';
	return (res);
}

static char	*get_line_update_cursor(char **split_lines, char **cursor)
{
	char	*line;

	if (split_lines)
	{
		line = split_lines[0];
		free(*cursor);
		*cursor = split_lines[1];
		free(split_lines);
	}
	else
	{
		if (*cursor && **cursor)
			line = ft_strndup(*cursor, ft_strlen(*cursor));
		else
			line = NULL;
		free(*cursor);
		*cursor = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*cursor;
	char		*buffer;
	char		**split_lines;

	while (1)
	{
		split_lines = get_splits_line(cursor);
		if (split_lines)
		{
			return (get_line_update_cursor(split_lines, &cursor));
		}
		buffer = read_from_file(fd);
		if (!buffer)
		{
			return (get_line_update_cursor(NULL, &cursor));
		}
		cursor = ft_str_join(cursor, buffer);
		free(buffer);
		if (!cursor)
			return (NULL);
	}
}
