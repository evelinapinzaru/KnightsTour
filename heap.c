#include"heap.h"
#include"input.h"

int** allocate_matrix(int size) {
	int** matrix = (int**)calloc(size, sizeof(int*));
	if (!matrix) {
		perror("Error allocating dynamic memory for the matrix!\n");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++)
		if (!(matrix[i] = (int*)calloc(size, sizeof(int)))) {
			perror("Error allocating dynamic memory for a row of the matrix!\n");
			free_matrix(matrix, i);
			exit(EXIT_FAILURE);
		}
	return matrix;
}

void free_matrix(int** matrix, int line_nr) {
	for (int i = 0; i < line_nr; i++)
		free(matrix[i]);
	free(matrix);
}