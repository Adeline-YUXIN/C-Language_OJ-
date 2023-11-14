#include <stdio.h>
int mod(char a[],int n)
{
	int s=0;
	for(int i=0;a[i]!='\0';i++)
	{
		s=(s*10+a[i]-'0')%n;
	}
	return s;
}
int main()
{
 int n,i,j,m,k,a,w[40000],col=0;
 char ch[40000]={'\0'};
 while(scanf("%d",&n)!=EOF)
 {
  w[0]=1;
  k=0;
  for(i=1;i<=n;i++)
  {
   m=0;
   for(j=0;j<=k;j++)
   {
    a=w[j]*i+m;
    m=a/10;
    w[j]=a%10;
   }
   while(m>0)
   {
    k++;
    w[k]=m%10;
    m=m/10;
   }
  }
  for(col=0,i=k;i>=0;i--,col++)
  {
  	ch[col]=w[i]+'0';
  }
   printf("%d",mod(ch,2009));
 printf("\n");
 }
}
