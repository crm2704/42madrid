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

#include "libftprintf.h"

void	ft_putnbr(va_list args)
{
	int	n;

	n = (int)va_arg(args, int);
	ft_putnbr_fd(n, 1);
}

void	ft_putunsigned(va_list args)
{
	int				n;
	unsigned int	num;

	n = (int)va_arg(args, int);
	num = (unsigned int)n;
	n = (num) % 10;
	num /= 10;
	ft_putnbr_fd(num, 1);
	ft_putnbr_fd((n), 1);
}
