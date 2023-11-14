#include<stdio.h>
#include <stdlib.h>
int up(const void *a,const void *b)
  {
      return *(int*)a-*(int*)b;
  }  
int main()
{
	int num,a[400000],n,m,i=0,s=0,k;
	scanf("%d",&n);
	m=n;
	while(n>0)
	{
		scanf("%d",&num);
		a[i]=num;
		i++;
		n--;
	}
	qsort(a,m-1,sizeof(int),up);
	for(i=0;i<m;i++)
	{
		if(a[i]!=-1)
		{
			num=a[i];
			for(int j=0;j<m;j++)
			{
			if(a[j]==num)
			{
				s++;
				a[j]=-1;
			}
			}
			printf("%d %d\n",num,s);
			s=0;
		}
	}
	return 0;
}


