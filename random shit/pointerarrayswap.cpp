#include <bits/stdc++.h>
using namespace std;

int main() {
    int arr1[5] = {0,1,2,3,4};
    int arr2[5] = {5,6,7,8,9};
    for (int i = 0; i < 5; ++i) {
        *(arr1+i) ^= *(arr2+i);
        *(arr2+i) ^= *(arr1+i);
        *(arr1+i) ^= *(arr2+i);
    }
    for (int i = 0; i < 5; ++i) {
        printf("%d ",arr1[i]);
    }
    printf("\n");
    for (int i = 0; i < 5; ++i) {
        printf("%d ",arr2[i]);
    }
    return 0;
}
