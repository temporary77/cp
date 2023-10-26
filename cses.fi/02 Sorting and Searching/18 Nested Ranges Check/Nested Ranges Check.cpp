#include <bits/stdc++.h>
using namespace std;

struct paris {
    int first, second;
    bool operator <(const paris &rhs) const {
        if (first != rhs.first) {
            return first < rhs.first;
        } else {
            return second > rhs.second;
        }
    }
};

bool in[200005], out[200005];

multiset<pair<paris,int>> mltst1;

int main() {
    //freopen("test_input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a,&b);
        mltst1.insert({{a,b},i});
    }
    auto it = mltst1.begin();
    b = it->first.second;
    c = it->second;
    ++it;
    int bi, ci;
    for (int i = 1; i < n; ++i) {
        bi = it->first.second;
        ci = it->second;
        if (bi <= b) {
            in[ci] = 1;
        } else {
            b = it->first.second;
            c = it->second;
        }
        ++it;
    }
    it = mltst1.end();
    --it;
    b = it->first.second;
    c = it->second;
    --it;
    for (int i = 1; i < n; ++i) {
        bi = it->first.second;
        ci = it->second;
        if (bi >= b) {
            out[ci] = 1;
        } else {
            b = it->first.second;
            c = it->second;
        }
        --it;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d ",out[i]);
    }
    printf("\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ",in[i]);
    }
    return 0;
}
