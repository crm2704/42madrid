/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:40:59 by crubio            #+#    #+#             */
/*   Updated: 2024/02/21 16:41:01 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (src[j])
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
	char	dest[30] = "bbbbbbbbb";
	char	*res;
	char	*res2;

	res = ft_strcat(dest, src);
	res2 = strcat(dest, src);
	printf("miaddddd: %s.\n", res);
	printf("original: %s.\n", res2);
	printf("%s.\n", dest);
	printf("%s.\n", src);
	return (0);
}
*/