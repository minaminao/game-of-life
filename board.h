#pragma once
#include <string>
#include <vector>
#include <random>

class Board {
public:
	Board(int H, int W);
	std::string toString();
	void fillRandom();
	void next();
private:
	const int kH_, kW_;
	std::vector<std::vector<bool>> board_, next_board_;
	std::mt19937 mt_;
	int countNeighbors(int i, int j);
	bool inRange(int i, int j);
};