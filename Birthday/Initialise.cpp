#include "Initialise.h"

Initialise::Initialise()
{
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
	if (!CreateDirectory(DIRECTORY, NULL)) {
		cerr << "ERROR 6: create dircetory error.";
		getchar();
		exit(6);
	}
	ofstream ofs(DATAFILE);
	ofs << "FIRSTUSE" << endl;
	ofs.close();
}