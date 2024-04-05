/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:11:35 by crubio            #+#    #+#             */
/*   Updated: 2024/03/19 12:45:13 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memok(char **ans, int i)
{
	while (i >= 0)
	{
		free(ans[i]);
		i--;
	}
	free(ans);
	return (NULL);
}

static void	ft_putstr(char *s, char *dst, size_t start, size_t end)
{
	int	i;

	i = 0;
	while (start < end)
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
}

static size_t	ft_strlen_aux(char *s, char c, size_t i)
{
	size_t	j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	return (j - i);
}

static size_t	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	cont;

	if (s[0] == '\0')
		return (0);
	i = 1;
	cont = 0;
	while (s[i])
	{
		if (s[i] == c && s[i - 1] != c)
			cont += 1;
		i += 1;
	}
	if (s[i - 1] != c)
		cont++;
	return (cont);
}

char	**ft_split(char *s, char c)
{
	char	**ans;
	size_t	i;
	size_t	pos;
	size_t	s_len;
	size_t	s_i_len;

	ans = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (ans == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	s_len = ft_strlen(s);
	while (pos < s_len)
	{
		s_i_len = ft_strlen_aux(s, c, pos);
		if (s_i_len > 0)
		{
			ans[i] = malloc((s_i_len + 1) * sizeof(char));
			if (ans[i] == NULL)
				return (ft_memok(ans, (int)i));
			ft_putstr(s, ans[i], pos, pos + s_i_len);
			pos += s_i_len;
			i++;
		}
		else
			pos++;
	}
	ans[i] = NULL;
	return (ans);
}
/*
int	main(void)
{
	char	**tabstr;
	int		i;
	char	test_chars[] = {',', ',', ',', ',', 'a', '\0'};
	int		j;

	char	*test_strings[] = {"Hello, world", "foo,bar,baz", "",
			"a,b,c,d,e,f,g", "", NULL};
	i = 0;
	while (test_strings[i] != NULL)
	{
		printf("Testing with string: %s and split char: %c\n", test_strings[i],
			test_chars[i]);
		tabstr = ft_split(test_strings[i], test_chars[i]);
		if (tabstr == NULL)
		{
			printf("ft_split returned NULL\n");
		}
		else
		{
			j = 0;
			while (tabstr[j])
			{
				printf("Split word %d: %s\n", j, tabstr[j]);
				free(tabstr[j]);
				j++;
			}
			free(tabstr);
		}
		i++;
	}
	return (0);
}
*/
