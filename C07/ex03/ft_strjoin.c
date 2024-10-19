/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 22:37:37 by djoung            #+#    #+#             */
/*   Updated: 2024/08/28 19:21:51 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_len(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_put_value(char *join, char **strs, char *sep, int size)
{
	int	i;

	if (!join)
		return (NULL);
	join[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(join, strs[i]);
		if (i < size - 1)
			ft_strcat(join, sep);
		i++;
	}
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		sep_len;
	int		str_len;
	char	*join;

	str_len = 0;
	sep_len = 0;
	if (size <= 0)
	{
		join = (char *)malloc(1);
		join[0] = '\0';
		return (join);
	}
	i = 0;
	while (i < size)
	{
		str_len += ft_len(strs[i]);
		if (i < size - 1)
			sep_len += ft_len(sep);
		i++;
	}
	join = (char *)malloc(sizeof(char) * (str_len + sep_len + 1));
	join = ft_put_value(join, strs, sep, size);
	return (join);
}
