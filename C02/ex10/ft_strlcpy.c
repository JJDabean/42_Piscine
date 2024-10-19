/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:51:06 by djoung            #+#    #+#             */
/*   Updated: 2024/08/14 14:26:13 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_length(char *src)
{
	unsigned int	x;

	x = 0;
	while (src[x] != '\0')
	{
		x++;
	}
	return (x);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{	
	unsigned int	i;

	i = 0;
	if (size != 0)
	{
		while ((src[i] != '\0') && i + 1 < size)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_length(src));
}
