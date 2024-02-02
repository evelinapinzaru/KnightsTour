# Knight's Tour

**Problem statement :** Given a N x N empty board with the knight placed on the square 
with the (i, j) coordinates. Moving according to the rules of chess, the knight must 
visit each square exactly once.

## Table of Contents 📃
1. [Language and Framework Used](#language-and-framework)
2. [Getting Started](#getting-started)
3. [Step-by-Step Walkthrough](#step-by-step-walkthrough)
4. [Troubleshooting](#troubleshooting)
5. [Final Results](#final-results)


<a name="language-and-framework"></a>
## Language and Framework Used 🛠
* C native
* Microsoft Visual Studio 2019

<a name="getting-started"></a>

## Getting Started 🪄
1. **Install Docker**\
If you don't have Docker Desktop installed on your machine, you can download 
and install it from [Docker's official website](https://www.docker.com/).
2. **Pull the Docker Image**\
Paste the following command into your terminal :
```bash
docker pull evepin/knightstour
```
3. **Run the Docker Container**\
Execute the following command :
```bash
docker run -it evepin/knightstour
```

<a name="step-by-step-walkthrough"></a>
## Step-by-Step Walkthrough 👣
In order to solve the Knight's Tour problem, I've considered the chessboard 
to be a 2D array (a matrix) and called it *board*. When dynamically allocated, 
the *board* is initialised with 0's to show that no position has ever been occupied.

The solution revolves around the **search_4_solutions()** function :
```c
void search_4_solutions(int** board, int n, int i, int j, int position_nr) {
	board[i][j] = position_nr;

	for (int k = 0; k < 8; k++) {
		if (is_on_board(i, j, k, n) && is_free(board, i, j, k)) {
			search_4_solutions(board, n, i + x[k], j + y[k], position_nr + 1);
		}
	}
	if (position_nr == n * n) {
		solution_nr++;
		print_solution(board, n, solution_nr);
	}
	board[i][j] = 0;
	position_nr--;
}
```
which places the *position_nr* (currently equal to 1) on board[i][j] and parses through 
the 2 global arrays, *x[8]* and *y[8]*:
```c
int x[8] = { -2, -1,  1,  2,  2,  1, -1, -2 };
int y[8] = {  1,  2,  2,  1, -1, -2, -2, -1 };
```
in order to get the 8 potential destinations of the knight, and checks if they are within the board's 
borders and are currently free. When these 2 conditions are met, the **search_4_solutions()** function is being 
called again, this time for the position with (i+x[k], j+y[k]) coordinates.

This set of steps is repeated until the *position_nr* reaches *n* * *n*, indicating that all 
squares have been visited exactly once. That's when we print the board onto the screen.

After doing so, it's crucial to mark the current position, board[i][j], with 0 and decrement 
*position_nr* before we return from the reccursive call of **search_4_solution()** we're in at this point.

<a name="troubleshooting"></a>
## Troubleshooting 🎯
They say *"Never trust user input."*. That's why I've created the **get_input()** function :
```c
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
```
This function encapsulates test cases for every potential scenario out there, whever the user tries to 
enter a negative number or a question mark, a letter or a newline character, it covers it all. Moreover, 
it prints corresponding error messages with the help of the **print_err_txt()** function :
```c
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
```

<a name="Final Results"></a>

### Final Results ✨
The program succesfully displays all the solutions to the Knight's Tour problem.

As an **EXTRA FEATURE**, I've implemented ANSI color codes throughout the project, to improve readability 
and provide a more engaging user experience.

