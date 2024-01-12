#include<stdio.h>
int colour_nr = 0;
int rainbow[6] = { 1, 3, 2, 6, 4, 5 };

// this function returns the nr. of digits for a given integer
int how_many_digits(int number) {
	if (number == 0) return 1;

	int len = 0;

	while (number != 0) {
		number = number / 10;
		len++;
	}
	return len;
}

// this functions returns the nr. of digits of the largest nr. 
// in matrix (the index of the last position on the board)
int max_nr_digits(int n) {
	return how_many_digits(n * n - 1);
}

// this function prints blank spaces for text alignment
void blank_spaces(int nr, int max) {
	for (int i = 0; i < (max - how_many_digits(nr)); i++) printf(" ");
}

// this function prints a row of alternating plus signs & dashes for solution display
void dash_n_plus(int** matrix, int n, int max) {
	int j = 3 + max_nr_digits(n);
	printf("+");
	for (int i = 1; i < max; i++)
		if (i == j) {
			printf("+");
			j = j + 3 + max_nr_digits(n);
		}
		else printf("-");
}

// this function sisplays the elements of a given vector horizontally
void line_display(int** matrix, int* line, int n) {
	int max = max_nr_digits(n);
	for (int i = 0; i < n - 1; i++) { blank_spaces(line[i], max); printf("%u | ", line[i]); }
	blank_spaces(line[n - 1], max); printf("%u |\n", line[n - 1]); dash_n_plus(matrix, n, 1 + n * (3 + max_nr_digits(n))); printf("\n");
}

// this function displays a solution
void display_matrix(int** matrix, int n, int solution_nr) {
	if (colour_nr == 6) colour_nr = 0;

	printf("%s%d%s", "\x1b[3", rainbow[colour_nr], "m");
	printf("SOLUTION NR. %d :\n\n", solution_nr);
	dash_n_plus(matrix, n, 1 + n * (3 + max_nr_digits(n))); printf("\n");
	for (int i = 0; i < n; i++) {
		printf("| "); line_display(matrix, matrix[i], n);
	}
	colour_nr++;
	printf("\x1b[0m\n");
}