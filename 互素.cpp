#include<stdio.h>
int main()
{
	long long int a,b;
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		while(n>0)
		{
		scanf("%lld %lld",&a,&b);
	
		int a1,b1,m,p;
		m=a;
		p=b;
		b1=b/30;
		b=b%(30*(b1+1));
		if(b>=27)
		{
			b=10;
		}
		if(b<27&&b>=25)
		{
			b=9;
		}
		if(b<25&&b>=23)
		{
			b=8;
		}
		if(b<23&&b>=19)
		{
			b=7;
		}
		if(b<19&&b>=17)
		{
			b=6;
		}
		if(b<17&&b>=13)
		{
			b=5;
		}
		if(b<13&&b>=11)
		{
			b=4;
		}
		else if(b<11&&b>=7)
		{
			b=3;
		}
		else if(b<7&&b>=5)
		{
			b=2;
		}
		else if(b<5&&b>=1)
		{
			b=1;
		}
		else if(b==0) b=0;
		b=b+b1*10;
		a1=a/30;
		a=a%(30*(a1+1));
		if(a>27)
		{
			a=10;
		}
		if(a<=27&&a>25)
		{
			a=9;
		}
		if(a<=25&&a>23)
		{
			a=8;
		}
		if(a<=23&&a>19)
		{
			a=7;
		}
		if(a<=19&&a>17)
		{
			a=6;
		}
		if(a<=17&&a>13)
		{
			a=5;
		}
		if(a<=13&&a>11)
		{
			a=4;
		}
		else if(a<=11&&a>7)
		{
			a=3;
		}
		else if(a<=7&&a>5)
		{
			a=2;
		}
		else if(a<=5&&a>1)
		{
			a=1;
		}
		else if(a==1) a=0;
		a=a+a1*10;
		if(m!=p) printf("%lld\n",b-a);
		if(m==p)
		{
			if(m%2!=0&&m%3!=0) printf("1\n");
		}
		n--;
		}
	}
	
}
