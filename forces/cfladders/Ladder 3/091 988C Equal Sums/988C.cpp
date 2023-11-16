#include <bits/stdc++.h>
using namespace std;

unordered_map<int,pair<int,int>> mp;
vector<int> vctr;

int main() {
	int k;
	scanf("%d",&k);
	bool check = 0;
	int n1, i1, n2, i2;
	for (int i = 1; i <= k; ++i) {
		int n;
		scanf("%d",&n);
		int x;
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			scanf("%d",&x);
			vctr.push_back(x);
			sum += x;
		}
		for (int j = 0; j < n; ++j) {
			if (mp.find(sum-vctr[j]) != mp.end()) {
				if (mp[sum-vctr[j]].first != i) {
					check = 1;
					tie(n1,i1) = mp[sum-vctr[j]];
					n2 = i;
					i2 = j+1;
					printf("YES\n%d %d\n%d %d",n1,i1,n2,i2);
					return 0;
				}
			} else {
				mp[sum-vctr[j]] = {i,j+1};
			}
		}
		vctr.clear();
	}
	printf("NO");
	return 0;
}