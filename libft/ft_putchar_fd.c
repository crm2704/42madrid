/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crm2704 <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:33:30 by crm2704           #+#    #+#             */
/*   Updated: 2024/04/05 22:33:31 by crm2704          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
    if(fd != -1)
        write(fd, &c, 1);
}
/*
#include <fcntl.h>
#include "libft.h"

int main()
{
    int fd = open("testfile.txt", O_WRONLY | O_CREAT, 0644);
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_putchar_fd('A', fd);
    close(fd);
    return 0;
}
*/