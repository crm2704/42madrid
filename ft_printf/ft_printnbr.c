/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:54:51 by crubio            #+#    #+#             */
/*   Updated: 2024/04/14 19:55:04 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(va_list args)
{
	int	n;

	n = (int)va_arg(args, int);
	return (ft_putnbr_fd(n, 1));
}

static int	aux(unsigned int n, int fd, int cont)
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
		cont = aux(n / 10, fd, cont + 1);
		w = (n % 10) + '0';
		ft_putchar_fd(w, 1);
		return (cont);
	}
}

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int	cont;

	cont = aux(n, 1, 0);
	return (cont);
}

int	ft_putunsigned(va_list args)
{
	unsigned int	num;
	int				prnt;

	num = va_arg(args, unsigned int);
	prnt = ft_putunsigned_fd(num, 1);
	return (prnt);
}
