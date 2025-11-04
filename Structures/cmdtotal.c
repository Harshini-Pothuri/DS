#include<stdio.h>
#include<string.h>
struct student
{
	char name[30];
	int m1,m2,m3,m4;
	float total;
};
int main(int argc,char *argv[])
{
	struct student s1;
	strcpy(s1.name,argv[1]);
	s1.m1=atoi(argv[2]);
	s1.m2=atoi(argv[3]);
	s1.m3=atoi(argv[4]);
	s1.m4=atoi(argv[5]);
	s1.total=s1.m1+s1.m2+s1.m3+s1.m4;
	printf("%s %f",s1.name,s1.total);
	return 0;
}
