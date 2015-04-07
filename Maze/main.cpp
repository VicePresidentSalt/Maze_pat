#include "Commande.h"
#include "Jeu.h"
#include "Menu.h"

int main()
{
	Jeu jeu;
	jeu.AfficherEtat();
	Commande c;

	while (!jeu.Fini() && c != Menu::QUITTER)
	{
		c = Menu::LireCommande();
		jeu.Executer(c);
		jeu.AfficherEtat();
	}
}