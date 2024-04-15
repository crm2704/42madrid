/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crubio <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 13:17:27 by crubio            #+#    #+#             */
/*   Updated: 2024/02/21 13:14:26 by crubio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (str[0] >= 97 && str[0] <= 122)
		str[0] = str[0] - 32;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122 && !((str[i - 1] >= 48 && str[i
						- 1] <= 57) || (str[i - 1] >= 97 && str[i - 1] <= 122)
				|| (str[i - 1] >= 65 && str[i - 1] <= 90)))
			str[i] = str[i] - 32;
		else if (str[i] >= 65 && str[i] <= 90 && ((str[i - 1] >= 48 && str[i
						- 1] <= 57) || (str[i - 1] >= 97 && str[i - 1] <= 122)
				|| (str[i - 1] >= 65 && str[i - 1] <= 90)))
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

/*int	main(void)
{
	char	str[] = "holA, como estas ? iuaAOADaodan";
	char	*res;

	res = ft_strcapitalize(str);
	printf("%s\n", res);
	return (0);
}*/
