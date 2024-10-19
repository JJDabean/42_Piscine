/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 21:00:23 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 22:11:35 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	hundred_print(int extra, char *nb, int i)
{
	while (extra > 0)
	{
		if (extra == 3)
			i = process_hundreds(extra, nb, i);
		else if (extra == 2)
			i = process_tens(extra, nb, i);
		else
			i = process_ones(extra, nb, i);
		extra--;
	}
	return (i);
}

int	is_triple_zero(char *nb, int i)
{
	return (nb[i - 3] == '0' && nb[i - 2] == '0' && nb[i - 1] == '0');
}

void	ft_print(int danwe, int nameoji, char *nb)
{
	int	i;

	i = 0;
	while (0 <= danwe)
	{
		i = hundred_print(nameoji, nb, i);
		if (1 <= danwe)
		{
			if (!is_triple_zero(nb, i))
				write_power(danwe);
			nameoji = 3;
		}
		danwe--;
	}
	write(1, "\n", 1);
}
