#include<stdio.h>  
#include<string.h>  
char a[10000],b[10000];//�������ַ�������������������   
int x[10000],y[10000],z[10000],m[10000];//������  ����  ��  ����   
int digit;//������λ��   
void sub(int x[],int y[],int len1,int len2)//��������   
{  
    int i;  
    for(i=0;i<len1;i++)  
    {  
        if(x[i]<y[i])  
        {  
            x[i]=x[i]+10-y[i];  
            x[i+1]--;  
        }  
        else  
            x[i]=x[i]-y[i];  
    }  
    for(i=len1-1;i>=0;i--)//�жϼ�������֮�󣬱�������λ��   
    {  
        if(x[i])  
        {   
            digit=i+1;  
            break;           
        }   
    }  
}  
int judge(int x[],int y[],int len1,int len2)  
{  
    int i;  
    if(len1<len2)  
        return -1;  
    if(len1==len2)//��������λ�����   
    {  
        for(i=len1-1;i>=0;i--)  
        {  
            if(x[i]==y[i])//��Ӧλ�������   
                continue;  
            if(x[i]>y[i])//������ ���� ����������ֵΪ1   
                return 1;  
            if(x[i]<y[i])//������ С�� ����������ֵΪ-1   
                return -1;  
        }  
        return 0;//������ ���� ����������ֵΪ0   
    }     
}  
int main()  
{  
    int i,j=0,k=0,temp;  
    int len1,len2,len;//len��������λ���Ĳ�ֵ     
    while(~scanf("%s %s",a,b))  
    {  
        len1=strlen(a);//������λ��  
        len2=strlen(b);//����λ��  
        for(i=len1-1,j=0;i>=0;i--)//���ַ����и���Ԫ�ص��򴢴���������   
            x[j++]=a[i]-'0';  
        for(i=len2-1,k=0;i>=0;i--)  
            y[k++]=b[i]-'0';              
        if(len1<len2)//��������λ�� С�� ����λ��ʱ   
        {  
            printf("���ǣ�0\n");  
            printf("�����ǣ�");  
            puts(a);   
        }  
        else //��������λ�� ���ڻ��� ����λ��ʱ  
        {  
            len=len1-len2;//��������λ���Ĳ�ֵ  
            for(i=len1-1;i>=0;i--)//���������㣬ʹ����������λ����ͬ����������4541543329 ������98745,�����:9874500000   
            {  
                if(i>=len)  
                    y[i]=y[i-len];  
                else  
                    y[i]=0;  
            }  
            len2=len1;//������������λ��ͬ         
            digit=len1; //��ԭ������λ����ֵ��digit   
            for(j=0;j<=len;j++)  
            {  
                z[len-j]=0;  
                while(((temp=judge(x,y,len1,len2))>=0)&&digit>=k)//�ж�������֮��Ĺ�ϵ�Լ�λ�������ԭλ���Ĺ�ϵ   
                {     
                    sub(x,y,len1,len2); //������������                  
                    z[len-j]++;//�����̵�ÿһλ  
                    len1=digit;//�����޸ı������ĳ���  
                    if(len1<len2&&y[len2-1]==0)        
                        len2=len1;//��len1���ȸ���len2;                        
                }  
                if(temp<0)//�������� С�� ������������Сһλ�����磺��������4541543329 ������(ԭ)98745,(�����)9874500000������һλ��:0987450000   
                {  
                    for(i=1;i<len2;i++)  
                        y[i-1]=y[i];  
                    y[i-1]=0;  
                    if(len1<len2)   
                        len2--;                                           
                }  
            }    
            for(i=len1;i>0;i--)  
            {  
                if(x[i])  
                    break;  
            }  
            for(;i>=0;i--)  
                printf("%d",x[i]);  
            printf("\n");  
        }  
    }  
    return 0;  
}
