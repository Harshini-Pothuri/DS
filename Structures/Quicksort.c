#include<stdio.h>
void Quicksort(int[],int,int);
int main()
{
	int a[20],i,n;
	printf("Enter n value:");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	}
	Quicksort(a,0,n-1);
	printf("Sorted array is \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
void Quicksort(int a[],int left,int right)
{
	int pivot=left,t;
	if(left<right)
    {
	    int i=left,j=right;
	while(i<j)
	{
		while(a[i]<=a[pivot]&&i<=right)
		{
		    i++;
		}
		while(a[j]>a[pivot])
		{
			j--;
		}
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
    t=a[j];
    a[j]=a[pivot];
    a[pivot]=t;
    Quicksort(a,left,j-1);
    Quicksort(a,j+1,right);
    }
}

