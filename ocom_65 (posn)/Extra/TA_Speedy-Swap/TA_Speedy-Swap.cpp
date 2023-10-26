#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a;
    scanf("%d",&n);
    int *arr[n], size1[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&m);
        size1[i] = m;
        arr[i] = new int [m]{};
        for (int j = 0; j < m; ++j) {
            scanf("%d",&a);
            arr[i][j] = a;
        }
    }
    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; ++i) {
        char cmd;
        int r, x;
        scanf(" %c%d%d",&cmd,&r,&x);
        if (cmd == 'A') {
            arr[r-1] = (int *)realloc(arr[r-1], (size1[r-1]+1)*sizeof(int));
            arr[r-1][size1[r-1]] = x;
            size1[r-1]++;
        } else if (cmd == 'S') {
            int *temp = arr[r-1];
            arr[r-1] = arr[x-1];
            arr[x-1] = temp;
            size1[r-1] ^= size1[x-1];
            size1[x-1] ^= size1[r-1];
            size1[r-1] ^= size1[x-1];
        } else if (cmd == 'D') {
            if (size1[r-1] > x-1) {
                printf("%d\n",arr[r-1][x-1]);
            } else {
                printf("Invalid Index\n");
            }
        }
    }
    return 0;
}
