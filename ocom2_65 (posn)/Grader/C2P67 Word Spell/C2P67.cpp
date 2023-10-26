#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio();
    cin.tie(nullptr);
    string str1, str2;
    cin >> str1 >> str2;
    int n = str2.size();
    int max1 = 1;
    for (int i = 0; i < n; ++i) {
        int t = i;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (str1[j] == str2[t]) {
                ++cnt;
                ++t;
            }
        }
        max1 = max(max1,cnt);
    }
    printf("%d",n-max1);
    return 0;
}

// (n,m)
// if idx of (n-1,m) = n-1; (n,m) = (n-1,m)+1
// if endchar of (n,m-1) = m-1 && idx of m is greater than m-1; (n,m) = (n,m-1)+1
