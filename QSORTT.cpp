#include <stdio.h>    
#include <string.h>
#include <ctype.h>      
#include <stdlib.h>   
#include <io.h>  
#include <math.h>  
#include <time.h>
#include<iostream>
void swap(int a[],int i,int j) 
{ 
	int temp=a[i]; 
	a[i]=a[j]; 
	a[j]=temp; 
}
int Partition(int a[],int low,int high)
{
    int pivot = a[low];//作为临时变量保存
    while(low<high)
    {
        while(low<high && a[high]>=pivot)
            high--;//low<high一定要加上,否则会出现low超过high，然后赋值就会出问题，见栗子9,2,3,4,5,1,2,6,5,10
        swap(a,low,high);
        while(low<high && a[low]<=pivot)
            low++;
        swap(a,low,high);
    }
    a[low] = pivot;
    return low;
}
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int pivot = Partition(a,low,high);
        QuickSort(a,low,pivot-1);
        QuickSort(a,pivot+1,high);
    }
    else return;
}
void QSort(int a[],int size)
{
    int high = size-1;
    QuickSort(a,0,high);
}
int main() {
	//using namespace std;
    int size = 5;
    double n,m,o;
    int a[5];
    int b[5];
    int c[5];
    //产生随机数
    srand((unsigned)time(NULL));
    for(int i=0;i<size;i++){
        a[i] = rand()%10000;
    }
    for(int i= 0;i < size;i++){
        b[i] = 0;
    }
    for(int i = size;i >0;i--){
        c[i] = i;
    }
    //计算时间复杂度
    clock_t start,end;
    start = clock();
    QSort(a,size);
    end = clock();
    n=1000*(double)(end-start)/CLOCKS_PER_SEC;
    start = clock();
    QSort(b,size);
    end = clock();
    m=1000*(double)(end-start)/CLOCKS_PER_SEC;
    start = clock();
    QSort(c, size);
    end = clock();
    o=1000*(double)(end-start)/CLOCKS_PER_SEC;
    printf("%f\n",n);
    printf("%f\n",m);
    printf("%f\n",o);
    /*cout<<endl;
    cout<<"(随机数组)快速排序函数所用的时间为："<<n<<"ms"<<endl;
    cout<<"(顺序数组)快速排序函数所用的时间为："<<m<<"ms"<<endl;
    cout<<"(倒序数组)快速排序函数所用的时间为："<<o<<"ms"<<endl;*/
    return 0;
}
