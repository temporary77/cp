#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("test_input.txt","r",stdin);
    int n, mode;
    scanf("%d%d",&n,&mode);
    deque<long long> vctr;
    deque<long long> arr[10];
    long long max1 = 0;
    long long k;
    for (int i = 0; i < n; ++i) {
        scanf("%lld",&k);
        max1 = max(max1,k);
        vctr.push_back(k);
    }
    for (long long i = 1; max1/i > 0; i *= 10) {
        for (int j = 0; j < n; ++j) {
            arr[vctr[0]/i%10].push_back(vctr[0]);
            vctr.pop_front();
        }
        for (int j = 0; j < 10; ++j) {
            for (;!arr[j].empty();) {
                vctr.push_back(arr[j][0]);
                if (mode == 1)printf("%lld ",arr[j][0]);
                arr[j].pop_front();
            }
        }
        if (mode == 1)printf("\n");
    }
    if (mode == 0) {
        for (int i = 0; i < n; ++i) {
            printf("%lld ",vctr[i]);
        }
        printf("\n");
    }
    return 0;
}
