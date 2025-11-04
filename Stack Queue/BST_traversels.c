#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node NODE;
NODE *root = NULL;
void create(int);
void insert(NODE*, NODE*);
void inorder(NODE*);
void preorder(NODE*);
void postorder(NODE*);

void create(int value) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode; // First node becomes root
    else
        insert(root, newnode); // Insert elsewhere
}

// Recursive insertion
void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data) {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    } else {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}

void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d  ", root->data);
        inorder(root->right);
    }
}

void preorder(NODE *root)
{
	if(root!=NULL)
	{
	     printf("%d  ", root->data);
		 preorder(root->left);
		 preorder(root->right);	
	}
}

void postorder(NODE *root)
{
	if(root!=NULL)
	{
		 postorder(root->left);
		 postorder(root->right);	
		 printf("%d  ", root->data);
	}
}

int main() {
	int a=-10,b=3;
int n=a/b;
printf("%d",n);
    int ch, value;
    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. In-Order\n3. Pre-order\n4. Post-order\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("In-Order Traversal: ");
                    inorder(root);
                    printf("\n");
                }
                break;
            case 3:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Pre-Order Traversal: ");
                    preorder(root);
                    printf("\n");
                }
                break;
            case 4:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Post-Order Traversal: ");
                    postorder(root);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
}
