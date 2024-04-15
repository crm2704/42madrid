/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:55:49 by crubio            #+#    #+#             */
/*   Updated: 2024/02/20 13:55:52 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_c(char *str);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	int				change;
	int				res;

	i = 0;
	change = 0;
	while (i < size)
	{
		if (change == 0)
		{
			dest[i] = src[i];
		}
		else
		{
			dest[i] = '\0';
		}
		if (change == 0 && src[i] == '\0')
		{
			change = 1;
		}
		i++;
	}
	dest[i] = '\0';
	res = ft_c(src);
	return (res);
}

int	ft_c(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
/*
int	main(void)
{
	char	dest[50] = "cubiertos";
	char	*src;
	int		res;

	src = "sjdffsbvdsjbv";
	res = ft_strlcpy(dest, src, 10);
	printf("%d\n", res);
	printf("%s\n", dest);
	return (0);
}
*/