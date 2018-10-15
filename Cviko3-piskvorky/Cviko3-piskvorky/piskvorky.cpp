// piskvorky.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "piskvorky.h"
#include <iostream>

int main()
{
	std::cout << "Enter size of the game: " << std::endl;

}

Board::Board(int size) {

	for (int i = 0; i < size; i++) {
		std::vector<char> row; // Create an empty row
		for (int j = 0; j < size; j++) {
			row.push_back('*'); // Add an element (column) to the row
		}
		board.push_back(row); // Add the row to the main vector
	}
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
