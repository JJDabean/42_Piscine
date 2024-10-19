/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 23:52:24 by djoung            #+#    #+#             */
/*   Updated: 2024/08/30 12:55:12 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ru_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	word_count(char *str, char *sep)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 1;
	while (str[i])
	{
		if (ft_ru_sep(str[i], sep)
			&& (i == 0 || !ft_ru_sep(str[i + 1], sep)))
			cnt++;
		i++;
	}
	return (cnt);
}

char	*final_str(char *str, char *sep)
{
	int		str_len;
	int		i;
	char	*new_str;

	str_len = 0;
	while (str[str_len] && !ft_ru_sep(str[str_len], sep))
		str_len++;
	new_str = (char *)malloc(sizeof(char) * str_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

void	ft_fill_result(char **only_str, char *str, char *sep)
{
	int	i;
	int	str_i;

	i = 0;
	str_i = 0;
	while (str[i])
	{
		while (ft_ru_sep(str[i], sep))
			i++;
		if (str[i] && !ft_ru_sep(str[i], sep))
		{
			only_str[str_i] = final_str(&str[i], sep);
			str_i++;
		}
		while (str[i] && !ft_ru_sep(str[i], sep))
			i++;
	}
	only_str[str_i] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	sep[256];
	char	**only_str;
	int		i;

	i = 0;
	while (charset[i])
	{
		sep[i] = charset[i];
		i++;
	}
	sep[i] = '\0';
	only_str = (char **)malloc(sizeof(char *) * (word_count(str, sep) + 1));
	if (!only_str)
		return (NULL);
	ft_fill_result(only_str, str, sep);
	return (only_str);
}
