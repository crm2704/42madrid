/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:22:24 by crubio            #+#    #+#             */
/*   Updated: 2024/03/30 21:22:27 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pot_ten(int pot)
{
	int	res;

	res = 1;
	while (--pot > 0)
		res *= 10;
	return (res);
}

static int	ft_res(char *num, int cont_sub)
{
	int	len;
	int	i;
	int	res;

	len = ft_strlen(num);
	i = 0;
	res = 0;
	while (num[i])
	{
		res += (num[i] - '0') * ft_pot_ten(len);
		i++;
		len--;
	}
	return (res * cont_sub);
}

static int	ft_calc(int cont_sub, char *num, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((str[i] >= '\a' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			cont_sub = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num[j] = str[i];
		j++;
		i++;
	}
	return (ft_res(num, cont_sub));
}

int	ft_atoi(char *nptr)
{
	int		cont_sub;
	char	num[255];

	cont_sub = 1;
	return (ft_calc(cont_sub, num, nptr));
}
/*
int	main(int argc, char const *argv[])
{
	char	*str;
	int		n1;
	int		n2;

	str = "\v 12";
	n1 = ft_atoi(str);
	n2 = atoi(str);
	printf("%d, %d\n", n1, n2);
	return (0);
}
*/