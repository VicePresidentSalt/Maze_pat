#include "Maze.h"

Maze::Maze() 
{
	read_maze();
}

void Maze::read_maze() {
	int i, j;

	FILE* ifp;

	ifp = fopen("maze.txt", "r");

	for (i = 0; i< SIZE; i++)
		for (j = 0; j< SIZE; j++)
			fscanf(ifp, " %c ", &M[i][j]);
}

int Maze::maze_traverse(int row, int col) {
	// return TRUE if at the end of the maze
	if (M[row][col] == 'E') return TRUE;

	// return FALSE if not at the end of the maze
	if (M[row][col] > SIZE - 1 || M[row][col] == 'S') return FALSE;

	// mark + for part of the path
	M[row][col] = '+';

	// return TRUE if the path goes to the North
	if (M[row - 1][col] == TRUE) return TRUE;

	// return TRUE if the path goes to the South
	if (M[row + 1][col] == TRUE) return TRUE;

	// return TRUE if the path goes to the East
	if (M[row][col + 1] == TRUE) return TRUE;

	// return TRUE if the path goes to the West
	if (M[row][col - 1] == TRUE) return TRUE;

	// mark x for the wrong path
	M[row][col] = 'x';

	return FALSE;
}
void Maze::display_maze() {
	int i, j;

	for (i = 0; i<SIZE; i++) {
		for (j = 0; j< SIZE; j++)
			printf("%c ", M[i][j]);
		cout << endl;
	}
	cout << endl;
}