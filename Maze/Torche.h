#pragma once
#include <iostream>
#include "Position.h"
using namespace std;

class Torche
{
	Position position_;
	static const int ajoutPasTorche_ = 12;
	bool torchePrise_;


public:
	Torche()
	{ 
		torchePrise_ = false;
	}

	Torche(const Position &p) throw()
		: position_(p)
	{
		torchePrise_ = false;
	}

	void SetPosition(Position pos)
	{
		position_ = pos;
	}

	Position GetPosition() const throw()
	{
		return position_;
	}

	bool torchePrise()
	{
		return torchePrise_;
	}

	void PrendreTorche()
	{
		torchePrise_ = true;
	}

	int GetAjoutPasTorche()
	{
		return ajoutPasTorche_;
	}
};
ostream & operator<<(ostream&, const Torche&);
