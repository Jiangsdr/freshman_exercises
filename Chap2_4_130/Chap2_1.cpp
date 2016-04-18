/***
*
*
*
***/

#include "Date.h"

using namespace std;

int main()
{
	int year, month, day;

	cout << "请输入两个日期。" << endl;

	cout << "日期一（年、月、日）：";
	cin >> year >> month >> day;
	Date date1(year, month, day);

	cout << "日期二（年、月、日）：";
	cin >> year >> month >> day;
	Date date2(year, month, day);

	cout << "两个日期相隔天数为：" << interval(date1,date2) << endl;

	Date d = date1;
	cout << "给日期一增加一天为：";
	date1.increaseDay();
	date1.print();

	date1 = d;
	cout << "给日期一增加一月为：" ;
	date1.increaseMonth();
	date1.print();

	date1 = d;
	cout << "给日期一增加一年为：";
	date1.increaseYear();
	date1.print();

	getchar();
	getchar();

	return 0;
}