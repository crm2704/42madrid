/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnarciso <jnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 12:05:47 by jnarciso          #+#    #+#             */
/*   Updated: 2024/02/14 15:56:03 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern void	ft_putchar(char c);

void	write_horizontal(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar('-');
		++i;
	}
}

void	write_empty(int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_putchar(' ');
		++i;
	}
}

void	rush(int width, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (i == 0 || i == height - 1)
		{
			ft_putchar('o');
			write_horizontal(width - 2);
			ft_putchar('o');
		}
		else
		{
			ft_putchar('|');
			write_empty(width - 2);
			ft_putchar('|');
		}
		ft_putchar('\n');
		++i;
	}
}
