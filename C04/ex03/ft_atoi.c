/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:22:36 by djoung            #+#    #+#             */
/*   Updated: 2024/08/24 17:28:52 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_check(char str)
{
	if (str >= 9 && (str <= 13 || str == 32))
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	n;
	int	sign;

	sign = 1;
	n = 0;
	while (ft_str_check(*str))
	{
		str++;
	}
	while (*str == '-' || *str == '+')
	{
		if (*(str++) == '-')
			sign *= -1;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			n = n * 10 + sign * (*str - '0');
		else
			return (n);
		str++;
	}
	return (n);
}
