#include<stdio.h>
#include<string.h>
int mod(char str[],int c)
{
    int number[100000];
    for(int i=0;i<strlen(str);i++)
     number[i]=str[i]-'0';
    int sum=0;//10000000000000000 4294967296 
    for(int i=0;i<strlen(str);i++)//大数取模就是按照每一位取模,不断重复
    {
        sum=((long long)sum*10+number[i])%c;
    }
    return sum;
}
int main()
{
	char a[100005]={'\0'};
	int b;
	while(scanf("%s %d",a,&b)!=EOF)
	{
		printf("%lld\n",(long long)mod(a,b));
	}
	return 0;
}
