#include"Date.h"

int main()
{
	Date d1,d2;
	d1.initialize();d1.turn_valid();
	d2.initialize();d2.turn_valid();
	int i=d1.inteval(d2);
	cout<<"����һ�����ڶ���Ϊ"<<i<<endl;
	cout<<"����һΪ�����"<<d1.day_to_year()<<"��"<<endl;
	if(d1.in_is_leapyear())
		cout<<"����һΪ����"<<endl;
	else
		cout<<"����һΪƽ��"<<endl;
	d1.year_plus();
	d1.month_plus();
	d1.date_plus();

	cout<<"Written by Steven J. Thanks for viewing."<<endl;
	getchar();
	getchar();
	return 0;
}

	