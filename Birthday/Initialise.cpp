#include "Initialise.h"

string DATAFILE ;
string TEMPFILE ;
string DIRECTORY ;
string USERFILE ;
string SnakeFile;
string UpdataLog;

#define USERNAMEMAX 100
void Get_name()
{
	DWORD max = USERNAMEMAX;
	char name[USERNAMEMAX];
	GetUserName(name, &max);
	string username = name;
	DATAFILE = "C:\\Users\\" + username + "\\Documents\\Birthday\\data.txt";
	TEMPFILE = "C:\\Users\\" + username + "\\Documents\\Birthday\\temp.txt";
	DIRECTORY = "C:\\Users\\" + username + "\\Documents\\Birthday";
	USERFILE = "C:\\Users\\" + username + "\\Documents\\Birthday\\userinfomation.dat";
	SnakeFile = "C:\\Users\\" + username + "\\Documents\\Birthday\\snakeinfomation.dat";
	UpdataLog = "C:\\Users\\" + username + "\\Documents\\Birthday\\更新日志.txt";
}

Initialise::Initialise()
{
	Get_name();
	if (first_use()) {
		CreatDateFile();
		EnterNamePrompt();
		CreatUserName();
	}
}

bool first_use() {
	ifstream ifs(USERFILE);
	if (!ifs) {
		ifs.close();
		return 1;
	}
	return 0;
}

void CreatUserName() {
	ofstream ofs(USERFILE);
	string username;
	cin >> username;
	getchar();
	ofs << username;
	ofs.close();
}

inline void EnterNamePrompt() {
	cout << "You might be the first time to use our program on this computer." << endl;
	cout << "Tell me your name!(由于目前还是测试版,这个名字一旦输入就不能更改)" << endl;
	cout << "(如果不幸输入了错误的信息,请联系开发者传授你黑科技)" << endl;
}

void CreatDateFile() {
	if (!CreateDirectory(DIRECTORY.c_str(), NULL)) {
		cerr << "ERROR 6: create dircetory error.";
		getchar();
		exit(6);
	}
	ofstream ofs(DATAFILE);
	ofs << "FIRSTUSE" << endl;
	ofs.close();
}

