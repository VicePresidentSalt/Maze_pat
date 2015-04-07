#include "Commande.h"
#include "Jeu.h"
#include "Menu.h"

int main()
{
	Jeu jeu;
	jeu.AfficherEtat();
	Commande c;

	while (!jeu.Fini() && c != Menu::QUITTER && jeu.GetPersonnage().GetNbPas() != 0)
	{
		c = Menu::LireCommande();
		jeu.Executer(c);
		jeu.AfficherEtat();
	}
}