/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:20:28 by crubio            #+#    #+#             */
/*   Updated: 2024/02/29 15:20:29 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*nums;
	int	i;

	if (min >= max)
	{
		return (NULL);
	}
	nums = (int *)malloc((max - min) * sizeof(int));
	i = 0;
	while (min < max)
	{
		nums[i] = min;
		i++;
		min++;
	}
	return (nums);
}
/*
#include <stdio.h>

int	main(int argc, char const *argv[])
{
	int	*nums;
	int	i;

	nums = ft_range(2, 15);
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