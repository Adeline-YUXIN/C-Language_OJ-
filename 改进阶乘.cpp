#include<stdio.h>
int power(int x,int n)
{
	int pow;
	if(n%2==0&&n>0)
	{
		return power(x,n/2)*power(x,n/2);
	}
	if(n%2!=0)
	{
		return x*power(x,n-1); 
	}
	if(n==0)
	{
		return 1;
	}
 } 
 int main()
 {
 	int a,b;
 	printf("请输入底数与幂（以空格间隔开）："); 
 	scanf("%d %d",&a,&b);
 	printf("%d",power(a,b));
 	return 0;
 }
