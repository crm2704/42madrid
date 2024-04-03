/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:17:31 by crubio            #+#    #+#             */
/*   Updated: 2024/03/30 20:17:33 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = 0;
	j = 0;
	if ((ft_strlen(src) + dstsize) < (ft_strlen(src) + ft_strlen(dst))
		&& dstsize < (ft_strlen(src) + ft_strlen(dst)))
		res = ft_strlen(src) + dstsize;
	else
		res = ft_strlen(src) + ft_strlen(dst);
	while (dst[i])
		i++;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (res);
}
/*
int	main(int argc, char const *argv[])
{
	char	*str;
	char	buff1[30] = "CCCCC";
	char	*buff2;
	int		max;
	size_t	res;

	buff2 = (char *)"AAAAAAAAA";
	str = "the cake is a lie !\0I'm hidden lol\r\n";
	max = ft_strlen(str) + 4;
	res = ft_strlcat(buff1, buff2, -1);
	// strlcat(buff1, str, -1);
	printf("%s\n", buff1);
	printf("%zu\n", res);
	return (0);
}
*/
