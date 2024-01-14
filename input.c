#include"input.h"

void print_err_txt(enum option opt, int order_nr, int extra) {
	printf("%s\n", ansi(DRK_RED));
	if (opt == SIZE)
		if (order_nr == 0) printf("Reading N error!");
		else if (order_nr == 1) printf("Invalid size!");
		else printf("There are no solutions for a %dx%d board!", extra, extra);
	else if (opt == ACTION) 
		(!order_nr) ? printf("Reading option error!") : printf("Invalid option!");
	else
		(!order_nr) ? printf("Reading coordinate error!") : printf("Invalid coordinate!");
	printf(" Try again ...%s\n\n", ansi(RESET));
}

int get_input(char* text, enum option opt, int set_value) {
	char buf[20];
	int var = -1;

	if (opt == SIZE) {
		do {
			printf(text, ansi(CYA), ansi(RESET));
			fgets(buf, sizeof(buf), stdin);
			if (sscanf(buf, "%d", &var) != 1) print_err_txt(opt, 0, 0);
			else {
				if (var < 0) print_err_txt(opt, 1, 0); 
				else { if (var <= set_value) print_err_txt(opt, 2, var); }
			}
		} while (var <= set_value);
	}
	else if (opt == ACTION) {
		do {
			printf(text);
			fgets(buf, sizeof(buf), stdin);
			if (sscanf(buf, "%d", &var) != 1) { print_err_txt(opt, 0, 0); }
			else { if (var != 0 && var != set_value) print_err_txt(opt, 1, 0); }
		} while (var != 0 && var != set_value);
	}
	else {
		do {
			if (opt == I_COOR) printf(text, ansi(GRE), ansi(RESET));
			else printf(text, ansi(YEL), ansi(RESET));
			fgets(buf, sizeof(buf), stdin);
			if (sscanf(buf, "%d", &var) != 1) { print_err_txt(opt, 0, 0); }
			else { var = var - 1; if (var < 0 || var >= set_value) print_err_txt(opt, 1, 0); }
		} while (var < 0 || var >= set_value);
	}
	printf("\n");
	return var;
}