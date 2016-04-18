#include"FigureGroup.h"

void FigureGroup::display_figures()
{
	for(int i=0;i<num_of_figures;i++)
		figures_buf[i]->draw();
}

void FigureGroup::input_figures_data()
{
	for(num_of_figures=0;num_of_figures<MAX_NUM_OF_FIGURES;num_of_figures++)
	{
		int shape;
		do
		{
			cout<<"������ͼ�ε����ࣨ0���߶Σ�1�����Σ�2��Բ��-1��������:"<<endl;
			cin>>shape;
		}while(shape<-1||shape>2);
		if(shape==-1) break;
		switch(shape)
		{
		case LINE:
			figures_buf[num_of_figures]=new Line;
			break;
		case RECTANGLE:
			figures_buf[num_of_figures]=new REctangle;
			break;
		case CIRCLE:
			figures_buf[num_of_figures]=new Circle;
			break;
		}
		figures_buf[num_of_figures]->input_data();
	}
}