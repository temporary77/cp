#include <bits/stdc++.h>
using namespace std;

bool sort1(const tuple<int,int,int> &a, const tuple<int,int,int> &b) {
    if (get<2>(a) != get<2>(b)) {
        return get<2>(a) > get<2>(b);
    } else {
        return get<1>(a) < get<1>(b);
    }
}

int main() {
    for (int i = 0; i < 5; ++i) {
        int n, c;
        scanf("%d%d",&n,&c);
        map<int,pair<int,int>> mp;
        int k, l = 0;
        for (int j = 0; j < n; ++j) {
            scanf("%d",&k);
            if (mp[k].second == 0) {
                mp[k].first = l++;
            }
            ++mp[k].second;
        }
        vector<tuple<int,int,int>> vctr;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int idx = it->first;
            vctr.push_back({idx,mp[idx].first,mp[idx].second});
        }
        sort(vctr.begin(),vctr.end(),sort1);
        for (auto it = vctr.begin(); it != vctr.end(); ++it) {
            for (int j = 0; j < get<2>(*it); ++j) {
                printf("%d ",get<0>(*it));
            }
        }
        printf("\n");
    }
    return 0;
}
