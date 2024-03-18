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
	res[i][j] = '\0';
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

void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(int argc, char const *argv[])
{
	char	**tabstr;
	int		i;

	i = 0;
	if (!(tabstr = ft_split("          ", ' ')))
		ft_print_result("NULL");
	else
	{
		while (tabstr[i] != NULL)
		{
			ft_print_result(tabstr[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
/*
#include <stdlib.h>
#include <unistd.h>


void	ft_print_result(char const *s)
{
		int             len;

		len = 0;
		while (s[len])
				len++;
		write(1, s, len);
}

int	main(int argc, const char *argv[])
{
		char    **tabstr;
		int             i;
		int             arg;

		if (argc == 1)
				return (0);
		i = 0;
		if ((arg = atoi(argv[1])) == 1)
		{
				if (!(tabstr = ft_split("          ", ' ')))
						ft_print_result("NULL");
				else
				{
						while (tabstr[i] != NULL)
						{
								ft_print_result(tabstr[i]);
								write(1, "\n", 1);
								i++;
						}
				}
		}
		else if (arg == 2)
		{
				if (!(tabstr = ft_split("lorem ipsum dolor sit amet,
							consectetur adipiscing elit. Sed non risus. Suspendisse",
							' ')))
						ft_print_result("NULL");
				else
				{
						while (tabstr[i] != NULL)
						{
								ft_print_result(tabstr[i]);
								write(1, "\n", 1);
								i++;
						}
				}
		}
		else if (arg == 3)
		{
				if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet,
							consectetur   adipiscing elit. Sed non risus. Suspendisse   ",
							' ')))
						ft_print_result("NULL");
				else
				{
						while (tabstr[i] != NULL)
						{
								ft_print_result(tabstr[i]);
								write(1, "\n", 1);
								i++;
						}
				}
		}
		else if (arg == 4)
		{
				if (!(tabstr = ft_split("lorem ipsum dolor sit amet,
							consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor,
							dignissim sit amet, adipiscing nec, ultricies sed,
							dolor. Cras elementum ultricies diam. Maecenas ligula massa,
							varius a, semper congue, euismod non, mi.", 'i')))
						ft_print_result("NULL");
				else
				{
						while (tabstr[i] != NULL)
						{
								ft_print_result(tabstr[i]);
								write(1, "\n", 1);
								i++;
						}
				}
		}
		else if (arg == 5)
		{
				if (!(tabstr = ft_split("lorem ipsum dolor sit amet,
							consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor,
							dignissim sit amet, adipiscing nec, ultricies sed,
							dolor. Cras elementum ultricies diam. Maecenas ligula massa,
							varius a, semper congue, euismod non, mi.", 'z')))
						ft_print_result("NULL");
				else
				{
						while (tabstr[i] != NULL)
						{
								ft_print_result(tabstr[i]);
								write(1, "\n", 1);
								i++;
						}
				}
		}
		else if (arg == 6)
		{
				if (!(tabstr = ft_split("", 'z')))
						ft_print_result("NULL");
				else
						if (!tabstr[0])
								ft_print_result("ok\n");
		}
		return (0);
}*/