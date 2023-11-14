一、对int类型数组排序 

int num[100]; 

Sample: 

int cmp ( const void *a , const void *b ) 
{ 
return *(int *)a - *(int *)b; 
} 

qsort(num,100,sizeof(num[0]),cmp); 

二、对char类型数组排序（同int类型） 

char word[100]; 

Sample: 

int cmp( const void *a , const void *b ) 
{ 
return *(char *)a - *(int *)b; 
} 

qsort(word,100,sizeof(word[0]),cmp); 

三、对double类型数组排序（特别要注意） 

double in[100]; 

int cmp( const void *a , const void *b ) 
{ 
return *(double *)a > *(double *)b ? 1 : -1; 
} 

qsort(in,100,sizeof(in[0]),cmp)； 

四、对结构体一级排序 

struct In 
{ 
double data; 
int other; 
}s[100] 

//按照data的值从小到大将结构体排序,关于结构体内的排序关键数据data的类型可以很多种，参考上面的例子写 

int cmp( const void *a ,const void *b) 
{ 
return (*(In *)a).data > (*(In *)b).data ? 1 : -1; 
} 

qsort(s,100,sizeof(s[0]),cmp); 
五、对结构体二级排序 

struct In 
{ 
int x; 
int y; 
}s[100]; 

//按照x从小到大排序，当x相等时按照y从大到小排序 

int cmp( const void *a , const void *b ) 
{ 
struct In *c = (In *)a; 
struct In *d = (In *)b; 
if(c->x != d->x) return c->x - d->x; 
else return d->y - c->y; 
} 

qsort(s,100,sizeof(s[0]),cmp); 
对结构体三级排序（都是从小到大）
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
六、对字符串进行排序 

struct In 
{ 
int data; 
char str[100]; 
}s[100]; 

//按照结构体中字符串str的字典顺序排序 

int cmp ( const void *a , const void *b ) 
{ 
return strcmp( (*(In *)a)->str , (*(In *)b)->str ); 
} 

qsort(s,100,sizeof(s[0]),cmp); 
