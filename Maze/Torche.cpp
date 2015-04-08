#include "Torche.h"
#include <iostream>
using namespace std;

ostream & operator<<(ostream &os, const Torche&)
{
	return os << 'T';
}