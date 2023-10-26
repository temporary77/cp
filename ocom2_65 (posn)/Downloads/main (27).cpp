#include <bits/stdc++.h>
using namespace std;

int recursion(vector<int> &vctr, int l, int r) {
    if (r-l == 1) {
        return 0;
    }
    if (r-l == 2) {
        return (vctr[l]+vctr[r]);
    }
    int max1 = -1e9;
    for (int i = l+1; i < r; ++i) {
        max1 = max(max1,recursion(vctr,l,i)+recursion(vctr,i,r));
    }
    return max1+vctr[l]+vctr[r];
}

int main() {
    int n;
    scanf("%d",&n);
    vector<int> vctr;
    int k;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&k);
        vctr.push_back(k);
    }
    int max1 = recursion(vctr,0,n-1);
    printf("%d",max1);
}