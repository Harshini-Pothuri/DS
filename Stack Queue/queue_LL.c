#include<stdio.h>
#include<stdlib.h>
typedef struct queue
{
	int data;
	struct queue *next;
}Q;
Q *front=NULL,*rear=NULL;
void enqueue(int ele)
{
	Q *newnode=(Q*)malloc(sizeof(Q));
	if(newnode==NULL)
	{
		printf("Memory not allocated");
	}
	newnode->data=ele;
	newnode->next=NULL;
	if(rear==NULL)
	{
		front=rear=newnode;
	}
	else
	{
	   rear->next=newnode;
	   rear=newnode;
	}
	printf("%d is inserted element\n",ele);
}
int dequeue()
{
	int x;
	if(front==NULL)
	{
		printf("List is empty");
		return -1;
	}
	Q *temp=front;
	x=front->data;
	front=front->next;
	if(front==NULL)
	{
		rear=NULL;
	}
	free(temp);
	return x;
}
void display()
{
	int i;
	if(front==NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		Q *temp=front;
		printf("Queue elements are.... ");
		while(temp!=NULL)
		{
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.Enqueue 2.Dequeue 3.display 4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter element into Queue:");
			scanf("%d",&x);
			enqueue(x);
			break;
			case 2:x=dequeue();
			if(x!=-1)
			printf("%d is deleted\n",x);
			break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid operator");
			}
	}
		return 0;
}
