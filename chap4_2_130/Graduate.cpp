#include"Graduate.h"
std::istream& Graduate::read(std::istream& in)
{
	in>>name>>mid_grade>>final_grade;
	for(int i=0;i<6;i++)
	{
	    double nTmp;
		in>>nTmp;
		homework.push_back(nTmp);
	}
	in >> paper_grade;
	return in;
}

ostream& Graduate::output(ostream& out)
{
    out<<name<<"\t\t"<<Graduate::total_mask()<<"\t\t"<<"G"<<endl;
    return out;
}

double Graduate::total_mask()
{
	int t=0.4*regular_grade()+0.2*mid_grade+0.4*final_grade;
	return t<paper_grade?t:paper_grade;
}

