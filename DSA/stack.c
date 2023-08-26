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

int isFull(struct stack * s){
    if(s->top == s->size - 1) return 1;
    return 0;
}

int isEmpty(struct stack * s){
    if(s->top == - 1) return 1;
    return 0;
}

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
    struct stack *stp = (struct stack *) malloc(sizeof(struct stack));
    printf("Enter the size of stack : ");
    scanf("%d", &stp->size);
    stp->top = - 1;
    stp->arr = (int *) malloc(stp->size * sizeof(int));
    full_empty(isFull(stp), isEmpty(stp));
    
    push(stp);
    full_empty(isFull(stp), isEmpty(stp));
    push(stp);

    printf("\n");
    int num = pop(stp);
    printf("We have popped %d from stack\n", num);
    full_empty(isFull(stp), isEmpty(stp));
    pop(stp);
    num = pop(stp);
    printf("We have popped %d from stack\n", num);
}*/

#include<stdio.h>
