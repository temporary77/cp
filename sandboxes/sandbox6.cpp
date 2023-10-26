#include <bits/stdc++.h>
using namespace std;

void mergesort(int arr[], int begin1, int end1) {
    if (begin1 >= end1)return;
    int mid = begin1+(begin1+end1)/2;
    mergesort(arr,begin1,mid);
    mergesort(arr,mid+1,end1);
    //merge(arr+begin1,arr+mid+1,arr+mid+1,arr+end1+1,arr+begin1);
    return;
}

int main() {
    int arr[10] = {5,1,2,8,4,10,9,3,7,6};
    mergesort(arr,0,9);
    for (int i = 0; i < 10; ++i) {
        printf("%d ",arr[i]);
    }

}
