#include <bits/stdc++.h>
using namespace std;

bool arr[1002][1002];
int visited[1002][1002];
int dirx[4] = {0,-1,1,0}, diry[4] = {-1,0,0,1};
int cnt, n, m;
bool xor1;

void recursion(int x, int y, int k) {
    visited[x][y] = k;
    int vx, vy;
    for (int i = 0; i < 4; ++i) {
        vx = x+dirx[i];
        vy = y+diry[i];
        if (arr[vx][vy] == 1) {
            ++cnt;
        }
        if (vx >= 1 && vx <= n && vy >= 1 && vy <= m && arr[vx][vy] == 0 && visited[vx][vy] == 0) {
            recursion(vx,vy,k);
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    int k;
    scanf("%d%d%d",&n,&m,&k);
    string str;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= m; ++j) {
            if (str[j-1] == '*')arr[i][j] = 1;
        }
    }
    int x, y;
    vector<int> vctr;
    vctr.push_back(0);
    int det = 1;
    for (int i = 0; i < k; ++i) {
        cnt = 0;
        scanf("%d%d",&x,&y);
        if (arr[x][y] == 0) {
            if (visited[x][y] == 0) {
                recursion(x,y,det);
                ++det;
                vctr.push_back(cnt);
            }
            printf("%d\n",vctr[visited[x][y]]);
        } else {
            printf("0\n");
        }
    }
    return 0;
}