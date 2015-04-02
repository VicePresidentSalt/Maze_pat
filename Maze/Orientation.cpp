#include "Orientation.h"

Orientation PivoterGauche(const Orientation o)
{
	return static_cast<Orientation> ( (o + 1) % NB_DIRECTIONS );
}

Orientation PivoterDroite(const Orientation o)
{
	return o == Est ? Sud : static_cast<Orientation>(o - 1);
}