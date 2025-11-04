#include<stdio.h>
struct student
{
	int rno;
	char name[30];
	float avg;
}s1,s2;
int main()
{
	struct student s3={101,"Ramu",79.89};
	s2=s3;
	printf("Enter rollno,name,average");
	scanf("%d%s%f",&s1.rno,&s1.name,&s1.avg);
	printf("%d  %s  %f\n",s3.rno,s3.name,s3.avg);
	printf("%d  %s  %f",s1.rno,s1.name,s1.avg);
	return 0;
}
