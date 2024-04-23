/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:55:13 by crubio            #+#    #+#             */
/*   Updated: 2024/04/14 19:55:33 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_choosechr(size_t n, int mayus)
{
	int	plus;

	plus = 0;
	if (mayus == 1)
		plus = 'A' - 'a';
	if (n == 10)
		return ('a' + plus);
	else if (n == 11)
		return ('b' + plus);
	else if (n == 12)
		return ('c' + plus);
	else if (n == 13)
		return ('d' + plus);
	else if (n == 14)
		return ('e' + plus);
	else
		return ('f' + plus);
}

static size_t	ft_cont_malloc(size_t ptr)
{
	size_t	ans;

	ans = 0;
	while (ptr / 16 != 0)
	{
		ans++;
		ptr /= 16;
	}
	ans++;
	return (ans);
}

static char	*ft_to_hex(size_t ptr, int mayus, size_t i)
{
	char	c;
	size_t	n;
	int		flag;
	char	*res;

	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i--] = '\0';
	flag = 0;
	while (flag == 0)
	{
		n = ptr % 16;
		if (n > 9)
			c = ft_choosechr(n, mayus);
		else
			c = n + '0';
		res[i] = c;
		ptr /= 16;
		if (i == 0)
			flag = 1;
		i--;
	}
	return (res);
}

int	ft_putmem(va_list args)
{
	size_t	ptr;
	size_t	i;
	char	*res;
	int		n;

	ptr = va_arg(args, size_t);
	i = ft_cont_malloc(ptr);
	res = ft_to_hex(ptr, 0, i);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	n = ft_strlen(res);
	return (free(res), n + 2);
}

int	ft_puthex(va_list args, int mayus)
{
	unsigned int	n;
	char			*res;
	size_t			i;

	n = va_arg(args, unsigned int);
	i = ft_cont_malloc(n);
	res = ft_to_hex(n, mayus, i);
	ft_putstr_fd(res, 1);
	n = ft_strlen(res);
	return (free(res), n);
}
