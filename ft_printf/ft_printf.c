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

#include "ft_printf.h"

static int	ft_choose_option(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(args));
	else if (c == 's')
		return (ft_putstr(args));
	else if (c == 'p')
		return (ft_putmem(args));
	else if (c == 'd')
		return (ft_putnbr(args));
	else if (c == 'i')
		return (ft_putnbr(args));
	else if (c == 'u')
		return (ft_putunsigned(args));
	else if (c == 'x')
		return (ft_puthex(args, 0));
	else if (c == 'X')
		return (ft_puthex(args, 1));
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		ans;
	va_list	args;

	i = 0;
	ans = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			ans++;
		}
		else
		{
			i++;
			ans += ft_choose_option(format[i], args);
		}
		i++;
	}
	return (ans);
}
/*
int	main(void)
{
	char	*res;

	res = "hola";
	printf("%d\n", printf("%d\n", 0));
	printf("%d\n", ft_printf("%d\n", 0));
	return (0);
}
*/