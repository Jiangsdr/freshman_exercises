#include"Student.h"


class Graduate:public Student
{
private:
	double paper_grade;
public:
	std::istream& read(std::istream& in);//输入函数
	ostream& output(ostream& out);//输出函数
	double total_mask();//总评成绩
};