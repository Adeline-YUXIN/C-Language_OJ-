int huiwen(char a[],int n)
{
	int k,i;
	char b[1000];
	k=0;
	i=n-1;
	for(;k<n;k++,i--)
	{
		b[k]=a[i];
	} 
	 int m,s=0;
	 m=k;
	 i=i+1;
	for(k=0;k<m;k++,i++)
	{
		if(a[i]==b[k]){
			s++;
		}
	}
	if(s==m) return 1;
	else return 0;
}//回文
int hui(int n)
{
	int a[10],i,k,d;
	d=n;
	for(i=0;;i++)
	{
		a[i]=d%10;
		if(d/10==0) break;
		d=d/10;
	}
	k=0;
	if(a[k]!=a[i]) return 1;
	if(i%2!=0)
	{
		if(a[k+1]!=a[i-1]) return 1;
		else return n;
	}
	else return n;
}//数字回文 
//判断一个字符串是否是回文
void IsHuiWen()
{
 char str[100];
 int i,j,n;
 printf("请输入一段字符串：");
 gets(str);
 n = strlen(str);
 for(i = 0,j = n-1; i < j; i++,j--)
  if(str[i] != str[j])
   break;
 if(i >= j)
  printf("是回文!\n");
 else
  printf("不是回文!\n");
 
} 

//完数
//找出1000以内的所有完数(一个数等于其因子之和）
void PerfectNumber()
{
 int p[80];  //保存分解的因子
 int i,num,count,s,c = 0;
    int MaxNum = 10000; 
 
 for(num = 2; num < MaxNum; num++)
 {
  count = 0;
  s = num;
  for(i = 1; i < num/2+1; i++)      //循环处理每个数
  {
   if(num % i == 0)          //能被i整除
   {
    p[count++]  = i;      //保存因子，让计数器count增加1
    s -= i;               //减去一个因子
   }
  }
  if( 0 == s)
  {
   printf("%4d是一个完数，因子是：",num);
   printf("%d = %d",num,p[0]);  //输出完数
   for(i = 1; i < count; i++)
    printf("+%d",p[i]);
   printf("\n");
   c++;
  }
 }
 printf("\n共找到%d个完数。\n",c);
}

/*实现字符串翻转*/
char* reverse_str(char* str)
{
 if(NULL == str) //字符串为空直接返回
 {
  return str;
 }
 char *begin;
 char *end;
 begin = end = str;
 
 while(*end != '\0') //end指向字符串的末尾
 {
  end++;
 }
 --end;
 
 char temp;
 while(begin < end) //交换两个字符
 {
  temp = *begin;
  *begin = *end;
  *end = temp;
  begin++;
  end--;
 }
 
 return str; //返回结果
}
//水仙花 
main()
{
int i,j,k,n;
printf("‘water flower’number is:");
　for(n=100;n<1000;n++)
　{
　　i=n/100;//分解出百位/
　　j=n/10%10;//分解出十位/
　　k=n%10;//分解出个位/
　　if(i*100+j*10+k==i*i*i+j*j*j+k*k*k)
　　　{
　　　printf(“%-5d,n);
　　　}
　}
printf(“\n”);
}
//质因数
main()
{
int n,i;
printf(“\nplease input a number:\n”);
scanf(“%d”,&n);
printf(“%d=”,n);
for(i=2;i<=n;i++)
　{
　　while(n!=i)
　　{
　　　if(n%i==0)
　　　{ printf(“%d*”,i);
　　　　n=n/i;
　　　}
　　　else
　　　　break;
　　}
}
printf(“%d”,n);
} 
void prime(long long m)//求一个数的素因子
{
    long long i;
       k=0;
    for(i=2;i*i<=m;i++)
    {
        if(m%i==0)
        {
            s[k++]=i;
            while(m%i==0)
                m/=i;

main()
{
　int a,b,num1,num2,temp;
　printf(“please input two numbers:\n”);
　scanf(“%d,%d”,&num1,&num2);
　if(num1 　{ temp=num1;
　　num1=num2;　
　　num2=temp;
　}
a=num1;b=num2;
while(b!=0)/利用辗除法，直到b为0为止/
　{
　　temp=a%b;
　　a=b;
　　b=temp;
　}
printf(“gongyueshu:%d\n”,a);
printf(“gongbeishu:%d\n”,num1*num2/a);
}//求最大公约数最小公倍数 
