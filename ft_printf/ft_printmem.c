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

static char	*ft_toHex(size_t ptr)
{
}

void	ft_putmem(va_list args)
{
	size_t	ptr;
	char	*res;

	ptr = (size_t)va_arg(args, void *);
	res = ft_toHex(ptr);
	ft_putstr_fd(res, 1);
}
