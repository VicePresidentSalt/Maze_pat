#include "Commande.h"
#include "Jeu.h"
#include "Menu.h"
#include "Maze.h"

int main()
{
	Jeu jeu;
	Maze  M;
	jeu.AfficherEtat();
	Commande c;
	M.display_maze();
	M.maze_traverse(2, 0);

	while (!jeu.Fini() && c != Menu::QUITTER && jeu.GetPersonnage().GetNbPas() != 0)
	{

		c = Menu::LireCommande();
		jeu.Executer(c);
		jeu.AfficherEtat();
	}
}