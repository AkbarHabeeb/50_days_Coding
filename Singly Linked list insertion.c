#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
/*Since we pass address of a pointer, we use pointer to a pointer. 
Thus we ensure it is reflected back in the original list */
void insert_first(struct Node** head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_last(struct Node** head_ref, int data)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last_ref = *head_ref;
    new_node->data = data;
    new_node->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while(last_ref->next != NULL)
    {
        last_ref = last_ref->next;
    }
    last_ref->next = new_node;
}

void insert_after(struct Node *prev_node,int data)
{
    if(prev_node == NULL)
    {
        printf("Not possible");
        return;
    }
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void print(struct Node* node)
{
    //Entire node itself is a pointer.
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node = node->next;
    }
}

int main(void)
{
    struct Node *head = NULL;
    insert_first(&head,1);
    insert_last(&head,2);
    //We are passing the address of header to other fns. (So thr shld be ** in those fns)
    //If we are passing just the name alone also, it will be falling as pointer only.
    insert_after(head,15);
    print(head);
    return 0;   
}
