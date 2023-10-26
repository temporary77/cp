#include <bits/stdc++.h>
using namespace std;

int arr[22][22];
int dirx[8] = {-1,0,1,-1,1,-1,0,1}, diry[8] = {-1,-1,-1,0,0,1,1,1};

void recursion(int i, int j) {
    arr[i][j] = 0;
    for (int k = 0; k < 8; ++k) {
        if (arr[i+dirx[k]][j+diry[k]] == 1) {
            recursion(i+dirx[k],j+diry[k]);
        }
    }
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    memset(arr,0,sizeof(arr));
    int cnt = 0;
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            if (arr[i][j] == 1) {
                recursion(i,j);
                ++cnt;
            }
        }
    }
    printf("%d",cnt);
    
    return 0;
}