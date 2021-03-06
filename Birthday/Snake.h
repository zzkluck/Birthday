#pragma once
#include"ToD_array.h"
#include"header.h"
#include<vector>
#include<deque>
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<Windows.h>
#include<fstream>

using namespace std;
typedef unsigned int position;
#define WIDTH 7
#define HEIGHT 7


typedef struct {
	char snakehead;
	char snakebody;
	char food;
	char upper_boundary;
	char side_boundary;
	char lower_boundary;
	char floor;
}Skin;

typedef struct tagSNAKEINFOHEADER {
	unsigned level;
	Skin skin;
	unsigned coins;
}SNAKEINFOHEADER;

class Snake
{
public:
	Snake() = default;

	void PlayTheSnake();
private:
	void Initilise();
	void DrawMap();
	void DrawSnakeAndFood();
	void Move(position next);
	position GetNext();
	bool ExamineNext(position next);
	void RandFood();
	bool EndMenu();
	void LoadInfo();
	void SaveInfo();
	void Shop();
	void WhileWin();
private:
	ToD_array index ;
	vector<char> map;
	deque<position> snakebody ;
	position food;
	SNAKEINFOHEADER info;
};

