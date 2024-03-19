/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:47:41 by crm2704           #+#    #+#             */
/*   Updated: 2024/03/19 13:47:59 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		*(p + i) = (unsigned char)c;
        i++;
	}
	return (s);
}
/*
int	main(int argc, char const *argv[])
{
	int		n;
	void	*s;

	n = 6;
	s = malloc(6);
	printf("%02x\n", s);
	ft_memset(s, 34, n);
	printf("%02x\n", s);
	return (0);
}
*/