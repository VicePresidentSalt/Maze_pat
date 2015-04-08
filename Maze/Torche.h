#pragma once
#pragma once
#include <iostream>
#include "Position.h"
using namespace std;

class Torche
{
	const Position position_;
	static const int ajoutPas_ = 5;
	bool torchePrise_;

public:
	Torche()
	{

	}

	Torche(const Position &p) throw()
		: position_(p)
	{
		torchePrise_ = false;
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
};
ostream & operator<<(ostream&, const Torche&);
