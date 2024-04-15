/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oansoteg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 17:19:28 by oansoteg          #+#    #+#             */
/*   Updated: 2024/02/24 17:19:31 by oansoteg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_search_num(char *str)
{
	char	*buffer;
	int		end_fd;
	int		in;
	int		i;
	int		j;
	char	error[] = "Dict error\n";

	buffer = ft_read();
	end_fd = 0;
	in = 0;
	i = 0;
	while (buffer[i])
	{
		j = 0;
		if (str[0] == 1 || ft_len(str) == 1)
		{
			while (buffer[i] == str[j] && str[j] != '\0')
			{
				i++;
				j++;
				in = 1;
			}
			if (str[j] == '\0')
				return (ft_find_num(buffer, i));
			if (in == 1)
				i--;
		}
		// habria que hacer una condicion para buscar un numero mayor
		// que 19, en estos casos hay que usar la longitud del str para
		// saber si estamos en las decenas, centenas o unidades.
		// ej: 479 -> 1)4 2)exp10 3)70 4)9
		i++;
	}
	return (error);
}

char	*ft_read(void)
{
	char	*buffer;
	int		num_char;
	int		fd;

	num_char = ft_cont();
	buffer = (char *)malloc(num_char * sizeof(char));
	fd = open("../numbers.dict", 0);
	read(fd, buffer, num_char);
	return (buffer);
}

char	*ft_find_num(char *buffer, int i)
{
	char	str[255];
	int		num_found;
	int		j;

	num_found = 0;
	j = 0;
	while (num_found == 0)
	{
		while ((buffer[i] >= 'a' && buffer[i] <= 'z') || (buffer[i] >= 'A'
				&& buffer[i] <= 'Z'))
		{
			str[j] = buffer[i];
			j++;
			i++;
			num_found = 1;
		}
		i++;
	}
	str[j] = " ";
	return (str);
}

char	*rush(char *str)
{
	char	res[1024];
	char	wrt[4];
	int		l;
	int		i;
	int		num_d;
	int		j;

	l = ft_len(str) - 1;
	i = l;
	while (i >= 0)
	{
		// se entra aqui en el caso de que estemos en un numero que
		// dividido entre 10ˆî de un numero de un digito
		if (i % 3 == 0)
		{
			// se entra aqui en el caso de que el primer trio de numeros
			// a imprimir no tenga 3 numeros
			if (l - i < 3)
			{
				num_d = l - i;
				i -= 3 - (num_d + 1);
				j = 0;
				while (j < num_d + 1)
				{
					wrt[j] = str[l - (l - i)];
					j++;
					i++;
				}
			}
			else
			{
				j = 0;
				i -= 2;
				while (j < 3)
				{
					wrt[j] = str[l - i];
					j++;
					i++;
				}
			}
			write_num(wrt);
			find_exp(i);
		}
		i--;
	}
}
void	write_num(char *str)
{
	char	wrt[255] = ft_search_num(str);
	int		i;

	i = 0;
	while (wrt[i])
	{
		write(1, (wrt + i), 1);
		write(1, "\n", 1);
	}
}

void	find_exp(int n)
{
	char	*wrt[50];
	int		i;
	char	ans[255] = ft_search_num(wrt);

	i = 0;
	wrt[i] = '1';
	while (i < n - 1)
	{
		wrt[i] = '0';
	}
	write_num(ans);
}

int	ft_cont(void)
{
	char	buffer[1];

	int fd2, contador = 0;
	fd2 = open("numbers.dict", 0);
	if (fd2 == -1)
	{
		return (1);
	}
	while (read(fd2, buffer, 1) == 1)
	{
		contador++;
	}
	close(fd2);
	return (contador + 1);
}

int	ft_len(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}