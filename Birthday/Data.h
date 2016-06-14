#pragma once
#include<vector>
#include<iostream>
#include"Person.h"
#include<algorithm>
class Data
{
public:
	Data() = default;
	Data(istream& is) { read(is); }
	istream& read(istream& is) {
		Person temp;
		while (temp.read(is)) {
			shit.push_back(temp);
		}
		return is;
	}
	ostream& print(ostream& os)const{
		for_each(shit.begin(), shit.end(),
			[&os](Person bitch) {bitch.print(os); });
		return os;
	}
	void sort() {
		std::sort(shit.begin(), shit.end(), 
			[](const Person bitch1, const Person bitch2){return bitch1.birthday < bitch2.birthday; });
	}
	void insert(Person bitch) {
		auto dst = find_if(shit.begin(), shit.end(),
			[bitch](Person bitch2) {return bitch2.birthday > bitch.birthday; });
		shit.insert(dst, bitch);

	}
	vector<Person> shit;
};

