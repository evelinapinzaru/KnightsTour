/*Circuitul calului : Se da o tabla de sah de N x N elemente pe care se afla un cal la coordonatele
(i, j).Se cere sa se scrie un program care determina mutarile calului(respectand saritura calului
din jocul de sah) astfel incat toate pozitiile tablei sa fie acoperite.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"display.h"

//vectori cu valorile ce se adauga la coordonata de pe axa x si,
//respectiv, y a pozitiei calului pentru fiecare dintre miscari
int x[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };
int y[8] = { 2,  1, -1, -2, -2, -1,  1,  2 };

enum option { DIMENSIUNE, POZITIE };

int read_var(char* text, enum option opt, int set_value) {
	char buf[20]; buf[19] = '\n';
	int var = -1;

	switch (opt) {
	case DIMENSIUNE:

		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			sscanf_s(buf, "%d", &var);
			if (var > 0 && var <= set_value)
				printf("\nThere are no solutions for a %dx%d board!\n", var, var);
			printf("\n");
		} while (var <= set_value);
		break;

	case POZITIE:
		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			sscanf_s(buf, "%d", &var);
			printf("\n");
		} while (var < 0 || var >= set_value);
		break;
	}
	return var;
}

void free_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
}

int** allocate_matrix(int n) {
	int** matrix = (int**)calloc(n, sizeof(int*));
	if (!matrix) {
		perror("Eroare la alocarea dinamica de memorie pentru matrice!");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++)
		if (!(matrix[i] = (int*)calloc(n, sizeof(int)))) {
			perror("Eroare la alocarea dinamica de memorie pentru o linie din matrice!");
			free_matrix(matrix, i);
			exit(EXIT_FAILURE);
		}
	return matrix;
}

void display_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) line_display(matrix[i], n);
}

void knights_tour(int** matrix, int n, int i, int j) {

}

int main(void) {
	int n, i, j;

	n = read_var("N = ", DIMENSIUNE, 3);
	i = read_var("i = ", POZITIE, n);
	j = read_var("j = ", POZITIE, n);

	int** matrix = allocate_matrix(n);

	knights_tour(matrix, n, i, j);

	free_matrix(matrix, n);
	return EXIT_SUCCESS;
}