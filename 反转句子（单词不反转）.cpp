#include <stdio.h>
 
int main(void)
{
	char sen[100],sen1[100];
	int i,m=0,over, start,j=0,pri;
	
	printf("Enter a sentence: ");
	for (i = 0; i < 100; i++) {                                     //建立字符数字sen并输入句子 
		sen[i] = getchar();
		if (sen[i] == '!' || sen[i] == '.' || sen[i] == '?') break; //遇到句末符号break跳出循环（i++并没有执行），此时i指向末尾的符号 
	}
	
	pri = i;								//记录下句子的长度，以后用于输出	 								//建立一个数组用于存改变顺序后的句子 （一个一个单词地复制） 
	i=i-1;
	over = i;						    //start为每次开始复制时的数组下标，over为复制结束时的 
	for (; i >= 0; i--) {         //从i-1的位置往前找空格，i-1表示先不处理句末符号 
								//下次一个单词的复制就从i（i此时已经i-1）处结束 
		while (sen[i] != ' ' && i > 0) 		//遇到空格或者i<=0时，停止寻找 
		{
		start = i;				
		i--;
		}			//开始一个单词的复制，下标应该在空格后一个 
		if (i == 0) start--;					//这个if只针对已经复制到原句的第一个单词的情况，start需要从零开始故减1 
		while(start <= over) {
			sen1[j] = sen[start];
			start++;
			j++;			//复制单词 
		}
		sen1[j] = ' ';     
		j++;                     //每个单词后加个空格 
	}
						//之后就是sen1数组的输出了！ 
	printf("Reversal of sentence: ");
	for (; m <= pri ; m++) {
		printf("%c", sen1[m]);
	}
		
	return 0;
}


