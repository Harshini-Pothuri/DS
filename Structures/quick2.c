#include<stdio.h>
void quick_sort(int a[],int left,int right)
{   int pivot=a[left],t;
	if(left<right)
	{
		int i=left+1,j=right;
		while(i<j)
		{
			while(a[i]<=pivot&&i<=right){
			i++;}
			while(a[j]>pivot){
			j--;}
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[j];
		a[j]=pivot;
		a[left]=t;
		quick_sort(a,left,j-1);
		quick_sort(a,j+1,right);
	}
}
	int main()
	{
		int a[25],n,i;
		printf("enter n value:");
		scanf("%d",&n);
		printf("enter %d values:",n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		quick_sort(a,0,n-1);
		printf("sorted array elements are:\n");
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
	}
