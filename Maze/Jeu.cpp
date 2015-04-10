#include "Jeu.h"
#include "Menu.h"
#include "Espace.h"
#include "Torche.h"
#include <iostream>
using namespace std;


char** Jeu::initMaze()
{
	char** maze = Espace::readMaze();
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			const Position pos(j, i);
			if (maze[j][i] == 'B')
			{
				boost_.SetPosition(pos);
			}
			else if(maze[j][i] == 'T')
			{
				torche_.SetPosition(pos);
			}
			else if(maze[j][i] == 'S')
			{
				perso_.SetPosition(pos);
			}
			else if(maze[j][i] == 'E')
			{
				LIEU_FIN = pos;
			}
		}
	}
	return maze;
}
bool Jeu::Fini() const throw()
{
	return perso_.GetPosition() == LIEU_FIN ; // ?changer pour la position finale du maze
}

void Jeu::AfficherEtat()
{
	system("cls");

	for (int i = Espace::Y_MIN; i < Espace::Y_MAX; ++i)
	{
		for (int j = Espace::X_MIN; j < Espace::X_MAX; ++j)
		{
			const Position pos(j, i);

			if(maze_[j][i] == '#' && perso_.champVision(pos) )
			{
				cout << '#'; // dessine les murs
			}
			else if (maze_[j][i] == 'E' && perso_.champVision(pos))
			{
				cout << 'E'; // dessine la sortie
			}
			else if (pos == perso_.GetPosition())
			{
				cout << perso_; // dessine le perso
			}
			else if (pos == boost_.GetPosition() && !boost_.estManger() && perso_.champVision(pos) )
			{
				cout << boost_; // dessine le boost
			}
			
			else if (pos == torche_.GetPosition() && !torche_.torchePrise() && perso_.champVision(pos) )
			{
				cout << torche_; // dessine la torche
			}
			else
			{
				cout << ' '; // chemin
			}
		}
	}

	Menu::Afficher();
	cout << "Nombre De Pas: " << perso_.GetNbPas() << endl;
	cout << "Nombre De Pas Avec Torche : " << perso_.GetNbPasTorche() << endl;
}
void Jeu::Executer(const Commande &c)
{
	if (c == Menu::AVANCER)
	{
		if (Espace::EstValide(perso_.Destination(), maze_))
		{
			perso_.Avancer();
			perso_.IncrementerPasTotal();
			perso_.ReduirePas();
			if (torche_.torchePrise() && perso_.GetNbPasTorche() > 0)
			{
				perso_.ReduirePasTorche();
			}
		}
		if (perso_.GetPosition() == boost_.GetPosition() && !boost_.estManger())
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
