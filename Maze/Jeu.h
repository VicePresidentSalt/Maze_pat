#pragma once
#include "Torche.h"
#include "Boost.h"
#include "Perso.h"
#include "Commande.h"
#include <vector>

class Jeu
{
	Perso perso_;
	Boost boost_;
	Torche torche_;
	char** maze_;
	Position LIEU_FIN;

	
public :
	Jeu() throw()
	{
		maze_ = initMaze();
	}
	bool Fini() const throw();
	char** initMaze();
	void AfficherEtat();
	void Executer(const Commande&);
	Perso GetPersonnage();
};