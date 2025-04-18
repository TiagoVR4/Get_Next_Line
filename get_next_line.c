/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:20 by tiagalex          #+#    #+#             */
/*   Updated: 2025/04/07 03:35:08 by tiagvr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (0);
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_stash(char *stash, int fd)
{
	ssize_t	bytes_read;
	char	*buffer;
	char	*new_stash;

	buffer = gnl_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && find_line(stash) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(stash), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		new_stash = gnl_strjoin(stash, buffer);
		if (!new_stash)
			return (free(stash), NULL);
		free(stash);
		stash = new_stash;
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char	*stash)
{
	int		i;
	int		line_len;
	char	*line;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	line_len = 0;
	if (!stash)
		return (NULL);
	while (stash[line_len] != '\n' && stash[line_len] != '\0')
		line_len++;
	line = (char *)gnl_calloc(line_len + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*update_stash(char *stash)
{
	char	*new_stash;
	int		i;
	int		new_i;

	i = 0;
	new_i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	new_stash = gnl_calloc(gnl_strlen(stash) - i + 1, sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	i++;
	while (stash[i] != '\0')
	{
		new_stash[new_i] = stash[i];
		i++;
		new_i++;
	}
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!stash)
		stash = (char *)gnl_calloc(1, sizeof(char));
	stash = fill_stash(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = update_stash(stash);
	if (!line)
		return (free(stash), NULL);
	return (line);
}
/* 
int	main()
{
	int	fd = open("file.txt", O_RDONLY);
	char	*line;
	
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf ("%s", line);
		free(line);
	}
	close (fd);
	return (0);
} */