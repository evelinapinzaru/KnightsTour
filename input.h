// header file that tackles user input processing

#ifndef INPUT
#define INPUT

// enum type defining options for different types of user inputs
typedef enum { SIZE, I_COORD, J_COORD, ACTION } option;

// prints error message based on the provided argument
void print_err_txt(int);

// returns 1, if an int was read, else returns 0
int is_int(char*, int*);

// returns 1, if the input has a valid value, else returns 0
int has_valid_value(option, int, int);

// reads, validates & returns the validated user input
int get_valid_input(option, char*, int);
#endif