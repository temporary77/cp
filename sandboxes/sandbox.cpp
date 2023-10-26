#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ofstream ofs;
    ofs.open("outputf.out", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    return 0;
    vector<int> vctr = {1,2,3,4,5,6,7};
    rotate(vctr.begin(),vctr.begin()+2,vctr.end());
    for (auto it : vctr)printf("%d ",it);
    /*for (int i = 1; i <= 16; ++i) {
        printf("%d: ",i);
        for (int j = i; j <= 16; j+=j&(-j)) {
            printf("%d ",j);
        }
        printf("\n");
    }
    for (int i = 1; i <= 16; ++i) {
        printf("%d: ",i);
        for (int j = i; j > 0; j-=j&(-j)) {
            printf("%d ",j);
        }
        printf("\n");
    }*/
    

    return 0;
}