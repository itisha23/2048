#pragma once
#include "player.h"
#include<map>
#include<string>
using namespace std;

class Game2048
{	
	
	map<string, Player>playerList;

	public:
	void playGame(int boardSize, string Id);
	void addInPlayers(string Id);
	void showScore(string Id);

	void updateResults(int score, string id);
};

