/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:43:19 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 15:08:52 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aux(int nb, int b);

void	ft_putnbr(int nb, int b)
{
	if (nb == -1024 * 1024 * 1024 * 2)
	{
		nb = (nb + 1) * (-1);
		write(1, "-", 1);
		aux(nb / b, b);
		write(1, "8", 1);
		nb = -1024 * 1024 * 1024 * 2;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * (-1);
		aux(nb, b);
	}
	else
	{
		aux(nb, b);
	}
}

void	aux(int nb, int b)
{
	char	n;

	if (nb / b == 0)
	{
		n = (nb % b) + '0';
		write(1, &n, 1);
	}
	else
	{
		n = (nb % b) + '0';
		aux(nb / b, b);
		write(1, &n, 1);
	}
}
