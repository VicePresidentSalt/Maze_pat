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
	int nbPasTorche_;

	void SetDir(Orientation o) throw()
	{
		direction_ = o ;
	}

public:
	Perso(const Position &p = Position(), const Orientation o = Nord) throw()
		: position_(p), direction_(o), nbPas_(50) , nbPasTorche_(0)
	{
	}

	Orientation GetDir() const throw()
	{
		return direction_;
	}

	void SetPosition(Position pos)
	{
		position_ = pos;
	}

	bool champVision(Position pos)
	{
		if(nbPasTorche_ > 0 )
			return pos == position_.VoisineEst() || pos == position_.VoisineNord() || pos == position_.VoisineNordEst() || pos == position_.VoisineSudEst()
				|| pos == position_.VoisineSud() || pos == position_.VoisineOuest() || pos == position_.VoisineNordOuest() || pos == position_.VoisineSudOuest();
		else
			return pos == position_.VoisineEst() || pos == position_.VoisineNord()
				|| pos == position_.VoisineSud() || pos == position_.VoisineOuest();
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
	
	void AjoutNbPas(int ajoutPas)
	{
		nbPas_ += ajoutPas;
	}

	int GetNbPasTorche() const
	{
		return nbPasTorche_;
	}
	void ReduirePasTorche()
	{
		nbPasTorche_--;
	}

	void AjoutNbPasTorche(int ajoutPasTorche)
	{
		nbPasTorche_ += ajoutPasTorche;
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