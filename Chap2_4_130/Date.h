/***
*
*  ʹ���������ĳ�����Ʒ�����д��һ����ҵ�еڶ���, Ҫ��:
* 1) ��Date����Ϊ��, year, month, dayΪ�����private���ݳ�Ա.
* 2) ������1��, ����1��, ����1��Ⱥ�����ΪDate��ĳ�Ա����. 
* 3) ���������ڵ��������Ҳ����ΪDate��ĳ�Ա����inteval���β�Ϊconst Date&����. ʹ��ʱ����:
		Date d1, d2;
		......    //d1, d2����Ϊ��������
		int i = d1.inteval(d2);  //i�����������
* 4) ������صĹ��ܺ���, ��: �ж�ĳ���Ƿ�Ϊ����, ����Ч���ڱ�Ϊ��Ч����, ������Ϊ���еڼ���, etc, Ҳ����Ϊ��Ա����. 
* 5) ��д����ʹ��Date��. 
*
***/
#include <iostream>

using std::cout;		using std::endl;

#define LEAPYEAR 366
#define YEAR 365

const int mon[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
enum Operation{INC_DAY, INC_MONTH, INC_YEAR};	//���ֲ������ͣ�����һ�죬����һ�£�����һ��

class Date {
public:
    Date(int y,int m,int d);

	void increaseDay();
	void increaseMonth();
	void increaseYear();

	void print()
	{
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
private:
	int year, month, day;

	bool isLeap() const
	{
		return year%4 == 0 && year%100 || year%400 == 0;
	}
	void validate(Operation flag);
	int dayOfYear()const;
public:
	friend int interval(const Date &date1,const Date& date2);
};	

