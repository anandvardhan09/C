
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct node *create_22054408(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data :");
scanf("%d", &num);
while(num != -1)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data = num;
new_node -> next = NULL;
if(start == NULL)
{
start = (struct node*)malloc(sizeof(struct node));
start -> next = new_node;
}
else
{
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = new_node;
}
printf("\n Enter the data :");
scanf("%d", &num);
}
return start;
}

struct Node* create_node_22054408(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}


struct Node* init_22054408() {
    struct Node* header = create_node_22054408(0);
    header->next = header; 
    return header;
}


void insert_22054408(struct Node* header, int data) {
    struct Node* new_node = create_node_22054408(data);
    struct Node* current = header;
    
    while (current->next != header) {
        current = current->next;
    }
    
    current->next = new_node;
    new_node->next = header;
}


void display_22054408(struct Node* header) {
    struct Node* current = header->next;
    
    if (current == header) {
        printf("Circular linked list is empty.\n");
        return;
    }
    
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != header);
    printf("HEAD\n");
}

int main() {
    struct Node* header = init_22054408();
    

    insert_22054408(header, 11);
    insert_22054408(header, 31);
    insert_22054408(header, 343);
    
  
    display_22054408(header);
    
    return 0;
}
