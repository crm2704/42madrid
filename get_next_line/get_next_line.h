/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:44:24 by crubio            #+#    #+#             */
/*   Updated: 2024/04/23 16:44:26 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*get_next_line(int fd);
char				*ft_next_line(t_list *root, ssize_t i);
void				ft_freemem(t_list *start);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif
