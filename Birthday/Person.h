#pragma once
#include<string>
#include<fstream>
#include"header.h"
using namespace std;
class Person 
{
public:
	Person() = default;
	Person(string who, date month, date day) :
		name(who), birthday(100*month+day) {}
	Person(string who,date when):
		name(who),birthday(when){}
	Person(istream& is) { read(is); }

	bool operator<(const Person shit2) {
		return (*this).birthday <= shit2.birthday;
	}
	bool operator==(const Person shit2) {
		return name == shit2.name&&birthday == shit2.birthday;
	}
	istream& read(istream& is) {
		is >> name >> birthday;
		return is;
	}
	ostream& print(ostream &os)const {
		os << name << " " << birthday<<" ";
		return os;
	}
	
	string name;
	date birthday;
	string ExtraInfomation;
};