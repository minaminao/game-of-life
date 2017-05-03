#include "board.h"
#include <time.h>

Board::Board(int H, int W) :kH_(H), kW_(W), board_(H, std::vector<bool>(W)) {
	srand(time(NULL));
	// don't use std::random_device
	mt_.seed(rand());
};

std::string Board::toString() {
	std::string s;
	for (int i = 0; i < kH_; i++) {
		for (int j = 0; j < kW_; j++) {
			s += board_[i][j] ? '#' : '.';
		}
		s += '\n';
	}
	return s;
}

void Board::fillRandom() {
	for (int i = 0; i < kH_; i++)
		for (int j = 0; j < kW_; j++)
			if (mt_() & 1)
				board_[i][j] = true;
}

void Board::next() {
	next_board_.assign(kH_, std::vector<bool>(kW_));
	for (int i = 0; i < kH_; i++)
		for (int j = 0; j < kW_; j++) {
			int count = countNeighbors(i, j);
			if (!board_[i][j] && count == 3)
				next_board_[i][j] = true;
			if (board_[i][j] && (count == 2 || count == 3))
				next_board_[i][j] = true;
		}
	board_ = next_board_;
}

int Board::countNeighbors(int i, int j) {
	int count = 0;
	for (int di = -1; di <= 1; di++)
		for (int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0)
				continue;
			if (inRange(i + di, j + dj) && board_[i + di][j + dj])
				count++;
		}
	return count;
}

bool Board::inRange(int i, int j) {
	return i >= 0 && i < kH_ && j >= 0 && j < kW_;
}