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

/*#include<stdio.h>

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
}*/

/*#include<stdio.h>

// Largest number with square less than target

int largestRoot(int *arr, int target, int low, int high){
    int ans;
    while(low <= high){
        int mid = low + ((high - low) / 2);
        if((arr[mid] * arr[mid]) == target){
            ans = mid;
            break;
        }else if((arr[mid] * arr[mid]) < target){
            ans = mid;
            low = mid+1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int target;
    printf("Enter the target element ");
    scanf("%d", &target);

    int arr[target];
    for(int i = 0; i < target; i++){
        arr[i] = i+1;
    }

    int ans = largestRoot(arr, target, 0, target - 1);
    printf("The largest element with square less than number is %d", arr[ans]);
}*/

/*#include<stdio.h>

// First and Last occurence of an element

int lowerbound(int *arr, int target, int low, int high){
    int ans;
    while(low <= high){
        int mid = low + ((high - low) / 2);
        if(arr[mid] >= target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid+1;           
        }
    }
    return ans;
}

int upperbound(int *arr, int target, int low, int high){
    int ans;
    while(low <= high){
        int mid = low + ((high - low) / 2);
        if(arr[mid] > target){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
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

    int lower = lowerbound(arr, target, 0, size - 1);
    if(lower == -1){
        printf("Element is not in array ");
    }else{
        int upper = upperbound(arr, target, 0, size-1);
        printf("The lower and upper bound are %d and %d", lower, upper-1);
    }
}*/

/*#include<stdio.h>

// Minimum value of rotated sorted array

int minval(int *arr, int size){
    if(size == 1) return 0;
    int low = 0;
    int high = size - 1;
    if(arr[low] < arr[high]) return low;
    while(low <= high){
        int mid = low + (high-low) / 2;
        if(arr[mid] > arr[mid+1]) return mid + 1;
        if(arr[mid] < arr[mid - 1]) return mid;
        if(arr[mid] < arr[low]){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
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
    int min_index = minval(arr, size);
    printf("The minimum value of the array is %d", arr[min_index]);
}*/

/*#include<stdio.h>

// Finding element in Rotated Sorted Array

int find(int *arr, int target, int low, int high){
    int index = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(target == arr[mid]){
            index = mid;
            break;
        }
        if(arr[mid] > arr[low]){
            if((arr[mid] > target) && (arr[low] <= target)){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if((arr[mid] < target) && (arr[high]>= target)){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
    }
    return index;
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

    int ans = find(arr, target, 0, size - 1);
    if(ans == -1){
        printf("Element is not in array");
    }else{
        printf("Element is at index %d", ans);
    }
}*/