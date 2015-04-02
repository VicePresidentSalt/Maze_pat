#pragma once
#include "Commande.h"

class Menu
{
public:
	static const Commande
		AVANCER, GAUCHE, DROITE, QUITTER;
	static void Afficher();
	static Commande LireCommande();
};
