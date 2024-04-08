/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:39:22 by crubio            #+#    #+#             */
/*   Updated: 2024/03/18 17:39:37 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int ch)
{
	char	*str;
	char	c;
	size_t	i;

	str = (char *)s;
	c = (char)ch;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (str[i] == c)
			return (str + i);
		++i;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}
