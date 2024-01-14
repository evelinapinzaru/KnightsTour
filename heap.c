#include"heap.h"

void free_matrix(int** matrix, int n) {
	for (int i = 0; i < n; i++) 
		free(matrix[i]);
	free(matrix);
}

int** allocate_matrix(int n) {
	int** matrix = (int**)calloc(n, sizeof(int*));
	if (!matrix) {
		perror("Error allocating dynamic memory for the matrix!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; i++)
		if (!(matrix[i] = (int*)calloc(n, sizeof(int)))) {
			perror("Error allocating dynamic memory for a row of the matrix!\n");
			free_matrix(matrix, i);
			exit(EXIT_FAILURE);
		}
	return matrix;
}