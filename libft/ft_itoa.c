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

static int	ft_check_num_len(int n)
{
	int	cont;

	cont = 0;
	while (n / 10 != 0)
	{
		cont++;
		n /= 10;
	}
	return (cont + 1);
}

static void	ft_chrnum(char *s, int n, int len)
{
	s[len] = '\0';
	len--;
	while (n / 10 != 0)
	{
		s[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	s[len] = n + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ans;
	int		neg;

	neg = 0;
	if (n == -2147483648)
	{
		ans = malloc(12 * sizeof(char));
		if (ans != NULL)
			ft_strlcpy(ans, "-2147483648", 12);
		return (ans);
	}
	len = ft_check_num_len(n);
	if (n >= 0)
		ans = malloc((len + 1) * sizeof(char));
	else
	{
		ans = malloc((len + 2) * sizeof(char));
		n *= -1;
		neg = 1;
		len++;
	}
	if (ans == NULL)
		return (NULL);
	ft_chrnum(ans, n, len);
	if (neg == 1)
	{
		ans[0] = '-';
		return (ans);
	}
	return (ans);
}
/*
#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void) {
	int test_cases[] = {0, 1, -1, 12345, -12345, INT_MAX, INT_MIN};
	int num_test_cases = sizeof(test_cases) / sizeof(test_cases[0]);

	for (int i = 0; i < num_test_cases; i++) {
		int num = test_cases[i];
		char *str = ft_itoa(num);
		if (str == NULL) {
			printf("Test case %d: Memory allocation failed\n", i + 1);
			continue ;
		}
		printf("Test case %d: The string representation of %d is %s\n", i + 1,
			num, str);
		free(str);
	}

	return (0);
}
*/
