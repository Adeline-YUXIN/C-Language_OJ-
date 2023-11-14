#include<stdio.h>
int a[32];
int two(int n) {
    int i=0,k;
    for (;n>0;n/=2)
	{
		a[i++]=n%2;	
	} 
	k=i-1; 
	return k;
}
int main()
{
	int sta=1,end=1000,q=0,b=0;
	while(sta<=end)
	{
		int n,p,s=0,m=0;
		n=sta;
		p=two(n);
		for(;p>=0;p--)
		{
			if(a[p]==1)
			{
				s++;
			}
			if(a[p]==0)
			{
				m++;
			}
		}
		if(s>m)
		{
			 q++;
		}
		else b++;
		sta++;
	}
	printf("%d %d",q,b);
	return 0;
}
