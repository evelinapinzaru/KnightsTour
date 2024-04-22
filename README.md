# Knight's Tour

**Problem statement :** Given a N x N empty board with the knight placed on the square 
with the (i, j) coordinates. Moving according to the rules of chess, the knight must 
visit each square exactly once.

## Table of Contents 📃
1. [Getting Started](#getting-started)
2. [Overview](#overview)
3. [Final Results](#final-results)

<a name="getting-started"></a>
## Getting Started 🪄
1. **Install Docker**\
If you don't have Docker Engine installed on your machine, you can download it from the [official Docker Documentation website](https://docs.docker.com/engine/install/).
2. **Pull the Docker Image**\
Paste the following command into your terminal:
```bash
docker pull evepin/knightstour
```
3. **Run the Docker Container**\
Execute the following command:
```bash
docker run -it --rm evepin/knightstour
```

<a name="overview"></a>
## Overview 🔍
In order to solve the Knight's Tour problem, I've considered the chessboard 
to be a square matrix and called it *board*. To indicate that no position has 
been occupied yet, I chose to initialise it to zero. Both the initialisation 
and the dynamic allocation of the *board* are handled using **calloc()**.

In an effort to avoid potential issues caused by invalid user input, I've 
created a robust validation system within the *input.h* header, which covers 
all sorts of scenarios, including: unexpected data types, input exceeding 
specified bounds, etc.

The solution revolves around the **search_4_solutions()** function :
```c
void search_4_solutions(int** board, int i, int j, int position_nr) {
	board[i][j] = position_nr;

	for (int k = 0; k < 8; k++)
		if (is_on_board(i, j, k) && is_free(board, i, j, k))
			search_4_solutions(board, i + offset[k].x, j + offset[k].y, position_nr + 1);

	if (solution_found(position_nr)) {
		solution_nr++;
		print_solution(board, n, solution_nr);
	}
	board[i][j] = 0;
	position_nr--;
}
```
which starts by placing the knight at the position with coordinates (i, j), 
provided by the user. It then proceeds to check if any of the 8 squares the 
knight can potentially move to are within the chessboard's borders and are 
currently free. When both conditions are met, the function recursively calls 
itself with the updated position and position number.

This process is repeated until 1 of 2 scenarios occurs :
1. the knight reached a dead-end before completing a full tour
2. a solution has been found.

Before returning from the current call of **search_4_solution()**,  it's crucial 
to backtrack by marking the current position as unoccupied and decrementing the 
*position_nr*. This way we ensure all solutions are found.

<a name="final-results"></a>
## Final Results ✨
The program succesfully displays all the solutions to the Knight's Tour problem.

I've integrated ANSI color codes as an **EXTRA FEATURE** to enhance readability 
and create a more captivating user experience.

*Author's Note: Thanks for taking your time to read this. Wish u all the best :)*

