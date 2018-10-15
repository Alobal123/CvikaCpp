#pragma once
#include <vector>

class Board {


	std::vector<std::vector<char> > board;
public:
	int size;

	Board(int size);

	void make_play(int x, int y, char symbol);

	void print();


};