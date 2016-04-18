#include<stdio.h>

int a[]={0,0,0,0,0,0,0,0,0,0};

void digit_count(int n)
{
	while(n>0)
	{
		int t=n%10;
		n=n/10;
		a[t]++;
	}
}

int main()
{
	int i;
	scanf("%d",&i);
	int*q=new int[i];
	for(int p=0;p<i;p++)
	scanf("%d",&q[p]);
	for(int p=0;p<i;p++)
	{
		for(int t=1;t<=q[p];t++)
		{
			digit_count(t);
		}
	    for(int k=0;k<9;k++){
	    	printf("%d ",a[k]);
	    	a[k]=0;
		}
		printf("%d\n",a[9]);
		a[9]=0;
    }
    
	return 0;
}
