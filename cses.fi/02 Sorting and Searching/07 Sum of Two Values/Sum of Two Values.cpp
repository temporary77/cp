#include <bits/stdc++.h>
using namespace std;

struct cheese {
    int a, b;
    bool operator < (const cheese &rhs) {
        return a < rhs.a;
    }
    bool operator > (const cheese &rhs) {
        return a > rhs.a;
    }
};

int main() {
    int n, x;
    scanf("%d%d",&n,&x);
    cheese arr[n], brr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i].a);
        arr[i].b = i;
    }
    sort(arr,arr+n);
    for (int i = 0; i < n; ++i) {
        brr[i].a = x-arr[i].a;
        brr[i].b = arr[i].b;
    }
    reverse(brr,brr+n);
    /*for (int i = 0; i < n; ++i) {
        printf("%d %d | %d %d\n",arr[i].a,arr[i].b,brr[i].a,brr[i].b);
    }*/
    int ai = 0, bi = 0;
    for (;ai < n && bi < n;) {
        if (arr[ai].a == brr[bi].a && arr[ai].b != brr[bi].b) {
            printf("%d %d",arr[ai].b+1,brr[bi].b+1);
            return 0;
        }
        if (arr[ai].a < brr[bi].a) {
            ++ai;
        } else {
            ++bi;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}
