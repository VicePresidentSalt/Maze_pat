#pragma once
#include "Boost.h"
#include "Perso.h"
#include "Commande.h"

class Jeu
{
	Perso perso_;
	Boost boost_;

	static const Position LIEU_BOOST_DEFAUT, LIEU_PERSO_DEFAUT;

public :
	Jeu() throw()
		: perso_(LIEU_PERSO_DEFAUT),
		boost_(LIEU_BOOST_DEFAUT)
	{
		
	}
	bool Fini() const throw();
	void AfficherEtat() const;
	void Executer(const Commande&);
};