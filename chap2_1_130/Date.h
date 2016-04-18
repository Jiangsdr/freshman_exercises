#include<iostream>
using namespace std;

/*�ඨ��*/
class Date
{
private:
	int year;
	int month;
	int day;
	int date_std();//ѡ��һ����׼�գ������������ڵ������ʱ�䣬�˴�ȡ0��0��0�գ��ٶ����ڣ�
    
public:
	void initialize();//��һ�����ڸ�ֵ
	bool in_is_leapyear();//�ж��Ƿ�Ϊ����
	void turn_valid();//��һ�����ڱ�Ϊ��Ч����
	int inteval(const Date&);//�������ڲ�
	int day_to_year();//��������Ϊһ���еĵڼ���
	void year_plus();//����һ��ĺ���
    void month_plus();//����һ�µĺ���
    void date_plus();//����һ��ĺ���
};



/*�ǳ�Ա���������鶨��*/
int leap_year[]={31,29,31,30,31,30,31,31,30,31,30,31};//����ÿ������
int common_year[]={31,28,31,30,31,30,31,31,30,31,30,31};//ƽ��ÿ������

int min(int x,int y)
{
	return x<y?x:y;
}

bool is_leapyear(int year)//�ж��Ƿ�Ϊ����
	{
	    if((year%400==0)||(year%100!=0&&year%4==0))
		    return true;
	    else
		    return false;
	}



/*��Ա��������*/
void Date::initialize()//��ʼ������ֵ
{
	cout<<"��������Ч���ꡢ�¡���"<<endl;
	cin>>year>>month>>day;
}

void Date::turn_valid()//����Ч���ڱ�Ϊ��Ч����
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
		cout<<"��������������󣬳������Զ�Ϊ������Ϊ"<<endl;
		cout<<year<<" "<<month<<" "<<day<<" "<<endl;
	}
}

bool Date::in_is_leapyear()//�ж��Ƿ�Ϊ����
	{
		return is_leapyear(year);
	}

int Date::date_std()//ѡ��һ����׼�գ������������ڵ������ʱ�䣬�˴�ȡ0��0��0�գ��ٶ����ڣ�
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

int Date::inteval(const Date& d3)//�������ڲ�
{
	Date d1,d2;
	d1.year=year;d2.year=d3.year;
	d1.month=month;d2.month=d3.month;
	d1.day=day;d2.day=d3.day;
	int i=d1.date_std();
	int j=d2.date_std();
	return i>j?(i-j):(j-i);
}

int Date::day_to_year()//����Ϊһ���еĵڼ���
{
	Date d1,d2;
	d1.year=year;d2.year=year;
	d1.month=month;d2.month=1;
	d1.day=day;d2.day=1;
	return d1.inteval(d2)+1;
}

void Date::year_plus()//����һ��ĺ���
    {
	    Date* q;
	    q=new Date;
	    q->year=year;
	    q->month=month;
	    q->day=day;
	    q->year++;
	    if(q->month==2&&q->day==29)
		    q->day=28;
	    cout<<"����һ����һ��Ϊ"<<q->year<<" "<<q->month<<" "<<q->day<<endl;
	    free(q);
    }

void Date::month_plus()//����һ�µĺ���
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
	    cout<<"����һ����һ��Ϊ"<<q->year<<" "<<q->month<<" "<<q->day<<endl;
	    free(q);
    }

	void Date::date_plus()//����һ��ĺ���
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
	    cout<<"����һ����һ��Ϊ"<<q->year<<" "<<q->month<<" "<<q->day<<endl;
	    free(q);
    }