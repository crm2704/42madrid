/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:56:12 by crubio            #+#    #+#             */
/*   Updated: 2024/04/04 17:56:14 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ans;
	int		i;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	i = 1;
	while (n / i >= 10)
		i *= 10;
	ans = (char *)malloc((i + neg + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	if (neg)
		ans[0] = '-';
	while (i >= 1)
	{
		ans[neg] = n / i + '0';
		n %= i;
		i /= 10;
		neg++;
	}
	ans[neg] = '\0';
	return (ans);
}
