/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:21:01 by djoung            #+#    #+#             */
/*   Updated: 2024/09/01 19:00:18 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	asc;
	int	desc;
	int	i;

	i = 0;
	asc = 0;
	desc = 0;
	while (tab[i] && i < length)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			desc++;
		if ((*f)(tab[i], tab[i + 1] <= 0))
			asc++;
		i++;
	}
	if (desc == i || asc == i)
		return (1);
	return (0);
}

#include <stdio.h>

int		ft_is_sort(int *tab, int length, int(*f)(int, int));

int		ft_compare(int n1, int n2)
{
	return (n1 - n2);
}

int main(void)
{
	int sorted1[] = {10, 30, 56, 1235, 6546, 10345};
	int sorted2[] = {7, 7, 7, 7, 6, 6, 6, 6, 5, 5, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1};
	int not_sorted1[] = {10, 30, 56, 3, 10345, 1235, 6546};
	int not_sorted2[] = {6546, 1235, 10345, 3, 56, 30, 10};
	printf("%d\n", ft_is_sort(sorted1, 6, &ft_compare));
	printf("%d\n", ft_is_sort(sorted2, 26, &ft_compare));
	printf("%d\n", ft_is_sort(not_sorted1, 7, &ft_compare));
	printf("%d\n", ft_is_sort(not_sorted2, 7, &ft_compare));
	return (0);
}

