// piskvorky.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "piskvorky.h"
#include <iostream>

int main()
{
	Game game = Game();
	game.play();
	

}

Board::Board(int size) {

	this->size = size;
	for (int i = 0; i < size; i++) {
		std::vector<char> row; // Create an empty row
		for (int j = 0; j < size; j++) {
			row.push_back('*'); // Add an element (column) to the row
		}
		board.push_back(row); // Add the row to the main vector
	}
}
Board::Board()
{
}


void Board::make_play(int x, int y, char symbol)
{
	board[x][y] = symbol;
}

void Board::print()
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

bool Board::check_for_winner()
{
	return false;
}

void Game::play()
{
	std::cout << "Enter size of the game: " << std::endl;
	int board_size; std::cin >> board_size;
	this->board = Board(board_size);
	this->board.print();

	while (not board.check_for_winner()) {
		play_turn();
	}
}

Game::Game()
{}

void Game::play_turn()
{
	char player = (turn % 2 == 0) ? p1_symbol : p2_symbol;
	std::cout<< player << " player is on the move" << std::endl;
	std::cout << "Enter row coordinate" << std::endl;
	int x; std::cin >> x;
	std::cout << "Enter column coordinate" << std::endl;
	int y; std::cin >> y;
	board.make_play(x, y, player);
	board.print();
	turn++;

}
