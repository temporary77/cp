#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[100000] = {};
    bool d = 1;
    scanf("%[^\n]",arr);
    int n = strlen(arr);
    while (arr[n-1] == ' ') {
        arr[n-1] = '\0';
        --n;
    }
    for (int i = 0; i < n/2; ++i) {
        if (arr[i] != arr[n-1-i]) {
            d = 0;
            break;
        }
    }
    if (d == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}
