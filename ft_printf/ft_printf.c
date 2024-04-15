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
	char	res;

	if (c == 'c')
		ft_putchar(args);
	else if (c == 's')
		ft_putstr(args);
	else if (c == 'p')
		ft_putmem(args);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	int		j;
	int		ans;
	va_list	args;

	i = 0;
	j = 0;
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

int	main(void)
{
	char	*res;

	res = "hola";
	printf("Messi %d, %c %s, direccion %d\n", 10, 'c', "hola", 0xb7);
	ft_printf("s, %c, %s, %p\n", 'i', "hola", res);
	return (0);
}
