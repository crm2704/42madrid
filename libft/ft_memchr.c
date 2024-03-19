/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:22:01 by crm2704           #+#    #+#             */
/*   Updated: 2024/03/19 14:22:17 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned const char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
		{
			return (void *)(p + i);
		}
        i++;
	}
	return (0);
}
