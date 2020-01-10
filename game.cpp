#include "game.h"
#include <iostream>
#include<set>
#include<map>

Game::Game(int boardSize) {

	this->boardSize = boardSize;

	board.resize(boardSize);
	for (int i = 0; i < boardSize; i++) {
		board[i].resize(boardSize);
	}

}

int Game::run() {

	initializeBoard();
	printBoard();
	char command;

	cout << "Moves: u for up,  d for down, r for right, l for left, q for exit\n";
	map<char, int>mp;
	mp['u'] = 1;
	mp['d'] = 2;
	mp['l'] = 3;
	mp['r'] = 4;
	mp['q'] = 5;

	int current_score = 0;
	int play = 1;

	while (hasEmptyPosition() && play) {
		cin >> command;
		

		switch (mp.at(command)) {

		case 1:
			moveUp(current_score);
			printBoard();
			break;

		case 2:
			moveDown(current_score);
			printBoard();
			break;

		case 3:
			moveLeft(current_score);
			printBoard();
			break;

		case 4:
			moveRight(current_score);
			printBoard();
			break;

		case 5:
			play = 0;
			break;
		}
	}

	if (!hasEmptyPosition()) {
		cout << "You cannot proceed further !!";
	}
	return current_score;
	
}


void Game::initializeBoard() {

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			board[i][j] = 0;
		}
	}

	fillEmptyPosition(); // may be initialise you can just fill by 2;
	fillEmptyPosition();
}

void Game::fillEmptyPosition() {

	int number = getRandomNumber();
	pair<int, int>pos = getRandomEmptyPosition();
	board[pos.first][pos.second] = number;

}

int Game::getRandomNumber() {

	int newNumber = rand() % 2 ? 2 : 4;
	return newNumber;
}

bool Game::hasEmptyPosition() {

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] == 0) {
				return true;
			}
		}
	}
	return false;
}


pair<int, int> Game::getRandomEmptyPosition() {

	int count = 0;
	set<pair<int, int>>uniqueFilledPositions;

	while (uniqueFilledPositions.size()!= (boardSize * boardSize)) {
		int xcord = rand() % boardSize;
		int ycord = rand() % boardSize;

		if (board[xcord][ycord] == 0) {
			return make_pair(xcord, ycord);
		}
		else {
			uniqueFilledPositions.insert(make_pair(xcord, ycord));
		}
	}
	return make_pair(-1, -1); //denotes no position is left
}

void Game::moveUp(int &score) {

	for (int j = 0; j < boardSize; j++) {
		int i = 1;

		int low = 0;
		while (i<boardSize) {

			if (!isPositionEmpty(i, j)) {
				if (isPositionEmpty(low, j) || board[low][j] == board[i][j]) {
					if (board[low][j] == board[i][j]) {
						score += board[low][j];
					}

					board[low][j] += board[i][j];
					board[i][j] = 0;

				}

				else {
					low++;
					board[low][j] = board[i][j];
					if (low != i) {
						board[i][j] = 0;
					}
				}
			}
			
			i++;
		}
	}

	fillEmptyPosition();
}

void Game::moveDown(int& score) {

	for (int j = 0; j < boardSize; j++) {
		int i = boardSize-2;

		int low = boardSize-1;
		while (i >= 0) {

			if (!isPositionEmpty(i, j)) {
				if (isPositionEmpty(low, j) || board[low][j] == board[i][j]) {
					if (board[low][j] == board[i][j]) {
						score += board[low][j];
					}

					board[low][j] += board[i][j];
					board[i][j] = 0;

				}

				else {
					low--;
					board[low][j] = board[i][j];
					if (low != i) {
						board[i][j] = 0;
					}
				}
			}
			
			i--;
		}
	}

	fillEmptyPosition();
}

void Game::moveLeft(int& score) {

	for (int i = 0; i < boardSize; i++) {
		int j = 1;

		int low = 0;
		while (j < boardSize) {

			if (!isPositionEmpty(i, j)) {
				if (isPositionEmpty(i, low) || board[i][low] == board[i][j]) {
					if (board[i][low] == board[i][j]) {
						score += board[i][low] * 2;
					}

					board[i][low] += board[i][j];
					board[i][j] = 0;

				}

				else {
					low++;
					board[i][low] = board[i][j];
					if (low != j) {
						board[i][j] = 0;
					}
				}
			}
			
			j++;
		}
	}

	fillEmptyPosition();
}

void Game::moveRight(int& score) {

	for (int i = 0; i < boardSize; i++) {
		int j = boardSize-2;

		int low = boardSize-1;
		while (j >=0 ) {
			if (!isPositionEmpty(i, j)) {
				if (isPositionEmpty(i, low) || board[i][low] == board[i][j]) {
					if (board[i][low] == board[i][j]) {
						score += board[i][low] * 2;
					}

					board[i][low] += board[i][j];
					board[i][j] = 0;

				}

				else {
					low--;
					board[i][low] = board[i][j];
					if (low != j) {
						board[i][j] = 0;
					}
				}
			}
			
			j--;
		}
	}

	fillEmptyPosition();
}

bool Game::isPositionEmpty(int x, int y) {
	return !board[x][y];
}

void Game::printBoard() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (board[i][j] == 0)
				cout << ". ";
			else
				cout << board[i][j] << " ";
		}
		cout << endl;
	}
}