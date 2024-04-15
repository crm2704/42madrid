/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 20:15:07 by crm2704           #+#    #+#             */
/*   Updated: 2024/03/24 22:12:19 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(int argc, char const *argv[])
{
	char	*src;
	char	dest[] = "adios";
	char	*s1;
	char	*s2;

	src = "hola";
	s1 = ft_memcpy(((void *)0), ((void *)0), 0);
	s2 = memcpy(((void *)0), ((void *)0), 0);
	printf("%s\n", s1);
	printf("%s\n", s2);
	return (0);
}
*/