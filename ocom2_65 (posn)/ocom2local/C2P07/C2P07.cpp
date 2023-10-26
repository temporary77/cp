#include <bits/stdc++.h>
using namespace std;

bool customsort(const pair<pair<long double,int>,pair<long long,long long>> &a,const pair<pair<long double,int>,pair<long long,long long>> &b) {
    if ((a.first).first != (b.first).first) {
        return (a.first).first < (b.first).first;
    } else {
        return (a.first).second < (b.first).second;
    }
}

int main() {
    int n;
    scanf("%d",&n);
    vector<pair<pair<long double,int>,pair<long long,long long>>> vctr;
    long long a, b;
    long double c;
    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld",&a,&b);
        c = sqrt((long double)(a*a+b*b));
        vctr.push_back({{c,i},{a,b}});
    }
    sort(vctr.begin(),vctr.end(),customsort);
    for (int i = 0; i < n; ++i) {
        printf("(%lld, %lld)\n",(vctr[i].second).first,(vctr[i].second).second);
    }

    return 0;
}
