#include<stdio.h>
int onepuls(int num,int numsys){
    int res = 0;
    do{
        res += num%numsys;
        num = num/numsys;
    }while(num != 0);
    return res;
}//ע�⣺16������λ�����ͣ���Ҫ�Լ����ϴ���9��ת������������� 
int main()
{
	int sum1=0,sum2=0,sum3=0;
	int num;
	for(num=2992;num<=9999;num++)
	{
		sum1=onepuls(num,10);
		sum2=onepuls(num,12);
		sum3=onepuls(num,16);
		if(sum1==sum2&&sum2==sum3)
		{
			printf("%d\n",num);
		}
	}
	return 0;
}
