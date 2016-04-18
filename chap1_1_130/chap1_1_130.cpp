#include<iostream>
using namespace std;

void paint(int i)//正方形绘制函数
{
	int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<i;n++)
			cout<<"*"<<"   ";//3空格用来调整间距
		cout<<endl<<endl;
	}
}

void paint(int i,int j)//长方形绘制函数
{
	int m,n;
	for(m=0;m<j;m++)
	{
		for(n=0;n<i;n++)
			cout<<"*"<<"   ";
		cout<<endl<<endl;
	}
}

void paint(int t,int h,int k)
{
	int i,j,p;
	if(k==1)
	{
		for(i=0;i<h;i++)
		{
			p=0;
			while(p<h-i)
			{
				cout<<"   ";
				p++;
			}
			for(j=0;j<t;j++)
				cout<<"*  ";
			cout<<endl<<endl;
		}
	}
	if(k==0)
	{
		for(i=0;i<h;i++)
		{
			p=0;
			while(p<i)
			{
				cout<<"   ";
				p++;
			}
			for(j=0;j<t;j++)
				cout<<"*  ";
			cout<<endl<<endl;
		}
	}
	if(k!=0&&k!=1)
		cout<<"输入错误！！";
}



int main()
{
	int x;
	cout<<"请输入正方形的边长"<<endl;
	cin>>x;
	paint(x);//画正方形部分

	int a,b;
	cout<<"请依次输入长方形的长和宽，以空白键分隔"<<endl;
	cin>>a>>b;
	paint(a,b);//画长方形部分

	int t,h,k;
	cout<<"请依次输入平行四边形的底和高，以空白键分隔"<<endl;
	cin>>t>>h;
	cout<<endl;
	cout<<"请输入倾斜方式，1为右倾，0为左倾"<<endl;
	cin>>k;
	paint(t,h,k);//画平行四边形部分

	cout<<"Writtern by Steven.J .Thanks for viewing";

	getchar();
	getchar();//getchar为防止程序闪退，无实际意义
	return 0;
}
