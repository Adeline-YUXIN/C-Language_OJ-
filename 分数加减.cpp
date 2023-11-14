#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 
int reduce(int numerator,int denominator)
{
	int k;
	if(abs(numerator)>abs(denominator))
	{
		k=abs(denominator);
	} 
	else k=abs(numerator);
	while(!(numerator%k==0&&denominator%k==0))
	{
		k--;
	}
	return k;
}
int main()
{
	int a,b,c,d,div,sum1,sum2,end1,end2,k,p,q;
	char s;
	while(scanf("%d/%d%c%d/%d",&b,&a,&s,&c,&d)!=EOF)
	{
		if(b==0&&c==0)
		{
			printf("0\n");
			continue;
		}
	
		if(b%a==0&&c%d==0&&s=='-')
		{
			printf("%d\n",b/a-c/d);
			continue; 
		}
		switch(s){
			case '+':sum1=(b*d+c*a);sum2=(a*d);break;
			case '-':sum1=(b*d-c*a);sum2=(a*d);break;
			default:break;
		}
		if(sum1==0)
		{
			printf("0\n");
			continue;
		}
		div=reduce(sum1,sum2);
		sum1=sum1/div;
		sum2=sum2/div;
		if(sum1>=0&&sum2>0)
		{
			if(sum1>sum2)
		{
			k=sum1/sum2;
			end1=sum1-k*sum2;
			if(end1==0)
			{
			printf("%d\n",k);
			 } 
			else{
			div=reduce(end1,sum2);
			end1=end1/div;
			sum2=sum2/div;
			printf("%d+%d/%d\n",k,end1,sum2);
			}
			
		}
			else if(sum1==sum2) printf("1\n");
			else if(sum1<sum2)
			{
			printf("%d/%d\n",sum1,sum2);
			}
		}
		else
		{
			if(abs(sum1)>abs(sum2))
			{
				k=abs(sum1)/abs(sum2);
				end1=abs((k+1)*abs(sum2)-abs(sum1));
				if(end1==0)
				{
				printf("%d\n",k);
				 } 
				 else
				 {
				 	div=reduce(end1,sum2);
				end1=end1/div;
				sum2=sum2/div;
				printf("-%d+%d/%d\n",k+1,end1,sum2);
				 }
			}
			else if(sum1==sum2) printf("1\n");
			else if((sum1+sum2)==0) printf("-1\n");
			else if(abs(sum1)<abs(sum2))
			{
				printf("%d/%d\n",sum1,sum2);
			}
			
		}
	}
	return 0;
}

int gcd(int x,int y)
{
	if(y==0) return x;
	else return gcd(y,x%y);
}
