/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 02:01:19 by djoung            #+#    #+#             */
/*   Updated: 2024/08/30 18:08:32 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern int	ft_base_valid(char *base);
extern int	ft_putnbr_base(char ch, char *base);
extern int	ft_space_check(char str);
extern char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char	*ft_check_result(char *result, int sign)
{
	int		i;
	int		result_len;

	result_len = 0;
	while (result[result_len])
		result_len++;
	i = 0;
	if (sign == -1)
	{
		result[result_len] = '-';
		while (i < (result_len + 1) / 2)
		{
			ft_swap(&result[i], &result[result_len - i]);
			i++;
		}
	}
	else
	{
		while (i < result_len / 2)
		{
			ft_swap(&result[i], &result[result_len - 1 - i]);
			i++;
		}
	}
	return (result);
}

char	*ft_base_to(int nbr, char *base_to, char *base_result)
{
	int	base_len;
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	base_len = ft_base_valid(base_to);
	if (!(ft_base_valid(base_to)))
		return (0);
	if (nbr < 0)
	{
		sign = -1;
		nbr = -1 * nbr;
	}
	while (nbr >= base_len)
	{
		base_result[i] = base_to[nbr % base_len];
		nbr = nbr / base_len;
		i++;
	}
	base_result[i] = base_to[nbr % base_len];
	return (ft_check_result(base_result, sign));
}

char	*ft_inital_base(int n, char *base_to)
{
	char	*base_result;
	int		i;

	i = 0;
	base_result = (char *)malloc(sizeof(char) * 50);
	while (i < 50)
	{
		base_result[i] = '\0';
		i++;
	}
	return (ft_base_to(n, base_to, base_result));
}
