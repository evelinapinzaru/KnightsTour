#include<stdio.h>

#ifndef INPUT
#define INPUT
enum option { SIZE, POSITION };
#endif

// this function reads and validates user input
int read_var(char* text, enum option opt, int set_value) {
	char buf[20]; buf[19] = '\n';
	int var = -1;

	switch (opt) {
	case SIZE:

		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			if (sscanf(buf, "%d", &var) == EOF) printf("\nReading N error!\n\n");
			if (var > 0 && var <= set_value)
				printf("\n\x1b[2;31mThere are no solutions for a %dx%d board! Try again ...\x1b[0m\n\n", var, var);
		} while (var <= set_value);
		break;

	case POSITION:
		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			if (sscanf(buf, "%d", &var) == EOF) printf("\nReading coordinates error!\n\n");
			if (var < 0 || var >= set_value) printf("\n\x1b[2;31mIncorrect coordinate! Try again ...\x1b[0m\n\n");
		} while (var < 0 || var >= set_value);
		break;
	}
	printf("\n");
	return var;
}