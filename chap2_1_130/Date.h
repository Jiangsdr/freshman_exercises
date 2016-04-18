#include<iostream>
using namespace std;

/*类定义*/
class Date
{
private:
	int year;
	int month;
	int day;
	int date_std();//选定一个基准日，计算输入日期到该天的时间，此处取0年0月0日（假定存在）
    
public:
	void initialize();//给一个日期赋值
	bool in_is_leapyear();//判断是否为闰年
	void turn_valid();//将一个日期变为有效日期
	int inteval(const Date&);//计算日期差
	int day_to_year();//计算日期为一年中的第几天
	void year_plus();//增加一年的函数
    void month_plus();//增加一月的函数
    void date_plus();//增加一天的函数
};



/*非成员函数和数组定义*/
int leap_year[]={31,29,31,30,31,30,31,31,30,31,30,31};//闰年每月天数
int common_year[]={31,28,31,30,31,30,31,31,30,31,30,31};//平年每月天数

int min(int x,int y)
{
	return x<y?x:y;
}

bool is_leapyear(int year)//判断是否为闰年
	{
	    if((year%400==0)||(year%100!=0&&year%4==0))
		    return true;
	    else
		    return false;
	}



/*成员函数定义*/
void Date::initialize()//初始化函数值
{
	cout<<"请输入有效的年、月、日"<<endl;
	cin>>year>>month>>day;
}

void Date::turn_valid()//将无效日期变为有效日期
{
	int i=0;
	if(month>12)
	{
			month%=12;
			i++;
	}
	if(is_leapyear(year))
	{
		if(day>leap_year[month-1])
		{
			day=leap_year[month-1];
			i++;
		}
	}
	else
	{
		if(day>common_year[month-1])
		{
			day=common_year[month-1];
			i++;
		}
	}
	if(i>0)
	{
		cout<<"你输入的日期有误，程序已自动为你修正为"<<endl;
		cout<<year<<" "<<month<<" "<<day<<" "<<endl;
	}
}

bool Date::in_is_leapyear()//判断是否为闰年
	{
		return is_leapyear(year);
	}

int Date::date_std()//选定一个基准日，计算输入日期到该天的时间，此处取0年0月0日（假定存在）
    {
	    int year1=year;int y;
	    int month1=month;int m;
	    int date1=day;int d;
	    int sum=0;
	    for(y=0;y<year1;y++)
	    {
		    if(is_leapyear(y))
			    sum+=366;
		    else  sum+=365;
	    }
	    if(is_leapyear(year1))
	    {
		    if(month1==1)
			    sum+=date1;
		    else
		    {
			    for(m=1;m<month1;m++)
				    sum+=leap_year[m-1];
			    sum+=date1;
		    }
	    }
	    else
		    {
		    if(month1==1)
			    sum+=date1;
		    else
		    {
			    for(m=1;m<month1;m++)
				    sum+=common_year[m-1];
			    sum+=date1;
		    }
	    }
	    return sum;
    }

int Date::inteval(const Date& d3)//计算日期差
{
	Date d1,d2;
	d1.year=year;d2.year=d3.year;
	d1.month=month;d2.month=d3.month;
	d1.day=day;d2.day=d3.day;
	int i=d1.date_std();
	int j=d2.date_std();
	return i>j?(i-j):(j-i);
}

int Date::day_to_year()//计算为一年中的第几天
{
	Date d1,d2;
	d1.year=year;d2.year=year;
	d1.month=month;d2.month=1;
	d1.day=day;d2.day=1;
	return d1.inteval(d2)+1;
}

void Date::year_plus()//增加一年的函数
    {
	    Date* q;
	    q=new Date;
	    q->year=year;
	    q->month=month;
	    q->day=day;
	    q->year++;
	    if(q->month==2&&q->day==29)
		    q->day=28;
	    cout<<"日期一增加一年为"<<q->year<<" "<<q->month<<" "<<q->day<<endl;
	    free(q);
    }

void Date::month_plus()//增加一月的函数
    {
	    Date* q;
	    q=new Date;
	    q->year=year;
	    q->month=month;
	    q->day=day;
	    if(q->month<=11)
	    {
		    if(is_leapyear(q->year))
			    q->day=min(q->day,leap_year[q->month]);
		    else
			    q->day=min(q->day,common_year[q->month]);
	    }
	    q->month=(1+q->month)%12;
	    q->year+=(1+q->month)/13;
	    cout<<"日期一增加一月为"<<q->year<<" "<<q->month<<" "<<q->day<<endl;
	    free(q);
    }

	void Date::date_plus()//增加一天的函数
    {
	    Date* q;
	    q=new Date;
	    q->year=year;
	    q->month=month;
	    q->day=day;
	    if(is_leapyear(q->year))
	    {
		    if(q->day<leap_year[q->month-1])
			    q->day++;
		    else
		    {
			    q->day=1;
			    q->month=(1+q->month)%12;
	            q->year+=(1+q->month)/13;
		    }
	    }
	    else
	    {
		    if(q->day<common_year[q->month-1])
			    q->day++;
		    else
		    {
			    q->day=1;
			    q->month=(1+q->month)%12;
	            q->year+=(1+q->month)/13;
		    }  
	    }
	    cout<<"日期一增加一天为"<<q->year<<" "<<q->month<<" "<<q->day<<endl;
	    free(q);
    }