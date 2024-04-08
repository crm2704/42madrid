/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:50:54 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/08 11:50:57 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
#include "libft.h"

int main()
{
    int num1 = 42;
    int num2 = 24;
    int num3 = 12;

    t_list *node1 = ft_lstnew(&num1);
    t_list *node2 = ft_lstnew(&num2);
    t_list *node3 = ft_lstnew(&num3);

    if (node1 == NULL || node2 == NULL || node3 == NULL)
    {
        printf("Failed to create nodes\n");
        return 1;
    }

    ft_lstadd_front(&node1, node2);
    ft_lstadd_front(&node2, node3);

    t_list *last_node = ft_lstlast(node1);
    if (last_node != NULL)
    {
        int *last_value = (int *)last_node->content;
        printf("Last node value: %d\n", *last_value);
    }

    t_list *tmp;
    while (node1 != NULL)
    {
        tmp = node1;
        node1 = node1->next;
        free(tmp);
    }

    return 0;
}
*/