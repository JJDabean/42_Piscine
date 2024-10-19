/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:47:07 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 21:00:11 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	process_number(char *buffer, int *i, int *entry_index)
{
	char	num_str[50];
	int		num_i;

	num_i = 0;
	while (buffer[*i] >= '0' && buffer[*i] <= '9' && num_i < 49)
		num_str[num_i++] = buffer[(*i)++];
	num_str[num_i] = '\0';
	g_dict.entries[*entry_index].number = ft_atoul(num_str);
}

void	process_word(char *buffer, int *i, int *entry_index)
{
	int	word_start;
	int	j;

	word_start = *i;
	while (buffer[*i] != '\n' && *i < BUFF_SIZE)
		(*i)++;
	if (*i > word_start)
	{
		g_dict.entries[*entry_index].word = malloc(*i - word_start + 1);
		if (g_dict.entries[*entry_index].word)
		{
			j = 0;
			while (j < *i - word_start)
			{
				g_dict.entries[*entry_index].word[j] = buffer[word_start + j];
				j++;
			}
			g_dict.entries[*entry_index].word[j] = '\0';
			(*entry_index)++;
		}
	}
}

int	process_hundreds(int extra, char *nb, int i)
{
	if (extra == 3 && nb[i] != '0')
	{
		write_number_word(nb[i] - '0');
		write(1, " ", 1);
		write_number_word(100);
		write(1, " ", 1);
	}
	return (i + 1);
}

int	process_tens(int extra, char *nb, int i)
{
	if (extra == 2 && nb[i] == '1')
	{
		write_number_word((nb[i] - '0') * 10 + (nb[i + 1] - '0'));
		write(1, " ", 1);
		return (i + 1);
	}
	else if (extra == 2 && nb[i] != '0')
	{
		write_number_word((nb[i] - '0') * 10);
		if (nb[i + 1] != '0')
			write(1, "-", 1);
		else
			write(1, " ", 1);
	}
	return (i + 1);
}

int	process_ones(int extra, char *nb, int i)
{
	if (extra == 1 && (nb[i - 1] != '1' || i == 0) && nb[i] != '0')
	{
		write_number_word(nb[i] - '0');
		write(1, " ", 1);
	}
	return (i + 1);
}
