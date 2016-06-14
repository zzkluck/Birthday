#pragma once
#include"ToD_array.h"
#include<array>
#include<deque>
#include<iostream>
#include<cstdlib>

using namespace std;
typedef unsigned int position;
#define WIDTH 15
#define HEIGHT 15

#define SNAKEBODY 2
#define FOOD 3
class Snake
{
public:
	Snake() = default;
	void DrawMap();
	void DrawSnakeAndFood();
private:
	ToD_array index = ToD_array(WIDTH, HEIGHT);
	array<char, WIDTH*HEIGHT> map = { 0 };
	deque<position> snakebody = { 113 };
	position food;
};

