#include<stdio.h>
#include<conio.h>
void commentRemover(char*);
void main()
{
   char *file;
   clrscr();
   printf("Enter file name\n");
   scanf("%s",file);
   commentRemover(file);
   getch();
}
void commentRemover(char *file)
{
   FILE *fp1,*fp2;
   int inComment=0,j,k,i;
   fp1=fopen(file,"r");
   fp2=fopen("newfile","w");
   while(1)
   {
       i=getc(fp1);
       if(i==EOF)
       {
	   printf("End of file");
	   break;
       }
       if(inComment==0&&i=='/')
       {
	   j=getc(fp1);
	   if(j==EOF)
	   {
		printf("End of file");
	   }
	   else if(j=='*')
	   {
		inComment=1;
	   }
	   else if(j=='/')
	   {
		while(j!='\n')
		   j=getc(fp1);
	   }
       }
       else if(inComment==0)
       {
	   putc(i,fp2);
       }
       if(inComment==1&&i=='*')
       {
	   j=getc(fp1);
	   if(j=='/')
	   {
		inComment=0;
	   }
       }
   }
   fclose(fp1);
   fclose(fp2);
}
