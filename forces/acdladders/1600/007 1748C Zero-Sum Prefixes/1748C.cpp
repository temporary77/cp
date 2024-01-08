#include <bits/stdc++.h>
using namespace std;

int arr[200001];
long long qs[200001];
map<long long,int> mp;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n;
		scanf("%d",&n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d",&arr[i]);
			qs[i] = qs[i-1]+arr[i];
		}
		int max1 = 0;
		int ans = 0;
		for (int i = n; i >= 1; --i) {
			max1 = max(max1,++mp[qs[i]]);
			if (arr[i] == 0) {
				ans += max1;
				max1 = 0;
				mp.clear();
			}
		}
		if(mp.find(0) != mp.end())ans += mp[0];
		printf("%d\n",ans);
		mp.clear();
	}
	return 0;
}