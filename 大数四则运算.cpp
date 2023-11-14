//#include<stdio.h>
//#include<string.h>
//int main(){
//    char a[10000],b[10000];
//    int i,as,bs,k,p,sum[10000];
//    while(scanf("%s %s",a,b)!=EOF)
//    {
//       k=(strlen(a)>strlen(b))?strlen(a):strlen(b);
//       for(i=0;i<=k;i++)
//       {
//       	    sum[i]=0;
//	   }
//       p=k;
//       as=strlen(a);
//       bs=strlen(b);
//       for(k;as>0&&bs>0;k--)
//       {
//           sum[k]=sum[k]+(a[--as]-48)+(b[--bs]-48);
//           if(sum[k]/10!=0)
//           {
//               sum[k-1]++;
//               sum[k]=sum[k]%10;
//           }
//       }
//       while(as>0)
//       {
//       		as=as-1;
//            sum[k]=sum[k]+(a[as]-48);
//            k--;
//            if(sum[k+1]/10!=0)
//           {
//               sum[k]++;
//               sum[k+1]=sum[k+1]%10;
//           }
//       }
//       while(bs>0)
//       {
//       		bs=bs-1;
//            sum[k]=sum[k]+(b[bs]-48);
//            k--;
//            if(sum[k+1]/10!=0)
//           {
//               sum[k]++;
//               sum[k+1]=sum[k+1]%10;
//           }
//       }
//       printf("%s + %s = ",a,b);
//       if(sum[0]!=0) printf("%d",sum[0]);
//       for(i=1;i<=p;i++)
//       {
//            printf("%d",sum[i]);
//       }
//       printf("\n");
//   }
//   return 0;
//}
//大数减法（假设第一个数已经比第二个数大了）
#include<stdio.h>

#include<string.h>

int main(void)
{
    char s1[505],s2[505];
    while(scanf("%s%s",s1,s2)==2)
    {
        int i,j,len1,len2;
        int a[105]={0},b[105]={0};
        len1=strlen(s1);
        len2=strlen(s2);
        for(i=len1-1,j=0;i>=0;i--,j++)
        {
            a[j]=s1[i]-48;
        }
        for(i=len2-1,j=0;i>=0;i--,j++)
        {
            b[j]=s2[i]-48;
        }
        for(i=0;i<len1;i++)
        {
            a[i]=a[i]-b[i];
            if(a[i]<0)
            {
                a[i]+=10;
                a[i+1]--;
            }
        }
        i=len1-1;
        while(a[i]==0)
        {
            i--;
        }
        for(;i>=0;i--)
        {
            printf("%d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
//大数乘法
//#include<stdio.h>
//#include<string.h>
//
//
//int main(void)
//{
//    char s1[510],s2[510],temp[510];
//    int a[510],b[510],c[1010];
//    while(scanf("%s%s",s1,s2)==2)
//    {
//        int i,j,h;
//        int len1,len2;
//        if(strlen(s1)<strlen(s2))
//        {
//            strcpy(temp,s1);
//            strcpy(s1,s2);
//            strcpy(s2,temp);
//        }
//        len1=strlen(s1);
//        len2=strlen(s2);
//        memset(c,0,sizeof(c));
//        for(i=len1-1,j=0;i>=0;i--,j++)
//        {
//            a[j]=s1[i]-48;
//        }
//        for(i=len2-1,j=0;i>=0;i--,j++)
//        {
//            b[j]=s2[i]-48;
//        }
//        for(i=0;i<len2;i++)
//        {
//            for(j=0;j<len1;j++)
//            {
//                c[i+j]=a[j]*b[i]+c[i+j];
//            }
//        }
//        for(i=0;i<2*len1;i++)
//        {
//            if(c[i]>=10)
//            {
//                c[i+1]=c[i+1]+c[i]/10;
//                c[i]=c[i]%10;
//            }
//        }
//        i=2*len1;
//        while(c[i]==0)
//        {
//            i--;
//        }
//        if(i<0)
//        {
//            printf("0\n");
//        }
//        else
//        {
//            for(;i>=0;i--)
//                printf("%d",c[i]);
//            printf("\n");
//        }    
//    }
//    return 0;
//}

//#include<stdio.h>
//#include<string.h>
//
//int len1,len2;
//char s1[905];
//char s2[905];
//int re[905];
//
//void sub()
//{
//    int i=0;
//    int j;
//    while(1)
//    {
//        if(s1[i]=='0')
//            i++;
//        else
//        {
//            j=i;
//            break;
//        }
//    }
//    for(;i<len2;i++)
//    {
//        s1[i]=s1[i]-s2[i]+'0';
//    }
//    for(i=len2-1;i>j;i--)    //低位开始检测是否小于0
//    {
//        if(s1[i]<'0')
//        {
//            s1[i]+=10;
//            s1[i-1]--;
//        }
//    }
//}
////大数除法 
//int main(void)
//{
//    int i,p;
//    while(scanf("%s%s",s1,s2)==2)
//    {
//        len1=strlen(s1);
//        len2=strlen(s2);
//        if(len1<len2||(len1==len2&&strncmp(s1,s2,len2)<0))   //如果a<b,直接输出0
//        {
//            printf("0\n");
//            continue;
//        }
//        p=0;
//        while(1)
//        {
//            re[p]=0;
//            while(strncmp(s1,s2,len2)>=0)       //一直进行减法，直到不能减为止
//             {
//                sub();
//                re[p]++;
//            }
//            p++;
//            if(len1==len2)
//                break;
//            for(i=len2-1;i>=0;i--)             //在s2前面补0，以便进行减法运算
//             {
//                s2[i+1]=s2[i];
//            }
//            s2[0]='0';
//            len2++;
//            s2[len2]='\0';
//        }
//        i=0;
//        while(1)
//        {
//            if(re[i]==0)
//                i++;
//            else
//                break;
//        }
//        for(;i<p;i++)
//            printf("%d",re[i]);
//        printf("\n");
//    }
//    return 0;
//}
