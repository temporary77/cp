#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, result = 0;
    scanf("%d",&n);
    int arr[5];
    for (int i = 0; i < 5; ++i) {
        arr[4-i] = n%10;
        n /= 10;
    }
    if (arr[4] > 5) {
        result += 500;
    } else if (arr[3] > 5) {
        result += 400;
    } else if (arr[2] > 5) {
        result += 300;
    } else if (arr[1] > 5) {
        result += 200;
    } else if (arr[0] > 5) {
        result += 100;
    }
    if (arr[0] == arr[4] && arr[1] == arr[3]) {
        if (arr[1]-arr[4] > 5) {
            result += 20;
        } else if (arr[0]+arr[4] > 5) {
            result += 10;
        }
    } else {

    }
    return 0;
}
