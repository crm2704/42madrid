/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:11:55 by crubio            #+#    #+#             */
/*   Updated: 2024/02/27 18:36:59 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		before(char *right, char *left);

void	ft_write_params(char *str);

void	ft_sort(char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (before(argv[j], argv[i]) < 0)
			{
				temp = argv[i];
				argv[i] = argv[j];
				argv[j] = temp;
			}
			j++;
		}
		ft_write_params(argv[i]);
		i++;
	}
}

int	before(char *right, char *left)
{
	int	i;

	i = 0;
	while (right[i] == left[i] && (right[i] != '\0'))
	{
		i++;
	}
	return (right[i] - left[i]);
}

void	ft_write_params(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, (str + i), 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ft_sort(argv);
	}
	return (0);
}
