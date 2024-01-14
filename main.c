#include<stdlib.h>
#include<stdio.h>
#include"heap.h"
#include"input.h"
#include"display.h"

// tracks the number of solutions found
int solution_nr;
// store the values added to the board coordinates
// of the knight's position for each move
int x[8] = { -2, -1,  1,  2,  2,  1, -1, -2 };
int y[8] = {  1,  2,  2,  1, -1, -2, -2, -1 };

// returns 1 if the square with coordinates (i, j) is 
// within the borders of the chessboard, or 0 if not
int is_on_board(int, int, int, int);
// returns 1 if the square with coordinates (i, j) is 
// free, or 0 if it has already been occupied once
int is_free(int**, int, int, int);
// searches for solutions to the Knight's Tour problem
void search_4_solutions(int**, int, int, int, int);

int main(void) {
	int n, i, j, action;

	do {
		solution_nr = 0;
		printf("Given a %sN%s x %sN%s empty board with the knight placed on the "
			"square with the (%si%s, %sj%s) coordinates. Moving according to the "
			"rules of chess, the knight must visit each square exactly once. For "
			"reference, the coordinates (1,1) represent the position of the first "
			"left square.\n\n", ansi(CYA), ansi(RESET), ansi(CYA), ansi(RESET),
			ansi(GRE), ansi(RESET), ansi(YEL), ansi(RESET));

		n = get_input("%sN (size) = %s", SIZE, 3);
		i = get_input("%si coordinate = %s", I_COOR, n);
		j = get_input("%sj coordinate = %s", J_COOR, n);

		int** board = allocate_matrix(n);

		search_4_solutions(board, n, i, j, 1);
		if (!solution_nr) printf("%sNo solutions were found!%s%s%s\n\n\n",
			ansi(ONOFF_RED), ansi(RESET), ansi(UP1LN), ansi(CLRLN));

		free_matrix(board, n);
	} while (action = get_input("Enter 0 to exit / 1 to try again : ", ACTION, 1));

	return EXIT_SUCCESS;
}

int is_on_board(int i, int j, int k, int n) {
	return (i + x[k] >= 0) && (i + x[k] < n) && (j + y[k] >= 0) && (j + y[k] < n);
}

int is_free(int** board, int i, int j, int k) { return !board[i + x[k]][j + y[k]]; }

void search_4_solutions(int** board, int n, int i, int j, int position_nr) {
	board[i][j] = position_nr;

	for (int k = 0; k < 8; k++) {
		if (is_on_board(i, j, k, n) && is_free(board, i, j, k)) {
			search_4_solutions(board, n, i + x[k], j + y[k], position_nr + 1);
		}
	}
	if (position_nr == n * n) {
		solution_nr++;
		print_solution(board, n, solution_nr);
	}
	board[i][j] = 0;
	position_nr--;
}