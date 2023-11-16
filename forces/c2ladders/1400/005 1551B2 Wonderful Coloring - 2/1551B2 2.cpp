#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[200001];
int ans[200001];
vector<pair<int,int>> vctr;

int main() {
	int t;
	scanf("%d",&t);
	for (int ti = 0; ti < t; ++ti) {
		int n, k;
		scanf("%d%d",&n,&k);
		for (int i = 0; i < n; ++i) {
			scanf("%d",&arr[i].first);
			arr[i].second = i;
		}
		sort(arr,arr+n);
		int cur = 0;
		int c = 0;
		for (int i = 0; i < n; ++i) {
			if (i == 0 || arr[i].first == arr[i-1].first) {
				if (cur == k) {
					ans[arr[i].second] = 0;
					continue;
				}
				++cur;
			} else {
				cur = 1;
			}
			vctr.push_back({arr[i].second,c+1});
			c = (c+1)%k;
			if (!c) {
				for (auto it : vctr) {
					ans[it.first] = it.second;
				}
				vctr.clear();
			}
		}
		for (auto it : vctr) {
			ans[it.first] = 0;
		}
		for (int i = 0; i < n; ++i) {
			printf("%d ",ans[i]);
		}
		printf("\n");
		vctr.clear();
	}
	return 0;
}