/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:00:22 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/05 22:00:23 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	if (!(!s || !f))
	{
		i = 0;
		while (s[i])
		{
			f(i, &s[i]);
			i++;
		}
	}
}
/*
void	test_func(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char	str[] = "Hello, World!";

	ft_striteri(str, test_func);
	printf("Modified string: %s\n", str);
	return (0);
}
*/