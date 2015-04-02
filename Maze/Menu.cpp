#include "Menu.h"
#include "Commande.h"
#include <iostream>
using namespace std;

const Commande
	Menu::AVANCER = Commande('W'),
	Menu::GAUCHE = Commande('A'),
	Menu::DROITE = Commande('D'),
	Menu::QUITTER = Commande('Q');

void Menu::Afficher()
{
	cout << "Avancer: " << AVANCER << "; "
			"Gauche: " << GAUCHE << "; "
			"Droite: " << DROITE << "; "
			"Quitter: " << QUITTER << endl;
}

Commande Menu::LireCommande()
{
	Commande c = QUITTER;
	cin >> c;
	return c;
}