#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    map<int,int> mltst;
    int k, sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        sum += k;
        ++mltst[k];
    }
    sum /= n;
    int cnt = 0;
    for (auto it : mltst) {
        if (it.first >= sum)break;
        cnt += (sum-(it.first))*(it.second);
    }
    printf("%d",cnt);
    
    return 0;
}