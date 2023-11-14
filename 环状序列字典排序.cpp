#include<stdio.h>
#include<string.h>
int less(char s[],int ans,int x)
{
    int n=strlen(s);
    for(int i=0; i<n; i++)                                             
    {                                                              
        if(s[(ans+i)%n]<s[(x+i)%n]) return  0;            
        else if(s[(ans+i)%n]==s[(x+i)%n])continue;  
        else return 1;                                                   
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        char s[1100]={'\0'};
        scanf("%s",s);
        int ans=0;
        int n=strlen(s);
        for(int i=1; i<n; i++)                                                   
        {
            if(less(s,ans,i))
                ans=i;                                                                
        }
        for(int i=0; i<strlen(s); i++)                                      
        {
            printf("%c",s[(i+ans)%n]);                                  
        }
        printf("\n");
    }
    return 0;
}
