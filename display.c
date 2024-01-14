#include"display.h"

colour_nr = 0;

char* ansi(enum ansi_option opt) {
	switch (opt) {
	case RED: return "\x1b[31m";
	case YEL: return "\x1b[33m";
	case GRE: return "\x1b[32m";
	case CYA: return "\x1b[36m";
	case BLU: return "\x1b[34m";
	case MAG: return "\x1b[35m";
	case DRK_RED: return "\x1b[2;31m";
	case ONOFF_RED: return "\x1b[5;31m";
	case RESET: return "\x1b[0m";
	case UP1LN: return "\x1b[1A";
	case CLRLN: return "\x1b[2K";
	default: return "-INVALID_OPTION-";
	}
}

int how_many_digits(int nr) {
	if (nr == 0) return 1;
	int len = 0;

	while (nr != 0) {
		nr = nr / 10;
		len++;
	}
	return len;
}

int max_nr_digits(int n) { return how_many_digits(n * n); }

void blank_spaces(int nr, int max) {
	for (int i = 0; i < (max - how_many_digits(nr)); i++) printf(" ");
}

void dash_n_plus(int n, int max) {
	int plus_index = 0;
	for (int i = 0; i < max; i++)
		if (i != plus_index) printf("-");
		else {
			printf("+");
			plus_index += 3 + max;
		}
	printf("\n");
}

void print_row(int* row, int n, int max, int max_row) {
	for (int i = 0; i < n - 1; i++) {
		blank_spaces(row[i], max);
		printf("%d | ", row[i]);
	}
	blank_spaces(row[n - 1], max);
	printf("%d |\n", row[n - 1]);
}

void print_solution(int** matrix, int n, int solution_nr) {
	int max = max_nr_digits(n), max_chars_row = 1 + n * (3 + max);
	
	if (colour_nr == 6) colour_nr = 0;
	printf("%sSOLUTION NR. %d :\n\n", ansi(colour_nr), solution_nr);
	dash_n_plus(n, max_chars_row);
	for (int i = 0; i < n; i++) {
		printf("| ");
		print_row(matrix[i], n, max, max_chars_row);
		dash_n_plus(n, max_chars_row);
	}
	printf("%s\n", ansi(RESET));
	colour_nr++;
}