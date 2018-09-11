#include<stdio.h>
#include<conio.h>
void main()
{
   int i,j,k,k_value,n,m,s;
   int tt[10][50];
   int alpha[5];
   clrscr();
   printf("Enter number of states\n");
   scanf("%d",&n);
   printf("Enter number of alphabets\n");
   scanf("%d",&m);
   printf("Enter %d alphabets\n",m);
   for(i=0;i<m;i++)
	scanf("%d",&alpha[i]);

   for(i=0;i<10;i++)
   {
	for(j=0;j<50;j++)
	{
		tt[i][j]=-1;
	}
   }

   for(i=0;i<n;i++)
   {
	k_value=0;
	printf("Reading transitions of q%d\n\n",i);
	for(j=0;j<m;j++)
	{
		printf("Transitions of %d from q%d. Enter %d to switch symbol\n",alpha[j],i,n);
		for(k=k_value;k<(n+k_value);k++)
		{
			scanf("%d",&s);
			if(s!=n)
			   tt[i][k]=s;
			else
			   break;
		}
		k_value=k_value+n;
	}
   }
   printf("\nTransitions are\n\n");
   for(i=0;i<n;i++)
   {
	k_value=0;
	for(j=0;j<m;j++)
	{
		printf(" (q%d,%d) --> {",i,alpha[j]);
		for(k=k_value;k<(n+k_value);k++)
		{
			if(tt[i][k]!=-1)
			   printf("q%d,",tt[i][k]);
			else
			   break;
		}
		printf("\b}\n");
		k_value=k_value+n;
	}
   }
   getch();
}