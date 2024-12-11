/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:20 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/11 18:22:39 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_line(char *buffer)
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

char	*fill_line(char *buffer, int fd)
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
			return (free(new_buffer), free(temp), NULL);
		free (buffer);
		buffer = new_buffer;
	}
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