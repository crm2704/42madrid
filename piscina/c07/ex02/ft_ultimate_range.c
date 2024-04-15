/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:29:53 by crubio            #+#    #+#             */
/*   Updated: 2024/02/29 16:29:54 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_intlen(int **range)
{
	int	i;

	i = 0;
	while ((*range)[i])
	{
		i++;
	}
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	res;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = (int *)malloc((max - min) + 2 * sizeof(int));
	if (range == NULL)
	{
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		(*range)[i] = min;
		i++;
		min++;
	}
	(*range)[i] = 0;
	res = ft_intlen(range);
	return (res);
}
/*
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	int	*nums;
	int	r;
	int	i;

	nums = NULL;
	r = ft_ultimate_range(&nums, 1, 200);
	printf("%d\n", r);
	i = 0;
	while (nums[i])
	{
		printf("%d ", nums[i]);
		i++;
	}
	free(nums);
	printf("\n");
	return (0);
}
*/