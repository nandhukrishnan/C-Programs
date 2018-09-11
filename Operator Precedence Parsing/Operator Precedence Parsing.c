#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>

void shift();
void reduce();

char os[50];
double vs[50];
int otop=-1,vtop=-1;

void main()
{
	char *c,exp[50];
	clrscr();
	printf("\nEnter the expression\n");
	scanf("%s",exp);
	c=strtok(exp,".");
	while(c!=NULL)
	{
		if(*c=='+'||*c=='-'||*c=='*'||*c=='/'||*c=='^')
		{
			shift(*c);
		}
		else
		{
				vtop++;
				vs[vtop]=atof(c);
		}
		c=strtok(NULL,".");
	}
	
	while(otop>=0&&vtop>=0)
	{
		reduce();
	}
	
	if(vtop==0&&otop==-1)
	{
		printf("\nExpression is CORRECT\n");
		printf("\n\nFinal value : %f",vs[0]);
	}
	else
	{
		printf("\nExpression is WRONG\n");
	}
	getch();
}

void shift(char s)
{
	if(s=='+'||s=='-')
	{
		if(otop>=0)
		{
			while(os[otop]=='+'||os[otop]=='-'||os[otop]=='*'||os[otop]=='/'||os[otop]=='^')
			{
				reduce();
			}
			otop++;
			os[otop]=s;
		}
		else
		{
			otop++;
			os[otop]=s;
		}
	}
	else if(s=='*'||s=='/')
	{
		if(otop>=0)
		{
			while(os[otop]=='*'||os[otop]=='/'||os[otop]=='^')
			{
				reduce();
			}
			otop++;
			os[otop]=s;
		}
		else
		{
			otop++;
			os[otop]=s;
		}
	}
	else if(s=='^')
	{
		if(otop>=0)
		{
			while(os[otop]=='^')
			{
				reduce();
			}
			otop++;
			os[otop]=s;
		}
		else
		{
			otop++;
			os[otop]=s;
		}
	}
}

void reduce()
{
	switch(os[otop])
	{
		case '+':vs[vtop-1]=vs[vtop-1]+vs[vtop];
				 vtop--;
				 break;
		case '-':vs[vtop-1]=vs[vtop-1]-vs[vtop];
				 vtop--;
				 break;
		case '*':vs[vtop-1]=vs[vtop-1]*vs[vtop];
				 vtop--;
				 break;
		case '/':vs[vtop-1]=vs[vtop-1]/vs[vtop];
				 vtop--;
				 break;				 
		case '^':vs[vtop-1]=pow(vs[vtop-1],vs[vtop]);
				 vtop--;
				 break;
	}
	otop--;
}