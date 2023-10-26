#include <bits/stdc++.h>
using namespace std;

struct real1 {
    int idx, num;
    double scr;
    bool operator < (const real1 &rhs) {
        if (scr != rhs.scr) {
            return scr > rhs.scr;
        } else if (num != rhs.num) {
            return num < rhs.num;
        } else {
            return idx < rhs.idx;
        }
    }
};

int main() {
    int n, m, k, h;
    scanf("%d%d%d%d",&n,&m,&k,&h);
    int a, b, c;
    real1 realism[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a,&b);
        int sum = 0;
        int arr[b];
        for (int j = 0; j < b; ++j) {
            scanf("%d",&arr[j]);
        }
        sort(arr,arr+b,greater<int>());
        int det = k;
        if (b < k)det = b;
        for (int j = 0; j < det; ++j) {
            sum += arr[j];
            //printf("%d ",arr[j]);
        }
        double avg = sum/(double)det;
        realism[i] = {a,b,avg};
        //printf(">> %d <<\n",i);
        //printf("\n%d %d %lf\n",sum,det,avg);
    }
    sort(realism,realism+n);
    for (int i = 0; i < h; ++i) {
        if (i == h-1) {
            int cnt = realism[i].num;
            double pnts = realism[i].scr;
            for (;realism[i].num == cnt && realism[i].scr == pnts;) {
                printf("%d \n",realism[i].idx);
                ++i;
            }
            break;
        }
        printf("%d \n",realism[i].idx);
    }
    return 0;
}
