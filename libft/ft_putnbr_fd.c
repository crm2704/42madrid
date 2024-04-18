/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 22:00:00 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/06 22:00:02 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	aux(int n, int fd)
{
	char	w;

	if (n / 10 == 0)
	{
		w = n + '0';
		write(fd, &w, 1);
	}
	else
	{
		aux(n / 10, fd);
		w = (n % 10) + '0';
		write(fd, &w, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		aux(n, fd);
	}
}

/*
#include "libft.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	// Test case 1: Positive number
	ft_putnbr_fd(123456789, fd);
	write(fd, "\n", 1);
	// Test case 2: Negative number
	ft_putnbr_fd(-123456789, fd);
	write(fd, "\n", 1);
	// Test case 3: Zero
	ft_putnbr_fd(0, fd);
	write(fd, "\n", 1);
	// Test case 4: Maximum int value
	ft_putnbr_fd(2147483647, fd);
	write(fd, "\n", 1);
	// Test case 5: Minimum int value
	ft_putnbr_fd(-2147483648, fd);
	write(fd, "\n", 1);
	close(fd);
	return (0);
}
*/