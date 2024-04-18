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

int	ft_putunsigned(va_list args)
{
	int				n;
	unsigned int	num;
	unsigned int	prnt;

	n = (int)va_arg(args, int);
	num = (unsigned int)n;
	n = (num) / 10;
	num = n % 10;
	prnt = ft_putnbr_fd(num, 1);
	n = ft_putnbr_fd(n, 1);
	if (num > 0)
		return (prnt + 1);
	return (1);
}
