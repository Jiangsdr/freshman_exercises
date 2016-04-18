/***
*
*  使用面向对象的程序设计方法改写第一次作业中第二题, 要求:
* 1) 将Date定义为类, year, month, day为该类的private数据成员.
* 2) 将增加1年, 增加1月, 增加1天等函数作为Date类的成员函数. 
* 3) 求两个日期的相隔天数也定义为Date类的成员函数inteval，形参为const Date&类型. 使用时如下:
		Date d1, d2;
		......    //d1, d2设置为具体日期
		int i = d1.inteval(d2);  //i保存相隔天数
* 4) 其他相关的功能函数, 如: 判断某年是否为闰年, 将无效日期变为有效日期, 求日期为年中第几天, etc, 也定义为成员函数. 
* 5) 编写程序使用Date类. 
*
***/
#include <iostream>

using std::cout;		using std::endl;

#define LEAPYEAR 366
#define YEAR 365

const int mon[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
enum Operation{INC_DAY, INC_MONTH, INC_YEAR};	//三种操作类型：增加一天，增加一月，增加一年

class Date {
public:
    Date(int y,int m,int d);

	void increaseDay();
	void increaseMonth();
	void increaseYear();

	void print()
	{
		cout << year << "年" << month << "月" << day << "日" << endl;
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

