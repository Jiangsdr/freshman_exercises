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
	std::istream& read(std::istream& in);//���뺯��
	double regular_grade();//ƽʱ�ɼ�
	double total_mask();//�����ɼ�
	ostream& output(ostream& out);//�������
	friend bool compare1(const Student&A,const Student&B);//����������
};



bool compare2(const Student&A,const Student&B);