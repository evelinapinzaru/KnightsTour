#ifndef DISPLAY
#define DISPLAY
#include<stdio.h>

// tracks the current color number
extern int colour_nr;
// stores options for ANSI codes usage
enum ansi_option { RED, YEL, GRE, CYA, BLU, MAG, DRK_RED, ONOFF_RED, RESET, UP1LN, CLRLN };

// returns the corresponding ANSI code for the given option
char* ansi(enum ansi_option);
// returns the nr. of digits for a given integer
int how_many_digits(int);
// returns the nr. of digits required to represent the index of the
// last position the knight has to occupy to complete a tour
int max_nr_digits(int);
// prints blank spaces for text alignment
void blank_spaces(int, int);
// prints a row of alternating dashes & plus signs for solution display
void dash_n_plus(int, int, int);
// displays the elements of a given row (a 1D array) of the matrix
void print_row(int*, int, int, int);
// displays a solution
void print_solution(int**, int, int);
#endif
