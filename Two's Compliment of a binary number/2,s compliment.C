#include<stdio.h>
#include<conio.h>

void main()
{
 int i,j;
 char a[10];
 clrscr();
 printf("Enter the Binary no.\n");
 scanf("%s",a);
 for(i=9;i>=0;i--)
 {
   if(a[i]=='1')
   {
      i--;
      break;
   } 
 }

 for(j=i;j>=0;j--)
 {
    if(a[j]=='1')
    a[j]='0';
    else
    a[j]='1';
 }
 printf("\n2s Compliment = %s",a);
 getch();
}