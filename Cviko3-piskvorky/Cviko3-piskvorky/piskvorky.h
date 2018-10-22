#pragma once
#include <vector>

class Board {


	std::vector<std::vector<char> > board;
public:
	int size;
	Board(int size);
	Board();

	void make_play(int x, int y, char symbol);
	void print();
	bool check_for_winner(int limit);
	bool is_valid_move(int x, int y);
private:
	bool check_for_winner_row(bool rows, int limit);
};

class Game {
	
	int turn = 0;
	char p1_symbol = 'X';
	char p2_symbol = 'O';
	Board board;

public:
	void play();
	Game();
private:
	void play_turn();

};