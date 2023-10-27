#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node * prev ;
    struct Node * next;
};

// Creating a function for printing the linked list
void printLL(struct Node * head){
    while(head->next != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
}

// Function to insert element at 
struct Node * insertBeg(struct Node * head){
    int val;
    printf("Enter the number to be inserted : ");
    scanf("%d", &val);
    struct Node * new = (struct Node *) malloc(sizeof(struct Node));
    new->data = val;
    new->prev = NULL;
    new->next = head;
    head->prev = new;
    head = new;
}

// Function to Insert Element at specified Node
struct Node * insertBet(struct Node * head){
    int val, index;
    printf("Enter the number to be entered : ");
    scanf("%d", &val);
    printf("Enter the index to enter at : ");
    scanf("%d", &index);

    struct Node * new = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    for(int i = 0; i < index - 1; i++){
        p->prev = p;
        p = p->next;
    }
    (p->next)->prev = new;
    new->prev = p;
    new->data = val;
    new->next = p->next;
    p->next = new;

    return head;
}

// Function to Delete element at beginning

struct Node * DelBeg(struct Node * head){
    struct Node * new = head;
    new = new->next;
    new->prev = NULL;
    free(head);
    return new;
}

struct Node * DelBet(struct Node * head){
    int index;
    printf("Enter the index to remove at : ");
    scanf("%d", &index);
    struct Node * new = head;
    struct Node * p = head->next;
    for(int i = 0; i < index - 1; i++){
        p->prev = p;
        p = p->next;
        new->prev = new;
        new = new->next;
    }
    new->next = p->next;
    (p->next)->prev = new;
    free(p);
    return head;
}

// Function to Delete element at index

int main(){
    struct Node * head = (struct Node * ) malloc(sizeof(struct Node));
    head->next = NULL;
    head = insertBeg(head);
    head = insertBeg(head);
    head = insertBeg(head);
    head = insertBeg(head);
    printf("Linked List after Insertion : ");
    printLL(head);
    printf("\n");

    head = insertBet(head);
    head = insertBet(head);
    printf("Linked List after insertion in between : ");
    printLL(head);
    printf("\n");

    head = DelBeg(head);
    head = DelBeg(head);
    printf("Linked List after Deleting Starting elements : ");
    printLL(head);
    printf("\n");

    head = DelBet(head);
    head = DelBet(head);
    printf("Linked List after Deleting elements at index : ");
    printLL(head);
}