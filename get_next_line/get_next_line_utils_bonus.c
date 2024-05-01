/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:44:14 by crubio            #+#    #+#             */
/*   Updated: 2024/05/01 19:57:31 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*ans;
	int		i;
	int		j;
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	ans = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		ans[i++] = s2[j++];
	ans[i] = '\0';
	return (ans);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	mem = malloc((len + 1) * sizeof(char));
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s + start, len + 1);
	return (mem);
}

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char const *s)
{
	size_t	total;
	size_t	i;
	char	*ans;
	char	*s1;

	s1 = (char *)s;
	total = ft_strlen(s1) + 1;
	ans = malloc(total);
	if (ans != NULL)
	{
		i = 0;
		while (i < total)
		{
			ans[i] = 0;
			i++;
		}
	}
	else
		return (NULL);
	ft_strlcpy(ans, s1, total);
	return (ans);
}

size_t	ft_strlcpy(char *dest, char const *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

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
