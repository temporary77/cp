#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    multiset<int> mltst;
    int k, sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        sum += k;
        mltst.insert(k);
    }
    sum /= n;
    int cnt = 0;
    for (auto it = mltst.begin(); *it < sum; ++it) {
        cnt += abs(sum-(*it));
    }
    printf("%d",cnt);
    
    return 0;
}