/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:12:49 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 12:12:51 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <gen_square.c>

void ft_print_matrix(char **map){
    map = gen_square(map);
    int rows = ft_strlen(map); // generar funcion
	int cols = ft_strlen(map[0]);
    int i = 0;
    int j;
    while (i < rows){
        j = 0;
        while (j < cols){
            write(1, &(map[i][j]), 1);
        }
        write(1, "\n", 1);
    }
}