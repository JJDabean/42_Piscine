/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:46:32 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 22:47:39 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

unsigned long long	ft_atoul(char *str)
{
	unsigned long long	result;
	int					i;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	write_str(int fd, char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}

void	write_number_word(unsigned long long number)
{
	char	*word;

	word = find_word(number);
	if (word)
		write_str(1, word);
}

void	write_power(int danwe)
{
	unsigned long long	power;
	int					j;

	power = 1;
	j = 0;
	while (j < danwe * 3)
	{
		power *= 10;
		j++;
	}
	write_number_word(power);
	write(1, " ", 1);
}

void	print_dict_contents(const char *filename)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write_str(2, "Dict Error\n");
		return ;
	}
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFF_SIZE);
		if (bytes_read > 0)
			write(1, buffer, bytes_read);
	}
	if (bytes_read == -1)
	{
		write_str(2, "Dict Error\n");
	}
	close(fd);
}
