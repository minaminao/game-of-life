#include "board.h"
#include "windows.h"
#include <iostream>

void clear() {
	system("cls");
}

int main(int argc, char *argv[]) {
	Board board(20, 40);
	board.fillRandom();
	while (true) {
		clear();
		std::cout << board.toString();
		Sleep(500);
		board.next();
	}
	return 0;
}