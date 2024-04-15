/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iteratve_factorial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:22:12 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 14:50:55 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
	{
		return (0);
	}
	else if (nb == 0)
	{
		return (1);
	}
	else
	{
		while (nb > 1)
		{
			res *= nb;
			nb--;
		}
	}
	return (res);
}
/*
int	main(int argc, char const *argv[])
{
	int	res;

	res = ft_iterative_factorial(5);
	printf("%d\n", res);
	return (0);
}
*/