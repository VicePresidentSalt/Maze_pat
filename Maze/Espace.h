#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Espace
{
public:
	static char** readMaze()
	{
		char** maze = new char*[100];
		for (int i = 0; i < 100; ++i)
		{
		   maze[i] = new char[100];
		}
		ifstream din;
		din.open("maze.txt");
		string line;
		for (int r = 0; r < 100 ; r++)
		{
			getline(din, line);
			for (int c = 0; c < 100; c++)
			if (c < int(line.length()))
			maze[c][r] = line[c];
		}
		din.close();
		return maze;
	}
	enum
	{
		X_MIN = 0, Y_MIN= 0,
		X_MAX = 80 ,Y_MAX = 20
	};

	static bool EstValide(const Position &p, char** maze) throw()
	{
		if (maze[p.GetX()][p.GetY()] == '#')
			return false;
		return X_MIN <= p.GetX() && p.GetX() < X_MAX &&
			   Y_MIN <= p.GetY() && p.GetY() < Y_MAX;
	}
};