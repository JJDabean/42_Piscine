/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscrapper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoung <djoung@student.42gyeongsan.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:11:28 by djoung            #+#    #+#             */
/*   Updated: 2024/08/21 20:14:23 by djoung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define N 4 // 보드 크기

int board[N][N]; // 내부 보드 (건물의 층수를 적는 사각형)
int clues[4][N]; // 상, 하, 좌, 우 순서로 단서 저장 (사각형 가장자리에 있는 보이는 층수)

// 숫자를 놓을 수 있는지 확인하는 함수 (건물의 층수를 쓰느 사각형)
int is_valid(int row, int col, int num) {
    int i = 0;
    while (i < N) {
        // 같은 행이나 열에 같은 수가 있으면 안됨
        if (board[row][i] == num || board[i][col] == num)
            return 0;
        i++;
    }
    return 1;
}

// 내부 사각형에 들어있는 숫자들을 채우는 함수
int count_visible_buildings(int arr[N]) {
    int count = 1;
    int max_height = arr[0];
    int i = 1;
    while (i < N) {
        // 이전 최대 높이보다 높은 건물을 발견하면 카운트 증가
        if (arr[i] > max_height) {
            count++;
            max_height = arr[i];
        }
        i++;
    }
    return count;
}

// 현재 내부 사각형의 상태가 모든 조건을 만족하는지 확인하는 함수
int check_clues() {
    int temp[N];
    int row, col;

    col = 0;
    while (col < N) {
        row = 0;
        while (row < N) {
            temp[row] = board[row][col];
            row++;
        }
        // 위에서 아래로 보이는 건물 수
        if (count_visible_buildings(temp) != clues[0][col]) return 0;
        row = 0;
        while (row < N) {
            temp[row] = board[N-1-row][col];
            row++;
        }
       // 아래에서 위로 보이는 건물 수 체크
        if (count_visible_buildings(temp) != clues[1][col]) return 0;
        col++;
    }

    row = 0;
    while (row < N) {
        col = 0;
        while (col < N) {
            temp[col] = board[row][col];
            col++;
        }
         // 왼쪽에서 오른쪽으로 보이는 건물 수 체크
        if (count_visible_buildings(temp) != clues[2][row]) return 0;
        col = 0;
        while (col < N) {
            temp[col] = board[row][N-1-col];
            col++;
        }
       //오른쪽에서 왼쪽으로 보이는 건물 수 체크
        if (count_visible_buildings(temp) != clues[3][row]) return 0;
        row++;
    }

    return 1;
}
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
