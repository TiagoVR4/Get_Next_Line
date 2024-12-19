/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:40:31 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/19 10:27:34 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//Conta o tamanho da str.
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

//Junta uma str com outra numa nova str.
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	s2_len = 0;
	s3 = ft_calloc(sizeof(char), ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!s3)
		return (NULL);
	while (s1[s1_len] != '\0')
	{
		s3[s1_len] = s1[s1_len];
		s1_len++;
	}
	while (s2[s2_len] != '\0')
	{
		s3[s1_len + s2_len] = s2[s2_len];
		s2_len++;
	}
	s3[s1_len + s2_len] = '\0';
	return (s3);
}

//aloca a memória para um array e inicializa todos os bytes por '\0'
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)malloc(count * size);
	i = 0;
	if (!temp)
		return (NULL);
	while (i < (count * size))
	{
		temp[i] = '\0';
		i++;
	}
	return ((void *)temp);
}
