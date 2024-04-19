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
	va_end(args);
	return (ans);
}

/*
int main(void)
{
	char *str = "Hello, World!";
	int num = 4232412;
	unsigned int unum = -42;
	void *ptr = &num;
	int ret1, ret2;

	printf("Testing string: ");
	ret1 = printf("%s\n", str);
	ret2 = ft_printf("%s\n", str);
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	printf("Testing integer: ");
	ret1 = printf("%d\n", num);
	ret2 = ft_printf("%d\n", num);
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	printf("Testing unsigned integer: ");
	ret1 = printf("%u\n", unum);
	ret2 = ft_printf("%u\n", unum);
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	printf("Testing hexadecimal: ");
	ret1 = printf("%x\n", num);
	ret2 = ft_printf("%x\n", num);
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	printf("Testing uppercase hexadecimal: ");
	ret1 = printf("%X\n", num);
	ret2 = ft_printf("%X\n", num);
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	printf("Testing pointer: ");
	ret1 = printf("%p\n", ptr);
	ret2 = ft_printf("%p\n", ptr);
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	printf("Testing percentage: ");
	ret1 = printf("%%\n");
	ret2 = ft_printf("%%\n");
	printf("printf returned: %d, ft_printf returned: %d\n", ret1, ret2);

	return 0;
}
*/