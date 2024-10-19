/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:02:15 by djoung            #+#    #+#             */
/*   Updated: 2024/08/23 18:13:15 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		index = 0;
	else if (index == 1)
		index = 1;
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
	return (index);
}
