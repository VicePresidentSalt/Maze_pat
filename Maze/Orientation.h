#ifndef ORIENTATION_H
#define ORIENTATION_H

enum Orientation
{
	Est, Nord, Ouest, Sud, NB_DIRECTIONS
};

Orientation PivoterGauche(const Orientation);
Orientation PivoterDroite(const Orientation);

#endif