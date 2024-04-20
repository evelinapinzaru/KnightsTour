// header file that handles solution display

#ifndef DISPLAY
#define DISPLAY

// stores options for ANSI codes usage
enum ansi_option { RED, YEL, GRE, CYA, BLU, MAG,
	  DRK_RED, ONOFF_RED, RESET, UP1LN, CLRLN };

// stores ansi codes
char* ansi[];

// the maximum number of digits it takes to represent
// any position number on the board
int max_digits;

// the number of chars printed on each row
int chars_per_row;

// the number of extra chars used for displaying each row
int extra_chars;

// marks the base distance between 2 vertical dividers
int min_div_distance;

// returns the number of digits of a given integer
int how_many_digits(int);

// prints blanks to center solution elements
// within the dividers delineated squares
void print_blanks(int);

// prints a horizontal divider to separate
// the rows of the solution
void print_hrz_div();

// prints the elements of a given row of
// the solution separated by '|'
void print_div_row(int*, int);

// displays a solution
void print_solution(int**, int, int);
#endif