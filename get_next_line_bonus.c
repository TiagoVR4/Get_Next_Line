/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:20 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/23 13:08:45 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && find_line(stash) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(stash), free(buffer), NULL);
		buffer[bytes_read] = '\0';
		new_stash = ft_strjoin(stash, buffer);
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
	line = (char *)ft_calloc(line_len + 2, sizeof(char));
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
	new_stash = ft_calloc(ft_strlen(stash) - i + 1, sizeof(char));
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
	static char	*stash[FD_SIZE];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FD_SIZE)
		return (NULL);
	if (!stash[fd])
		stash[fd] = (char *)ft_calloc(1, sizeof(char));
	stash[fd] = fill_stash(stash[fd], fd);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	if (!line)
		return (free(stash[fd]), NULL);
	return (line);
}
/* 
int	main()
{
	char	*line;
	const char	*filename[] = 
	{"file.txt", "file0.txt", "file1.txt", "file2.txt"};
	int	fd;
	int	i = 0;

	// fd = open(filename[1], O_RDONLY);
	// while ((line = get_next_line(fd)) != NULL)
	// 	{
	// 		printf ("%s", line);
	// 		free(line);
	// 	}
	// close (fd);
	while (i < 3)
	{
		fd = open(filename[i], O_RDONLY);
		while ((line = get_next_line(fd)) != NULL)
		{
			printf ("%s", line);
			free(line);
		}
		close (fd);
		i++; 
	}
	return (0);
} */
/* 
int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd < 0)
			{
				i++;
				printf("Error");
				continue ;
			}
			while ((line = get_next_line(fd)) != NULL)
			{
				printf("%s", line);
				free(line);
			}
			close(fd);
			i++;
		}
	}
	return (0);
} */