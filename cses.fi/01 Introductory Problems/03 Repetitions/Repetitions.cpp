#include <bits/stdc++.h>
using namespace std;

char arr[1000000];

int main() {
    scanf("%s",arr);
    unsigned l = strlen(arr);
    long long cnt = 1, max1 = 1;
    for (int i = 0; i < l; ++i) {
        if (arr[i] == arr[i+1]) {
            ++cnt;
            if (cnt > max1) {max1 = cnt;}
        } else {
            cnt = 1;
        }
    }
    printf("%d",max1);
    return 0;
}
