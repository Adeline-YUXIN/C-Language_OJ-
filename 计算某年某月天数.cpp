#include<stdio.h>
int main(void)
{
	int y,m;
	scanf("%d %d",&y,&m);
	if(y%400==0)
	{
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			printf("31");
			return 0;
		}
		if(m==2)
		{
			printf("29");
			return 0;
		}
		else
		{
			printf("30");
			return 0;
		}
	}
	if(y%400!=0)
	{
		if(y%100==0)
		{if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			printf("31");
			return 0;
		}
		if(m==2)
		{
			printf("28");
			return 0;
		}
		else
		{
			printf("30");
			return 0;
			
			
		}}
	else
	{
		if(y%4==0)
		{
		if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			printf("31");
			return 0;
		}
		if(m==2)
		{
			printf("29");
			return 0;
		}
		else
		{
			printf("30");
			return 0;
			
		} 
		}
		if(y%4!=0)
		{
			if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)
		{
			printf("31");
			return 0;
		}
		if(m==2)
		{
			printf("28");
			return 0;
		}
		else
		{
			printf("30");
			return 0;
		}
	    }

    
    } }    
	return 0;
}
