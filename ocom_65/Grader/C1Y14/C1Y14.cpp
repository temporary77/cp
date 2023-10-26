#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[1000000] = {};
    bool d = 1;
    scanf("%[^\n]",arr);
    int n = strlen(arr);
    for (int i = 0; i < n; ++i) {
        if (arr[i] != arr[n-1-i]) {
            d = 0;
            break;
        }
    }
    if (d == 1) {
        printf("%s is a palindrome",arr);
    } else {
        printf("%s is not a palindrome",arr);
    }
    return 0;
}

