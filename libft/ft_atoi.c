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

int	ft_pot_ten(int pot)
{
	int	res;

	res = 10;
	while (pot > 0)
	{
		res *= 10;
		pot--;
	}
	return (res);
}

int	ft_res(char *num, int cont_sub)
{
	int	len;
	int	j;
	int	res;

	len = ft_strlen(num) - 1;
	j = 0;
	res = 0;
	while (len >= 0)
	{
		res += (num[j] - 48) * ft_pot_ten(len);
		len--;
		j++;
	}
	if (cont_sub % 2 == 0)
	{
		return (res / 10);
	}
	return ((res * (-1)) / 10);
}

int	ft_calc(int cont_sub, char *num, char *str)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	res = 0;
	while (str[i] == ' ')
		i++;
	while (!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			cont_sub++;
		i++;
	}
	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num[j] = str[i];
		i++;
		j++;
	}
	num[j] = '\0';
	res = ft_res(num, cont_sub);
	return (res);
}

int	ft_atoi(char *str)
{
	int		cont_sub;
	char	num[255];

	cont_sub = 0;
	return (ft_calc(cont_sub, num, str));
}
