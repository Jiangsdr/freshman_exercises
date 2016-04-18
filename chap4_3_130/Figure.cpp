#include"Figure.h"
//Rectangle
void REctangle::draw()const
{
	HWND hWnd=GetConsoleWindow();
	HDC hDC=GetWindowDC(hWnd); 
	Rectangle(hDC, left, top, right, bottom); 
	cout<<"�������Ϊ��"<<area()<<endl;
}

void REctangle::input_data() 
{
	cout<<"��������е����Ͻ���������½����꣨x1,y1,x2,y2��:"<<endl;
	cin>>left>>top>>right>>bottom;
}

double REctangle::area() const
{
	return (bottom-top)*(right-left);
}

//Circle
const double pi=3.1415926;
void Circle::draw()const
{
	HWND hWnd=GetConsoleWindow();
	HDC hDC=GetWindowDC(hWnd); 
	Ellipse(hDC,x-r, y-r, x+r, y+r);
	cout<<"Բ���Ϊ��"<<area()<<endl;
}

void Circle::input_data()
{
	cout<<"������Բ������Ͱ뾶(x,y,r):"<<endl;
	cin>>x>>y>>r;
}

double Circle::area() const
{
	return pi*r*r;
}

//Line
void Line::draw() const
{
	HWND hWnd=GetConsoleWindow();
	HDC hDC=GetWindowDC(hWnd); 
	MoveToEx(hDC, x1, y1, NULL);        
	LineTo(hDC, x2, y2);  
	cout<<"ֱ�����Ϊ��"<<area()<<endl;
}

void Line::input_data()
{
	cout<<"�������߶ε������յ�����(x1,y1,x2,y2):"<<endl;
	cin>>x1>>y1>>x2>>y2;
}

double Line::area() const
{
	return 0;
}