#include"Student.h"


class Graduate:public Student
{
private:
	double paper_grade;
public:
	std::istream& read(std::istream& in);//���뺯��
	ostream& output(ostream& out);//�������
	double total_mask();//�����ɼ�
};