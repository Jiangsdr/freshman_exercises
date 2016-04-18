#include<iostream>
#include<cstring>
using namespace std;

#define Max_line 100


int main()
{
	char word[Max_line][Max_line];
	int i=0;char temp[Max_line];
	cout<<"请输入若干单词，以0结束"<<endl;
	while(1)
	{
		cin>>word[i];
		if(!strcmp(word[i],"0"))
			break;
		else
			i++;
		if(i>=Max_line)
			break;
	}//数组输入部分


	cout<<"按字典顺序排列后为"<<endl;

	for(int j=0;j<i;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if(strcmp(word[j],word[k])>0)
			{
				strcpy(temp,word[j]);
				strcpy(word[j],word[k]);
				strcpy(word[k],temp);
			}
		}
	}

	for(int j=0;j<i;j++)
	{
		cout<<word[j]<<endl;
	}

	cout<<"Writtern by Steven.J .Thanks for viewing";
	return 0; 
}
		
