/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:11:43 by crubio            #+#    #+#             */
/*   Updated: 2024/04/03 14:11:45 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*mem;

	if (s == 0)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	mem = malloc((len + 1) * sizeof(char));
	if (mem == 0)
		return (0);
	ft_strlcpy(mem, s + start, len + 1);
	return (mem);
}
/*
int	main(void)
{
	unsigned int	start;
	size_t			len;
	char			*res;
	char			*str;
	char			*res2;

	str = "01234";
	start = 10;
	len = 10;
	res = ft_substr("01234", 10, 10);
	if (res != NULL)
		printf("%s\n", res);
	return (0);
}
*/