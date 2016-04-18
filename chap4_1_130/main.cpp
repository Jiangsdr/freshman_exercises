//#include"Student.h"
#include"Graduate.h"

int main()
{//���벿��
	ifstream in_file("E://grades_core.txt",ios::in);
	if(!in_file)
	{
		cerr<<"���ļ�ʧ��";
		return -1;
	}
	vector<Student>students;
	for(int i=0;!in_file.eof();i++)
	{
		Student st;
		st.read(in_file);
	    students.push_back(st);
	}
	in_file.close();

	ifstream in_file2("E://grades_grad.txt",ios::in);
	if(!in_file2)
	{
		cerr<<"���ļ�ʧ��";
		return -1;
	}
	vector<Graduate>graduates;
	for(int i=0;!in_file2.eof();i++)
	{
		Graduate gr;
		gr.read(in_file2);
	    graduates.push_back(gr);
	}
	in_file2.close();
	

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
		sort(graduates.begin(),graduates.end(),compare1);
	}
	if(t==2)
	{
		sort(students.begin(),students.end(),compare2);
		sort(graduates.begin(),graduates.end(),compare2);
	}

//�������
	ofstream out_file("E://grades_core.txt",ios::out);
	out_file<<"����\t"<<"�����ɼ�"<<endl;
	int s=students.size();
	for(int i=0;i<s;i++)
	students[i].output(out_file);

	out_file.close();

	ofstream out_file2("E://grades_grad.txt",ios::out);
	out_file2<<"����\t"<<"����\t"<<"�����ɼ�"<<endl;
	int p=graduates.size();
	for(int i=0;i<p;i++)
	graduates[i].output(out_file2);

	out_file2.close();

	cout<<"Written by Steven J. Thanks for watching!"

	getchar();
	getchar();
	return 0;
}