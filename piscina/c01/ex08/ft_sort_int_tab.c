/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 12:27:03 by crubio            #+#    #+#             */
/*   Updated: 2024/02/15 12:27:08 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;
	int	temp;
	int	index;

	i = 0;
	while (i < size)
	{
		min = tab[i] + 1;
		j = i;
		while (j < size)
		{
			if (tab[j] < min)
			{
				min = tab[j];
				index = j;
			}
			j++;
		}
		temp = tab[i];
		tab[i] = tab[index];
		tab[index] = temp;
		i++;
	}
}
