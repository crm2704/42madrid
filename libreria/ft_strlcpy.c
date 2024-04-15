/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 19:22:56 by crubio            #+#    #+#             */
/*   Updated: 2024/03/30 19:22:58 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t dstsize)
{
	size_t	i;
	size_t	res;
	char	*s;

	s = (char *)src;
	i = 0;
	if (dstsize > 0)
	{
		while (i < dstsize - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	res = ft_strlen(src);
	return (res);
}
/*
int	main(void)
{
	char	dest[50] = "";
	char	*src;
	int		res;

	src = "";
	res = strlcpy(dest, src, 10);
	printf("%d\n", res);
	printf("%s\n", dest);
	return (0);
}*/
