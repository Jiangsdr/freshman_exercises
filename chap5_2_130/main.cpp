#include "Queue.h"

int main()
{
	ifstream in_file("E://name.txt",ios::in);
	if(!in_file)
	{
		cout<<"���ļ�ʧ��"<<endl;
		exit(-1);
	}
	Queue<string> q;
	cout<<"/***���Ӳ���***/"<<endl;
	string tmp;
	while(!in_file.eof())
	{
		in_file>>tmp;
		q.enQueue(tmp);
		cout<<tmp<<"����"<<endl;
		if(q.isFull())
		{
			cout<<"��������"<<endl;
			exit(-2);
		}
	}

	cout<<endl<<"/***�����а������³�Ա***/"<<endl;
	q.output();

	cout<<"/***���Ӳ���***/"<<endl;
	while(!q.isEmpty())
	{
		string s;
		q.deQueue(s);
		cout<<s<<"����"<<endl;
	}
	if(q.isEmpty())
		cout<<"/***�����ѿ�***/"<<endl;

	getchar();
	getchar();
	return 0;

}
