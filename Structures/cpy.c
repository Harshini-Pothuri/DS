#include<stdio.h>
struct student
{
	int rno;
	char name[30];
	float avg;
}s1,s2,s3;
int main()
{
	printf("Enter Rollno,Name&Average:");
	scanf("%d%s%f",&s3.rno,&s3.name,&s3.avg);
	printf("%d %s %f\n",s2.rno,s2.name,s2.avg);
	printf("%d %s %f",s3.rno,s3.name,s3.avg);
	return 0;
}
