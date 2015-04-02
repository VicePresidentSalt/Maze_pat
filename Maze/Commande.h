#pragma once

class Commande
{
	char symbole_;
public:
	Commande (char symbole) throw() : symbole_(symbole)
	{
	}
	char GetSymbole() const throw() { return symbole_; }
	bool operator==(const Commande &c) const throw() { return GetSymbole() == c.GetSymbole(); }
	bool operator!=(const Commande &c) const throw() { return !(*this==c); }
};

#include <iosfwd>
using std::istream;
using std::ostream;
ostream & operator<<(ostream &, const Commande &);
istream & operator>>(istream&, Commande &);
