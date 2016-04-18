#include"Binsearch.h"

int main()
{
	int a1[]={1,3,5,7,9,12,14,16,18};
	double a2[]={65.1,72.3,73.6,75.2,79.5,81.4,84.8,86.6,87.9,89.7,91.3};
	char a3[]={'0','5','7','@','a','b','e','f','g'};

	int n1=sizeof(a1)/sizeof(int);
	int n2=sizeof(a2)/sizeof(double);
	int n3=sizeof(a3)/sizeof(char);

	int key1;
	double key2;
	char key3;

	cout<<"请输入一个整数"<<endl;
	cin>>key1;
	sort(a1,key1,n1);

	cout<<"请输入一个double型数"<<endl;
	cin>>key2;
	sort(a2,key2,n2);

	cout<<"请输入一个字符"<<endl;
	cin>>key3;
	sort(a3,key3,n3);

	getchar();
	getchar();

	return 0;
}