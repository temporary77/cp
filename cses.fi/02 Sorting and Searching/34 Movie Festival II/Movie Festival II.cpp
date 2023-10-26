#include <bits/stdc++.h>
using namespace std;

pair<int,int> arr[200001];
multiset<int> mltst;

bool comp(pair<int,int> a, pair<int,int> b) {
	if (a.second != b.second) {
		return a.second < b.second;
	} else {
		return a.first < b.first;
	}
}

int main() {
	int n, k;
	scanf("%d%d",&n,&k);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d",&arr[i].first,&arr[i].second);
	}
	sort(arr,arr+n,comp);
	/*for (int i = 0; i < n; ++i) {
		printf("%d %d\n",arr[i]);
	}*/
	for (int i = 0; i < k; ++i) {
		mltst.insert(0);
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		auto it = mltst.upper_bound(arr[i].first);
		if (it == mltst.begin()) {
			continue;
		}
		--it;
		mltst.erase(it);
		mltst.insert(arr[i].second);
		++cnt;
	}
	printf("%d",cnt);
	return 0;
}