/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 19:54:17 by crubio            #+#    #+#             */
/*   Updated: 2024/04/14 19:54:38 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(va_list args)
{
	char	res;

	res = (char)va_arg(args, int);
	return (ft_putchar_fd(res, 1));
}

int	ft_putstr(va_list args)
{
	char	*res;

	res = (char *)va_arg(args, char *);
	return (ft_putstr_fd(res, 1));
}
