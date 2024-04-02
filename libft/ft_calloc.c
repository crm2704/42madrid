/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:36:36 by crubio            #+#    #+#             */
/*   Updated: 2024/04/02 15:36:38 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t total = count * size;

	unsigned char *ans = malloc(total);

	if (ans != NULL)
	{
		size_t i = 0;
		while (i < total)
		{
			ans[i] = 0;
			i++;
		}
	}
	return (ans);
}