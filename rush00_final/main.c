/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RUSHddh <rush00ddh@42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:53:55 by djoung            #+#    #+#             */
/*   Updated: 2024/08/14 18:03:17 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern void	rush(int x, int y);
extern int	ft_atoi(const char *s);

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	rush(ft_atoi(argv[1]), ft_atoi(argv[2]));
	return (0);
}

int	ft_atoi(const char *s)
{
	int	n;
	int	minus_flag;

	if (*s == '-')
	{
		minus_flag = -1;
		s++;
	}
	else
		minus_flag = 1;
	n = 0;
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		n = 10 * n + minus_flag * (*s - '0');
		s++;
	}
	return (n);
}
