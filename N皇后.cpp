#include <stdio.h>
#include <math.h>
int N;
int queenpos[100];
void Nqueen(int k);
int main()
{
 scanf("%d",&N);
 Nqueen(0);
 return 0;
}
 
void Nqueen(int k)
{
    int i;//ע�⣡!�����ڿ�ͷ����
 if(k==N)
 {
  for(i=0;i<N;i++)
  {
   printf("%d\t",queenpos[i]+1);
  }
  printf("\n");
  return;
 }
 
 
  for(i=0;i<N;i++)
  {   int j;//ͬ��ע�⣡
   for(j=0;j<k;j++)
   {
    if(queenpos[j]==i||abs(queenpos[j]-i)==abs(k-j))
    {
     break;
    }
   }
   if(j==k){
    queenpos[k]=i;
       Nqueen(k+1);//ע��λ�ã�
   }
   
  }
  
 }
