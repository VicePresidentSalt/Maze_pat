#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 61  // 30 * 2 + 1
#define CELL 900  // 30 * 30
#define WALL 1
#define PATH 0

void init_maze(int maze[MAX][MAX]);
void maze_generator(int indeks, int maze[MAX][MAX], int backtrack_x[CELL], int bactrack_y[CELL], int x, int y, int n, int visited);
void print_maze(int maze[MAX][MAX], int maze_size);
int is_closed(int maze[MAX][MAX], int x, int y);