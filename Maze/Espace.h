#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Espace
{
public:

	static char** initMaze()
	{
		char** maze = new char*[50];
		for (int i = 0; i < 50; ++i)
		{
		   maze[i] = new char[50];
		}
		// Read maze.txt header
		ifstream din;
		din.open("mazetest.txt");
		string line;
		for (int r = 0; r < 50 ; r++)
		{
			getline(din, line);
			for (int c = 0; c < 50; c++)
			if (c < int(line.length()))
			maze[c][r] = line[c];
		}
		din.close();
		return maze;
	}
	enum
	{
		X_MIN = 0, Y_MIN= 0,
		X_MAX = 12 ,Y_MAX = 12
	};

	static bool EstValide(const Position &p) throw()
	{
		char** maze = initMaze();
		return maze[p.GetX()][p.GetY()] == '#' && X_MIN <= p.GetX() && p.GetX() < X_MAX &&
			   Y_MIN <= p.GetY() && p.GetY() < Y_MAX;
	}
};