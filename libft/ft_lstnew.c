/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:24:50 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/07 19:25:03 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	ans = malloc(2 * sizeof(t_list));
	if (ans != NULL)
	{
		ans->content = content;
		ans->next = NULL;
	}
	return (ans);
}
/*
int main()
{
    int num = 42;
    t_list *node = ft_lstnew(&num);
    if (node != NULL)
    {
        printf("Node content: %d\n", *(int*)node->content);
    }
    else
    {
        printf("Failed to create node\n");
    }
    free(node);
    return 0;
}
*/