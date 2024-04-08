/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:44:54 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 12:44:55 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newnext;
	void	*transformed_content;

	new = NULL;
	newnext = NULL;
	while (lst != NULL)
	{
		transformed_content = f(lst->content);
		if (transformed_content == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		newnext = ft_lstnew(transformed_content);
		if (newnext == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, newnext);
		lst = lst->next;
	}
	return (new);
}
/*
#include "libft.h"
#include <stdio.h>

void	*double_value(void *content)
{
	int	*value;
	int	*new_value;

	value = (int *)content;
	new_value = malloc(sizeof(int));
	if (new_value == NULL)
	{
		return (NULL);
	}
	*new_value = *value * 2;
	return (new_value);
}

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
	t_list	*new_list;

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
	printf("Original list:\n");
	ft_lstiter(node1, print_node);
	new_list = ft_lstmap(node1, double_value, free);
	if (new_list == NULL)
	{
		printf("Failed to create new list\n");
		ft_lstclear(&node1, free);
		return (1);
	}
	printf("New list:\n");
	ft_lstiter(new_list, print_node);
	ft_lstclear(&node1, free);
	return (0);
}
*/