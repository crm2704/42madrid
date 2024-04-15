/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:32:32 by crubio            #+#    #+#             */
/*   Updated: 2024/02/27 12:32:34 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
	{
		return (0);
	}
	else
	{
		if (nb % 2 == 0)
		{
			return (0);
		}
		i = 3;
		while (i <= nb / 2)
		{
			if (nb % i == 0)
			{
				return (0);
			}
			i += 2;
		}
	}
	return (1);
}
/*
#include <stdio.h>

int	main(void)
{
	int	res;

	res = ft_is_prime(1259029);
	printf("%d\n", res);
	return (0);
}
*/