#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*end=NULL;
void create_nodes();
void display();
int count=0;
void create_nodes()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("\nMemory is full");
		return;
	}
	printf("Enter data into node:\n");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=end=newnode;
	}
	else
	{
		end->next=newnode;
		end=newnode;
	}
	count++;
	printf("\nNode is created\n");
}
void display()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	temp=head;
	printf("\nList elements are...");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void insertfirst()
{
	int info;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory full");
		return;
	}
	printf("Enter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=head;
	head=newnode;
	count++;
	printf("\nNode is created\n");
}
void insertlast()
{
	int info;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory full");
		return;
	}
	printf("Enter data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->next=NULL;
	end->next=newnode;
	end=newnode;
	count++;
	printf("\nNode is created\n");
}
void insert_pos()
{
	int info,pos,i;
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Memory full");
		return;
	}
	printf("Enter data into node:");
	scanf("%d",&info);
	printf("Enter position:");
	scanf("%d",&pos);
	newnode->data=info;
	newnode->next=NULL;
	if(pos<0||pos>count)
	{
		printf("Invalid position\n");
		free(newnode);
		return;
	}
	struct node *temp=head;
	for(i=1;i<pos-1;i++)
	{
		temp=temp->next;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	count++;
}
void delete_beginning()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	struct node *temp=head;
	head=head->next;
	free(temp);
	count--;
	printf("Node is created\n");
}
void delete_end()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	struct node *prev,*curr;
	curr=head;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=NULL;
	free(curr);
	end=prev;
	count--;
	printf("Node is deleted");
}
void delete_pos()
{
	int pos,i;
	if(head==NULL){
		printf("List is empty");
		return;
	}
	printf("Enter position:");
	scanf("%d",&pos);
	if(pos<1||pos>count)
	{
		printf("Invalid");
		return;
	}
	struct node *prev,*curr;
	curr=head;
	for(i=1;i<pos;i++)
	{
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	free(curr);
	count--;
	printf("Node is deleted");
}
void search()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
   	struct node *curr=head;
	int found=0,key;
	printf("Enter the element you want to search:");
	scanf("%d",&key);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			printf("Element Found\n");
			found=1;
			break;
		}
		curr=curr->next;
	}
	if(found==0)
	{
		printf("Element not found\n");
	}
}
void replace()
{
	if(head==NULL)
	{
		printf("List is empty");
	}
   	struct node *curr=head;
	int found=0,key,ele;
	printf("Enter the element you want to replace:");
	scanf("%d",&key);
	printf("Enter the element you want to be replaced:");
	scanf("%d",&ele);
	while(curr!=NULL)
	{
		if(curr->data==key)
		{
			curr->data=ele;
			printf("Element is replaced\n");
			break;
		}
		curr=curr->next;
	}
}
void reverse()
{
	if(head==NULL)
	{
		printf("List is empty");
		return;
	}
	struct node *prev=NULL,*curr=head,*next1=NULL;
	end=head;
	while(curr!=NULL)
	{
		next1=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next1;
	}
	head=prev;
	printf("\nNodes are reversed");
}
int main()
{
	int ch;
	while(1)
	{
		printf("\nChoose the number");
		printf("\n1.Create\n2.Display\n3.Insert First\n4.Insert Last\n5.Insert at any position\n6.Delete at beginning\n7.Delete at end\n");
		printf("8.Delete any position\n9.search\n10.Replace\n11.Reverse\n12.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			       create_nodes();
			       break;
			case 2:
			       display();
			       break;
			case 3:
				   insertfirst();
				   break;
			case 4:
				   insertlast();
			       break;
			case 5:
			        insert_pos();
			        break;
			case 6:
				    delete_beginning();
				    break;
			case 7:
				    delete_end();
				    break;
			case 8:
				    delete_pos();
				    break;
			case 9:
				    search();
				    break;
			case 10:
				    replace();
				    break;
			case 11:
				    reverse();
				    break;
			case 12:
			       exit(0);
			default:
			        printf("\nInvalid choice\n");
		}
	}
	return 0;
}
