һ����int������������ 

int num[100]; 

Sample: 

int cmp ( const void *a , const void *b ) 
{ 
return *(int *)a - *(int *)b; 
} 

qsort(num,100,sizeof(num[0]),cmp); 

������char������������ͬint���ͣ� 

char word[100]; 

Sample: 

int cmp( const void *a , const void *b ) 
{ 
return *(char *)a - *(int *)b; 
} 

qsort(word,100,sizeof(word[0]),cmp); 

������double�������������ر�Ҫע�⣩ 

double in[100]; 

int cmp( const void *a , const void *b ) 
{ 
return *(double *)a > *(double *)b ? 1 : -1; 
} 

qsort(in,100,sizeof(in[0]),cmp)�� 

�ġ��Խṹ��һ������ 

struct In 
{ 
double data; 
int other; 
}s[100] 

//����data��ֵ��С���󽫽ṹ������,���ڽṹ���ڵ�����ؼ�����data�����Ϳ��Ժܶ��֣��ο����������д 

int cmp( const void *a ,const void *b) 
{ 
return (*(In *)a).data > (*(In *)b).data ? 1 : -1; 
} 

qsort(s,100,sizeof(s[0]),cmp); 
�塢�Խṹ��������� 

struct In 
{ 
int x; 
int y; 
}s[100]; 

//����x��С�������򣬵�x���ʱ����y�Ӵ�С���� 

int cmp( const void *a , const void *b ) 
{ 
struct In *c = (In *)a; 
struct In *d = (In *)b; 
if(c->x != d->x) return c->x - d->x; 
else return d->y - c->y; 
} 

qsort(s,100,sizeof(s[0]),cmp); 
�Խṹ���������򣨶��Ǵ�С����
#include<stdlib.h>

typedef struct  item
{
    int num,length,width;
};


int comp(const void *p1,const void *p2)
{
    struct item *c=(item*)p1;
    struct item *d=(item*)p2;
    if(c->num!=d->num)
    {
        return d->num<c->num?1:-1;
    }
    else if(c->length!=d->length&&c->num==d->num)
    return d->length<c->length?1:-1;
    else return d->width<c->width?1:-1;
}
item ss[1200];
qsort(ss,n,sizeof(ss[0]),comp);
�������ַ����������� 

struct In 
{ 
int data; 
char str[100]; 
}s[100]; 

//���սṹ�����ַ���str���ֵ�˳������ 

int cmp ( const void *a , const void *b ) 
{ 
return strcmp( (*(In *)a)->str , (*(In *)b)->str ); 
} 

qsort(s,100,sizeof(s[0]),cmp); 
