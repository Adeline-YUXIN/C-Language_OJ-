#include<stdio.h>
#include<string.h>
int main()
{
	char str1[10001]={0},str2[10001]={0},*n,*m,*i,str[10001]={0};
	while(gets(str1)!=NULL)
	{
		m=str1;
		n=str2;
		gets(str2);
		for(;*n!=0;n++)
		{
			str[*n]=1;
		}
		
		for(;*m!=0;m++)
		{
			if(!str[*m])
			{
				printf("%c",*m);
			}
		}
		printf("\n");
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		memset(str,0,sizeof(str));
	}
	return 0;
}
