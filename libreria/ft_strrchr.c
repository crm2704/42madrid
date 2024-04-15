/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 18:03:23 by crubio            #+#    #+#             */
/*   Updated: 2024/03/18 18:03:38 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	char	*str;
	char	c;
	size_t	i;

	str = (char *)s;
	c = (char)ch;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (str[i] == c)
			return (str + i);
		if (i == 0)
			break ;
		i--;
	}
	return (0);
}
