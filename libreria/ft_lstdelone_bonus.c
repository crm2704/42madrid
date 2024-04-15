/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:09:36 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 12:09:38 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
/*
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
	t_list	*node1;
	t_list	*node2;

	num1 = malloc(sizeof(int));
	num2 = malloc(sizeof(int));
	if (num1 == NULL || num2 == NULL)
	{
		printf("Failed to allocate memory\n");
		return (1);
	}
	*num1 = 42;
	*num2 = 24;
	node1 = ft_lstnew(num1);
	node2 = ft_lstnew(num2);
	if (node1 == NULL || node2 == NULL)
	{
		printf("Failed to create nodes\n");
		free(num1);
		free(num2);
		return (1);
	}
	ft_lstadd_back(&node1, node2);
	printf("Before deletion:\n");
	print_list(node1);
	node1->next = NULL;  // Remove the reference to node2 in node1's next field
	ft_lstdelone(node2, del);
	printf("After deletion:\n");
	print_list(node1);
	ft_lstdelone(node1, del);
	return (0);
}
*/