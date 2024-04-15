/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:25:25 by crubio            #+#    #+#             */
/*   Updated: 2024/02/22 18:19:34 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				flag;

	flag = 0;
	i = 0;
	while ((s1[i] || s2[i]) && i < n && flag == 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		if (!s1[i] || !s2[i])
			flag = 1;
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

	s1 = "holo\0p"; // revisar para distinotos caracteres null.
	s2 = "hola\0s";
	res = ft_strncmp(s1, s2, 5);
	res2 = strncmp(s1, s2, 5);
	printf("%d\n", res);
	printf("%d\n", res2);
	return (0);
}
*/
