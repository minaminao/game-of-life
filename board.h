#pragma once
#include <string>
#include <vector>
#include <random>

class Board {
public:
	Board(int h, int w);
	std::string toString();
	void fillRandom();
	void next();
private:
	static const char kAlive = '#', kDead = '.';
	const int kH_, kW_;
	std::vector<std::vector<bool>> board_, next_board_;
	std::mt19937 mt_;
	int countNeighbors(int i, int j);
	bool inRange(int i, int j);
};