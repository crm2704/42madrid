/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 16:11:35 by crubio            #+#    #+#             */
/*   Updated: 2024/03/16 16:11:36 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**aux(char const *s, char **res, char c)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	r = 0;
	while (s[r])
	{
		if (s[r] == c)
		{
			res[i][j] = '\0';
			r += 1;
			j = 0;
			i += 1;
		}
		if (s[r] != c)
			res[i][j] = s[r];
		j += 1;
		r += 1;
	}
	return (res);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == c)
			cont += 1;
		i += 1;
	}
	if (s[0] == '\0')
		return (0);
	return (cont + 1);
}

static int	ft_strlen_aux(char const *s, char c, int i)
{
	int	j;

	j = i;
	while (s[j] && s[j] != c)
	{
		j += 1;
	}
	return (j - i);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		i;
	int		max;
	char	**res;

	if (s == NULL)
		return (NULL);
	n = ft_count_words(s, c);
	res = malloc((n + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = malloc((ft_strlen_aux(s, c, i) + 1) * sizeof(char));
		if (res[i] == NULL)
		{
			while (--n >= 0)
				free(res[n]);
			return (free(res), NULL);
		}
		i += 1;
	}
	return (aux(s, res, c));
}

int	main(int argc, char const *argv[])
{
	char	**res;
	char	*str;

	str = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
	if (argc > 0)
	{
		res = ft_split(str, ' ');
		for (size_t i = 0; res != NULL && res[i]; i++)
		{
			printf("%s\n", res[i]);
			free(res[i]);
		}
		free(res);
	}
	return (0);
}
