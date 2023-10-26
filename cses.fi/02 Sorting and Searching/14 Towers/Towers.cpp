#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    multiset<int> mltst;
    int k;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        auto it = mltst.upper_bound(k);
        if (it == mltst.end()) {
            mltst.insert(k);
            continue;
        }
        mltst.erase(it);
        mltst.insert(k);
    }
    printf("%lu",mltst.size());
    return 0;
}
