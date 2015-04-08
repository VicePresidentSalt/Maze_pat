#include "Commande.h"
#include "Jeu.h"
#include "Menu.h"
#include "Maze.h"

int main()
{
	Jeu jeu;
	jeu.AfficherEtat();
	Commande c;
	srand((unsigned)time(NULL));

	int size;
	int indeks = 0;
	printf("MAZE CREATOR\n\n");
	printf("input  (0 ~ 30): ");
	scanf("%d", &size);
	printf("\n");
	int maze[MAX][MAX];
	int backtrack_x[CELL];
	int backtrack_y[CELL];

	init_maze(maze);

	backtrack_x[indeks] = 1;
	backtrack_y[indeks] = 1;

	maze_generator(indeks, maze, backtrack_x, backtrack_y, 1, 1, size, 1);
	print_maze(maze, size);

	getch();

	while (!jeu.Fini() && c != Menu::QUITTER && jeu.GetPersonnage().GetNbPas() != 0)
	{
		c = Menu::LireCommande();
		jeu.Executer(c);
		jeu.AfficherEtat();
	}
}