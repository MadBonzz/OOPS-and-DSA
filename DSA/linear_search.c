#include<stdio.h>

int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Input the array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter the number to be searched : ");
    scanf("%d", &num);

    int index = -1;
    for(int i = 0; i < size; i++){
        if(arr[i] == num){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("The element is not in array ");
    }else{
        printf("The element is at index %d", index);
    }
}