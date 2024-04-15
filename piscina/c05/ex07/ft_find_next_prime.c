/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:40:11 by crubio            #+#    #+#             */
/*   Updated: 2024/02/27 12:40:13 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb == 0 || nb == 1)
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

int	ft_find_next_prime(int nb)
{
	int	temp;

	temp = nb + 2;
	while (!(ft_is_prime(temp)))
	{
		temp += 2;
	}
	return (temp);
}
/*
#include <stdio.h>

int	main(void)
{
	int	res;
	int	i;

	res = 73;
	i = 0;
	while (i < 121212)
	{
		res = ft_find_next_prime(res);
		printf("%d\n", res);
		i++;
	}
	return (0);
}
*/