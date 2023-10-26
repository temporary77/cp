#include <bits/stdc++.h>
using namespace std;

int arr[200001];
int tree[200001];
int n, m;

void build() {
    for (int i = 1; i <= n; ++i) {
        tree[i] = i&-i;
    }
    return;
}

void update(int a, int val) {
    for (int i = a; i <= n; i += i&-i) {
        tree[i] += val;
    }
    return;
}

int query(int a) {
    int res = 0;
    for (int i = a; i > 0; i -= i&-i) {
        res += tree[i];
    }
    return res;
}

bool comp(int a, int b) {
    return query(a) < b;
}

int main() {
    scanf("%d%d",&n,&m);
    build();
    ++m;
    int realidx = 0;
    for (int i = 1; i <= n; ++i)arr[i] = i;
    for (int i = n; i >= 1; --i) {
        // for (int i = 1; i <= n; ++i) {
        //     printf("%d ",tree[i]);
        // }
        // printf("\n");
        // printf("next chop %d %d\n",query(realidx),(query(realidx)+m-1)%i+1);
        realidx = lower_bound(arr+1,arr+n+1,(query(realidx)+m-1)%i+1,comp)-arr; //find pos of next order to chop 
        // printf("at %d\n",realidx);
        update(realidx,-1); //chop
        //idx = (realidx+m-1)%i+1; //find next order
        printf("%d ",realidx);
    }
    return 0;
}