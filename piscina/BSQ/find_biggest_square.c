/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_biggest_square.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:12:21 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 12:12:22 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>
#include <gen_matrix.c>

t_res find_square(char **map)
{
    t_res res;
    int max_i = 0;
    int max_j = 0;
    t_casilla **matrix = gen_matrix(map);
    res = solve_square(matrix);
    return res;
}

t_res solve_square(t_casilla **matrix)
{
    int rows = ft_strlen(matrix); // generar funcion
	int cols = ft_strlen(matrix[0]);
    int i = 0;
    int j;
    int max_density = 0;
    int density = 0;
    int max_i = 0;
    int max_j = 0;
    while(i < rows)
    {
        j = 0;
        while(j < cols)
        {
            t_casilla cas_act = matrix[i][j];
            if(i < cas_act.dist_down && j < cas_act.dist_right)
            {
                density++;
            }
            if(density > max_density){
                max_density = density;
                max_i = i;
                max_j = j;
                density = 0;
            }
            j++;
        }
        i++;
    }
    t_res res;
    res.i = max_i;
    res.j = max_j;
    res.density = max_density;
    return res;
}