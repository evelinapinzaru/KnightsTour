#ifndef INPUT
#define INPUT
#include<stdio.h>
#include"display.h"

// stores options for user input
enum option { SIZE, I_COOR, J_COOR, ACTION };
// prints error message for a specified scenario
void print_err_txt(enum option, int, int);
// reads and validates user input
int get_input(char*, enum option, int);
#endif
