#include"queue.h"

int main()
{
	Queue A;
	if(!A.setNULL()) return 1;
	for(int i=0;;i++)
	{
		if(i%8==0)
		{
			int k=A.enqueue();
			cout<<i<<"秒：第"<<k<<"人入队"<<endl;
		}
		if(A.full())
		{
			cout<<"该窗口排队人数已超过50人，请分流"<<endl;
			break;
		}

		if(i%25==0)
		{
			int t=A.getfirst();
			cout<<"\t"<<i<<"秒：第"<<t<<"人出队"<<endl;
		}
	}

	A.clear();

	cout<<"Written by Steven J.Thanks for viewing."

	getchar();
	getchar();
	return 0;
}