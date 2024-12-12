/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:20 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/12 13:37:20 by tiagalex         ###   ########.fr       */
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

static char	*extract_line(char	*buffer)
{
	size_t	i;
	size_t	r_buffer_len;
	char *	r_buffer;
	
	i = 0;
	r_buffer_len = 0;
	if (!buffer)
		return (NULL);
	while (buffer[r_buffer_len] != '\n' && buffer[r_buffer_len] != '\0')
		r_buffer_len++;
	r_buffer = (char *)ft_calloc(r_buffer_len + 2, sizeof(char));
	if (!r_buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		r_buffer[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		r_buffer[i] = '\n';
		i++;
	}
	r_buffer[i] = '\0';
	return (r_buffer);
}

static char	*fill_line(char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*temp;
	char	*new_buffer;

	bytes_read = 1;
	while (find_line(buffer) == 0 && bytes_read != 0)
	{
		temp = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(temp), NULL);
		new_buffer = ft_strjoin(buffer, temp);
		if (!new_buffer)
			return (free(temp), NULL);
		free (buffer);
		buffer = new_buffer;
	}
	if (find_line(buffer) == 1)
		extract_line(buffer);
	return (free(temp), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = ft_calloc(sizeof(char), (ft_strlen(buffer) + 1));
	buffer = fill_line(buffer, fd);
	if(!buffer)
		return (NULL);
	return (buffer);

}

int	main()
{
	int	fd = open("arquivo.txt", O_RDONLY);

	//get_next_line(fd);
	
	close (fd);
	return (0);
}