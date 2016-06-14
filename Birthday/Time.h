#pragma once
#include<atltime.h>
#include"header.h"

static date month_days[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
class Time {
public:
	Time(){ getime = CTime::GetCurrentTime(); }

	date getoday(){return getime.GetMonth() * 100 + getime.GetDay();}
	date howlong(const date d);
//private:
	CTime getime;
};