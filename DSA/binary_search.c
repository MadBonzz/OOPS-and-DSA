/*#include<stdio.h>

// Binary Search

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Input the array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the number to search : ");
    scanf("%d", &target);

    int index = -1;
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == target){
            index = mid;
            break;
        }else if(arr[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }

    if(index == -1){
        printf("Element is not in array ");
    }else{
        printf("The element is at index %d", index);
    }
}*/

/*#include<stdio.h>

// Binary Search using Recursion

int recursive_binary(int *arr, int target, int low, int high){
    if(low > high){
        return -1;
    }
    int mid = (low + high) / 2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] < target){
        return recursive_binary(arr, target, mid+1, high);
    }else{
       return recursive_binary(arr, target, low, mid - 1); 
    }
}

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Input the array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the number to search : ");
    scanf("%d", &target);

    
    int index = recursive_binary(arr, target, 0, size - 1);
    if(index == -1){
        printf("Element is not in array ");
    }else{
        printf("The element is at index %d", index);
    }
}*/

#include<stdio.h>

//Finding first occurence of an element

int firstindex(int *arr, int target, int low, int high, int index){
    if(low > high){
        return index;
    }
    int mid = low + ((high - low) / 2);
    if(arr[mid] == target){
        return firstindex(arr, target, low, mid-1, mid);
    }else if(arr[mid] > target){
        return firstindex(arr, target, low, mid-1, index);
    }else{
        return firstindex(arr, target, mid+1, high, index);
    }
}

int main(){
    int size;
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int arr[size];
    printf("Input the array : ");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target element ");
    scanf("%d", &target);

    int ans = firstindex(arr, target, 0, size-1, -1);
    if(ans == -1){
        printf("The element is not in array");
    }else{
        printf("The first index of element is %d", ans);
    }
}