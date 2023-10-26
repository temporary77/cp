#include <bits/stdc++.h>
using namespace std;

struct banana {
    int a, b, c;
    bool operator < (const banana &rhs) {
        if (a != rhs.a) {
            return a < rhs.a;
        } else if (b != rhs.b) {
            return b > rhs.b;
        } else {
            return c < rhs.c;
        }
    }
    void swapping(banana &rhs) {
        int temp;
        temp = a;
        a = rhs.a;
        rhs.a = temp;
        temp = b;
        b = rhs.b;
        rhs.b = temp;
        temp = c;
        c = rhs.c;
        rhs.c = temp;
    }
};

int main() {
    int n;
    scanf("%d",&n);
    banana arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
    }
    int swaps[n], cnt = 1;
    int k = 0;
    for (int i = 0; i < n-1; ++i) {
        banana min1 = {1000001,1000001,1000001};
        k = -1;
        for (int j = i; j < n; ++j) {
            if (arr[j] < min1) {
                min1 = arr[j];
                k = j;
            }
        }
        if (k >= 0) {
            swaps[cnt] = k;
            cnt++;
            arr[i].swapping(arr[k]);
        }
    }
    int q, x;
    scanf("%d",&q);
    for (int i = 0; i < q; ++i) {
        scanf("%d",&x);
        printf("%d\n",swaps[x]);
    }
    for (int i = 0; i < n; ++i) {
        printf("%d %d %d\n",arr[i].a,arr[i].b,arr[i].c);
    }
    return 0;
}
