/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:44:14 by crubio            #+#    #+#             */
/*   Updated: 2024/04/23 16:44:16 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(t_list *root, ssize_t pos, ssize_t BUFFER_SIZE)
{
	char			*res;
	static ssize_t	temp;
	ssize_t			i;
	int				found;
	char			*sobra;
	t_list			*del;

	found = 0;
	temp = 0;
	res = (char *)malloc((pos - temp + 1) * sizeof(char));
	node = 0;
	del = root;
	while (root != NULL && found == 0)
	{
		root->content = (char *)root->content;
		while ((i > temp && i < pos) && found == 0)
		{
			res[i] = root->content[i];
			if (res[i] == '\n')
				found = 1;
			else
			{
				i++;
				temp++;
			}
		}
		if (found == 0)
		{
			root = root->next;
			pos -= BUFFER_SIZE;
			temp -= BUFFER_SIZE;
		}
	}
	while (root->content[i])
		sobra[i++] = root->content[i++];
	ft_freemem(del);
	ft_lstadd_back(&root, sobra);
	return (res);
}

void	ft_freemem(t_list *root)
{
	t_list	*tmp;

	while (root != NULL)
	{
		tmp = root;
		root = root->next;
		free(tmp);
	}
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ans;

	ans = malloc(sizeof(t_list));
	if (ans != NULL)
	{
		ans->content = content;
		ans->next = NULL;
	}
	return (ans);
}

static t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

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
