#pragma once
#ifndef IOFILE_H
#define IOFILE_H

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class IOfile {
public:
	IOfile() = default;
	IOfile(int a);
	IOfile(string ifn, string ofn);
	void get_iofile_name();
	void open_iofile();
	void close() { ifs.close(); ofs.close(); }
//private:
	string ifname;
	ifstream ifs;
	string ofname;
	ofstream ofs;
	
};

#endif // !IOFILE_H