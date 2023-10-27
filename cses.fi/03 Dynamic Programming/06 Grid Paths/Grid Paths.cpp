#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
int arr[1001][1001];
 
int main() {
    cin.tie(nullptr);
    int n;
    scanf("%d",&n);
    string str;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= n; ++j) {
            if (i == 1 && j == 1) {
                if (str[0] == '*')break;
                arr[1][1] = 1;
                continue;
            }
            if (str[j-1] == '.') {
                arr[i][j] = arr[i-1][j]+arr[i][j-1];
                arr[i][j] %= mod;
            }
        }
    }
    printf("%d",arr[n][n]);
    return 0;
}
