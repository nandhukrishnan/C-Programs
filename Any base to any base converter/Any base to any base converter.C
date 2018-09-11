#include<stdio.h>
#include<conio.h>
#include<string.h>

void convert(char s[20],int,int);

void main()
{
   char s[20];
   int b1,b2;
   clrscr();
   printf("Enter the number and base\n");
   scanf("%s%d",s,&b1);
   printf("Enter destination base\n");
   scanf("%d",&b2);
   convert(s,b1,b2);
   getch();
}

void convert(char s[20],int b1,int b2)
{
   int count=0,r,digit,i,n=0,b=1;
   for(i=strlen(s)-1;i>=0;i--)
   {
      if(s[i]>='A'&&s[i]<='Z')
      {
	 digit=s[i]-'0'-7;
      }
      else
      {
	 digit=s[i]-'0';
      }
      n=digit*b+n;
      b=b*b1;
   }

   while(n!=0)
   {
      r=n%b2;
      digit='0'+r;
      if(digit>'9')
      {
	 digit=digit+7;
      }
      s[count]=digit;
      count++;
      n=n/b2;
   }

   for(i=count-1;i>=0;i--)
   {
      printf("%c",s[i]);
   }
   printf("\n");
}