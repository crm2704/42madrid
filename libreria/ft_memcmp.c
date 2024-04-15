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
	const unsigned char	*s1_aux;
	const unsigned char	*s2_aux;

	s1_aux = s1;
	s2_aux = s2;
	i = 0;
	while (i < n)
	{
		if (s1_aux[i] != s2_aux[i])
			return (s1_aux[i] - s2_aux[i]);
		i++;
	}
	return (0);
}
