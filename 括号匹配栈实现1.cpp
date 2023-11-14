#include<iostream>
using namespace std;
#include<string.h>
int main()
{
	char str[100005];
while(cin>>str)
{
	int p[100005]={0},s[50005],i=0,top=0,pos;
while(i<strlen(str)){
   if(str[i]=='(') s[top++]=i+1;
   if(str[i]==')'){
	pos=s[--top];
	p[pos]=i+1;
}
    i++;
}
for(i=1;i<100001;i++)
if(p[i]) printf("%d %d\n",i,p[i]);
}
return 0;
}

