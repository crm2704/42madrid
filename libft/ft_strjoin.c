/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 19:11:47 by crubio            #+#    #+#             */
/*   Updated: 2024/04/03 19:11:49 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ans;
	int		i;
	int		j;

	ans = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ans == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ans[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ans[i] = s2[j];
		i++;
		j++;
	}
	ans[i] = '\0';
	return (ans);
}
