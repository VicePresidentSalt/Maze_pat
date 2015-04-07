#pragma once
#include <iostream>
#include <locale>
using namespace std;

class Commande
{
	char symbole_;
public:
	Commande (char symbole = ' ') throw() : symbole_(symbole)
	{
	}
	char GetSymbole() const throw() { return symbole_; }
	bool operator==(const Commande &c) const 
	{
		const locale loc("");
		return toupper(GetSymbole(),loc) == toupper(c.GetSymbole(),loc); 
	}
	bool operator!=(const Commande &c) const 
		{ return !(*this==c); }
};
ostream & operator<<(ostream &, const Commande &);
istream & operator>>(istream&, Commande &);


