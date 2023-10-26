#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vctr = {1,2,3,4,5,6,7,4};
    auto it = lower_bound(vctr.begin(),vctr.end(),4);
    rotate(it,vctr.end()-1,vctr.end());
    for (auto it : vctr)printf("%d ",it);
    return 0;
}