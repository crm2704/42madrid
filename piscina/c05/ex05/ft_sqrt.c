/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:21:37 by crubio            #+#    #+#             */
/*   Updated: 2024/02/27 15:03:44 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		return (0);
	}
	while (i * i <= nb)
	{
		if (i * i == nb)
		{
			return (i);
		}
		if (i > 46340)
		{
			return (0);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	int	res;

	res = ft_sqrt(1649415769);
	printf("%d\n", res);
	return (0);
}
*/
