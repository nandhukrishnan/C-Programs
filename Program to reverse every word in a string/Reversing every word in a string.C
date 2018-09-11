#include<stdio.h>
#include<conio.h>
#include<string.h>
char txt[1000];
void reverse(char[],int,int);

void main()
{
	int i,index=0,start=0,end=0;
	char tmp[100];
	clrscr();
	printf("Enter the text\n");
	gets(txt);
	while(index<=strlen(txt))
	{
		i=0;
		start=index;
		while(txt[index]!=' '&&txt[index]!='\0')
		{
			tmp[i]=txt[index];
			i++;
			index++;
		}
		if(i>0) //Found atleast one word
		{
			tmp[i]='\0';
			end=index;
			reverse(tmp,start,end);
		}
		else  //increment index since space is found
		{
			index++;
		}
	}
	puts(txt);
	getch();
}

void reverse(char tmp[],int start,int end)
{
	int l=end-start-1,i;
	for(i=start;i<end;i++)
	{
		txt[i]=tmp[l];
		l--;
	}
	if(txt[start]>='a'&&txt[start]<='z')
	{
		txt[start]=txt[start]-32;
	}
}