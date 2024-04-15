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

#endif