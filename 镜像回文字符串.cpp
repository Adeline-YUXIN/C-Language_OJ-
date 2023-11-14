#include<stdio.h>
#include<string.h>
int huiwen(char a[],int n);
int mirror(char a[],int n);
int main()
{
	char ch,a[80];
	int p,m,h,q,i=0;
	while((ch=getchar())!=EOF)
	{
		p=0;
		a[p]=ch;
		p++; 
		while((ch=getchar())!='\n')
		{
			a[p]=ch;
			p++; 
		}
		m=p;
		h=huiwen(a,m);
		q=mirror(a,m);
		if(h==1&&q==1)
		{
			for(i=0;i<p-1;i++)
			{
				printf("%c",a[i]);
			}
			if(i==p-1) printf("%c -- is a mirrored palindrome.\n\n",a[i]);
		
		}
		else if(h==1&&q==0)
		{
			for(i=0;i<p-1;i++)
			{
				printf("%c",a[i]);
			}
			if(i==p-1) printf("%c -- is a regular palindrome.\n\n",a[i]);
		}
		else if(h==0&&q==1)
		{
			for(i=0;i<p-1;i++)
			{
				printf("%c",a[i]);
			}
			if(i==p-1) printf("%c -- is a mirrored string.\n\n",a[i]);
		}
		else 
		{
			for(i=0;i<p-1;i++)
			{
				printf("%c",a[i]);
			}
			if(i==p-1) printf("%c -- is not a palindrome.\n\n",a[i]);
		}
	}
	return 0;
}
int huiwen(char a[],int n)
{
	int k,i;
	char b[80];
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
}
int mirror(char a[],int n)
{
	int k,i;
	char b[80];
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
		if(a[i]=='A'&&b[k]=='A')
		{
			s++;
		}
		if(a[i]=='3'&&b[k]=='E')
		{
			s++;
		}
		if(a[i]=='H'&&b[k]=='H')
		{
			s++;
		}
		if(a[i]=='I'&&b[k]=='I')
		{
			s++;
		}
		if(a[i]=='J'&&b[k]=='L')
		{
			s++;
		}
		if(a[i]=='L'&&b[k]=='J')
		{
			s++;
		}
		if(a[i]=='M'&&b[k]=='M')
		{
			s++;
		}
		if(a[i]=='O'&&b[k]=='O')
		{
			s++;
		}
		if(a[i]=='S'&&b[k]=='2')
		{
			s++;
		}
		if(a[i]=='T'&&b[k]=='T')
		{
			s++;
		}
		if(a[i]=='U'&&b[k]=='U')
		{
			s++;
		}
		if(a[i]=='V'&&b[k]=='V')
		{
			s++;
		}
		if(a[i]=='W'&&b[k]=='W')
		{
			s++;
		}
		if(a[i]=='X'&&b[k]=='X')
		{
			s++;
		}
		if(a[i]=='Y'&&b[k]=='Y')
		{
			s++;
		}
		if(a[i]=='Z'&&b[k]=='5')
		{
			s++;
		}
		if(a[i]=='1'&&b[k]=='1')
		{
			s++;
		}
		if(a[i]=='2'&&b[k]=='S')
		{
			s++;
		}
		if(a[i]=='3'&&b[k]=='E')
		{
			s++;
		}
		if(a[i]=='5'&&b[k]=='Z')
		{
			s++;
		}
		if(a[i]=='8'&&b[k]=='8')
		{
			s++;
		}
	}
	if(s==m) return 1;
	else return 0;
}
