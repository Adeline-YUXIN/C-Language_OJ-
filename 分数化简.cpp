#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 
int reduce(int numerator,int denominator)
{
	int k;
	if(abs(numerator)>abs(denominator))
	{
		k=abs(denominator);
	} 
	else k=abs(numerator);
	while(!(numerator%k==0&&denominator%k==0))
	{
		k--;
	}
	return k;
}
int main()
{
	int a,b,c,d,div,sum1,sum2,end1,end2,k,p,q;
	while(scanf("%d %d %d %d",&b,&a,&c,&d)!=EOF)
	{
		if(b==0&&c==0)
		{
			printf("0\n");
			continue;
		}
	
		sum1=(b*d+c*a);
		sum2=(a*d);
		
		if(sum1==0)
		{
			printf("0\n");
			continue;
		}
		div=reduce(sum1,sum2);
		sum1=sum1/div;
		sum2=sum2/div;
		printf("%d %d\n",sum1,sum2);
	}
	return 0;
}
