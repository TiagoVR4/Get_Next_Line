/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:30:20 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/10 17:04:38 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_line(char *buffer)
{
	int	i;

	i = 0;
	buffer = malloc(sizeof(char) * (ft_strlen(buffer) + 1));
	if (!buffer)
		return (NULL);
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

	bytes_read = 1;
	while (ft_find_line(buffer) == 0 && bytes_read != 0)
	{
		temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!temp)
			return (NULL);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free (temp);
			free (buffer);
			return (NULL);
		}
		buffer = ft_strjoin (buffer, temp[BUFFER_SIZE]);

	}
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);

	//fill_line (buffer, fd);
	if(!buffer)
		return (NULL);

}

int	main()
{
	int	fd = open("arquivo.txt", O_RDONLY);

	//get_next_line(fd);
	
	close (fd);
	return (0);
}