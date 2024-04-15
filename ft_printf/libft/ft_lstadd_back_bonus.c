/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:57:21 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 11:57:22 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst != NULL)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
	{
		*lst = new;
		return ;
	}
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
	t_list	*current_node;
	int		*current_value;
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
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	current_node = node1;
	while (current_node != NULL)
	{
		current_value = (int *)current_node->content;
		printf("Node value: %d\n", *current_value);
		current_node = current_node->next;
	}
	while (node1 != NULL)
	{
		tmp = node1;
		node1 = node1->next;
		free(tmp);
	}
	return (0);
}
*/