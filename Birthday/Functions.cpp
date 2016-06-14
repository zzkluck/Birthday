#include "Functions.h"

#define STARNUM 40
#define SHOW_PERSON_NUM 3

extern bool Changed = 0;
extern bool FileEmpty = 0;
string longstar(STARNUM, '*');
string shortstar("***   ");

inline void InsertModeIntroduce();
inline void SelectModeIntroduce();

Functions::Functions()  {
	io = IOfile(DATAFILE, TEMPFILE);
	data = Data(io.ifs);
	time = Time();
	ifstream USERNAMEFILEstream(USERFILE);
	USERNAMEFILEstream >> username;
	USERNAMEFILEstream.close();
}

void Functions::ShowMainMenu(){
	cout << longstar << endl;
	cout << shortstar << endl;
	cout << shortstar << "Hello " << username << endl;
	cout << shortstar << "Good "<<maen_name[maen()]<<" !"<<endl;
	if (data.shit.begin() == data.shit.end()) {
		cout << shortstar << "Find no data" << endl;
	}
	else {
		this->ShowClosest();
	}
	cout << shortstar << endl;
	cout << longstar << endl;
}

void Functions::ShowClosest() {
	auto close = find_if
	(data.shit.begin(), data.shit.end(),
		[this](Person bitch) {return bitch.birthday > this->time.getoday(); });
	date someday = close->birthday;
	unsigned count = 0;
	while (close!=data.shit.end()&&close->birthday == someday||++count<SHOW_PERSON_NUM) {
		unsigned a = time.howlong((*close).birthday);
		cout << shortstar << close->name << "的生日是"
			<< close->birthday / 100 << "月" << close->birthday % 100 << "日,距今还有" << a << "天." << endl;
		close++;
	}
};

int Functions::maen()const {
	date hour = time.getime.GetHour();
	if ((hour >= 0 && hour <= 5) || (hour >= 22 && hour <= 24))
		return 3;
	else if (hour > 5 && hour < 12)
		return 0;
	else if (hour >= 12 && hour < 18)
		return 1;
	else
		return 2;
}

void Functions::ShowPersonList() {
	data.print(cout);
}

void Functions::InsertMode() {
	InsertModeIntroduce();
	Person bitch;
	while (bitch.read(cin)) {
		data.insert(bitch);
	}
	Changed = 1;
}

inline void InsertModeIntroduce() {
	cout << "InsertMode ON" << endl;
	cout << "Enter a person's name and birthday information like \"张智凯 0624\"" << endl;
	cout << "Use \"CTRL+Z\" to make mode OFF"<<endl;
}

void Functions::SaveInfo() {
	//若Changed为真,将内存中的信息输出至temp,并删除data,将temp更名为data
	//若Changed为假,删除temp.
	if (Changed) {
		data.print(io.ofs);
		io.close();
		if (remove(DATAFILE)) {
			cerr << "ERROR 4 : REMOVE file error.";
			getchar();
			exit(4);
		}
		if (rename(TEMPFILE, DATAFILE)) {
			cerr << "ERROR 5 : RENAME file error.";
			getchar();
			exit(5);
		}
	}
	else {
		io.close();
		if (remove(TEMPFILE)) {
			cerr << "ERROR 4 : REMOVE file error.";
			getchar();
			exit(4);
		}
		
	}
}

void Functions::SelectMode() {
	//enum ModeName{
	//	Reserved,ShowMainMenu,ShowPersonList,InserMode
	//};
	int mode;
	SelectModeIntroduce();
	while (cout << "Now your should select the mode" << endl,cin >> mode) {
		getchar();
		switch (mode)
		{
		case 1:
			ShowMainMenu();
			break;
		case 2:
			ShowPersonList();
			break;
		case 3:
			InsertMode();
			break;
		default:
			break;
		}
	}
}

inline void SelectModeIntroduce() {
	cout << "Now you can select the mode." << endl;
	cout << "Use mode 1 to show the mainmenu again;" << endl;
	cout << "Use mode 2 to show all data saved" << endl;
	cout << "Use mode 3 to add new data" << endl;
	cout << "Enter 'q' to quit" << endl;
	cout << "If you are the first time to use, you now should select mode 3 " << endl;
}