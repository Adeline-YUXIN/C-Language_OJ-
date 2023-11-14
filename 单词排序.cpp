#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
//int up( const void *a , const void *b ) 
//{ 
//return strcmp((char*)a , (char*)b); 
//} 
int main()
{
	int k=0;
	char str[30]={'\0'},*p,*word[max];
	while(1)
	{
		int i=0;
		printf("请输入一串单词（若要停止，直接键入回车）：");
		gets(str);
		p=str;
		if(*p=='\0') break;
		for(i=0;i<k;i++)
		{
			if(strcmp(str,word[i])<0) break;
		}
		for(int j=k;j>i;j--)
		{
			word[j]=word[j-1];
		}
		word[i]=(char*)malloc(2+strlen(str)+1);
		strcpy(word[i],str);
		printf("\n");
		i++;
		k++;
	}
//	qsort(word,k-1,sizeof(char*),up);
	for(int p=0;p<k;p++)
	{
		if(p==0) printf("字典序为：%s ",word[p]);
		else printf("%s ",word[p]);
	}
	return 0;
}
