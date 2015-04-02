#pragma once
#include "Position.h"
#include "Orientation.h"

class Perso
{
	Orientation direction_;
	Position position_;

	void SetDir(Orientation o) throw()
	{
		direction_ = o ;
	}

public:
	Perso(const Position &p = Position(), const Orientation o = Nord) throw()
		: position_(p), direction_(o)
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

	void Gauche() throw()
	{
		SetDir(PivoterGauche(GetDir()));
	}
	void Droite() throw()
	{
		SetDir(PivoterDroite(GetDir()));
	}
	void Avancer() throw();
};