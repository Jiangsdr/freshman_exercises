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

	cout << "�������������ڡ�" << endl;

	cout << "����һ���ꡢ�¡��գ���";
	cin >> year >> month >> day;
	Date date1(year, month, day);

	cout << "���ڶ����ꡢ�¡��գ���";
	cin >> year >> month >> day;
	Date date2(year, month, day);

	cout << "���������������Ϊ��" << interval(date1,date2) << endl;

	Date d = date1;
	cout << "������һ����һ��Ϊ��";
	date1.increaseDay();
	date1.print();

	date1 = d;
	cout << "������һ����һ��Ϊ��" ;
	date1.increaseMonth();
	date1.print();

	date1 = d;
	cout << "������һ����һ��Ϊ��";
	date1.increaseYear();
	date1.print();

	getchar();
	getchar();

	return 0;
}