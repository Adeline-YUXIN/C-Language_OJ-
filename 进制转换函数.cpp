#include<stdio.h>
//位数小的数字适用 
void jinzhi(int n,int r)
{
	int m;
	if(n==0)
	{
		return;
	}
	else
	{
		jinzhi(n/r,r);
		m=n%r;
		if(m<10)
		{
			printf("%d",m);
		}
		else
		{
			printf("%c",'A'+m-10);
		}
	}
}
int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	jinzhi(n,r);
}
