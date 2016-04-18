#include "Date.h"

Date::Date(int y,int m,int d)
{
	year=y;month=m;day=d;
}

void Date::validate(Operation flag)
{
	bool leap = isLeap();

	if(day > mon[leap][month-1]){			//无效日
		if(flag == INC_YEAR || flag == INC_MONTH)		//如果是由于增加一年或一月导致的无效日
			day = mon[leap][month-1];		//置为最近的有效日
		else {		//由于增加一天导致的无效日
			month++;
			day = 1;
		}
	}
	if(month > 12) {		//无效月
		year++;
		month = 1;
	}
}

void Date::increaseDay()
{
	day++;
	validate(INC_DAY);
}

void Date::increaseMonth()
{
	month++;
	validate(INC_MONTH);
}

void Date::increaseYear()
{
	year++;
	validate(INC_YEAR);
}

int Date::dayOfYear() const
{
	bool leap = isLeap();
	int d = day;

	for(int i = 0; i != month-1; i++)
		d += mon[leap][i];

	return d;
}

int interval(const Date& date1,const Date& date2)
{
	int i, interval;

	const Date *p, *p1, *p2 ;
	p1 = &date1, p2 = &date2;
	if(p1->year > p2->year){
		p = p1; p1 = p2; p2 = p;	//让p1指向较早的日期
	} 

	int day1 = p1->dayOfYear();
	int day2 = p2->dayOfYear();

	if(p1->year == p2->year)
		interval = day1 > day2 ? day1-day2 : day2-day1;
	else {
		interval = day2;
		for(i = 0; i != p2->year - p1->year; i++){
			Date d(p1->year+i , p1->month, p1->day);
			interval += d.isLeap() ? LEAPYEAR : YEAR;
		}
		interval -= day1;
	}

	return interval;
}