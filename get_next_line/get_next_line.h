/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:44:24 by crubio            #+#    #+#             */
/*   Updated: 2024/04/23 16:44:26 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 255
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(char const *s);
char	*ft_strdup(char const *s);
size_t	ft_strlcpy(char *dest, char const *src, size_t dstsize);

#endif
