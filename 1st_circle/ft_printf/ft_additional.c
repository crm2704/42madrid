/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:42:40 by crubio            #+#    #+#             */
/*   Updated: 2024/04/18 17:42:41 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (fd != -1)
		return (write(fd, &c, 1));
	else
		return (0);
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		s = "(null)";
	if (fd != -1)
	{
		while (s[i])
		{
			if (write(fd, &s[i], 1) == -1)
				return (-1);
			i++;
		}
	}
	return (i);
}

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int	aux_add(int n, int fd, int cont)
{
	char	w;

	if (n / 10 == 0)
	{
		w = n + '0';
		ft_putchar_fd(w, 1);
		return (cont + 1);
	}
	else
	{
		cont = aux_add(n / 10, fd, cont + 1);
		w = (n % 10) + '0';
		ft_putchar_fd(w, 1);
		return (cont);
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	int	cont;

	cont = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		cont = 11;
	}
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
			cont++;
		}
		cont += aux_add(n, fd, 0);
	}
	return (cont);
}
