#include<stdio.h>
long long int fi[100];
void fib()
{
	int i;
	fi[0]=0;
	fi[1]=1;
	for(i=2;i<100;i++)
	{
		fi[i]=fi[i-1]+fi[i-2];
	}
	return ;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		fib();
		if(n==-1) break;
		printf("%lld\n",fi[n]);
	}
	return 0;
}
