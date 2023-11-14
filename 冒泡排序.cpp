#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int arr[], int size) {
 //相邻元素进行比较，升序排列
 //较大者放到后面，较小者遍历一遍后放到数组首位
 //排序中 待排序区间 与 已排序区间 区分
 //[0，bound)代表已排序区间 注意 bound初始值为0
 //（bound, size]代表未排序区间
 for (int bound = 0; bound < size; bound++) {//bound从数组第一个元素开始查起
  for (int cur = size - 1; cur > bound; cur--) {//cur从数组最后一个元素查起
   if (arr[cur - 1] > arr[cur]) {//如果前一个比后一个大 则调换两者的位置
    int tem = arr[cur -1];
    arr[cur - 1] = arr[cur];
    arr[cur] = tem;
   }
  }
 }

}

int main() {
 int arry[100];
 for(int j=0;j<100;j++)
 {
 	arry[j]=100-j;
 }
 bubbleSort(arry, sizeof(arry) / sizeof(arry[0]));

 for (int i = 0; i < 100; i++) {
  printf("%d ", arry[i]);//用for循环输出数组内元素
 }
 return 0;
}
