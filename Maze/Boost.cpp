#include "Boost.h"
#include <iostream>
using namespace std;

ostream & operator<<(ostream &os, const Boost&)
{
	return os << 'B';
}