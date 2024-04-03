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

char	*ft_strnstr(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return (big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && little[j] == big[i])
		{
			j++;
			i++;
		}
		if (j == ft_strlen(little))
			return (&big[i - j]);
        if (j > 0)
            i--;
        i++;
	}
	return (0);
}

int	main(int argc, char const *argv[])
{
	char	*big;
	char	*little;
	char	*res;

	big = "holaquetal";
	little = "i";
	res = ft_strnstr(big, little, 10);
	printf("%s\n", res);
	return (0);
}
