/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 13:06:18 by crubio            #+#    #+#             */
/*   Updated: 2024/02/22 13:06:20 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_len(char *str);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;

	i = 0;
	j = 0;
	res = ft_len(dest) + ft_len(src);
	while (dest[i])
		i++;
	while (i < size && src[j] != '\0')
	{
		if (i < size - 1)
		{
			dest[i] = src[j];
		}
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

unsigned int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	char			*src;
	char			dest[200] = "H";
	unsigned int	res;
	unsigned int	res2;

	src = "elloworld";
	res = ft_strlcat(dest, src, 20);
	res2 = strlcat(dest, src, 200);
	printf("mi funcion:\n%d\n", res);
	printf("funcion de C\n%d\n", res2);
	return (0);
}
*/