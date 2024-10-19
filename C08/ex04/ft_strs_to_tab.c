/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 05:55:30 by djoung            #+#    #+#             */
/*   Updated: 2024/08/30 23:39:10 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *av)
{
	int	cnt;

	cnt = 0;
	while (av[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*cpy_src;
	int		i;

	i = 0;
	src_len = ft_strlen(src);
	cpy_src = (char *)malloc((src_len + 1) * sizeof(char));
	if (!cpy_src)
		return (NULL);
	while (src[i])
	{
		cpy_src[i] = src[i];
		i++;
	}
	cpy_src[i] = '\0';
	return (cpy_src);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*temp;
	t_stock_str	*stock;

	i = 0;
	temp = (t_stock_str *)malloc(sizeof(*temp) * (ac + 1));
	if (!temp)
		return (NULL);
	stock = temp;
	while (i < ac)
	{
		stock->size = ft_strlen(*av);
		stock->str = *av;
		stock->copy = ft_strdup(*av);
		i++;
		av++;
		stock++;
	}
	stock->str = 0;
	return (temp);
}
