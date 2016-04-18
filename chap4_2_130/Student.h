#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;
#define Max_line 20

class Student
{
protected:
	string name;
	double mid_grade;
	double final_grade;
	vector<double>homework;
public:
    virtual std::istream& read(std::istream& in);//输入函数
	double regular_grade();//平时成绩
    virtual double total_mask();//总评成绩
    virtual ostream& output(ostream& out);//输出函数
	friend bool compare1(Student*A,Student*B);//按姓名排序
};



bool compare2(Student*A,Student*B);