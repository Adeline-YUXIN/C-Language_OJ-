#include <stdio.h>
 
int main(void)
{
	char sen[100],sen1[100];
	int i,m=0,over, start,j=0,pri;
	
	printf("Enter a sentence: ");
	for (i = 0; i < 100; i++) {                                     //�����ַ�����sen��������� 
		sen[i] = getchar();
		if (sen[i] == '!' || sen[i] == '.' || sen[i] == '?') break; //������ĩ����break����ѭ����i++��û��ִ�У�����ʱiָ��ĩβ�ķ��� 
	}
	
	pri = i;								//��¼�¾��ӵĳ��ȣ��Ժ��������	 								//����һ���������ڴ�ı�˳���ľ��� ��һ��һ�����ʵظ��ƣ� 
	i=i-1;
	over = i;						    //startΪÿ�ο�ʼ����ʱ�������±꣬overΪ���ƽ���ʱ�� 
	for (; i >= 0; i--) {         //��i-1��λ����ǰ�ҿո�i-1��ʾ�Ȳ������ĩ���� 
								//�´�һ�����ʵĸ��ƾʹ�i��i��ʱ�Ѿ�i-1�������� 
		while (sen[i] != ' ' && i > 0) 		//�����ո����i<=0ʱ��ֹͣѰ�� 
		{
		start = i;				
		i--;
		}			//��ʼһ�����ʵĸ��ƣ��±�Ӧ���ڿո��һ�� 
		if (i == 0) start--;					//���ifֻ����Ѿ����Ƶ�ԭ��ĵ�һ�����ʵ������start��Ҫ���㿪ʼ�ʼ�1 
		while(start <= over) {
			sen1[j] = sen[start];
			start++;
			j++;			//���Ƶ��� 
		}
		sen1[j] = ' ';     
		j++;                     //ÿ�����ʺ�Ӹ��ո� 
	}
						//֮�����sen1���������ˣ� 
	printf("Reversal of sentence: ");
	for (; m <= pri ; m++) {
		printf("%c", sen1[m]);
	}
		
	return 0;
}


