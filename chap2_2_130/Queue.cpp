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
			cout<<i<<"�룺��"<<k<<"�����"<<endl;
		}
		if(A.full())
		{
			cout<<"�ô����Ŷ������ѳ���50�ˣ������"<<endl;
			break;
		}

		if(i%25==0)
		{
			int t=A.getfirst();
			cout<<"\t"<<i<<"�룺��"<<t<<"�˳���"<<endl;
		}
	}

	A.clear();

	cout<<"Written by Steven J.Thanks for viewing."

	getchar();
	getchar();
	return 0;
}