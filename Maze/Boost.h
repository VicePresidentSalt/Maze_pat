#pragma once
#include <iostream>
#include "Position.h"
using namespace std;

class Boost
{
	const Position position_;

public:
	Boost() 
	{

	}

	Boost(const Position &p) throw()
		: position_(p)
	{
	
	}

	Position GetPosition() const throw()
	{
		return position_;
	}

};
ostream & operator<<(ostream&, const Boost&);