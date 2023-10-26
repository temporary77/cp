#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    multiset<int> tckts;
    int ipt;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&ipt);
        tckts.insert(ipt);
    }
    /*for (multiset<int>::iterator i = tckts.begin(); i != tckts.end(); ++i) {
        printf("%d %d\n",i,*i);
    }*/
    for (int i = 0; i < m; ++i) {
        scanf("%d",&ipt);
        multiset<int>::iterator x = tckts.upper_bound(ipt);
        // multiset<int>::iterator x = upper_bound(tckts.begin(),tckts.end(),ipt);
        // printf("%d %d %d %d\n",tckts.begin(),tckts.end(),x,*x);
        if (x == tckts.begin()) {
            printf("-1\n");
            continue;
        }
        --x;
        printf("%d\n",*x);
        tckts.erase(x);
    }
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("test_input.txt","r",stdin);
    int n, m;
    scanf("%d%d",&n,&m);
    int tckts[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&tckts[i]);
    }
    sort(tckts,tckts+n);
    for (int i = 0; i < n; ++i) {
        printf("%d ",tckts[i]);
    }
    printf("\n");
    int prc, k = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d",&prc);
        int x = upper_bound(tckts,tckts+n-k,prc)-tckts-1;
        printf("%d<>\n",x);
        if (x == -1) {
            printf("-1\n");
            continue;
        }
        printf("%d\n",tckts[x]);
        printf("|%d %d %d|\n",tckts+x,tckts+x+1,n-x);
        memmove(tckts+x,tckts+x+1,(n-k-x)*4);
        ++k;
        for (int i = 0; i < n; ++i) {
            printf("%d ",tckts[i]);
        }
        printf("\n");
    }
}*/
