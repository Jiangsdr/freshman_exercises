//#include"Student.h"
#include"Graduate.h"

int main()
{//���벿��
	ifstream in_file("F://grades.txt",ios::in);
	if(!in_file)
	{
		cerr<<"���ļ�ʧ��";
		return -1;
	}
	
	vector<Student*>students;
	for(int i=0;!in_file.eof();i++)
	{
		char a;
		in_file>>a;
		if(a==85)
		{
		    Student* st = new Student;
		    (*st).read(in_file);
	        students.push_back(st);

	    }
		if(a==71)
		{
			Graduate* gr = new Graduate;
			(*gr).read(in_file);
			students.push_back(gr);
		}
	}
	in_file.close();
	

//���򲿷�
	cout<<"������1��2��1������������2�����ܳɼ�����"<<endl;
	int t;
	cin>>t;
	if(t!=1&&t!=2)
	{
		cout<<"�������"<<endl;
		return -2;
	}


	if(t==1)
	{
		sort(students.begin(),students.end(),compare1);
	}
	if(t==2)
	{
		sort(students.begin(),students.end(),compare2);
	}


//�������
	ofstream out_file("F://grades.txt",ios::app);
	out_file<<"����\t\t"<<"�����ɼ�"<<"\t����"<<endl;
	int s=students.size();
	for(int i=0;i<s;i++)
	students[i]->output(out_file);

	out_file.close();

	cout<<"Written by Steven J. Thanks for watching!"<<endl;
	cout<<"Ps:Fail1�ĳɼ��ٸ���һ���������Ҽ�����һ���ɼ�"<<endl;

	getchar();
	getchar();
	return 0;
	}