/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:34:49 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 11:34:50 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cont;

	cont = 0;
	while (lst != NULL)
	{
		cont++;
		lst = lst->next;
	}
	return (cont);
}

/*
#include "libft.h"
#include <stdio.h>

int	main(void)
{
	int		num1;
	int		num2;
	int		num3;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	int		size;
	t_list	*tmp;

	num1 = 42;
	num2 = 24;
	num3 = 12;
	node1 = ft_lstnew(&num1);
	node2 = ft_lstnew(&num2);
	node3 = ft_lstnew(&num3);
	if (node1 == NULL || node2 == NULL || node3 == NULL)
	{
		printf("Failed to create nodes\n");
		return (1);
	}
	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node1, node3);
	size = ft_lstsize(node1);
	printf("List size: %d\n", size);
	while (node1 != NULL)
	{
		tmp = node1;
		node1 = node1->next;
		free(tmp);
	}
	return (0);
}
*/