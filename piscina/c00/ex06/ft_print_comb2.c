/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex06.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:23:56 by crubio            #+#    #+#             */
/*   Updated: 2024/02/13 12:12:28 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	wrt(int i, int j);

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 99)
	{
		j = 0;
		while (j <= 99)
		{
			wrt(i, j);
			j++;
		}
		i++;
	}
}

void	wrt(int i, int j)
{
	char	num_str[2];

	if (i == 98 && j == 99)
	{
		num_str[0] = i / 10 + '0';
		num_str[1] = i % 10 + '0';
		write(1, num_str, 2);
		write(1, " ", 1);
		num_str[0] = j / 10 + '0';
		num_str[1] = j % 10 + '0';
		write(1, num_str, 2);
	}
	else
	{
		num_str[0] = i / 10 + '0';
		num_str[1] = i % 10 + '0';
		write(1, num_str, 2);
		write(1, " ", 1);
		num_str[0] = j / 10 + '0';
		num_str[1] = j % 10 + '0';
		write(1, num_str, 2);
		write(1, ", ", 2);
	}
}
