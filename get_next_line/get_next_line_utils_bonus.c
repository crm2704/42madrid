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

char	*ft_strjoin(char *str1, char *str2)
{
	char	*ans;
	int		i;
	int		j;

	ans = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (ans == NULL)
	{
		str1 = ft_freemem(&str1);
		return (NULL);
	}
	i = 0;
	while (str1[i])
	{
		ans[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
		ans[i++] = str2[j++];
	ans[i] = '\0';
	str1 = ft_freemem(&str1);
	return (ans);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
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
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_strdup(char const *s)
{
	size_t	total;
	size_t	i;
	char	*ans;

	total = ft_strlen(s) + 1;
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
	ft_strlcpy(ans, s, total);
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
