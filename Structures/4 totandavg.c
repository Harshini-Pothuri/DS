#include<stdio.h>
struct student
{
	int rno;
	int s1,s2,s3,s4;
	int total;
	float average;
}s1,s2;
int main()
{
	struct student std[100];
	int n,i;
	printf("Enter n value:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter student Rollno,4 subject Marks:");
	scanf("%d%d%d%d%d",&std[i].rno,&std[i].s1,&std[i].s2,&std[i].s3,&std[i].s4);
    }
    for(i=0;i<n;i++)
    {
    	std[i].total=std[i].s1+std[i].s2+std[i].s3+std[i].s4;
    	std[i].average=std[i].total/4.0;
	printf("Total is %d Average is %f\n",std[i].total,std[i].average);
    }
    return 0;
}
