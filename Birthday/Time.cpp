#include"Time.h"

date Time::howlong(const date d) {
	date days = 0;
	date day = getime.GetDay();
	date month = getime.GetMonth();
	date year = getime.GetYear();
	month_days[2] = (year % 400 == 0 || year % 100 != 0 && year % 4 == 0) ? 29 : 28;
	while (100 * month + day != d) {
		days += 1;
		day += 1;
		if (day > month_days[month]) {
			month += 1;
			if (month > 12) {
				year += 1;
				month_days[2] = (year % 400 == 0 || year % 100 != 0 && year % 4 == 0) ? 29 : 28;
				month = 1;
			}
			day = 1;
		}
	}
	return days;
}