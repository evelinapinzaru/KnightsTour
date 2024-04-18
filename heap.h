#ifndef HEAP
#define HEAP
#include<stdlib.h>

// dynamically allocates a size * size matrix
int** allocate_matrix(int);

// frees the dynamically allocated matrix passed as an argument
void free_matrix(int**, int);
#endif