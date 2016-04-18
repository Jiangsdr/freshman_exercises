#include"Student.h"
bool compare2(Student*A,Student*B)
{
	Student C(*A);Student D(*B);
	return C.total_mask()>D.total_mask();
}

bool compare1(Student*A,Student*B)
{
	return (*A).name<(*B).name;
}

bool compare(const int&x,const int&y)
{
	return x>y;
}

 std::istream& Student::read(std::istream& in)
{
	in>>name>>mid_grade>>final_grade;
	for(int i=0;i<6;i++)
	{
	    int nTmp;
		in>>nTmp;
		homework.push_back(nTmp);
	}
	return in;
}
double Student::regular_grade()
{
	sort(homework.begin(),homework.end(),compare);
	int size=homework.size();
	int mid=size/2;
	double median;
	median=(size%2==0?(homework[mid]+homework[mid-1])/2:homework[mid]);
	return median;
}

double Student::total_mask()
{
	return 0.4*regular_grade()+0.2*mid_grade+0.4*final_grade;
}

ostream& Student::output(ostream& out)
{
	if(name.size()<=7)
        out<<name<<"\t\t"<<total_mask()<<"\t\t"<<"U"<<endl;
	else
		out<<name<<"\t"<<total_mask()<<"\t\t"<<"U"<<endl;
    return out;
}