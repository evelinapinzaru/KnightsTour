// header file that deals with heap management for a square matrix

#ifndef HEAP
#define HEAP

// dynamically allocates a size * size matrix
int** allocate_matrix(int);

// frees the dynamically allocated matrix passed as an argument
void free_matrix(int**, int);
#endif