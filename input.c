#include<stdio.h>
#include<string.h>
#include"input.h"
#include"display.h"

void print_err_txt(int print_arg) {
	printf("%s\n", ansi[DRK_RED]);
	if (print_arg < 0) printf("Invalid input!");
	else printf("There are no solutions for a %dx%d board!", print_arg, print_arg);
	printf(" Try again ...%s\n\n", ansi[RESET]);
}

int is_int(char* buf, int* input) {
	int chars_consumed;

	if (!buf) return 0;
	buf[strlen(buf) - 1] = '\0';
	if (sscanf(buf, "%d%n", input, &chars_consumed) == 1
		&& buf[chars_consumed] == '\0') return 1;
	print_err_txt(-1);
	return 0;
}

int has_valid_value(option opt, int input, int set_value) {
	switch (opt) {
	case SIZE:
		if (input < 0) { print_err_txt(-1); return 0; }
		if (input < set_value) { print_err_txt(input); return 0; }
		break;
	case I_COORD:
	case J_COORD:
		if (input < 0 || input >= set_value) { print_err_txt(-1); return 0; }
		break;
	case ACTION:
		if (input != 0 && input != set_value) { print_err_txt(-1); return 0; }
		break;
	}
	return 1;
}

int get_valid_input(option opt, char* text, int set_value) {
	char buf[20];
	int input = -1;

	do {
		switch (opt) {
		case SIZE:
		case I_COORD:
		case J_COORD: printf("%s%s%s", ansi[CYA - opt], text, ansi[RESET]);
			break;
		case ACTION: printf(text);
			break;
		}
		fgets(buf, sizeof(buf), stdin);
	} while (!is_int(buf, &input) || !has_valid_value(opt, input, set_value));
	printf("\n");
	return input;
}