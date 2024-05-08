/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:44:04 by crubio            #+#    #+#             */
/*   Updated: 2024/05/01 19:57:11 by crubio           ###   ########.fr       */
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

static char	*ft_check_newline(char **buff, char c)
{
	char	*res;
	size_t	i;
	char	*tmp;

	tmp = ft_strdup(*buff);
	res = NULL;
	i = 0;
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

static char	*ft_search_newline(char *read_buffer, char **buff, int fd)
{
	char	*res;
	ssize_t	read_bytes;

	read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	res = NULL;
	while (read_bytes > 0 && res == NULL)
	{
		read_buffer[read_bytes] = '\0';
		*buff = ft_strjoin(*buff, read_buffer);
		res = ft_check_newline(buff, '\n');
		if (res == NULL)
		{
			if (*buff == NULL)
				return (NULL);
			read_bytes = read(fd, read_buffer, BUFFER_SIZE);
		}
	}
	if (read_bytes < 0)
		return (NULL);
	else if (read_bytes == 0)
	{
		if (ft_strlen(*buff) > 0)
		{
			res = ft_check_newline(buff, '\n');
			if (res == NULL)
				res = ft_check_newline(buff, '\0');
		}
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		read_buffer[BUFFER_SIZE];
	char		*res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (buff[fd] == NULL)
		buff[fd] = ft_strdup("");
	if (buff[fd] == NULL)
		return (NULL);
	res = ft_search_newline(read_buffer, &buff[fd], fd);
	if (res == NULL)
		buff[fd] = ft_freemem(&buff[fd]);
	return (res);
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	*filename;

	filename = "file2.txt";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file: %s\n", filename);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("From %s: %s\n", filename, line);
	close(fd);
	return (0);
}

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	char	*filename;

	filename = "file1.txt";
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open file: %s\n", filename);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("From %s: %s\n", filename, line);
	close(fd);
	return (0);
}


#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_FILES 3

int	main(void)
{
	int		fd;
	int		i;
	char	*line;
	char	*filenames[NUM_FILES] = {"file1.txt", "file2.txt", "file3.txt"};

	for (i = 0; i < NUM_FILES; i++)
	{
		fd = open(filenames[i], O_RDONLY);
		if (fd == -1)
		{
			printf("Failed to open file: %s\n", filenames[i]);
			return (1);
		}
		while ((line = get_next_line(fd)) != NULL)
		{
			printf("From %s: %s\n", filenames[i], line);
			free(line);
		}
		close(fd);
	}
	return (0);
}


#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*line;

	while ((line = get_next_line(0)) != NULL)
		// 0 es el descriptor de archivo para stdin
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
*/