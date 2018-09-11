#include<stdio.h>
#include<conio.h>

void mergeSort(int,int); 
void merge(int,int,int); 

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
	
	mergeSort(0,n-1);
	
	printf("Nearest %d points are\n",k);
	for(i=0;i<k;i++)
	{
		printf("%d.(%d,%d) Dist: %f\n",(i+1),s[i].x,s[i].y,s[i].dist);
	}
	getch();
}

void mergeSort(int l,int r) 
{ 
	int m;
    if(l<r) 
    { 
        m=l+(r-l)/2; 
  
		mergeSort(l,m); 
        mergeSort(m+1,r); 
  
        merge(l,m,r); 
    } 
} 

void merge(int l,int m,int r) 
{ 
    int i,j,k; 
    int n1=m-l+1; 
    int n2=r-m; 
  
    struct points L[n1],R[n2]; 
  
    for (i=0; i<n1; i++)
	{
		L[i]=s[l+i]; 
	}		
        
    for (j=0; j<n2; j++) 
	{
		R[j]=s[m+1+j];
	}
         
    i = 0; 
    j = 0; 
    k = l; 
    
	while(i<n1 && j<n2) 
    { 
        if(L[i].dist<=R[j].dist) 
        { 
            s[k]=L[i]; 
            i++; 
        } 
        else
        { 
            s[k]=R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while(i<n1) 
    { 
        s[k]=L[i]; 
        i++; 
        k++; 
    } 
  
    while(j<n2) 
    { 
        s[k]=R[j]; 
        j++; 
        k++; 
    } 
} 