#include<stdio.h>
void selection_sort(int a[],int n)
{
	int k,m,i;
	if(n==0) return;
	for(k=0;k<n;k++)
	{
		for(i=k+1;i<n;i++)
		{
			if(a[k]<=a[i])
			{
			m=a[k];
			a[k]=a[i];
			a[i]=m;
			}

		}
	}
}
int main()
{
	int n,a[10000],i;
	printf("����������������"); 
	scanf("%d",&n);
	printf("���������֣��Կո���������");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	selection_sort(a,i);
	printf("����������˳��Ϊ��");
	for(i=i-1;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	printf("��Ү��");
	return 0;
}
