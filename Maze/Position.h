#pragma once
class Position
{
	short x_, y_;

public:
	Position() throw()
		: x_(0), y_(0)
	{

	}

	Position(const short x, const short y) throw() 
		: x_(x), y_(y)
	{

	}

	short GetX() const throw()
	{
		return x_;
	}

	short GetY() const throw()
	{
		return y_;
	}

	bool operator == (const Position &p) const throw()
	{
		return GetX() == p.GetX() && GetY() == p.GetY();
	}

	bool operator != (const Position &p) const throw()
	{
		return !(*this == p);
	}

	Position VoisineEst() const throw()
	{
		return Position(GetX() + 1, GetY());
	}
	Position VoisineNord() const throw()
	{
		return Position(GetX(), GetY()-1);
	}
	Position VoisineOuest() const throw()
	{
		return Position(GetX() - 1, GetY());
	}
	Position VoisineSud() const throw()
	{
		return Position(GetX(), GetY()+1);
	}

};
