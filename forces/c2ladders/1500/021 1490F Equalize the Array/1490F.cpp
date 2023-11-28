#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;
map<int,int> mp2;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d",&a);
			++mp[a];
		}
		for (auto it : mp) {
			++mp2[it.second];
		}
		int max1 = 0;
		int cur = 0;
		for (auto it : mp2) {
			max1 = max(max1,((int)mp.size()-cur)*it.first);
			cur += it.second;
		}
		printf("%d\n",n-max1);
		mp.clear();
		mp2.clear();
	}
	return 0;
}