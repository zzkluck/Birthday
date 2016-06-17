#include "Snake.h"
#include<string>

bool win = 0;

void Snake::Initilise() {
	srand(time(NULL));
	for (auto beg = map.begin(); beg != map.end(); beg++) {
		*beg = ' ';
	}
	snakebody = { HEIGHT*WIDTH / 2 + 1,HEIGHT*WIDTH / 2 + WIDTH + 1 };
	food = rand() % (HEIGHT*WIDTH);
	win = 0;
	LoadInfo();
	system("cls");
}

void Snake::PlayTheSnake() {
	Initilise();
	position next;
	while (!win) {
		DrawSnakeAndFood();
		DrawMap();
		next = GetNext();
		if (ExamineNext(next)) {
			if (EndMenu()) {
				Initilise();
				continue;
			}
			else
				break;
		}
		Move(next);
		if (win) {
			cout << "You are win!" << endl;
			cout << "在下一个版本中,我们会实现过关系统.敬请期待." << endl;
			Shop();
			if (EndMenu()) {
				Initilise();
				continue;
			}
			else
				break;
		}
		system("cls");
	}
	SaveInfo();
}

void Snake::DrawMap() {
	string upper(WIDTH + 2, info.skin.upper_boundary);
	string lower(WIDTH + 2, info.skin.lower_boundary);;
	cout << upper << endl;
	for (int i = 0; i < HEIGHT; i++) {
		cout << info.skin.side_boundary;
		for (int j = 0; j < WIDTH; j++) {
			cout << map[i*WIDTH + j];
		}
		cout << info.skin.side_boundary << '\n';
	}
	cout << lower << endl;
}
void Snake::DrawSnakeAndFood() {
	map[*snakebody.begin()] = info.skin.snakehead;
	for (auto beg = snakebody.begin()+1; beg != snakebody.end(); beg++) {
		map[*beg] = info.skin.snakebody;
	}
	cout << food << endl;
	map[food] = info.skin.food;
}
void Snake::Move(position next) {
	snakebody.push_front(next);
	if (next != food) {
		map[*(snakebody.end() - 1)] = info.skin.floor;
		snakebody.pop_back();
	}
	else {
		RandFood();
	}
}
position Snake::GetNext() {
	char ch1;
	static char ch2 = 0x48;
	position next;
	while(1) {
		if ((ch1=_getch() )!= (char)0xe0) {
			_getch();
			continue;
		}
		ch2 = _getch();
		switch (ch2)
		{
		case 0x4b:
			next = index.left(snakebody[0]);
			break;
		case 0x48:
			next = index.above(snakebody[0]);
			break;
		case 0x4d:
			next = index.right(snakebody[0]);
			break;
		case 0x50:
			next = index.low(snakebody[0]);
		default:
			break;
		}
		if (next == snakebody[1])
			continue;
		else
			break;
	} 
	return next;
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
	return 0;
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
		if (*beg++ == info.skin.floor)
			shit -= 1;
	}
	food = beg - map.begin() - 1;
	if (food == -1) {
		system("pause");
	}
}
void Snake::Shop() {
	cout << "you have a skin?";
	info.skin = { 2,1,3,'_','|','-',' ' };
	SaveInfo();
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
void Snake::LoadInfo() {
	ifstream ifs(SnakeFile);
	if (!ifs) {
		ifs.close();
		ofstream ofs(SnakeFile);
		info.skin = { 56,56,67,' ',' ',' ',' ' };
		info.coins = 0;
		ofs.write((char*)&info, sizeof(info));
		return;
	}
	ifs.read((char*)&info, sizeof(info));
	return;
}
void Snake::SaveInfo() {
	ofstream ofs(SnakeFile);
	ofs.write((char*)&info, sizeof(info));
}