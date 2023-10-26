#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int arr[N + 5];

void permutation(int i, const int &n){
    if(i == n){
        for(int j = 1; j <= n; ++j){
            cout << arr[j] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int j = i; j <= n; ++j){
        swap(arr[i], arr[j]);
        for(int k = j; k > i + 1; --k){
            swap(arr[k], arr[k - 1]);
        }
        permutation(i + 1, n);
        for(int k = i + 1; k < j; ++k){
            swap(arr[k], arr[k + 1]);
        }
        swap(arr[i], arr[j]);
    }
}

int main(){

    int n;
    scanf("%d", &n);
    int fact = 1;
    for(int i = 1; i <= n; ++i){
        scanf("%d", &arr[i]);
        fact *= i;
    }
    permutation(1, n);
    cout << fact;

    return 0;
}
