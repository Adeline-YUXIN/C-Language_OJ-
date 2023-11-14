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

char digit(int a)
{
	char b[10];
	int i;
	for (i = 0; a != 0; i++)
	{
		b[i] = a % 2 + '0';
		a /= 2;
	}
}


int main()
{
	int k;
	scanf("%d",&k);
	k=two(k);
	for(;k>=0;k--)
	{
		printf("%d",a[k]); 
	}
	return 0;
 } 
