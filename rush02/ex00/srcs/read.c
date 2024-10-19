/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:47:45 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 22:47:56 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	read_dict_entry(char *buffer, int *i, int *entry_index)
{
	process_number(buffer, i, entry_index);
	while (buffer[*i] == ' ' || buffer[*i] == ':')
		(*i)++;
	process_word(buffer, i, entry_index);
	(*i)++;
}

void	read_dict_from_file(char *filename)
{
	int		fd;
	char	buffer[BUFF_SIZE];
	int		bytes_read;
	int		i;
	int		entry_index;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write_str(2, "Dict Error");
		return ;
	}
	bytes_read = read(fd, buffer, BUFF_SIZE);
	if (bytes_read <= 0)
	{
		write_str(2, "Dict Error");
		close(fd);
		return ;
	}
	i = 0;
	entry_index = 0;
	while (i < bytes_read && entry_index < MAX_ENTRIES)
		read_dict_entry(buffer, &i, &entry_index);
	g_dict.size = entry_index;
	close(fd);
}

void	free_dict(void)
{
	int	i;

	i = 0;
	while (i < g_dict.size)
	{
		free(g_dict.entries[i].word);
		i++;
	}
}

char	*find_word(unsigned long long number)
{
	int	i;

	i = 0;
	while (i < g_dict.size)
	{
		if (g_dict.entries[i].number == number)
			return (g_dict.entries[i].word);
		i++;
	}
	return (NULL);
}
