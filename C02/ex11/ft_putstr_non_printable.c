/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 19:32:21 by djoung            #+#    #+#             */
/*   Updated: 2024/08/14 20:40:34 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexa(unsigned char c)
{
	char	*digits;

	digits = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(digits[c / 16]);
	ft_putchar(digits[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned char	ch;

	i = 0;
	while (str[i])
	{
		ch = (unsigned char)str[i];
		if (ch < 32 || ch == 127)
			ft_hexa(ch);
		else
			ft_putchar(str[i]);
		i++;
	}
}
