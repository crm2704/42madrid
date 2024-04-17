/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:34:19 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/17 17:34:21 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
void	ft_putchar(va_list args);
void	ft_putstr(va_list args);
void	ft_putmem(va_list args);
void	ft_putnbr(va_list args);
void	ft_putunsigned(va_list args);
void	ft_puthex(va_list args, int mayus);

#endif
