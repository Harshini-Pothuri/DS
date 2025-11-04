#include<stdio.h>
#include<stdlib.h>
int top=-1;
#define size 15
int stack[size];
void push(int ele)
{
	if(top==size-1)
	{
		printf("Stack is Full");
	}
	else{
		top++;
		stack[top]=ele;
	}
}
void display()
{
	int i;
	if(top==-1)
	{
		printf("Stack is Empty");
	}
	else{
		printf("List Elements are....\n");
		for(i=top;i>=0;i--)
		{
			printf("%d ",stack[i]);
		}
	}
}
int pop()
{
	int x;
	if(top==-1)
	{
		printf("Stack is Empty");
		return -1;
	}
	else{
		x=stack[top];
		top--;
	}
	return x;
}
int peek()
{
	int x;
	if(top==-1)
	{
		printf("Stack is Empty");
		return -1;
	}
	else{
		x=stack[top];
	}
	return x;
}
int main()
{
	int ch,x;
	do{
		printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the Element:");
				scanf("%d",&x);
				push(x);
				break;
			case 2:
				x=pop();
				if(x!=-1)        
				printf("Popped Element is:%d\n",x);
				break;
			case 3:
				x=peek();
				if(x!=-1)        
				printf("Top most element is:%d\n",x);
				break;
			case 4:
				display();
				break;
			case 5:
				exit(0);
		}
	}while(1);
	return 0;
}
