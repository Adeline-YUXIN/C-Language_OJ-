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
	printf("请输入数字总数："); 
	scanf("%d",&n);
	printf("请输入数字（以空格间隔开）：");
	for(i=0;i<n;i++)
	{
		scanf(" %d",&a[i]);
	}
	selection_sort(a,i);
	printf("排序后的数字顺序为：");
	for(i=i-1;i>=0;i--)
	{
		printf("%d ",a[i]);
	}
	printf("好耶！");
	return 0;
}
