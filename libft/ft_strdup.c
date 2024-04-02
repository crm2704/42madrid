/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:48:02 by crubio            #+#    #+#             */
/*   Updated: 2024/04/02 15:48:04 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	size_t	total;
	size_t	i;
	char	*ans;

	total = ft_strlen(s1) + 1;
	ans = malloc(total);
	if (ans != NULL)
	{
		i = 0;
		while (i < total)
		{
			ans[i] = 0;
			i++;
		}
	}
	else
		return (NULL);
	ft_strlcpy(ans, s1, total);
	return (ans);
}
