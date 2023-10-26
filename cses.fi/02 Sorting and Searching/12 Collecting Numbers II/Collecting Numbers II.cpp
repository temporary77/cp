#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int arr[n], pos[n];
    bool dev[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
        pos[arr[i]-1] = i;
    }
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (pos[i] < pos[i-1]) {
            ++cnt;
            dev[i] = 0;
        } else {
            dev[i] = 1;
        }
    }
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d",&a,&b);
        --a;
        --b;
        swap(arr[a],arr[b]);
        swap(pos[arr[a]-1],pos[arr[b]-1]);
        int checks[4] = {arr[a],arr[a]+1,arr[b],arr[b]+1};
        // printf("checks %d %d %d %d\n",arr[a],arr[a]+1,arr[b],arr[b]+1);
        for (int j = 0; j < 4; ++j) {
            int k = checks[j]-1;
            /*printf("%d %d %d\n",i,j,k);
            printf("------------------\n");
            for (int i = 0; i < n; ++i) {
                printf("%d %d %d\n",arr[i],pos[i],dev[i]);
            }
            printf("------------------>\n");*/
            if(k == 0 || k == n)continue;
            if (dev[k] == 0) {
                if (pos[k] > pos[k-1]) {
                    dev[k] = 1;
                    --cnt;
                    // printf("minus\n");
                }
            } else {
                if (pos[k] < pos[k-1]) {
                    dev[k] = 0;
                    ++cnt;
                    // printf("positive\n");
                }
            }
        }
        printf("%d\n",cnt);
    }

    return 0;
}
