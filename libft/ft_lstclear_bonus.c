/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:21:53 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 12:21:55 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	aux = *lst;
	while (*lst != NULL)
	{
		aux = aux->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}

/*
#include "libft.h"
#include <stdio.h>

void	del(void *content)
{
	free(content);
}

void	print_list(t_list *lst)
{
	t_list	*current_node;
	int		*current_value;

	current_node = lst;
	while (current_node != NULL)
	{
		current_value = (int *)current_node->content;
		printf("Node value: %d\n", *current_value);
		current_node = current_node->next;
	}
}

int	main(void)
{
	int		*num1;
	int		*num2;
	int		*num3;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	num3 = malloc(sizeof(int));
	if (num1 == NULL || num2 == NULL || num3 == NULL)
	{
		printf("Failed to allocate memory\n");
		return (1);
	}
	*num1 = 42;
	*num2 = 24;
	*num3 = 12;
	node1 = ft_lstnew(num1);
	node2 = ft_lstnew(num2);
	node3 = ft_lstnew(num3);
	if (node1 == NULL || node2 == NULL || node3 == NULL)
	{
		printf("Failed to create nodes\n");
		free(num1);
		free(num2);
		free(num3);
		return (1);
	}
	ft_lstadd_back(&node1, node2);
	ft_lstadd_back(&node1, node3);
	printf("Before deletion:\n");
	print_list(node1);
	ft_lstclear(&node1, del);
	printf("After deletion:\n");
	print_list(node1); 
		// This should not print anything because the list has been cleared
	return (0);
}
*/