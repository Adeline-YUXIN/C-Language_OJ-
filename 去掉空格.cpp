#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[90],*p,a[90],*q,*y;
	int k=0;
	memset(str,'\0',sizeof(str));
	while(gets(str)!=NULL)
	{
		p=strtok(str," ");
		a[k++]=atoi(p);
		while((p=strtok(NULL," "))!=NULL)
		{
			a[k++]=atoi(p);
		}
		q=a;
		y=str;
		for(;*y!=NULL;y++)
		{
			for(;*q!=NULL;q++)
			{
				if(*y==*q) printf("%c",*q);				
			}

		}
		printf("\n");
	}
	return 0;
 } 
