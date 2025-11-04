#include<stdio.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
int main()
{
	int a[20],i,n;
	printf("Enter n value:");
	scanf("%d",&n);
	printf("Enter %d elements ",n);
	for(i=0;i<n;i++){
	scanf("%d",&a[i]);
	}
	mergesort(a,0,n-1);
	printf("Sorted array is \n");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
void mergesort(int a[],int left,int right)
{
	int mid;
	if(left<right)
	{
		mid=(left+right)/2;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);
	}
}
void merge(int a[],int left,int mid,int right)
{
	int temp[right-left+1];
	int i,j,k=0;
	i=left,j=mid+1;
	while(i<=mid&&j<=right)
	{
		if(a[i]<=a[j])
		{
			temp[k]=a[i];
			i++;
		}
		else
		{
		    temp[k]=a[j];
			j++;	
		}
		k++;
	}
	while(i<=mid)
	{
		temp[k]=a[i];
		i++;
		k++;
	}
	while(j<=right)
	{
		temp[k]=a[j];
		j++;
		k++;
	}
	for(i=left,k=0;i<=right;i++,k++)
	{
		a[i]=temp[k]; 
	}
}
