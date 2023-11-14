#include<stdio.h>
#include<string.h>
int main(){
    char a[10000],b[10000];
    int i,as,bs,k,p,sum[10000];
    while(scanf("%s %s",a,b)!=EOF)
    {
       k=(strlen(a)>strlen(b))?strlen(a):strlen(b);
       for(i=0;i<=k;i++)
       {
       	    sum[i]=0;
	   }
       p=k;
       as=strlen(a);
       bs=strlen(b);
       for(k;as>0&&bs>0;k--)
       {
           sum[k]=sum[k]+(a[--as]-48)+(b[--bs]-48);
           if(sum[k]/10!=0)
           {
               sum[k-1]++;
               sum[k]=sum[k]%10;
           }
       }
       while(as>0)
       {
       		as=as-1;
            sum[k]=sum[k]+(a[as]-48);
            k--;
            if(sum[k+1]/10!=0)
           {
               sum[k]++;
               sum[k+1]=sum[k+1]%10;
           }
       }
       while(bs>0)
       {
       		bs=bs-1;
            sum[k]=sum[k]+(b[bs]-48);
            k--;
            if(sum[k+1]/10!=0)
           {
               sum[k]++;
               sum[k+1]=sum[k+1]%10;
           }
       }
       printf("%s + %s = ",a,b);
       if(sum[0]!=0) printf("%d",sum[0]);
       for(i=1;i<=p;i++)
       {
            printf("%d",sum[i]);
       }
       printf("\n");
   }
   return 0;
}
