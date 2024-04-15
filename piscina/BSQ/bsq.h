/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:11:28 by crubio            #+#    #+#             */
/*   Updated: 2024/02/28 12:11:37 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// struct casilla
// funciones de escritura
// funciones de lectura
#ifndef bsq_h
# define bsq_h
// #include <main.c>

//char empty =
typedef struct s_casilla
{
	int	dist_right;
	int	dist_down;
}		t_casilla;

typedef struct s_res
{
	int	i;
	int	j;
	int density;
}		t_res;
#endif