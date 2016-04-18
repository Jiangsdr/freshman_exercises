#include<iostream>
#include<Windows.h>
using namespace std;

class Figure
{
public:
	virtual void draw() const=0;
	virtual void input_data()=0;
	virtual double area() const=0;
};

class REctangle:public Figure
{
	double left,top,right,bottom;
public:
	void draw() const;//»­¾ØÐÎ
	void input_data();
	double area() const;
};

class Circle:public Figure
{
	double x,y,r;
public:
	void draw() const;//»­Ô²
	void input_data();
	double area() const;
};

class Line:public Figure
{
	double x1,y1,x2,y2;
public:
	void draw() const;//»­Ö±Ïß
	void input_data();
	double area() const;
};

