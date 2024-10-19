/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 09:27:33 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 22:31:53 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 4096
# define MAX_ENTRIES 100
# define DICT_FILE "numbers.dict"

typedef struct s_dict_entry
{
	unsigned long long	number;
	char				*word;
}						t_dict_entry;

typedef struct s_dict
{
	t_dict_entry		entries[MAX_ENTRIES];
	int					size;
}						t_dict;

extern t_dict			g_dict;

unsigned long long		ft_atoul(char *str);
void					write_str(int fd, char *str);
void					write_number_word(unsigned long long number);
void					write_power(int danwe);
void					print_dict_contents(const char *filename);

int						hundred_print(int extra, char *nb, int i);
void					ft_print(int danwe, int nameoji, char *nb);

void					process_number(char *buffer, int *i, int *entry_index);
void					process_word(char *buffer, int *i, int *entry_index);
int						process_hundreds(int extra, char *nb, int i);
int						process_tens(int extra, char *nb, int i);
int						process_ones(int extra, char *nb, int i);

void					read_dict_entry(char *buffer, int *i, int *entry_index);
void					read_dict_from_file(char *filename);
void					free_dict(void);
char					*find_word(unsigned long long number);

void					ru(char *nb);

int						check_input(char *input);

#endif
