#include "Perso.h"
#include <iostream>
using std::ostream;
ostream & operator << (ostream &os, const Perso &p)
{
	switch (p.GetDir())
	{
	case Est:
		os << '>'; break;
	case Nord:
		os << 'A'; break;
	case Ouest:
		os << '<'; break;
	case Sud:
		os << 'V'; break;
	default:
		os << '?'; break;
	}
	return os;
}