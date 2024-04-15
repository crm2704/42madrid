/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnarciso <jnarciso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:50:41 by jnarciso          #+#    #+#             */
/*   Updated: 2024/02/20 10:48:24 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

extern void	rush(int width, int height);

int	main(int argc, char **argv)
{
	printf("%d\n", argc);
	if (argc != 3)
		return 0;
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	rush(x, y);
	return (0);
}
