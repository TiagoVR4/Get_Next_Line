/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagalex <tiagalex@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:32:40 by tiagalex          #+#    #+#             */
/*   Updated: 2024/12/10 16:53:26 by tiagalex         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1322
#endif

char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);


#endif