/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:20 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/17 19:01:05 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	find_line(char *buffer)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*fill_line(char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*new_buffer;

	bytes_read = 1;
	if (!buffer)
		buffer = (char *)ft_calloc(1, sizeof(char));
	while (find_line(buffer) == 0 && bytes_read != 0)
	{
		temp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (free(buffer), free(temp), NULL);
		new_buffer = ft_strjoin(buffer, temp);
		free(temp);
		if (!new_buffer)
			return (free(buffer), NULL);
		free (buffer);
		buffer = new_buffer;
	}
	return (buffer);
}

static char	*extract_line(char	*buffer)
{
	int		i;
	int		line_len;
	char	*line;

	i = 0;
	line_len = 0;
	if (!buffer)
		return (NULL);
	while (buffer[line_len] != '\n' && buffer[line_len] != '\0')
		line_len++;
	line = (char *)ft_calloc(line_len + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer)
{
	char	*new_buffer;
	int		i;
	int		new_i;

	i = 0;
	new_i = 0;
	if (!buffer) //impede erros caso o buffer esteja NULL
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	new_buffer = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char)); // + 1 porque nao estavamos a pensar no '\0'
	if (!new_buffer)
		return (free(buffer), NULL); //esquecemo-nos de livertar ao buffer;
	i++;
	while (buffer[i] != '\0')
	{
		new_buffer[new_i] = buffer[i];
		i++;
		new_i++;
	}
	new_buffer[new_i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = fill_line(buffer, fd);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	if (!line)
		return (free(buffer), NULL);
	buffer = update_buffer(buffer);
	return (line);
}

int	main()
{
	int	fd = open("arquivo.txt", O_RDONLY);
	char	*line;
	
	
	while ((line = get_next_line(fd)) != NULL)
	{
		printf ("%s", line);
		free(line);
	}
	close (fd);
	return (0);
}