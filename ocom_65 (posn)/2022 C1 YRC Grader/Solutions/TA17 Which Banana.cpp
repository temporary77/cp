#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

struct banana {
    int a, b, c;
    banana(): a(0), b(0), c(0) {}
    banana(int a, int b, int c): a(a), b(b), c(c) {}
    bool operator < (const banana &rhs) const {
        if(a != rhs.a){
            return a < rhs.a;
        } else if(b != rhs.b){
            return b > rhs.b;
        }
        return c < rhs.c;
    }
};

banana arr[N + 5];
int idx[N + 5];

int main(){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].c);
    }
    for(int i = 1; i <= n - 1; ++i){
        int mnIdx = i;
        for(int j = i + 1; j <= n; ++j){
            if(arr[j] < arr[mnIdx]){
                mnIdx = j;
            }
        }
        idx[i] = mnIdx;
        swap(arr[i], arr[mnIdx]);
    }
    int Q;
    scanf("%d", &Q);
    while(Q-- > 0){
        int x;
        scanf("%d", &x);
        cout << idx[x] - 1 << '\n';
    }
    for(int i = 1; i <= n; ++i){
        cout << arr[i].a << ' ' << arr[i].b << ' ' << arr[i].c << '\n';
    }

    return 0;
}
