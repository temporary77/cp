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
 
int tree[200005];

multiset<pair<paris,int>> mltst1;

void update() {

    
}
 
int main() {
    //freopen("test_input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int a, b, c;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a,&b);
        mltst1.insert({{a,b},i});
    }
    update();
    for (int i = 0; i < n; ++i) {

    }
    return 0;
}