#pragma once
class Espace
{
public:
	enum
	{
		X_MIN = 0, Y_MIN= 0,
		X_MAX = 80 ,Y_MAX = 20
	};

	static bool EstValide(const Position &p) throw()
	{
		return X_MIN <= p.GetX() && p.GetX() < X_MAX &&
			   Y_MIN <= p.GetY() && p.GetY() < Y_MAX;
	}
};