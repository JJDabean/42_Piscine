/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 03:20:06 by djoung            #+#    #+#             */
/*   Updated: 2024/08/22 04:16:19 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *src)
{
	int	cnt;

	cnt = 0;
	while (*src)
	{
		cnt++;
		src++;
	}
	return (cnt);
}

char	*ft_strdup(char *src)
{
	int		src_len;
	char	*cpy_src;
	int		i;

	i = 0;
	src_len = ft_len(src);
	cpy_src = (char *)malloc(src_len + 1 * sizeof(char));
	if (!(cpy_src))
		return (0);
	while (src[i])
	{
		cpy_src[i] = src[i];
		i++;
	}
	cpy_src[i] = '\0';
	return (cpy_src);
}
