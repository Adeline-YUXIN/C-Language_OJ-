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
}//����
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
}//���ֻ��� 
//�ж�һ���ַ����Ƿ��ǻ���
void IsHuiWen()
{
 char str[100];
 int i,j,n;
 printf("������һ���ַ�����");
 gets(str);
 n = strlen(str);
 for(i = 0,j = n-1; i < j; i++,j--)
  if(str[i] != str[j])
   break;
 if(i >= j)
  printf("�ǻ���!\n");
 else
  printf("���ǻ���!\n");
 
} 

//����
//�ҳ�1000���ڵ���������(һ��������������֮�ͣ�
void PerfectNumber()
{
 int p[80];  //����ֽ������
 int i,num,count,s,c = 0;
    int MaxNum = 10000; 
 
 for(num = 2; num < MaxNum; num++)
 {
  count = 0;
  s = num;
  for(i = 1; i < num/2+1; i++)      //ѭ������ÿ����
  {
   if(num % i == 0)          //�ܱ�i����
   {
    p[count++]  = i;      //�������ӣ��ü�����count����1
    s -= i;               //��ȥһ������
   }
  }
  if( 0 == s)
  {
   printf("%4d��һ�������������ǣ�",num);
   printf("%d = %d",num,p[0]);  //�������
   for(i = 1; i < count; i++)
    printf("+%d",p[i]);
   printf("\n");
   c++;
  }
 }
 printf("\n���ҵ�%d��������\n",c);
}

/*ʵ���ַ�����ת*/
char* reverse_str(char* str)
{
 if(NULL == str) //�ַ���Ϊ��ֱ�ӷ���
 {
  return str;
 }
 char *begin;
 char *end;
 begin = end = str;
 
 while(*end != '\0') //endָ���ַ�����ĩβ
 {
  end++;
 }
 --end;
 
 char temp;
 while(begin < end) //���������ַ�
 {
  temp = *begin;
  *begin = *end;
  *end = temp;
  begin++;
  end--;
 }
 
 return str; //���ؽ��
}
//ˮ�ɻ� 
main()
{
int i,j,k,n;
printf("��water flower��number is:");
��for(n=100;n<1000;n++)
��{
����i=n/100;//�ֽ����λ/
����j=n/10%10;//�ֽ��ʮλ/
����k=n%10;//�ֽ����λ/
����if(i*100+j*10+k==i*i*i+j*j*j+k*k*k)
������{
������printf(��%-5d,n);
������}
��}
printf(��\n��);
}
//������
main()
{
int n,i;
printf(��\nplease input a number:\n��);
scanf(��%d��,&n);
printf(��%d=��,n);
for(i=2;i<=n;i++)
��{
����while(n!=i)
����{
������if(n%i==0)
������{ printf(��%d*��,i);
��������n=n/i;
������}
������else
��������break;
����}
}
printf(��%d��,n);
} 
void prime(long long m)//��һ������������
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
��int a,b,num1,num2,temp;
��printf(��please input two numbers:\n��);
��scanf(��%d,%d��,&num1,&num2);
��if(num1 ��{ temp=num1;
����num1=num2;��
����num2=temp;
��}
a=num1;b=num2;
while(b!=0)/����շ������ֱ��bΪ0Ϊֹ/
��{
����temp=a%b;
����a=b;
����b=temp;
��}
printf(��gongyueshu:%d\n��,a);
printf(��gongbeishu:%d\n��,num1*num2/a);
}//�����Լ����С������ 
