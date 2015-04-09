#include "Jeu.h"
#include "Menu.h"
#include "Espace.h"
#include "Torche.h"
#include <iostream>
using namespace std;

const Position
	Jeu::LIEU_BOOST_DEFAUT = Position(3, 3),
	Jeu::LIEU_PERSO_DEFAUT = Position(1, 1),
	Jeu::LIEU_FIN = Position(16,1),
	Jeu::LIEU_TORCHE_DEFAUT = Position(3, 2);

bool Jeu::Fini() const throw()
{
	return perso_.GetPosition() == LIEU_FIN ; // ?changer pour la position finale du maze
}

void Jeu::AfficherEtat()
{
	system("cls");
	char** maze = Espace::initMaze();

	for (int i = Espace::Y_MIN; i < Espace::Y_MAX; ++i)
	{
		for (int j = Espace::X_MIN; j < Espace::X_MAX; ++j)
		{
			const Position pos(j, i);

			if(maze[j][i] == '#')
			{
				cout << '#';
			}
			else if (pos == perso_.GetPosition())
			{
					cout << perso_; // dessine le perso
			}
			else if (pos == boost_.GetPosition() && !boost_.estManger())
			{
					cout << boost_; // dessine le boost
			}
			
			else if (pos == torche_.GetPosition() && !torche_.torchePrise())
			{
					cout << torche_; // dessine la torche
			}
			else
			{
					cout << ' '; // rien
			}
		}
	}

	Menu::Afficher();
	cout << "Nombre De Pas: " << perso_.GetNbPas() << endl;
	cout << "Nombre De Pas Avec Torche :" << perso_.GetNbPasTorche() << endl;
}
void Jeu::Executer(const Commande &c)
{
	if (c == Menu::AVANCER)
	{
		if (Espace::EstValide(perso_.Destination()))
		{
			perso_.Avancer();
			perso_.ReduirePas();
			if (torche_.torchePrise() && perso_.GetNbPasTorche() > 0)
			{
				perso_.ReduirePasTorche();
			}
		}
		if(perso_.GetPosition() == boost_.GetPosition() && !boost_.estManger())
		{
			perso_.AjoutNbPas(boost_.GetAjoutPas());
			boost_.Mange();
		}
		if (perso_.GetPosition() == torche_.GetPosition() && !torche_.torchePrise())
		{
			perso_.AjoutNbPasTorche(torche_.GetAjoutPasTorche());
			torche_.PrendreTorche();
		}

	}
	else if (c == Menu::DROITE)
		perso_.Droite();
	else if (c == Menu::GAUCHE)
		perso_.Gauche();
	
}

Perso Jeu::GetPersonnage()
{
	return perso_;
}
