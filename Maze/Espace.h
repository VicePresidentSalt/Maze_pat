#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Espace
{
public:

	static int** initMaze()
	{
		int** maze = new int*[10];
		for (int i = 0; i < 10; ++i)
		{
		   maze[i] = new int[10];
		}
		// Read maze.txt header
		ifstream din;
		din.open("mazetest.txt");
		string line;
		getline(din, line);
		for (int r = 0; r < 10; r++)
		{
			getline(din, line);
			for (int c = 0; c < 10; c++)
			if (c < int(line.length()))
			maze[r][c] = line[c];
		}
		din.close();
		return maze;
	}
	enum
	{
		X_MIN = 0, Y_MIN= 0,
		X_MAX = 10 ,Y_MAX = 10
	};

	static bool EstValide(const Position &p) throw()
	{
		return X_MIN <= p.GetX() && p.GetX() < X_MAX &&
			   Y_MIN <= p.GetY() && p.GetY() < Y_MAX;
	}
};