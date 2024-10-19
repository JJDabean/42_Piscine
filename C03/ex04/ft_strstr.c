/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 01:32:20 by djoung            #+#    #+#             */
/*   Updated: 2024/08/17 01:10:04 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare(char *str, char *find)
{
	while (*find != '\0')
	{
		if (*str != *find)
			return (0);
		str++;
		find++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		if ((*str == *to_find) && ft_compare(str, to_find))
		{
			return (str);
		}
		str++;
	}
	return (0);
}
