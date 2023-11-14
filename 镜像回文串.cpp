#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char mirror(char a)
{
	if (a == 'E')
		a = '3';
	else if (a == 'J')
		a = 'L';
	else if (a == 'L')
		a = 'J';
	else if (a == 'S')
		a = '2';
	else if (a == 'Z')
		a = '5';
	else if (a == '2')
		a = 'S';
	else if (a == '3')
		a = 'E';
	else if (a == '5')
		a = 'Z';
	return a;
}
int main()
{
	char a[55];
	while (gets(a) != NULL)
	{
		int judge1 = 1;
		int judge2 = 1;
		int len = strlen(a);

		if (len == 1)
		{
			if (a[0] == '2')
			{
				printf("2 -- is a mirrored palindrome.\n\n");
				continue;
			}
			else if (a[0] == '3')
			{
				printf("3 -- is a mirrored palindrome.\n\n");
				continue;
			}
		}
		
		for (int i = 0; i <= len / 2 - 1; i++)
		{
			if (a[i] != a[len - i - 1])
			{
				judge1 = 0;
				break;
			}
		}

		char b[55];
		strcpy(b, a);
		for (int i = 0, j = len - 1; i < len; i++, j--)
		{
			if (a[i] == 'B' || a[i] == 'C' || a[i] == 'D' || a[i] == 'F' || a[i] == 'G' || a[i] == 'K' || a[i] == 'N'
				|| a[i] == 'P' || a[i] == 'Q' || a[i] == 'R' || a[i] == '4' || a[i] == '6' || a[i] == '7' || a[i] == '9')
			{
				judge2 = 0;
				break;
			}
			b[j] = a[i];
			b[j] = mirror(b[j]);
		}
		for (int i = 0; i < len; i++)
		{
			if (judge2 == 0)
				break;
			if (b[i] != a[i])
			{
				judge2 = 0;
				break;
			}
		}

		if (judge1 == 0 && judge2 == 0)
			printf("%s -- is not a palindrome.\n", a);
		else if (judge1 == 1 && judge2 == 0)
			printf("%s -- is a regular palindrome.\n", a);
		else if (judge1 == 0 && judge2 == 1)
			printf("%s -- is a mirrored string.\n", a);
		else if (judge1 == 1 && judge2 == 1)
			printf("%s -- is a mirrored palindrome.\n", a);
		printf("\n");
	}
	return 0;
}
