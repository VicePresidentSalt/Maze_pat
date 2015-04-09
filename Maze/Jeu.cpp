#include "Jeu.h"
#include "Menu.h"
#include "Espace.h"
#include "Torche.h"
#include <iostream>
using namespace std;

	char** maze = Espace::initMaze();
	/*
	const Position Jeu::LIEU_BOOST_DEFAUT = Position(3, 3);
	const Position Jeu::LIEU_PERSO_DEFAUT = Position(1, 1);
	const Position Jeu::LIEU_FIN = Position(16,1);
	const Position Jeu::LIEU_TORCHE_DEFAUT = Position(3, 2);
	*/
	const Position LIEU_FIN;

bool Jeu::Fini() const throw()
{
	return perso_.GetPosition() == positionFin ; // ?changer pour la position finale du maze
}

void Jeu::AfficherEtat()
{
	system("cls");

	for (int i = Espace::Y_MIN; i < Espace::Y_MAX; ++i)
	{
		for (int j = Espace::X_MIN; j < Espace::X_MAX; ++j)
		{
			const Position pos(j, i);

			if(maze[j][i] == '#' && perso_.champVision(pos) )
			{
				cout << '#'; // dessine les murs
			}
			else if (maze[j][i] == 'B' && perso_.champVision(pos))
			{
				cout << boost_; // dessine boost
				positionBoost.push_back(make_pair(j, i));
			}
			else if (maze[j][i] == 'T' && perso_.champVision(pos))
			{
				cout << torche_; // dessine torche
				positionTorche.push_back(make_pair(j, i));
			}
			else if (maze[j][i] == 'E' && perso_.champVision(pos))
			{
				LIEU_FIN = positionFin.push_back(make_pair(j, i));
				cout << 'E'; // dessine exit
			}
			else if (pos == perso_.GetPosition())
			{
				cout << perso_; // dessine le perso
			}
			/*
			else if (pos == boost_.GetPosition() && !boost_.estManger() && perso_.champVision(pos) )
			{
				cout << boost_; // dessine le boost
			}
			
			else if (pos == torche_.GetPosition() && !torche_.torchePrise() && perso_.champVision(pos) )
			{
				cout << torche_; // dessine la torche
			}
			*/
			else
			{
				cout << ' '; // rien
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
		if (Espace::EstValide(perso_.Destination(), maze))
		{
			perso_.Avancer();
			perso_.ReduirePas();
			if (torche_.torchePrise() && perso_.GetNbPasTorche() > 0)
			{
				perso_.ReduirePasTorche();
			}
		}
		for ( int i = 0; i < positionBoost.size(); i++)
		{
			if (perso_.GetPosition() == positionBoost<j,i> && !boost_.estManger())
			{
				perso_.AjoutNbPas(boost_.GetAjoutPas());
				boost_.Mange();
			}
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
