#include<stdio.h>
#include<stdlib.h>

// this function frees the dynamically allocated n*n matrix passed as an argument
void free_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++)
		free(matrix[i]);
	free(matrix);
}

// this function dynamically allocates a n*n matrix
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