#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20
void push(int);
int pop();
int peek();
int evaluation_of_postfix(char*);
int stack[max],top=-1;
void push(int n)
{
	stack[++top]=n;
}
int pop()
{
	return stack[top--];
}
int peek()
{
	return stack[top];
}
int evaluation_of_postfix(char*ex)
{
	int dig=0,op=0,i;
for(i=0;ex[i]!='\0';i++)
{
	if(isdigit(ex[i]))
	dig++;
	else if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^')
	op++;
}
if(dig<=op)
{
	printf("invalid expression\n");
	exit(0);
}
for(i=0;ex[i]!='\0';i++)
{
	if(isdigit(ex[i])||ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%')
	{
		if(isdigit(ex[i]))
		push(ex[i]-'0');
		else
		{
			int x1,x2;
			x1=pop();
			x2=pop();
			switch(ex[i])
			{
				case '+':push(x2+x1);break;
				case '-':push(x2-x1);break;
				case '*':push(x2*x1);break;
				case '/':push(x2/x1);break;
				case '%':push(x2%x1);break;	
			}
		}
	}else{
		printf("invalid expression\n");
		exit(0);
	}
}
if(top!=0)
{
	printf("invalid expression\n");
	exit(0);
	}
	else
	{
		return stack[top];
	}
}
int main()
{
	char postfix[max];
	int result;
	printf("enter a valid postfix expresssion:");
	gets(postfix);
	result=evaluation_of_postfix(postfix);
	printf("result of postfix evaluation is %d\n",result);
	return 0;
}
