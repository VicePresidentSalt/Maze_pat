#pragma once
#include "Position.h"

class Boost
{
	const Position position_;

public:
	Boost() 
	{

	}

	Boost(const Position &p) throw()
	{
	
	}

	Position GetPosition() const throw()
	{
		return position_;
	}

};