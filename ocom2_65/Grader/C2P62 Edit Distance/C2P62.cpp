#include <bits/stdc++.h>
using namespace std;

int arr[1001][1001];

int main() {
    cin.tie(nullptr);
    string str1, str2;
    cin >> str1 >> str2;
    int n = str1.size();
    int m = str2.size();
    for (int i = 0; i <= n; ++i) {
        arr[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        arr[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (str1[i-1] == str2[j-1]) {
                arr[i][j] = arr[i-1][j-1];
            } else {
                arr[i][j] = min(min(arr[i][j-1],arr[i-1][j]),arr[i-1][j-1])+1;
            }
        }
    }
    printf("%d",arr[n][m]);
    return 0;
}
