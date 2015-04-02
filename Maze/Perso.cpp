#include "Perso.h"

void Perso::Avancer() throw()
{
	Position pos = GetPosition();

	switch ( GetDir() )
	{
		case Est:
			position_ = Position( pos.GetX()+1,pos.GetY() );
			break;
		case Nord:
			position_ = Position( pos.GetX(),pos.GetY()-1 );
			break;
		case Ouest:
			position_ = Position( pos.GetX()-1,pos.GetY() );
			break;
		case Sud:
			position_ = Position( pos.GetX(),pos.GetY()+1 );
			break;
	}
}