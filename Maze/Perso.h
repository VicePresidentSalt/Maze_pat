#pragma once
#include <iostream>
#include "Position.h"
#include "Orientation.h"
using namespace std;

class Perso
{
	Orientation direction_;
	Position position_;
	int nbPas_;

	void SetDir(Orientation o) throw()
	{
		direction_ = o ;
	}

public:
	Perso(const Position &p = Position(), const Orientation o = Nord) throw()
		: position_(p), direction_(o), nbPas_(10)
	{
	}

	Orientation GetDir() const throw()
	{
		return direction_;
	}

	Position GetPosition() const
	{
		return position_;
	}
	int GetNbPas() const
	{
		return nbPas_;
	}
	void ReduirePas()
	{
		nbPas_--;
	}

	void Gauche() throw()
	{
		SetDir(PivoterGauche(GetDir()));
	}
	void Droite() throw()
	{
		SetDir(PivoterDroite(GetDir()));
	}
	Position Destination() const throw()
	{
		Position pos = GetPosition();
		switch (GetDir())
		{
		case Est:
			pos = pos.VoisineEst(); break;
		case Nord:
			pos = pos.VoisineNord(); break;
		case Ouest:
			pos = pos.VoisineOuest(); break;
		case Sud:
			pos = pos.VoisineSud(); break;
		}
		return pos;
	};
	void Avancer() throw()
	{
		position_ = Destination();
	}
};
ostream & operator<<(ostream&, const Perso&);