#include <bits/stdc++.h>
using namespace std;

int sum = 0;

void recursion(int **arr, int currow, int curcol, int amount, int examount, int n, int m) {
    amount += arr[currow][curcol];
    if (curcol == m) {
        if (amount+examount > sum) {
            sum = amount+examount;
        }
        return;
    }
    if (currow == 0) {
        if (currow == n) {
            recursion(arr,0,curcol+1,amount,examount,n,m);
            return;
        }
        if (arr[0][curcol+1] > arr[1][curcol+1]) {
            recursion(arr,0,curcol+1,amount,examount,n,m);
        }
        if (arr[currow][curcol+1] > examount) {
            examount = arr[currow][curcol+1];
        }
        recursion(arr,1,curcol+1,amount,examount,n,m);
    } else if (currow == n) {
        if (arr[currow][curcol+1] > arr[currow-1][curcol+1]) {
            recursion(arr,currow,curcol+1,amount,examount,n,m);
        }
        if (arr[currow][curcol+1] > examount) {
            examount = arr[currow][curcol+1];
        }
        recursion(arr,currow-1,curcol+1,amount,examount,n,m);
    } else {
        if (arr[currow][curcol+1] > arr[currow-1][curcol+1] || arr[currow][curcol+1] > arr[currow+1][curcol+1]) {
            recursion(arr,currow,curcol+1,amount,examount,n,m);
        }
        if (arr[currow][curcol+1] > examount) {
            examount = arr[currow][curcol+1];
        }
        recursion(arr,currow-1,curcol+1,amount,examount,n,m);
        recursion(arr,currow+1,curcol+1,amount,examount,n,m);
    }
    return;
}

int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    int *arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i] = new int [m];
        for (int j = 0; j < m; ++j) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (int i = 0; i < n; ++i) {
        recursion(arr,i,0,0,0,n-1,m-1);
    }
    printf("%d",sum);
    return 0;
}
