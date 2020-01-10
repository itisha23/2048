#pragma once
#include<string>
using namespace std;
class Player
{	
private:
	string Id;
	int lastScore;
	int bestScore;

public:
	Player() {}
	Player(string Id);

	int getLatestScore();
	int getBestScore();
	void setBestScore(int score);
	void setLatestScore(int score);

};

