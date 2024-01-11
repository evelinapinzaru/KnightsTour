/*Circuitul calului : Se da o tabla de sah de N x N elemente pe care se afla un cal la coordonatele
(i, j).Se cere sa se scrie un program care determina mutarile calului(respectand saritura calului
din jocul de sah) astfel incat toate pozitiile tablei sa fie acoperite.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"heap.h"
#include"input.h"
#include"display.h"

//vectori cu valorile ce se adauga la coordonata de pe axa x si,
//respectiv, y a pozitiei calului pentru fiecare dintre miscari
int r[8] = { -2, -1,  1,  2,  2,  1, -1, -2 };
int c[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };

int is_on_board(int i, int j, int k, int n) {
	return (i + r[k] >= 0) && (i + r[k] < n) && (j + c[k] >= 0) && (j + c[k] < n);
}

int is_free(int** matrix, int i, int j, int k) {
	return !matrix[i + r[k]][j + c[k]];
}

void find_solutions(int** matrix, int n, int i, int j, int contor) {
	int flag = 0;

	matrix[i][j] = contor;
	for (int k = 0; k < 8; k++) {
		if (is_on_board(i, j, k, n) && is_free(matrix, i, j, k)) {
			find_solutions(matrix, n, i + r[k], j + c[k], contor + 1);
			flag = 1;
		}
	}
	if (flag == 0 && contor == n * n) { display_matrix(matrix, n); printf("\n"); }
	matrix[i][j] = 0; contor--;
}

int main(void) {
	int n, i, j;

	n = read_var("N = ", SIZE, 3);
	i = read_var("i = ", POSITION, n);
	j = read_var("j = ", POSITION, n);

	int** matrix = allocate_matrix(n);

	find_solutions(matrix, n, i, j, 1);

	free_matrix(matrix, n);
	return EXIT_SUCCESS;
}