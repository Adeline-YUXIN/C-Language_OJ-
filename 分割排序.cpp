#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int up(const void *a,const void *b)
  {
      return *(int*)a-*(int*)b;
  } 
int main(){
 int n,temp,i=0,j,k;
 char str[1000]={'\0'};
 int  a[1000];
 char *p;
  scanf("%s",str);
  p=strtok(str,"5");
        a[i++]=atoi(p);
        while((p=strtok(NULL,"5"))!=NULL)
		{
          a[i++]=atoi(p);
  		}
   qsort(a,i,sizeof(int),up);
    for(j=0;j<i;j++)
    {
    if(j==i-1) printf("%d",a[j]);
     else printf("%d ",a[j]);	
	}

 return 0;
}
//不用strtok的方法 
#include<stdio.h>
#include<string.h>
 
 
void bubblesort(int a[], int n)//冒泡排序 
{
 for (int i = 0; i < n - 1; i++)
  for (int j = 0; j < n - 1 - i; j++)
  {
 
   if (a[j] > a[j + 1])
   {
    int temp = a[j + 1];
    a[j + 1] = a[j];
    a[j] = temp;
   }
 
  }
 for (int i = 0; i < n - 1; i++)
 {
  printf("%d ", a[i]);
 }
 printf("%d", a[n - 1]);
}
 
int main()
{
 char str[1000] = "015500551231232050775559";
 gets(str);
 int len = strlen(str);
 //printf("%d\n", len);
 int a[1000];
 int n = 0;
 int i = 0;
 while(i<len)
 {
  int k = 0;
  while (str[i] == '5'&& i < len)
  {
   
   //printf("1-----%d----%c\n",i,str[i]);
   i++;
  }
  while (str[i] != '5'&& i < len)
  {
   
   //printf("2----%d----%c----k--%d\n", i, str[i],k);
   k++;
   i++;
  }
  if (k != 0)
  {
   int num = 0;
   while (k)
   {
    num = num * 10 + (str[i - k] - '0');
    k--;
   }
   //printf("%d\n", num);
   a[n] = num;
   n++;
  }
  
 }
 bubblesort(a, n);
 return 0;
}
