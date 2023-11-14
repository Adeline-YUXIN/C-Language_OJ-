#include"stdio.h"
int main()
{
    int n,i,j,m,temp=0;
    int a[5000]={0};
    a[0]=1;a[1]=1;
    for(i=2;i<5000;i++)
       {
           a[i]=0;
           for(j=1;j<=i/2;j++)
            if(i%j==0)
            a[i]+=j;
          }
          scanf("%d",&n);
          while(n--)
          {
       
              scanf("%d",&m);
              
              for(i=0;i<=1000;i++)         
                {
                  if(m==a[i])
                  {
                      
                      temp=1;
                      break;
                      
                  }
              
              }
              if(temp==0)
              printf("yes\n");
              else
              printf("no\n");
          }
    return 0;
}
