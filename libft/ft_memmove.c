/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:42:06 by crubio            #+#    #+#             */
/*   Updated: 2024/03/30 17:42:09 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	if (dst == NULL && src == NULL)
		return (NULL);
	s = src;
	d = dst;
	i = 0;
	if (s < d && s + len > d)
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
	else
	{
		i = -1;
		while (++i < len)
			d[i] = s[i];
	}
	return (dst);
}
/*
int	main(int argc, char const *argv[])
{
	char	*src;
	char	dest[] = "inonon";
	char	*s1;

	src = "hol";
	s1 = ft_memmove(dest, src, 4);
	printf("%s\n", s1);
	return (0);
}
*/