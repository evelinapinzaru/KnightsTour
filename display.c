#include<stdio.h>
#include<math.h>
#include"display.h"
#include"input.h"

// tracks the current color number
static int colour_nr = 0;

extra_chars = 1;
min_div_distance = 3;

char* ansi[] = { "\x1b[31m", "\x1b[33m", "\x1b[32m", "\x1b[36m", "\x1b[34m",
  "\x1b[35m", "\x1b[2;31m", "\x1b[5;31m", "\x1b[0m", "\x1b[1A", "\x1b[2K" };

int how_many_digits(int nr) {
	return nr ? (int)log10(nr) + 1 : 1;
}

void print_blanks(int nr) {
	for (int i = 0; i < (max_digits - how_many_digits(nr)); i++) printf(" ");
}

void print_hrz_divider(void) {
	int plus_index = 0;
	for (int i = 0; i < chars_per_row; i++)
		if (i != plus_index) printf("-");
		else {
			printf("+");
			plus_index += min_div_distance + max_digits;
		}
	printf("\n");
}

void print_divided_row(int* row, int size) {
	printf("| ");
	for (int i = 0; i < size - 1; i++) {
		print_blanks(row[i]);
		printf("%d | ", row[i]);
	}
	print_blanks(row[size - 1]);
	printf("%d |\n", row[size - 1]);
}

void print_solution(int** matrix, int size, int solution_nr) {
	if (colour_nr == 6) colour_nr = 0;
	printf("%sSOLUTION NR. %d :\n\n", ansi[colour_nr], solution_nr);
	print_hrz_divider();

	for (int i = 0; i < size; i++) {
		print_divided_row(matrix[i], size);
		print_hrz_divider();
	}
	printf("%s\n", ansi[RESET]);
	colour_nr++;
}