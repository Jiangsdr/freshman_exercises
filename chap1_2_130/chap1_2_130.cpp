#include<iostream>
using namespace std;

struct Date
{
	int year;
	int month;
	int date;
};//����Date����һ���ṹ

int leap_year[]={31,29,31,30,31,30,31,31,30,31,30,31};//����ÿ������
int common_year[]={31,28,31,30,31,30,31,31,30,31,30,31};//ƽ��ÿ������

bool is_leapyear(int year)//�ж��Ƿ�Ϊ����
{
	if((year%400==0)||(year%100!=0&&year%4==0))
		return true;
	else
		return false;
}

int date_std(Date* p)//ѡ��һ����׼�գ������������ڵ������ʱ�䣬�˴�ȡ0��0��0�գ��ٶ����ڣ�
{
	int year1=p->year;int y;
	int month1=p->month;int m;
	int date1=p->date;int d;
	int sum=0;
	for(y=0;y<year1;y++)
	{
		if(is_leapyear(y))
			sum+=366;
		else sum+=365;
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

int date_difference(Date* p,Date* q)//�������ڲ�
{
	int i=date_std(p);
	int j=date_std(q);
	if(i>j) return i-j;
	if(i<j) return j-i;
	if(i==j) return 0;
}

void year_plus(Date* p)//����һ��ĺ���
{
	Date* q;
	q=new Date;
	q->year=p->year;
	q->month=p->month;
	q->date=p->date;
	q->year++;
	if(q->month==2&&q->date==29)
		q->date=28;
	cout<<"����һ����һ��Ϊ"<<q->year<<" "<<q->month<<" "<<q->date<<endl;
	free(q);
}

void month_plus(Date* p)//����һ�µĺ���
{
	Date* q;
	q=new Date;
	q->year=p->year;
	q->month=p->month;
	q->date=p->date;
	if(q->month<=11)
	{
		if(is_leapyear(q->year))
			q->date=min(q->date,leap_year[q->month]);
		else
			q->date=min(q->date,common_year[q->month]);
	}
	q->month=(1+q->month)%12;
	q->year+=(1+q->month)/13;
	cout<<"����һ����һ��Ϊ"<<q->year<<" "<<q->month<<" "<<q->date<<endl;
	free(q);
}

void date_plus(Date* p)
{
	Date* q;
	q=new Date;
	q->year=p->year;
	q->month=p->month;
	q->date=p->date;
	if(is_leapyear(q->year))
	{
		if(q->date<leap_year[q->month-1])
			q->date++;
		else
		{
			q->date=1;
			q->month=(1+q->month)%12;
	        q->year+=(1+q->month)/13;
		}
	}
	else
	{
		if(q->date<common_year[q->month-1])
			q->date++;
		else
		{
			q->date=1;
			q->month=(1+q->month)%12;
	        q->year+=(1+q->month)/13;
		}
	}
	cout<<"����һ����һ��Ϊ"<<q->year<<" "<<q->month<<" "<<q->date<<endl;
	free(q);
}


int min(int x,int y)
{
	return x<y?x:y;
}


int main()
{
	Date* p;Date* q;
	p=new Date;q=new Date;
	cout<<"����������һ�������գ��Կհ׷����"<<endl;
	cin>>p->year>>p->month>>p->date;
	cout<<"���������ڶ��������գ��Կհ׷����"<<endl;
	cin>>q->year>>q->month>>q->date;
	cout<<"���ڲ�Ϊ"<<date_difference(p,q)<<endl;
	year_plus(p);
	month_plus(p);
	date_plus(p);

	cout<<"Writtern by Steven.J .Thanks for viewing";

    getchar();
	getchar();
	return 0;
}