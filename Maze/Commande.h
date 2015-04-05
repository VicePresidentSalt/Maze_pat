#pragma once
#include <locale>
using std::toupper;
using std::locale;
class Commande
{
	char symbole_;
public:
	Commande (char symbole) throw() : symbole_(symbole)
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

#include <iosfwd>
using std::istream;
using std::ostream;
ostream & operator<<(ostream &, const Commande &);
istream & operator>>(istream&, Commande &);
