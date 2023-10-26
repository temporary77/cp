#include <bits/stdc++.h>
using namespace std;

stack<pair<int,long long>> stck1;
stack<pair<int,long long>> stck2;
pair<long long,long long> minmax1[5000001];
long long qs[5000001];
int n;

long long restaurant(int nn, std::vector<int> &a) {
    n = nn;
    // edit this
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        qs[i] = sum;
        //printf("%lld ",qs[i]);
    }
    //printf("\n");
    stck1.push({-1,0});
    for (int i = 0; i < n; ++i) {
        for (;!stck1.empty() && stck1.top().first >= abs(a[i]);) {
            long long pmin = stck1.top().second;
            stck1.pop();
            stck1.top().second = min(stck1.top().second,pmin);
        }
        minmax1[i].first = stck1.top().second;
        stck1.top().second = min(stck1.top().second,qs[i]);
        stck1.push({abs(a[i]),qs[i]});
    }
    stck2.push({-1,LLONG_MIN});
    for (int i = n-1; i >= 0; --i) {
        for (;!stck2.empty() && stck2.top().first >= abs(a[i]);) {
            long long pmax = stck2.top().second;
            stck2.pop();
            stck2.top().second = max(stck2.top().second,pmax);
        }
        stck2.top().second = max(stck2.top().second,qs[i]);
        minmax1[i].second = stck2.top().second;
        stck2.push({abs(a[i]),LLONG_MIN});
    }
    long long ans = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        //printf("%d %lld %lld %d %lld\n",i,minmax1[i],a[i],minmax1[i].second-minmax1[i].first);
        ans = max(ans,abs(a[i])*(minmax1[i].second-minmax1[i].first));
    }
    return ans;
}