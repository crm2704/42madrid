/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:38:57 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 12:38:59 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include "libft.h"
#include <stdio.h>

void	print_node(void *content)
{
	int	*value;

	value = (int *)content;
	printf("Node value: %d\n", *value);
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
	ft_lstiter(node1, print_node);
	ft_lstclear(&node1, free);
	return (0);
}
*/