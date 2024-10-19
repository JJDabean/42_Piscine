/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 04:49:22 by djoung            #+#    #+#             */
/*   Updated: 2024/08/26 21:02:59 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ran_arr;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	ran_arr = (int *)malloc(sizeof(int) * (max - min));
	if (!ran_arr)
		return (0);
	while (min < max)
	{
		ran_arr[i] = min;
		min++;
		i++;
	}
	return (ran_arr);
}
