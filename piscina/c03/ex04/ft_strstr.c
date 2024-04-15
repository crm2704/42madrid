/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:43:02 by crubio            #+#    #+#             */
/*   Updated: 2024/02/21 17:43:04 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		flag = 0;
		while (str[i] == to_find[j] && to_find[j] != '\0')
		{
			i++;
			j++;
			flag = 1;
		}
		if (to_find[j] == '\0')
			return ((str + i - 1) - (j - 1));
		if (flag == 1)
			i--;
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	src[30] = "Hellowoworlworldaa";
	char	*dest;
	char	*res;
	char	*res2;

	dest = "";
	res = ft_strstr(src, dest);
	res2 = strstr(src, dest);
	printf("%s.\n", res);
	printf("%s.\n", res2);
	return (0);
}
*/