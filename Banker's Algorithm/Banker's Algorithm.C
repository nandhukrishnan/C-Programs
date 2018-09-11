#include<stdio.h>
#include<conio.h>
int safety();
void request();
void read();
int allocation[10][10],max[10][10],need[10][10],available[10];
int n,m;
void main()
{
  int chc;
  clrscr();
  printf("Enter number of processes and resources\n");
  scanf("%d%d",&n,&m);
  read();
  do
  {
     printf("\n1.Safety 2.Request 3.Exit\n");
     scanf("%d",&chc);
     switch(chc)
     {
	case 1:if(safety()==1)
		 printf("System is in a safe state\n");
	       else
		 printf("System is not in a safe state\n");
	       break;
	case 2:request();
	       break;
     }
  }while(chc<3);
  getch();
}

void read()
{
  int i,j;
  printf("Enter allocation matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
       scanf("%d",&allocation[i][j]);
    }
  }
  printf("Enter max matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
       scanf("%d",&max[i][j]);
    }
  }
  printf("Enter available matrix\n");
  for(j=0;j<m;j++)
  {
    scanf("%d",&available[j]);
  }
  for(i=0;i<n;i++)
  {
    for(j=0;j<m;j++)
    {
       need[i][j]=max[i][j]-allocation[i][j];
    }
  }
}

int safety()
{
   int work[10],finish[10],i,j,k,flag,counter;
   for(j=0;j<m;j++)
   {
      work[j]=available[j];
   }
   for(i=0;i<n;i++)
   {
      finish[i]=0;
   }
   for(k=0;k<n;k++)
   {
      for(i=0;i<n;i++)
      {
	 counter=0;
	 for(j=0;j<m;j++)
	 {
	    if(need[i][j]<=work[j])
	       counter++;
	 }
	 if(counter==m&&finish[i]==0)
	 {
	    for(j=0;j<m;j++)
	    {
	       work[j]=work[j]+allocation[i][j];
	    }
	    finish[i]=1;
	    printf("P%d > ",i);
	    break;
	 }
      }
   }
   for(i=0;i<n;i++)
   {
      if(finish[i]==0)
      {
	 break;
      }
   }
   if(i<n)
     return 0;
   else
     return 1;
}
void request()
{
   int i,j,p,flag;
   int req[10];
   printf("Enter the process number\n");
   scanf("%d",&p);
   printf("Enter request of P%d \n",p);
   for(j=0;j<m;j++)
   {
      scanf("%d",&req[j]);
   }
   for(j=0;j<m;j++)
   {
      if(req[j]>need[p][j])
	 break;
   }
   if(j<m)
   {
      printf("\nRequest exceeded maximum claim..!\n");
      return;
   }
   for(j=0;j<m;j++)
   {
      if(req[j]>available[j])
	 break;
   }
   if(j<m)
   {
     printf("\nNot available..!\n");
     return;
   }
   for(j=0;j<m;j++)
   {
      allocation[p][j]+=req[j];
      need[p][j]-=req[j];
      available[j]-=req[j];
   }
   flag=safety();
   if(flag==0)
   {
      allocation[p][j]-=req[j];
      need[p][j]+=req[j];
      available[j]+=req[j];
      printf("\nCant satisfy request..!\n");
   }
   else
    printf("\nRequest granted\n");
}

