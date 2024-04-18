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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(char const *, ...);
int		ft_putchar(va_list args);
int		ft_putstr(va_list args);
int		ft_putmem(va_list args);
int		ft_putnbr(va_list args);
int		ft_putunsigned(va_list args);
int		ft_puthex(va_list args, int mayus);
int		ft_putstr_fd(char *s, int fd);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(char const *s);
int		ft_putnbr_fd(int n, int fd);

#endif
