#include <stdio.h> 
#include <stdlib.h> 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 

void deleteNode(struct Node ** head_ref,int key)
{
    struct Node *temp = *head_ref;
    struct Node *prev = NULL;
    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    // If key was not present in linked list 
    if(temp == NULL)
    {
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteNode_position(struct Node **head_ref,int position)
{
    struct Node *temp = *head_ref;
    if(temp != NULL && position == 0)
    {
        *head_ref = temp->next;
        return;
    }
    for(int i=0;temp != NULL  &&  i<position-1;i++)
    {
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL)
    {
        return;
    }
    struct Node *next = temp->next->next; 
    free(temp->next);
    temp->next = next;
}

void delete_list(struct Node **head_ref)
{
    struct Node *current = *head_ref;
    struct Node *next;
    while(current!=NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf(" %d ", node->data); 
		node = node->next; 
	} 
} 


int main() 
{ 
	struct Node* head = NULL; 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 3); 
	push(&head, 4); 
	push(&head, 5); 

	printf("Created Linked List: "); 
	printList(head); 
	deleteNode(&head, 1); 
	printf("\nLinked List after Deletion of node which has the content 1: "); 
	printList(head); 
	deleteNode_position(&head, 1); 
	printf("\nLinked List after Deletion of 1 node(started with 0): "); 
	printList(head); 
	delete_list(&head); 
	printf("\nLinked List after Deletion of the list: "); 
	printList(head); 
	return 0; 
}