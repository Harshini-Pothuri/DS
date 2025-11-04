#include<stdio.h>
#include<stdlib.h>
#define size 10
int front=-1,rear=-1;
int Q[size];
void enqueue(int ele)
{
	if(rear==size-1)
	{
		printf("Queue is full");
	}
	else
	{
		if(front==-1)
		{
			front=0;
		}
		rear++;
		Q[rear]=ele;
	}
	printf("Element is Placed into Queue\n");
}
int dequeue()
{
	int x;
	if(front==-1)
	{
		printf("Queue is Empty");
		return -1;
	}
	else
	{
		x=Q[front];
		printf("Element %d is removed from Queue\n", x);
			front++;
		if(front>rear)
		{
			front=rear=-1;
		}
		return x;
    }
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("List elements are..");
		for(i=front;i<=rear;i++)
		{
			printf("%d ",Q[i]);
		}
	}
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("\n1.Enqueue(Insertion) 2.Dequeue(Deletion) 3.Display 4.Exit\n");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter any Element into Queue:");
				scanf("%d",&x);
				enqueue(x);
				break;
			case 2:
				x=dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Operator");
		}
    }
    return 0;
}
