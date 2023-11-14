#include <stdio.h>

_int64 hanoi(int N,int K)
{
	_int64 s=0;
	if(N>K)s=hanoi(N-1,K)*2;
		else s=1;
	return s;
}

int main()
{
	int T,N,K;
    scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		printf("%I64d\n",hanoi(N,K));
	}
	return 0;
}
