/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 01:00:18 by djoung            #+#    #+#             */
/*   Updated: 2024/08/30 18:22:06 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

extern void	ft_swap(char *a, char *b);
extern char	*ft_check_result(char *result, int sign);
extern char	*ft_base_to(int nbr, char *base_to, char *base_result);
extern char	*ft_inital_base(int n, char *base_to);

int	ft_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] >= 9 && (base[i] <= 13 || base[i] == 32))
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

int	ft_putnbr_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_space_check(char str)
{
	if (str >= 9 && (str <= 13 || str == 32))
		return (1);
	else
		return (0);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	int		sign;
	char	value;

	sign = 1;
	n = 0;
	if (!ft_base_valid(base_from))
		return (NULL);
	while (ft_space_check(*nbr))
		nbr++;
	while (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	while (*nbr)
	{
		value = ft_putnbr_base(*nbr, base_from);
		if (value == -1)
			return (ft_inital_base(n, base_to));
		n = n * ft_base_valid(base_from) + sign * value;
		nbr++;
	}
	return (ft_inital_base(n, base_to));
}
