#include<iostream>
using namespace std;

void paint(int i)//�����λ��ƺ���
{
	int m,n;
	for(m=0;m<i;m++)
	{
		for(n=0;n<i;n++)
			cout<<"*"<<"   ";//3�ո������������
		cout<<endl<<endl;
	}
}

void paint(int i,int j)//�����λ��ƺ���
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
		cout<<"������󣡣�";
}



int main()
{
	int x;
	cout<<"�����������εı߳�"<<endl;
	cin>>x;
	paint(x);//�������β���

	int a,b;
	cout<<"���������볤���εĳ��Ϳ��Կհ׼��ָ�"<<endl;
	cin>>a>>b;
	paint(a,b);//�������β���

	int t,h,k;
	cout<<"����������ƽ���ı��εĵ׺͸ߣ��Կհ׼��ָ�"<<endl;
	cin>>t>>h;
	cout<<endl;
	cout<<"��������б��ʽ��1Ϊ���㣬0Ϊ����"<<endl;
	cin>>k;
	paint(t,h,k);//��ƽ���ı��β���

	cout<<"Writtern by Steven.J .Thanks for viewing";

	getchar();
	getchar();//getcharΪ��ֹ�������ˣ���ʵ������
	return 0;
}
