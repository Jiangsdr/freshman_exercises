//#include"Student.h"
#include"Graduate.h"

int main()
{//输入部分
	ifstream in_file("F://grades.txt",ios::in);
	if(!in_file)
	{
		cerr<<"打开文件失败";
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
	

//排序部分
	cout<<"请输入1或2，1将按姓名排序，2将按总成绩排序"<<endl;
	int t;
	cin>>t;
	if(t!=1&&t!=2)
	{
		cout<<"输入错误"<<endl;
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


//输出部分
	ofstream out_file("F://grades.txt",ios::app);
	out_file<<"姓名\t\t"<<"总评成绩"<<"\t属性"<<endl;
	int s=students.size();
	for(int i=0;i<s;i++)
	students[i]->output(out_file);

	out_file.close();

	cout<<"Written by Steven J. Thanks for watching!"<<endl;
	cout<<"Ps:Fail1的成绩少给了一个，所以我加上了一个成绩"<<endl;

	getchar();
	getchar();
	return 0;
	}