/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 20:22:19 by djoung            #+#    #+#             */
/*   Updated: 2024/08/13 04:56:17 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = *a / *b;
	tmp_b = *a % *b;
	*a = tmp_a;
	*b = tmp_b;
}
/*
int main(void)
{
	int a;
	int b;

	a = 8;
	b = 3;

	printf("a : %d, b : %d\n", a, b);

	ft_ultimate_div_mod(&a, &b);

	printf("result : %d, remain : %d\n", a, b);
}
*/
