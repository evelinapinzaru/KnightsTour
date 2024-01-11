#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#ifndef input
#define input
enum option { SIZE, POSITION };
#endif

int read_var(char* text, enum option opt, int set_value) {
	char buf[20]; buf[19] = '\n';
	int var = -1;

	switch (opt) {
	case SIZE:

		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			sscanf_s(buf, "%d", &var);
			if (var > 0 && var <= set_value)
				printf("\nThere are no solutions for a %dx%d board!\n", var, var);
			printf("\n");
		} while (var <= set_value);
		break;

	case POSITION:
		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			sscanf_s(buf, "%d", &var);
			printf("\n");
		} while (var < 0 || var >= set_value);
		break;
	}
	return var;
}