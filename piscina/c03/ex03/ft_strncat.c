/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:37:27 by crubio            #+#    #+#             */
/*   Updated: 2024/02/21 17:40:15 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j] && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int	main(int argc, char const *argv[])
{
	char	src[30] = "aaaaaaaaaaaaaaaaaaa";
	char	*dest;
	char	*res;
	char	*res2;

	dest = "bbbbbbbbb";
	res = ft_strncat(dest, src, 5);
	res2 = strncat(dest, src, 5);
	printf("%s.\n", res);
	return (0);
}
*/