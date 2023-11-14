#include<stdio.h>
#include<string.h>
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
	while(scanf("%d",&n)!=EOF)
	{
		r=8;
		jinzhi(n,r);
		printf("\n");
	}
	return 0;
 } 
