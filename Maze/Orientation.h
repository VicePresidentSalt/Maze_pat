#pragma once

enum Orientation
{
	Est, Nord, Ouest, Sud, NB_DIRECTIONS
};

Orientation PivoterGauche(const Orientation);
Orientation PivoterDroite(const Orientation);