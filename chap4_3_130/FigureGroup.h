#include"Figure.h"
const int MAX_NUM_OF_FIGURES=100;
enum FigureShape{LINE,RECTANGLE,CIRCLE};

class FigureGroup
{
	Figure *figures_buf[MAX_NUM_OF_FIGURES];
	int num_of_figures;
public:
	FigureGroup(){num_of_figures=0;}
	void display_figures();//ͨ����̬�󶨵�����Ӧ��draw
	void input_figures_data();//ͨ����̬�󶨵�����Ӧ��input_data
};