#include<stdlib.h>
#include<stdio.h>
#include"heap.h"
#include"input.h"
#include"display.h"

int solution_nr = 0;

// arrays with the values added to the x and y coordinates
// of the knight's position for each move
int x[8] = { -2, -1,  1,  2,  2,  1, -1, -2 };
int y[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };

// this function returns 1 if the square with coordinates (i, j) is
// within the chessboard's boarders, or 0 if it is outside of them
int is_on_board(int, int, int, int);

// this function returns 1 if the square with coordinates (i, j) 
// is free, or 0 if it has already been occupied once
int is_free(int**, int, int, int);

// this function finds solutions for the Knight's Tour problem
void find_solutions(int**, int, int, int, int);

int main(void) {
	int n, i, j;

	printf("Given a \x1b[36mN\x1b[0m x \x1b[36mN\x1b[0m empty board with "
		"the knight placed on the square with the (\x1b[32mi\x1b[0m, "
		"\x1b[33mj\x1b[0m) coordinates. Moving according to the rules "
		"of chess, the knight must visit each square exactly once.\n\n");

	n = read_var("\x1b[36mN (size) = \x1b[0m", SIZE, 3);
	i = read_var("\x1b[32mi coordinate = \x1b[0m", POSITION, n);
	j = read_var("\x1b[33mj coordinate = \x1b[0m", POSITION, n);

	int** matrix = allocate_matrix(n);

	find_solutions(matrix, n, i, j, 1);
	if (!solution_nr) printf("\x1b[5;31mNu au fost gasite solutii!\x1b[0m\n");
	else printf("\x1b[1A\x1b[2K");

	free_matrix(matrix, n);
	return EXIT_SUCCESS;
}

int is_on_board(int i, int j, int k, int n) {
	return (i + x[k] >= 0) && (i + x[k] < n) && (j + y[k] >= 0) && (j + y[k] < n);
}

int is_free(int** matrix, int i, int j, int k) {
	return !matrix[i + x[k]][j + y[k]];
}

void find_solutions(int** matrix, int n, int i, int j, int contor) {
	int flag = 0;

	matrix[i][j] = contor;
	for (int k = 0; k < 8; k++) {
		if (is_on_board(i, j, k, n) && is_free(matrix, i, j, k)) {
			find_solutions(matrix, n, i + x[k], j + y[k], contor + 1);
			flag = 1;
		}
	}
	if (flag == 0 && contor == n * n) {
		solution_nr++;
		display_matrix(matrix, n, solution_nr);
	}
	matrix[i][j] = 0; contor--;
}