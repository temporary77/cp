#include <bits/stdc++.h>
using namespace std;

int main() {
    char arr[1000000] = {};
    bool d = 1, cap = 0, nocap = 0;
    scanf("%[^\n]",arr);
    int n = strlen(arr);
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 65 && arr[i] <= 90) {
            cap = 1;
        } else {
            nocap = 1;
        }
    }
    if (cap == 1 && nocap == 1) {
        printf("[%d]Mix",n);
    } else if (cap == 1) {
        printf("[%d]All Capital Letter",n);
    } else {
        printf("[%d]All Small Letter",n);
    }
    return 0;
}

