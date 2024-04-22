#include<stdio.h>
#include<stdlib.h>
#include"display.h"
#include"input.h"
#include"heap.h"

int max_digits;
int chars_per_row;

// the size of the board
int n;

// the minimum board size required to complete a knight's tour
int min_board_size = 4;

// the number of solutions found
int solution_nr;

// stores the offsets for the knight's moves
struct { int x; int y; } offset[8] = { {-2, 1}, {-1, 2},
 {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1} };

// returns 1 if the square with coordinates (i, j) is within
// the borders of the chessboard, else returns 0
int is_on_board(int, int, int);

// returns 1 if the square with coordinates (i, j)
// hasn't been occupied, else returns 0
int is_free(int**, int, int, int);

// returns 1 if a solution has been found (i.e. all
// squares have been checked once), else returns 0
int solution_found(int);

// searches for solutions to the knight's tour problem
void search_4_solutions(int**, int, int, int);

int main(void) {
	int i, j, action;
	int runs_in_terminal;

#ifdef _WIN32
	runs_in_terminal = (_isatty(_fileno(stdout))) ? 1 : 0;
#else
	runs_in_terminal = (isatty(fileno(stdout))) ? 1 : 0;
#endif

	do {
		if (runs_in_terminal) printf("\n");
		printf("Given a %sN%s x %sN%s empty board with the knight placed on the "
			"square with the (%si%s, %sj%s) coordinates.\n", ansi[CYA], ansi[RESET],
			ansi[CYA], ansi[RESET], ansi[GRE], ansi[RESET], ansi[YEL], ansi[RESET]);
		printf("Moving according to the rules of chess, the knight must visit each "
			"square exactly once.\n\n");

		n = get_valid_input(SIZE, "N (size) = ", min_board_size);
		printf("The values of %si%s and %sj%s can range from 0 to %d, inclusive!\n\n",
			ansi[GRE], ansi[RESET], ansi[YEL], ansi[RESET], n-1);
		i = get_valid_input(I_COORD, "i coordinate = ", n);
		j = get_valid_input(J_COORD, "j coordinate = ", n);

		max_digits = how_many_digits(n * n);
		chars_per_row = extra_chars + n * (min_div_distance + max_digits);

		int** board = allocate_matrix(n);

		solution_nr = 0;
		search_4_solutions(board, i, j, 1);
		if (!solution_nr) printf("%sNo solutions were found!%s%s%s\n\n\n",
			ansi[ONOFF_RED], ansi[RESET], ansi[UP1LN], ansi[CLRLN]);

		free_matrix(board, n);
	} while (action = get_valid_input(ACTION, "Enter 0 to exit / 1 to try again : ", 1));
	return EXIT_SUCCESS;
}

int is_on_board(int i, int j, int k) {
	return (i + offset[k].x >= 0) && (i + offset[k].x < n)
		&& (j + offset[k].y >= 0) && (j + offset[k].y < n);
}

int is_free(int** board, int i, int j, int k) {
	return !board[i + offset[k].x][j + offset[k].y];
}

int solution_found(int position_nr) {
	return position_nr == n * n;
}

void search_4_solutions(int** board, int i, int j, int position_nr) {
	board[i][j] = position_nr;

	for (int k = 0; k < 8; k++)
		if (is_on_board(i, j, k) && is_free(board, i, j, k))
			search_4_solutions(board, i + offset[k].x, j + offset[k].y, position_nr + 1);

	if (solution_found(position_nr)) {
		solution_nr++;
		print_solution(board, n, solution_nr);
	}
	board[i][j] = 0;
	position_nr--;
}