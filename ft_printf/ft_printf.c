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

int    ft_printf(char const *format, ...)
{
    size_t punct;
    void *ptr;
    ptr = (void *)format;
    punct = (size_t)ptr;

    size_t i;
    i = 0x77;
    printf("%zu\n", i);
    printf("%p\n", ptr);
    printf("%lu\n", punct);
    return (0);
}

int ft_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int argc, char const *argv[])
{
    ft_printf("Hello, World!\n");
    return 0;
}
