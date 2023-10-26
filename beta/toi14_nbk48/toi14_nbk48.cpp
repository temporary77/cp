#include <bits/stdc++.h>
using namespace std;

int n, q;
vector<pair<int,int>> vctr, vctr2, vctr3;

int main() {
	scanf("%d%d",&n,&q);
	int k;
	vctr.push_back({0,0});
	for (int i = 1; i <= n; ++i) {
		scanf("%d",&k);
		vctr.push_back({k,i});
	}
	for (int i = n; i >= 1; --i) {
		 if (vctr[i].first <= 0) {
		 	vctr[i-1].first += vctr[i].first;
		 	vctr[i-1].second = vctr[i].second;
		 } else {
		 	vctr2.push_back(vctr[i]);
		 }
	}
	vctr2.push_back(vctr[0]);
	reverse(vctr2.begin(),vctr2.end());
	int sum = 0;
	for (auto it : vctr2) {
		sum += it.first;
		vctr3.push_back({sum,it.second});
		//printf("%d %d\n",*vctr3.rbegin());
	}
	for (int i = 0; i < q; ++i) {
		scanf("%d",&k);
		printf("%d\n",(*--lower_bound(vctr3.begin(),vctr3.end(),(pair<int,int>){k+1,0})).second);
	}
	return 0;
}