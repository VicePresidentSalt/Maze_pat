#include "Jeu.h"
#include "Menu.h"
#include "Espace.h"
#include <iostream>
using namespace std;

const Position
	Jeu::LIEU_BOOST_DEFAUT = Position(1, 1),
	Jeu::LIEU_PERSO_DEFAUT = Position(5, 5);

bool Jeu::Fini() const throw()
{
	return perso_.GetPosition() == boost_.GetPosition(); // ?changer pour la position finale du maze
}

void Jeu::AfficherEtat() const
{
	system("cls");
	Menu::Afficher();

	for (int i = Espace::Y_MIN; i < Espace::Y_MAX; ++i)
	{
		for (int j = Espace::X_MIN; j < Espace::X_MAX; ++j)
		{
			const Position pos(j, i);

			if (pos == perso_.GetPosition())
			{
				cout << perso_; // dessine le perso
			}
			else if (pos == boost_.GetPosition())
			{
				cout << boost_; // dessine le boost
			}
			// rajouter le shit pour la torche
			else
			{
				cout << ' '; // rien
			}
		}
	}
}
void Jeu::Executer(const Commande &c)
{
	if (c == Menu::AVANCER)
	{
		if (Espace::EstValide(perso_.Destination()))
			perso_.Avancer();
	}
	else if (c == Menu::DROITE)
		perso_.Droite();
	else if (c == Menu::GAUCHE)
		perso_.Gauche();
	
}



