#include<stdio.h>
#include<conio.h>
#include<string.h>

void stringMatcher(char*,char*);

void main()
{
   char *pattern,*txt;
   clrscr();
   printf("Enter the pattern\n");
   scanf("%s",pattern);
   printf("\nEnter the text\n");
   scanf("%s",txt);
   stringMatcher(pattern,txt);
   getch();
}

void stringMatcher(char *pattern,char *txt)
{
   int m=strlen(pattern);
   int n=strlen(txt);
   int TF[30][256],i,j,lps=0;

   for(j=0;j<256;j++)
	TF[0][j]=0;
   TF[0][pattern[0]]=1;

   for(i=1;i<=m;i++)
   {
      for(j=0;j<256;j++)
      {
	 TF[i][j]=TF[lps][j];
      }

      TF[i][pattern[i]]=i+1;

      if(i<m)
      {
	 lps=TF[lps][pattern[i]];
      }
   }
   
   for(i=0;i<n;i++)
   {
      j=TF[j][txt[i]];
      if(j==m)
      {
	 printf("\nindex : %d",i-m+1);
      }
   }

   printf("\n\n---Transition Table---\n");
   for(i=0;i<=m;i++)
   {
      printf("q%d:\t",i);
      for(j=97;j<=100;j++)
      {
	  printf("%d\t",TF[i][j]);
      }
      printf("\n");
   }
}
