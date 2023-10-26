#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, n;
    scanf("%d%d",&x,&n);
    set<int> st;
    map<int,int> host;
    set<int> dist;
    st.insert(0);
    st.insert(n);
    dist.insert(x);
    host[0] = x;
    for (int i = 0; i < n; ++i) {
        printf("--------------report\n");
        for (auto it = st.begin(); it != st.end(); ++it) {
            printf("%d ",*it);
        }
        printf("\n");
        for (auto it = host.begin(); it != host.end(); ++it) {
            printf("%d ",it->first);
        }
        printf("\n");
        for (auto it = host.begin(); it != host.end(); ++it) {
            printf("%d ",it->second);
        }
        printf("\n");
        for (auto it = dist.begin(); it != dist.end(); ++it) {
            printf("%d ",*it);
        }
        printf("\n");
        printf("------------------\n");
        int k;
        scanf("%d",&k);
        auto it = st.lower_bound(k);
        int idxl = *(--it);
        int idxr = *(++it);
        printf("indexes %d %d\n",idxl,idxr);
        auto it2 = dist.find(host[idxl]);
        dist.erase(it2);
        dist.insert(k-idxl);
        dist.insert(idxr-k);
        host[idxl] = k-idxl;
        host[k] = idxr-k;
        st.insert(k);
        printf("%d ",*(dist.rbegin()));
    }
    
    return 0;
}