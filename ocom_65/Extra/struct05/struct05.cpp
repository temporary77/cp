#include <bits/stdc++.h>
using namespace std;

struct time1 {
    int h, m, s;
    time1 operator - (const time1 &rhs) const {
        time1 diff = {rhs.h-h,rhs.m-m,rhs.s-s};
        if (diff.s < 0) {
            diff.s += 60;
            diff.m--;
        }
        if (diff.m < 0) {
            diff.m += 60;
            diff.h--;
        }
        return diff;
    }
};

int main() {
    time1 start1, end1;
    scanf("%d%d%d%d%d%d",&start1.h,&start1.m,&start1.s,&end1.h,&end1.m,&end1.s);
    printf("%d:%02d:%02d - %d:%02d:%02d = %d:%02d:%02d",start1.h,start1.m,start1.s,end1.h,end1.m,end1.s,(start1-end1).h,(start1-end1).m,(start1-end1).s);
    return 0;
}
