#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
 char a[10],b[10],c[10];
 int i,j=0,l1,l2,l3,k=0,x=0;
 clrscr();
 printf("Enter the String\n");
 gets(a);
 printf("\nEnter the string to Delete\n");
 gets(b);
 l1=strlen(a);
 l2=strlen(b);
 for(i=0;i<l1;i++)
 {
   if(a[i]==b[j])
   {
     j++; k++;
     if(k==l2)
     {
       break;
     }
   }
   else
   {
     j=0;
     k=0;
   }
 }
 l3=i-l2;
 l3++;
 
 for(j=i+1;j<l1;j++)
 {
   c[x]=a[j];
   x++;
 }

 for(x=0;c[x]!='\0';x++)
 {
   a[l3]=c[x];
   l3++;
 }
 a[l3]='\0';
printf("\nString = %s",a);
getch();
}