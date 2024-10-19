/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solutions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:01:21 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 22:24:42 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

char	*zeros_handler(char *str)
{
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	return (str);
}

void	ru(char *nb)
{
	int	danwe;
	int	nameoji;
	int	i;

	nb = zeros_handler(nb);
	i = 0;
	while (nb[i])
		i++;
	danwe = ((i - 1) / 3);
	nameoji = (i % 3);
	if (nameoji == 0)
		nameoji = 3;
	if ((danwe == 0) && (nameoji == 1) && (nb[0] == '0'))
	{
		write_number_word(0);
		write(1, "\n", 1);
		return ;
	}
	if (danwe > 12)
	{
		write_str(2, "Dict Error\n");
		return ;
	}
	ft_print(danwe, nameoji, nb);
}

int	check_input(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] < '0' || input[i] > '9')
		{
			write_str(1, "Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}
