#include"String.h"
//�������������
ostream& operator<<(ostream& os,String& str)
{
	os<<str.m_data;
	return os;
}

istream& operator>>(istream& input,String& s)
{
	char temp[255];
	input>>setw(255)>>temp;
	s=temp;
	return input;
}

//���캯��
String::String(void)
{
	m_data=new char[1];
	strcpy(m_data,"\0");
	count++;
}

String::String(const char* str)
{
	m_data=new char[strlen(str)+1];
	strcpy(m_data,str);
	count++;
}

String::String(const String& other)
{
	if(!other.m_data) m_data=0;
	else
	{
		m_data=new char[strlen(other.m_data)+1];
		strcpy(m_data,other.m_data);
	}
	count++;
}

String::String(const char*str,int n)
{
	if(!str)m_data=0;
	else
	{
		m_data=new char[n*strlen(str)+1];
		strcpy(m_data,str);
		if(n>1)
		{
			for(int t=0;t<n-1;t++)
				strcat(m_data,str);
		}
	}
	count++;
}


//��ֵ��������
String& String::operator=(const char* other)
{
	delete []m_data;
	m_data=new char[strlen(other)+1];
	strcpy(m_data,other);
	return *this;
}

String& String::operator=(const String& other)
{
	if(&other!=this)
	{
		m_data=new char[strlen(other.m_data)+1];
		strcpy(m_data,other.m_data);
	}
	return *this;
}


//[]�±�����
char& String::operator[](unsigned int e)
{
	if (e>=0&&e<=strlen(m_data))
		return m_data[e];
	else
	{
		cerr<<"�±�Խ�����\n"<<endl;
		exit(-1);
	}
}

//����Ч����
size_t String::size()
{
	return strlen(m_data);
}

//����+�����
String operator+(const String&str1,const String&str2)
{
	String temp;
	temp.m_data=new char[strlen(str1.m_data)+strlen(str2.m_data)+100];
	//int i=strlen(str1.m_data)+strlen(str2.m_data)+1;
	//cout<<i;
	strcpy(temp.m_data,str1.m_data);
	strcat(temp.m_data,str2.m_data);
	return temp;
}


//==����
bool operator==(const String&str1,const String&str2)
{
	return strcmp(str1.m_data,str2.m_data)==0;
}

bool operator==(const String&str1,const char*str2)
{
	String s(str2);
	return str1==s;
}

bool operator==(const char*str1,const String&str2)
{
	String s(str1);
	return s==str2;
}

//!=����
bool operator!=(const String&str1,const String&str2)
{
	return !(str1==str2);
}

bool operator!=(const String&str1,const char*str2)
{
	return !(str1==str2);
}

bool operator!=(const char*str1,const String&str2)
{
	return !(str1==str2);
}

//<����
bool operator<(const String&str1,const String&str2)
{
	int n=strcmp(str1.m_data,str2.m_data);
	if(n<0)return true;
	else return false;
}

bool operator<(const String&str1,const char*str2)
{
	String s(str2);
	return str1<s;
}

bool operator<(const char*str1,const String&str2)
{
	String s(str1);
	return s<str2;
}


//>����
bool operator>(const String&str1,const String&str2)
{
	int n=strcmp(str1.m_data,str2.m_data);
	if(n>0)return true;
	else return false;
}

bool operator>(const String&str1,const char*str2)
{
	String s(str2);
	return str1>s;
}

bool operator>(const char*str1,const String&str2)
{
	String s(str1);
	return s>str2;
}

//�������
void String::output()
{
	cout<<m_data;
}

int String::get_count()
{
	return count;
}

int String::count=0;
//��������
String::~String()
{
	delete[] m_data;
	m_data=NULL;
	count--;
}