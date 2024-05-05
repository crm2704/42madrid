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

static void	ft_freemem(char **buff)
{
	if (*buff != NULL)
	{
		free(*buff);
		*buff = NULL;
	}
}

static char	*ft_reuse(char **buff)
{
	if (*buff != NULL)
	{
		free(*buff);
		*buff = ft_strdup(""); // puede devolver null
	}
	return (*buff);
}

static char	*ft_check_newline(char **tmp, char **buff, char c)
{
	char	*res;
	size_t	i;
	char	*temp;

	i = 0;
	temp = ft_strjoin(*buff, *tmp); // puede devolver null
	while (i <= ft_strlen(temp))
	{
		if (temp[i] == c)
		{
			res = ft_substr(temp, 0, (size_t)i+1);            
				// puede devolver null  incluso si strlen(temp) > 0
			*buff = ft_substr(temp, i + 1, ft_strlen(temp));
				// puede devolver null  incluso si strlen(temp) > 0
			*tmp = ft_reuse(tmp);
			free(temp);
			if (c == '\0')
			{
				ft_freemem(buff);
				ft_freemem(tmp);
			}
			return (res);
		}
		i++;
	}
	if (c == '\n')
	{
		*buff = ft_strdup(temp); // puede devolver null
		*tmp = ft_reuse(tmp);
		free(temp);
	}
	return (NULL);
}

static char	*ft_search_newline(char *read_buffer, char **tmp, char **buff,
		int fd)
{
	char	*res;
	ssize_t	read_bytes;

	res = NULL;
	read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (res == NULL && read_bytes > 0)
	{
		read_buffer[read_bytes] = '\0';
		*tmp = ft_strjoin(*tmp, read_buffer); // puede devolver null
		if (*tmp == NULL)
		{
			ft_freemem(buff);
			ft_freemem(&read_buffer);
			return (NULL);
		}
		res = ft_check_newline(tmp, buff, '\n');
		if (res == NULL)
			read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	if (res != NULL)
		return (res);
	else if (read_bytes < 0 || (read_bytes == 0 && ft_strlen(*buff) == 0))
	{
		ft_freemem(tmp);
		ft_freemem(&read_buffer);
		ft_freemem(buff);
		return (NULL);
	}
	ft_freemem(&read_buffer);
	res = (ft_check_newline(tmp, buff, '\n'));
	if (res != NULL)
		return (res);
	return (ft_check_newline(tmp, buff, '\0'));
}

char	*get_next_line(int fd)
{
	static char	*buff[MAX_FD];
	char		*tmp;
	char		*read_buffer;
	char		*res;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (read_buffer == NULL)
		return (NULL);
	tmp = ft_strdup("");
	res = NULL;
	if (buff[fd] == NULL)
		buff[fd] = ft_strdup("");
	if (buff[fd] == NULL || tmp == NULL)
	{
		free(read_buffer);
		if (tmp != NULL)
			free(tmp);
		else
			free(buff[fd]);
		return (NULL);
	}
	res = ft_search_newline(read_buffer, &tmp, &buff[fd], fd);
	return (res);
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
	//printf("From %s: %s\n", filename, line);
	//free(line);
	close(fd);
	return (0);
}

/*
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

int main(void)
{
	char *line;

	while ((line = get_next_line(0)) != NULL) // 0 es el descriptor de archivo para stdin
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
*/