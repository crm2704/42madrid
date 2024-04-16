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

#include "libftprintf.h"

static char	ft_choosechr(size_t n)
{
	if (n == 10)
		return ('a');
	else if (n == 11)
		return ('b');
	else if (n == 12)
		return ('c');
	else if (n == 13)
		return ('d');
	else if (n == 14)
		return ('e');
	else
		return ('f');
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

static char	*ft_to_hex(size_t ptr)
{
	char	c;
	size_t	n;
	size_t	i;
	char	*res;
	int		flag;

	i = ft_cont_malloc(ptr);
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	i--;
	flag = 0;
	while (flag == 0)
	{
		n = ptr % 16;
		if (n > 9)
			c = ft_choosechr(n);
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

void	ft_putmem(va_list args)
{
	size_t	ptr;
	char	*res;

	ptr = (size_t)va_arg(args, void *);
	res = ft_to_hex(ptr);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(res, 1);
	free(res);
}
