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
	cout<<"��ִ����s1=\"How \"+s2+\" you\"+s4֮��"<<s1<<endl;

	cout<<"����ַ����s1�������±��ʾ��"<<endl;
	for(int i=0;i<s1.size();i++)
		cout<<s1[i];
	cout<<endl;

	cout<<endl;
	cout<<"����������ز��Բ���:"<<endl;
	cout<<"������s5,s6"<<endl;
	String s5,s6;
	cin>>s5>>s6;
	cout<<s5<<s6;
	cout<<endl;

	cout<<"��һ��vector<String>�����з������µ���"<<endl;
	vector<String>st;
	st.push_back("how");
	st.push_back("are");
	st.push_back("are");
	st.push_back("you");
	for(int i=0;i<4;i++)
		cout<<st[i]<<endl;

	cout<<"����󣨵���sort������"<<endl;
	sort(st.begin(),st.end(),compare);
	for(int i=0;i<4;i++)
		cout<<st[i]<<endl;

	cout<<"ɾȥ�ظ����ʺ�"<<endl;
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

	cout<<"�������еĶ������Ϊ"<<String::get_count()<<endl;
	cout<<"�����ظ��ĵ�����ɾ�������������еĶ���-1"<<endl;

	String s9,s10;
	cout<<"�����������ַ���"<<endl;
	cin>>s9>>s10;
	cout<<"��������ַ���Ϊ"<<endl;
	cout<<s9<<endl<<s10<<endl;

	cout<<"Written by Steven J.Thanks for watching!"<<endl;

	getchar();
	getchar();
	return 0;
}