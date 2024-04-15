/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 10:37:02 by crubio            #+#    #+#             */
/*   Updated: 2024/02/21 10:37:04 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
/*
int	main(int argc, char const *argv[])
{
	char	*s1;
	char	*s2;
	int		res;
	int		res2;

	s1 = "hola"; // revisar para distinotos caracteres null.
	s2 = "holA";
	res = ft_strcmp(s1, s2);
	res2 = strcmp(s1, s2);
	printf("%d\n", res);
	printf("%d\n", res2);
	return (0);
}
*/