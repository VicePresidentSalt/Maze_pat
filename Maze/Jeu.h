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
	vector<pair<int, int>> positionBoost;
	vector<pair<int, int>> positionTorche;
	vector<pair<int, int>> positionFin;
	/*
	static const Position LIEU_BOOST_DEFAUT, LIEU_PERSO_DEFAUT, LIEU_FIN ,LIEU_TORCHE_DEFAUT;
	*/
public :
	Jeu() throw()
	{
		
	}
	bool Fini() const throw();
	void AfficherEtat();
	void Executer(const Commande&);
	Perso GetPersonnage();
};