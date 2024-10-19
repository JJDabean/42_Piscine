/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:13:15 by djoung            #+#    #+#             */
/*   Updated: 2024/08/28 06:56:20 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base)
{
	int		n;
	int		sign;
	char	value;

	sign = 1;
	n = 0;
	if (!ft_base_valid(base))
		return (0);
	while (ft_space_check(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str)
	{
		value = ft_putnbr_base(*str, base);
		if (value == -1)
			return (n);
		n = n * ft_base_valid(base) + sign * (value);
		str++;
	}
	return (n);
}
