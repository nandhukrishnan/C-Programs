#include<stdio.h>
#include<conio.h>

void buildMinHeap(int);
void heapSort(int);
void heapify(int,int);

struct points
{
	int x,y;
	float dist;
}s[100],temp;

void main()
{
	int i,j,n,k;
	printf("Enter the number of points\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the point %d.(x,y)\n",(i+1));
		scanf("%d%d",&s[i].x,&s[i].y);
	}
	printf("Enter the value of K\n");
	scanf("%d",&k);
	for(i=0;i<n;i++)
	{
		s[i].dist=s[i].x*s[i].x+s[i].y*s[i].y;
	}
	
	buildMinHeap(n);
	heapSort(n);
	
	printf("Nearest %d points are\n",k);
	j=1;
	for(i=n-1;i>=n-k;i--)
	{
		printf("%d.(%d,%d) Dist: %f\n",j,s[i].x,s[i].y,s[i].dist);
		j++;
	}
	getch();
}

void buildMinHeap(int n)
{
	int i,j;
	for (int i = n / 2 - 1; i >= 0; i--) 
	{
		heapify(n,i); 
	}
}

void heapSort(int n)
{
	int i,j=1;
	for (i=n-1;i>=0;i--) 
    { 
		temp=s[0];
		s[0]=s[i];
		s[i]=temp;
        heapify(i,0); 
    } 
}

void heapify(int n,int i)
{
	int smallest=i;
	int l=2*i;
	int r=(2*i)+1;

	if (l<n && s[l].dist<s[smallest].dist) 
	{
		smallest=l; 
	}
  
    if (r<n && s[r].dist<s[smallest].dist)
	{
		smallest=r; 
	}		
       
    if (smallest!=i) 
    { 
		temp=s[i];
		s[i]=s[smallest];
		s[smallest]=temp;
        heapify(n,smallest); 
    } 
	
}