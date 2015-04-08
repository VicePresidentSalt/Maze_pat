#include "Jeu.h"
#include "Menu.h"
#include "Espace.h"
#include <iostream>
using namespace std;

const Position
	Jeu::LIEU_BOOST_DEFAUT = Position(1, 1),
	Jeu::LIEU_PERSO_DEFAUT = Position(5, 5),
	Jeu::LIEU_FIN = Position(6,6);

bool Jeu::Fini() const throw()
{
	return perso_.GetPosition() == LIEU_FIN ; // ?changer pour la position finale du maze
}

void Jeu::AfficherEtat()
{
	system("cls");
	int** maze = Espace::initMaze();

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
				if (pos.GetX() == Espace::X_MAX-1)
					cout << perso_ << endl;
				else
					cout << perso_; // dessine le perso
				
			}
			else if (pos == boost_.GetPosition() && !boost_.estManger())
			{
				if (pos.GetX() == Espace::X_MAX-1)
					cout << boost_ << endl;
				else
					cout << boost_; // dessine le boost
			}
			// rajouter le shit pour la torche
			else
			{
				if (pos.GetX() == Espace::X_MAX-1)
					cout << ' ' << endl;
				else
					cout << ' '; // rien
			}
		}
	}

	Menu::Afficher();
	cout << "Nombre De Pas: " << perso_.GetNbPas() << endl;
}
void Jeu::Executer(const Commande &c)
{
	if (c == Menu::AVANCER)
	{
		if (Espace::EstValide(perso_.Destination()))
		{
			perso_.Avancer();
			perso_.ReduirePas();
		}
		if(perso_.GetPosition() == boost_.GetPosition() && !boost_.estManger())
		{
			perso_.AjoutNbPas(boost_.GetAjoutPas());
			boost_.Mange();
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




