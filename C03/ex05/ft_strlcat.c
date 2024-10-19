/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 01:34:59 by djoung            #+#    #+#             */
/*   Updated: 2024/08/17 01:13:43 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned	int	ft_length(char *src)
{
	unsigned int	x;

	x = 0;
	while (src[x] != '\0')
		x++;
	return (x);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	dest_len;
	unsigned int	i;

	i = 0;
	src_len = ft_length(src);
	dest_len = ft_length(dest);
	if (size <= dest_len)
		return (size + src_len);
	while (src[i] && (i + dest_len + 1) < size)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (src_len + dest_len);
}
