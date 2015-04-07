#pragma once
#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<ctime>
#define FALSE 0
#define TRUE 1
using namespace std;
const int SIZE = 12;
class Maze 
{
private:
	char  M[SIZE][SIZE]; // array of random numbers
	int size; // size of the array

public:
	Maze();  // constructor
	void read_maze();
	int maze_traverse(int row, int col);
	void display_maze();
};
