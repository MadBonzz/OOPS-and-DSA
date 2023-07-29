/*#include<iostream>
using namespace std;

// Printing array using recursion

void printarr(int *arr, int n, int idx = 0){
    if(idx == n){
        return;
    }
    cout<<arr[idx];
    printarr(arr, n, idx+1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    printarr(arr, n, 0);
}*/

/*#include<iostream>
using namespace std;

// Max Element using Recursion

int maximum(int *arr, int n, int idx = 0){
    if(idx == n-1) return arr[idx];
    return max(arr[idx], maximum(arr, n, idx+1));
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int maxele = maximum(arr, n, 0);
    cout<<maxele;
}*/

/*#include<iostream>
using namespace std;

// Sum of elements in array

int sum(int *arr, int n, int idx = 0){
    if(idx == n-1){
        return arr[idx];
    }
    return arr[idx] + sum(arr, n, idx+1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int arr_sum = sum(arr, n, 0);
    cout<<arr_sum<<endl;
}*/

/*#include<iostream>
#include<string>
using namespace std;

// Removing a particular character from a string

string remove(string &s, int idx, char c, int n){
    if(idx == n) return "";
    string curr = "";
    curr += s[idx];
    return ((s[idx] == c) ? "" : curr) + remove(s, idx + 1, c, n);
}

int main(){
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    int len = s.size();

    string final = remove(s, 0, ch, len);
    cout<<final<<endl;
}*/

#include<iostream>
using namespace std;

void pattern(int num, int n, int s, bool flag){
    if(n <= 0 && flag == true){
        flag = false;
        pattern(num, n, s, flag);
    }
    else if(flag == false && n == num){
        cout<<n<<" ";
        return;
    }
    else if(flag == true && n > 0){
        cout<<n<<" ";
        pattern(num, n-s, s, flag);
    }else{
        cout<<n<<" ";
        pattern(num, n+s, s, flag);
    }

    return;
}

int main(){
    // int number;
    // cin>>number;
    // int step;
    // cin>>step;
    bool flag = true;
    pattern(16, 16, 5, flag);
    
}