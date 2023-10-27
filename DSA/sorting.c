#include<stdio.h>

void printArray(int * arr, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

void BubbleSort(int * arr, int n){
    for(int i = 0; i < n; i++){
        int flag = 0;
        for(int j = 0; j < n - 1 - i; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                flag++;
            }
        }
        if(flag == 0) break;
    }
}

void SelectionSort(int * arr, int n){
    for(int i = 0; i < n; i++){
        int min_idx = i;
        for(int j = i+1; j < n; j++){
            if(*(arr + j) < *(arr + min_idx)){
                min_idx = j;
            }
        }
        if(min_idx != i){
            int temp = *(arr + min_idx);
            *(arr + min_idx) = *(arr + i);
            *(arr + i) = temp;
        }
    }
}

void InsertionSort(int * arr, int n){
    for(int i = 1; i < n; i++){
        int current = *(arr + i);
        int j = i - 1;

        while(j >= 0 && (*(arr + j) > current)){
            *(arr + j + 1) = *(arr + j);
            j--;
        }
        *(arr + j + 1) = current;
    }
}

int main(){
    int size = 18;
    int arr[18] = {5, -10, 11, 29, -2, 0, 68, 19, 72, 65, 56, 20, 36, 54, 101, -9, 2, 23};

    printArray(arr, size);
    InsertionSort(arr, size);
    printArray(arr, size);
}