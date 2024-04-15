/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 21:47:11 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/05 21:47:12 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*new_str;
	char			*s;

	s = (char *)str;
	if (!s || !f)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new_str[i] = f(i, s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
/*
char	test_func(unsigned int i, char c)
{
	return (c + 1);
}

int	main(void)
{
	char	*str;
	char	*new_str;

	str = "123";
	new_str = ft_strmapi(str, test_func);
	if (new_str == NULL)
	{
		printf("Memory allocation failed\n");
		return (1);
	}
	printf("Original string: %s\n", str);
	printf("New string: %s\n", new_str);
	free(new_str);
	return (0);
}
*/