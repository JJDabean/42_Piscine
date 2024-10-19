/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:02:11 by djoung            #+#    #+#             */
/*   Updated: 2024/08/21 20:10:58 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#define A_SIZE 4

// 백트래킹 사용
int solve(int row, int col) {
    if (row == N)
        return check_clues();

    if (col == N)
        return solve(row + 1, 0);

    int num = 1;
    while (num <= N) {
        if (is_valid(row, col, num)) {
            board[row][col] = num;
            if (solve(row, col + 1))
                return 1;
            board[row][col] = 0;
        }
        num++;
    }
    return 0;
}

void print_board() {
    int i = 0, j;
    char buffer[3];
    while (i < N) {
        j = 0;
        while (j < N) {
            buffer[0] = board[i][j] + '0';
            buffer[1] = ' ';
            buffer[2] = '\0';
            write(1, buffer, 2);
            j++;
        }
        write(1, "\n", 1);
        i++;
    }
}

void	ft_input(char **argv)
{
	char *input = argv[1];
    int i = 0, j = 0, k = 0;
    while (input[i] != '\0') {
        if (input[i] >= '1' && input[i] <= '4') {
            clues[j][k] = input[i] - '0';
            k++;
            if (k == N) {
                j++;
                k = 0;
            }
            if (j == 4) break;
        }
        i++;
    }
    if (j != 4 || k != 0) {
        write(1, "Error\n", 6);
        return 1;
    }
    if (solve(0, 0)) {
        print_board();
    } else {
        write(1, "Error\n", 6);
    }
}



int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	else
		ft_input(argv[1]);
}



