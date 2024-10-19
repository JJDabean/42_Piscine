/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:11:56 by djoung            #+#    #+#             */
/*   Updated: 2024/08/20 23:51:15 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_ru_prime(int nb)
{
	int	n;

	n = 2;
	if (nb <= 1 || nb >= 2147483647)
		return (0);
	else if (nb == 2)
		return (1);
	while (n * n <= nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}

int	ft_is_prime(int nb)
{
	if (ft_ru_prime(nb))
		return (1);
	else
		return (0);
}
