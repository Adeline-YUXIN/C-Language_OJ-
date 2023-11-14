#include<stdio.h>
#include<string.h>
void tou(char a[],int s)
{
	int i=0;
	for(;i<=s;i++)
	{
		if(a[i]>='A'&&a[i]<='Z')
		{
			a[i]=a[i]+'a'-'A';
		}
	}
}
char str[10000005];
int main()
{
	freopen("test1.in","r",stdin);
	freopen("test.out","w",stdout);
	int s1,s2,sum=0,first,k,p;
	char ch[15]={'\0'};
	gets(ch);
	gets(str);
	s1=strlen(ch);
	s2=strlen(str);
	tou(ch,s1);
	tou(str,s2);
	for(int j=0;j<s2;j++)
	{
		if(str[j]==ch[0]&&(str[j-1]==' '||j==0))
		{
			k=j;
			for(p=0;p<s1;p++,k++)
			{
				if(str[k]!=ch[p]) break;
			}
			if(p==s1)
			{
				if(sum==0)first=j;
				sum++;
			}
		}
	}
	if(sum!=0) printf("%d %d",sum,first);
	if(sum==0) printf("-1");
	return 0;
}
//

