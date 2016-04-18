#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

class String
{
	friend ostream& operator <<(ostream&,String&);//重载<<运算符
	friend istream& operator >>(istream&,String&);//重载>>运算符
	friend String operator+(const String&,const String&);
	friend String operator+(const String&,const char*);
	friend String operator+(const char*,const String&);//重载+操作符
	friend bool operator<(const String&,const String&);
	friend bool operator<(const String&,const char*);
	friend bool operator<(const char*,const String&);//重载<操作符
	friend bool operator>(const String&,const String&);
	friend bool operator>(const String&,const char*);
	friend bool operator>(const char*,const String&);//重载>操作符
	friend bool operator==(const String&,const String&);
	friend bool operator==(const String&,const char*);
	friend bool operator==(const char*,const String&);//重载==操作符
	friend bool operator!=(const String&,const String&);
	friend bool operator!=(const String&,const char*);
	friend bool operator!=(const char*,const String&);//重载!=操作符
public:
	String(void);//默认构造函数
	String(const char*s);//字符数组初始化
	String(const String& other);//拷贝构造
	String(const char*ch,int n);//用n个ch赋值给对象
	String& operator=(const char* other);
	String& operator=(const String &other);//重载赋值操作符
	char& operator[](unsigned int);//重载[]操作符
	void output();//输出String对象
	size_t size();//求String对象的有效字符个数
	static int get_count();//返回对象个数
	~String(void);//析构函数
private:
	char* m_data;//用来保存字符串
	static int count;//用来保存正在运行的对象个数
};