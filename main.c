/*Circuitul calului : Se da o tabla de sah de N x N elemente pe care se afla un cal la coordonatele
(i, j).Se cere sa se scrie un program care determina mutarile calului(respectand saritura calului
din jocul de sah) astfel incat toate pozitiile tablei sa fie acoperite.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//vectori cu valorile ce se adauga la coordonata de pe axa x si,
//respectiv, y a pozitiei calului pentru fiecare dintre miscari
int x[8] = { 1,  2,  2,  1, -1, -2, -2, -1 };
int y[8] = { 2,  1, -1, -2, -2, -1,  1,  2 };

enum option { DIMENSIUNE, POZITIE };

int read_var(char* text, enum option opt, int set_value) {
	char buf[20]; buf[19] = '\n';
	int var = 0;

	switch (opt) {
	case DIMENSIUNE:

		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);

			if ((var = atoi(buf)) > 0 && var <= set_value)
				printf("\nThere are no solutions for a %dx%d board!\n\n", var, var);
		} while (var <= set_value);
		break;

	case POZITIE:
		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
		} while ((var = atoi(buf)) <= 0 || var >= set_value);
		break;
	}
	return var;
}

void free_memory(int** matrix, int n) {
	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
}

int** allocate_memory(int n) {
	int** matrix = (int**)calloc(n, sizeof(int*));
	if (!matrix) {
		perror("Eroare la alocarea dinamica de memorie pentru matrice!");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++)
		if (!(matrix[i] = (int*)calloc(n, sizeof(int)))) {
			perror("Eroare la alocarea dinamica de memorie pentru o linie din matrice!");
			free_memory(matrix, i);
			exit(EXIT_FAILURE);
		}
	return matrix;
}

void knights_tour(int** matrix, int n, int i, int j) {

}

int main(void) {
	int n, i, j;

	n = read_var("N = ", DIMENSIUNE, 3);
	i = read_var("i = ", POZITIE, n);
	j = read_var("j = ", POZITIE, n);

	int** matrix = allocate_memory(n);

	knights_tour(matrix, n, i, j);

	free_memory(matrix, n);

	return EXIT_SUCCESS;
}