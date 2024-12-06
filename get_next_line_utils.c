/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:40:31 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/05 18:33:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Conta o tamanho da str.
size_t ft_strlen(const char *str)
{
	int	i;

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
	s3 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
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