#pragma once
#include <iostream>
#include "Position.h"
using namespace std;

class Boost
{
	const Position position_;
	const int ajoutPas_ = 5;
	bool manger_;

public:
	Boost() 
	{

	}

	Boost(const Position &p) throw()
		: position_(p)
	{
		manger_ = false;
	}

	Position GetPosition() const throw()
	{
		return position_;
	}

	bool estManger()
	{
		return manger_;
	}

	void Mange()
	{
		manger_ = true;
	}

	int GetAjoutPas() 
	{
		return ajoutPas_;
	}

};
ostream & operator<<(ostream&, const Boost&);