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
    virtual std::istream& read(std::istream& in);//���뺯��
	double regular_grade();//ƽʱ�ɼ�
    virtual double total_mask();//�����ɼ�
    virtual ostream& output(ostream& out);//�������
	friend bool compare1(Student*A,Student*B);//����������
};



bool compare2(Student*A,Student*B);