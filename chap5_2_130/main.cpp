#include "Queue.h"

int main()
{
	ifstream in_file("E://name.txt",ios::in);
	if(!in_file)
	{
		cout<<"打开文件失败"<<endl;
		exit(-1);
	}
	Queue<string> q;
	cout<<"/***进队操作***/"<<endl;
	string tmp;
	while(!in_file.eof())
	{
		in_file>>tmp;
		q.enQueue(tmp);
		cout<<tmp<<"进队"<<endl;
		if(q.isFull())
		{
			cout<<"队列已满"<<endl;
			exit(-2);
		}
	}

	cout<<endl<<"/***队列中包含如下成员***/"<<endl;
	q.output();

	cout<<"/***出队操作***/"<<endl;
	while(!q.isEmpty())
	{
		string s;
		q.deQueue(s);
		cout<<s<<"出队"<<endl;
	}
	if(q.isEmpty())
		cout<<"/***队列已空***/"<<endl;

	getchar();
	getchar();
	return 0;

}
