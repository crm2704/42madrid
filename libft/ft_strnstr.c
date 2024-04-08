/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:26:42 by crubio            #+#    #+#             */
/*   Updated: 2024/03/30 21:26:44 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *h, char const *n, size_t len)
{
	size_t	i;
	size_t	j;
	char	*haystack;
	char	*needle;

	haystack = (char *)h;
	needle = (char *)n;
	i = 0;
	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i] == needle[j] && needle[j] && i < len)
		{
			i++;
			j++;
		}
		if (needle[j] == '\0')
			return ((haystack + i - 1) - (j - 1));
		if (j > 0)
			i -= j;
		i++;
	}
	return (0);
}
/*
int	main(int argc, char const *argv[])
{
	char	*haystack;
	char	*needle;
	char	*res;

	haystack = "aaaaabcabcd";
	needle = "aabc";
	res = ft_strnstr(haystack, needle, -1);
	printf("%s\n", res);
	res = strnstr(haystack, needle, -1);
	printf("%s\n", res);
	return (0);
}
*/