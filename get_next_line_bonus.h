/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiagvr <tiagvr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:32:40 by tiagalex          #+#    #+#             */
/*   Updated: 2025/04/07 03:35:08 by tiagvr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_SIZE
#  define FD_SIZE 65534
# endif

char	*gnl_strjoin(const char *s1, const char *s2);
char	*get_next_line(int fd);

size_t	gnl_strlen(const char *str);

void	*gnl_calloc(size_t count, size_t size);

#endif