/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:09:07 by crubio            #+#    #+#             */
/*   Updated: 2024/02/21 15:04:07 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;
	int				change;

	i = 0;
	change = 0;
	while (i < n)
	{
		if (change == 0 && src[i] == '\0')
		{
			change = 1;
		}
		if (change == 0)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[20] = "cubiertos";
	char	*src;
	char	*res;

	src = "hola";
	res = ft_strncpy(dest, src, 5);
	printf("%s\n", res);
	return (0);
}
*/