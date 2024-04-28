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

char	*get_next_line(int fd)
{
	
}
/*
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*str;
	int		i;
	char	*line;

	srand(time(NULL));  // Seed the random number generator
	str = malloc(2001); // 2000 characters + '\0'
	if (str == NULL)
	{
		return (1);
	}
	for (i = 0; i < 1999; i++) // Only fill up to index 1999
	{
		if (rand() % 100 < 5) // Approximately 5% chance
		{
			str[i] = '\n'; // Add a newline character
		}
		else
		{
			str[i] = 'a'; // Fill the string with 'a'
		}
	}
	str[1999] = 'a';  // Ensure the last character is 'a'
	str[2000] = '\0'; // Null-terminate the string
	fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		free(str);
		return (1);
	}
	write(fd, str, 2000); // Write the string to the file
	close(fd);
	free(str);
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/