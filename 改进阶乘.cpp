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
 	printf("������������ݣ��Կո���������"); 
 	scanf("%d %d",&a,&b);
 	printf("%d",power(a,b));
 	return 0;
 }
