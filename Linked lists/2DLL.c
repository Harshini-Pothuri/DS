#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL,*end=NULL;
int count=0;
struct node *create_node()
{
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
	{
		printf("List is empty\n");
		return;
	}
	printf("Entet data into node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}
void create_list()
{
	struct node *newnode=create_node();
	if(head==NULL)
	{
	head=end=newnode;
	}
	else
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}
	count++;
	printf("Node is created\n");
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
	printf("\nList elements(Forward)");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->next;
	}
}
void reverse()
{
	struct node *temp;
	if(head==NULL)
	{
		printf("\nList is empty\n");
		return;
	}
	temp=end;
	printf("\nList elements(Backward)");
	while(temp!=NULL)
	{
		printf("%d->",temp->data);
		temp=temp->prev;
	}
}
void insert_first()
{
	struct node *newnode=create_node();
	struct node *curr,*temp;
	int pos,i;
	if(head==NULL)
	{
	printf("List is empty");
	}
	printf("Enter Position");
	scanf("%d",&pos);
	if(pos==1)
	{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
		printf("Node is created\n");
	}
	else if(pos==count+1)
	{
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
		printf("Node is created\n");
	}
	else
	{
	   if(pos<0||pos>count)
	   {
		printf("Invalid position\n");
		return;
	   }
	curr=head;
	for(i=1;i<pos;i++)
	{
		temp=curr;
		curr=curr->next;
	}
	newnode->next=curr;
	newnode->prev=temp;
	temp->next=newnode;
	curr->prev=newnode;
	count++;
	printf("Node is created\n");
}
}
void delete_first()
{
	struct node *temp;
	int pos,i;
	temp=head;
	if(head==NULL)
	{
	printf("List is empty");
	}
	head=head->next;
	if(head==NULL)
	{
		end=NULL;
	}
	else
	{
		head->prev=NULL;
	}
	free(temp);
	count--;
	printf("Node is deleted");
}
void delete_end()
{
	struct node *temp;
	int pos,i;
	temp=end;
	end=end->prev;
	if(end==NULL)
	{
	printf("List is empty");
	}
	else
	{
		end->next=NULL;
	}
	free(temp);
	count--;
	printf("Node is deleted");
}
void  delete_pos()
{
	struct node *temp,*curr;
	int pos,i;
	curr=head;
	printf("Enter the position:");
	scanf("%d",&pos);
	if(head==NULL)
	{
	printf("List is empty");
	}
	if(pos<0||pos>count)
	{
		printf("Invalid position\n");
		return;
	}
	for(i=1;i<pos;i++)
	{
		temp=curr;
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next->prev=temp;
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
int main()
{
	int ch;
	while(1)
	{
		printf("\nChoose the number");
		printf("\n1.Create 2.Display 3.Display Reverse 4.Insert First 5.Insert Last 6.Insert at any position 7.Delete at beginning \n");
		printf("8.Delete at end 9.Delete any position 10.search 11.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			       create_list();
			       break;
			case 2:
			       display();
			       break;
			case 3:
			       reverse();
			       break;
			case 4:
			       insert_first();
				   break;     
			case 7:
			       delete_first();
				   break;
			case 8:
			       delete_end();
				   break;
			case 9:
			       delete_pos();
				   break;
		    case 10:
			        search();
					break;       
			case 11:
			       exit(0);
			default:
			        printf("\nInvalid choice\n");
		}
	}
	return 0;
}
