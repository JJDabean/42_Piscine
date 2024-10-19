/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 03:48:34 by djoung            #+#    #+#             */
/*   Updated: 2024/08/28 06:59:03 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	num;

	base_len = (unsigned int)ft_base_valid(base);
	if (!(ft_base_valid(base)))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		num = (unsigned int)(-nbr);
	}
	else
		num = (unsigned int)nbr;
	if (num >= base_len)
		ft_putnbr_base(num / base_len, base);
	ft_putchar(base[num % base_len]);
}
