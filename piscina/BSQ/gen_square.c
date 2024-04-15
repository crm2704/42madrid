/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.square.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:12:58 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 12:12:59 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <find_biggest_square.c>

char **gen_square(char **map){
    t_res found = find_square(map);
    int casilla_i = found.i;
    int casilla_j = found.j;
    int i = casilla_i;
    int j; 
    while (i < found.density + 1)
    {
        j = casilla_j;
        while(j < found.density)
        {
            map[i][j] = 'x';
        }
    }
    return map;
}