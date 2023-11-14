#include<stdio.h>
int main()
{
	int i,N,k;
	char a[1000],ch;
	printf("请输入一句话:");
	for(i=0;i<1000;i++)
	{
		a[i]=getchar();
		if(a[i]=='!'||a[i]=='?'||a[i]=='.')
		{
			ch=a[i];
			N=i;
			k=i;
			break;
		}
	}
	printf("反转句子:");
	for(;i>=0;i--)
	{
		if(a[i]=='!'||a[i]=='?'||a[i]=='.')
		{
			printf("%c",ch);
		}
		if(a[i]==' ')
		{
			for(;i<=(N-1);i++)
			{
				printf("%c",a[i+1]);
				k--;
			}
		
		N=k;
		i=k-1;
		}
		if(a[i]!=' ')
		{
			k--;
		}
	}
	return 0;
	
}
