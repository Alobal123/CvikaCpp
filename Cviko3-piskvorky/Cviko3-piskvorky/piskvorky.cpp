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

Board::Board(size_t size) : size{ size }, board(size, std::vector<char>(size, '*')) {}

Board::Board()
{
}


void Board::make_play(int x, int y, char symbol)
{
	board[x][y] = symbol;
}

const void Board::print()
{
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

const bool Board::check_for_winner(int limit)
{
	return check_for_winner_row(true, limit) || check_for_winner_row(false, limit);
}

bool Board::is_valid_move(int x, int y)
{
	return x >= 0 and y >= 0 and x < size and y < size and board[x][y] == '*';
}

const bool Board::check_for_winner_row(bool rows, int limit)
{
	for (int i = 0; i < size; i++)
	{
		int longest_seq = 0;
		char last_symbol = '*';
		for (int j = 0; j < size; j++)
		{
			char next_char = rows ? board[i][j] : board[j][i];

			if (next_char != '*') {
				if (longest_seq == 0) {
					last_symbol = next_char;
				}
				else if (next_char == last_symbol) {
				}
				else {
					last_symbol = next_char;
					longest_seq = 0;
				}
				longest_seq++;
				if (longest_seq >= limit) {
					return true;
				}
			}
			else {
				last_symbol = '*';
				longest_seq = 0;
			}
		}
	}
	return false;
}


void Game::play()
{
	std::cout << "Enter size of the game: " << std::endl;
	int board_size; std::cin >> board_size;
	this->board = Board(board_size);
	this->board.print();

	while (! board.check_for_winner(2)) {
		play_turn();
	}
	std::cout<< ((turn % 2 == 1) ? p1_symbol : p2_symbol) << " wins!" << std::endl;

	int end; std::cin >> end;
	
}

Game::Game()
{}

void Game::play_turn()
{
	char player = (turn % 2 == 0) ? p1_symbol : p2_symbol;
	int x;
	int y;
	bool valid_move = false;
	std::cout << player << " player is on the move" << std::endl;
	while (! valid_move) {
		std::cout << "Enter row coordinate" << std::endl;
		std::cin >> x;
		std::cout << "Enter column coordinate" << std::endl;
		std::cin >> y;
		valid_move = board.is_valid_move(x, y);
		if (! valid_move) {
			std::cout << "Invalid move! Try again." << std::endl;;
		}
	}
	board.make_play(x-1, y-1, player);
	board.print();
	turn++;

}
