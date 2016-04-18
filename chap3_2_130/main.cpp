#include"String.h"
bool compare(String&a,String&b)
{
	return a<b;
}

int main()
{
	String s1;
	String s2("are");
	String s3(s2);
	String s4("!",3);
	cout<<"s1="<<s1<<endl<<"s2="<<s2<<endl<<"s3="<<s3<<endl<<"s4="<<s4<<endl;

	s1="How "+s2+" you"+s4;
	cout<<"在执行了s1=\"How \"+s2+\" you\"+s4之后"<<s1<<endl;

	cout<<"逐个字符输出s1，调用下标表示符"<<endl;
	for(int i=0;i<s1.size();i++)
		cout<<s1[i];
	cout<<endl;

	cout<<endl;
	cout<<"输入输出重载测试部分:"<<endl;
	cout<<"请输入s5,s6"<<endl;
	String s5,s6;
	cin>>s5>>s6;
	cout<<s5<<s6;
	cout<<endl;

	cout<<"在一个vector<String>对象中放入以下单词"<<endl;
	vector<String>st;
	st.push_back("how");
	st.push_back("are");
	st.push_back("are");
	st.push_back("you");
	for(int i=0;i<4;i++)
		cout<<st[i]<<endl;

	cout<<"排序后（调用sort函数）"<<endl;
	sort(st.begin(),st.end(),compare);
	for(int i=0;i<4;i++)
		cout<<st[i]<<endl;

	cout<<"删去重复单词后"<<endl;
	int i=st.size();
	for(int j=0;j<st.size()-1;j++)
	{
		for(int t=j+1;t<st.size();t++)
		{
			if(st[j]==st[t])
			{
			     st.erase(st.begin()+t-1);
			     i--;
			}
		}
	}

	for(int s=0;s<i;s++)
		cout<<st[s]<<endl;

	cout<<"正在运行的对象个数为"<<String::get_count()<<endl;
	cout<<"由于重复的单词已删除，故正在运行的对象-1"<<endl;

	String s9,s10;
	cout<<"请输入两个字符串"<<endl;
	cin>>s9>>s10;
	cout<<"你输入的字符串为"<<endl;
	cout<<s9<<endl<<s10<<endl;

	cout<<"Written by Steven J.Thanks for watching!"<<endl;

	getchar();
	getchar();
	return 0;
}