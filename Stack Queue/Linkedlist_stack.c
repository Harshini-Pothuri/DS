#include<stdio.h>
#include<stdlib.h>
typedef struct stack
{
	int data;
	struct stack *next;
}stack;
stack *top=NULL;
int count=0;
void push(int info)
{
	stack *newnode=(stack*)malloc(sizeof(struct stack));
	if(newnode==NULL)
	{
		printf("memory not allocated");
	}
	newnode->data=info;
	newnode->next=NULL;
	if(top==NULL)
	{
		top=newnode;
	}
	else
	{
	   newnode->next=top;
	   top=newnode;
	}
	count++;
	printf("element is pushed");
}
void display()
{
	int i;
	if(top==NULL)
	{
		printf("STACK is empty");
	}
	else
	{
		stack *temp=top;
		printf("stack elements are:\n");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
int pop()
{
	int ele;
	if(top==NULL)
	{
		printf("underflow");
		return -1;
	}
	else
	{
	stack *temp=top;
	top=top->next;
	ele=temp->data;
	count--;
	free(temp);
	return ele;
	}
}
int peek()
{
	if(top==NULL)
	{
		printf("underflow");
	    return -1;
	}
	else
	{
		return top->data;}
}
int main()
{
	int ch,x;
	do
	{
		printf("\n1.push 2.pop 3.peek 4.display 5.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("enter element:");
			scanf("%d",&x);
			push(x);
			break;
			case 2:x=pop();
			if(x!=-1)
			printf("popped element is %d",x);
			break;
			case 3:x=peek();
			if(x!=-1)
			printf("the top element is %d",x);
			break;
			case 4:display();
			break;
			case 5:exit(0);
			default:
				printf("invalid operator");
			}
		}
		while(1);
		return 0;
}
