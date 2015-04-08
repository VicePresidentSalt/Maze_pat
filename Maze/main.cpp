#include "Commande.h"
#include "Jeu.h"
#include "Menu.h"
#include "Maze.h"

int main()
{
	Jeu jeu;
	jeu.AfficherEtat();
	Commande c;

	int maze[10][10];

	while (!jeu.Fini() && c != Menu::QUITTER && jeu.GetPersonnage().GetNbPas() != 0)
	{
		c = Menu::LireCommande();
		jeu.Executer(c);
		jeu.AfficherEtat();
	}
}