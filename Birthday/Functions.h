#pragma once
#include"Data.h"
#include"Snake.h"
#include"IOfile.h"
#include"Time.h"
#include"header.h"

static string maen_name[4] = { "morning","afternoon","evening","night" };


class Functions
{
public:
	Functions();
	
	void ShowClosest();
	void ShowMainMenu();
	void SelectMode();
	void ShowPersonList();
	void InsertMode();
	void SaveInfo();
	int maen()const;

private:
	Snake snake;
	Data data;
	IOfile io;
	Time time;
	string username;
};
