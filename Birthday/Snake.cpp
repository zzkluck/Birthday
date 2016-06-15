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

void Snake::Move(position next) {
	snakebody.push_front(next);
	if (next != food) {
		map[*(snakebody.end() - 1)] = 0;
		snakebody.pop_back();
	}
	else {
		RandFood();
	}
}

position Snake::GetNext() {
	char ch1;
	static char ch2 = 0x48;
	while (1) {
		if ((ch1=_getch() )!= (char)0xe0) {
			_getch();
			continue;
		}
		ch2 = _getch();
		switch (ch2)
		{
		case 0x4b:
			return index.left(snakebody[0]);
			break;
		case 0x48:
			return index.above(snakebody[0]);
			break;
		case 0x4d:
			return index.right(snakebody[0]);
			break;
		case 0x50:
			return index.low(snakebody[0]);
		default:
			break;
		}
	}

}

bool Snake::ExamineNext(position next) {
	if (next == index.getmax()) {
		cout << "YOU DIED!";
		return 1;
	}

	for (auto beg = snakebody.begin(); beg != snakebody.end(); beg++) {
		if (next == *beg) {
			cout << "YOU DIED!";
			return 1;
		}
	}

}

void Snake::RandFood() {
	position shit = rand() % (sizeof(map) - sizeof(snakebody));
	auto beg = map.begin();
	while(shit != 0) {
		if (*beg++ == 0)
			shit -= 1;
	}
	food = beg - map.begin();
}

bool Snake::EndMenu(){
	cout << "Do you want to continue?(Y/N)" << endl;
	while (1) {
		switch (getchar())
		{
		case 'Y':
		case 'y':
			return 1;
			break;
		case 'N':
		case 'n':
			return 0;
			break;
		default:
			continue;
			break;
		}
	}
}

void Snake::Initilise() {
	map = { 0 };
	snakebody = { 113 };
	food = rand() % 225;
}


void Snake::PlayTheSnake() {
	srand(time(NULL));
	while (1) {
		DrawSnakeAndFood();
		DrawMap();
		position next = GetNext();
		if (ExamineNext(next)) {
			if (EndMenu()) {
				Initilise();
				system("cls");
				continue;
			}
			else
				break;
		}
		Move(next);
		system("cls");
	}
}