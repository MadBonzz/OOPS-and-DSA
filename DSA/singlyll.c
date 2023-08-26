/*#include<stdio.h>
#include<stdlib.h>

// Taking input and printing an array

struct Node{
    int data;
    struct Node * ptr;
};

void printlist(struct Node * index){
    while(index->ptr != NULL){
    printf("%d ", index->data);
    index = index->ptr;
    }
}

int main(){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    struct Node * nodes[n];
    for(int i = 0; i < n; i++){
        nodes[i] = (struct Node *) malloc(sizeof(struct Node));
    }

    printf("Input the data in linked list : ");
    for(int i = 0; i < n; i++){
        if(i == n - 1){
            scanf("%d", &nodes[i]->data);
            nodes[i]->ptr = NULL;
            break;
        }
        scanf("%d", &nodes[i]->data);
        nodes[i]->ptr = nodes[i+1];
    }

    printlist(nodes[0]);
}*/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node * ptr;
};

// Creating a function for printing the linked list
void printLL(struct Node * head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->ptr;
    }
}

struct Node * InsertBeg(struct Node * head){
    struct Node * new;
    new = (struct Node *) malloc(sizeof(struct Node));
    printf("Enter the data for the new node : ");
    scanf("%d", &new->data);
    new->ptr = head;
    return new;
}

struct Node * InsertBet(struct Node * head){
    int index, val;
    printf("Enter the index to insert at : ");
    scanf("%d", &index);
    printf("Enter the data to enter in new node : ");
    scanf("%d", &val);

    struct Node * new = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;

    for(int i = 0; i < index - 1; i++){
        p = p->ptr;
    }

    new->ptr = p->ptr;
    new->data = val;
    p->ptr = new;
    return new;
}

struct Node * DelBeg(struct Node * head){
    struct Node * new = head->ptr;
    free(head);
    return new;
}

void DelBet(struct Node * head){
    struct Node * p = head;
    struct Node * q = head->ptr;
    int index;
    printf("Enter the index to delete node : ");
    scanf("%d", &index);
    for(int i = 0; i < index - 1; i++){
        p = p->ptr;
        q = q->ptr;
    }
    p->ptr = q->ptr;
    free(q);
}

int main(){
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;

    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));

    // Setting up the first Node of the Linked List
    printf("Enter the data for node : ");
    scanf("%d", &head->data);
    head->ptr = second;

    // Setting up the second Node of the Linked List
    printf("Enter the data for node : ");
    scanf("%d", &second->data);
    second->ptr = third;

    // Setting up the third Node of the Linked List
    printf("Enter the data for node : ");
    scanf("%d", &third->data);
    third->ptr = fourth;

    // Setting up the last Node of the Linked List
    printf("Enter the data for node : ");
    scanf("%d", &fourth->data);
    fourth->ptr = NULL;


    // Now let's print our linked list before any insertion or deletion operation
    printLL(head);
    printf("\n");

    //Insertion


    // Inserting in the beginning
    head = InsertBeg(head);
    // Printing the Linked List Again
    printLL(head);
    printf("\n");

    // Inserting at Index
    struct Node * new = InsertBet(head);
    // Printing the Linked List Again
    printLL(head);
    printf("\n");

    // Deletion of Node

    // Deleting the head of linked list
    head = DelBeg(head);
    // Printing the Linked List Again
    printf("Linked List after deleting the head node : ");
    printLL(head);
    printf("\n");

    //Deleting element at a particular index
    DelBet(head);

    // Printing the Linked List Again
    printf("Linked List after deleting the index node : ");
    printLL(head);
    printf("\n");
}
