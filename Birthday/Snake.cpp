#include "Snake.h"
#include<string>

bool win = 0;

void Snake::DrawMap() {
	string stars(WIDTH+2,'_');
	cout << stars << endl;
	for (int i = 0; i < HEIGHT; i++) {
		cout << '|';
		for (int j = 0; j < WIDTH; j++) {
			cout << map[i*WIDTH + j];
		}
		cout << "|\n";
	}
	cout << stars << endl;
}

void Snake::DrawSnakeAndFood() {
	for (auto beg = snakebody.begin(); beg != snakebody.end(); beg++) {
		map[*beg] = SNAKEBODY;
	}
	cout << food << endl;
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
	unsigned residue = map.size() - snakebody.size();
	if (residue == 0) {
		win = 1;
		return;
	}
	position shit = rand() % residue + 1;
	auto beg = map.begin();
	while(shit != 0) {
		if (*beg++ == 0)
			shit -= 1;
	}
	food = beg - map.begin() - 1;
	if (food == -1) {
		system("pause");
	}
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
	srand(time(NULL));
	map = { 0 };
	snakebody = { HEIGHT*WIDTH / 2 + 1 };
	food = rand() % (HEIGHT*WIDTH);
	win = 0;
}


void Snake::PlayTheSnake() {
	Initilise();
	while (!win) {
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
		if (win) {
			cout << "You are win!" << endl;
			if (EndMenu()) {
				Initilise();
				system("cls");
				continue;
			}
			else
				break;
		}
		system("cls");
	}
	
}