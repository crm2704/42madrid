/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 16:17:56 by crubio            #+#    #+#             */
/*   Updated: 2024/03/18 16:28:22 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int main(int argc, char const *argv[])
{
	int i= 0;
	while(i < 47){
		printf("%d",ft_isdigit(i));	
		i++;
	}
	printf("\n");
	return 0;
}
*/