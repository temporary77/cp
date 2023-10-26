#include <bits/stdc++.h>
using namespace std;

bool arr[1001][1001];
string str;
int idx = -1;
int n, m;

void recursion(int a, int b, int c, int d) {
    ++idx;
    int x = c-(c-a)/2, y = d-(d-b)/2;
    if (str[idx] == 'D') {
        recursion(a,b,x,y);
        if (d-b != 1)recursion(a,y,x,d);
        if (c-a != 1)recursion(x,b,c,y);
        if (d-b != 1 && c-a != 1)recursion(x,y,c,d);
    } else if (str[idx] == '0') {
        for (int i = a; i < c; ++i) {
            for (int j = b; j < d; ++j) {
                arr[i][j] = 0;
            }
        }
    } else {
        for (int i = a; i < c; ++i) {
            for (int j = b; j < d; ++j) {
                arr[i][j] = 1;
            }
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    scanf("%d%d",&n,&m);
    cin >> str;
    recursion(0,0,n,m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
