/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:12:29 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 12:12:31 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_casilla	**gen_matrix(char **map)
{
	t_casilla	**matrix;
	int			cols;
	int			i;
	int			j;
	int			rows;

	rows = ft_strlen(map); // generar funcion
	cols = ft_strlen(map[0]);
	matrix = init_matrix(map, rows, cols);
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			matrix[i][j] = ft_put_vals(map, i, j);
			// generar funcion que coloca los valores de cada casilla.
		}
	}
}

t_casilla	ft_put_vals(char **map, int i, int j){
	int right = j;
	int down = i;
	int temp = 0;
	temp = j;
	while(map[i][j] != '.') //poner el caracter de obstaculo que pasen por parametro
	{
		j++;
	}
	right = j;
	j = temp;
	temp = i;
	while(map[i][j] != '.') //poner el caracter de obstaculo que pasen por parametro
	{
		i++;
	}
	down = i;
	i = temp;
	t_casilla res;
	res.dist_right = right;
	res.dist_down = down;
	return (res);
}

char	**init_matrix(char **map, int rows, int cols)
{
	t_casilla **matrix;

	//matrix = (t_casilla **)malloc(rows * sizeof(t_casilla *));
	// handle malloc error
	int i = 0;
	while (i < cols)
	{
		//matrix[i] = (t_casilla *)malloc(cols * sizeof(t_casilla));
		// handle malloc error
		i++;
	}
	return (matrix);
}