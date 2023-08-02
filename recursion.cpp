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

/*#include<iostream>
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
    
}*/

/*#include<iostream>
using namespace std;

int sum(int n, int m){
    if(m == 1){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            sum += i;
        }
        return sum;
    }
    return sum(sum(n, m-1),1);
}

int main(){
    int n, m;
    cin>>n>>m;

    int total = sum(n, m);
    cout<<total<<endl;
}*/

/*#include<iostream>
using namespace std;

int count(int n, int v){
    int total = 0;
    if(n == 1 && v >= 0){
        return 1;
    }
    for(int i = 0; i <= v; i++){
        total += count(n-1, v-i);
    }
    return total;
}

int main(){
    int num, val;
    cin>>num>>val;
    int total = count(num, val);
    cout<<total<<endl;
}*/

/*#include<iostream>
using namespace std;

// Increasing Sequence

void sequence(int n){
    if(n == 1){
        cout<<n<<" ";
        return;
    }
    sequence(n-1);
    cout<<n<<" ";
}

int main(){
    int number;
    cout<<"Enter a number : ";
    cin>>number;

    sequence(number);
}*/

/*#include<iostream>
using namespace std;

// k multiples of n

void multiples(int n, int k){
    if(k < 1){
        return;
    }
    multiples(n, k-1);
    cout<<n*k<<" ";
}

int main(){
    int number, multiple;
    cin>>number>>multiple;
    multiples(number, multiple);
}*/

/*#include<iostream>
using namespace std;

// Sum with alternate sign

int altsum(int n){
    if(n < 1) return 0;
    return altsum(n-1) + ((n % 2 == 0) ? -n : n);
}

int main(){
    int number;
    cin>>number;
    int sum = altsum(number);
    cout<<sum<<endl;
}*/

/*#include<iostream>
using namespace std;

// Product of numbers using recursion

int product(int n, int m){
    if(m == 0) return 0;
    return product(n, m-1) + n;
}

int main(){
    int num1, num2;
    cin>>num1>>num2;
    int prod = product(num1, num2);
    cout<<prod<<endl;
}*/

/*#include<iostream>
using namespace std;

// GCD using Recursion

int gcd(int n, int m){
    if(n == m){
        return n;
    }

    return ((n > m) ? gcd(n - m, m) : gcd(n, m - n));
}

int main(){
    int num1, num2;
    cin>>num1>>num2;

    int hcf = gcd(num1, num2);
    cout<<hcf<<endl;
}*/

/*#include<iostream>
#include<cmath>
using namespace std;

// Armstrong number using recursion

int armstrong(int n, int d){
    if(n == 0) return 0;
    return armstrong(n / 10, d) + pow(n % 10, d);
}

int main(){
    int number;
    cin>>number;
    int temp = number;
    int digits = 0;
    while(temp > 0){
        digits++;
        temp /= 10;
    }

    int result = armstrong(number, digits);
    (result == number) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
}*/

/*#include<iostream>
using namespace std;

int min_cost(int *arr, int idx, int n){
    if(idx == n-1){
        return 0;
    }else if(idx == n-2){
        return abs(arr[idx + 1] - arr[idx]);
    }
    if(min_cost(arr, idx+1, n) + (abs(arr[idx+1] - arr[idx])) >= min_cost(arr, idx+2, n) + (abs(arr[idx+2] - arr[idx]))){
        return min_cost(arr, idx+2, n) + (abs(arr[idx+2] - arr[idx]));
    }else{
        return min_cost(arr, idx+1, n) + (abs(arr[idx+1] - arr[idx]));
    }
}

int main(){
    int n;
    cin>>n;
    int height[n];
    for(int i = 0; i < n; i++){
        cin>>height[i];
    }

    int cost = min_cost(height, 0, n);
    cout<<cost<<endl;
}*/

/*#include<iostream>
using namespace std;

// Prime Number using Recursion

bool primenum(int i, int j = 2){
    if(j * j > i){
        return true;
    }
    return (i % j != 0) && primenum(i, j+1);
}

int main(){
    int num;
    cin>>num;
    cout<<primenum(num)<<endl;
}*/

/*#include<iostream>
using namespace std;

// Decimal to Binary using Recursion

void binary(int n){
    if(n == 0){
        return;
    }

    binary(n / 2);
    (n % 2 == 0)? cout<<"0" : cout<<"1";
    return;
}

int main(){
    int number;
    cin>>number;
    binary(number);
}*/

/*#include<iostream>
#include<cmath>
using namespace std;

// Binary to Gray using Recursion

int gray(int n, int i){
    int a, b;
    int result = 0;
    if(n != 0){
        a = n % 10;
        n /= 10;
        b = n % 10;

        if((a & ~b) == 1 || (~a & b) == 1){
            result = (int)(result + pow(10, i));
        }
        return gray(n, ++i) + result;
    }
    return result;
}

int main(){
    int num;
    cin>>num;
    
    int result = gray(num, 0);
    cout<<result<<endl;
}*/

/*#include<iostream>
using namespace std;

// Cheching if element exists in array

bool check(int *arr, int n, int m, int idx=0){
    if(idx == n){
        return false;
    }
    return ((arr[idx] == m ) | check(arr, n, m, ++idx));
}

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    int target;
    cin>>target;

    cout<<check(arr, size, target, 0);
}*/

/*#include<iostream>
using namespace std;

// Printing sum of all subsets of an array

void subsetsum(int *arr, int n, int sum, int idx = 0){
    if(idx == n){
        cout<<sum<<" ";
        return;
    }
    subsetsum(arr, n, sum+arr[idx], idx + 1);
    subsetsum(arr, n, sum, idx + 1);
}

int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    subsetsum(arr, size, 0, 0);
}*/

/*#include<iostream>
using namespace std;

// Finding number of paths from top left to bottom right

int countpaths(int *arr, int n, int m, int idx_i, int idx_j){
    if((idx_i == n-1) && (idx_j == m-1)) return 1;
    if((idx_i == n) || (idx_j == m)) return 0;

    return countpaths(arr, n, m, idx_i+1, idx_j) + countpaths(arr, n, m, idx_i, idx_j + 1);
}

int main(){
    int nrow, ncol;
    cin>>nrow>>ncol;

    int matrix[nrow][ncol];

    int counts = countpaths(matrix[0], nrow, ncol, 0, 0);
    cout<<counts<<endl;
}*/

/*#include<iostream>
using namespace std;

// Printing indices where target is present

void indexes(int *arr, int target, int n, int idx = 0){
        if(idx == n) return;
        ((arr[idx] == target) ? cout<<idx<<" " : cout<<"");
        return indexes(arr, target, n, ++idx);
    }

int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }
    int target;
    cin>>target;
    indexes(arr, target, size, 0);
}*/

/*#include<iostream>
using namespace std;

// Sum Triangle of an array

void sumtriangle(int *arr, int n, int idx = 0){
    if(n == 0){
        return;
    }
    if(idx == n){
        cout<<endl;
        return sumtriangle(arr, n-1, 0);
    }

    cout<<arr[idx];
    arr[idx] += arr[idx+1];
    return sumtriangle(arr, n, ++idx);
}

int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    sumtriangle(arr, size, 0);
}*/

/*#include<iostream>
#include<vector>
using namespace std;

// Subsequences of a string

void subsequence(string s, int n, int idx, vector<string> *v, string res){
    if(idx == n){
        v->push_back(res);
        return;
    }
    subsequence(s, n, idx + 1, v, res+s[idx]);
    subsequence(s, n, idx + 1, v, res);
}

int main(){
    string sequence;
    cin>>sequence;

    int size = sequence.size();

    vector<string> sub;
    subsequence(sequence, size, 0, &sub, "");

    for(int i = 0; i < sub.size(); i++){
        cout<<sub[i]<<" ";
    }
}*/

/*#include<iostream>
#include<vector>
using namespace std;

// Printing combinations based on old keypad

void printcombs(string s, int idx, string res, vector<string> &v, vector<string> &patt){
    if(idx == s.size()){
        v.push_back(res);
        return;
    }
    int dig = s[idx] - '0';
    if(dig <= 1){
        printcombs(s, idx + 1, res, v, patt);
        return;
    }

    for(int j = 0; j < patt[dig].size(); j++){
        printcombs(s, idx+1, res + patt[dig][j], v, patt);
    }
    return;
}

int main(){
    string nums;
    cin>>nums;

    vector<string> str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combs;
    printcombs(nums, 0, "", combs, str);

    for(int i = 0; i < combs.size(); i++){
        cout<<combs[i]<<" ";
    }
}*/

/*#include<iostream>
#include<vector>
using namespace std;

// Printing all possible combinations of r elements

void printcombs(int *arr, int n, int r, int idx, vector<int> &temp, vector<vector<int>> &combs){
    if(temp.size() == r){
        combs.push_back(temp);
        return;
    }else if(idx == n){
        return;
    }

    temp.push_back(arr[idx]);
    printcombs(arr, n, r, idx+1, temp, combs);

    temp.pop_back();
    printcombs(arr, n, r, idx+1, temp, combs);
    return;

    }

int main(){
    int size;
    cin>>size;

    int arr[size];
    for(int i = 0; i < size; i++){
        cin>>arr[i];
    }

    int r;
    cin>>r;

    vector<int> data;
    vector<vector<int>> comb;

    printcombs(arr, size, r, 0, data, comb);

    cout<<comb.size();

    for(int i = 0; i < comb.size(); i++){
        for(int j = 0; j < r; j++){
            cout<<comb[i][j]<<" ";
        }
        cout<<endl;
    }
}*/
    


