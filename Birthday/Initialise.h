#pragma once
#include<fstream>
#include"header.h"
#include<iostream>
#include<stdio.h>
#include<string>
#include<atltime.h>
using namespace std;

class Initialise
{
public:
	Initialise();
};

void CreatUserName();
inline void EnterNamePrompt();
bool first_use();
void CreatDateFile();