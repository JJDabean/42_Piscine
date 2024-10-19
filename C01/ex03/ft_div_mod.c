/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:59:11 by djoung            #+#    #+#             */
/*   Updated: 2024/08/11 20:19:33 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
int	main(void)
{
	int num1;
	int num2;
	int mod;
	int div;

	num1 = 10;
	num2 = 3;
	ft_div_mod(num1, num2, &div, &mod);
	printf("%d / %d = %d\n",num1, num2, div);
	printf("%d . %d = %d", num1, num2, mod);
}
*/
