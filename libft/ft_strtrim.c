/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:22:20 by crubio            #+#    #+#             */
/*   Updated: 2024/04/03 19:22:21 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	char	*ans;
	int		foundRight;
	int		foundLeft;
	int		k;

	foundRight = 0;
	foundLeft = 0;
	i = 0;
	j = ft_strlen(s1);
	while (i < j && (foundRight == 0 || foundLeft == 0))
	{
		if (ft_in(s1[i], set) == 0)
			foundRight = 1;
		if (ft_in(s1[i], set) == 1 && foundRight == 0)
			i++;
		if (ft_in(s1[j], set) == 0)
			foundLeft = 1;
		if (ft_in(s1[j], set) == 1 && foundLeft == 0)
			j--;
	}
	ans = malloc(j - i + 1);
	k = 0;
	while (i < j)
	{
		ans[i] = s1[k];
		i++;
		k++;
	}
	ans[i] = '\0';
	return (ans);
}

int	main(int argc, char const *argv[])
{
	char	*set;
	char	*s1;
	char	*res;

	set = " hol";
	s1 = " hola Ignacio ";
	res = ft_strtrim(s1, set);
	printf("%s\n", res);
	return (0);
}
