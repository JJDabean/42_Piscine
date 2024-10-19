/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 04:39:50 by djoung            #+#    #+#             */
/*   Updated: 2024/08/13 19:28:05 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_flag(char c)
{
	if (!((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')
			|| (c >= '0' && c <= '9')))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	int		check;

	i = 0;
	check = 1;
	while (str[i])
	{
		if (ft_flag(str[i]))
			check = 1;
		else
		{
			if (check == 1 && str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] = str[i] - 32;
			}
			else if (check == 0 && str[i] >= 'A' && str[i] <= 'Z')
			{
				str[i] = str[i] + 32;
			}
			check = 0;
		}
		i++;
	}
	return (str);
}
