/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 00:55:29 by crm2704           #+#    #+#             */
/*   Updated: 2024/03/25 00:59:00 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*S1 = s1;
	const unsigned char	*S2 = s2;

	i = 0;
	while (i < n)
	{
		if (S1[i] != S2[i])
			return (S1[i] - S2[i]);
		i++;
	}
	return (0);
}
