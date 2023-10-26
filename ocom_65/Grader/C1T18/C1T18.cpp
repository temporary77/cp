#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = {};

int main() {
    int a, maxcnt = -1, num = 0;
    long long sum = 0;
    char c;
    scanf("%d",&a);
    arr[a]++;
    sum += a;
    num++;
    if (arr[a] > maxcnt) {
        maxcnt = arr[a];
    }
    scanf("%c",&c);
    while (c == '-') {
        scanf("%d%c",&a,&c);
        arr[a]++;
        sum += a;
        num++;
        if (arr[a] > maxcnt) {
            maxcnt = arr[a];
        }
    }
    long long avg = sum/num;
    int diff = 1e7, mode = -1;
    for (int i = 0; i < 1000001; ++i) {
        if (arr[i] == maxcnt) {
            if (abs(i-avg) < diff) {
                mode = i;
                diff = abs(i-avg);
            } else if (abs(i-avg) == diff) {
                mode = min(mode,i);
            }
        }
    }
    printf("%d %d",mode,arr[mode]);
    return 0;
}
