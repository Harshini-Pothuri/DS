#include<stdio.h>
struct date{
	int dd;
	int mm;
	int yy;
};
struct student{
	struct date dob;
};
int main()
{
	int date,month,year;
	struct student s1={7,2,2025};
	struct student s2={27,12,2009};
	if(s1.dob.dd>s2.dob.dd)
	{
	date=s1.dob.dd-s2.dob.dd;
	}
	else
	{
	date=s2.dob.dd-s1.dob.dd;
	}
	if(s1.dob.mm>s2.dob.mm)
	{
	month=s1.dob.mm-s2.dob.mm;
	}
	else
	{
	month=s2.dob.mm-s1.dob.mm;	
	}
	year=s1.dob.yy-s2.dob.yy;
	printf("%d %d %d",date,month,year);
	return 0;
}
	
