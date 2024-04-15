/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:57:04 by crubio            #+#    #+#             */
/*   Updated: 2024/02/27 11:04:11 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
		return (1);
	else
	{
		while (power > 1)
		{
			res *= nb;
			power--;
		}
	}
	return (res);
}
/*
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	int	res;

	res = ft_iterative_power(2, 5);
	printf("%d\n", res);
	return (0);
}
*/