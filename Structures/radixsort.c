#include<stdio.h>
void radixsort(int a[],int n)
{
	int max,digit=0,i,j,k,count[10],bucket[10][n];
	int div=1,pos,steps;
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	while(max>0)
	{
		digit++;
		max=max/10;
	}
	for(steps=1;steps<=digit;steps++)
	{
		for(i=0;i<10;i++)
		{
			count[i]=0;
		}
		for(i=0;i<n;i++)
		{
			pos=(a[i]/div)%10;
			bucket[pos][count[pos]]=a[i];
			count[pos]++;
		}
		k=0;
		for(i=0;i<10;i++)
		{
			for(j=0;j<count[i];j++)
			{
				a[k]=bucket[i][j];
				k++;
			}
		}
		div=div*10;
	}
}
int main()
{
	int a[20],n,i;
	printf("Enter n value:");
	scanf("%d",&n);
	printf("Enter %d elements:",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	radixsort(a,n);
	printf("Sorted array is:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
