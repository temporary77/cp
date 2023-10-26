#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = {}, a, maxcnt = -1, maxint[1000001] = {}, cnt = 0, num = 0;
int main() {

    long long sum = 0;
    char c;
    scanf("%d",&a);
    arr[a]++;
    sum += a;
    num++;
    if (arr[a] > maxcnt) {
        maxcnt = arr[a];
        maxint[0] = a;
        cnt = 1;
    } else if (arr[a] == maxcnt) {
        maxint[cnt] = a;
        cnt++;
    }
    scanf("%c",&c);
    while (c == '-') {
        scanf("%d%c",&a,&c);
        arr[a]++;
        sum += a;
        num++;
        if (arr[a] > maxcnt) {
            maxcnt = arr[a];
            for (int i = 0; i < 1000001; ++i) {
                maxint[i] = 0;
            }
            maxint[cnt] = a;
            cnt++;
        } else if (arr[a] == maxcnt) {
            maxint[cnt] = a;
            cnt++;
        }
    }
    long long avg = sum/num;
    int diff = 1e7, mode = -1;
    for (int i = 0; i < cnt; ++i) {
        if (abs(maxint[i]-avg) < diff) {
            mode = maxint[i];
            diff = abs(maxint[i]-avg);
        } else if (abs(maxint[i]-avg) == diff) {
            mode = min(mode,maxint[i]);
        }
    }
    printf("%d %d",mode,arr[mode]);
    return 0;
}
