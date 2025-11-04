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
		end->next=head;
	}
	else
	{
		end->next=newnode;
		end=newnode;
		end->next=head;
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
	do
	{
	    printf("%d->",temp->data);
		temp=temp->next;	
	}
	while(temp!=head);
	{temp=temp->next;
	}
}
void insert_first()
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
	end->next=newnode;
	count++;
	printf("\nNode is created\n");
}
void insert_end()
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
	end->next=head;
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
	printf("\nNode is created\n");
}
void delete_Beginning() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp =head;
    if (temp->next ==head) {
        free(temp);
        head = NULL;
    } else {
    	head=head->next;
    	end->next=head;
    	free(temp);
    	count--;
    }
    printf("Node is deleted");
}
void delete_End() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *temp = head,*prev = NULL;
    if (temp->next == head) {
        free(temp);
        head = NULL;
    } else {
        while (temp->next !=head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next =head;
		end=prev; 
        free(temp);
		count--;        
    }
    printf("Node is deleted");
}
void delete_at_Position() {
	int i, pos;
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct node *prev, *curr=head;
    printf("Enter position to delete:");
    scanf("%d",&pos);
    if (pos < 1 || pos > count) 
	{
        printf("Deletion not posibble");
        return;
    }
	for (i = 1; i < pos; i++) 
	{
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    free(curr);
	count--;  
	printf("Node is Deleted");       
}
int main()
{
	int ch;
	while(1)
	{
		printf("\nChoose the number");
		printf("\n1.Create 2.Display 3.Insert First 4.Insert Last 5.Insert at any position 6.Delete at beginning 7.Delete at end\n");
		printf("8.Delete any position 9.exit\n");
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
				   insert_first();
				   break;
			case 4:
				   insert_end();
				   break;	   
			case 5:
				   insert_pos();
				   break;
		    case 6:
				   delete_Beginning();
				   break;
			case 7:
				   	delete_End();
				   	break;
			case 8:
				    delete_at_Position();
				    break;
			case 9:
			       exit(0);
			default:
			        printf("\nInvalid choice\n");
		}
	}
	return 0;
}
