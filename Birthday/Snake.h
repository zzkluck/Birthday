#pragma once
#include"ToD_array.h"
#include<array>
#include<deque>
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<Windows.h>

using namespace std;
typedef unsigned int position;
#define WIDTH 15
#define HEIGHT 15

#define SNAKEBODY 56
#define FOOD 67
class Snake
{
public:
	Snake() = default;
	void Initilise();
	void DrawMap();
	void DrawSnakeAndFood();
	void Move(position next);
	position GetNext();
	bool ExamineNext(position next);
	void Snake::RandFood();
	bool Snake::EndMenu();

	void PlayTheSnake();
private:
	ToD_array index = ToD_array(WIDTH, HEIGHT);
	array<char, WIDTH*HEIGHT> map = { 0 };
	deque<position> snakebody = { 113 };
	position food = rand() % 225;
};

