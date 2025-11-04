#include<stdio.h>
struct date{
	int dd;
	int mm;
	int yy;
};
struct student{
	char name[30];
	struct date dob;
	float avg;
};
int main()
{
	struct student s1;
	printf("Enter name date month year and average");
	scanf("%s%d%d%d%f",&s1.name,&s1.dob.dd,&s1.dob.mm,&s1.dob.yy,&s1.avg);
    printf("Memory created=%d\n",sizeof(s1));
    printf("%s\t%d-%d-%d\t%f",s1.name,s1.dob.dd,s1.dob.mm,s1.dob.yy,s1.avg);
    return 0;
}
