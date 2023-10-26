#include <bits/stdc++.h>
using namespace std;

int k = 0, l = 0;

void toybox(char **arr, int h, int w, int s) {
    int hmod = h-s-1, wmod = w-s-1;
    int cnt = 0;
    for (int i = 0; i <= s+1; ++i) {
        for (int j = 0; j <= s*2+2; ++j) {
            if (i == 0 && (j == 0 || j == s*2+2)) {
                arr[i+hmod][j+wmod] = ' ';
            } else if (i == 0) {
                arr[i+hmod][j+wmod] = '_';
            } else if (j == 0 || j == s*2+2) {
                arr[i+hmod][j+wmod] = '|';
            } else if (i == 1 && j == s+1) {
                arr[i+hmod][j+wmod] = '^';
            } else if (i == s+2-j) {
                arr[i+hmod][j+wmod] = '/';
            } else if (i == j-s) {
                arr[i+hmod][j+wmod] = '\\';
            } else if (i >= s+2-j && i >= j-s) {
                arr[i+hmod][j+wmod] = char(65+cnt%26);
                ++cnt;
            } else {
                arr[i+hmod][j+wmod] = ' ';
            }
        }
    }
    k -= s+2;
    return;
}

int main() {
    int n;
    scanf("%d",&n);
    int strge[n][103] = {}, height = 0, width = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&strge[i][100]);
        for (int j = 0; j < strge[i][100]; ++j) {
            scanf("%d",&strge[i][j]);
            strge[i][102] += strge[i][j]+2;
            if (strge[i][j] > strge[i][101]) {
                strge[i][101] = strge[i][j];
            }
        }
        if (strge[i][102] > height) {
            height = strge[i][102];
        }
        width += 2*strge[i][101]+3;
    }
    char *arr[height];
    for (int i = 0; i < height; ++i) {
        arr[i] = new char[width];
        for (int j = 0; j < width; ++j) {
            arr[i][j] = ' ';
        }
    }
    for (int i = n-1; i >= 0; --i) {
        k = height-1;
        l += strge[n-i-1][101]+1;
        for (int j = 0; j < strge[n-i-1][100]; ++j) {
            toybox(arr,k,l,strge[n-i-1][j]);
        }
        l += strge[n-i-1][101]+2;
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
