#include<stdio.h>
int main()
{
	int i,N,k=0,j,p=0,q=0;
	char a[1000],b[1000],ch;
	printf("请输入一句话:");
	for(i=0;i<1000;i++)
	{
		a[i]=getchar();
		if(a[i]=='!'||a[i]=='?'||a[i]=='.')
		{
			ch=a[i];
			break;
		}										
	}
	N=i;
	i=i-1;
	k=i;
	for(j=0;i>=0;i--)
	{
		k=i;
		while(a[i]!=' '&&i>=0)
		{
			p=i;
			i--;
		} 
		if(i==0) p--;
		while(p<=k)
		{
			b[j]=a[p];
			p++;
			j++;
		}
		b[j]=' ';
		j++;
	}
	printf("反转句子:");
	for(q=0;q<N;q++)
	{
		printf("%c",b[q]);
	}
	printf("%c",ch);
	return 0;
	}

