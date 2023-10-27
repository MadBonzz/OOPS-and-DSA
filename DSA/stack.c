/*#include<stdio.h>
#include<stdlib.h>

// Basic Implementation of Stack

struct stack{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack * s){
    if(s->top == s->size - 1) return 1;
    return 0;
}

int isEmpty(struct stack * s){
    if(s->top == - 1) return 1;
    return 0;
}

int main(){
    struct stack * s;
    printf("Enter the size of the array : ");
    scanf("%d", &s->size);
    s->top = -1;
    s->arr = (int *) malloc(s->size * sizeof(int));
    
    // Checking the stack before pushing any element 
    if(isFull(s)){
        printf("Stack is full\n");
    }else{
        printf("Stack is not full\n");
    }

    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
    printf("\n");
    // Now let's push an element in the stack and check again
    s->arr[0] = 5;
    s->top++;
    if(isFull(s)){
        printf("Stack is full\n");
    }else{
        printf("Stack is not full\n");
    }

    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
}*/

/*#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

// Push and Pop in stack

struct stack{
    int size;
    int top;
    int * arr;
};

// Function to check if Stack is full
int isFull(struct stack * s){
    if(s->top == s->size - 1) return 1;
    return 0;
}

// Function to check if stack is empty
int isEmpty(struct stack * s){
    if(s->top == - 1) return 1;
    return 0;
}

// Function that prints if the stack is full or empty
void full_empty(int full, int empty){
    if(full){
        printf("Stack is full\n");
    }else{
        printf("Stack is not full\n");
    }

    if(empty){
        printf("Stack is empty\n");
    }else{
        printf("Stack is not empty\n");
    }
    return;
}

// Function to push any element into the stack
void push(struct stack * ptr){
    if(isFull(ptr)){
        printf("Stack Overflow. Can't push into the stack\n");
    }else{
    int val;
    printf("Enter the value to be pushed : ");
    scanf("%d", &val);
    ptr->top++;
    ptr->arr[ptr->top] = val;
    }
}

// Function to pop an element from the stack
int pop(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow. Stack is empty\n");
        return INT_MIN;
    }else{
        int num = ptr->arr[ptr->top];
        ptr->top--;
        return num;
    }
}

int main(){
    // Initialising an empty Stack
    struct stack *stp = (struct stack *) malloc(sizeof(struct stack));
    printf("Enter the size of stack : ");
    scanf("%d", &stp->size);
    stp->top = - 1;
    stp->arr = (int *) malloc(stp->size * sizeof(int));
    full_empty(isFull(stp), isEmpty(stp));
    
    // Pushing an element into the stack
    push(stp);
    push(stp);
    push(stp);
    full_empty(isFull(stp), isEmpty(stp));
    printf("\n");

    // Popping elements from the stack
    int num = pop(stp);
    printf("We have popped %d from stack\n", num);
    pop(stp);
    num = pop(stp);
    printf("We have popped %d from stack\n", num);
    full_empty(isFull(stp), isEmpty(stp));
}*/

/*#include<stdio.h>
#include<stdlib.h>

// Stack using Linked List

struct Node{
    int data;
    struct Node * next;
};

int isFull(struct Node * ptr){
    struct Node * new = (struct Node * ) malloc(sizeof(struct Node));
    if(new == NULL){
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(struct Node * ptr){
    if(ptr == NULL){
        return 1;
    }else{
        return 0;
    }
}

struct Node * push(struct Node * ptr){
    if(isFull(ptr)){
        printf("Stack Overflow \n");
    }else{
        struct Node * new = (struct Node * ) malloc(sizeof(struct Node));
        int val;
        printf("Enter the data to be input : ");
        scanf("%d", &val);
        new->data = val;
        new->next = ptr;
        ptr = new;
        printf("Pushed : %d\n", new->data);
        return ptr;
    }
}

int pop(struct Node ** ptr){
    if(isEmpty(*ptr)){
        printf("Stack Underflow");
    }else{
        struct Node * new = *ptr;
        *ptr = (*ptr)->next;
        int val = new->data;
        free(new);
        return val;
    }
}

void printLL(struct Node * head){
    while(head != NULL){
        printf("%d \n", head->data);
        head = head->next;
    }
}

int main(){
    // Initialising a stack using Linked List
    struct Node * stack = NULL;
    // Pushing some values into the stack
    stack = push(stack);
    stack = push(stack);
    stack = push(stack);
    // Let's print the stack we have for now
    printLL(stack);

    // Popping some values from the stack
    int num;
    num = pop(&stack);
    printf("Popped %d from stack\n", num);
    num = pop(&stack);
    printf("Popped %d from stack\n", num);
    // Printing the stack again
    printLL(stack);
}*/


