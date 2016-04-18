#include<iostream>
#include<cstring>

using namespace std;

template<class T>
void sort(T elements[],T key,unsigned int n)
{
	if(n<1) exit(-1);
	int down=0;
	int up=n-1;
	while(1)
	{
		if(down>up)
		{
			cout<<"找不到这个元素"<<endl;
			break;
		}
		int m=(down+up)/2;
		if(key==elements[m])
		{
			cout<<"你找的元素在数组第"<<m+1<<"位！"<<endl;
			break;
		}
		if(key>elements[m])
			down=m+1;
		if(key<elements[m])
			up=m-1;
	}
}