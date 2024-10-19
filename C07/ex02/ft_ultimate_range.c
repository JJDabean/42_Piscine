/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:38:20 by djoung            #+#    #+#             */
/*   Updated: 2024/08/28 19:21:23 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ran_arr;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	ran_arr = (int *)malloc(sizeof(int) * (max - min));
	if (!ran_arr)
		return (-1);
	while (max > min)
	{
		ran_arr[i] = min;
		min++;
		i++;
	}
	*range = ran_arr;
	return (i);
}
