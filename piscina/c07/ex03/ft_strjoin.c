/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:24:47 by crubio            #+#    #+#             */
/*   Updated: 2024/02/29 18:33:03 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_cont_malloc(char **str)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			cont++;
			j++;
		}
		i++;
	}
	return (cont);
}

char	*aux(int size, char **strs, char *sep, int cont_malloc)
{
	char	*res;
	int		i;
	int		x;
	int		j;

	res = (char *)malloc((cont_malloc + size * ft_strlen(sep)) * sizeof(char));
	i = 0;
	x = 0;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			res[x] = strs[i][j];
			j++;
			x++;
		}
		j = 0;
		while (sep[j])
		{
			res[x++] = sep[j++];
		}
		i++;
	}
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		cont_malloc;
	int		i;
	int		j;
	int		x;

	if (size == 0)
	{
		res = (char *)malloc(sizeof(char));
		return (res);
	}
	else
	{
		cont_malloc = ft_cont_malloc(strs);
		res = aux(size, strs, sep, cont_malloc);
		return (res);
	}
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	sep[] = "-";
	char	*res;

	res = ft_strjoin(argc, argv, sep);
	printf("%s\n", res);
	free(res);
	return (0);
}
*/