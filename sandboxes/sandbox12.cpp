#include <bits/stdc++.h>
using namespace std;

vector<int> funct(int n) {
    printf("called\n");
    vector<int> vctr2;
    for (int i = 0; i < n; ++i)vctr2.push_back(i);
    return vctr2;
}

int main() {
    // vector<int> vctr = {1,2,3,4,5,6,7,4};
    // auto it = lower_bound(vctr.begin(),vctr.end(),4);
    // rotate(it,vctr.end()-1,vctr.end());
    // for (auto it : vctr)printf("%d ",it);
    // printf("\n");
    // for (auto it : funct(9))printf("%d ",it);
    // printf("\n");
    // for (int i = 0; i < funct(9).size(); ++i)printf("%d ",i);
    int l = 1, r = 2;
    int* ptr = &r;
    *ptr = 3;
    printf("%d %d\n",l,r);
    if (ptr == &l) {
        printf("is l");
    } else if (ptr == &r) {
        printf("is r");
    }
    printf("\n%lf\n",log2(200000));
    printf("%d\n",(int)ceil(log2(200000)));
    printf("%d",pow(2,ceil(log2(200000))));
    return 0;
}