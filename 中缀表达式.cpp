#include "stdio.h"    
#include "stdlib.h"   
#include<string.h>
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status; 
typedef char SElemType; /* SElemType���͸���ʵ������������������Ϊint */

/* ˳��ջ�ṹ */
typedef struct
{
        SElemType data[MAXSIZE];
        int top; /* ����ջ��ָ�� */
}SqStack;

Status visit(SElemType c)
{
        if(c!=')') printf("%c",c);
        return OK;
}

/*  ����һ����ջS */
Status InitStack(SqStack *S)
{ 
        /* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
        S->top=-1;
        return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(SqStack *S)
{ 
        S->top=-1;
        return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
int StackEmpty(SqStack S)
{ 
        if (S.top==-1)
                return 1;
        else
                return 0;
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqStack S)
{ 
        return S.top+1;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(SqStack S,SElemType *e)
{
        if (S.top==-1)
                return ERROR;
        else
                *e=S.data[S.top];
        return OK;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack *S,SElemType e)
{
        if(S->top == MAXSIZE -1) /* ջ�� */
        {
                return ERROR;
        }
        S->top++;				/* ջ��ָ������һ */
        S->data[S->top]=e;  /* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
        return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack *S,SElemType *e)
{ 
        if(S->top==-1)
                return ERROR;
        *e=S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
        S->top--;				/* ջ��ָ���һ */
        return OK;
}

/* ��ջ����ջ�����ζ�ջ��ÿ��Ԫ����ʾ */
Status antiStackTraverse(SqStack S)
{
        int i;
        i=S.top;
        while(i>=0)
        {
                visit(S.data[i--]);
        }
        return OK;
}

Status StackTraverse(SqStack S)
{
        int i;
        i=0;
        while(i<=S.top)
        {
                visit(S.data[i++]);
        }
        return OK;
}

int level(char n)
{
	switch(n){
		case '+':return 1;break;
		case '-':return 1;break;
		case '*':return 2;break;
		case '/':return 2;break;
		case '(':return 3;break;
		case ')':return 0;break;
		default:return -1;break;
	}
}

int main()
{
	char func,a[MAXSIZE];
	char e;
	int i,flag=0,k=0,j,subject=0,m,n,delta=0,h=0;
	double sum=0;
	double H[MAXSIZE];
	SqStack S;
	InitStack(&S);
	scanf("%s",a);
	while(1)
	{
		//loop:scanf("%c",&func);
		loop:func=a[k++];
		if(subject!=0)
			{
				func=a[subject];
				k=subject+1;
				subject=0;
			}
		if(func=='\0')
		{
			antiStackTraverse(S);
			while(StackEmpty(S)!=1)
			{
				Pop(&S,&e);
			//	Push(&H,e);
				H[h]=e-'0';
				h++;
				GetTop(S,&e);
			}
			printf("\n");
		//	StackTraverse(H);
			ClearStack(&S);
			for(int u=0;u<h;u++)
			{
				if(H[u]==-8||H[u]==-7||H[u]==-6||H[u]==-5||H[u]==-3||H[u]==-1) printf("%c",(int)H[u]+48);
				else printf("%.2f",H[u]);
			}
			printf("\n");
		/*	char houzhui[StackLength(H)];
			for(i=StackLength(H);i>0;i--)
			{
				houzhui[i]=Push(&H,e);
			}
			houzhui[0]=(char)StackLength(H);*/
			
		//	printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(S));
			double houzhui[MAXSIZE];
			int point;
			point=-1;//����ʵ��ջ��ջ��ֻ������ 
			for(int u=0;u<h;u++)
			{
				if(H[u]!=-8&&H[u]!=-7&&H[u]!=-6&&H[u]!=-5&&H[u]!=-3&&H[u]!=-1)
				{
					houzhui[++point]=H[u];
					}	
				else
				{
					
						if(H[u]==-5)
					{
						houzhui[point-1]=houzhui[point]+houzhui[point-1];
						point--;
					}
					if(H[u]==-3)
					{
						houzhui[point-1]=houzhui[point-1]-houzhui[point];
						point--;
					}
					if(H[u]==-6)
					{
						houzhui[point-1]=houzhui[point]*houzhui[point-1];
						point--;
					}
					if(H[u]==-1)
					{
						if(houzhui[point]!=0) houzhui[point-1]=houzhui[point-1]/houzhui[point];
						else
						{
							printf("��ĸ����Ϊ0����\n");
							return 0;
						 } 
						point--;
					}
					
					
				}
			
			}
				printf("%.2f",houzhui[0]);//9+(3-1)*3+10/2
			return 0;
		}
		//end require
		else if(a[k-1]!='+'&&a[k-1]!='-'&&a[k-1]!='*'&&a[k-1]!='/'&&a[k-1]!='('&&a[k-1]!=')'&&a[k-1]!='\0')//numbers output
		{
			sum=0;
			subject=0;
			flag=0;
			n=k-1;
			for(j=k-1;j<=strlen(a);j++)
			{
				
				if(a[j]=='+'||a[j]=='-'||a[j]=='*'||a[j]=='/'||a[j]=='('||a[j]==')'||a[j]=='\0')
				{
					subject=j;
					break;
				}
			//	sum+=(a[j]-'0')*pow(10,flag);
			//	flag++;
			}
			m=subject-1;
			flag=subject-k-1;
			delta=0;
			for(;n<=m;n++)
			{
				if(a[n]=='.')
				{
					delta=subject-n-1;
					continue;
				}
				sum+=(a[n]-'0')*pow(10,flag);
				flag--;
			}
			func=sum/pow(10,delta)+'0';
			if(delta==0) 
			{
				H[h]=sum*10/pow(10,delta);
				h++;
				printf("%.2f",sum*10/pow(10,delta));
			}
			
			if(delta!=0)
			{
				H[h]=sum/pow(10,delta);
				h++;
				printf("%.2f",sum/pow(10,delta));
			 } 
		}
		else if(func=='+'||func=='-'||func=='*'||func=='/'||func=='('||func==')')
		{
			//printf("ջ�շ�%d(1:�� 0:��)\n",StackEmpty(S));
			if(StackEmpty(S)==1)
			{
			//	printf("!");
				Push(&S,func);
				goto loop;
			//	printf("!");
			}
			else
			{
				GetTop(S,&e);
				if(level(func)>level(e)&&level(func)!=0)
				{
					
			//		if(func=='(')
			//		{
			//			flag=1;
			//		}
					/*else*/ Push(&S,func);
					goto loop;
				}
				else if(func==')')
				{GetTop(S,&e);
				//	if(func==')')
				//	{
				//		flag=0;
				//		goto re;
				//	}
					//else Push(&S,func);
					while(e!='('&&StackLength(S)!=0)
					{
						Pop(&S,&e);
						printf("%c",e);
			//			Push(&H,e);
						H[h]=e-'0';
						h++;
						GetTop(S,&e);
					}
					Pop(&S,&e);
					goto loop;
				}
				else
				{
					GetTop(S,&e);
					//if(level(func)==level(e)) goto loop;
					while(level(func)<=level(e)&&StackLength(S)!=0/*&&flag==0*/)
					{
						/*if(level(func)==0)
						{
							while(level(e)!=3&&StackLength(S)!=0)
							{
								Pop(&S,&e);
								printf("%c",e);
								GetTop(S,&e);
							}
							if(level(e)==3)
							{
								Pop(&S,&e);
								goto loop;
							}
						}
					//	9+(3-1)*3+1/2
					// 1+2*3+(4*5+6)*7
						else if(level(e)==3)
						{
						}*/
						if(e!='(')
						{
							Pop(&S,&e);
							if(e!=')') 
							{
								printf("%c",e);
							//	Push(&H,e);
								H[h]=e-'0';
								h++;
							}
							GetTop(S,&e);
						}
						else
						{
							Push(&S,func);
							goto loop;
						}
						//printf("%c",e);
					}
				//	if(e=='(')
				//	{
				//		Pop(&S,&e);
				//		GetTop(S,&e);
				//	}
					Push(&S,func);
				}
			}
		}
		else
		{
			printf("����Ƿ��������ԡ�\n");
			return 0;
		}
	}
	return 0;
	
}


