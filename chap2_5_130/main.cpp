#include"Student.h"

int main()
{//输入部分
	ifstream in_file("E://grades.txt",ios::in);
	if(!in_file)
	{
		cerr<<"打开文件失败";
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
	ofstream out_file("E://grades.txt",ios::out);
	out_file<<"姓名\t"<<"总评成绩"<<endl;
	int s=students.size();
	for(int i=0;i<s;i++)
	students[i].output(out_file);

	out_file.close();

	getchar();
	getchar();
	return 0;
}
