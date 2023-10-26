#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&a);
    bool existence = 0;
    for (int i = 0; i < n; ++i) {
        if (a == arr[i]) {
            printf("%d ",i+1);
            existence = 1;
        }
    }
    if (existence == 0) {
        printf("0");
    }
    return 0;
}
