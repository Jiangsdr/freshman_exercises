#include"Graduate.h"
std::istream& Graduate::read(std::istream& in)
{
	in>>name>>mid_grade>>final_grade;
	for(int i=0;i<6;i++)
	{
	    int nTmp;
		in>>nTmp;
		homework.push_back(nTmp);
	}
	in>>paper_grade;
	return in;
}

ostream& Graduate::output(ostream& out)
{
    out<<name<<"\t"<<g_total_mask()<<"\t"<<"G"<<endl;
    return out;
}

double Graduate::g_total_mask()
{
	return total_mask()<paper_grade?total_mask():paper_grade;
}

