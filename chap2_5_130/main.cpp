#include"Student.h"

int main()
{//���벿��
	ifstream in_file("E://grades.txt",ios::in);
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
	ofstream out_file("E://grades.txt",ios::out);
	out_file<<"����\t"<<"�����ɼ�"<<endl;
	int s=students.size();
	for(int i=0;i<s;i++)
	students[i].output(out_file);

	out_file.close();

	getchar();
	getchar();
	return 0;
}
