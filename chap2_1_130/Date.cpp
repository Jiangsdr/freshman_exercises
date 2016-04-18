#include"Date.h"

int main()
{
	Date d1,d2;
	d1.initialize();d1.turn_valid();
	d2.initialize();d2.turn_valid();
	int i=d1.inteval(d2);
	cout<<"日期一与日期二差为"<<i<<endl;
	cout<<"日期一为该年第"<<d1.day_to_year()<<"天"<<endl;
	if(d1.in_is_leapyear())
		cout<<"日期一为闰年"<<endl;
	else
		cout<<"日期一为平年"<<endl;
	d1.year_plus();
	d1.month_plus();
	d1.date_plus();

	cout<<"Written by Steven J. Thanks for viewing."<<endl;
	getchar();
	getchar();
	return 0;
}

	