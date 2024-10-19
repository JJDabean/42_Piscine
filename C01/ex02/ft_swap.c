/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:44:34 by djoung            #+#    #+#             */
/*   Updated: 2024/08/13 04:57:05 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
int main()
{
	int num1 = 10;
	int num2 = 20;
	int *a1, *b1;

	a1 = &num1;
	b1 = &num2;
	
	printf("%d %d ", *a1, *b1);
	ft_swap(a1, b1);
	printf("%d %d", *a1, *b1);
	return (0);
}
*/
