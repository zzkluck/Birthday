#include "Snake.h"

void Snake::DrawMap() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << map[i*WIDTH + j];
		}
		cout << '\n';
	}
}

void Snake::DrawSnakeAndFood() {
	for (auto beg = snakebody.begin(); beg != snakebody.end(); beg++) {
		map[*beg] = SNAKEBODY;
	}
	map[food] = FOOD;
}