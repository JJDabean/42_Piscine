/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: RUSHddh <rush00ddh@42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 17:53:55 by djoung            #+#    #+#             */
/*   Updated: 2024/08/14 18:06:11 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define VERTEX1 '/'
#define VERTEX2 '\\'
#define EDGE '*'

int	ft_putchar(int c);

void	print_width(int n, char x, char y, char z)
{
	int	i;

	ft_putchar(x);
	if (n == 1)
	{
		ft_putchar('\n');
		return ;
	}
	i = 0;
	while (i++ < n - 2)
		ft_putchar(y);
	ft_putchar(z);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x <= 0 || y <= 0)
		return ;
	print_width(x, VERTEX1, EDGE, VERTEX2);
	if (y == 1)
		return ;
	i = 0;
	while (i++ < y - 2)
		print_width(x, EDGE, ' ', EDGE);
	print_width(x, VERTEX2, EDGE, VERTEX1);
}
