#include <bits/stdc++.h>
using namespace std;

int main() {
    int *arr[3];
    for (int i = 0; i < 3; ++i) {
        arr[i] = new int [4]{};
        for (int j = 0; j < 4; ++j) {
            arr[i][j] = i+j;
        }
    }
    int *temp = arr[1];
    arr[1] = arr[2];
    arr[2] = temp;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            printf("%d|",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
