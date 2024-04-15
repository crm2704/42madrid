/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 19:31:38 by crubio            #+#    #+#             */
/*   Updated: 2024/02/13 11:31:34 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	prnt(char i, char j, char k);

void	ft_print_comb(void)
{
	char	i;
	char	j;
	char	k;

	i = '0';
	while (i <= '7')
	{
		j = '0';
		while (j <= '8')
		{
			k = '0';
			while (k <= '9')
			{
				if (i < j && j < k)
				{
					prnt(i, j, k);
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

void	prnt(char i, char j, char k)
{
	if (i < '7')
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
		write(1, ", ", 2);
	}
	else
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, &k, 1);
	}
}
