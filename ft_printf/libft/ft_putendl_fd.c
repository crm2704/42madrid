/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 21:47:29 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/06 21:47:31 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
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
	ft_putendl_fd("Hello, World!", fd);
	close(fd);
	return (0);
}
*/