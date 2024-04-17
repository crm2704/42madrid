/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:51:26 by crubio            #+#    #+#             */
/*   Updated: 2024/04/14 19:51:27 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_choose_option(char c, va_list args)
{
	if (c == 'c')
		ft_putchar(args);
	else if (c == 's')
		ft_putstr(args);
	else if (c == 'p')
		ft_putmem(args);
	else if (c == 'd')
		ft_putnbr(args);
	else if (c == 'i')
		ft_putnbr(args);
	else if (c == 'u')
		ft_putunsigned(args);
	else if (c == 'x')
		ft_puthex(args, 0);
	else if (c == 'X')
		ft_puthex(args, 1);
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		ans;
	va_list	args;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
			write(1, &format[i], 1);
		else
		{
			i++;
			ft_choose_option(format[i], args);
		}
		i++;
	}
	ans = ft_strlen(format);
	return (ans);
}
/*
int	main(void)
{
	char	*res;

	res = "hola";
	printf("Messi %p, %c, %d, %i, %u, %x, %X\n", &res, 'c', 077, 067,
		-27198912, 3287421, 3287421);
	ft_printf("Messi %p, %c, %d, %i, %u, %x, %X\n", &res, 'c', 077, 067,
		-27198912, 3287421, 3287421);
	return (0);
}
*/