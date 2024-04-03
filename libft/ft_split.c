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

static char	**aux(char *s, char **res, char c)
{
	size_t	i;
	size_t	j;
	size_t	r;

	i = 0;
	j = 0;
	r = 0;
	while (s[r])
	{
		if (s[r] == c)
		{
			if (j > 0)
			{
				res[i][j] = '\0';
				i++;
			}
			j = 0;
			r++;
		}
		else
		{
			res[i][j] = s[r];
			j++;
			r++;
		}
	}
	if (j > 0)
		res[i][j] = '\0';
	return (res);
}

static size_t	ft_count_words(char *s, char c)
{
	size_t	i;
	size_t	cont;

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

static size_t	ft_strlen_aux(char *s, char c, int i)
{
	size_t	j;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	return (j - i);
}

char	**ft_split(char *s, char c)
{
	long	n;
	long	i;
	char	**res;
	int		pos;
	int		m;

	n = ft_count_words(s, c);
	res = malloc((n + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	pos = 0;
	m = 0;
	while (i < n)
	{
		m = ft_strlen_aux(s, c, pos) + 1;
		res[i] = malloc((m) * sizeof(char));
		pos += m;
		if (res[i] == NULL)
		{
			while (--n >= 0)
				free(res[n]);
			return (free(res), NULL);
		}
		i++;
	}
	return (aux(s, res, c));
}
/*
int	main(void)
{
	char	**tabstr;
	int		i;

	i = 0;
	if (!(tabstr = ft_split("hello!", ' ')))
		printf("NULL\n");
	else
		printf("GOOD\n");
	while(tabstr[i])
	{
		printf("%s\n", tabstr[i++]);
	}
	return (0);
}
*/
