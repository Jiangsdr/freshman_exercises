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
	friend ostream& operator <<(ostream&,String&);//����<<�����
	friend istream& operator >>(istream&,String&);//����>>�����
	friend String operator+(const String&,const String&);
	friend String operator+(const String&,const char*);
	friend String operator+(const char*,const String&);//����+������
	friend bool operator<(const String&,const String&);
	friend bool operator<(const String&,const char*);
	friend bool operator<(const char*,const String&);//����<������
	friend bool operator>(const String&,const String&);
	friend bool operator>(const String&,const char*);
	friend bool operator>(const char*,const String&);//����>������
	friend bool operator==(const String&,const String&);
	friend bool operator==(const String&,const char*);
	friend bool operator==(const char*,const String&);//����==������
	friend bool operator!=(const String&,const String&);
	friend bool operator!=(const String&,const char*);
	friend bool operator!=(const char*,const String&);//����!=������
public:
	String(void);//Ĭ�Ϲ��캯��
	String(const char*s);//�ַ������ʼ��
	String(const String& other);//��������
	String(const char*ch,int n);//��n��ch��ֵ������
	String& operator=(const char* other);
	String& operator=(const String &other);//���ظ�ֵ������
	char& operator[](unsigned int);//����[]������
	void output();//���String����
	size_t size();//��String�������Ч�ַ�����
	static int get_count();//���ض������
	~String(void);//��������
private:
	char* m_data;//���������ַ���
	static int count;//���������������еĶ������
};