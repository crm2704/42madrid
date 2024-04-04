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

static int	ft_in(char c, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		i;
	int		j;
	char	*ans;
	int		k;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_in(s1[i], set) == 1)
		i++;
	while (j >= 0 && ft_in(s1[j], set) == 1)
		j--;
	if (j > i)
		ans = malloc(j - i + 2);
	else
		ans = malloc(1);
	if (ans == NULL)
		return (NULL);
	k = 0;
	while (i <= j)
		ans[k++] = s1[i++];
	ans[k] = '\0';
	return (ans);
}
/*
int	main(int argc, char const *argv[])
{
	char	*set;
	char	*s1;
	char	*res;

	set = "";
	s1 = "";
	res = ft_strtrim(s1, set);
	printf("%s\n", res);
	return (0);
}
*/