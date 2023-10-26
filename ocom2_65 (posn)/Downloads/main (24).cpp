#include <bits/stdc++.h>
using namespace std;

int arr[20][20];
int n, x2, y2;
int ans = 401;
int dirx[8] = {-1,1,2,2,1,-1,-2,-2}, diry[8] = {-2,-2,-1,1,2,2,1,-1};

void recursion(int x1, int y1, int cnt) {
    if (cnt > n)return;
    if (x1 == x2 && y1 == y2) {
        ans = min(ans,cnt);
        return;
    }
    int desx, desy;
    arr[x1][y1] = 1;
    for (int i = 0; i < 8; ++i) {
        desx = x1+dirx[i];
        desy = y1+diry[i];
        if (desx >= 0 && desx < n && desy >= 0 && desy < n && arr[desx][desy] == 0) {
            recursion(desx,desy,cnt+1);
        }
    }
    arr[x1][y1] = 0;
}

int main() {
    int x1, y1;
    scanf("%d%d%d%d%d",&n,&x1,&y1,&x2,&y2);
    memset(arr,0,sizeof(arr));
    recursion(x1,y1,0);
    printf("%d",ans);
    return 0;
}