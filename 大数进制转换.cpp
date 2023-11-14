#include<stdio.h>
#include<string.h>
#include <stdbool.h>

char numstr[100];
char res[100];
int main() {


    while (scanf("%s",numstr)!=EOF) {
        int len = strlen(numstr);
        int j = 0;
        bool flag = true;
        while (flag)
        {
            int a = 0;
            for (int i = 0; i < len; i++)
            {
                if (i == len - 1)
                {
                    res[j++] = (numstr[i] - '0') % 2 + '0';

                }
                else
                    numstr[i + 1] += (numstr[i] - '0') % 2 * 10 ;
                    numstr[i] = (numstr[i] - '0') / 2+'0';

            }
            for (int i = 0; i < len; i++)
            {
                if (numstr[i] == '0')
                    a++;
            }
            if (a==len)
            {
                flag = false;

            }
        }
        res[j] = '\0';
        for (int i = 0, k = j - 1; i<k; i++, k--)
        {
            char temp = res[i];
            res[i] = res[k];
            res[k] = temp;
        }
        printf("%s\n", res);

    }
    return 0;
}
