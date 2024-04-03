/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:11:43 by crubio            #+#    #+#             */
/*   Updated: 2024/04/03 14:11:45 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr_aux(char *s, size_t s_len, unsigned int start,
		size_t len)
{
	char	*ans;
	int		i;
	int		j;

	i = start;
	if (s_len - start < len)
		ans = malloc((s_len - start + 1) * sizeof(char));
	else
		ans = malloc((len + 1) * sizeof(char));
	j = 0;
	if (ans == NULL)
		return (NULL);
	while (s[i] && (i - start) < len)
	{
		ans[j] = s[i];
		j++;
		i++;
	}
	ans[j] = '\0';
	return (ans);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		ans = malloc(1);
		ans[0] = '\0';
		if (ans == NULL)
			return (NULL);
		return (ans);
	}
	return (ft_substr_aux(s, s_len, start, len));
}
/*
int	main(void)
{
	unsigned int	start;
	size_t			len;
	char			*res;
	char			*str;
	char			*res2;

	str = "01234";
	start = 10;
	len = 10;
	res = ft_substr("01234", 10, 10);
	if (res != NULL)
		printf("%s\n", res);
	return (0);
}
*/