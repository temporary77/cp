#include <bits/stdc++.h>
using namespace std;

vector<int> vctr;
vector<int> piles;

int main() {
	int n;
	scanf("%d",&n);
	int k;
	for (int i = 0; i < n; ++i) {
		scanf("%d",&k);
		vctr.push_back(k);
	}
	sort(vctr.begin(),vctr.end());
	for (auto it : vctr) {
		auto it2 = lower_bound(piles.begin(),piles.end(),it,greater<int>());
		if (it2 == piles.end())piles.push_back(1);
		else ++*it2;
	}
	printf("%d",piles.size());
	return 0;
}