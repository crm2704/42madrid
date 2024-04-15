/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:43:15 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/05 22:43:17 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd != -1)
	{
		i = 0;
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}
/*
#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;

	fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	ft_putstr_fd("Hello, World!", fd);
	close(fd);
	return (0);
}
*/