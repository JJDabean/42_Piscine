/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taebkim <taebkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 20:57:50 by taebkim           #+#    #+#             */
/*   Updated: 2024/08/28 22:30:00 by taebkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

t_dict	g_dict;

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		print_dict_contents(DICT_FILE);
		return (0);
	}
	if (argc == 3)
	{
		if (!check_input(argv[2]))
			return (1);
		read_dict_from_file(argv[1]);
		ru(argv[2]);
	}
	else if (argc == 2)
	{
		if (!check_input(argv[1]))
			return (1);
		read_dict_from_file(DICT_FILE);
		ru(argv[1]);
	}
	else
		write_str(2, "Error\n");
	if (g_dict.size == 0)
		return (1);
	free_dict();
	return (0);
}
