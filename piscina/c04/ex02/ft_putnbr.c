/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 13:15:33 by crubio            #+#    #+#             */
/*   Updated: 2024/02/24 13:15:38 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aux(int nb);

void	ft_putnbr(int nb)
{
	if (nb == -1024 * 1024 * 1024 * 2)
	{
		nb = (nb + 1) * (-1);
		write(1, "-", 1);
		aux(nb / 10);
		write(1, "8", 1);
		nb = -1024 * 1024 * 1024 * 2;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		aux(nb);
	}
	else
	{
		aux(nb);
	}
}

void	aux(int nb)
{
	char	n;

	if (nb / 10 == 0)
	{
		n = (nb % 10) + '0';
		write(1, &n, 1);
	}
	else
	{
		n = (nb % 10) + '0';
		aux(nb / 10);
		write(1, &n, 1);
	}
}
/*
int	main(void)
{
	int	i;

	i = 1024 * 1024 * 1024 * 2 + 10;
	ft_putnbr(i);
	write(1, "\n", 1);
	i--;
	ft_putnbr(i);
	write(1, "\n", 1);
	return (0);
}
*/