/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:44:04 by crubio            #+#    #+#             */
/*   Updated: 2024/04/23 16:44:06 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_freemem(char **buff)
{
	if (*buff != NULL)
	{
		free(*buff);
		*buff = NULL;
	}
	return (NULL);
}

static char	*ft_check_newline(char **buff, char c, char *res, size_t i)
{
	char	*tmp;

	tmp = ft_strdup(*buff);
	while (i <= ft_strlen(tmp))
	{
		if (tmp[i] == c)
		{
			res = ft_substr(tmp, 0, i + 1);
			*buff = ft_freemem(buff);
			if (c == '\n')
				*buff = ft_substr(tmp, i + 1, ft_strlen(tmp) - i + 1);
			tmp = ft_freemem(&tmp);
			if (res == NULL || *buff == NULL)
			{
				res = ft_freemem(&res);
				*buff = ft_freemem(buff);
				return (NULL);
			}
			return (res);
		}
		i++;
	}
	tmp = ft_freemem(&tmp);
	return (res);
}

static char	*ft_search_newline(char *read_buffer, char **buff, int fd,
		char *res)
{
	ssize_t	read_bytes;

	read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (read_bytes > 0 && res == NULL)
	{
		read_buffer[read_bytes] = '\0';
		*buff = ft_strjoin(*buff, read_buffer);
		res = ft_check_newline(buff, '\n', NULL, 0);
		if (res == NULL)
		{
			if (*buff == NULL)
				return (NULL);
			read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		}
	}
	if (read_bytes < 0)
		return (ft_freemem(buff));
	else if (read_bytes == 0 && ft_strlen(*buff) > 0)
	{
		res = ft_check_newline(buff, '\n', NULL, 0);
		if (res == NULL)
			res = ft_check_newline(buff, '\0', NULL, 0);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		read_buffer[BUFFER_SIZE + 1];
	char		*res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (buff[fd] == NULL)
		buff[fd] = ft_strdup("");
	if (buff[fd] == NULL)
		return (NULL);
	res = ft_search_newline(read_buffer, &buff[fd], fd, NULL);
	if (res == NULL)
		buff[fd] = ft_freemem(&buff[fd]);
	return (res);
}
/*
#include "get_next_line.h"
#include <fcntl.h> // Para la función open y la constante O_RDONLY
#include <stdio.h> // Para la función printf
#include <unistd.h> // Para la función close

void	read_file(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening file: %s\n", filename);
		return ;
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	printf("Reading test.txt\n");
	read_file("test.txt");
	printf("\nReading no_newlines.txt\n");
	read_file("no_newlines.txt");
	printf("\nReading only_newline.txt\n");
	read_file("only_newline.txt");
	printf("\nReading prueba\n");
	read_file("prueba");
	return (0);
}
 */