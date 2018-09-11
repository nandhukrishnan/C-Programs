#include<stdio.h>
#include<conio.h>
int rev(int);

void main()
{
 int n,temp;
 clrscr();
 printf("Enter the number\n");
 scanf("%d",&n);
 temp=rev(n);
 printf("\nReverse = %d",temp);
 getch();
 }

int rev(int n)
{
 static int revs;
 int r;
 if(n)
 {
  revs=revs*10+(n%10);
  rev(n/10);
 }
 return revs;
}

