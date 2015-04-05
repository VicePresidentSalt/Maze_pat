#include "Commande.h"
#include "Jeu.h"
#include "Menu.h"

int main()
{
	Jeu jeu;
	jeu.AfficherEtat();
	Menu::Afficher();
	Commande c;

	while (!jeu.Fini() && (c = Menu::LireCommande(),c != Menu::QUITTER))
	{
		jeu.Executer(c);
		jeu.AfficherEtat();
	}
}