#include<stdio.h>
#include<string.h>
#define STACK 100020 
char kuo[STACK/2];
int top=0;
int main()
{
	int i,posi;
	char ch;
	while(gets(kuo)!=NULL)
	{
		int num[STACK]={0};
		top=0;
		for(i=0;i<strlen(kuo);i++)
		{
			ch=kuo[i];
			if(ch=='(')
			{
				kuo[top++]=i+1;
			}
			if(ch==')')
			{
				posi=kuo[--top];
				num[posi]=i+1;
			}
		}
		for(int k=1;k<100001;k++)
		{
			if(num[k]!=0)
			{
				printf("%d %d\n",k,num[k]);
			}
		}
	}
	return 0;
 } 
