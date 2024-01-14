#ifndef HEAP
#define HEAP
#include<stdio.h>
#include<stdlib.h>

// frees the dynamically allocated n*n matrix passed as an argument
void free_matrix(int**, int);
// dynamically allocates a n*n matrix
int** allocate_matrix(int);
#endif